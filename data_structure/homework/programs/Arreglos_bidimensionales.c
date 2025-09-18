#include <stdio.h>
#include <stdlib.h>

//busque como inicializar la matriz como en el ejemplo que nos dio y encontre que no puedes crear una matriz directamente con tipos de datos mixtos usando la sintaxis int **matrix, ya que esa técnica asume que todos los elementos son del mismo tipo
typedef struct {
    char nombre[25];
    int edad;
    int calificacion;
} Alumno;

#define maximo_alumnos 100

int main(){
int n = 0; //contador de alumnos actualmente almacenados en el arreglo
char opcion;
int sumaEdad = 0;
int sumaCalif = 0;

Alumno *alumnos = (Alumno*)malloc(maximo_alumnos * sizeof(Alumno));

while (n < maximo_alumnos) {
        printf("Desea agregar un alumno? s/n: ");
        scanf(" %c", &opcion);
        if (opcion == 'n') break;

        printf("Nombre: ");
        scanf(" %[^\n]", alumnos[n].nombre);
        printf("Edad: ");
        scanf("%d", &alumnos[n].edad);
        printf("Calificacion: ");
        scanf("%d", &alumnos[n].calificacion);

        sumaEdad += alumnos[n].edad;
        sumaCalif += alumnos[n].calificacion;
        n++; // incrementa el contador de alumnos
    }

   if (n == 0) {
        printf("No se ingresaron alumnos.\n");
        free(alumnos);
        return 0;
    } 
    printf("| Nom | Edad | Cal |\n");
     for (int i = 0; i < n; i++) {
        printf("| %s | %d | %d |\n", alumnos[i].nombre, alumnos[i].edad, alumnos[i].calificacion);
    }

    printf("\nPromedio de edad: %.2f\n", (float)sumaEdad / n); //este (float) fuerza a que la división sea flotante y obtienes el resultado con decimales porque si declaro n con flotantes me da error
    printf("Promedio de calificacion: %.2f\n", (float)sumaCalif / n);

    printf("\nNombres en orden inverso:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%s\n", alumnos[i].nombre);
    }

    free(alumnos);
    return 0;
}