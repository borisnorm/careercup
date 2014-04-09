// http://www.careercup.com/question?id=24308662
// nobody said the elements in both arrays are unique, why would bitset work?
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	void mergeIntersection(vector<int> &a1, vector<int> &a2, vector<int> &intersect) {
		if (a1.size() > a2.size()) {
			mergeIntersection(a2, a1, intersect);
			return;
		}
		unordered_map<int, pair<int, int> > um;
		int n1, n2;
		int i;
		
		n1 = (int)a1.size();
		n2 = (int)a2.size();
		unordered_map<int, pair<int, int> >::iterator it;
		
		for (i = 0; i < n1; ++i) {
			it = um.find(a1[i]);
			if (it == um.end()) {
				um[a1[i]] = make_pair(1, 0);
			} else {
				++it->second.first;
			}
		}
		
		for (i = 0; i < n2; ++i) {
			it = um.find(a2[i]);
			if (it != um.end()) {
				++it->second.second;
			}
		}
		
		intersect.clear();
		for (it = um.begin(); it != um.end(); ++it) {
			n1 = min(it->second.first, it->second.second);
			for (i = 0; i < n1; ++i) {
				intersect.push_back(it->first);
			}
		}
		
		um.clear();
	};
};

int main()
{
	int n1, n2, n;
	vector<int> a1, a2;
	vector<int> intersect;
	int i;
	Solution sol;
	
	while (cin >> n1 >> n2 && (n1 > 0 && n2 > 0)) {
		a1.resize(n1);
		a2.resize(n2);
		for (i = 0; i < n1; ++i) {
			cin >> a1[i];
		}
		for (i = 0; i < n2; ++i) {
			cin >> a2[i];
		}
		sol.mergeIntersection(a1, a2, intersect);
		
		cout << '{';
		n = (int)intersect.size();
		for (i = 0; i < n; ++i) {
			i ? (cout << ' '), 1 : 1;
			cout << intersect[i];
		}
		cout << '}' << endl;
	}
	
	return 0;
}