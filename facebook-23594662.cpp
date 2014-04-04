// http://www.careercup.com/question?id=23594662
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void myswap(int &x, int &y)
{
	if (x == y) {
		return;
	}

	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
}

int maxDiscontiguousSum(vector<int> &v)
{
	int i, n;
	int sum1, sum2, sum3;
	
	n = (int)v.size();
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return v[0];
	}
	
	sum1 = v[0];
	for (i = 1; i < n; ++i) {
		sum1 = v[i] > sum1 ? v[i] : sum1;
	}
	if (sum1 <= 0) {
		return sum1;
	}
	
	sum1 = v[0];
	sum2 = max(v[0], v[1]);
	sum3 = sum2;
	for (i = 2; i < n; ++i) {
		sum3 = max(sum2, (v[i] > 0 ? sum1 + v[i] : sum1));
		sum1 = sum2;
		sum2 = sum3;
	}
	
	return sum3;
}

int main()
{
	vector<int> v;
	int n;
	int i;
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		cout << maxDiscontiguousSum(v) << endl;
		v.clear();
	}
	
	return 0;
}