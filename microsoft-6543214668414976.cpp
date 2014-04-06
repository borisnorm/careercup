// http://www.careercup.com/question?id=6543214668414976
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int n;
	int i;
	
	while (cin >> n && n > 0) {
		for (i = 1; i <= n; ++i) {
			if (i % 3) {
				if (i % 5) {
					cout << i;
				} else {
					cout << "Bar";
				}
			} else {
				if (i % 5) {
					cout << "Foo";
				} else {
					cout << "FooBar";
				}
			}
			cout << endl;
		}
	}
	
	return 0;
}