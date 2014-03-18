// http://www.careercup.com/question?id=5732809947742208
#include <cstring>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int longestWordInDictionary(unordered_set<string> &dictionary, string letters) {
		int i;
		int max_len;
		int word_len;
		
		memset(c1, 0, MAXLEN * sizeof(int));
		word_len = (int)letters.length();
		for (i = 0; i < word_len; ++i) {
			++c1[letters[i]];
		}
		
		max_len = 0;
		unordered_set<string>::iterator it;
		for (it = dictionary.begin(); it != dictionary.end(); ++it) {
			word_len = (int)(*it).length();
			if (word_len > (int)letters.length()) {
				continue;
			}
			
			memcpy(c2, c1, MAXLEN * sizeof(int));
			for (i = 0; i < word_len; ++i) {
				if (c2[(*it)[i]] == 0) {
					break;
				}
				--c2[(*it)[i]];
			}
			if (i == word_len) {
				max_len = word_len > max_len ? word_len : max_len;
			}
		}
		
		return max_len;
	};
private:
	const int MAXLEN
	int c1[MAXLEN];
	int c2[MAXLEN];
};