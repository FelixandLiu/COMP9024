#include <stdio.h>

int innerProduct(float a[], float b[]) {
  int i;
  int n=3;
  float g;
  for (i=0; i< n; i++) {
    g = g + a[i]*b[i];
	//printf("%.f %.f %.f\n",g,a[i],b[i]);
    }
	
	return g;
}
#define M 3
#define N 4
#define P 4
float matrixProduct(float a[M][N], float b[N][P]) {
	int i;
	int j;
	int k;
	float c[M][P];
    float inner_product;
  for (i=0; i<M; i++) {
	  for (j = 0; j <P; j++) {
		  for (k=0; k<N; k++) {
			  inner_product= inner_product+a[i][k]*b[k][j];
		  }
		  c[i][j]=inner_product;
	  }
  }
  return c[0][0];
}
int main(void) {
	float a[3][4]={{1,2,3,4},{1,2,3,4},{1,2,3,4}};
	float b[4][4]={{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
	float c[3]={1,2,3};
	float total=innerProduct(c,c);
	float h= matrixProduct(a,b);
	printf("%.2f + %.1f", h, total);
	return 0;
}