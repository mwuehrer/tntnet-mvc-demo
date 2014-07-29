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

#include <tnt/componentfactory.h>
#include <tnt/component.h>
#include <tnt/httpreply.h>
#include <tnt/httprequest.h>
#include <header/misc.h>
#include <cxxtools/log.h>

log_define("controller.index")

namespace
{
  class IndexController : public tnt::Component
  {
    public:
      unsigned operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam);
  };

  static tnt::ComponentFactoryImpl<IndexController> factory("controller/index");

  unsigned IndexController::operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam)
  {
    TNT_SESSION_SHARED_VAR(unsigned int, s_page_cnt, (0));

    s_page_cnt ++;

    log_debug("index controller");

    return DECLINED;
  }
}
