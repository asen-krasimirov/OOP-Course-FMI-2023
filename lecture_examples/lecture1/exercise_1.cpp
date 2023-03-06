#include <iostream>
#include <cmath>


struct Point {
    int x;
    int y;
};

struct Triangle {
    Point point1;
    Point point2;
    Point point3;
};

void readPoint(Point& point) {
    std::cin >> point.x >> point.y;
}

void readTriangle(Triangle& triangle) {
    readPoint(triangle.point1);
    readPoint(triangle.point2);
    readPoint(triangle.point3);
}

double getSide(const Point& point1, const Point& point2) {
    double dx = point1.x - point2.x;
    double dy = point1.y - point2.y;

    return sqrt(dx * dx - dy * dy);
}

double getArea(const Triangle& triangle) {
    double sideA = getSide(triangle.point1, triangle.point2);
    double sideB = getSide(triangle.point2, triangle.point3);
    double sideC = getSide(triangle.point3, triangle.point1);

    double halfPerimeter = (sideA + sideB + sideC) / 2;

    // Math formula
    return sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC));
}

int main() {
    int N;
    std::cin >> N;

    Triangle* triangles = new Triangle[N];

    for (int i = 0; i < N; ++i) {
        readTriangle(triangles[i]);
    }

    std::cout << std::endl;

    /*
    for (int i = 0; i < N; ++i) {
        std::cout << triangles[i].point1.x << ", " << triangles[i].point1.y << std::endl;
    }
    */
}