// http://www.careercup.com/question?id=4877486110277632
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
	double x;
	double y;
	Point(double _x = 0, double _y = 0): x(_x), y(_y) {};
	
	Point operator - (const Point &other) {
		return Point(x - other.x, y - other.y);
	};

	Point operator + (const Point &other) {
		return Point(x + other.x, y + other.y);
	};

	double operator * (const Point &other) {
		return x * other.x + y * other.y;
	};
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
	Point center;
	Point v0, vout;
	// the angle between OM and a line of center
	double angle;
	// 2 * pi / n
	double side_angle;
	const double pi = 3.1415926;
	double d;
	
	while (cin >> n && n > 0) {
		vp.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> vp[i].x >> vp[i].y;
			
		}
		cin >> center.x >> center.y;
		cin >> pout.x >> pout.y;
		
		v0 = vp[0] - center;
		vout = pout - center;
		
		side_angle = 2 * pi / n;
		angle = arccos((v0 * vout) / (dist(vp[0], center) * dist(pout, center)));
		d = angle / side_angle;
		// Here I assume the points are arranged in clockwise order.
		i = d - floor(d) < 0.5 ? floor(d) : floor(d) + 1;
		cout << vp[i].x << ' ' << vp[i].y << endl;
		
		vp.clear();
	}
	
	return 0;
}