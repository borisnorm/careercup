// http://www.careercup.com/question?id=5761467236220928
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
	bool findTwoSum(vector<int> &v, int target) {
		int n = (int)v.size();
		unordered_set<int> us;
		
		if (n < 2) {
			return false;
		}		
		
		int i;
		for (i = 0; i < n; ++i) {
			if (us.find(target - v[i]) != us.end()) {
				us.clear();
				return true;
			} else {
				us.insert(v[i]);
			}
		}
		
		us.clear();
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