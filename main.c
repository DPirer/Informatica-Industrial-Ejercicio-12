#include <stdio.h>

// Pedro Antonio Estévez Pérez

// Ejercicio 12

/* Dada una variable valor de tipo unsigned char, escribir la expresión C que
 * ponga a 1 los 2 bits de mayor peso y a 0 los 2 bits de menor peso.*/

/* En un principio hice el programa para que cogiera los bits más significativos del
 * byte, pero luego pensé que si eran 0, no serían nada significativos, así que lo
 * cambié para que hiciera una operación u otra dependiendo del número de 0 que
 * hubiera antes del primer 1. Luego me dijiste que se refiere al byte en sí,
 * así pues:*/

int main(void)
{
    unsigned char var;
    printf("Introduce un caracter: ");
    scanf("%c", &var);
    int i; // 2^(8-1) = 128

    /* Lo siguiente que vamos a hacer es imprimir por pantalla el número en binario.
     * Aunque no sea necesario, lo hago porque así se ve directamente si el programa
     * funciona como debe. Para imprimirlo, lo que hago es hacer un and entre la variable
     * y un número cuyo 1 en binario va a ir avanzando. Si el resultado es un número
     * distinto de 0, entonces imprimirá un uno, y si es 0, imprimirá un 0.*/

    printf("En binario es: ");
    for(i = 128; i > 0; i >>= 1) // El 1 se irá desplazando a la derecha. >0 porque no tiene sentido hacer un and con 0
    {
        if(i & var) // No compara que sea uno, compara que sea cierto, que en C, lo será si es distinto de 0.
            printf("1");
        else
            printf("0");
    }
    printf("b\n");

    /* Ya tenemos impreso el binario del caracter. Ahora vamos a hacer las operaciones
     * que son poner los dos MSB a 1 y los dos LSB a 0. Se usarán operaciones con bits.*/

    var = var | 0xC0; // MSBs a 1
    var = var & 0xFC; // LSBs a 0

    /* Como podemos observar, lo que es el programa en sí, son dos líneas. Se ha hecho más
     * largo porque me gusta imprimirlo en binario para evitar que el usuario deba
     * realizar ninguna cuenta. Así, la comprobación del resultado es inmediata en cuanto
     * imprimimaos el binario que queda.*/

    printf("Despues de las operaciones: ");
    for(i = 128; i > 0; i >>= 1) // La i se desplaza un bit a la derecha cada ciclo
    {
        if(i & var) // Si contador AND var == 1
            printf("1");
        else
            printf("0");
    }

    printf("b\n");
    printf("El nuevo caracter es: %c\n\n", var);
}
