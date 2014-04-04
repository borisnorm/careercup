// http://www.careercup.com/question?id=5761467236220928
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool findTwoSum(vector<int> &v, int target) {
		int n = (int)v.size();
		
		if (n < 2) {
			return false;
		}
		
		sort(v.begin(), v.end());
		int i, j;
		int sum;
		
		i = 0;
		j = n - 1;
		while (i < j) {
			sum = v[i] + v[j];
			if (sum < target) {
				++i;
			} else if (sum > target) {
				--j;
			} else {
				return true;
			}
		}
		
		return false;
	};
};

int main()
{
	int i;
	int n;
	vector<int> v;
	int target;
	Solution sol;
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		cin >> target;
		cout << (sol.findTwoSum(v, target) ? "True" : "False") << endl;
		v.clear();
	}
	
	return 0;
}