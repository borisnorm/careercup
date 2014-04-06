// http://www.careercup.com/question?id=5673934611546112
#include <iostream>
using namespace std;

int fib1(int n)
{
	if (n < 1) {
		return 0;
	}
	
	if (n == 1 || n == 2) {
		return 1;
	}
	
	return fib1(n - 1) + fib1(n - 2);
}

int fib2(int n)
{
	if (n < 1) {
		return 0;
	}
	
	if (n == 1 || n == 2) {
		return 1;
	}

	int f1, f2, f3;
	
	f1 = f2 = 1;
	for (int i = 3; i <= n; ++i) {
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}

void matrixMultiply(int a[2][2], int b[2][2], int c[2][2])
{
	int i, j, k;
	
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 2; ++j) {
			c[i][j] = 0;
			for (k = 0; k < 2; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void matrixPower(int a[2][2], int b[2][2], int n)
{
	if (n < 1) {
		b[0][0] = b[1][1] = 1;
		b[0][1] = b[1][0] = 0;
		return;
	}
	
	if (n == 1) {
		b[0][0] = a[0][0];
		b[0][1] = a[0][1];
		b[1][0] = a[1][0];
		b[1][1] = a[1][1];
		return;
	}
	
	int p[2][2];
	matrixPower(a, p, n / 2);
	if (n % 2) {
		int c[2][2];
		matrixMultiply(p, p, c);
		matrixMultiply(a, c, b);
	} else {
		matrixMultiply(p, p, b);
	}
}

int fib3(int n)
{
	if (n < 1) {
		return 0;
	}
	
	if (n == 1 || n == 2) {
		return 1;
	}
	
	int a[2][2] = {
		{1, 1}, 
		{1, 0}
	};
	int b[2][2];
	matrixPower(a, b, n - 2);
	
	return b[0][0] + b[0][1];
}

int main()
{
	int n;
	
	while (cin >> n) {
		cout << fib3(n) << endl;
	}
	
	return 0;
}