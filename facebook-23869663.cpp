// http://www.careercup.com/question?id=23869663
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countSString(const string &s, const int mod)
{
	vector<int> v;
	int i, n;
	
	n = (int)s.length();
	v.resize(n);
	v[0] = 1 % mod;
	for (i = 1; i < n; ++i) {
		v[i] = v[i - 1] * 25 % mod;
	}
	
	int count = 0;
	char prev = 'z' + 1;
	for (i = 0; i < n; ++i) {
		if (prev >= s[i]) {
			count = (count + (s[i] - 'a') * v[n - 1 - i]) % mod;
		} else {
			count = (count + (s[i] - 'a' - 1) * v[n - 1 - i]) % mod;
		}
		if (prev == s[i]) {
			break;
		} else {
			prev = s[i];
		}
	}

	v.clear();
	return i == n ? count + 1 : count;
}

int main()
{
	string s;
	const int mod = 1009;
	
	while (cin >> s) {
		cout << countSString(s, mod) << endl;
	}
	
	return 0;
}