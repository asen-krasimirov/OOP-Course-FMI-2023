#pragma once
#include "../Shape/Shape.h"


class Circle : public Shape {
private:
    double radius;

public:
    Circle(int x, int y, double radius);

    bool intersectsWith(const Shape *other) const override;

    bool intersectsWithTriangle(const Triangle *triangle) const override;
    bool intersectsWithRectangle(const Rectangle *rectangle) const override;
    bool intersectsWithCircle(const Circle *circle) const override;

};
