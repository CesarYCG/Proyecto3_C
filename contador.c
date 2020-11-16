#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //Esto nos permitira hacer el lowercase de las palabras
#include "contador.h"

//Funcion pa quitarle puntos, comas (al final de las palabras) y convertir plurales a no plurales, gg.
void limpiar_palabra(char *palabra){
	int i = 0;
	//Vamos a evaluar caracter por caracter
	
	
	//Mientras la palabra no sea fin de cadena
	while(palabra[i] != '\0'){ //Donde '\0' es el fin de cadea
		//Convertimos todas las letras a minusculas
		palabra[i]=tolower(palabra[i]);
		
		//Vamos a verificar si no tiene algun signo '.' o ',', si lo tiene, lo quitamos
		
		if (palabra[i] == ',' || palabra[i] == '.'){ //Si posee alguno de los dos caracteres
			palabra[i] ='\0'; //Reemplazamos el caracter con un fin de cadena
		}
		i++; //Aumentamos el valor de i para evaluar el siguiente caracter
	}

	/*Aqui se termina de recorrer la palabra, todo es minuscula y se eliminaron los signos ',' y '.'
	Vamos a evaluar la pluralidad de las palabras, es decir, aquellas que terminan en 's'
	Para este caso en especifico, se esta evaluando un texto en ingles, por tanto quiero mantener 
	la palabra 'is' 
	*/
	
	if (palabra[i-1] == 's' ){
		if (palabra[i-2] == 'i'){ //Si le precede una i, seguramente es 'is'
			; //No hacemos nada XD
		}
	}
	if (palabra[i-1] == 's' && palabra[i-2] != 'i'){ //Aqui la palabra no es un 'is'
		palabra[i-1]='\0'; //Cambiamos esa terminacion en 's' por un fin de linea
	}
	
}
	
//Creditos de la funcion a Abraham
int contar_palabra(const char *palabra_leida, Nodo *conjunto_palabras, int auxiliar){
	int i;
	int paso = 0;
	int nuevoaux;
	
	//Creditos a Abraham
	//Vamos a comparar las nuevas palabras leidas con las que ya se encuentran en el conjunto
	for(i=0; i<auxiliar; i++){
		if(strcmp(conjunto_palabras[i].palabra, palabra_leida)==0){ //Si ambas palabras son iguales
			conjunto_palabras[i].frecuencia+=1; //Agrega 1 a la frecuencia de la palabra
			paso = 1;
		}
		
		if(paso != 1){
			strcpy(conjunto_palabras[auxiliar].palabra, palabra_leida);
			conjunto_palabras[auxiliar].frecuencia=1;
			nuevoaux = auxiliar+1;
		}
	}
	
	if(paso != 1){ //Si la palabra no tuvo algun match 
		strcpy(conjunto_palabras[auxiliar].palabra, palabra_leida); //Se agrega la palabra leida al conjunto
		conjunto_palabras[auxiliar].frecuencia = 1;  //Se le asigna por primera vez una frecuencia
		nuevoaux = auxiliar +1; //Agregamos una posicion más 
		
	}
	
	return nuevoaux;
}
//Creditos a abraham
void guardar_palabras(const Nodo *conjunto_palabras, FILE *archivo_objetivo, int auxiliar){
	int i;
	for(i=auxiliar; i>-1; i--){
		fprintf(archivo_objetivo, "%s:     %d\n", conjunto_palabras[i].palabra, conjunto_palabras[i].frecuencia);
	}
	
}

