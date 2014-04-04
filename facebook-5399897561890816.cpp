// http://www.careercup.com/question?id=5399897561890816
#include <cstdio>
using namespace std;

int main()
{
	int nzero;
	int sum;
	int n;
	
	while (scanf("%d", &n) == 1 && n > 0) {
		sum = 0;
		nzero = 0;
		while (n > 0) {
			if (n & 1) {
				sum += nzero;
			} else {
				++nzero;
			}
			n >>= 1;
		}
		printf((sum & 1) ? "First player wins.\n" : "Second player wins.\n");
	}
	
	return 0;
}