// http://www.careercup.com/question?id=5752271719628800
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int maxSubarrayProduct(vector<int> &v, int k)
{
	int n = (int)v.size();
	
	if (n == 0) {
		return -1;
	}
	if (k >= n) {
		return 0;
	}
	
	int i, ll;
	long long int product;
	long long int max_product = INT_MIN;
	
	int j;
	i = 0;
	while (i + k <= n) {
		product = 1;
		for (j = i; j < i + k; ++j) {
			if (v[j] == 0) {
				product = 0;
				break;
			} else {
				product *= v[j];
			}
		}
		if (product > max_product) {
			max_product = product;
			ll = i;
		}
		if (j < i + k) {
			i = j + 1;
		} else {
			++i;
			while (i + k <= n && v[i + k - 1] != 0) {
				product = product / v[i - 1] * v[i + k - 1];
				if (product > max_product) {
					max_product = product;
					ll = i;
				}
				++i;
			}
			if (i + k <= n) {
				if (max_product < 0) {
					max_product = 0;
					ll = i;
				}
				i = i + k;
			}
		}
	}
	
	return ll;
}

int main()
{
	int i;
	int n;
	int k;
	int ll;
	vector<int> v;
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		cin >> k;
		k = k < n ? k : n;
		ll = maxSubarrayProduct(v, k);
		cout << '{';
		for (i = 0; i < k; ++i) {
			i ? (cout << ' '), 1 : 1;
			cout << v[i + ll];
		}
		cout << '}' << endl;
		v.clear();
	}
	
	return 0;
}