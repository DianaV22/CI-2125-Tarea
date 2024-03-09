#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_polinomios, mayor_grado;
    
    // Pedir al usuario el número de polinomios y el mayor grado
    printf("Ingrese el numero de polinomios: ");
    scanf("%d", &num_polinomios);
    printf("Ingrese el mayor grado aceptado para los polinomios: ");
    scanf("%d", &mayor_grado);
    
    // Crear matriz de coeficientes
    int **coeficientes = (int **)malloc(num_polinomios * sizeof(int *));
    for (int i = 0; i < num_polinomios; i++) {
        coeficientes[i] = (int *)calloc((mayor_grado + 1), sizeof(int)); // +1 para incluir el término independiente
    }
    
    // Leer coeficientes de los polinomios
    for (int i = 0; i < num_polinomios; i++) {
        printf("\nIngrese los coeficientes para el polinomio %d (comenzando desde el termino de mayor grado):\n", i + 1);
        for (int j = mayor_grado; j >= 0; j--) {
            printf("Coeficiente para x^%d: ", j);
            scanf("%d", &coeficientes[i][j]);
        }
    }
    
    // Sumar los polinomios
    int *suma = (int *)calloc((mayor_grado + 1), sizeof(int));
    for (int i = 0; i < num_polinomios; i++) {
        for (int j = 0; j <= mayor_grado; j++) {
            suma[j] += coeficientes[i][j];
        }
    }
    
    // Imprimir el resultado
    printf("\nLa suma de los polinomios es:\n");
    for (int i = mayor_grado; i >= 0; i--) {
        printf("%dx^%d ", suma[i], i);
        if (i > 0)
            printf("+ ");
    }
    
    // Liberar memoria
    for (int i = 0; i < num_polinomios; i++) {
        free(coeficientes[i]);
    }
    free(coeficientes);
    free(suma);
    
    return 0;
}
