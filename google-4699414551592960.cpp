// http://www.careercup.com/question?id=4699414551592960
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Person {
	int height;
	int taller;
	string name;
	Person(int _height = 0, int _taller = 0, string _name = ""): 
		height(_height), taller(_taller), name(_name) {};
	bool operator < (const Person &other) {
		return this->height < other.height;
	};
	
	friend ostream& operator << (ostream &cout, const Person &p) {
		cout << '<'<< p.name << p.height << '>';
		return cout;
	};
};

template <class T>
class BinaryIndexedTree {
public:
	BinaryIndexedTree(int _n = 0): n(_n), v(_n + 1) {};
	
	int size() {
		return n;
	};
	
	void addAll(int x, const T &val) {
		while (x >= 1 && x <= n) {
			v[x] += val;
			x -= lowBit(x);
		}
	};
	
	void addInterval(int x, int y, const T &val) {
		addAll(x - 1, -val);
		addAll(y, val);
	};
	
	void clear() {
		v.resize(1);
		n = 0;
	};
	
	void resize(int new_n) {
		v.resize(new_n + 1);
		n = new_n;
	}
	
	T sum(int x) {
		T res = 0;
		while (x >= 1 && x <= n) {
			res += v[x];
			x += lowBit(x);
		}
		
		return res;
	};
	
	int lowerBound(const T &val) {
		int ll, mm, rr;
		
		if (n == 0) {
			return 0;
		}

		T res;
		if (val <= (res = sum(1))) {
			return 1;
		}
		if (val > (res = sum(n))) {
			return n + 1;
		}
		
		ll = 1;
		rr = n;
		while (rr - ll > 1) {
			mm = (ll + rr) / 2;
			res = sum(mm);
			if (val > res) {
				ll = mm;
			} else {
				rr = mm;
			}
		}
		
		return rr;
	}
private:
	vector<T> v;
	int n;
	
	int lowBit(int x) {
		return x & -x;
	};
};

int main()
{
	vector<Person> people;
	vector<int> queue;
	BinaryIndexedTree<int> bit;
	int i, j;
	int n;
	
	while (cin >> n && n > 0) {
		people.resize(n);
		for (i = 0; i < n; ++i) {
			cin >> people[i].height >> people[i].taller >> people[i].name;
		}
		sort(people.begin(), people.end());
		bit.resize(n);
		queue.resize(n);
		for (i = 1; i <= n; ++i) {
			bit.addInterval(i, n, 1);
		}
		for (i = 1; i <= n; ++i) {
			j = bit.lowerBound(people[i - 1].taller + 1);
			queue[j - 1] = i;
			bit.addInterval(j, n, -1);
		}
		for (i = 0; i < n; ++i) {
			cout << people[queue[i] - 1];
		}
		cout << endl;
		
		people.clear();
		queue.clear();
		bit.clear();
	}
	
	return 0;
}