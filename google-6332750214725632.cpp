// http://www.careercup.com/question?id=6332750214725632
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class BinaryIndexedTree {
public:
	BinaryIndexedTree(int _n = 1): n(_n) {
		v.resize(n + 1);
	};
	
	// add val to all elements from v[1] to v[x]
	void addAll(int x, int val) {
		while (x >= 1) {
			v[x] += val;
			x -= lowBit(x);
		}
	};
	
	// add val to all elements from v[x] to v[y]
	void addInterval(int x, int y, int val) {
		if (x > y) {
			addInterval(y, x, val);
			return;
		}
		addAll(x - 1, -val);
		addAll(y, val);
	};
	
	// return v[x]
	int sum(int x) {
		int res = 0;
		while (x <= n) {
			res += v[x];
			x += lowBit(x);
		}
		
		return res;
	};
	
	~BinaryIndexedTree() {
		v.clear();
	};
private:
	int n;
	vector<int> v;
	
	int lowBit(int x) {
		return x & -x;
	};
};

struct Interval {
	int start;
	int end;
	Interval(int _start = 0, int _end = 0): start(_start), end(_end) {};
	
	bool operator < (const Interval &other) {
		if (start != other.start) {
			return start < other.start;
		} else {
			return end < other.end;
		}
	};

	friend ostream& operator << (ostream &cout, const Interval &i) {
		cout << '(' << i.start << ',' << i.end << ')';
		return cout;
	};
};

Interval solve(vector<Interval> &v)
{
	int n = (int)v.size();
	
	if (n == 0) {
		return Interval(0, 0);
	} else if (n == 1) {
		return v[0];
	}
	
	sort(v.begin(), v.end());
	BinaryIndexedTree bit(n);
	
	int i, j;
	int ll, rr, mm;
	for (i = 0; i < n - 1; ++i) {
		if (v[i + 1].start >= v[i].end) {
			// no overlapping
			continue;
		}
		
		if (v[n - 1].start < v[i].end) {
			// all overlapped
			j = n - 1;
		} else {
			ll = i + 1;
			rr = n - 1;
			while (rr - ll > 1) {
				mm = (ll + rr) / 2;
				if (v[mm].start < v[i].end) {
					ll = mm;
				} else {
					rr = mm;
				}
			}
			j = ll;
		}
		// from [i + 1, j], they all overlap with v[i].
		bit.addInterval(i + 2, j + 1, 1);
		bit.addInterval(i + 1, i + 1, j - i);
	}
	
	int ri;
	int res, mres;
	
	ri = 0;
	mres = bit.sum(1);
	for (i = 1; i < n; ++i) {
		res = bit.sum(i + 1);
		ri = res > mres ? i : ri;
	}
	
	return v[ri];
}

int main()
{
	int i;
	int n;
	vector<Interval> v;
	Interval res;
	
	while (cin >> n && n > 0) {
		v.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> v[i].start >> v[i].end;
		}
		res = solve(v);
		cout << res << endl;
		v.clear();
	}
	
	return 0;
}

/*
// A simple test for the BIT above.
int main()
{
	string cmd;
	int n;
	BinaryIndexedTree *bit = nullptr;
	int x, y, val;
	int i;
	
	while (cin >> n && n > 0) {
		bit = new BinaryIndexedTree(n);
		while (true) {
			for (i = 1; i <= n; ++i) {
				cout << bit->sum(i) << ' ';
			}
			cout << endl;
			cin >> cmd;
			if (cmd == "e") {
				break;
			} else if (cmd == "a") {
				cin >> x >> val;
				bit->addAll(x, val);
			} else if (cmd == "ai") {
				cin >> x >> y >> val;
				bit->addInterval(x, y, val);
			}
		}
		delete bit;
		bit = nullptr;
	}
	
	return 0;
}
*/