// http://www.careercup.com/question?id=5765850736885760
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void DFS(int idx, vector<pair<int, char> > &dict, vector<string> &result, const string &s)
{
	int i;
	
	if (idx == (int)dict.size()) {
		static char m[10];
		
		for (i = 0; i < (int)dict.size(); ++i) {
			m[dict[i].first] = dict[i].second;
		}
		
		static string res;
		
		res.clear();
		for (i = 0; i < (int)s.length(); ++i) {
			res.push_back(m[s[i] - '1']);
		}
		
		result.push_back(res);
		return;
	}
	
	switch(dict[idx].first) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		for (i = 0; i < 3; ++i) {
			dict[idx].second = (dict[idx].first * 3 + i) + 'A';
			DFS(idx + 1, dict, result, s);
		}
		break;
	case 8:
		for (i = 0; i < 2; ++i) {
			dict[idx].second = (dict[idx].first * 3 + i) + 'A';
			DFS(idx + 1, dict, result, s);
		}
		break;
	}
}

int main()
{
	int i;
	string s;
	vector<pair<int, char> > dict;
	vector<string> result;
	int a[10];
	
	while (cin >> s) {
		for (i = 0; i < 10; ++i) {
			a[i] = 0;
		}
		for (i = 0; i < (int)s.length(); ++i) {
			a[s[i] - '1'] = 1;
		}
		
		for (i = 0; i < 10; ++i) {
			if (a[i]) {
				dict.push_back(make_pair(i, '\0'));
			}
		}
		
		DFS(0, dict, result, s);
		cout << "{" << endl;
		for (i = 0; i < (int)result.size(); ++i) {
			cout << "    " << result[i] << endl;
		}
		cout << "}" << endl;
		
		dict.clear();
		result.clear();
	}
	
	return 0;
}