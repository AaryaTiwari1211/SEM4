#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
struct Point
{
    int x, y;
};
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
double calculateArea(vector<Point> &vertices)
{
    int numVertices = vertices.size();

    int numInteriorPoints = 0, numBoundaryPoints = 0;
    for (int i = 0; i < numVertices; i++)
    {
        int j = (i + 1) % numVertices;
        int dx = abs(vertices[j].x - vertices[i].x);
        int dy = abs(vertices[j].y - vertices[i].y);
        numBoundaryPoints += gcd(dx, dy);
    }
    double area = (numInteriorPoints + numBoundaryPoints / 2.0 - 1);

    return area;
}

int main()
{
    int n;
    cin >> n;
    vector<Point> vertices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vertices[i].x >> vertices[i].y;
    }
    double area = calculateArea(vertices);
    int numTrees = area - n / 2 + 1;

    cout << "Area of polygon: " << area << endl;
    cout << "Number of trees that can be planted: " << numTrees << endl;

    return 0;
}
