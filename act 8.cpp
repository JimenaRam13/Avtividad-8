
/******************************************************************************

                            Nombre: Jimena Ramirez
                         Fecha: 19 de febrero de 2024
                            Programa: Ejercicio5.cpp
                     CENTRO UNIVERSITARIO DE LOS ALTOS/
                         UNIVERSIDAD DE GUADALAJARA/
                         INGENIERIA EN COMPUTACION/
                              SEGUNDO SEMESTRE
                     Profesor: Carlos Javier Cruz Franco
    Descripcion: En este programa el usuario puede agregar, mostrar, editar, 
                       sumar, borrar y vaciar valores.
                            
*******************************************************************************/

#include <stdio.h>
#include <iostream>
int num[10], a, suma;
void Agregar(){
    int hm;
    printf("¿Cuantos valores deseas agregar?\n");
    scanf("%d", &hm);
    printf("Agregue los valores\n");
    for(a=0; a<hm; a++){
        scanf("%d", &num[a]);
    }
}
void Mostrar(){
    printf("Los valores que has ingresado son:\n");
    for(a=0; a<10; a++){
        printf("%d\n", num[a]);
    }
}
void Sumar(){
    suma=0;
    for(a=0; a<10; a++){
        suma=suma+num[a];
    }
    printf("%d\n", suma);
}
void Editar(){
    int posicion, nuevo;
    printf("¿Que posicion quieres editar?\n");
    scanf("%d", &posicion);
    if(posicion<0 || posicion>10){
        printf("Posicion fuera de rango favor de poner una posicion que si sea aceptable\n");
        Editar();
    }
    else{
        printf("Anota el nuevo numero\n");
        scanf("%d", &nuevo);
        num[posicion-1]=nuevo;
    }
}
void Borrar(){
    int borra;
    printf("Ingresa la posicion del numero que quieres eliminar\n");
    scanf("%d", &borra);
    if(borra<0 || borra>10){
        printf("Posicion fuera de rango favor de poner una posicion que si sea aceptable\n");
        Borrar();
    }
    else{
        num[borra-1]=NULL;
    }
}
void Vaciar(){
    for(a=0; a<10; a++){
        num[a]=0;
    }
    printf("Se ha vaciado el arreglo");
}
void Menu(){
    int operacion;
    printf("¿Que operacion quieres realizar?\n\t1 para AGREGAR VALORES\n\t2 para MOSTRAR VALORES\n\t3 para MOSTRAR LA SUMATORIA DE LOS VALORES\n\t4 para EDITAR VALORES\n\t5 para BORRAR VALORES\n\t6 para VACIAR EL ARREGLO\n\t7 para SALIR\n");
    scanf("%d", &operacion);
    switch(operacion){
        case 1:
        Agregar();
        Menu();
        break;
        case 2:
        Mostrar();
        Menu();
        break;
        case 3:
        Sumar();
        Menu();
        break;
        case 4:
        Editar();
        Menu();
        break;
        case 5:
        Borrar();
        Menu();
        break;
        case 6:
        Vaciar();
        Menu();
        break;
        case 7:
        printf("Gracias por usarme, espero te haya gustado :D");
        break;
    }
}
int main(){
    Menu();
    return 0;
}