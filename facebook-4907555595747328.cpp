// http://www.careercup.com/question?id=4907555595747328
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Line {
	double a;
	double b;
	double c;
	Line(double _a = 0, double _b = 0, double _c = 0): a(_a), b(_b), c(_c) {};
};

struct Point {
	double x;
	double y;
	Point(double _x = 0, double _y = 0): x(_x), y(_y) {};
};

double calcDist(const Point &p, const Line &line)
{
	return abs(line.a * p.x + line.b * p.y + line.c) / sqrt(line.a * line.a + line.b * line.b);
}

void calcLine(const Point &p1, const Point &p2, Line &line)
{
	line.a = p2.y - p1.y;
	line.b = p1.x - p2.x;
	line.c = -((line.a * p1.x + line.b * p1.y) + (line.a * p2.x + line.b * p2.y)) / 2.0;
}

int main()
{
	vector<Point> p;
	int n;
	Line line, min_line;
	int i, j, k;
	double dist, min_dist;
	
	while (cin >> n && n > 0) {
		p.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> p[i].x >> p[i].y;
		}
		
		do {
			if (n == 1) {
				line = Line(0, 1, -p[0].y);
				break;
			} else if (n == 2) {
				min_dist = 0;
				calcLine(p[0], p[1], min_line);
				break;				
			}
			
			min_dist = -1;
			for (i = 0; i < n; ++i) {
				for (j = i + 1; j < n; ++j) {
					dist = 0;
					calcLine(p[i], p[j], line);
					for (k = 0; k < n; ++k) {
						if (k == i && k == j) {
							continue;
						}
						dist += calcDist(p[k], line);
					}
					if (min_dist < 0 || dist < min_dist) {
						min_dist = dist;
						min_line = line;
					}
				}
			}
		} while (0);
		
		if (min_line.a != 0.0) {
			cout << min_line.a << 'x';
		}
		if (min_line.b != 0.0) {
			cout << setiosflags(ios::showpos) << min_line.b << 'y';
		}
		if (min_line.c != 0.0) {
			cout << min_line.c;
		}
		cout << resetiosflags(ios::showpos) << "=0" << endl;
		cout << min_dist << endl;
	}
	
	return 0;
}