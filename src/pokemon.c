#include <stdlib.h>
#include "pokemon.h"
#include "tipo.h"
#include <stdio.h>
#include "ataque.h"
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_ATAQUES 3

struct pokemon {
	char nombre[MAX_NOMBRE];
	enum TIPO tipo;
	struct ataque *ataques[MAX_ATAQUES]

};

struct info_pokemon {
	pokemon_t** pokemones;
	int cantidad_pokemones;
};

pokemon_t *crear_pokemon(const char* string, int delimitadores){
	struct pokemon *pokemon = malloc(sizeof(struct pokemon));
	if(pokemon == NULL){
		return NULL;
	}

	//int poke_leidos = sscanf(string, "%s;%c\n%s;%c;%i\n%s;%c;%i\n%s;%c;%i", pokemon->nombre, &pokemon->tipo, pokemon->ataque1.nombre, &pokemon->ataque1.tipo, &pokemon->ataque1.poder, pokemon->ataque2.nombre, &pokemon->ataque2.tipo, &pokemon->ataque2.poder, pokemon->ataque3.nombre, &pokemon->ataque3.tipo, &pokemon->ataque3.poder);
	if(delimitadores ==1){
		int poke_leidos = sscanf(string, nombre, tipo)

	}

	else if (delimitadores == 2)
	if(poke_leidos != 11){
		free(pokemon);
		return NULL;
	}

	return pokemon;
}

int contar_delimitadores(const char* linea){
	int delimitadores = 0;
	
	for(int i = 0; linea[i] != '\0'; i++){
		if(linea[i] == ";"){
			delimitadores++;
		}
	}
	return delimitadores;
}

informacion_pokemon_t *pokemon_cargar_archivo(const char *path)
{
	FILE* archivo = fopen(path, "r");
	if(archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return NULL;
	}
	informacion_pokemon_t *info_pokemon = malloc(sizeof(informacion_pokemon_t));
	if (info_pokemon == NULL){
		return NULL;
	}
	info_pokemon->pokemones = NULL;
	info_pokemon->cantidad_pokemones = 0;


	pokemon_t* pokemon = calloc(1, sizeof(pokemon_t));
	if(pokemon == NULL){
		free(info_pokemon);
		return NULL;
	}

	/*int i = 0;
	while(fscanf(archivo, "%s;%c\n%s;%c;%i\n%s;%c;%i\n%s;%c;%i", pokemon->nombre, &info_pokemon->pokemones[i]->tipo, info_pokemon->pokemones[i]->ataque1.nombre, &info_pokemon->pokemones[i]->ataque1.tipo, &info_pokemon->pokemones[i]->ataque1.poder, info_pokemon->pokemones[i]->ataque2.nombre, &info_pokemon->pokemones[i]->ataque2.tipo, &info_pokemon->pokemones[i]->ataque2.poder, info_pokemon->pokemones[i]->ataque3.nombre, &info_pokemon->pokemones[i]->ataque3.tipo, &info_pokemon->pokemones[i]->ataque3.poder) == 11){
		i++;
		info_pokemon->pokemones = realloc(info_pokemon->pokemones, (1+info_pokemones->cantidad_pokemones)*(sizeof(pokemon_t*)));
		info_pokemon->pokemones[info_pokemon->cantidad_pokemones] = pokemon;
		info_pokemon->cantidad_pokemones++;

		
	}*/


	//como hacer esto: cada pokemon viene con multiplos de 4 en las lineas
	//tambien se puede pensar que post leer el pokemon hacemos un for que itere 3 veces para los ataques.

	char linea[500];

	while(fgets(linea, 500, path) != NULL){
		char pokemon_tipo;
		int delimitadores = contar_delimitadores(linea);

		//sscanf(%i,%s,%i)); = numero, hola;6;7 == 3
										hola;2 == 2

	}

}

pokemon_t *pokemon_buscar(informacion_pokemon_t *ip, const char *nombre)
{
	return NULL;
}

int pokemon_cantidad(informacion_pokemon_t *ip)
{
	return 0;
}

const char *pokemon_nombre(pokemon_t *pokemon)
{
	return NULL;
}

enum TIPO pokemon_tipo(pokemon_t *pokemon)
{
	return FUEGO;
}

const struct ataque *pokemon_buscar_ataque(pokemon_t *pokemon, const char *nombre)
{
	return NULL;
}

int con_cada_pokemon(informacion_pokemon_t *ip, void (*f)(pokemon_t *, void *), void *aux)
{
	return 0;
}

int con_cada_ataque(pokemon_t *pokemon, void (*f)(const struct ataque *, void *), void *aux)
{
	return 0;
}

void pokemon_destruir_todo(informacion_pokemon_t *ip)
{
}
