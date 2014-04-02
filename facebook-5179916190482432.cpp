// http://www.careercup.com/question?id=5179916190482432
#include <cstdio>
#include <vector>
using namespace std;

void multiplyArray(vector<int> &v)
{
	vector<int> vp;
	int p;
	int i;
	int n = (int)v.size();
	
	vp.resize(n);
	p = 1;
	for (i = 0; i <= n - 1; ++i) {
		vp[i] = p;
		p *= v[i];
	}
	
	p = 1;
	for (i = n - 1; i >= 0; --i) {
		vp[i] = p * vp[i];
		p *= v[i];
	}

	for (i = 0; i < n; ++i) {
		v[i] = vp[i];
	}
	
	vp.clear();
}

int main()
{
	int i, n;
	vector<int> v;
	
	while (scanf("%d", &n) == 1 && n >= 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		multiplyArray(v);
		for (i = 0; i < n; ++i) {
			printf((i ? " %d" : "%d"), v[i]);
		}
		putchar('\n');
	}
	
	return 0;
}