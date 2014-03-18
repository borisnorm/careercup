// http://www.careercup.com/question?id=4557716425015296
#include <queue>
#include <vector>
using namespace std;

template <class T>
struct greater {
	bool operator () (const T &x, const T &y) {
		return x > y;
	};
};

class Solution {
public:
	int minimalLengthSum(vector<int> &sticks) {
		int i, n;
		int sum;
		int num1, num2;
		
		sum = 0;
		n = (int)sticks.size();
		for (i = 0; i < n; ++i) {
			pq.push(sticks[i]);
		}
		
		for (i = 0; i < n - 1; ++i) {
			num1 = pq.top();
			pq.pop();
			num2 = pq.top();
			pq.pop();
			sum += num1 + num2;
			pq.push(num1 + num2);
		}
		
		while (!pq.empty()) {
			pq.pop();
		}
		
		return sum;
	};
private:
	// min heap
	priority_queue<int, vector<int>, greater<int> > pq;
};