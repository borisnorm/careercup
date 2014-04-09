// http://www.careercup.com/question?id=23123665
// all numbers are unique.
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	const int MAXN = 20000;
	FILE *fin, *fout;
	unsigned bit[MAXN >> 5];
	int i;
	
	memset(bit, 0, MAXN / 8);
	
	fin = fopen("in.txt", "r");
	while (!feof(fin)) {
		fscanf(fin, "%u", &i);
		bit[i >> 5] |= (1 << (i & 31));
	}
	fclose(fin);
	fin = nullptr;
	
	fout = fopen("out.txt", "w");
	for (i = 0; i < MAXN; ++i) {
		if (bit[i >> 5] & (1 << (i & 31))) {
			fprintf(fout, "%u\n", i);
		}
	}
	fclose(fout);
	fout = nullptr;
	
	return 0;
}