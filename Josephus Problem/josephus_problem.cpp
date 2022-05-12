#include <iostream>
#include <list>

/*
    People are standing in a circle waiting to be executed.
    Counting begins at a specified point in the circle and proceeds around the circle in a specified direction.
    After a specified number of people are skipped, the next person is executed.
    The procedure is repeated with the remaining people, starting with the next person,
    going in the same direction and skipping the same number of people, until only one person remains, and is freed.

    The problem—given the number of people, starting point, direction, and number to be skipped—is to choose the position in the initial circle to avoid execution.
*/

int main()
{
    int n, k;
    std::list<int> items;
    std::list<int>::iterator it;
    std::cout << "n = ";  std::cin >> n;
    std::cout << "k = ";  std::cin >> k;

    for (int i = 1; i <= n; i++)
        items.push_back(i);
    it = items.begin();

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            it++;
            if (it == items.end())
                it = items.begin();
        }
        std::cout << "Step " << i << ": item erased: " << *it << '\n';
        it = items.erase(it);
        if (it == items.end())
            it = items.begin();
    }
    std::cout << "Last item: " << *it << '\n';
}
