// http://www.careercup.com/question?id=4716965625069568
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	void solve(vector<vector<int> > &matrix) {
		// -1 for guard
		// -2 for blockade
		// 0 for room
		// > 0 for distance
		
		n = (int)matrix.size();
		if (n == 0) {
			return;
		}
		m = (int)matrix[0].size();
		if (m == 0) {
			return;
		}
		
		int i, j;
		
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (matrix[i][j] == -1) {
					doBFS(matrix, i, j);
				}
			}
		}
	};
private:
	int n, m;
	
	bool inBound(int x, int y) {
		return x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1;
	}
	
	void doBFS(vector<vector<int> > &matrix, int x, int y) {
		queue<int> q;
		static int dd[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
		int tmp;
		int xx, yy;
		int i;
		int dist;
		
		q.push(x * m + y);
		while (!q.empty()) {
			tmp = q.front();
			q.pop();
			x = tmp / m;
			y = tmp % m;
			dist = matrix[x][y] > 0 ? matrix[x][y] : 0;
			for (i = 0; i < 4; ++i) {
				xx = x + dd[i][0];
				yy = y + dd[i][1];
				if (!inBound(xx, yy) || matrix[xx][yy] < 0 || 
					(matrix[xx][yy] > 0 && matrix[xx][yy] <= dist + 1)) {
					// out of boundary
					// a guard or a blockade
					// the distance is no shorter
					continue;
				}
				matrix[xx][yy] = dist + 1;
				q.push(xx * m + yy);
			}
		}
	}
};