// http://www.careercup.com/question?id=4713484755402752
#include <vector>
using namespace std;

class Solution {
public:
	void mergeSortedArray(vector<int> &a, vector<int> &b, vector<int> &c) {
		int na, nb;
		
		na = (int)a.size();
		nb = (int)b.size();
		if (na == 0) {
			c = b;
			return;
		} else if (nb == 0) {
			c = a;
			return;
		}
		
		int i, j;
		i = j = 0;
		while (i < na && j < nb) {
			if (a[i] < b[j])
				c.push_back(a[i++]);
			} else if (a[i] > b[j]) {
				c.push_back(b[j++]);
			} else {
				c.push_back((a[i++], b[j++]));
			}
		}
		while (i < na) {
			c.push_back(a[i++]);
		}
		while (j < nb) {
			c.push_back(b[j++]);
		}
	}
};