// http://www.careercup.com/question?id=5733320654585856
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ss1, ss2;
bool comparator(const string &s1, const string &s2)
{
	ss1 = s1;
	ss2 = s2;
	
	sort(ss1.begin(), ss1.end());
	sort(ss2.begin(), ss2.end());
	
	return ss1 < ss2;
}

int main()
{
	int i;
	int n;
	vector<string> v;
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end(), comparator);
		cout << "{" << endl;
		for (i = 0; i < (int)v.size(); ++i) {
			cout << "    " << v[i] << endl;
		}
		cout << "}" << endl;
		v.clear();
	}
	
	return 0;
}