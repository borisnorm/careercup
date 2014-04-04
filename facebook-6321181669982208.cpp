// http://www.careercup.com/question?id=6321181669982208
#include <iostream>
#include <vector>
using namespace std;

void DFS(int cur, int remain, vector<vector<int> > &result, vector<int> &sum)
{
	if (remain == 0) {
		result.push_back(sum);
		return;
	}
	if (remain < cur) {
		return;
	}
	
	int i;
	for (i = cur; i <= remain; ++i) {
		if (remain - i != 0 && remain - i < i) {
			continue;
		}
		sum.push_back(i);
		DFS(i, remain - i, result, sum);
		sum.pop_back();
	}
}

int main()
{
	int n;
	vector<int> sum;
	vector<vector<int> > result;
	int i, j;
	
	while (cin >> n && n > 0) {
		DFS(1, n, result, sum);
		
		cout << "{" << endl;
		for (i = 0; i < (int)result.size(); ++i) {
			cout << "    {";
			for (j = 0; j < (int)result[i].size(); ++j) {
				j ? cout << ", ", 1: 1;
				cout << result[i][j];
			}
			cout << "}" << endl;
		}
		cout << "}" << endl;
		
		sum.clear();
		for (i = 0; i < (int)result.size(); ++i) {
			result[i].clear();
		}
		result.clear();
	}
	
	return 0;
}