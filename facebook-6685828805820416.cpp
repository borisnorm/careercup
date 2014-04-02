// http://www.careercup.com/question?id=6685828805820416
#include <cstdio>
#include <vector>
using namespace std;

struct Point {
	int x;
	int y;
	Point(int _x = 0, int _y = 0): x(_x), y(_y) {};
};

class Solution {
public:
	bool canReachAll(vector<vector<Point> > &grid) {
		int n, m;
		
		n = (int)grid.size();
		if (n == 0) {
			return false;
		}
		m = (int)grid[0].size();
		if (m == 0) {
			return false;
		}
		
		int cc = n * m;
		Point p(0, 0);
		Point next_p;

		while (true) {
			next_p = grid[p.x][p.y];
			grid[p.x][p.y].x = n;
			grid[p.x][p.y].y = m;
			--cc;
			p = next_p;
			if (p.x < 0 && p.y < 0) {
				// null terminated
				break;
			}
			if (grid[p.x][p.y].x == n && grid[p.x][p.y].y == m) {
				// already visited
				break;
			}
		}
		
		return cc == 0;
	};
};

int main()
{
	vector<vector<Point> > grid;
	int n, m;
	int i, j;
	Solution sol;
	
	while (scanf("%d%d", &n, &m) == 2 && (n > 0 && m > 0)) {
		grid.resize(n);
		for (i = 0; i < n; ++i) {
			grid[i].resize(m);
		}
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf("%d%d", &grid[i][j].x, &grid[i][j].y);
			}
		}
		printf(sol.canReachAll(grid) ? "Yes\n" : "No\n");
	}
	
	return 0;
}