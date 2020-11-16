#include <stdio.h>
#ifndef CONTADOR_H
#define CONTADOR_H

    struct nodo {           //Estructura con los elementos del arreglo.
        char palabra[30];  //Palabra que se leyó del archivo.
        int frecuencia;     //Cantidad de veces que apareció la palabra.
		
    };
    typedef struct nodo Nodo;   //typedef para facilitar la declaracion de estructuras.
    //En esta implementacion, el tama�o del arreglo de estructuras Nodo se guarda como una variable global en el archivo "contador.c".

    void limpiar_palabra(char*);                //Recibe una cadena, la convierte toda a minusculas y le quita puntos (.), comas (,) y letras 's'.
    int contar_palabra(const char*, Nodo*, int);   //Si la palabra esta en el conjunto, incrementa su frecuencia. Si no, la agrega. En cualquiera de los dos casos, regresa el conjunto actualizado.
    void ordenar_palabras(Nodo*);              //Recibe el arreglo de palabras y lo regresa ordenado de mayor a menor frecuencia.
    void guardar_palabras(const Nodo*, FILE *, int); //Guarda el arreglo de palabras en un archivo.

#endif
