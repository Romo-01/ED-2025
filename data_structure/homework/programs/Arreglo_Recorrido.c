#include <stdio.h>
#include <stdlib.h>

int main(){
   int n,m;
   do {
       printf("Ingrese el valor de las columnas (maximo 10): ");
       scanf("%d", &n);
       if (n > 10) {
           printf("El valor debe ser menor o igual a 10, ingresalo de nuevo: \n");
       }
   } while (n > 10);

    do {
       printf("Ingrese el valor de las filas (maximo 10): ");
       scanf("%d", &m);
       if (m > 10) {
           printf("El valor debe ser menor o igual a 10, ingresalo de nuevo: \n");
       }
   } while (m > 10);

    int matriz[m][n];
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("Ingrese el valor para matriz[%d][%d]: ", i, j);
           scanf("%d", &matriz[i][j]);
        }
    }
    //Impresion de la matriz
    printf("\nMatriz:\n");
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}  

    //lectura en fila
    printf("\nMatriz leida en fila :\n ");
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }   

    //lectura en columna
    printf("\nMatriz leida en columna:\n ");
     for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    //lectura en diagonal
      if (m != n) {
        printf("\nLa matriz no es cuadrada, no se puede leer en diagonal\n");
    }
    else{
        printf("\nMatriz leida en diagonal :\n ");
        for (int i = 0; i < n; i++) {
            printf("%d ", matriz[i][i]);
        }
    }
    return 0;

}