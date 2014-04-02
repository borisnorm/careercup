// http://www.careercup.com/question?id=5890898499993600
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		n = (int)board.size();
		if (n == 0) {
			return false;
		}
		m = (int)board[0].size();
		word_len = (int)word.length();
		
		if (word_len == 0) {
			return true;
		}
		
		int i, j;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if(dfs(board, word, i, j, 0)) {
					return true;
				}
			}
		}
		return false;
    }
private:
	int n, m;
	int word_len;
	
	bool dfs(vector<vector<char> > &board, string &word, int x, int y, int idx) {
		static const int d[8][2] = {
			{-1, -1}, 
			{-1,  0}, 
			{-1, +1}, 
			{ 0, -1}, 
			{ 0, +1}, 
			{+1, -1}, 
			{+1,  0}, 
			{+1, +1}
		};
		
		if (x < 0 || x > n - 1 || y < 0 || y > m - 1) {
			return false;
		}
		
		if (board[x][y] < 'A' || board[x][y] != word[idx]) {
			// already searched here
			// letter mismatch here
			return false;
		}
		
		bool res;
		if (idx == word_len - 1) {
			// reach the end of word, success
			return true;
		}

		for (int i = 0; i < 8; ++i) {
			board[x][y] -= 'a';
			res = dfs(board, word, x + d[i][0], y + d[i][1], idx + 1);
			board[x][y] += 'a';
			if (res) {
				return true;
			}
		}
		// all letters will be within [a-z], thus I marked a position as 'searched' by setting them to an invalid value.
		// we have to restore the value when the DFS is done, so their values must still be distiguishable.
		// therefore, I used an offset value of 'a'.
		// this tricky way is to save the extra O(n * m) space needed as marker array.
		
		return false;
	}
};