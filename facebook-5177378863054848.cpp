// http://www.careercup.com/question?id=5177378863054848
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countPalindrome(const string &s)
{
	int n = (int)s.length();
	if (n <= 1) {
		return n;
	}
	
	int i, j;
	int res;
	int count;
	
	res = 0;
	for (i = 0; i < n; ++i) {
		j = 0;
		count = 0;
		while (i - j >= 0 && i + j <= n - 1 && s[i - j] == s[i + j]) {
			++count;
			++j;
		}
		res += count;
		
		j = 0;
		count = 0;
		while (i - j >= 0 && i + 1 + j <= n - 1 && s[i - j] == s[i + 1 + j]) {
			++count;
			++j;
		}
		res += count;
	}
	
	return res;
}

int main()
{
	string s;

	while(cin >> s) {
		cout << countPalindrome(s) << endl;
	}

	return 0;
}