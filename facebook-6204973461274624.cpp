// http://www.careercup.com/question?id=6204973461274624
#include <vector>
using namespace std;

class Solution {
public:
	void findKSubsets(int n, int k, vector<vector<int> > &result) {
		if (n <= 0) {
			return;
		}
		if (k < 1 || k > n) {
			return;
		}
		
		vector<int> subset;
		
		DFS(0, 0, subset, result, n, k);
	}
private:
	void DFS(int in, int ik, vector<int> &subset, 
			 vector<vector<int> > &result, 
			 const int &n, const int &k) {
		if (ik == k) {
			result.push_back(subset);
			return;
		}
		
		int i;
		for (i = in + 1; i <= n - (k - ik) + 1; ++i) {
			subset.push_back(i);
			DFS(i, ik + 1, subset, result, n, k);
			subset.pop_back();
		}
	};
};

int main()
{
	vector<vector<int> > result;
	int n, k;
	int i, j;
	Solution sol;
	
	while (scanf("%d%d", &n, &k) == 2 && (n > 0 && k > 0)) {
		sol.findKSubsets(n, k, result);
		printf("{\n");
		for (i = 0; i < (int)result.size(); ++i) {
			printf("    {");
			for (j = 0; j < (int)result[i].size(); ++j) {
				printf((j ? ", %d" : "%d"), result[i][j]);
			}
			printf("}\n");
		}
		printf("}\n");
		
		for (i = 0; i < (int)result.size(); ++i) {
			result[i].clear();
		}
		result.clear();
	}
	
	return 0;
}