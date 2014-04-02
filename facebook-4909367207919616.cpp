// http://www.careercup.com/question?id=4909367207919616
#include <cstdio>
#include <vector>
using namespace std;

void displaceInPlace(vector<int> &v)
{
	int i;
	int n;
	
	// all elements in the array has value between 0 and n - 1.
	n = (int)v.size();
	for (i = 0; i < n; ++i) {
		v[i] = v[v[i]] % n * n + v[i];
	}
	for (i = 0; i < n; ++i) {
		v[i] = v[i] / n;
	}
}

int main()
{
	int i, n;
	vector<int> v;
	
	while (scanf("%d", &n) ==  1 && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		displaceInPlace(v);
		for (i = 0; i < n; ++i) {
			printf((i ? " %d" : "%d"), v[i]);
		}
		putchar('\n');
		v.clear();
	}
	
	return 0;
}