// http://www.careercup.com/question?id=6139456847347712
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string intToString(int n)
{
	string s = "";
	
	if (n <= 26) {
		while (n > 0) {
			s.push_back(n % 10 + '0');
			n /= 10;
		}
		reverse(s.begin(), s.end());
		return s;
	}

	int exp;
	int len;

	exp = 26;
	len = 1;
	while (n > exp) {
		n -= exp;
		++len;
		exp *= 26;
	}

	--n;
	for (int i = 0; i < len; ++i) {
		s.push_back(n % 26 + 'A');
		n /= 26;
	}
	reverse(s.begin(), s.end());

	return s;
}

int stringToInt(const string &s)
{
	int n = 0;
	int len = (int)s.length();

	if (s[0] >= '0' && s[0] <= '9') {
		sscanf(s.c_str(), "%d", &n);
		return n;
	}

	int exp = 26;

	for (int i = 1; i < len; ++i) {
		n += exp;
		exp *= 26;
	}
	exp = 0;
	for (int i = 0; i < len; ++i) {
		exp = exp * 26 + (s[i] - 'A');
	}
	n += exp;
	++n;

	return n;
}

int  main()
{
	int n;
	string s;
	
	while (scanf("%d", &n) == 1 && n > 0) {
		s = intToString(n);
		n = stringToInt(s);
		cout << n << ' ' << s << endl;
	}
	
	return 0;
}