#include <cstdlib>
#include <iostream>
#include <vector>

void read_integers(std::vector<int> &ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        ints.push_back(new_integer);
    }
}

bool same_values(const std::vector<int> &ints)
{
    std::vector<int>::size_type elem2_index = 0;

    int eka = ints.at(0);
    while (elem2_index < ints.size())
    {
        int elem2 = ints.at(elem2_index);
        if (elem2 != eka)
        {
            return false;
        }

        ++elem2_index;
    }
    return true;
}

bool is_ordered_non_strict_ascending(const std::vector<int> &ints)
{
    std::vector<int>::size_type elem1_index = 0;
    std::vector<int>::size_type elem2_index = 1;

    while (elem2_index < ints.size())
    {
        int elem1 = ints.at(elem1_index);
        int elem2 = ints.at(elem2_index);
        int diff = elem2 - elem1;

        if (diff < 0)
        {
            return false;
        }

        ++elem1_index;
        ++elem2_index;
    }

    return true;
}

bool is_arithmetic_series(const std::vector<int> &ints)
{

    std::vector<int>::size_type elem1_index = 0;
    std::vector<int>::size_type elem2_index = 1;

    int diff = ints.at(1) - ints.at(0);

    while (elem2_index < ints.size())
    {
        int elem1 = ints.at(elem1_index);
        int elem2 = ints.at(elem2_index);

        int new_diff = elem2 - elem1;
        if (new_diff != diff)
        {
            return false;
        }
        ++elem1_index;
        ++elem2_index;
    }

    return true;
}

bool is_geometric_series(const std::vector<int> &ints)
{
    if (ints.size() < 1)
    {
        return true;
    }
    if (ints.at(0) == 0)
    {
        return false;
    }

    std::vector<int>::size_type elem1_index = 0;
    std::vector<int>::size_type elem2_index = 1;

    int ratio = ints.at(1) / ints.at(0);
    int remainder = ints.at(1) % ints.at(0);

    while (elem2_index < ints.size())
    {
        int elem1 = ints.at(elem1_index);
        int elem2 = ints.at(elem2_index);

        int new_ratio = elem2 / elem1;
        int new_remainder = elem2 % elem1;
        if ((new_ratio != ratio) || (new_remainder != remainder))
        {
            return false;
        }
        ++elem1_index;
        ++elem2_index;
    }

    return true;
}
int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if (same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}
