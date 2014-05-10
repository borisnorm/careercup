// http://www.careercup.com/question?id=5684901156225024
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void arrangeArray(vector<int> &v) {
		int n;
		int i;
		
		n = (int)v.size();
		if (n < 2) {
			return;
		}
		
		int flag = 0;
		for (i = 0; i < n - 1; ++i) {
			if (flag ? v[i] < v[i + 1] : v[i] > v[i + 1]) {
				myswap(v[i], v[i + 1]);
			}
			flag = !flag;
		}
	};
private:
	void myswap(int &x, int &y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
};

int main()
{
	int n;
	int i;
	vector<int> v;
	Solution sol;
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sol.arrangeArray(v);
		
		for (i = 0; i < n; ++i) {
			cout << v[i];
			cout << (i == n - 1 ? '\n' : ' ');
		}
		
		v.clear();
	}
	
	return 0;
}