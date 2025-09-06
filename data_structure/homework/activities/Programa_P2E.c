#include <stdio.h>
#include <stdlib.h>

int main(){
int pares[10];
int i,c;

for (i=0; i<10; i++){
pares[i]= 20-(i*2);
}

for (i=0; i<10; i++){
printf("pares[%d] = %d\n", i,  pares[i]);
}

printf("Introduce tu numero de cuenta: ");
scanf("\n%d", &c);
int ult_dig;

ult_dig = c%10; //el residuo de una division entre 10 siempre es el ultimo digito

pares[ult_dig]=-1;
printf("%d\n", ult_dig);

for (i=0; i<10; i++){
printf("pares[%d] = %d\n", i,  pares[i]);
}
return 0;

}
