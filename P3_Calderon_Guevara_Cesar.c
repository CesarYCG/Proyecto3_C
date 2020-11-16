#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contador.h"
#include "contador.c"

//Este manipulador de archivos solo trabaja con archivos .txt
int main(int argc, char *argv[]) {
	char nom_archivo_consulta[15];   //Nombre archivo de donde leeremos
	char nom_archivo_resultante[15]; //Nombre archivo donde se escribe
	char filtro_archivo[4] = "txt";  //Valida el .txt
	int validar_archivo = 0;         //Valida el .txt
	int aux = 0;
	//int tamanio_arreglo = 0;
	//int auxiliar = 0; //Variable que nos ayudara a desplazarnos por el arreglo
	
	
	//Variable palabras de tipo Nodo
	Nodo *palabras = NULL;
	//Para manipular los archivos
	FILE *arch_consulta = NULL;
	FILE *arch_resultante = NULL;

	while (validar_archivo != 1){
		printf("Dame el nombre del archivo.txt a consultar, pulsa Enter para continuar.\n");
		scanf("%s", nom_archivo_consulta);
		printf("Dime el nombre del archivo.txt donde quieres guardar la modificacion\n"); 
		printf("Pulsa enter para continuar\n");
		scanf("%s", nom_archivo_resultante);
		if (strstr(nom_archivo_consulta, filtro_archivo) == NULL){
			printf("El archivo consulta no es .txt, intente de nuevo\n");
			getchar();
		}else if (strstr(nom_archivo_resultante, filtro_archivo) == NULL){
			printf("El archivo para almacenar la modificacion no es .txt, intente de nuevo\n");
			getchar();
		}else
			validar_archivo = 1; //Los archivos ya poseen extension txt
	}
	
	arch_consulta = fopen(nom_archivo_consulta, "r"); //Abrimos archivo objetivo con permisos de lectura
	arch_resultante = fopen(nom_archivo_resultante, "w"); //Abrimos archivo resultante con perm lectura
	
	if (arch_consulta == NULL || arch_resultante == NULL){ //Si no se pudo abrir algun archivo
		printf("No se pudo abrir algun archivo, verifique nombre e integridad\n");
		return 1; //Retornamos error porque no pudimos abrir los archivos
	}else{
		//A partir de aqui, se comienza a definir las instrucciones para contar palabras
		char cadena_leida[50]; // para almacenar la palabra leida
		
		while(!feof(arch_consulta)){ //Mientras NO se llegue al final del archivo.
		  
			fscanf(arch_consulta, "%s", cadena_leida);
			aux+=1;
		}
		rewind(arch_consulta);
		palabras = (Nodo *) malloc(aux*sizeof(Nodo));
		
		aux = 0;
		while (!feof(arch_consulta)){ //Mientras no terminemos de leer el archivo
			fscanf(arch_consulta, "%s", cadena_leida); //La palabra leida del archivo se manda a la cadena
			limpiar_palabra(cadena_leida);	//Funcion para limpiar la cadena
			//printf(" %s\n", cadena_leida);
			if(aux==0){		//Se agrega la primer palabra
				strcpy(palabras[aux].palabra, cadena_leida);
				palabras[aux].frecuencia = 1;
				aux++;
			}else
			   {
				aux = contar_palabra(cadena_leida, palabras, aux);
			}
		}
		guardar_palabras(palabras, arch_resultante, aux);
		
	}
	
	fclose(arch_consulta);
	fclose(arch_resultante);
	free(palabras);
	
	return 0;
}
