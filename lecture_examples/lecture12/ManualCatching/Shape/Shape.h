#pragma once

#include <iostream>
#include <cmath>

class Triangle;
class Rectangle;
class Circle;

class Shape {
protected:
    struct point {
        point() : x(0), y(0) {}

        point(int x, int y) : x(x), y(y) {}

        int x;
        int y;

        double getDist(const point &other) const {
            int dx = x - other.x;
            int dy = y - other.y;

            return sqrt(dx * dx + dy * dy);
        }
    };

    const point &getPointAtIndex(size_t index) const;

private:
    point *points;
    size_t pointsCount;

    void copyFrom(const Shape &other);

    void free();

public:
    Shape(size_t pointsCount);

    Shape(const Shape &other);

    Shape &operator=(const Shape &other);

    virtual ~Shape();

    void setPoint(size_t pointIndex, int x, int y);

    virtual bool intersectsWith(const Shape *other) const = 0;

    virtual bool intersectsWithTriangle(const Triangle *triangle) const = 0;
    virtual bool intersectsWithRectangle(const Rectangle *triangle) const = 0;
    virtual bool intersectsWithCircle(const Circle *triangle) const = 0;

};
