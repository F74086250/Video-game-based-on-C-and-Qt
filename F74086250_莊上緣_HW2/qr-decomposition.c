#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#define URE(n) for(int u=0;u<n;u++)
#define JRE(n) for(int j=0;j<n;j++)
#define KRE(n) for(int k=0;k<n;k++)
typedef long double ld;
ld a[10][10]={0},q[10][10]={0},r[10][10]={0};
int c,m,n;
FILE *in,*out;
ld L(int N){
	ld re=0;
	URE(m)re+=a[u][N]*a[u][N];
	return sqrt(re);
}
ld inner(int k,int j){
	ld re=0;
	URE(m)re+=a[u][j]*q[u][k];
	return re;
}
void F(){
	URE(n){
		r[u][u]=L(u);
		JRE(m)q[j][u]=a[j][u]/r[u][u];
		for(int j=u+1;j<n;j++){
			r[u][j]=inner(u,j);
			KRE(m)a[k][j]-=q[k][u]*r[u][j];
		}
	}
}
int main(){
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	fscanf(in,"%d",&c);
	fprintf(out,"%d\n",c);
	while(c--){
		fscanf(in,"%d %d",&m,&n);
		memset(a,0,sizeof(ld)*100);
		memset(q,0,sizeof(ld)*100);
		memset(r,0,sizeof(ld)*100);
		URE(m){
			JRE(n){
				fscanf(in,"%llf",&a[u][j]);
			}
		}
		F();
		fprintf(out,"%d %d\n",m,n);
		URE(m){
			JRE(n){
				if(fabsl(q[u][j])<DBL_EPSILON)fprintf(out,"0.00 ");
				else fprintf(out, "%.2llf ", q[u][j]);
			}
			fprintf(out, "\n");
		}
		fprintf(out,"%d %d\n",n,n);
		URE(n){
			JRE(n){
				if(fabsl(r[u][j])<DBL_EPSILON)fprintf(out,"0.00 ");
				else fprintf(out, "%.2llf ", r[u][j]);
			}
			fprintf(out, "\n");
		}
	}
	fclose(in);
	fclose(out);
    return 0;
}
