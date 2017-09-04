#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int c,largest,k,x,i;
	c= largest= i= 0;
	int *word = malloc(1*sizeof(int));
	int *a = malloc(1*sizeof(int));
	while ((c = getchar()) != EOF) {
			while (isalpha(c)) {
				a[i++] = c;
				c = getchar();
				a = realloc(a, (i+1)*sizeof(int));
			}
			if (i > largest) {
				largest = i;
				word = realloc(word,(largest)* sizeof(int));
				for (x = 0; x < largest; ++x)
					word[x]= a[x];
			}
			i= 0;
	}
	free(a);
	printf("%d characters in longest word: ",largest);
	for (k = 0; k < largest; ++k)
		printf("%c", word[k]);
	free(word);
	printf("\n");
	return 0;
}
