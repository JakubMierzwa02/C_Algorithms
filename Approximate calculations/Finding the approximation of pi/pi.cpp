#include <iostream>
#include <ctime>
#include <cmath>

/*
    Monte Carlo method
*/

int main()
{
    srand(time(NULL));
    int n, n0 = 0;
    double x, y;
    std::cout << "Number of points: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        x = -1 + 2 * (double(rand()) / RAND_MAX);
        y = -1 + 2 * (double(rand()) / RAND_MAX);
        if (x * x + y * y <= 1)
            n0++;
    }
    std::cout << "Approximation of Pi: " << 4 * (double(n0) / n) << '\n';

    return 0;
}
