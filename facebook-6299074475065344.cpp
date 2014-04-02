// http://www.careercup.com/question?id=6299074475065344
#include <vector>
using namespace std;

class Solution {
public:
	int maxRectangleWithAllOnes(vector<vector<int> > &v) {
		n = (int)v.size();
		if (n == 0) {
			return 0;
		}
		m = (int)v[0].size();
		if (m == 0) {
			return 0;
		}
		
		int i, j;
		int res, max_res;
		
		histogram.resize(m);
		left.resize(m);
		right.resize(m);
		fill_n(histogram.begin(), m, 0);
		max_res = 0;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				histogram[j] = v[i][j] ? histogram[j] + v[i][j]: 0;
				res = maxRectangleInHistogram(histogram);
				max_res = res > max_res ? res : max_res;
			}
		}
		
		histogram.clear();
		left.clear();
		right.clear();
		
		return max_res;
	};
private:
	vector<int> histogram;
	vector<int> left;
	vector<int> right;
	int n, m;
	
	int maxRectangleInHistogram(vector<int> &histogram) {
		int i;
		int j;
		
		left[0] = 0;
		for (i = 1; i <= n - 1; ++i) {
			j = i - 1;
			left[i] = i;
			while (j >= 0 && histogram[i] <= histogram[j]) {
				left[i] = left[j];
				j = left[j] - 1;
			}
		}
		
		right[n - 1] = n - 1;
		for (i = n - 2; i >= 0; --i) {
			j = i + 1;
			right[i] = i;
			while (j <= n - 1 && histogram[i] <= histogram[j]) {
				right[i] = right[j];
				j = right[j] + 1;
			}
		}
		
		int max_res, res;
		max_res = 0;
		for (i = 0; i < n; ++i) {
			res = histogram[i] * (right[i] - left[i] + 1);
			max_res = res > max_res ? res : max_res;
		}
		
		return max_res;
	};
};

int main()
{
	int n, m;
	int i, j;
	vector<vector<int> > v;
	Solution sol;
	
	while (scanf("%d%d", &n, &m) == 2 && (n > 0 && m > 0)) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			v[i].resize(m);
		}
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				scanf("%d", &v[i][j]);
			}
		}
		printf("%d\n", sol.maxRectangleWithAllOnes(v));
		
		for (i = 0; i < n; ++i) {
			v[i].clear();
		}
		v.clear();
	}
	
	return 0;
}