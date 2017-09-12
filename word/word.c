#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// SCORE 229
#define SIZE sizeof(int)

int main()
{
	int c, lst=0, i=0, ctr=0, index=0;
	char *word = malloc(1*SIZE);
	while ((c = getchar()) != EOF) {
		word[i++] = c;
		word = realloc(word,(i+1)*SIZE);
		if (isalpha(c))
			ctr++;
		 else {
			if (ctr > lst) {
				lst = ctr;
				index = i-1-lst;
			}
		ctr = 0;
		}
	}
	printf("%d characters in longest word: %.*s\n",lst, lst, word+index);
	free(word);
	return 0;
}
