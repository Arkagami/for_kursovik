#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main()
{
	char s[1000][1000];

	FILE *fin = fopen("in.mixno", "r");
	FILE *fout = fopen("out.mixno", "w");
	int ir = 0;

	while (!feof(fin)) {
		fgets(s[ir++], 999, fin);
	}
	fclose(fin);

	for (int i = 0;i < 24;i++) {
		for (int k = 0;k < ir;k++) {
			for (int l = 0;l < strlen(s[k]);l++) {
				if (s[k][l] == '#') {
					fprintf(fout, "%d", i + 1);
				} else
				if (s[k][l] == '@') {
					fprintf(fout, "%d", i);
				}
				else
					fputc(s[k][l], fout);
			}
		}
		fputc('\n', fout);
	}
	
	fclose(fout);
    return 0;
}

