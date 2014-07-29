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

#ifndef MODEL_OPTIONAL_H
#define MODEL_OPTIONAL_H

#include <istream>
#include <ostream>

namespace model
{
    template <typename T>
    class optional_t
    {
        public:
            optional_t(const T val): _set(true), _val(val){}
            optional_t(): _set(false){}

            bool is_set() const{return _set;}
            T get() const{return _val;}
            void set(const T val){_set = true; _val=val;}

        private:
            bool _set;
            T _val;
    };

    template <typename T>
    std::istream& operator>>(std::istream& lhs, optional_t<T>& rhs);

    template <typename T>
    std::ostream& operator<<(std::ostream& lhs, const optional_t<T>& rhs);


}

template <typename T>
std::istream& model::operator>>(std::istream& lhs, model::optional_t<T>& rhs){
    //seek to end, to calc length
    lhs.seekg (0, lhs.end);
    if(lhs.tellg() != 0) {
        T tmp;
        lhs.seekg (0, lhs.beg);//seek to begin, to read from begin
        lhs >> tmp;
        rhs.set(tmp);
    }
    return lhs;
}

template <typename T>
std::ostream& model::operator<<(std::ostream& lhs, const model::optional_t<T>& rhs){
    if(rhs.is_set()) {
        lhs << rhs.get();
    }
    return lhs;
}

#endif // MODEL_OPTIONAL_H
