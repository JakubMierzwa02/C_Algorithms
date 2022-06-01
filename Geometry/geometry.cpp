#include <iostream>

struct Point
{
    float x;
    float y;
};

void loadPoint(std::string info, Point &p)
{
    std::cout << info << '\n';
    std::cout << "x = ";
    std::cin >> p.x;
    std::cout << "y = ";
    std::cin >> p.y;
}

// A function that checks if the points lie on the same side of the straight line
bool pointOnTheSameSide(float a, float b, float c, Point p1, Point p2)
{
    return ((a * p1.x + b * p1.y + c) * (a * p2.x + b * p2.y + c) > 0);
}

int main()
{
    /*
        Location of points in relation to the line and segment
    */

    // Location of points relative to the line
    float a, b, c;
    Point p1, p2;
    std::cout << "Enter the values a, b, c: ";
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;

    loadPoint("Enter the coordinates of the point p1. ", p1);
    loadPoint("Enter the coordinates of the point p2. ", p2);

    if (pointOnTheSameSide(a, b, c, p1, p2))
        std::cout << "The points are on the same side of the straight line. \n";
    else
        std::cout << "The points are not on the same side of the straight line. \n";

    return 0;
}
