// http://www.careercup.com/question?id=5634470967246848
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<vector<int> > v;
	queue<int> q;
	int i, j, k;
	int x, y;
	int dx, dy;
	int d[4][2] = {
		{-1, 0}, 
		{+1, 0}, 
		{0, -1}, 
		{0, +1}
	};
	int back[4] = {1, 0, 3, 2};
	vector<vector<int> > trace;
	vector<int> path;
	int tmp;
	
	while (scanf("%d", &n) == 1 && n > 0) {
		v.resize(n);
		trace.resize(n);
		for (i = 0; i < n; ++i) {
			v[i].resize(n);
			trace[i].resize(n);
		}
		
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				scanf("%d", &v[i][j]);
				if (v[i][j] == 3) {
					dx = i;
					dy = j;
				}
			}
		}
		
		v[0][0] = -1;
		q.push(0);
		while (v[dx][dy] > 0 && !q.empty()) {
			tmp = q.front();
			q.pop();
			i = tmp / n;
			j = tmp % n;
			for (k = 0; k < 4; ++k) {
				x = i + d[k][0];
				y = j + d[k][1];
				if (x < 0 || x > n - 1 || y < 0 || y > n - 1) {
					continue;
				}
				if (v[x][y] > 0) {
					v[x][y] = v[i][j] - 1;
					trace[x][y] = back[k];
					q.push(x * n + y);
				}
			}
		}
		while (!q.empty()) {
			q.pop();
		}
		
		if (v[dx][dy] < 0) {
			x = dx;
			y = dy;
			while (x || y) {
				path.push_back(x * n + y);
				i = x + d[trace[x][y]][0];
				j = y + d[trace[x][y]][1];
				x = i;
				y = j;
			}
			path.push_back(0);
			while (!path.empty()) {
				x = path.back() / n;
				y = path.back() % n;
				printf("(%d, %d)", x, y);
				path.pop_back();
			}
			putchar('\n');
		} else {
			printf("Unreachable.\n");
		}
		
		for (i = 0; i < n; ++i) {
			v[i].clear();
			trace[i].clear();
		}
		v.clear();
		trace.clear();
		path.clear();
	}
	
	return 0;
}