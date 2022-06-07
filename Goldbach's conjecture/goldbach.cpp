#include <iostream>

bool isPrime(int n)
{
    int d = 2;
    if (n < 2)
        return false;
    while (d * d <= n)
    {
        if (n%d == 0)
            return false;
        d++;
    }
    return true;
}

void goldbach(int n)
{
    for (int i = 2; i * 2 < n; i++)
        for (int j = 2; j < n; j++)
            if (isPrime(i) && isPrime(j) && i + j == n)
                std::cout << i << " + " << j << " = " << n << '\n';
}

int main()
{
    int n;
    std::cout << "Enter an even number: ";
    std::cin >> n;

    if (n%2 != 0)
        std::cout << "Number must be even! \n";
    else
        goldbach(n);

    return 0;
}
