// http://www.careercup.com/question?id=5173689888800768
/*
	T(0) = 1;
	T(1) = 1;
	T(n) = T(n - 1) + T(n - 2);
	Thus T(n) is exactly nth Fibonacci number.
	T(n) = (((1 + sqrt(5)) / 2) ^ n - ((1 - sqrt(5)) / 2) ^ n) / sqrt(5);
*/
int fibonacci (int n)
{
	if (n < 2) {
		return n;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main()
{
	return 0;
}