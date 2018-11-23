#include <stdio.h>
#include <string.h>
void main (void) {
	char character[]="catdog";
	int length=strlen(character);
	int i,j,k,m,n,p,count;
	for (i=0;i<length;i++){
		for (j=0;j<length;j++){
			for (k=0;k<length;k++){
				for (m=0;m<length;m++){
					for (n=0;n<length;n++){
						for (p=0;p<length;p++){
							if (i!=j && i!=k && i!=m && i!=n && i!=p &&
							j!=k && j!=m && j!=n && j!=p &&
							k!=m && k!=n && k!=p &&
							m!=n && m!=p &&
							n!=p ) {
								count++;
							}
						}
					}
				}
			}
		}
	}
	printf("%d", count);
}
	
				
		
	