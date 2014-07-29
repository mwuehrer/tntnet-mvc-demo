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
#include <model/fibonacci.h>
#include <tnt/componentfactory.h>
#include <tnt/component.h>
#include <tnt/httpreply.h>
#include <tnt/httprequest.h>
#include <header/misc.h>

log_define("controller.fibonacci")

namespace
{
  class FibonacciController : public tnt::Component
  {
    public:
      unsigned operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam);

    private:
      unsigned long long int fibonacci(unsigned long long int zahl);
  };

  static tnt::ComponentFactoryImpl<FibonacciController> factory("controller/fibonacci");

  unsigned FibonacciController::operator() (tnt::HttpRequest& request, tnt::HttpReply& reply, tnt::QueryParams& qparam)
  {
    model::fibonacci_t::val_t arg_value(qparam.arg<model::fibonacci_t::val_t>("arg_value"));

    TNT_REQUEST_SHARED_VAR(model::fibonacci_t, s_data, (arg_value));

    if(arg_value.is_set()) {
        s_data.set_result(fibonacci(arg_value.get()));
    }

    s_data.stop();

    log_debug("fibonacci controller");

    return DECLINED;
  }

  unsigned long long int FibonacciController::fibonacci(unsigned long long int num) {
    if (num == 0) {
        return 0;
    }

    if (num == 1) {
        return 1;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
  }
}
