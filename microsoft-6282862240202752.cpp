// http://www.careercup.com/question?id=6282862240202752
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v, int ll, int rr)
{
	int n = (int)v.size();
	
	if (ll > rr) {
		swap(ll, rr);
	}
	if (ll < 0 || ll > n - 1 || rr < 0 || rr > n - 1) {
		return;
	}
	while (ll < rr) {
		swap(v[ll], v[rr]);
		++ll;
		--rr;
	}
}

void rightShift(vector<int> &v, int k)
{
	int n = (int)v.size();
	
	if (n == 0) {
		return;
	}
	k = k >= 0 ? k % n : (n - (n - k) % n) % n;
	if (k == 0) {
		return;
	}
	reverse(v, 0, n - k - 1);
	reverse(v, n - k, n - 1);
	reverse(v, 0, n - 1);
}

int main()
{
	vector<int> v;
	int n, k;
	int i;
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		cin >> k;
		rightShift(v, k);
		for (i = 0; i < n; ++i) {
			i ? (cout << ' '), 1 : 1;
			cout << v[i];
		}
		cout << endl;
		
		v.clear();
	}
	
	return 0;
}