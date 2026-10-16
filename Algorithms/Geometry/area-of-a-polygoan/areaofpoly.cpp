/**
 * @file areaofpoly.cpp
 * @brief Area of a Polygon (Shoelace Formula / Surveyor's Formula)
 * 
 * Computes the 2D planar area of an arbitrary non-self-intersecting polygon
 * with vertices ordered clockwise or counterclockwise.
 * 
 * Time Complexity:  O(n) where n is the number of vertices
 * Space Complexity: O(1) auxiliary
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

// 2D Cross Product of vectors OA and OB (where O is origin): a.x * b.y - a.y * b.x
double cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

// Computes polygon area using the Shoelace Formula
double polygon_area(const vector<Point> &vertices) {
    int n = vertices.size();
    if (n < 3) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += cross_product(vertices[i], vertices[(i + 1) % n]);
    }
    return fabs(sum) / 2.0;
}

int main() {
    int n;
    while (cin >> n && n >= 3) {
        vector<Point> vertices(n);
        for (int i = 0; i < n; i++) {
            cin >> vertices[i].x >> vertices[i].y;
        }
        printf("Area: %.6f\n", polygon_area(vertices));
    }
    return 0;
}
