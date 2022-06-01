#include <iostream>
#include <cmath>

const float EPS = 0.0001;

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

// A function that calculates the determinant of a matrix
float det(float x1, float y1, float x2, float y2, float x3, float y3)
{
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}

// A function that checks whether the point P belongs to the segment AB
bool pointInTheSegment(Point A, Point B, Point P)
{
    float w = det(A.x, A.y, B.x, B.y, P.x, P.y);
    if (std::abs(w) > EPS)
        return false;

    return (P.x >= std::min(A.x, B.x) && P.x <= std::max(A.x, B.x) && P.y >= std::min(A.y, B.y) && P.y <= std::max(A.y, B.y));
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

    // Affiliation of a point to a segment
    Point A, B, P;

    loadPoint("Enter the coordinates of the point A. ", A);
    loadPoint("Enter the coordinates of the point B. ", B);
    loadPoint("Enter the coordinates of the point P. ", P);

    if (pointInTheSegment(A, B, P))
        std::cout << "Point P belongs to the segment AB. \n";
    else
        std::cout << "Point P does not belong to the segment AB. \n";

    return 0;
}
