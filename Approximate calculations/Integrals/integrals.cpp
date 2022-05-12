#include <iostream>
#include <vector>
#include <cmath>

double f(const std::vector<double> coefficients, const int degree, double x)
{
    double value = 0;

    for (int i = degree; i >= 0; i--)
        value += coefficients[i] * std::pow(x, i);

    return value;
}

/// Rectangle method
double rectangle(double a, double b, int n, std::vector<double> coefficients, int degree)
{
    double x, dx, s = 0;

    dx = (b - a) / n;
    x = a;
    for (int i = 1; i <= n; i++)
    {
        x += dx;
        s += dx * f(coefficients, degree, x);
    }
    return s;
}

/// Trapezoidal method
double trapezoidal(double a, double b, int n, std::vector<double> coefficients, int degree)
{
    double x, dx, s = 0, f1, f2;

    dx = (b - a) / n;
    x = a;
    f1 = f(coefficients, degree, x);
    for (int i = 1; i <= n; i++)
    {
        x += dx;
        f2 = f(coefficients, degree, x);
        s += dx * (f1 + f2) / 2;
        f1 = f2;
    }
    return s;
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

    double a, b;
    int n;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "n = ";
    std::cin >> n;

    std::cout << "The area of field (rectangle method): " << rectangle(a, b, n, coefficients, degree) << '\n';
    std::cout << "The area of field (trapezoidal method): " << trapezoidal(a, b, n, coefficients, degree) << '\n';

    return 0;
}

