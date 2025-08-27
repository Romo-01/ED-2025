#include <stdio.h>
#include <stdlib.h>
int fact(int n, int a){
if (n==0){
return 1;
}
else if (n<0){
return 0;
}
else if (n==1){
return a;
}
else{
return fact( n-1,n*a);
}
}


int main (){
int n, result;
printf("Introduce factorial a calcular: ");
scanf("%d", &n);
result = fact(n,1);
printf("%d", result);
}
