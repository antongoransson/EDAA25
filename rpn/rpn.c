#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	int stack[10], top=-1, spec_sign = 0, c, line= 0;
	while ((c = getchar())!= EOF) {
		while (c != '\n') {
			if (isdigit(c)) {
				top++;
				if (top >= 10) {
					spec_sign=2;
					goto end;
				} else {
				stack[top]= c -'0';
				while (isdigit(c = getchar())) {
					stack[top] = stack[top] * 10 + c-'0';
					}
				}
			} if (c == '+' || c == '-'|| c== '*' || c == '/' ) {
				spec_sign = 1;
				if (top < 1){
					spec_sign = 2;
					goto end;
				} else {
					top--;
					switch (c) {
						case '+': stack[top]+= stack[top+1]; break;
						case '-': stack[top]-= stack[top+1]; break;
						case '*': stack[top]*= stack[top+1]; break;
						case '/':
						 if (stack[top+1] == 0) {
							 spec_sign=2;
							 goto end;
						 } else {
							 stack[top]/= stack[top+1]; break;
						 }
					}
				}
			} else if (c != ' '){
				if (c!='\n')
					spec_sign = 2;
				goto end;
			}
			c = getchar();
		}
end:
		line++;
		if (spec_sign == 0)
			printf("%s %d%s\n","line",line,": error at \\n");
		else if (spec_sign == 2){
			printf("%s %d%s%c\n","line",line,": error at ",c);
			while ((c = getchar()) != '\n');
		}
		else
			printf("%s%d%s %d\n","line ",line,":", stack[0]);
		top=-1;
		spec_sign= 0;
	}
	return 0;
}
