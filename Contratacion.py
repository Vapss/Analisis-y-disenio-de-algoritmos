import math
import random


def numero_aleatorio(a, b):
    bits = math.ceil(math.log2(b - a + 1))

    while True:
        numero = aleatorio_binay(bits)

        if a + numero <= b:
            return a + numero


def aleatorio_binay(bits):
    numero = 0

    for i in range(bits):
        numero = numero * 2 + random.randint(0, 1)

    return numero