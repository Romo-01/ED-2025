#include <stdio.h>
#include <stdlib.h>

int fact(int n){
	if (n==0){
		return 1;
	}
	else if (n<0){
		return 0;
	}
	else if (n==1){
		return 1;
	}
	else {
		int i;
		int r;
		r=1;
		for (i=1; i<=n; i++){
			r=r*i;
			
		}
		return r;
	}
}

int main(){
	int n, result;
	printf("introduce el factorial a calcular: ");
	scanf("%d", &n);
	result= fact(n);
	printf("%d", result);
	
}
