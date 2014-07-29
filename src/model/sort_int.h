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

#ifndef MODEL_SORT_INT_H
#define MODEL_SORT_INT_H

#include <ctime>
#include <vector>
#include <memory>
#include <model/timer.h>

namespace model
{
    template <typename T>
    class sort_t : public timer_t
    {
        public:
            typedef std::vector<T> list_t;

            sort_t(unsigned int arg_num = 0, std::shared_ptr<list_t> list = std::shared_ptr<list_t>()):
                timer_t(), _arg_num(arg_num), _list(list){}

            std::shared_ptr<list_t> get_list(){return _list;}

            unsigned int get_arg_num() const{return _arg_num;}

        private:
            unsigned int _arg_num;
            std::shared_ptr<list_t> _list;
    };
}

#endif //MODEL_SORT_INT_H
