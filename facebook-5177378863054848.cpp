// http://www.careercup.com/question?id=5177378863054848
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countPalindrome(const string &s)
{
	vector<int> pal[2];
	
	int n = (int)s.length();
	if (n <= 1) {
		return n;
	}
	
	int count;
	int i, j;
	int flag;
	int nflag;
	
	count = 0;

	flag = 0;
	pal[flag].push_back(0);
	count += pal[flag].size();
	
	flag = !flag;
	nflag = !flag;
	for (i = 1; i < n; ++i) {
		for (j = 0; j < (int)pal[nflag].size(); ++j) {
			if (pal[nflag][j] == 0) {
				continue;
			}
			if (s[pal[nflag][j] - 1] == s[i]) {
				pal[flag].push_back(pal[nflag][j] - 1);
			}
		}
		if (s[i - 1] == s[i]) {
			pal[flag].push_back(i - 1);
		}
		pal[flag].push_back(i);
		count += pal[flag].size();
		flag = !flag;
		nflag = !flag;
		pal[flag].clear();
	}
	
	return count;
}

int main()
{
	string s;

	while(cin >> s) {
		cout << countPalindrome(s) << endl;
	}

	return 0;
}