// http://www.careercup.com/question?id=5684901156225024
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	void arrangeArray(vector<int> &v) {
		int n;
		
		n = (int)v.size();
		if (n < 2) {
			return;
		}
		sort(v.begin(), v.end());
		interleaveInPlace(v);
	};
private:
	void interleaveInPlace(vector<int> &v) {
		int i, n;
		int idx1, idx2;
		int tmp1, tmp2;
		
		n = (int)v.size();
		if (n <= 2) {
			return;
		}

		idx1 = n - 1;
		tmp1 = v[idx1];
		for (i = 0; i < n - 1; ++i) {
			idx2 = (idx1 >= (n + 1) / 2) ? (2 * n - 1 - 2 * idx1) : (idx1 * 2);

			tmp2 = v[idx2];
			v[idx2] = tmp1;
			tmp1 = tmp2;

			idx1 = idx2;
		}
	};
};