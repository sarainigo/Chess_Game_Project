#include<iostream>
#include <stdio.h>
#include <string.h>
#include "pieza.hpp"
#include "casilla.hpp"

using namespace std;

void playGame();
bool FormatoValido(char*);
void Display(Casilla** tablero);
bool MovimientoValido(char* movimiento, Casilla** tablero, int jugador);

int main(){
    
    
    
    playGame();
    
    
    
}

void playGame(){
    
    
    //Declaracion del tablero como una matriz de 8x8 casillas.
    
    int i;
    Casilla* tablero[8];
    for(i=0;i<8;i++) {
        tablero[i] = new Casilla[8];
    }
    
    
    //LETRA: Tipo de pieza UNIDADES: 1-blanco 2-negro DECENAS: Elemento
    
    //Definicion piezas blancas
    
    Rey k10(1,tablero);
    Reina q10(1,tablero);
    Torre t10(1,tablero);
    Torre t11(1,tablero);
    Alfil a10(1,tablero);
    Alfil a11(1,tablero);
    Caballo c10(1,tablero);
    Caballo c11(1,tablero);
    Peon p10(1,tablero);
    Peon p11(1,tablero);
    Peon p12(1,tablero);
    Peon p13(1,tablero);
    Peon p14(1,tablero);
    Peon p15(1,tablero);
    Peon p16(1,tablero);
    Peon p17(1,tablero);
    
    //Definicion piezas negras
    
    Rey k20(2,tablero);
    Reina q20(2,tablero);
    Torre t20(2,tablero);
    Torre t21(2,tablero);
    Alfil a20(2,tablero);
    Alfil a21(2,tablero);
    Caballo c20(2,tablero);
    Caballo c21(2,tablero);
    Peon p20(2,tablero);
    Peon p21(2,tablero);
    Peon p22(2,tablero);
    Peon p23(2,tablero);
    Peon p24(2,tablero);
    Peon p25(2,tablero);
    Peon p26(2,tablero);
    Peon p27(2,tablero);
    
    //Colocación inicial de piezas en el tablero
    
    //Jugador 1 (blancas)
    
    tablero[0][0].setpieza(&t10);
    tablero[0][1].setpieza(&c10);
    tablero[0][2].setpieza(&a10);
    tablero[0][3].setpieza(&q10);
    tablero[0][4].setpieza(&k10);
    tablero[0][5].setpieza(&a11);
    tablero[0][6].setpieza(&c11);
    tablero[0][7].setpieza(&t11);
    
    tablero[1][0].setpieza(&p10);
    tablero[1][1].setpieza(&p11);
    tablero[1][2].setpieza(&p12);
    tablero[1][3].setpieza(&p12);
    tablero[1][4].setpieza(&p13);
    tablero[1][5].setpieza(&p14);
    tablero[1][6].setpieza(&p15);
    tablero[1][7].setpieza(&p16);
    
    //Jugador 2 (negras)
    
    tablero[7][0].setpieza(&t20);
    tablero[7][1].setpieza(&c20);
    tablero[7][2].setpieza(&a20);
    tablero[7][3].setpieza(&q20);
    tablero[7][4].setpieza(&k20);
    tablero[7][5].setpieza(&a21);
    tablero[7][6].setpieza(&c21);
    tablero[7][7].setpieza(&t21);
    
    tablero[6][0].setpieza(&p20);
    tablero[6][1].setpieza(&p21);
    tablero[6][2].setpieza(&p22);
    tablero[6][3].setpieza(&p22);
    tablero[6][4].setpieza(&p23);
    tablero[6][5].setpieza(&p24);
    tablero[6][6].setpieza(&p25);
    tablero[6][7].setpieza(&p26);
    
    //*************************************************//
    //*************************************************//
    //*************************************************//
    
    int jugador = 2;	//Inicializamos a 2 para que con el cambio empiece el 1.
    
    
    char movimiento[8];//movimiento recibido por teclado
    bool gameover=0;
    
    /**********///BUCLE DEL JUEGO///**********/
    
    while(!gameover){
        
        //CUANDO gameover=0, saldremos del buble y se acabará el juego
        
        //Despues de cada movimiento cambiamos el jugador
        
        if(jugador == 1)
            jugador = 2;
        else
            jugador = 1;

        
        
        system("cls"); //comprobar
        
        
        
        Display(tablero); //impresion por pantalla del tabero
        
        
        cout<<"JUGADOR"<<jugador<<" Realize un movimiento por favor: ";
        cin>>movimiento;
        
        //Comprueba si el formato del movimiento es correcto. Si es correcto FormatoValido devuelve 1 y el programa sigue, si no es correcto devuelve 0 y te lo vuelve a pedir.
        
        while(FormatoValido(movimiento) == 0){
            
            cout<<"Formato no válido. Vuelva a introducir su movimiento:"<<endl;
            cin>>movimiento;
            
        }
        
        //Comprueba que el movimiento se puede hacer por las reglas del ajedrez. Si se puede hacer, MovimientoValido lo hace y se vuelve a meter en el bucle para que juegue el otro jugador, si no, te vuelve a pedir que introduzcas el movimiento.
        
        while(MovimientoValido(movimiento, tablero, jugador) == 0){
            
            cout<<"Movimiento no válido o varias posibles alternativas. Vuelva a introducir su movimiento o especifique fila/columna de partida:"<<endl;
            cin>>movimiento;
            
        //poner condicion de posible movimiento de varias figuras iguales
            
        //poner contador
            
            
        }
    }//cierro while
}//cierro playgame

//*************************************************//
//*************************************************//
//*************************************************//

//declaración de funciones


//Esta función comprueba que el movimiento que mete el jugador tiene un formato correcto y está dentro del tablero

bool FormatoValido(char* movimiento){

    
    int nelem= (int)strlen(movimiento);
    int contx=0;
    
    for(int i=0; i<nelem;i++){
        if(movimiento[i]=='x') contx++;
    }
    
    
    //barremos todas las posibles entradas por teclado válidas, segun el número de elementos, con un case
    
    if(contx==0){
        
        switch(nelem){
                
            case 2:{
                
                if((movimiento[0]!='a')||(movimiento[0]!='b')||(movimiento[0]!='c')||(movimiento[0]!='d')||(movimiento[0]!='e')||   (movimiento[0]!='f')||(movimiento[0]!='g')||(movimiento[0]!='h')) return 0;
                
                if((movimiento[1]!='1')||(movimiento[1]!='2')||(movimiento[1]!='3')||(movimiento[1]!='4')||(movimiento[1]!='5')||(movimiento[1]!='6')||(movimiento[1]!='7')||(movimiento[1]!='8')) return 0;
                return 1;
            }
            case 3:{
            
                if((movimiento[0]!='R')||(movimiento[0]!='D')||(movimiento[0]!='T')||(movimiento[0]!='A')||(movimiento[0]!='C')) return 0;
                
                if((movimiento[1]!='a')||(movimiento[1]!='b')||(movimiento[1]!='c')||(movimiento[1]!='d')||(movimiento[1]!='e')||   (movimiento[1]!='f')||(movimiento[1]!='g')||(movimiento[1]!='h')) return 0;

                if((movimiento[2]!='1')||(movimiento[2]!='2')||(movimiento[2]!='3')||(movimiento[2]!='4')||(movimiento[2]!='5')||(movimiento[2]!='6')||(movimiento[2]!='7')||(movimiento[2]!='8')) return 0;
                return 1;
            }
            case 4:{
                
                if((movimiento[0]!='R')||(movimiento[0]!='D')||(movimiento[0]!='T')||(movimiento[0]!='A')||(movimiento[0]!='C')) return 0;
                
                if((movimiento[1]!='a')||(movimiento[1]!='b')||(movimiento[1]!='c')||(movimiento[1]!='d')||(movimiento[1]!='e')||   (movimiento[1]!='f')||(movimiento[1]!='g')||(movimiento[1]!='h')||(movimiento[1]!='1')||(movimiento[1]!='2')||(movimiento[1]!='3')||(movimiento[1]!='4')||(movimiento[1]!='5')||(movimiento[1]!='6')||(movimiento[1]!='7')||(movimiento[1]!='8')) return 0;
                
                 if((movimiento[2]!='a')||(movimiento[2]!='b')||(movimiento[2]!='c')||(movimiento[2]!='d')||(movimiento[2]!='e')||   (movimiento[2]!='f')||(movimiento[2]!='g')||(movimiento[2]!='h')) return 0;
                
                if((movimiento[3]!='1')||(movimiento[3]!='2')||(movimiento[3]!='3')||(movimiento[3]!='4')||(movimiento[3]!='5')||(movimiento[3]!='6')||(movimiento[3]!='7')||(movimiento[3]!='8')) return 0;
                return 1;
            }
                
            default: return 0;
        }//cierro switch
    }//cierro if
    
    else {if(contx==1){
            switch(nelem){
                
            case 4:{
                
                if((movimiento[0]!='R')||(movimiento[0]!='D')||(movimiento[0]!='T')||(movimiento[0]!='A')||(movimiento[0]!='C')||(movimiento[0]!='a')||(movimiento[0]!='b')||(movimiento[0]!='c')||(movimiento[0]!='d')||(movimiento[0]!='e')||   (movimiento[0]!='f')||(movimiento[0]!='g')||(movimiento[0]!='h')) return 0;
                
                if(movimiento[1]!='x') return 0;
                
                if((movimiento[2]!='a')||(movimiento[2]!='b')||(movimiento[2]!='c')||(movimiento[2]!='d')||(movimiento[2]!='e')||   (movimiento[2]!='f')||(movimiento[2]!='g')||(movimiento[2]!='h')) return 0;
                
                if((movimiento[3]!='1')||(movimiento[3]!='2')||(movimiento[3]!='3')||(movimiento[3]!='4')||(movimiento[3]!='5')||(movimiento[3]!='6')||(movimiento[3]!='7')||(movimiento[3]!='8')) return 0;
                return 1;
            }
            case 5:{
                
                if((movimiento[0]!='R')||(movimiento[0]!='D')||(movimiento[0]!='T')||(movimiento[0]!='A')||(movimiento[0]!='C')) return 0;
                
                if((movimiento[1]!='a')||(movimiento[1]!='b')||(movimiento[1]!='c')||(movimiento[1]!='d')||(movimiento[1]!='e')||   (movimiento[1]!='f')||(movimiento[1]!='g')||(movimiento[1]!='h')||(movimiento[1]!='1')||(movimiento[1]!='2')||(movimiento[1]!='3')||(movimiento[1]!='4')||(movimiento[1]!='5')||(movimiento[1]!='6')||(movimiento[1]!='7')||(movimiento[1]!='8')) return 0;
                
                 if(movimiento[2]!='x') return 0;
                
                if((movimiento[3]!='a')||(movimiento[3]!='b')||(movimiento[3]!='c')||(movimiento[3]!='d')||(movimiento[3]!='e')||   (movimiento[3]!='f')||(movimiento[3]!='g')||(movimiento[3]!='h')) return 0;
                
               if((movimiento[4]!='1')||(movimiento[4]!='2')||(movimiento[4]!='3')||(movimiento[4]!='4')||(movimiento[4]!='5')||(movimiento[4]!='6')||(movimiento[4]!='7')||(movimiento[4]!='8')) return 0;
                return 1;
            }
                
            default: return 0;
            }//cierro switch
        }//cierro if
        
        else {return 0;}
    }//cierro else
    
}//cierro función

//Esta función comprueba que el movimiento que mete el jugador se puede realizar (no hay una pieza ocupando el lugar donde se quiere ir y cumple leyes) y si se pude hacer, lo hace.
    
bool MovimientoValido(char* movimiento, Casilla** tablero, int jugador){
    
    
    int nelem=(int)strlen(movimiento);
    int f,c,ff,cf;
    
    //asignación de coordenadas finales ff,cf en funcion del string movimiento pedido por teclado
    
    switch(movimiento[nelem-1]){
            
        case '1': ff=0;
        case '2': ff=1;
        case '3': ff=2;
        case '4': ff=3;
        case '5': ff=4;
        case '6': ff=5;
        case '7': ff=6;
        case '8': ff=7;
            
    }
    
    switch(movimiento[nelem-2]){
            
            
        case 'a': cf=0;
        case 'b': cf=1;
        case 'c': cf=2;
        case 'd': cf=3;
        case 'e': cf=4;
        case 'f': cf=5;
        case 'g': cf=6;
        case 'h': cf=7;
            
    }
    
    
    //asignación de coordenadas iniciales y realización de movimiento
    
    
    //mover
    
  if (movimiento[nelem-3]!='x'){
     
     switch(nelem){
             
             //switch en funcion del tipo de pieza que quiero mover, detectado por el numero de elementos de la cadena cogida por teclado.
             
             //hago 2 bucles para recorrer la tabla y encontrar la pieza que quiero, comprobando que sea del color correcto, sea el tipo de pieza especificada por teclado y que pueda realizar ese movimiento.
             //si en la pasada por el bucle encuentra la pieza correcta, retorna un 1 y realiza el movimiento. Si no encuentra la pieza, retorna un 0
             
         case 2:{ //va a ser un peon
             
             for(int i=0; i<8; i++){
                 for(int j=0;j<8;j++){
                     
                     if((tablero[i][j].getpieza()->tipo()=='p')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoMover(i,j,ff,cf)==1))
                         
                         return tablero[i][j].getpieza()->mover(i,j,ff,cf);
                 }
             }
             
             return 0;
     
         }
            
             
        case 3:{ //sabremos el tipo de pieza que es en función de la primera letra especificada
             
            
            switch(movimiento[0]){
                    
                    
                case 'R':{
                    
                    for(int i=0; i<8; i++){
                        for(int j=0;j<8;j++){
                            
                            if((tablero[i][j].getpieza()->tipo()=='k')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoMover(i,j,ff,cf)==1))
                                
                                return tablero[i][j].getpieza()->mover(i,j,ff,cf);
                        }
                    }
                    
                    return 0;
                    
                }
                    
                case 'D':{
                    
                    for(int i=0; i<8; i++){
                        for(int j=0; j<8;j++){
                            
                            if((tablero[i][j].getpieza()->tipo()=='q')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoMover(i,j,ff,cf)==1))
                                
                                return tablero[i][j].getpieza()->mover(i,j,ff,cf);
                        }
                    }
                    
                    return 0;

                    
                }
                    
                case 'T':{
                    
                    for(int i=0; i<8; i++){
                        for(int j=0; j<8;j++){
                            
                            if((tablero[i][j].getpieza()->tipo()=='t')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoMover(i,j,ff,cf)==1))
                                
                                return tablero[i][j].getpieza()->mover(i,j,ff,cf);
                        }
                    }
                    
                return 0;
                    

                    
                }
                    
                case 'A':{
        
                    
                    for(int i=0; i<8; i++){
                        for(int j=0; j<8;j++){
                            
                            if((tablero[i][j].getpieza()->tipo()=='a')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoMover(i,j,ff,cf)==1))
                                
                                return tablero[i][j].getpieza()->mover(i,j,ff,cf);
                        }
                    }
                    
                    return 0;
                    

                }
                    
                case 'C':{
                    
                    for(int i=0; i<8; i++){
                        for(int j=0; j<8;j++){
                            
                            if((tablero[i][j].getpieza()->tipo()=='c')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoMover(i,j,ff,cf)==1))
                                
                                return tablero[i][j].getpieza()->mover(i,j,ff,cf);
                        }
                    }
                    
                    return 0;
                    
                }
            }//cierro switch
        }//cierro case 3
     
             
         case 4:{ //caso en el que se especifica la fila o columna
                    //sabremos el tipo de pieza que es en función de la primera letra especificada
             
             //el segundo elemento de la cadena nos dará la fila o columna
             
             switch(movimiento[1]){
                     
                 case '1': f=0;
                 case '2': f=1;
                 case '3': f=2;
                 case '4': f=3;
                 case '5': f=4;
                 case '6': f=5;
                 case '7': f=6;
                 case '8': f=7;
                 case 'a': c=0;
                 case 'b': c=1;
                 case 'c': c=2;
                 case 'd': c=3;
                 case 'e': c=4;
                 case 'f': c=5;
                 case 'g': c=6;
                 case 'h': c=7;
                     
             }
             
          // Separo en un if si el segundo elemento es una fila o una columna.
             
             
             //nos especifican fila
             
        if(movimiento[1]=='1'||movimiento[1]=='2'||movimiento[1]=='3'||movimiento[1]=='4'||movimiento[1]=='5'||movimiento[1]=='6'||movimiento[1]=='7'||movimiento[1]=='8'){
             
         switch(movimiento[0]){
         case 'R':{
             
             
             for(int j=0; j<8;j++){
                     
                     if((tablero[f][j].getpieza()->tipo()=='k')&&(tablero[f][j].getpieza()->getjugador()==jugador)&&(tablero[f][j].getpieza()->puedoMover(f,j,ff,cf)==1))
                         
                         return tablero[f][j].getpieza()->mover(f,j,ff,cf);
                 }
             
             
             return 0;
             
         }
             
         case 'D':{
             
             
             for(int j=0; j<8;j++){
                 
                 if((tablero[f][j].getpieza()->tipo()=='d')&&(tablero[f][j].getpieza()->getjugador()==jugador)&&(tablero[f][j].getpieza()->puedoMover(f,j,ff,cf)==1))
                     
                     return tablero[f][j].getpieza()->mover(f,j,ff,cf);
             }
             
             
             return 0;
             
             
         }
             
         case 'T':{
             
             for(int j=0; j<8;j++){
                 
                 if((tablero[f][j].getpieza()->tipo()=='t')&&(tablero[f][j].getpieza()->getjugador()==jugador)&&(tablero[f][j].getpieza()->puedoMover(f,j,ff,cf)==1))
                     
                     return tablero[f][j].getpieza()->mover(f,j,ff,cf);
             }
             
             
             return 0;
             
             
             
         }
             
         case 'A':{
             
             for(int j=0; j<8;j++){
                 
                 if((tablero[f][j].getpieza()->tipo()=='a')&&(tablero[f][j].getpieza()->getjugador()==jugador)&&(tablero[f][j].getpieza()->puedoMover(f,j,ff,cf)==1))
                     
                     return tablero[f][j].getpieza()->mover(f,j,ff,cf);
             }
             
             
             return 0;
             
             
             
         }
             
         case 'C':{
             
             
             for(int j=0; j<8;j++){
                 
                 if((tablero[f][j].getpieza()->tipo()=='c')&&(tablero[f][j].getpieza()->getjugador()==jugador)&&(tablero[f][j].getpieza()->puedoMover(f,j,ff,cf)==1))
                     
                     return tablero[f][j].getpieza()->mover(f,j,ff,cf);
             }
             
             
             return 0;
         }
             
         } //cierro switch

        } //cierro if
            
            
                //nos especifican columna
            
            else {
                
                switch(movimiento[0]){
                    case 'R':{
                        
                        
                        for(int i=0; i<8;i++){
                            
                            if((tablero[i][c].getpieza()->tipo()=='k')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoMover(i,c,ff,cf)==1))
                                
                                return tablero[i][c].getpieza()->mover(i,c,ff,cf);
                        }
                        
                        
                        return 0;
                        
                    }
                        
                    case 'D':{
                        
                        for(int i=0; i<8;i++){
                            
                            if((tablero[i][c].getpieza()->tipo()=='q')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoMover(i,c,ff,cf)==1))
                                
                                return tablero[i][c].getpieza()->mover(i,c,ff,cf);
                        }
                        
                        
                        return 0;
                        
                    }
                        
                    case 'T':{
                        
                        
                        for(int i=0; i<8;i++){
                            
                            if((tablero[i][c].getpieza()->tipo()=='t')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoMover(i,c,ff,cf)==1))
                                
                                return tablero[i][c].getpieza()->mover(i,c,ff,cf);
                        }
                        
                        
                        return 0;
                    }
                        
                    case 'A':{
                        
                        for(int i=0; i<8;i++){
                            
                            if((tablero[i][c].getpieza()->tipo()=='a')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoMover(i,c,ff,cf)==1))
                                
                                return tablero[i][c].getpieza()->mover(i,c,ff,cf);
                        }
                        
                        
                        return 0;
                    }
                        
                    case 'C':{
                        
                        for(int i=0; i<8;i++){
                            
                            if((tablero[i][c].getpieza()->tipo()=='c')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoMover(i,c,ff,cf)==1))
                                
                                return tablero[i][c].getpieza()->mover(i,c,ff,cf);
                        }
                        
                        
                        return 0;
                    }
                        
                }//cierro switch
                
            }//cierro else
   
    } //cierro case 4
             
}//cierro switch
 
}//cierro if mover
    
    //comer

  else{
    
    switch(nelem){
     
     case 4:{
                 
                 switch(movimiento[0]){
                         
                         
                     case 'R':{
                         
                         for(int i=0; i<8; i++){
                             for(int j=0;j<8;j++){
                                 
                                 if((tablero[i][j].getpieza()->tipo()=='k')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoComer(i,j,ff,cf)==1))
                                     
                                     return tablero[i][j].getpieza()->comer(i,j,ff,cf);
                             }
                         }
                         
                         return 0;
                         
                     }
                         
                     case 'D':{
                         
                         for(int i=0; i<8; i++){
                             for(int j=0; j<8;j++){
                                 
                                 if((tablero[i][j].getpieza()->tipo()=='q')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoComer(i,j,ff,cf)==1))
                                     
                                     return tablero[i][j].getpieza()->comer(i,j,ff,cf);
                             }
                         }
                         
                         return 0;
                         
                         
                     }
                         
                     case 'T':{
                         
                         for(int i=0; i<8; i++){
                             for(int j=0; j<8;j++){
                                 
                                 if((tablero[i][j].getpieza()->tipo()=='t')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoComer(i,j,ff,cf)==1))
                                     
                                     return tablero[i][j].getpieza()->comer(i,j,ff,cf);
                             }
                         }
                         
                         return 0;
                         
                         
                         
                     }
                         
                     case 'A':{
                         
                         
                         for(int i=0; i<8; i++){
                             for(int j=0; j<8;j++){
                                 
                                 if((tablero[i][j].getpieza()->tipo()=='a')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoComer(i,j,ff,cf)==1))
                                     
                                     return tablero[i][j].getpieza()->comer(i,j,ff,cf);
                             }
                         }
                         
                         return 0;
                         
                         
                     }
                         
                     case 'C':{
                         
                         for(int i=0; i<8; i++){
                             for(int j=0; j<8;j++){
                                 
                                 if((tablero[i][j].getpieza()->tipo()=='c')&&(tablero[i][j].getpieza()->getjugador()==jugador)&&(tablero[i][j].getpieza()->puedoComer(i,j,ff,cf)==1))
                                     
                                     return tablero[i][j].getpieza()->comer(i,j,ff,cf);
                             }
                         }
                         
                         return 0;
                         
                        }
                         
                        //peon
                     default:{
                         
                         switch(movimiento[1]){
                             
                         case 'a': c=0;
                         case 'b': c=1;
                         case 'c': c=2;
                         case 'd': c=3;
                         case 'e': c=4;
                         case 'f': c=5;
                         case 'g': c=6;
                         case 'h': c=7;
                         }
                        
                         
                         for(int i=0; i<8;i++){
                             
                             if((tablero[i][c].getpieza()->tipo()=='c')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoComer(i,c,ff,cf)==1))
                                 
                                 return tablero[i][c].getpieza()->comer(i,c,ff,cf);
                         }
                         
                         
                         return 0;
                         
                     
                     }//cierro default
                }//cierro switch
     
          }//cierro case 4
     
     case 5:{
         //caso en el que se especifica la fila o columna
         //sabremos el tipo de pieza que es en función de la primera letra especificada
         
         //el segundo elemento de la cadena nos dará la fila o columna
         
         switch(movimiento[1]){
                 
             case '1': f=0;
             case '2': f=1;
             case '3': f=2;
             case '4': f=3;
             case '5': f=4;
             case '6': f=5;
             case '7': f=6;
             case '8': f=7;
             case 'a': c=0;
             case 'b': c=1;
             case 'c': c=2;
             case 'd': c=3;
             case 'e': c=4;
             case 'f': c=5;
             case 'g': c=6;
             case 'h': c=7;
                 
         }
         
         // Separo en un if si el segundo elemento es una fila o una columna.
         
         
         //nos especifican fila
         
         if(movimiento[1]=='1'||movimiento[1]=='2'||movimiento[1]=='3'||movimiento[1]=='4'||movimiento[1]=='5'||movimiento[1]=='6'||movimiento[1]=='7'||movimiento[1]=='8'){
             
             switch(movimiento[0]){
                 case 'R':{
                     
                     for(int j=0; j<8;j++){
                         
                         if((tablero[f][j].getpieza()->tipo()=='k')&&(tablero[f][j].getpieza()->getjugador()==jugador)&&(tablero[f][j].getpieza()->puedoComer(f,j,ff,cf)==1))
                             
                             return tablero[f][j].getpieza()->comer(f,j,ff,cf);
                     }
                     
                     
                     return 0;
                     
                 }
                     
                 case 'D':{
                     
                     
                     for(int j=0; j<8;j++){
                         
                         if((tablero[f][j].getpieza()->tipo()=='d')&&(tablero[f][j].getpieza()->getjugador()==jugador)&&(tablero[f][j].getpieza()->puedoComer(f,j,ff,cf)==1))
                             
                             return tablero[f][j].getpieza()->comer(f,j,ff,cf);
                     }
                     
                     
                     return 0;
                     
                     
                 }
                     
                 case 'T':{
                     
                     for(int j=0; j<8;j++){
                         
                         if((tablero[f][j].getpieza()->tipo()=='t')&&(tablero[f][j].getpieza()->getjugador()==jugador)&&(tablero[f][j].getpieza()->puedoComer(f,j,ff,cf)==1))
                             
                             return tablero[f][j].getpieza()->comer(f,j,ff,cf);
                     }
                     
                     
                     return 0;
                     
                     
                     
                 }
                     
                 case 'A':{
                     
                     for(int j=0; j<8;j++){
                         
                         if((tablero[f][j].getpieza()->tipo()=='a')&&(tablero[f][j].getpieza()->getjugador()==jugador)&&(tablero[f][j].getpieza()->puedoComer(f,j,ff,cf)==1))
                             
                             return tablero[f][j].getpieza()->comer(f,j,ff,cf);
                     }
                     
                     
                     return 0;
                     
                     
                     
                 }
                     
                 case 'C':{
                     
                     
                     for(int j=0; j<8;j++){
                         
                         if((tablero[f][j].getpieza()->tipo()=='c')&&(tablero[f][j].getpieza()->getjugador()==jugador)&&(tablero[f][j].getpieza()->puedoComer(f,j,ff,cf)==1))
                             
                             return tablero[f][j].getpieza()->comer(f,j,ff,cf);
                     }
                     
                     
                     return 0;
                 }
                     
             } //cierro switch
             
         } //cierro if
         
         
         //nos especifican columna
         
         else {
             
             switch(movimiento[0]){
                 case 'R':{
                     
                     
                     for(int i=0; i<8;i++){
                         
                         if((tablero[i][c].getpieza()->tipo()=='k')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoComer(i,c,ff,cf)==1))
                             
                             return tablero[i][c].getpieza()->comer(i,c,ff,cf);
                     }
                     
                     
                     return 0;
                     
                 }
                     
                 case 'D':{
                     
                     for(int i=0; i<8;i++){
                         
                         if((tablero[i][c].getpieza()->tipo()=='q')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoComer(i,c,ff,cf)==1))
                             
                             return tablero[i][c].getpieza()->comer(i,c,ff,cf);
                     }
                     
                     
                     return 0;
                     
                 }
                     
                 case 'T':{
                     
                     
                     for(int i=0; i<8;i++){
                         
                         if((tablero[i][c].getpieza()->tipo()=='t')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoComer(i,c,ff,cf)==1))
                             
                             return tablero[i][c].getpieza()->comer(i,c,ff,cf);
                     }
                     
                     
                     return 0;
                 }
                     
                 case 'A':{
                     
                     for(int i=0; i<8;i++){
                         
                         if((tablero[i][c].getpieza()->tipo()=='a')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoComer(i,c,ff,cf)==1))
                             
                             return tablero[i][c].getpieza()->comer(i,c,ff,cf);
                     }
                     
                     
                     return 0;
                 }
                     
                 case 'C':{
                     
                     for(int i=0; i<8;i++){
                         
                         if((tablero[i][c].getpieza()->tipo()=='c')&&(tablero[i][c].getpieza()->getjugador()==jugador)&&(tablero[i][c].getpieza()->puedoComer(i,c,ff,cf)==1))
                             
                             return tablero[i][c].getpieza()->comer(i,c,ff,cf);
                     }
                     
                     
                     return 0;
                 }
                     
             }//cierro switch
             
         }//cierro else de columna
         
     
         }//cierro case 5
     
    }//cierro switch
    
     
  }//cierro else
    
return 0;

}//cierro funcion


void Display(Casilla** tablero){
    
    //inicialización de tablero display
    
    char tablerodisplay[38][53] = {
        
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', '7', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'Q', ' ', ' ', '#', ' ', ' ', 'K', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', '6', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', '5', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', '4', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', '3', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', '2', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', '1', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', '0', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'Q', ' ', ' ', '#', ' ', ' ', 'K', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        
    };
    
    
    //"displayfila" Asocia las coordenadas del tablero real con las coordenadas del tablero display que se imprime por pantalla
    
    //La fila 0 del tablero real es equivalente a la fila 31 del tablero display
    
    int df0 = 31;
    int df1 = 27;
    int df2 = 23;
    int df3 = 19;
    int df4 = 15;
    int df5 = 11;
    int df6 = 7;
    int df7 = 3;
    
    //"displaycolumna"
    
    int dc0 = 7;
    int dc1 = 13;
    int dc2 = 19;
    int dc3 = 25;
    int dc4 = 31;
    int dc5 = 37;
    int dc6 = 43;
    int dc7 = 49;
    
    
    //Actualiza la posición de las piezas del tablero real en el tablero display
    
    
    int filatemp = 0;
    int columnatemp = 0;
    
    for(int i = 0; i < 8; i++){
        
        if(i == 0)
            filatemp = df0;
        else if(i == 1)
            filatemp = df1;
        else if(i == 2)
            filatemp = df2;
        else if(i == 3)
            filatemp = df3;
        else if(i == 4)
            filatemp = df4;
        else if(i == 5)
            filatemp = df5;
        else if(i == 6)
            filatemp = df6;
        else
            filatemp = df7;
        
        
            for(int j = 0; j < 8; j++){
            
                if(j == 0)
                    columnatemp = dc0;
                else if(j == 1)
                    columnatemp = dc1;
                else if(j == 2)
                    columnatemp = dc2;
                else if(j == 3)
                    columnatemp = dc3;
                else if(j == 4)
                    columnatemp = dc4;
                else if(j == 5)
                    columnatemp = dc5;
                else if(j == 6)
                    columnatemp = dc6;
                else
                    columnatemp = dc7;
                
                
                //(i, j) coordenadas del tablero real y (filatemp,columnatemp) coordenadas equivalentes del tablero display
            
                if(tablero[i][j].getpieza() == nullptr)
                    tablerodisplay[filatemp][columnatemp] = ' ';
                
                else if(tablero[i][j].getpieza()->tipo() == 'p'){
                    
                    if (tablero[i][j].getpieza()->getjugador() == 1)
                        tablerodisplay[filatemp][columnatemp] = 'P';
                        else tablerodisplay[filatemp][columnatemp] = 'p';
                }
            
                else if(tablero[i][j].getpieza()->tipo() == 't'){
                    
                    if (tablero[i][j].getpieza()->getjugador() == 1)
                        tablerodisplay[filatemp][columnatemp] = 'T';
                    else tablerodisplay[filatemp][columnatemp] = 't';
                    
                }
                
                else if(tablero[i][j].getpieza()->tipo() == 'c'){
                    
                    if (tablero[i][j].getpieza()->getjugador() == 1)
                        tablerodisplay[filatemp][columnatemp] = 'C';
                    else tablerodisplay[filatemp][columnatemp] = 'c';
                }
                

                
                else if(tablero[i][j].getpieza()->tipo() == 'a'){
                    
                    if (tablero[i][j].getpieza()->getjugador() == 1)
                        tablerodisplay[filatemp][columnatemp] = 'A';
                    else tablerodisplay[filatemp][columnatemp] = 'a';
                }
                

            
                else if(tablero[i][j].getpieza()->tipo() == 'q'){
                    
                    if (tablero[i][j].getpieza()->getjugador() == 1)
                        tablerodisplay[filatemp][columnatemp] = 'Q';
                    else tablerodisplay[filatemp][columnatemp] = 'q';
                }
                

            
                else{
                    
                    if (tablero[i][j].getpieza()->getjugador() == 1)
                        tablerodisplay[filatemp][columnatemp] = 'K';
                    else tablerodisplay[filatemp][columnatemp] = 'k';
                }
                
                
            }
    }

    
    
   //Impresión por pantalla del tablero display
    
    
    for(int i = 0; i < 34; i++){
        
        cout<<endl;
        
        for(int j = 0; j < 53; j++){
            
            cout<<tablerodisplay[i][j];
            
        }
    }
    
    cout<<endl<<endl;
    
}//cierro display
