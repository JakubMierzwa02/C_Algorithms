#include <iostream>
#include <vector>
#include <cmath>

const double E = 0.00001;

double f(const std::vector<double> coefficients, const int degree, double x)
{
    double value = 0;

    for (int i = degree; i >= 0; i--)
        value += coefficients[i] * std::pow(x, i);

    return value;
}

int main()
{
    int degree;
    std::cout << "Enter degree of polynomial: ";
    std::cin >> degree;

    std::vector<double> coefficients;
    coefficients.resize(degree + 1);

    for (int i = degree; i >= 0; i--)
    {
        std::cout << "Enter coefficient by x^" << i << ": ";
        std::cin >> coefficients[i];
    }

    double a, b, x0, fa, fb, fx0;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    fa=f(coefficients, degree, a);
    fb=f(coefficients, degree, b);
    if (fa * fb >= 0)
    {
        std::cout << "The function values at the ends of the interval do not have distinct signs \n";
        return 0;
    }
    x0 = (a + b) / 2;
    fx0 = f(coefficients, degree, x0);

    while (std::abs(fx0) > E && b - a > E)
    {
        if (fa * fx0 < 0)
            b = x0;
        else
        {
            a = x0;
            fa = fx0;
        }
        x0 = (a + b) / 2;
        fx0 = f(coefficients, degree, x0);
    }
    std::cout << "x0 = " << x0 << '\n';

    return 0;
}
