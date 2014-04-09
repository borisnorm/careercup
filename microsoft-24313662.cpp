// http://www.careercup.com/question?id=24313662
#include <iostream>
#include <string>
using namespace std;

string baseConvert2To4(string num)
{
	string res;
	int n = (int)num.size();
	int i;
	
	res.resize((n + 1) >> 1);
	for (i = n - 2; i >= 0; i -= 2) {
		res[(i >> 1) + (n & 1)] = ((num[i] - '0') << 1) + (num[i + 1] - '0') + '0';
	}
	if (n & 1) {
		res[0] = num[0];
	}
	
	return res;
}

int main()
{
	string num;
	
	while (cin >> num) {
		cout << baseConvert2To4(num) << endl;
	}
	
	return 0;
}