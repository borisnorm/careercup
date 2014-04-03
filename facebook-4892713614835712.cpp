// http://www.careercup.com/question?id=4892713614835712
#include <iostream>
#include <string>
using namespace std;

string binaryAdd(string &a, string &b)
{
	if (a.length() > b.length()) {
		return binaryAdd(b, a);
	}
	
	string c;
	int carry;
	int na, nb;
	int bita, bitb;
	int i;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	na = (int)a.length();
	nb = (int)b.length();
	carry = 0;
	for (i = 0; i < nb; ++i) {
		bita = i < na ? a[i] - '0' : 0;
		bitb = b[i] - '0';
		c.push_back((bita ^ bitb ^ carry) + '0');
		carry = (bita + bitb + carry) > 1;
	}
	if (carry) {
		c.push_back('1');
	}
	reverse(c.begin(), c.end());

	return c;
}

int main()
{
	string a, b, c;
	
	while (cin >> a >> b) {
		c = binaryAdd(a, b);
		cout << c << endl;
	}
	
	return 0;
}