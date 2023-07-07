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

    return sqrt(dx * dx + dy * dy);
}

double getArea(const Triangle& triangle) {
    double sideA = getSide(triangle.point1, triangle.point2);
    double sideB = getSide(triangle.point2, triangle.point3);
    double sideC = getSide(triangle.point3, triangle.point1);

    double halfPerimeter = (sideA + sideB + sideC) / 2;

    // Math formula
    return sqrt(halfPerimeter * (halfPerimeter - sideA) * (halfPerimeter - sideB) * (halfPerimeter - sideC));
}

void getTriangleAreas(const Triangle* triangles, double* areas, const int N) {
    for (int i = 0; i < N; ++i)
        areas[i] = getArea(triangles[i]);
}

void swap(double& num1, double& num2) {
    double temp = num1;
    num1 = num2;
    num2 = temp;
}

void swap(Triangle& triangle1, Triangle& triangle2) {
    Triangle temp = triangle1;
    triangle1 = triangle2;
    triangle2 = temp;
}

void sortTriangles(Triangle* triangles, double* areas, const int N) {

    for (int i = 0; i < N - 1; ++i) {
        int indexOfSmallest = i;

        for (int y = i + 1; y < N; ++y) {

            if (areas[y] < areas[indexOfSmallest])
                indexOfSmallest = y;

        }

        if (indexOfSmallest != i) {
            swap(areas[i], areas[indexOfSmallest]);
            swap(triangles[i], triangles[indexOfSmallest]);
        }

    }
}

void printPoint(const Point& point) {
    std::cout << point.x << " " << point.y;
}

void printTriangle(const Triangle& triangle) {
    printPoint(triangle.point1);
    std::cout << " ";
    printPoint(triangle.point2);
    std::cout << " ";
    printPoint(triangle.point3);
    std::cout << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    Triangle* triangles = new Triangle[N];
    double* areas = new double[N];

    /* Reading triangles */

    for (int i = 0; i < N; ++i) {
        readTriangle(triangles[i]);
    }

    std::cout << std::endl;

    getTriangleAreas(triangles, areas, N);

    /* Sorting triangles */

//    std::cout << "Before sorting:\n";
//    for (int i = 0; i < N; ++i)
//        std::cout << areas[i] << std::endl;

    sortTriangles(triangles, areas, N);

//    std::cout << "After sorting:\n";
//    for (int i = 0; i < N; ++i)
//        std::cout << areas[i] << std::endl;


//    for (int i = 0; i < N; ++i)
//        std::cout << triangles[i].point1.x << ", " << triangles[i].point1.y << std::endl;

    /* Printing triangles */

    for (int i = 0; i < N; ++i)
        printTriangle(triangles[i]);

    /* Deleting triangles */

    delete[] triangles;
    delete[] areas;
}