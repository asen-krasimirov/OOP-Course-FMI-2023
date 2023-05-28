#include "Circle.h"

namespace {
    const double PI = 3.1415;
}

Circle::Circle(int x, int y, double radius) : Shape(1), radius(radius)
{
    setPoint(0, x, y);
}

bool Circle::intersectsWith(const Shape *other) const {
    return other->intersectsWithCircle(this);
}

bool Circle::intersectsWithTriangle(const Triangle *triangle) const {
    std::cout << "Formula for Triangle intersecting Circle" << std::endl;
    return true;
}

bool Circle::intersectsWithRectangle(const Rectangle *rectangle) const {
    std::cout << "Formula for Rectangle intersecting Circle" << std::endl;
    return true;
}

bool Circle::intersectsWithCircle(const Circle *circle) const {
    std::cout << "Formula for Circle intersecting Circle" << std::endl;
    return true;
}
