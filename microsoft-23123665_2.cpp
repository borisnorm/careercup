// http://www.careercup.com/question?id=23123665
// may contain duplicates.
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	const int MAXN = 20000;
	const int n = 1000;
	FILE *fin, *fout;
	int count[n];
	int i, j;
	int offset;
	
	fin = fopen("in.txt", "r");
	fout = fopen("out.txt", "w");
	if (fin == nullptr || fout == nullptr) {
		printf("File doesn't exist.\n");
		exit(1);
	}
	
	offset = 0;
	while (offset < MAXN) {		
		memset(count, 0, n * sizeof(int));
		
		fseek(fin, 0, SEEK_SET);
		while (!feof(fin)) {
			fscanf(fin, "%d", &i);
			if (i >= offset && i < offset + n) {
				++count[i - offset];
			}
		}
		
		for (i = 0; i < n; ++i) {
			for (j = 0; j < count[i]; ++j) {
				fprintf(fout, "%d\n", i + offset);
			}
		}
		
		offset += n;
	}
	fclose(fin);
	fin = nullptr;
	fclose(fout);
	fout = nullptr;
	
	return 0;
}