// http://www.careercup.com/question?id=6407924087783424
#include <iostream>
#include <vector>
using namespace std;

inline int mod(int x, int y)
{
	return x % y >= 0 ? x % y : y - (y - x) % y;
}

int main()
{
	vector<int> v;
	int n;
	int i;
	int sum;
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		
		sum = 0;
		for (i = 0; i < n; ++i) {
			sum = mod(sum + v[i], n);
		}
		cout << (sum ? n - 1 : n) << endl;
		v.clear();
	}
	
	return 0;
}