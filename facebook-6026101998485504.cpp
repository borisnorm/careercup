// http://www.careercup.com/question?id=6026101998485504
// Actually, I don't quite understand the problem. The poster of this problem gave it too vague..
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <xiosbase>
using namespace std;

class Solution {
public:
	void disperse(vector<int> &v, int m) {
		int n = (int)v.size();
		
		if (n <= 1) {
			return;
		}
		
		sort(v.begin(), v.end());
		int count;
		unordered_map<int, int> um;
		
		int i, j;
		
		i = 0;
		while (true) {
			j = i + 1;
			count = 1;
			while (j < n && v[i] == v[j]) {
				++j;
				++count;
			}
			um[v[i]] = count;
			i = j;
			if (i >= n) {
				break;
			}
		}
		
		unordered_map<int, int>::iterator umit, umit2;
		i = 0;
		while (!um.empty()) {
			count = 0;
			umit = um.begin();
			while (umit != um.end()) {
				v[i++] = umit->first;
				--(umit->second);
				++count;
				if (umit->second == 0) {
					// remove empty items to speed up the search.
					umit2 = umit;
					++umit;
					um.erase(umit2);
				} else {
					++umit;
				}
				
				if (count == m) {
					// pick at most m distinct elements at each round.
					break;
				}
			}
		}
	};
};

int main()
{
	int n, m;
	vector<int> v;
	Solution sol;
	int i;
	
	ios::sync_with_stdio(false);
	
	while (cin >> n && n > 0) {
		v.resize(n);
		
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		cin >> m;
		sol.disperse(v, m);
		for (i = 0; i < n; ++i) {
			i ? cout << ' ', 1 : 1;
			cout << v[i];
		}
		cout << endl;
		
		v.clear();
	}
	
	return 0;
}