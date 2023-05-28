#pragma once
#include "../Shape/Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(int x1, int y1, int x3, int y3);

    bool intersectsWith(const Shape *other) const override;

    bool intersectsWithTriangle(const Triangle *triangle) const override;
    bool intersectsWithRectangle(const Rectangle *rectangle) const override;
    bool intersectsWithCircle(const Circle *circle) const override;

};
