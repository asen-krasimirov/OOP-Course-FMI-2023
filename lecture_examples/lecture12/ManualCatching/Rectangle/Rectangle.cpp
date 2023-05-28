#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3) : Shape(4)
{
    setPoint(0, x1, y1);
    setPoint(1, x1, y3);
    setPoint(2, x3, y3);
    setPoint(3, x3, y1);
}

bool Rectangle::intersectsWith(const Shape *other) const {
    return other->intersectsWithRectangle(this);
}

bool Rectangle::intersectsWithTriangle(const Triangle *triangle) const {
    std::cout << "Formula for Triangle intersecting Rectangle" << std::endl;
    return true;
}

bool Rectangle::intersectsWithRectangle(const Rectangle *rectangle) const {
    std::cout << "Formula for Rectangle intersecting Rectangle" << std::endl;
    return true;
}

bool Rectangle::intersectsWithCircle(const Circle *circle) const {
    std::cout << "Formula for Circle intersecting Rectangle" << std::endl;
    return true;
}
