#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

struct Point {
    int x;
    double y;
};

void getPointInfo(Point &p) {
    cin >> p.x >> p.y;
}

void printPoint(Point &p) {
    cout << "(" << p.x << ", " << p.y << ")";
}

double getDistanceBetweenTwoPoints(const Point &p1, const Point &p2) {
    int dx = pow(p2.x - p1.x, 2);
    int dy = pow(p2.y - p1.y, 2);

    return sqrt(dx + dy);
}

double getDistanceFromCenter(const Point &p) {
    Point center{0, 0};

    return getDistanceBetweenTwoPoints(p, center);
}

int main() {
    Point p1{ 1, 1};
    Point p2{ 2, 2};

    cout << getDistanceBetweenTwoPoints(p1, p2);
    return 0;
}