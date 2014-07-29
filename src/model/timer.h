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

#ifndef MODEL_TIMER_H
#define MODEL_TIMER_H

#include <ctime>

namespace model
{
    class timer_t
    {
        public:
            timer_t():
                _start_time(clock()), _stop_time(0){}

            void stop(){_stop_time = clock();}

            double get_time() const{
                return (_stop_time == 0) ? 0 : (double)(_stop_time - _start_time)/(CLOCKS_PER_SEC/1000);}

        private:
            clock_t _start_time;
            clock_t _stop_time;
    };
}

#endif //MODEL_TIMER_H
