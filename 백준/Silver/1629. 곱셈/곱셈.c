#include <stdio.h>

int A,B,C;

long long int f(long long int y){
	if(y==1) return A%C;
	
	long long int k = f(y/2)%C;
	
	if(y%2==0) return k*k%C;
	else return k*k%C*A%C;
}

int main(){
	scanf("%d %d %d",&A,&B,&C);
	
	printf("%lld\n",f(B));
	
	return 0;
}