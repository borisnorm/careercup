// http://www.careercup.com/question?id=5177378863054848
// Modified Manacher Algorithm
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	long long int countPalindrome(const string &s) {
		int n = (int)s.length();
		
		if (n <= 1) {
			return n;
		}
		
		preProcess(s);
		n = (int)ss.length();
		int far;
		int far_i;
		
		int i;

		far = 0;
		c[0] = 0;
		for (i = 1; i < n; ++i) {
			c[i] = 1;
			if (far > i) {
				c[i] = c[2 * far_i - i];
				if (far - i < c[i]) {
					c[i] = far - i;
				}
			}
			
			while (ss[i - c[i]] == ss[i + c[i]]) {
				++c[i];
			}
			
			if (i + c[i] > far) {
				far = i + c[i];
				far_i = i;
			}
		}
		
		long long int count = 0;
		for (i = 0; i < n; ++i) {
			count += (c[i] + (i & 1)) / 2;
		}
		
		ss.clear();
		c.clear();
		
		return count;
	}
private:
	string ss;
	vector<int> c;
	
	void preProcess(const string &s) {
		int n;
		int i;
		
		n = (int)s.length();
		ss.clear();
		// don't insert '#' here, index may go out of bound.
		ss.push_back('$');
		for (i = 0; i < n; ++i) {
			ss.push_back(s[i]);
			ss.push_back('#');
		}
		c.resize(ss.length());
	};
};

int main()
{
	string s;
	Solution sol;
	const int big_n = 500000;

	s.resize(big_n);
	for(int i = 0; i < big_n; ++i) {
		s[i] = 'a';
	}
	
	clock_t start, end;
	start = clock();
	cout << sol.countPalindrome(s) << endl;
	end = clock();
	cout << "Runtime for test case of size " << big_n << ": " 
		 << (1.0 * (end - start) / CLOCKS_PER_SEC) 
		 << " seconds." << endl;

	while (cin >> s) {
		cout << sol.countPalindrome(s) << endl;
	}
	
	return 0;
}