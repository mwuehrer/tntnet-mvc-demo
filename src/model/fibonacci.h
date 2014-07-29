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

#ifndef MODEL_FIBONACCI_H
#define MODEL_FIBONACCI_H

#include <ctime>
#include <model/optional.h>
#include <model/timer.h>

namespace model
{
    class fibonacci_t : public timer_t
    {
        public:
            typedef model::optional_t<uint64_t> val_t;

            fibonacci_t(val_t arg_value=val_t()):
                timer_t(), _arg_value(arg_value), _result(){}

            void set_result(val_t result){_result.set(result.get());}

            val_t get_arg_value() const{return _arg_value;}

            val_t get_result() const{return _result;}

        private:
            val_t _arg_value;
            val_t _result;
    };
}

#endif //MODEL_FIBONACCI_H
