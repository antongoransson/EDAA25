#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int c,largest,i,x,k;
	c= largest= i= 0;
	int *word = malloc(1*sizeof(int));
	int *a = malloc(1*sizeof(int));
	while ((c = getchar()) != EOF){
			while (isalpha(c) > 0){
				a[i] = c;
				c = getchar();
				i++;
				a = realloc(a, (i+1)*sizeof(int));
			}
			if (i > largest){
				largest = i;
				word = realloc(word,(largest+1)* sizeof(int));
				for (x = 0; x < largest; x++)
					word[x]= a[x];
			}
			a= realloc(a, 1*sizeof(int));
			i= 0;
	}
	free(a);
	printf("%d characters in longest word: ",largest);
	for (k = 0; k < largest; k++)
		printf("%c", word[k]);
	free(word);
	printf("\n");
	return 0;
}
