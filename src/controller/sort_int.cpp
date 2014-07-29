/*
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cxxtools/log.h>
#include <model/sort_int.h>
#include <tnt/componentfactory.h>
#include <tnt/component.h>
#include <tnt/httpreply.h>
#include <tnt/httprequest.h>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <header/misc.h>
#include <controller/sort_values.h>

log_define("controller.sort_int")

namespace
{
  class Sort_intController : public tnt::Component
  {
    public:
      unsigned operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam);
  };

  static tnt::ComponentFactoryImpl<Sort_intController> factory("controller/sort_int");

  unsigned Sort_intController::operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam)
  {
    unsigned int arg_num(qparam.arg<unsigned int>("arg_num", 10000));

    std::shared_ptr<std::vector<int>> list(new std::vector<int>());
    TNT_REQUEST_SHARED_VAR(model::sort_t<int>, s_data, (arg_num, list));

    switch(arg_num) {
        case 10000:
            list->assign(INT_VALUES_10000);
            break;
        case 100000:
            list->assign(INT_VALUES_100000);
            break;
        case 1000000:
            list->assign(INT_VALUES_1000000);
            break;
        case 5000000:
            list->assign(INT_VALUES_5000000);
            break;
        default:
            std::stringstream ss;
            ss << "Given Argument arg_num='" << arg_num << "' is out of range.";
            throw std::out_of_range(ss.str());
    }

    std::sort (list->begin(), list->end());
    s_data.stop();

    log_debug("sort_int controller");

    return DECLINED;
  }
}
