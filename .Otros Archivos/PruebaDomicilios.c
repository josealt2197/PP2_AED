
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Domicilio Domicilio;
typedef struct Ruta Ruta;
typedef struct Lista Lista;

struct Domicilio{
	char codigo[20];
	char nombre_lugar[50];
    char codigo_postal[50];
	int visitado;
	int terminado;
	int monto;
	char anterior[50];
	Domicilio *siguiente;
	Ruta *adyacencia; 
};

struct Ruta{   
	Domicilio *lugar; 
	char tiempo_estimado[20];
    char distancia[20];
    char tipo_ruta[20];
	Ruta *siguiente;
	int peso;
};

struct Lista{
	Domicilio *nombre_lugar;
	Lista *siguiente;
};

Domicilio *inicio=NULL;
Lista *ini=NULL;
Lista *final=NULL; 

void registrarDomicilio();

void registrarRuta();
Domicilio* validarDomicilio(const char nombre[]);
void agregarRuta(Domicilio* origen, Domicilio* destino, Ruta* nuevaRuta);

void visualizarGrafo();
void recorridos();
void recorridoAnchura();
void recorridoProfundidad(Domicilio* aux);
void insertarPila(Domicilio* aux);
void insertarCola(Domicilio* aux);
Domicilio * desencolar();
void reiniciar();
void dijkstra();

int main(){   
    int opcion;

	system("cls");
    do{
    	printf("\n\n*********************************\n");
		printf("     Gestion de Domicilios\n");
		printf("*********************************\n");
        printf(" 1. Insertar Domicilio               \n");
        printf(" 2. Insertar Ruta                    \n");
        printf(" 3. Mostrar Domicilios y Rutas       \n");
        printf(" 4. Recorrer Grafo                   \n");
        printf(" 5. Dijkstra                         \n");
        printf(" 6. Salir                            \n");
        printf("*********************************\n");
        printf("<--Opcion: ");
        scanf("%i",&opcion);
        switch(opcion){
            case 1:
            	registrarDomicilio();
            	break;
    		case 2: 	
    			registrarRuta();
	        	break;
    		case 3: 	
    			visualizarGrafo();
    		   	break;
    		case 4: 	
    			recorridos();
    		    break;
    		case 5:
			 	dijkstra();
		    	break;
			case 6:
			 	break;
            default: printf("***Opcion no valida***\n");
                     break;
        }
        system("pause");
        system("cls");
    }while(opcion!=6);
    return 1;
}

void registrarDomicilio(){
    
	system( "CLS" );
    printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("     Registro de Domicilios\n" );
	printf("*********************************\n");	
	
	Domicilio* aux;
	Domicilio* nuevo=(Domicilio*)malloc(sizeof(Domicilio));
	fflush(stdin);

    do{
		printf("\n-->Ingrese el Nombre del Domicilio: \n");
	    gets(nuevo->nombre_lugar);

	    if(validarDomicilio(nuevo->nombre_lugar)!=NULL){
	    	printf("\n**Este Domicilio ya ha sido registrado**\n ");
		}else{
			break;
        }
        
    }while(1);

    printf("\n-->Ingrese el Código para el Domicilio: \n");
    gets(nuevo->codigo);
    
    printf("\n-->Ingrese el Codigo Postal: \n");
    gets(nuevo->codigo_postal);
	
	nuevo->siguiente=NULL;
    nuevo->adyacencia=NULL;
    nuevo->visitado=nuevo->terminado=0;
    nuevo->monto=-1;
    strcpy(nuevo->anterior, "0");
    
	if(inicio==NULL){
        inicio=nuevo;
    }else{
        aux=inicio;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
    }
    
    printf("\n+++ Informacion registrada correctamente +++\n" );
 
 }
 
Domicilio* validarDomicilio(const char nombre[]){
	
	Domicilio* iDomicilio=inicio;

    while(iDomicilio!=NULL){
        if(strcmp(iDomicilio->nombre_lugar,nombre)==0){
            break;
        }
        iDomicilio = iDomicilio->siguiente;
    }
    
    return iDomicilio;
} 
 
void registrarRuta(){   
        printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("       Registro de Rutas\n" );
	printf("*********************************\n");
	
    char lugar_origen[50], lugar_destino[50], tiempo_estimado[20], distancia[20], tipo_ruta[20], peso[10];
    
    Ruta* nuevaRuta=(Ruta*)malloc(sizeof(Ruta));
    
    nuevaRuta->siguiente=NULL;
    
    Domicilio *origen;
	Domicilio *destino;
	
    if(inicio==NULL){
         printf( "\n***No se han encontrado Domicilios registrados***");
         return;
    }
    
    fflush(stdin);
    
	//Agregar Origen
    do{
    	printf("\n-->Ingrese el Domicilio de ORIGEN:  \n");
	    gets(lugar_origen);
	    
	    origen = validarDomicilio(lugar_origen);

	    if(origen==NULL){
	    	printf( "\n***No se ha encontrado un Domicilio que coincida con el ORIGEN ingresado***");
		}else{
			break;
        }
        
    }while(1);
    
    //Agregar Destino
    do{
    	    
	    printf("\n-->Ingrese el Lugar de DESTINO \n");
	    gets(lugar_destino);
	    
	    destino = validarDomicilio(lugar_destino);

	    if(destino==NULL){
	    	printf( "\n***No se ha encontrado un Domicilio que coincida con el DESTINO ingresado***");	
		}else{
			break;
        }

        
    }while(1);
	
    printf("\n-->Ingrese el tipo de ruta (terrestre, aerea o maritima): \n");
    gets(nuevaRuta->tipo_ruta);  
    printf("\n-->Ingrese la Distancia entre ambos lugares (en km): \n");
    gets(nuevaRuta->distancia);  
    printf("\n-->Ingresar PESO de la Ruta: ");
    gets(peso);  
    
    nuevaRuta->peso = atoi(peso);
	
    agregarRuta(origen,destino,nuevaRuta);
    
    
}

void agregarRuta(Domicilio* origen, Domicilio* destino, Ruta* nuevaRuta){
    Ruta* iRuta;
    
    if(origen->adyacencia==NULL){   
	    origen->adyacencia=nuevaRuta;
        nuevaRuta->lugar=destino;
    }else{   
	    iRuta=origen->adyacencia;
	    
        while(iRuta->siguiente!=NULL)
            iRuta=iRuta->siguiente;
            
        nuevaRuta->lugar=destino;
        iRuta->siguiente=nuevaRuta;
    }
}

void visualizarGrafo(){
    Domicilio* iDomicilio=inicio;
    
    Ruta* iRuta;
    
    printf("Domicilios  -  Rutas\n");  
    while(iDomicilio!=NULL){   
	    printf("%s:    -",iDomicilio->nombre_lugar);
       
	    if(iDomicilio->adyacencia!=NULL){
            iRuta=iDomicilio->adyacencia;
            
			while(iRuta!=NULL){ 
			    printf(" %s",iRuta->lugar->nombre_lugar);
                iRuta=iRuta->siguiente;
            }
        }

        printf("\n");
        iDomicilio=iDomicilio->siguiente;
    }
    printf("\n");
}

void recorridos(){
	char domicilio [50];
	Domicilio * aux=inicio,*aux2=inicio;
	
	if(inicio!=NULL){
		fflush(stdin);
		printf("\n-->Ingrese el Domicilio de partida:  \n");
	    gets(domicilio);
			
		while(aux!=NULL){
			if(strcmp(aux->nombre_lugar, domicilio)==0){
				break;
			}
				
			aux=aux->siguiente;
		}
		
		if(aux==NULL){
			printf("Error: Domicilio no encontrado\n");
		}else{
			
			printf("Recorrido por anchura: ");
			aux->visitado=1;
			insertarCola(aux);
			recorridoAnchura();
			
			reiniciar();
			
			printf("\nRecorrido por profundidad: ");
			recorridoProfundidad(aux);
			
			while(aux2!=NULL){
				if(aux2->terminado==0)
					recorridoProfundidad(aux2);
					aux2=aux2->siguiente;
				}
			while(ini!=NULL)
				printf("%c ",desencolar()->nombre_lugar);
				
			reiniciar();
			printf("\n");
		}
	}
}

void recorridoAnchura(){
	Domicilio*aux=desencolar();
	
	if(aux==NULL)
		return;
		
	printf("%c ",aux->nombre_lugar);
	if(aux->adyacencia!=NULL){
		
		Ruta*a=aux->adyacencia;
		
		while(a!=NULL){
			if(a->lugar->visitado==0){
			    insertarCola(a->lugar);
				a->lugar->visitado=1;	
			}
			a=a->siguiente;
		}
	}
	
	recorridoAnchura();
	
}

void recorridoProfundidad(Domicilio* aux){
	Ruta*a;
	
	aux->visitado=1;
	
    if(aux->adyacencia!=NULL){
        a=aux->adyacencia;
        
        while(a!=NULL){ 
			if(a->lugar->visitado==0){
				recorridoProfundidad(a->lugar);
			}
            a=a->siguiente;
        }
    }
    aux->terminado=1;
    insertarPila(aux);
}

void insertarPila(Domicilio* aux){
	Lista*nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->nombre_lugar=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
	}else{
	   nuevo->siguiente=ini;
	   ini=nuevo;    	
	}
}

void insertarCola(Domicilio*aux){
	Lista*nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->nombre_lugar=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
	}else{
		final->siguiente=nuevo;
		final=nuevo;
	}
}

Domicilio*desencolar(){
	Lista*aux;
	
	if(ini==NULL){
		return NULL;
	}else{
		aux=ini;
		ini=ini->siguiente;
		aux->siguiente=NULL;
		if(ini==NULL)
		final=NULL;
	}
	
	Domicilio *resultado=aux->nombre_lugar;
	free(aux);
	return resultado;
}

void reiniciar(){
	if(inicio!=NULL){
		Domicilio*aux=inicio;
		while(aux!=NULL){
			aux->visitado=aux->terminado=0;
		    aux=aux->siguiente;
		}
	}
}
//Lorem Ipsum 
void dijkstra(){
	
	Domicilio*aux=inicio;
	char a[50],b[50];
	
	fflush(stdin);

	printf("\n-->Ingrese el Domicilio de ORIGEN:  \n");
    gets(a);
    
   	printf("\n-->Ingrese el Lugar de DESTINO \n");
	gets(b);

	while(aux!=NULL){
		
		if(strcmp(aux->nombre_lugar, a)==0){
			aux->terminado=1;
			aux->monto=0;
			break;
		}
		aux=aux->siguiente;
	}
	if(aux==NULL){
		printf("Domicilio no encontrado\n");
		return;
	}
	while(aux!=NULL){
		Ruta*a=aux->adyacencia;
	    while(a!=NULL){
		    if(a->lugar->monto==-1 || (aux->monto+a->peso)<a->lugar->monto){
		    	a->lugar->monto=aux->monto+a->peso;
		    	strcpy(a->lugar->anterior, aux->nombre_lugar);
			}
		    a=a->siguiente;
	    }
	    aux=inicio;
	    Domicilio*min=inicio;
	    while(min->anterior==0 || min->terminado ==1)
	    min=min->siguiente;
	    while(aux!=NULL){
	    	if(aux->monto<min->monto && aux->terminado==0 && aux->anterior!=0)
	    	min=aux;
	    	aux=aux->siguiente;
		}
		aux=min;
		aux->terminado=1;
		if(aux->nombre_lugar==b)
		break;
	}
	while(aux->anterior!=0){
		insertarPila(aux);
		
		char temp[50];
		strcpy(temp, aux->anterior);

		aux=inicio;
		while(aux->nombre_lugar!=temp){
		   aux=aux->siguiente;	
		}
	}
	insertarPila(aux);
	while(ini!=NULL){
		printf("%c ",desencolar()->nombre_lugar);
	}
		printf("\n");
	reiniciar();
}
