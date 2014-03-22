// http://www.careercup.com/question?id=4857362737266688
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	Solution() {
		generateNumbers();
	};
	
	string nextInteger(string input) {
		int n1, n2;
		vector<int>::iterator it;
		stringstream ss;
		
		ss << input;
		ss >> n1;
		it = upper_bound(arr.begin(), arr.end(), n1);
		if (it == arr.end()) {
			n2 = n1;
		} else {
			n2 = *it;
		}
		
		string output = to_string(n2);
		
		return output;
	};
private:
	vector<int> arr;
	
	void generateNumbers() {
		queue<int> q;
		int n, n1;
		int i, d;
		
		arr.push_back(0);
		q.push(0);
		while (!q.empty()) {
			n = q.front();
			q.pop();
			d = n % 10;
			for (i = d + 1; i <= 9; ++i) {
				n1 = n * 10 + i;
				arr.push_back(n1);
				q.push(n1);
			}
		}
	};
};