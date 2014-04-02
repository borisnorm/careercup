// http://www.careercup.com/question?id=5671785349513216
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool anaStrStr (string needle, string haystack) {
		int len1, len2;
		
		len1 = (int)needle.length();
		len2 = (int)haystack.length();
		
		if (len1 == 0) {
			return true;
		} else if (len2 < len1) {
			return false;
		}
		
		memset(cn, 0, 256 * sizeof(int));
		memset(ch, 0, 256 * sizeof(int));
		int i, j;

		cc = 0;
		for (i = 0; i < len1; ++i) {
			++cn[needle[i]];
			++cc;
		}
		
		i = 0;
		j = i;
		while (true) {
			if (cc == 0) {
				return true;
			}

			if (i > len2 - len1) {
				return false;
			}
			

			if (ch[haystack[j]] < cn[haystack[j]]) {
				++ch[haystack[j]];
				--cc;
				++j;
			} else {
				while (i <= j && ch[haystack[j]] == cn[haystack[j]]) {
					if (ch[haystack[i]] > 0) {
						--ch[haystack[i]];
						++cc;
					}
					++i;
				}
				j = i > j ? i : j;
			}
		}
	};
private:
	int cn[256], ch[256];
	int cc;
};

int main()
{
	string needle, haystack;
	Solution sol;
	
	while (cin >> needle >> haystack) {
		cout << (sol.anaStrStr(needle, haystack) ? "true" : "false") << endl;
	}
	
	return 0;
}