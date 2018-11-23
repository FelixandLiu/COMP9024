#include <stdio.h>

int main (void) {
	int a,b,c,d,e;
	for (a=1; a<3; a++){
	  for (b=0; b<5; b++){
	    for (c=0; c<10; c++){
	      for (d=0; d<10; d++){
		for (e=1; e<10; e++){
		  if (4*(a*10000+b*1000+c*100+d*10+e)==e*10000+d*1000+c*100+b*10+a)
		    printf( "%d %d %d %d %d\n",a,b,c,d,e);
		  }  
		}  
	     }	    
	   }  
	}

	return 0;
}
