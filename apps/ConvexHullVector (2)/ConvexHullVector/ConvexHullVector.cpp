#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
using namespace std;

using Point = pair<double, double>;

// Returns the orientation of the triplet (p, q, r)
int orientation(Point p, Point q, Point r) {
    double val = (q.second - p.second) * (r.first - q.first) -
        (q.first - p.first) * (r.second - q.second);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// Returns a reference to a vector of points that define the convex hull of the given points
vector<Point>& convexHullByBruteForce(vector<Point>& pointsVector) {
    int n = pointsVector.size();
    if (n < 3) return pointsVector; // not enough points to form a convex hull

    // Initialize the convex hull with the first three points
    vector<Point>& hull = pointsVector;
    sort(hull.begin(), hull.end());
    hull.resize(unique(hull.begin(), hull.end()) - hull.begin());
    int j = 2;
    while (j < n && orientation(hull[0], hull[1], hull[j]) != 2) j++;
    reverse(hull.begin() + j, hull.end());

    // Add the remaining points to the convex hull
    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], pointsVector[i]) != 2)
            hull.pop_back();
        hull.push_back(pointsVector[i]);
    }

    return hull;
}

// Returns a reference to a vector of points that define the convex hull that merges the two given convex hulls
vector<Point>& mergeHulls(vector<Point>& leftHull, vector<Point>& rightHull) {
    int n1 = leftHull.size(), n2 = rightHull.size();

    // Find the leftmost point of the right convex hull and the rightmost point of the left convex hull
    int leftMost = 0, rightMost = 0;
    for (int i = 1; i < n1; i++)
        if (leftHull[i].first < leftHull[leftMost].first)
            leftMost = i;
    for (int i = 1; i < n2; i++)
        if (rightHull[i].first > rightHull[rightMost].first)
            rightMost = i;

    // Initialize the result vector with the two extreme points
    vector<Point>& hull = leftHull;
    hull.push_back(rightHull[rightMost]);

    // Add the upper hull points of the left convex hull
    int p = leftMost, q;
    do {
        // Add the current point to the convex hull
        hull.push_back(leftHull[p]);

        // Find the next point in the upper hull of the left convex hull
        q = (p + 1) % n1;
        for (int i = 0; i < n1; i++)
            if (orientation(leftHull[p], leftHull[i], rightHull[rightMost]) == 2)
                q = i;

        // Move to the next point
        p = q;
    } while (p != leftMost);

    // Add the upper hull points of the right convex hull
    p = rightMost;
    do {
        // Add the current point to the convex hull
        hull.push_back(rightHull[p]);
        // Find the next point in the upper hull of the right convex hull
        q = (p + 1) % n2;
        for (int i = 0; i < n2; i++)
            if (orientation(rightHull[p], rightHull[i], leftHull[leftMost]) == 1)
                q = i;

        // Move to the next point
        p = q;
    } while (p != rightMost);

    // Remove the last point, which is the same as the first point
    hull.pop_back();

    return hull;
}

// Returns a reference to a vector of points that define the convex hull of the given points
vector<Point>& convexHullByDandC(vector<Point>& pointsVector) {
    int n = pointsVector.size();
    if (n < 3) return pointsVector; // not enough points to form a convex hull
    // Divide the points in two halves
    vector<Point> leftHalf(pointsVector.begin(), pointsVector.begin() + n / 2);
    vector<Point> rightHalf(pointsVector.begin() + n / 2, pointsVector.end());

    // Recursively compute the convex hull of each half
    vector<Point>& leftHull = convexHullByDandC(leftHalf);
    vector<Point>& rightHull = convexHullByDandC(rightHalf);

    // Merge the two convex hulls
    return mergeHulls(leftHull, rightHull);
}

// Helper function to print a vector of points
void printPoints(vector<Point>& pointsVector) {
    for (Point& point : pointsVector) {
        cout << "(" << point.first << ", " << point.second << ")" << endl;
    }
}

int main() {
    vector<Point> points = { };
    ifstream input_file("input.txt");
    int x, y;
    while (input_file >> x >> y) {
        points.push_back({ x, y });
    }
    input_file.close();
    cout << "Points:" << endl;
    printPoints(points);
    auto start_time = std::chrono::high_resolution_clock::now();
    vector<Point>& hull1 = convexHullByBruteForce(points);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count();

    std::cout << "Execution time: " << duration_seconds << " seconds" << std::endl;
    cout << "Convex Hull by Brute Force:" << endl;
    printPoints(hull1);

    auto start_time = std::chrono::high_resolution_clock::now();
    vector<Point>& hull2 = convexHullByDandC(points);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count();
    cout << "Convex Hull by Divide and Conquer:" << endl;
    printPoints(hull2);


    // Open the output file
    ofstream output_file("output.txt");

    // Write the points to the output file
    for (const auto& point : points) {
        output_file << point << " " << point << endl;
    }

    // Close the output file
    output_file.close();
    return 0;
}
