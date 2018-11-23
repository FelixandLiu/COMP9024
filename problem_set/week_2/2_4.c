#include <stdio.h>

void even_odd(int n) {
	while (n!=1) {
		if (n%2==0) {
			n=n/2;
		}
		else if (n%2!=0) {
			n=3*n+1;
		}
	}
	printf("%d",n);
}
void main(void) {
	int n=456;
	even_odd(n);
}