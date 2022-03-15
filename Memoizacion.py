# Usando memoización (De arriba hacia abajo)

#Podemos almacenar los números de fibboonacci calculados hasta ahora y
# almacenar todos los valores en una matriz.


# Iniciar el array de dp
dp = [-1 for i in range(10)]
 
def fibbo(n):
    if (n <= 1):
        return n;
    global dp;
     
    # Variables temporales a guardar
    # Valores de fibbo(n-1) y de fibbo(n-2)
    primero = 0;
    segundo = 0;
 
    if (dp[n - 1] != -1):
        primero = dp[n - 1];
    else:
        primero = fibbo(n - 1);
    if (dp[n - 2] != -1):
        segundo = dp[n - 2];
    else:
        segundo = fibbo(n - 2);
    dp[n] = primero + segundo;
 
    # Memoización
    return dp[n] ;
 
# Main
if __name__ == '__main__':
    n = 7;
    print(fibbo(n));