/******************************************************************************

                              Nombre: Jimena Ramirez
                         Fecha: 10 de marzo de 2024
                            Programa: Ejercicio7.cpp
                     CENTRO UNIVERSITARIO DE LOS ALTOS/
                         UNIVERSIDAD DE GUADALAJARA/
                         INGENIERIA EN COMPUTACION/
                              SEGUNDO SEMESTRE
                     Profesor: Carlos Javier Cruz Franco
    Descripcion: En este programa el usuario puede crear dos conjuntos, en 
        el cual puede agregar, editar, borrar los elementos o vaciar el 
               conjunto, ademas de hacer operaciones matematicas.

*******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
using namespace std;
std::set<std::string> conjunto1;
std::set<std::string> conjunto2;
std::set<std::string> unionuwu;
std::set<std::string> interseccionuwu;
std::set<std::string> diferenciauwu;
std::set<std::string> complementouwu;
int tam1, tam2, a, d, e, g, h, conjunto;
string b, c, f;

void Tamaño1(){
    printf("¿De qué tamaño es el primer conjunto?\n");
    scanf("%d", &tam1);
    if(tam1<5){
        printf("El conjunto debe tener un tamaño minimo de 5\n");
        Tamaño1();
    }
}
void Tamaño2(){
    printf("¿De qué tamaño es el segundo conjunto?\n");
    scanf("%d", &tam2);
    if(tam2<5){
        printf("El conjunto debe tener un tamaño minimo de 5\n");
        Tamaño2();
    }
}

void Agregar1(){
    string elemento;
    printf("Agrega los elementos del conjunto 1\n");
    for(a=0; a<tam1; a++){
        cout<< "Elemento " << a+1 <<" ";
        cin>> elemento;
        conjunto1.insert(elemento);
    }
}

void Agregar2(){
    string elemento;
    printf("Agrega los elementos del conjunto 2\n");
    for(a=0; a<tam2; a++){
        cout<< "Elemento " << a+1 <<" ";
        cin>> elemento;
        conjunto2.insert(elemento);
    }
}

void Agregar(){
    printf("¿En qué conjunto quieres agregar valores?\n");
    scanf("%d", &conjunto);
    switch(conjunto){
        case 1:
        Agregar1();
        break;
        case 2:
        Agregar2();
        break;
    }
}

void Mostrar(){
    printf("Conjunto 1:\n{");
    for(const auto& elem : conjunto1){
        cout << elem << ", " ;
    }
    printf("}");

    printf("\nConjunto 2:\n{");
    for(const auto& elem : conjunto2){
        cout << elem << ", " ;
    }
    printf("}\n");
}

void Editar(){
    printf("¿Cual es el conjunto en el que quieres editar?\n");
    scanf("%d", &d);
    switch(d){
        case 1:
        printf("Tu conjunto 1 es:\n{");
        for(const auto& elem : conjunto1){
            cout << elem << ", " ;
        }
        printf("}\n");
        cout<< "¿Cual es el elemento que deseas reemplazar?\n";
        cin>> b;
        cout<< "¿Cual es el nuevo elemento que deseas poner?\n";
        cin>> c;
        if(conjunto1.erase(b)){
            conjunto1.insert(c);
            printf("Se ha editado correctamente el conjunto\n");
        }
        else{
            printf("Ese no parece un elemento valido\n");
        }
        break;
        case 2:
        printf("Tu conjunto 2 es:\n{");
        for(const auto& elem : conjunto2){
            cout << elem << ", " ;
        }
        printf("}\n");
        cout<< "¿Cual es el elemento que deseas reemplazar?\n";
        cin>> b;
        cout<< "¿Cual es el nuevo elemento que deseas poner?\n";
        cin>> c;
        if(conjunto1.erase(b)){
            conjunto1.insert(c);
            printf("Se ha editado correctamente el conjunto\n");
        }
        else{
            printf("Ese no parece un elemento valido\n");
        }
        break;
    }
}

void Borrar(){
    printf("¿Cual es el conjunto en el que quieres eliminar?\n");
    scanf("%d", &e);
    switch(e){
        case 1:
        printf("Tu conjunto 1 es:\n{");
        for(const auto& elem : conjunto1){
            cout << elem << ", " ;
        }
        printf("}\n");
        cout<< "¿Cual es el elemento que deseas borrar?\n";
        cin>> f;
        if(conjunto1.erase(f)){
            printf("Se ha borrado correctamente el elemento\n");
        }
        else{
            printf("Ese no parece un elemento valido\n");
        }
        break;
        case 2:
        printf("Tu conjunto 2 es:\n{");
        for(const auto& elem : conjunto2){
            cout << elem << ", " ;
        }
        printf("}\n");
        cout<< "¿Cual es el elemento que deseas borrar?\n";
        cin>> f;
        if(conjunto2.erase(f)){
            printf("Se ha borrado correctamente el elemento\n");
        }
        else{
            printf("Ese no parece un elemento valido\n");
        }
        break;
    }
}

void Vaciar(){
    printf("¿Cual es el conjunto que quieres vaciar?\n");
    scanf("%d", &g);
    switch(g){
        case 1:
        conjunto1.clear();
            printf("Se ha vaciado correctamente el conjunto 1\n");
            break;
        case 2:
            conjunto2.clear();
            printf("Se ha vaciado correctamente el conjunto 2\n");
            break;
    }
}

void Union(){
    unionuwu.clear(); 
    for(const auto& elem : conjunto1){
        unionuwu.insert(elem);
    }
    for(const auto& elem : conjunto2){
        unionuwu.insert(elem);
    }
    printf("La union de los dos conjuntos da como resultado:\n{");
    for(const auto& elem : unionuwu){
        cout << elem << ", " ;
    }
    printf("}\n");
}

void Interseccion(){
    interseccionuwu.clear();
    for(const auto& elem : conjunto1){
        if(conjunto2.find(elem) != conjunto2.end()){
            interseccionuwu.insert(elem);
        }
    }
    printf("La interseccion de los dos conjuntos da como resultado:\n{");
    for(const auto& elem : interseccionuwu){
        cout << elem << ", " ;
    }
    printf("}\n");
}

void Diferencia(){
    diferenciauwu.clear();
    for(const auto& elem : conjunto1){
        if(conjunto2.find(elem) == conjunto2.end()){
            diferenciauwu.insert(elem);
        }
    }
    printf("La diferencia entre los conjuntos (conjunto1 - conjunto2) da como resultado:\n{");
    for(const auto& elem : diferenciauwu){
        cout << elem << ", " ;
    }
    printf("}\n");
}

void Complemento(){
    complementouwu.clear();
    for(const auto& elem : conjunto2){
        if(conjunto1.find(elem) == conjunto1.end()){
            complementouwu.insert(elem);
        }
    }
    printf("El complemento de conjunto1 respecto a conjunto2 da como resultado:\n{");
    for(const auto& elem : complementouwu){
        cout << elem << ", " ;
    }
    printf("}\n");
}

void OpConjuntos(){
    printf("Escribe la operacion que quieres hacer:\n\t1 para hacer la UNION de los dos con conjuntos\n\t2 para hacer la INTERSECCION de los dos conjuntos\n\t3 para hacer la DIFERENCIA de los dos conjuntos\n\t4 para hacer el COMPLEMENTO de los conjuntos\n");
    scanf("%d", &h);
    switch(h){
        case 1:
        Union();
        break;
        case 2:
        Interseccion();
        break;
        case 3:
        Diferencia();
        break;
        Complemento();
        break;
    }
}

void Menu(){
    int operacion;
    printf("¿Que operacion quieres realizar?\n\t1 para AGREGAR VALORES\n\t2 para MOSTRAR VALORES\n\t3 para EDITAR VALORES\n\t4 para BORRAR VALORES\n\t5 para VACIAR UN CONJUNTO\n\t6 para REALIZAR UNA OPERACION DE CONJUNTOS\n\t7 para SALIR\n");
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
        Editar();
        Menu();
        break;
        case 4:
        Borrar();
        Menu();
        break;
        case 5:
        Vaciar();
        Menu();
        break;
        case 6:
        OpConjuntos();
        Menu();
        break;
        case 7:
        printf("Gracias por usarme, espero te haya gustado :D");
        break;
        
    }
}
int main(){
    Tamaño1();
    Tamaño2();
    Menu();
    return 0;
}