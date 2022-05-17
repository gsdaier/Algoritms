#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10000

void main ()
{
        setlocale(LC_ALL, "");

        int numeros [TAM];
        int *num;
        int i, aux, contador;

        num = (int*)malloc(TAM*sizeof(int));

        for(int i = 0; i < TAM; i++){
        numeros[i] = rand() % 200;
        }

        printf("\n");
        printf("\n Ordem atual dos itens no array\n");
        for (i = 0; i < TAM; i++) {
            printf("%4d", numeros[i]);
        }

        // Ord. Bubble
        for (contador = 1; contador < TAM; contador++) {
            for(i = 0; i < TAM - 1; i++) {
                if (numeros[i] > numeros[i + 1]) {
                    aux = numeros[i];
                    numeros[i] = numeros[i + 1];
                    numeros[i + 1] = aux;
                }
            }
        }

        printf("\nElementos do array em ordem crescente:\n");

        for(i = 0; i < TAM; i++) {
                printf("%4d", numeros[i]);

        }

        printf("\n");

        return 0;
}
