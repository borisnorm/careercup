// http://www.careercup.com/question?id=5120588943196160
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct Point {
	int x;
	int y;
	Point(int _x = 0, int _y = 0): x(_x), y(_y) {};
};

struct hashFunctor {
	size_t operator () (const Point &p) {
		return p.x * 10000 + p.y;
	};
};

struct equalFunctor {
	bool operator () (const Point &p1, const Point &p2) {
		return p1.x == p2.x && p1.y == p2.y;
	};
};

typedef unordered_set<Point, hashFunctor, equalFunctor> point_set;

int twoArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

bool inside(int x[3], int y[3], int px, int py)
{
	int sum = 0;
	
	sum += twoArea(x[0], y[0], x[1], y[1], px, py);
	sum += twoArea(x[1], y[1], x[2], y[2], px, py);
	sum += twoArea(x[2], y[2], x[0], y[0], px, py);
	return sum == twoArea(x[0], y[0], x[1], y[1], x[2], y[2]);
}

void DFS(int x[3], int y[3], int px, int py, point_set &um, point_set &visited)
{
	static const int dir[4][2] = {
		{-1, 0}, 
		{+1, 0}, 
		{0, -1}, 
		{0, +1}
	};
	int i;
	int newx, newy;
	
	visited.insert(Point(px, py));
	um.insert(Point(px, py));
	
	for (i = 0; i < 4; ++i) {
		newx = px + dir[i][0];
		newy = py + dir[i][1];
		if (visited.find(Point(newx, newy)) == visited.end() && 
			inside(x, y, newx, newy)) {
			DFS(x, y, newx, newy, um, visited);
		}
	}
}

void insidePoints(int x[3], int y[3], vector<Point> &points)
{
	point_set um;
	point_set visited;
	int mx, my;
	
	mx = (x[0] + x[1] + x[2]) / 3;
	my = (y[0] + y[1] + y[2]) / 3;
	DFS(x, y, mx, my, um, visited);
	
	point_set::const_iterator usit;
	for (usit = um.begin(); usit != um.end(); ++usit) {
		points.push_back(Point(usit->x, usit->y));
	}
	um.clear();
	visited.clear();
}

int main()
{
	int x[3];
	int y[3];
	vector<Point> points;
	int i;
	int n;
	
	while (cin >> x[0] >> y[0]) {
		cin >> x[1] >> y[1];
		cin >> x[2] >> y[2];
		insidePoints(x, y, points);
		n = (int)points.size();
		for (i = 0; i < n; ++i) {
			cout << points[i].x << ' ' << points[i].y << endl;
		}
		points.clear();
	}
	
	return 0;
}