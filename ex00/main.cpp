#include "easyfind.hpp"

int main(void)
{
    std::vector<int> nb_vector;
    std::list<int> nb_list;
    std::deque<int> nb_deque;

    nb_vector.push_back(75);
    nb_vector.push_back(12);
    nb_list.push_back(2);
    nb_list.push_back(6);
    nb_deque.push_back(98);
    nb_deque.push_back(9);

    try
    {
        easyfind(nb_vector, 12);
        easyfind(nb_vector, 2);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        easyfind(nb_list, 2);
        easyfind(nb_list, 20);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        easyfind(nb_deque, 9);
        easyfind(nb_deque, 5);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}
