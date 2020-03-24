#include "pieza.hpp"
#include "casilla.hpp"
#include <stdlib.h>
#include <stdio.h>
#include<iostream>

//Definición funciones de clase Pieza


Pieza::Pieza(int p,Casilla** t){
    
    jugador = p;
    
    tablero=t;
    
}

Pieza::~Pieza(void){
    
}


int Pieza::getjugador(){
    
    return jugador;
    
}

//Deficición funciones de Rey

Rey::Rey(int p,Casilla** t):Pieza(p, t){
    
    hamovido=0;
    
}


Rey::~Rey(void){
    
}


bool Rey::mover(int a, int b , int c, int d){
    bool test;
    if(a==c && ((a==0 && jugador==1) ||(a==7 && jugador ==2)) && this->getmovido()==false && abs(b-d)==2 &&(tablero[a][d+1].getpieza()->tipo()=='t' || tablero[a][d-2].getpieza()->tipo()=='t')) {
        if(d==2 && tablero[0][0].getpieza()->tipo()=='t' && ((Torre*) tablero[0][0].getpieza())->getmovido()==false) {
            enrocar(true);
            test= true;
        } else if(d==6 && tablero[0][7].getpieza()->tipo()=='t' && ((Torre*) tablero[0][7].getpieza())->getmovido()==false){
            enrocar(false);
            test= true;
        }else {
            test= false;
        }
        
    }else {
        test=puedoMover(a,b,c,d);
        if(test) {
            Pieza* p= tablero[a][b].getpieza() ;
            tablero[a][b].setpieza(nullptr);
            tablero[c][d].setpieza(p);
            this->hamovido=true;
        }
    }
    if(test) {
        turno++;
    }
    return test;
    
}


bool Rey::comer(int a, int b , int c, int d){
    bool test=puedoComer(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
        this->hamovido=true;
    }
    if(test) {
        turno++;
    }
    return test;
}

bool Rey::puedoMover(int a,int b ,int c,int d) {
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test = test && (abs(a-c)==1|| abs (b-d)==1);
    test=test && tablero[c][d].getpieza()==nullptr ;
    return test;
}

bool Rey::puedoComer(int a,int b ,int c,int d) {
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test = test && (abs(a-c)==1|| abs (b-d)==1);
    test=test && tablero[c][d].getpieza()!=nullptr ;
    return test;
}

int * Rey::posicionposible(int a, int b){ //eso llama comer y mover, cambiar si hay movimientos
    int i,j,l;
    l=0;
    int* listPos = new int[16];
    for(i=-1;i<2;i++) {
        for(j=-1;j<2;j++) {
            if((i || j) && puedoMover(a,b,a+i,b+j) ) {
                listPos[l]=a+i;
                l++;
                listPos[l]=b+j;
                l++;
            } else if((i || j) && puedoComer(a,b,a+i,b+j) ) {
                listPos[l]=a+i;
                l++;
                listPos[l]=b+j;
                l++;
            }
        }
    }
    return listPos;
}

bool Rey::getmovido(){
    return this->hamovido;
}

void Rey::enrocar(bool a){
    Pieza*p;
    if(a&& jugador==1) {
        p= tablero[0][4].getpieza() ;
        tablero[0][4].setpieza(nullptr);
        tablero[0][2].setpieza(p);
        ((Torre*) tablero[0][0].getpieza())->enrocar();
    } else if(a && jugador==2) {
        p= tablero[7][4].getpieza() ;
        tablero[7][4].setpieza(nullptr);
        tablero[7][2].setpieza(p);
        ((Torre*) tablero[7][0].getpieza())->enrocar();
    } else if(!a && jugador ==1) {
        p= tablero[0][4].getpieza() ;
        tablero[0][4].setpieza(nullptr);
        tablero[0][6].setpieza(p);
        ((Torre*) tablero[0][7].getpieza())->enrocar();
    } else {
        p= tablero[7][4].getpieza() ;
        tablero[7][4].setpieza(nullptr);
        tablero[7][6].setpieza(p);
        ((Torre*) tablero[7][7].getpieza())->enrocar();
    }
}


//Deficición funciones de Reina

Reina::Reina(int p,Casilla** t):Pieza(p, t){
    
}

Reina::~Reina(void){
}



bool Reina::mover(int a, int b, int c, int d){
    bool test=puedoComer(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
    }
    if(test) {
        turno++;
    }
    return test;
    
}


bool Reina::comer(int a, int b, int c, int d){
    bool test=puedoComer(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
    }
    if(test) {
        turno++;
    }
    return test;
    
}


bool Reina::puedoMover(int a,int b ,int c,int d) {
    int i=0, direccion;
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test= test && a==c && b==d;
    direccion= ((a<=c)&& (b<=d ))?1:-1;
    if(test && a==c) {
        i=b+direccion;
        while(test && i!=d){
            test = tablero[a][i].getpieza()==nullptr;
            i+=direccion;
        }
    }else if(test && b==d) {
        i=a+direccion;
        while(test && i!=c){
            test = tablero[i][b].getpieza()==nullptr;
            i+=direccion;
        }
    } else if(test && (a-c)==(b-d)){
        i=direccion;
        while(test && a+i!=c){
            test = tablero[a+i][b+i].getpieza()==nullptr;
            i+=direccion;
        }
    } else if(test && (a-c)==-(b-d)) {
        direccion=(a<c)?1:-1;
        i=direccion;
        while(test && a+i!=c){
            test = tablero[a+i][b-i].getpieza()==nullptr;
            i+=direccion;
        }
    }
    test=test && tablero[c][d].getpieza()==nullptr;
    return test;
}

bool Reina::puedoComer(int a,int b ,int c,int d) {
    int i=0, direccion;
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test= test && a==c && b==d;
    direccion= (a<=c && b<=d )?1:-1;
    if(test && a==c) {
        i=b+direccion;
        while(test && i!=d){
            test = tablero[a][i].getpieza()==nullptr;
            i+=direccion;
        }
    }else if(test && b==d) {
        i=a+direccion;
        while(test && i!=c){
            test = tablero[i][b].getpieza()==nullptr;
            i+=direccion;
        }
    } else if(test && (a-c)==(b-d)){
        i=direccion;
        while(test && a+i!=c){
            test = tablero[a+i][b+i].getpieza()==nullptr;
            i+=direccion;
        }
    } else if(test && (a-c)==-(b-d)) {
        direccion=(a<c)?1:-1;
        i=direccion;
        while(test && a+i!=c){
            test = tablero[a+i][b-i].getpieza()==nullptr;
            i+=direccion;
        }
    }
    test=test && tablero[c][d].getpieza()!=nullptr ;
    return test;
}


int * Reina::posicionposible(int a, int b){
    int i,l;
    l=0;
    int* listPos = new int[64];
    for(i=-7;i<8;i++) {
        if(i && puedoMover(a,b,a+i,b) ) {//mover segun la columna
            listPos[l]=a+i;
            l++;
            listPos[l]=b;
            l++;
        } else if(i && puedoComer(a,b,a+i,b) ) {//comer segun la columna
            listPos[l]=a+i;
            l++;
            listPos[l]=b;
            l++;
        }
        if(i && puedoMover(a,b,a,b+i) ) {//mover segun la linea
            listPos[l]=a;
            l++;
            listPos[l]=b+i;
            l++;
        } else if(i && puedoComer(a,b,a,b+i) ) {//comer segun la linea
            listPos[l]=a;
            l++;
            listPos[l]=b+i;
            l++;
        }
        if(i && puedoMover(a,b,a+i,b+i) ) {//mover segun la diagonal abajo a ariba
            listPos[l]=a+i;
            l++;
            listPos[l]=b+i;
            l++;
        } else if(i && puedoComer(a,b,a+i,b+i) ) {//comer segun la diagonal abajo a ariba
            listPos[l]=a+i;
            l++;
            listPos[l]=b+i;
            l++;
        }
        if(i && puedoMover(a,b,a+i,b-i) ) {//mover segun la diagonal ariba a abajo
            listPos[l]=a+i;
            l++;
            listPos[l]=b-i;
            l++;
        } else if(i && puedoComer(a,b,a+i,b-i) ) {//comer segun la diagonal ariba a abajo
            listPos[l]=a+i;
            l++;
            listPos[l]=b-i;
            l++;
        }
        
    }
    return listPos;
}


//Deficición funciones de Torre

Torre::Torre(int p,Casilla** t):Pieza(p, t){
    
    hamovido=0;
    
}


Torre::~Torre(void){
    
}


bool Torre::mover(int a, int b, int c, int d){
    bool test=puedoComer(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
        hamovido=true;
    }
    if(test) {
        turno++;
    }
    return test;
}


bool Torre::comer(int a, int b, int c, int d){
    bool test=puedoComer(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
        hamovido=true;
    }
    if(test) {
        turno++;
    }
    return test;
}

bool Torre::puedoMover(int a,int b ,int c,int d) {
    int i=0, direccion;
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test= test && a==c && b==d;
    direccion= (a<=c && b<=d )?1:-1;
    if(test && a==c) {
        i=b+direccion;
        while(test && i!=d){
            test = tablero[a][i].getpieza()==nullptr;
            i+=direccion;
        }
    }else if(test && b==d) {
        i=a+direccion;
        while(test && i!=c){
            test = tablero[i][b].getpieza()==nullptr;
            i+=direccion;
        }
    }
    test=test && tablero[c][d].getpieza()==nullptr ;
    return test;
}

bool Torre::puedoComer(int a,int b ,int c,int d) {
    int i=0, direccion;
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test= test && a==c && b==d;
    direccion= (a<=c && b<=d )?1:-1;
    if(test && a==c) {
        i=b+direccion;
        while(test && i!=d){
            test = tablero[a][i].getpieza()==nullptr;
            i+=direccion;
        }
    }else if(test && b==d) {
        i=a+direccion;
        while(test && i!=c){
            test = tablero[i][b].getpieza()==nullptr;
            i+=direccion;
        }
    }
    test=test && tablero[c][d].getpieza()!=nullptr ;
    return test;
}


int * Torre::posicionposible(int a, int b){
    int i,l;
    l=0;
    int* listPos = new int[64];
    for(i=-7;i<8;i++) {
        if(i && puedoMover(a,b,a+i,b) ) {//mover segun al columna
            listPos[l]=a+i;
            l++;
            listPos[l]=b;
            l++;
        } else if(i && puedoComer(a,b,a+i,b) ) {//comer segun la columna
            listPos[l]=a+i;
            l++;
            listPos[l]=b;
            l++;
        }
        if(i && puedoMover(a,b,a,b+i) ) {//mover segun la linea
            listPos[l]=a;
            l++;
            listPos[l]=b+i;
            l++;
        } else if(i && puedoComer(a,b,a,b+i) ) {//comer segun la linea
            listPos[l]=a;
            l++;
            listPos[l]=b+i;
            l++;
        }
    }
    return listPos;
}


bool Torre::getmovido(){
    return this->hamovido;
}

void Torre::enrocar(){
    int linea=(jugador==1) ? 0 : 7;
    int columnaInit = (tablero[linea][2].getpieza()->tipo()=='k')?0:7;
    int columna = (tablero[linea][2].getpieza()->tipo()=='k')?3:5;
    Pieza* p= tablero[linea][columnaInit].getpieza() ;
    tablero[linea][columnaInit].setpieza(nullptr);
    tablero[linea][columna].setpieza(p);
}


//Deficición funciones de Alfil

Alfil::Alfil(int p,Casilla** t):Pieza(p, t){
    
}

Alfil::~Alfil(void){
}



bool Alfil::mover(int a, int b, int c, int d){
    bool test=puedoMover(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
    }
    if(test) {
        turno++;
    }
    return test;
    
}


bool Alfil::comer(int a, int b, int c, int d){
    bool test=puedoComer(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
    }
    if(test) {
        turno++;
    }
    return test;
    
}


bool Alfil::puedoMover(int a,int b ,int c,int d) {
    int i=0, direccion;
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test= test && a==c && b==d;
    direccion= (a<=c && b<=d )?1:-1;
    if(test && (a-c)==(b-d)){
        i=direccion;
        while(test && a+i!=c){
            test = tablero[a+i][b+i].getpieza()==nullptr;
            i+=direccion;
        }
    } else if(test && (a-c)==-(b-d)) {
        direccion=(a<c)?1:-1;
        i=direccion;
        while(test && a+i!=c){
            test = tablero[a+i][b-i].getpieza()==nullptr;
            i+=direccion;
        }
    }
    test=test && tablero[c][d].getpieza()==nullptr ;
    return test;
}

bool Alfil::puedoComer(int a,int b ,int c,int d) {
    int i=0, direccion;
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test= test && a==c && b==d;
    direccion= (a<=c && b<=d )?1:-1;
    if(test && (a-c)==(b-d)){
        i=direccion;
        while(test && a+i!=c){
            test = tablero[a+i][b+i].getpieza()==nullptr;
            i+=direccion;
        }
    } else if(test && (a-c)==-(b-d)) {
        direccion=(a<c)?1:-1;
        i=direccion;
        while(test && a+i!=c){
            test = tablero[a+i][b-i].getpieza()==nullptr;
            i+=direccion;
        }
    }
    test=test && tablero[c][d].getpieza()!=nullptr ;
    return test;
}


int * Alfil::posicionposible(int a, int b){
    int i,l;
    l=0;
    int* listPos = new int[64];
    for(i=-7;i<8;i++) {
        if(i && puedoMover(a,b,a+i,b+i) ) {//mover segun la diagonal de abajo a ariba
            listPos[l]=a+i;
            l++;
            listPos[l]=b+i;
            l++;
        } else if(i && puedoComer(a,b,a+i,b+i) ) {//comer segun la diagonal de abajo a ariba
            listPos[l]=a+i;
            l++;
            listPos[l]=b+i;
            l++;
        }
        if(i && puedoMover(a,b,a+i,b-i) ) {//mover segun la diagonal de ariba a abajo
            listPos[l]=a+i;
            l++;
            listPos[l]=b-i;
            l++;
        } else if(i && puedoComer(a,b,a+i,b-i) ) {//comer segun la diagonal de ariba a abajo
            listPos[l]=a+i;
            l++;
            listPos[l]=b-i;
            l++;
        }
    }
    return listPos;
}


//Deficición funciones de Caballo

Caballo::Caballo(int p,Casilla** t):Pieza(p, t){
    
}

Caballo::~Caballo(void){
}



bool Caballo::mover(int a, int b, int c, int d){
    bool test=puedoMover(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
    }
    if(test) {
        turno++;
    }
    return test;
    
}


bool Caballo::comer(int a, int b, int c, int d){
    bool test=puedoComer(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
    }
    if(test) {
        turno++;
    }
    return test;
    
}


bool Caballo::puedoMover(int a,int b ,int c,int d) {
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test= test && ( (abs(a-c)==1 && abs(b-d) == 2)|| (abs(b-d)==1 && abs(a-c) == 2) ) ;
    test=test && tablero[c][d].getpieza()==nullptr ;
    return test;
}

bool Caballo::puedoComer(int a,int b ,int c,int d) {
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test= test && ((abs(a-c)==1 && abs(b-d) == 2)|| (abs(b-d)==1 && abs(a-c) == 2) ) ;
    test=test && tablero[c][d].getpieza()!=nullptr ;
    return test;
}


int * Caballo::posicionposible(int a, int b){
    int i,l;
    l=0;
    int* listPos = new int[64];
    for(i=-2;i<2;i++) {
        if(i && puedoMover(a,b,a+i,b-3+abs(i)) ) {
            listPos[l]=a+i;
            l++;
            listPos[l]=b-3+abs(i);
            l++;
        } else if(i && puedoComer(a,b,a+i,b+abs(i)-3 )) {
            listPos[l]=a+i;
            l++;
            listPos[l]=b-3+abs(i);
            l++;
        }
        if(i && puedoMover(a,b,a+i,b-(-3+abs(i))) ) {
            listPos[l]=a+i;
            l++;
            listPos[l]=b-(abs(i)-3);
            l++;
        } else if(i && puedoComer(a,b,a+i,b-(abs(i)-3) )) {
            listPos[l]=a+i;
            l++;
            listPos[l]=b-(abs(i)-3);
            l++;
        }
        
    }
    return listPos;
}


//Deficición funciones de Peon

Peon::Peon(int p,Casilla** t):Pieza(p, t){
    
    haavanzado=0;
}

Peon::~Peon(void){
}



bool Peon::mover(int a,int b ,int c,int d) {
    bool test=puedoMover(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
        if(abs(a-c)==2) {
            haavanzado=turno;
        }
    }
    if(test) {
        turno++;
    }
    return test;
}


bool Peon::comer(int a, int b, int c, int d){
    bool test=puedoComer(a,b,c,d);
    if(test) {
        Pieza* p= tablero[a][b].getpieza() ;
        tablero[a][b].setpieza(nullptr);
        tablero[c][d].setpieza(p);
    }
    if(test) {
        turno++;
    }
    return test;
}


bool Peon::puedoMover(int a,int b ,int c,int d) {
    int direccion=(jugador==1)?1:-1;
    bool test = c<8 && c>-1 && d<8 && d>-1;
    test= test && b==d && ((a+direccion && c )|| (a+2*direccion==c && tablero[a+direccion][b].getpieza()==nullptr && haavanzado==0 && ((a==1 && jugador==1 )|| (jugador ==2 && a==6))) );
    test=test && tablero[c][d].getpieza()==nullptr ;
    return test;
}

bool Peon::puedoComer(int a,int b ,int c,int d) {
    bool test = c<8 && c>-1 && d<8 && d>-1;
    int direccion=(jugador==1)?1:-1;
    test= test && a+direccion==c && abs(b-d)==1;
    test=test && (tablero[c][d].getpieza()!=nullptr || tablero[a][d].getpieza()!=nullptr && tablero[a][d].getpieza()->tipo()=='p' && ((Peon*) tablero[a][d].getpieza())->haavanzado==turno-1 ) ;
    return test;
}


int * Peon::posicionposible(int a, int b){
    int l;
    l=0;
    int* listPos = new int[64];
    if(jugador-2) {//peon blanco
        if(puedoMover(a,b,a+1,b) ) {//mover de una  casilla
            listPos[l]=a+1;
            l++;
            listPos[l]=b;
            l++;
        }
        if(puedoMover(a,b,a+2,b) ) {//mover de dos casillas
            listPos[l]=a+2;
            l++;
            listPos[l]=b;
            l++;
        }
        if(puedoComer(a,b,a+1,b+1 )) {//comer la pieza a la derecha
            listPos[l]=a+1;
            l++;
            listPos[l]=b+1;
            l++;
        }
        if(puedoComer(a,b,a+1,b-1 )) {//comer la pieza a la izquierda
            listPos[l]=a+1;
            l++;
            listPos[l]=b-1;
            l++;
        }
    }else {//peon negro
        if(puedoMover(a,b,a+1,b) ) {//mover de una  casilla
            listPos[l]=a+1;
            l++;
            listPos[l]=b;
            l++;
        }
        if(puedoMover(a,b,a+2,b) ) {//mover de dos casillas
            listPos[l]=a+2;
            l++;
            listPos[l]=b;
            l++;
        }
        if(puedoComer(a,b,a+1,b+1 )) {//comer la pieza a la derecha
            listPos[l]=a+1;
            l++;
            listPos[l]=b+1;
            l++;
        }
        if(puedoComer(a,b,a+1,b-1 )) {//comer la pieza a la izquierda
            listPos[l]=a+1;
            l++;
            listPos[l]=b-1;
            l++;
        }
    }
    return listPos;
    
}



/*Pieza Peon::promocion(char c){
 
 Pieza* p;
 int col=(jugador==1)?7:0;
 int lin=0;
 while(lin<8 &&this->tablero[col][lin].getpieza()->tipo()!='p'){
 lin++;
 }
 if(lin<8){
 if(c=='c') {
 p=&(Caballo(jugador,tablero));
 }else if(c=='a') {
 p=&(Alfil(jugador,tablero));
 } else if(c=='t') {
 p=&(Torre(jugador,tablero));
 } else if (c=='q') {
 p=&(Reina(jugador,tablero));
 }
 this->tablero[col][lin].setpieza(p);
 }
 return *p;
 }
 
 int Peon::getavanzado(){
 return this->haavanzado;
 }*/




