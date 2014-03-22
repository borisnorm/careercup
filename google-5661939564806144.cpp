// http://www.careercup.com/question?id=5661939564806144
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	void printDiagonal(vector<vector<int> > &matrix) {
		int n, m;
		
		n = (int)matrix.size();
		if (n == 0) {
			return;
		}
		m = (int)matrix[0].size();
		if (m == 0) {
			return;
		}
		
		int i, j;
		bool first;
		
		for (i = 0; i < n + m; ++i) {
			first = true;
			for (j = (i < m ? i : m - 1); j >= 0; --j) {
				if (i - j < 0 || i - j > n - 1) {
					break;
				}
				printf((first ? "%d" : " %d"), matrix[i - j][j]);
				first = false;
			}
			printf("\n");
		}
	};
};