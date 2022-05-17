/* Merge Sort */
#include <stdio.h>
#include <stdlib.h>

// Merges dois subarrays de arr[].
// Primeiro subarray é arr[l..m]
// Segundo subarray é arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* Criando arrays temp */
	int L[n1], R[n2];

	/* Copy data temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge arrays temp em arr[l..r]*/
	i = 0; // Primeiro índice of primeiro subarray
	j = 0; // Primeiro índice of segundo subarray
	k = l; // Primeiro índice do merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Cópia dos itens restantes de L[], se tiver algum */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Cópia dos itens restantes de R[], se tiver algum */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l é para o index da esquerda e r é o index da direita do
sub-array de arr para ser rodado */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Igual a (l+r)/2
		int m = l + (r - l) / 2;

		// Rodando a primeira e segunda metades
		mergeSort(arr, l, m); // Esquerda-direita até achar um i maior que ele
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Função para printar o array na tela */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* main */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
