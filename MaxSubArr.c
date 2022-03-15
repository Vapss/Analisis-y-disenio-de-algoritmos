//MAXIMO SUBARREGLO DIVIDE Y VENCERAS 
//DADO UN ARREGLO, ENCONTRAR SU MAXIMA SUMATORIA DENTRO DE TODOS LOS SUBARREGLOS POSIBLES.

#include <stdio.h>
#include <limits.h>

// El maximo de dos numeros
int max(int x, int y) {
    return (x > y) ? x : y;
}
// divide y venceras para encontrar el maximo subarreglo sumado
int suma_maxima(int A[], int bajo, int alto)
{
    // SOLO CONTIENE UN ELEMENTO
    if (alto == bajo) {
        return A[bajo];
    }
 
    // ELEMENTO DE ENMEDIO
    int mid = (bajo + alto) / 2;

    // SUBARREGLO IZQUIERDO
    // CON EL ELEMENTO DE ENMEDIO
    int izq_maxima = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= bajo; i--)
    {
        sum += A[i];
        if (sum > izq_maxima) {
            izq_maxima = sum;
        }
    }
    // SUBARREGLO DERECHO SIN EL ELEMENTO DE ENMEDIO
    int der_maxima = INT_MIN;
    sum = 0;    // reset sum to 0
    for (int i = mid + 1; i <= alto; i++)
    {
        sum += A[i];
        if (sum > der_maxima) {
            der_maxima = sum;
        }
    }
 
    // suma maxima para el subarreglo izquierdo y derecho para tomar el maximo
    int maxima_izq_der = max(suma_maxima(A, bajo, mid),
                            suma_maxima(A, mid + 1, alto));
 
    // REGRESA EL MAS GRANDE DE LOS 3
    return max(maxima_izq_der, izq_maxima + der_maxima);
}
 

int main(void)
{
    int arr[] = { 88, -21, 99, 83, 65, 18, -30 }; //EJEMPLO DE ARREGLO
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("La suma maxima del subarreglo es:  %d",  //RESULTADO DE EJEMPLO
            suma_maxima(arr, 0, n - 1));
    
    return 0;
}