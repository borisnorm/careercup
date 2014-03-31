// http://www.careercup.com/question?id=5727310284062720
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char> > &board) {
		// Should n or m be smaller than 3, there'll be no captured region.
		n = (int)board.size();
		if (n < 3) {
			return;
		}
		
		m = (int)board[0].size();
		if (m < 3) {
			return;
		}
		
		int i, j;
		
		// if an 'O' is on the border, all of its connected 'O's are not captured.
		// so we scan the border and mark those 'O's as free.
		
		// the top row
		for (j = 0; j < m; ++j) {
			if (board[0][j] == 'O') {
				check_region(board, 0, j);
			}
		}
		
		// the bottom row
		for (j = 0; j < m; ++j) {
			if (board[n - 1][j] == 'O') {
				check_region(board, n - 1, j);
			}
		}
		
		// the left column
		for (i = 1; i < n - 1; ++i) {
			if (board[i][0] == 'O') {
				check_region(board, i, 0);
			}
		}
		
		// the right column
		for (i = 1; i < n - 1; ++i) {
			if (board[i][m - 1] == 'O') {
				check_region(board, i, m - 1);
			}
		}
		
		// other unchecked 'O's are all captured
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				if (board[i][j] == '#') {
					// free 'O's
					board[i][j] = 'O';
				} else if (board[i][j] == 'O') {
					// captured 'O's
					board[i][j] = 'X';
				}
			}
		}
	}
private:
	int n, m;
	
	void check_region(vector<vector<char> > &board, int startx, int starty) {
		if (startx < 0 || startx > n - 1 || starty < 0 || starty > m - 1) {
			return;
		}
		if (board[startx][starty] == 'O') {
			board[startx][starty] = '#';
			check_region(board, startx - 1, starty);
			check_region(board, startx + 1, starty);
			check_region(board, startx, starty - 1);
			check_region(board, startx, starty + 1);
		}
	}
};

int main()
{
	int n, m;
	int i, j;
	string str;
	vector<vector<char> > board;
	Solution sol;
	
	while (cin >> n >> m && (n > 0 && m > 0)) {
		board.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> str;
			board[i].resize(m);
			for (j = 0; j < m; ++j) {
				board[i][j] = str[j];
			}
		}
		sol.solve(board);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				cout << board[i][j];
			}
			cout << endl;
		}
		
		for (i = 0; i < n; ++i) {
			board[i].clear();
		}
		board.clear();
	}
	
	return 0;
}