// http://www.careercup.com/question?id=24308662
// nobody said the elements in both arrays are unique, why would bitset work?
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void mergeIntersection(vector<int> &a1, vector<int> &a2, vector<int> &intersect) {
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		
		int i, j;
		int n1, n2;
		
		i = 0;
		j = 0;
		n1 = (int)a1.size();
		n2 = (int)a2.size();
		intersect.clear();
		while (i < n1 && j < n2) {
			if (a1[i] < a2[j]) {
				++i;
			} else if (a1[i] > a2[j]) {
				++j;
			} else {
				intersect.push_back(a1[i]);
				++i;
				++j;
			}
		}
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