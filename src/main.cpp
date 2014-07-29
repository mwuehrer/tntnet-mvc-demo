//TODO: this file should be shrinked

/*
 * Copyright (C) 2013 Tommi Maekitalo
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * is provided AS IS, WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, and
 * NON-INFRINGEMENT.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */

#include <iostream>
#include <tnt/tntnet.h>
#include <tnt/tntconfig.h>
#include <tnt/configurator.h>
#include <cxxtools/log.h>
#include <cxxtools/xml/xml.h>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <stdexcept>

log_define("main")

namespace po = boost::program_options;
namespace fs = boost::filesystem;

template <typename T>
inline void read_config(const std::string &filename, T &config);
const tnt::TntConfig& config_main(const std::string &filename);
void config_log(const std::string &filename);

class configfile_error:public std::ios_base::failure{
    public:
        //inherit constructors
        using std::ios_base::failure::failure;
};

int main(int argc, char* argv[])
{
  try
  {
    std::string config_file;
    std::string log_config_file;
    po::variables_map vm;
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("config,c", po::value<std::string>(&config_file)->default_value(
                "etc/config.xml"), "path to config-file")
        ("log-config,l", po::value<std::string>(&log_config_file)->default_value(
                "etc/log.xml"), "path to log-config-file")
        //TODO: move log-config to standard-config
        ;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    if(vm.count("help")) {
        std::cout << desc << "\n";
        return EXIT_FAILURE;
    }

    config_log(log_config_file);
    log_debug("Using log-config-file '" << log_config_file << "'");
    log_debug("Using config-file '" << config_file << "'");

    tnt::Tntnet app;
    app.init(config_main(config_file));
    app.run();
  }
  catch (const std::exception& e)
  {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }
}

template <typename T>
inline void read_config(const std::string &filename, T &config) {
    std::ifstream xml(filename);

    if(!fs::exists(filename)) {
        throw configfile_error("config-file doesn't exist.");
    }

    if(!xml.is_open()) {
        throw configfile_error("config-file can't be opened.");
    }
    xml >> cxxtools::xml::Xml(config);
}

const tnt::TntConfig& config_main(const std::string &filename) {
    static tnt::TntConfig &config(tnt::TntConfig::it());
    read_config(filename, config);
    return tnt::TntConfig::it();
}

void config_log(const std::string &filename) {
    static cxxtools::LogConfiguration config;
    read_config(filename, config);
    log_init(config);
}
