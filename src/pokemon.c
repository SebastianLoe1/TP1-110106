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
	struct ataque *ataques[MAX_ATAQUES];
	int cant_ataques;

};

struct info_pokemon {
	pokemon_t** pokemones;
	int cantidad_pokemones;
};

/*pokemon_t *crear_pokemon(const char* string, int delimitadores){
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
}*/

int contar_delimitadores(const char* linea){
	int delimitadores = 0;
	
	for(int i = 0; linea[i] != '\0'; i++){
		if(linea[i] == ";"){
			delimitadores++;
		}
	}
	return delimitadores;
}

enum TIPO asignar_tipo_pokemon(char pokemon_tipo) {
    switch(pokemon_tipo) {
        case 'N':
            return NORMAL;
        case 'F':
            return FUEGO;
        case 'A':
            return AGUA;
        case 'P':
            return PLANTA;
        case 'E':
            return ELECTRICO;
        case 'R':
            return ROCA;
        default:
            return -1;
    }
}

informacion_pokemon_t *pokemon_cargar_archivo(const char *path)
{
	if(path == NULL){
		return NULL;
	}

	int hay_pokemon = 0;
	int cant_ataques = 0;

	FILE* archivo = fopen(path, "r");
	if(archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return NULL;
	}
	informacion_pokemon_t *info_pokemon = malloc(sizeof(informacion_pokemon_t));
	if (info_pokemon == NULL){
		fclose(archivo);
		return NULL;
	}
	info_pokemon->pokemones = NULL;
	info_pokemon->cantidad_pokemones = 0;


	pokemon_t* pokemon = calloc(1, sizeof(pokemon_t));
	if(pokemon == NULL){
		free(info_pokemon);
		fclose(archivo);
		return NULL;
	}

	char linea[100];

	while(fgets(linea, sizeof(linea), path) != NULL){
		char pokemon_tipo;
		int delimitadores = contar_delimitadores(linea);

		if(delimitadores == 1){
			if(sscanf(linea, "%s;%c", pokemon->nombre, &pokemon_tipo) != 2){
				free(pokemon);
				fclose(archivo);
				return info_pokemon;
			}
			
			pokemon->tipo = asignar_tipo_pokemon(pokemon_tipo);
			if(pokemon->tipo == -1){
				free(pokemon);
				fclose(archivo);
				return info_pokemon;
			}

			hay_pokemon = 1;
		}

		if(delimitadores == 2){
			if(sscanf(linea, "%s;%c;%i", pokemon->ataques[pokemon->cant_ataques]->nombre, &pokemon_tipo, &pokemon->ataques[pokemon->cant_ataques]->poder)){
				free(pokemon);
				fclose(archivo);
				return info_pokemon;
			}

			pokemon->ataques[pokemon->cant_ataques]->tipo = asignar_tipo_pokemon(pokemon_tipo);
			if(pokemon->ataques[pokemon->cant_ataques]->tipo == -1){
				free(pokemon);
				fclose(archivo);
				return info_pokemon;
			}

			pokemon->cant_ataques++;
		}

		if(pokemon->cant_ataques == MAX_ATAQUES){
			info_pokemon = realloc(info_pokemon->pokemones, (info_pokemon->cantidad_pokemones + 1) * sizeof(pokemon_t*));
			if(info_pokemon == NULL){
    			free(info_pokemon);
				fclose(archivo);
				return info_pokemon;
			}

			info_pokemon->pokemones[info_pokemon->cantidad_pokemones] = pokemon;

			info_pokemon->cantidad_pokemones++;
			pokemon->cant_ataques = 0;
		}
	}

	fclose(archivo);
	free(pokemon);
	return info_pokemon;
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
