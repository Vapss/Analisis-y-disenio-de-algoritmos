#include <stdio.h>
 
// función para ordenar la subsección a[i .. j] Del arreglo a[]
void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return;     // la subsección está vacía o es un solo elemento
    }
    int mid = (i + j) / 2;

    // la submatriz izquierda es una[i .. mid]
    // subarreglo derecho es un[mid + 1 .. j]
    
    merge_sort(i, mid, a, aux);     // ordenar la submatriz izquierda de forma recursiva
    merge_sort(mid + 1, j, a, aux);     // ordenar la submatriz derecha de forma recursiva

    int apuntador_derecho = i;       // apuntador_derecho apunta al comienzo de la submatriz izquierda
    int apuntador_izquierdo = mid + 1;        // apuntador_izquierdo apunta al comienzo de la submatriz derecha
    int k;      // k is the loop counter

    //hacemos un bucle de i a j para llenar cada elemento de la matriz fusionada final
    for (k = i; k <= j; k++) {
        if (apuntador_derecho == mid + 1) {      // el puntero izquierdo ha alcanzado el límite
            aux[k] = a[apuntador_izquierdo];
            apuntador_izquierdo++;
        } else if (apuntador_izquierdo == j + 1) {        // el puntero derechoo ha alcanzado el límite
            aux[k] = a[apuntador_derecho];
            apuntador_derecho++;
        } else if (a[apuntador_derecho] < a[apuntador_izquierdo]) {        // puntero izquierda apunta a un elemento más pequeño
            aux[k] = a[apuntador_derecho];
            apuntador_derecho++;
        } else {        // puntero derecha apunta a un elemento más pequeño
            aux[k] = a[apuntador_izquierdo];
            apuntador_izquierdo++;
        }
    }

    for (k = i; k <= j; k++) {      // copiar los elementos de aux[] hacia a[]
        a[k] = aux[k];
    }
}


int main() {
  int a[100], aux[100], n, i, d, swap;
 
  printf("Ingresa elementos en el arreglo:\n");
  scanf("%d", &n);
 
  printf("Ingresa %d enteros\n", n);
 
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
 
  merge_sort(0, n - 1, a, aux);
 
  printf("Imprime el arreglo ordenado:\n");
 
  for (i = 0; i < n; i++)
     printf("%d\n", a[i]);
 
  return 0;
}