// http://www.careercup.com/question?id=5435439490007040
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void mergeTwoArray (vector<int> &a, vector<int> &b) {
		// merge a[] into b[].
		int na = (int)a.size();
		int nb = (int)b.size();

		b.resize(na + nb);

		int i, j, k;
		
		i = na - 1;
		j = nb - 1;
		k = na + nb - 1;
		while (i >= 0 && j >= 0) {
			b[k--] = a[i] > b[j] ? a[i--] : b[j--];
		}
		while (i >= 0) {
			b[k--] = a[i--];
		}
	};
};

int main()
{
	vector<int> a, b;
	int na, nb;
	int i;
	Solution sol;
	
	while (cin >> na >> nb && (na > 0 && nb > 0)) {
		a.resize(na);
		b.resize(nb);
		for (i = 0; i < na; ++i) {
			cin >> a[i];
		}
		for (i = 0; i < nb; ++i) {
			cin >> b[i];
		}
		sol.mergeTwoArray(a, b);
		nb = (int)b.size();
		for (i = 0; i < nb; ++i) {
			i ? (cout << ' ', 1) : 1;
			cout << b[i];
		}
		cout << endl;
		
		a.clear();
		b.clear();
	}
	
	return 0;
}