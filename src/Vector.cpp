#include "Vector.hpp"
#include <iostream>
Vector::Vector() {
    this->tamanioMaximo= 15;
    this->cantidadDatos= 0;
    this->datos = new Item*[cantidadDatos];
}

void Vector::alta(Item *dato) {
    if(cantidadDatos<tamanioMaximo){
        datos[cantidadDatos] = dato;
        cantidadDatos++;
    }else{
        std::cout<<"cantidad de datos maxima alcanzada"<<std::endl;
    }
}

void Vector::alta(Item *dato, size_t indice) {
    Item *dato_aux;
    if(indice <=cantidadDatos){
        if(indice<cantidadDatos){
            do {
                dato_aux = datos[indice];
                datos[indice+1] = dato_aux;
            }while(datos[indice+1] != nullptr);
            datos[indice] = dato;
            cantidadDatos++;
        }else if(indice==cantidadDatos){
            alta(dato);
        }
    }
}
Item* Vector::baja() {
    if(cantidadDatos!=0){
        delete datos[cantidadDatos];
        cantidadDatos--;
    }else{
        std::cout<<"el vector se encuenta vacio"<<std::endl;
    }
}
Item* Vector::baja(size_t indice) {
    if(cantidadDatos > 0 && indice <= cantidadDatos){
        delete datos[indice];
        cantidadDatos--;
    }
}


