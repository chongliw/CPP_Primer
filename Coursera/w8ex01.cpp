//
// Created by Chongli Wang on 10/28/15.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point(int x_, int y_) : x(x_), y(y_) { }
};

bool operator<(const Point &p1, const Point &p2) {
    return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
}

bool isDiff(const Point &p1, const Point &p2) {
    return (p1.x != p2.x) && (p1.y != p2.y);
}

ostream &operator<<(ostream &os, const Point &rhs) {
    os << rhs.x << "," << rhs.y;
    return os;
}

int main() {
    int t;
    int x, y;
    cin >> t;
    vector<Point> v;
    while (t--) {
        cin >> x >> y;
        v.push_back(Point(x, y));
    }
    vector<Point>::iterator i, j;
    sort(v.begin(), v.end());
    set<Point> set_v(v.begin(), v.end());
    int nTotalNum = 0;
    for (i = v.begin(); i < v.end(); ++i)
        for (j = i + 1; j < v.end(); ++j)
            if (isDiff(*i, *j)) {
                Point p2(i->x, j->y);
                Point p3(j->x, i->y);
                if (set_v.count(p2) && set_v.count(p3)) {
                    ++nTotalNum;
                }

            }
    cout << nTotalNum / 2 << endl; // two diagonal lines, counted twice
    return 0;
}

//Input:
//6
//2 3
//2 5
//4 5
//4 4
//2 4
//4 3
//Output:
//3