//
//  casilla.cpp
//  trabajo ajedrez prueba
//
//  Created by Sara Íñigo on 10/5/16.
//  Copyright © 2016 Sara Íñigo. All rights reserved.
//

#include "casilla.hpp"

Casilla::Casilla(void){
    
    pieza = nullptr;
}

Pieza* Casilla::getpieza(){
    
    return  pieza;

}

void Casilla::setpieza(Pieza * pieza){
  
    this->pieza=pieza;
    
}

Casilla::~Casilla(void){
}