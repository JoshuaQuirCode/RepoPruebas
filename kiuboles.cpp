//INICIO DE CODIGO CON MAU Y JOSHUA;

//Como estas mau ?;

//bien y tu ?;

//bien tambien;
//Que haces;

//haciendo cosas de git;
// y tu ?;

//Igual;
//Seguimos mañana?;

//a que hora ?;

//como a las 8;

//am o pm ;

//pm;

//OOOOOOOOOOOOOOKKKKKKKKKKKKKKKKK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Función para convertir el nombre de la ciudad en su respectivo desplazamiento horario
int get_timezone_offset(char *city) {
    int offset = 0;
    if (strcmp(city, "Nueva York") == 0) {
        offset = -5;
    } else if (strcmp(city, "Los Ángeles") == 0) {
        offset = -8;
    } else if (strcmp(city, "Londres") == 0) {
        offset = 0;
    } else if (strcmp(city, "París") == 0) {
        offset = 1;
    } else if (strcmp(city, "Tokio") == 0) {
        offset = 9;
    }
    return offset;
}

// Función para obtener el tiempo actual en una ciudad dada
void get_local_time(char *city) {
    // Obtenemos el desplazamiento horario de la ciudad
    int offset = get_timezone_offset(city);
    
    // Obtenemos la hora actual en el sistema
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = gmtime(&rawtime);
    
    // Sumamos el desplazamiento horario a la hora actual
    timeinfo->tm_hour += offset;
    mktime(timeinfo);
    
    // Imprimimos el horario local de la ciudad
    printf("La hora actual en %s es %02d:%02d:%02d\n", city, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

// Función principal
int main() {
    // Pedimos al usuario que ingrese la ciudad de la que desea conocer el horario local
    char city[20];
    printf("Ingrese el nombre de la ciudad de la que desea conocer el horario local: ");
    scanf("%[^\n]%*c", city);
    
    // Obtenemos el horario local de la ciudad
    get_local_time(city);
    
    return 0;
}

