// http://www.careercup.com/question?id=4877486110277632
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
	double x;
	double y;
	Point(double _x = 0, double _y = 0): x(_x), y(_y) {};
};

double dist(const Point &p1, const Point &p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{
	int i, n;
	Point pout;
	vector<Point> vp;
	int min_i;
	double d, min_d;
	
	while (cin >> n && n > 0) {
		vp.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> vp[i].x >> vp[i].y;
		}
		cin >> pout.x >> pout.y;
		
		min_i = 0;
		min_d = dist(pout, vp[0]);
		for (i = 1; i < n; ++i) {
			d = dist(pout, vp[i]);
			min_i = d < min_d ? i : min_i;
		}
		cout << '(' << vp[min_i].x << ',' << vp[min_i].y << ')' << endl;
		cout << min_d << endl;
		vp.clear();
	}
	
	return 0;
}