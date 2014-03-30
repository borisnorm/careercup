// http://www.careercup.com/question?id=6271724635029504
#include <cstdio>
#include <vector>
using namespace std;

bool twoSortedArraySum(vector<int> &a, vector<int> &b, int target, int &ia, int &ib)
{
	int i, j;
	int na, nb;

	na = (int)a.size();
	nb = (int)b.size();

	i = 0;
	j = nb - 1;

	int sum;
	while (i <= na - 1 && j >= 0) {
		sum = a[i] + b[j];
		if (sum > target) {
			--j;
		} else if (sum < target) {
			++i;
		} else {
			ia = i;
			ib = j;
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> a, b;
	int na, nb;
	int i;
	int ia, ib;
	int target;
	
	while (scanf("%d%d", &na, &nb) == 2 && (na > 0 && nb > 0)) {
		a.resize(na);
		b.resize(nb);
		for (i = 0; i < na; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < nb; ++i) {
			scanf("%d", &b[i]);
		}
		while (scanf("%d", &target) == 1) {
			ia = ib = -1;
			if (twoSortedArraySum(a, b, target, ia, ib)) {
				printf("%d + %d = %d\n", a[ia], b[ib], target);
			} else {
				printf("Not found.\n");
			}
		}
	}
	
	return 0;
}