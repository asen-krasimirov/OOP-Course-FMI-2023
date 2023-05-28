#include "Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(3)
{
    setPoint(0, x1, y1);
    setPoint(1, x2, y2);
    setPoint(2, x3, y3);
}

bool Triangle::intersectsWith(const Shape *other) const {
    return other->intersectsWithTriangle(this);
}

bool Triangle::intersectsWithTriangle(const Triangle *triangle) const {
    std::cout << "Formula for Triangle intersecting Triangle" << std::endl;
    return true;
}

bool Triangle::intersectsWithRectangle(const Rectangle *rectangle) const {
    std::cout << "Formula for Rectangle intersecting Triangle" << std::endl;
    return true;
}

bool Triangle::intersectsWithCircle(const Circle *circle) const {
    std::cout << "Formula for Circle intersecting Triangle" << std::endl;
    return true;
}
