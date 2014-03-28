// http://www.careercup.com/question?id=6283958983589888
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int findKthSmallest(vector<int> &a, vector<int> &b, int k)
{
	int na, nb;
	
	na = (int)a.size();
	nb = (int)b.size();
	if (na == 0) {
		return b[k];
	} else if (nb == 0) {
		return a[k];
	} else if (a[0] > b[nb - 1]) {
		return (k < nb ? b[k] : a[k - nb]);
	} else if (b[0] > a[na - 1]) {
		return (k < na ? a[k] : b[k - na]);
	}
	
	int i, j;

	i = j = 0;
	int res = a[i] < b[j] ? a[i++] : b[j++];
	while (i + j <= k) {
		if (i == na) {
			res = b[j++];
		} else if (j == nb) {
			res = a[i++];
		} else {
			res = a[i] < b[j] ? a[i++] : b[j++];
		}
	}

	return res;
}

int main()
{
	vector<int> a, b;
	int na, nb;
	int i;
	
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
			printf("%d\n", findKthSmallest(a, b, i));
		}
		a.clear();
		b.clear();
	}
	
	return 0;
}