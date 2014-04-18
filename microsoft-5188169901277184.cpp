// http://www.careercup.com/question?id=5188169901277184
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countWord(const string &word, string &pattern) {
		lw = (int)word.length();
		lp = (int)pattern.length();
		
		if (lw == 0 || lp == 0) {
			return 0;
		}
		
		if (lw < lp) {
			return 0;
		}
		
		int result = 0;
		if (isPalindrome(pattern)) {
			calculateNext(pattern);
			result += KMPMatch(word, pattern);
		} else {
			calculateNext(pattern);
			result += KMPMatch(word, pattern);
			reverse(pattern.begin(), pattern.end());
			calculateNext(pattern);
			result += KMPMatch(word, pattern);
			reverse(pattern.begin(), pattern.end());
			result *= 2;
		}
		next.clear();
		
		return result;
    }
private:
	int lw;
	int lp;
	vector<int> next;
	
	bool isPalindrome(const string &s) {
		int len = (int)s.length();
		int i;

		if (len <= 1) {
			return true;
		}

		for (i = 0; i < len - 1 - i; ++i) {
			if (s[i] != s[len - 1 - i]) {
				return false;
			}
		}

		return true;
	}

	void calculateNext(const string &pattern) {
		int i = 0;
		int j = -1;
		
		next.resize(lp + 1);
		next[0] = -1;
		while (i < lp) {
			if (j == -1 || pattern[i] == pattern[j]) {
				++i;
				++j;
				next[i] = j;
			} else {
				j = next[j];
			}
		}
	}
	
	int KMPMatch(const string &word, const string &pattern)
	{
		int index;
		int pos;
		int result;
		
		index = pos = 0;
		result = 0;
		while (index < lw) {
			if (pos == -1 || word[index] == pattern[pos]) {
				++index;
				++pos;
			} else {
				pos = next[pos];
			}
			
			if (pos == lp) {
				pos = 0;
				++result;
			}
		}
		
		return result;
	}
};

int main()
{
	string word, pattern;
	Solution sol;
	
	while (cin >> word >> pattern) {
		cout << sol.countWord(word, pattern) << endl;
	}
	
	return 0;
}