#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <list>

template<typename T>
void easyfind(T container, int nb)
{
    typename T::iterator it = std::find(container.begin(), container.end(), nb);

    if (it == container.end())
        throw std::runtime_error("Element not found.");
    else
        std::cout << *it << std::endl;
}

#endif
