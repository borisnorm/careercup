// http://www.careercup.com/question?id=6283958983589888
#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

int findKthSmallest(vector<int> &a, vector<int> &b, int na, int nb, int ia, int d, int k)
{
	int ib = k - 1 - ia;
	
	int pre_a = ia == 0 ? INT_MIN : a[ia - 1];
	int pre_b = ib == 0 ? INT_MIN : b[ib - 1];
	int cur_a = ia == na ? INT_MAX : a[ia];
	int cur_b = ib == nb ? INT_MAX : b[ib];
	
	if (cur_a >= pre_b && cur_a <= cur_b) {
		return cur_a;
	}
	if (cur_b >= pre_a && cur_b <= cur_a) {
		return cur_b;
	}
	
	if (cur_a > cur_b) {
		ia = (k - 1) - (ia - d) > nb ? (k - 1) - nb : ia - d;
	} else {
		ia = ia + d > na ? na : ia + d;
	}
	
	return findKthSmallest(a, b, na, nb, ia, (d + 1) / 2, k);
}

int main()
{
	vector<int> a, b;
	int na, nb;
	int i;
	int ia;
	
	while (scanf("%d%d", &na, &nb) == 2 && (na > 0 && nb > 0)) {
		a.resize(na);
		b.resize(nb);
		for (i = 0; i < na; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < nb; ++i) {
			scanf("%d", &b[i]);
		}
		while (scanf("%d", &i) == 1) {
			ia = min(na, i - 1);
			printf("%d\n", findKthSmallest(a, b, na, nb, ia, (ia + 1) / 2, i));
		}
		a.clear();
		b.clear();
	}
	
	return 0;
}