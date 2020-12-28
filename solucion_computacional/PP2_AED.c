/*Algoritmos y Estructuras de Datos - Grupo 1
	Proyecto Programado 2 
	Estudiantes: Jose Altamirano Salazar - 2020426159
	             Josué Brenes Alfaro - 2020054427
*/
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tipos para la gestion de los datos de cada elemento
typedef struct Nino Nino;
typedef struct ListaNinos ListaNinos;

typedef struct Comportamiento Comportamiento;
typedef struct ListaComport ListaComport;

typedef struct AydanteSanta AydanteSanta;
typedef struct ListaAyudantes ListaAyudantes;

typedef struct Juguete Juguete;

typedef struct Carta Carta;
typedef struct ListaCarta ListaCarta;

typedef struct Deseo Deseo;
typedef struct ListaDeseo ListaDeseo;

//Procedimientos para Menus de Opciones
void MenuPrincipal();
void GestionNinos();
void GestionJuguetes();
void GestionDomicilios();
void GestionAyudantes();
void GestionCartas();
void AnalisisDeDatos();

//Procedimientos para gestion de Ninos/as
void registrarNinos(struct ListaNinos *LNinos);
void mostrarNinos(struct ListaNinos *LNinos);
void modificarNino(struct ListaNinos *LNinos);
void eliminarNino(struct ListaNinos *LNinos);
int validarCedula(struct ListaNinos *LNinos, const char identificacion []);
void registrarComportamiento(struct ListaNinos *LNinos, struct ListaComport *LComp);
void mostrarComp(struct ListaComport *LComp);
void validarComp(struct ListaComport *LComp, const char identificacion []);

//Procedimientos para gestion de de Ayudantes de santa
void registrarAyudante(struct ListaAyudantes *LAyudantes);
int validarIdentificacion(struct ListaAyudantes *LAyudantes, const char identificacion []);
void modificarAyudante(struct ListaAyudantes *LAyudantes);
void eliminarAyudante(struct ListaAyudantes *LAyudantes);

//Procedimientos para gestion de Juguetes
void registrarJuguetes();
void mostrarJuguetes(struct Juguete *recorrer);
void modificarJuguetes();
struct Juguete* buscarJuguete(struct Juguete *arbol, char jugueteBuscado[]);
struct Juguete *borrarJuguete(struct Juguete *aux, char porBorrar[]);
void eliminarJuguete();

//Procedimientos para gestion de Cartas para Santa
void registrarCartas(struct ListaNinos *LNinos, struct ListaCarta *LCarta, struct ListaDeseo *LDeseo);
int validarCarta(struct ListaCarta *LCarta, const char identificacion [], const char anno []);
int contarJuguetes(struct ListaCarta *LCarta, const char identificacion [], const char anno []);
void modificarCarta(struct ListaCarta *LCarta);
void consultarCarta(struct ListaCarta *LCarta);
void mostrarCarta(struct ListaCarta *LCarta, const char identificacion [], const char anno []);


struct Nino{
    char cedula[12];
	char nombre_completo[50];
    char nombre_usuario[20];
    char correo[50];
    char codigo_domicilio[20];
    char fecha_nacimiento[15];
    char edad[5];
    char necesidades_esp[150];
    Nino *siguiente;
    Nino *anterior;
    
};

struct ListaNinos {
	Nino *inicio;
	Nino *final;
};

struct Comportamiento{
	char nombre_padre_madre[50];
	char cedula_nino[12];
    char fecha_registro[20];
    char indicacion[15];
    char descripcion[150];
    Comportamiento *siguiente;
    Comportamiento *anterior;
    
};

struct ListaComport {
	Comportamiento *inicio;
	Comportamiento *final;
};

struct AydanteSanta{
    char identificacion[15];
    char nombre[50];
    char puesto[50];
    char funcionPuesto[50];
    char fechaComienzo[10];
    AydanteSanta *siguiente; 
	AydanteSanta *anterior; 
};

struct ListaAyudantes{
    AydanteSanta *inicio;
	AydanteSanta *final;  
};

struct Juguete{
    char codigo[12];
	char nombre[50];
    char descripcion[150];
    char categoria[50];
    char rango_edad[20];
    char costo_fabricacion[15];
    Juguete *izq;
    Juguete *der;
    
};

struct Carta{
    char identificacion[12];
	char anno[50];
    char nombre_juguete[20];
    char estado[50];
    Carta *siguiente;
    Carta *anterior;
    
};

struct ListaCarta {
	Carta *inicio;
	Carta *final;
};

struct Deseo{
    char identificacion[12];
	char anno[50];
    char nombre_juguete[20];
    Deseo *siguiente;
    Deseo *anterior;
    
};

struct ListaDeseo {
	Deseo *inicio;
	Deseo *final;
};



/****************************************************************Menús de Opciones***********************************************************************************************/

Juguete *jugueteRaiz=NULL;

/*
	Entradas: Un número (tipo char) en un rango de 0 a 7 para escoger una de las opciones disponibles en el menú. 
	Salidas: Llamada a las demas funciones de menús.
	Restricciones: Solo se deben ingresar números en un rango de 0 a 7.
*/
void MenuPrincipal(){
	char opcion;
	
	struct ListaNinos *LNinos;
	LNinos = (struct ListaNinos *) malloc(sizeof(struct ListaNinos));
	LNinos->inicio = NULL;
	LNinos->final = NULL;
	
	struct ListaComport *LComp;
	LComp = (struct ListaComport *) malloc(sizeof(struct ListaComport));
	LComp->inicio = NULL;
	LComp->final = NULL;
	
	struct ListaAyudantes *LAyudantes;
	LAyudantes = (struct ListaAyudantes *) malloc(sizeof(struct ListaAyudantes));
	LAyudantes->inicio = NULL;
	LAyudantes->final = NULL;
	
	struct ListaCarta *LCarta;
	LCarta = (struct ListaCarta *) malloc(sizeof(struct ListaCarta));
	LCarta->inicio = NULL;
	LCarta->final = NULL;
	
	struct ListaDeseo *LDeseo;
	LDeseo = (struct ListaDeseo *) malloc(sizeof(struct ListaDeseo));
	LDeseo->inicio = NULL;
	LDeseo->final = NULL;
	
	do{
        system( "CLS" );
        fflush(stdin);
        printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf("        Menu Principal\n" );
		printf("*********************************\n");
		printf( "\n 1 - Gestion de NINOS(AS)" );
		printf( "\n 2 - Gestion de JUGUETES" );
		printf( "\n 3 - Gestion de DOMICILIOS" );
	    printf( "\n 4 - Gestion de AYUDANTES DE SANTA" );	    
	    printf( "\n 5 - Gestion de CARTAS PARA SANTA" );
		printf( "\n 6 - Analisis de DATOS" );   
	    printf( "\n 7 - Salir" );
	    printf("\n\n<--Digite una opcion (1-7): ");
        opcion = getchar();
        
        switch ( opcion ){
            case '1': GestionNinos(LNinos, LComp);
                break;
			case '2': GestionJuguetes();
                break;
            case '3': GestionDomicilios();
                break;
			case '4': GestionAyudantes(LAyudantes);
                break;
            case '5': GestionCartas(LNinos, LCarta, LDeseo);
				break;
			case '6': AnalisisDeDatos();
				break;
			case '7': exit(1);
				break;
            default:
            	fflush(stdin);
				printf("**Opcion no valida. Intente de nuevo.**\n");
				getchar();
                break;
        }
    } while (opcion!='7');    
    fflush(stdin);
	getchar();	
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void GestionNinos(struct ListaNinos *LNinos, struct ListaComport *LComp){
	char opcion, ch;	

	do{
		system( "CLS" );
		fflush(stdin);
		printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf("       Gestion de Ninos\n");
		printf("*********************************\n");
		printf("\n 0. REGRESAR al Menu Principal.");
		printf("\n 1. REGISTRAR informacion de un nino o nina.");
		printf("\n 2. REGISTRAR comportamiento de un nino o nina.");
		printf("\n 3. MODIFICAR informacion de un nino o nina.");
		printf("\n 4. ELIMINAR informacion de un nino o nina.");
		printf("\n\n<--Digite una opcion (0-4): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': registrarNinos(LNinos);
					break;
				case '2': registrarComportamiento(LNinos, LComp);
					break;
				case '3': modificarNino(LNinos);
					break;
				case '4': eliminarNino(LNinos);
					break;
				case '0': 
					break;
				default:
					fflush(stdin);
					printf("**Opcion no valida. Intente de nuevo.**\n");
					getchar();
					break;	
		}	
	}while(opcion!='0');			
	fflush(stdin);
}


/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void GestionJuguetes(){
	char opcion, ch;	

	do{
		system( "CLS" );
		fflush(stdin);
		printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf("       Gestion de Juguetes\n");
		printf("*********************************\n");
		printf("\n 0. REGRESAR al Menu Principal.");
		printf("\n 1. REGISTRAR informacion de un Juguete.");
		printf("\n 2. ELIMINAR informacion de un Juguete.");
		printf("\n 3. MODIFICAR informacion de un Juguete.");
		printf("\n 4. ENTREGAR Juguetes de Cartas registradas.");
		printf("\n\n<--Digite una opcion (0-3): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': registrarJuguetes();
					break;
				case '2': eliminarJuguete();
					break;
				case '3': modificarJuguetes();
					break;
				case '4': MenuPrincipal();
					break;
				case '0': 
					break;
				default:
					fflush(stdin);
					printf("**Opcion no valida. Intente de nuevo.**\n");
					getchar();
					break;	
		}	
	}while(opcion!='0');			
	fflush(stdin);
	getchar();
}


/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void GestionDomicilios(){
	char opcion, ch;	

	do{
		system( "CLS" );
		fflush(stdin);
		printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf("     Gestion de Domicilios\n");
		printf("*********************************\n");
		printf("\n 0. REGRESAR al Menu Principal.");
		printf("\n 1. REGISTRAR un Lugar de Domicilio.");
		printf("\n 2. REGISTRAR una Ruta entre lugares.");
		printf("\n 3. MODIFICAR un Lugar de Domicilio.");
		printf("\n 4. MODIFICAR una Ruta entre lugares.");
		printf("\n 5. ELIMINAR un Lugar de Domicilio.");
		printf("\n 6. ELIMINAR una Ruta entre lugares.");
		printf("\n\n<--Digite una opcion (0-6): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': MenuPrincipal();
					break;
				case '2': MenuPrincipal();
					break;
				case '3': MenuPrincipal();
					break;
				case '4': MenuPrincipal();
					break;
				case '5': MenuPrincipal();
					break;
				case '6': MenuPrincipal();
					break;
				case '0': 
					break;
				default:
					fflush(stdin);
					printf("**Opcion no valida. Intente de nuevo.**\n");
					getchar();
					break;	
		}	
	}while(opcion!='0');			
	fflush(stdin);
	getchar();
}


/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void GestionAyudantes(struct ListaAyudantes *LAyudantes){
	char opcion, ch;	

	do{
		system( "CLS" );
		fflush(stdin);
		printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf("  Gestion de Ayudantes de Santa\n");
		printf("*********************************\n");
		printf("\n 0. REGRESAR al Menu Principal.");
		printf("\n 1. REGISTRAR informacion de un Ayudante de Santa.");
		printf("\n 2. MODIFICAR informacion de un Ayudante de Santa.");
		printf("\n 3. ELIMINAR informacion de un Ayudante de Santa.");
		printf("\n\n<--Digite una opcion (1-3): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': registrarAyudante(LAyudantes);
					break;
				case '2': modificarAyudante(LAyudantes);
					break;
				case '3': eliminarAyudante(LAyudantes);
					break;
				case '0':
					break;
				default:
					fflush(stdin);
					printf("**Opcion no valida. Intente de nuevo.**\n");
					getchar();
					break;		
		}	
	}while(opcion!='0');			
	fflush(stdin);
}


/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void GestionCartas(struct ListaNinos *LNinos, struct ListaCarta *LCarta, struct ListaDeseo *LDeseo){
	char opcion, ch;	

	do{
		system( "CLS" );
		fflush(stdin);
		printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf("       Gestion de Cartas\n");
		printf("*********************************\n");
		printf("\n 0. REGRESAR al Menu Principal.");
		printf("\n 1. REGISTRAR una Carta para Santa.");
		printf("\n 3. MODIFICAR una Carta para Santa.");
		printf("\n 1. CONSULTAR una Carta para Santa.");
		printf("\n 3. PROCESAR una Carta para Santa.");
		printf("\n\n<--Digite una opcion (0-3): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': registrarCartas(LNinos, LCarta, LDeseo);
					break;
				case '2': MenuPrincipal();
					break;
				case '3': MenuPrincipal();
					break;
				case '0': MenuPrincipal();
					break;
				default:
					fflush(stdin);
					printf("**Opcion no valida. Intente de nuevo.**\n");
					getchar();
					break;	
		}	
	}while(opcion!=3);			
	fflush(stdin);
	getchar();
}


/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void AnalisisDeDatos(){
	char opcion, ch;	

	do{
		system( "CLS" );
		fflush(stdin);
		printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf("      Analisis de Datos\n");
		printf("*********************************\n");
		printf("\n 0. REGRESAR al Menu Principal.");
		printf("\n 1. Cantidad de juguetes solicitados por año ");
		printf("\n 2. Lugar donde se solicitaron más y menos juguetes ");
		printf("\n 3. Cantidad de niños a los que se les aprobó su carta por año ");
		printf("\n 4. Cantidad de niños a los que se les rechazó su carta por año ");
		printf("\n 5. Cantidad de comportamientos buenos y malos registrados");
		printf("\n 6. Cantidad de cartas procesadas según ayudante. ");
		printf("\n 7. Top 10 de los juguetes más pedidos  ");
		printf("\n\n<--Digite una opcion (0-7): ");		
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': MenuPrincipal();
					break;
				case '2': MenuPrincipal();
					break;
				case '0': MenuPrincipal();
					break;
				default:
					fflush(stdin);
					printf("**Opcion no valida. Intente de nuevo.**\n");
					getchar();
					break;	
		}	
	}while(opcion!=3);			
	fflush(stdin);
	getchar();
}

/****************************************************************Gestion de Niños***********************************************************************************************/

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void registrarNinos(struct ListaNinos *LNinos){
  
	system( "CLS" );
    printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("     Registro de Ninos y Ninas\n" );
	printf("*********************************\n");

    struct Nino *nino;

    nino=(struct Nino *) malloc (sizeof(struct Nino));

    do{
        printf("\n-->Ingrese el numero de Identificacion: (Ej. 105450656) \n");
        gets(nino->cedula);
	
        if(validarCedula(LNinos, nino->cedula)==1){
            printf("\n**Esta Identificacion ya ha sido registrada**\n ");
        }else{
            break;
        }
    }while(1);
    
    printf("\n-->Ingrese el Nombre Completo: (Ej. Juan Perez) \n");
    gets(nino->nombre_completo);
    printf("\n-->Ingrese el Nombre de Usuario: (Ej. juanp123) \n");
    gets(nino->nombre_usuario);
    printf("\n-->Ingrese el Correo Electronico: (Ej. juanp123@correo.com) \n");
    gets(nino->correo);
    printf("\n-->Ingrese el Código del Domicilio (Ej. DOM-001): \n");
    gets(nino->codigo_domicilio);
    printf("\n-->Ingrese la Fecha de Nacimiento (Ej. 12/12/2000) \n");
    gets(nino->fecha_nacimiento);
    printf("\n-->Ingrese la Edad del nino/nina:\n");
    gets(nino->edad);
    printf("\n-->Ingrese alguna Necesidad(es) especial(es): \n");
    gets(nino->necesidades_esp);
    
    if(LNinos->inicio == NULL) 
	{
		LNinos->inicio = nino;
		LNinos->inicio->siguiente = NULL; 
		LNinos->inicio->anterior = NULL; 
		LNinos->final = LNinos->inicio;

	}
	else
	{	
		LNinos->final->siguiente = nino;
		LNinos->final->siguiente->siguiente = NULL; 
		LNinos->final->siguiente->anterior = LNinos->final; 
		LNinos->final = LNinos->final->siguiente;
	}	
    
	mostrarNinos(LNinos);
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void registrarComportamiento(struct ListaNinos *LNinos, struct ListaComport *LComp){
	 
	system( "CLS" );
    printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("   Registro de Comportamiento\n" );
	printf("*********************************\n");
	
	if(LNinos->inicio!=NULL)
	{
	    struct Comportamiento *comport;
	
	    comport=(struct Comportamiento *) malloc (sizeof(struct Comportamiento));
	
	    do{
	        printf("\n-->Ingrese el numero de Identificacion del Nino/Nina: (Ej. 105450656) \n");
	        gets(comport->cedula_nino);
		
	        if(validarCedula(LNinos, comport->cedula_nino)==0){
	            printf("\n**Esta Identificacion NO ha sido registrada**\n ");
	        }else{
	            break;
	        }
	    }while(1);
	    
		printf("\n-->Ingrese el Nombre del Padre/Madre: (Ej. Juan Perez) \n");
	    gets(comport->nombre_padre_madre);
	    printf("\n-->Ingrese la Fecha de Registro del comportamiento: (Ej. 12/12/2000) \n");
	    gets(comport->fecha_registro);
	    printf("\n-->Ingrese el indicador para el comportamiento: 1-BUENO o 2-MALO:\n");
	    gets(comport->indicacion);
	    printf("\n-->Ingrese la Descripcion del Comportamiento: \n");
	    gets(comport->descripcion);
	    
	    if(LComp->inicio == NULL) 
		{
			LComp->inicio = comport;
			LComp->inicio->siguiente = NULL; 
			LComp->inicio->anterior = NULL; 
			LComp->final = LComp->inicio;
	
		}
		else
		{	
			LComp->final->siguiente = comport;
			LComp->final->siguiente->siguiente = NULL; 
			LComp->final->siguiente->anterior = LComp->final; 
			LComp->final = LComp->final->siguiente;
		}	
	    
		mostrarComp(LComp);
		validarComp(LComp, comport->cedula_nino);
	
	}else{
		printf( "\n***No se han encontrado Ninos(as) registrados***");
	}
	
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
int validarCedula(struct ListaNinos *LNinos, const char identificacion []){

    struct Nino *i= LNinos->inicio;
    int comp=3;

    if(LNinos->inicio!=NULL)
    {
        while( i!= NULL){
			comp=strcmp(identificacion,i->cedula);
	        if(comp==0)
			{
                return 1;
            }
            i = i->siguiente;
        }
    }

    return 0;
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void modificarNino(struct ListaNinos *LNinos){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Modificar Info. de Ninos y Ninas\n" );
	printf("*********************************\n");
	
	struct Nino *iNino;
	int hallado=0, comp=3, resp;
	char id[15], respuesta[2], nombre[50], usuario[20], correo[50], domicilio[20], 
		  nacimiento[15], edad[5], necesidades[150]; 
	
	
    if(LNinos->inicio!=NULL)
	{
		
		printf("\n Ingrese el numero de identificacion: (Ejm. 105450656) \n ");
    	gets(id);
		
        iNino = LNinos->inicio;
        while(iNino!=NULL){
            
            comp=strcmp(id,iNino->cedula);
            if(comp==0){
            	printf("\n+------------------------------------+");
				printf("\n      Datos del  Nino/Nina " );
            	printf("\n+------------------------------------+");
                printf("\n  Identificacion: %s \n", iNino->cedula);
                printf("  Nombre Completo: %s \n", iNino->nombre_completo);
                printf("  Correo: %s \n", iNino->correo);
                printf("  Domicilio: %s \n", iNino->codigo_domicilio);
                printf("  Fecha de Nacimiento: %s \n", iNino->fecha_nacimiento);
                printf("  Edad: %s \n", iNino->edad);
                printf("  Necesidades Especiales: %s \n", iNino->necesidades_esp );
                printf("+-------------------------------------+\n");
                
                
                //Modificar el Nombre Completo
                do{
			        printf("\nDesea modificar el Nombre? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese el valor para el Nombre: (Ej. Juan Perez) \n");
			    	gets(nombre);	
					strcpy(iNino->nombre_completo,nombre);
				}
				
				//Modificar el Nombre de Usuario
				do{
			        printf("\nDesea modificar el Nombre de Usuario? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese el valor para el Nombre de Usuario: (Ej. juanp123) \n");
			    	gets(usuario);	
					strcpy(iNino->nombre_usuario,usuario);
				}
				
				//Modificar el Correo Electronico
				do{
			        printf("\nDesea modificar el Correo Electronico? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese el valor para el Correo Electronico: (Ej. juanp123@correo.com) \n");
			    	gets(usuario);	
					strcpy(iNino->correo,correo);
				}
				
				//Modificar el Domicilio
				do{
			        printf("\nDesea modificar el Domicilio? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese el Código del Domicilio (Ej. DOM-001): \n");
			    	gets(domicilio);	
					strcpy(iNino->codigo_domicilio,domicilio);
				}
				
				//Modificar la Fecha de Nacimiento
				do{
			        printf("\nDesea modificar la Fecha de Nacimiento? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese la Fecha de Nacimiento (Ej. 12/12/2000)\n");
			    	gets(nacimiento);	
					strcpy(iNino->fecha_nacimiento,nacimiento);
				}
				
               	//Modificar la Edad
				do{
			        printf("\nDesea modificar la Edad? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese la Edad del nino/nina\n");
			    	gets(edad);	
					strcpy(iNino->edad,edad);
				}
			   
			   	//Modificar las Necesidades Especiales
				do{
			        printf("\nDesea modificar la Necesidad(es) especial(es)? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese la Necesidad(es) especial(es): \n");
			    	gets(necesidades);	
					strcpy(iNino->necesidades_esp,necesidades);
				}
                      
                hallado=1;
				break;
			}
			iNino = iNino->siguiente;

        }
        
		if(hallado==0){
			printf( "\n***No se ha encontrado un Nino/Nina para la identificacion ingresada***");
		}
		
	}else{
		printf( "\n***No se han encontrado Ninos(as) registrados***");
	}
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void eliminarNino(struct ListaNinos *LNinos){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Eliminar Info. de Ninos y Ninas\n" );
	printf("*********************************\n");
	
	struct Nino *aux = LNinos->inicio;
	int hallado=0, comp=3;
	char id[15]; 
	
    if(LNinos->inicio!=NULL)
	{
		
		printf("\n Ingrese el numero de identificacion: (Ejm. 105450656) \n ");
    	gets(id);
	
		comp=strcmp(id,LNinos->inicio->cedula);
        if(comp==0)
		{
			if(LNinos->inicio == LNinos->final){ 
				LNinos->final = NULL;
				LNinos->inicio = NULL;
			}else{
				LNinos->inicio = LNinos->inicio->siguiente;
				LNinos->inicio->anterior = NULL;
			}
			hallado=1;				
		}
		else 
		{
			while(aux != NULL)
			{
				comp=strcmp(id,aux->cedula);
		        if(comp==0)
				{
					aux->anterior->siguiente = aux->siguiente;
					if(aux != LNinos->final)
						aux->siguiente->anterior = aux->anterior;
					else if(aux == LNinos->final) 
						LNinos->final = LNinos->final->anterior;					
					
					hallado=1;
					break;
					
				}
				aux = aux->siguiente;					
			}

		}
		
		if(hallado==0){
			printf( "\n***No se ha encontrado un Nino/Nina para la identificacion ingresada***");
		}
		
		if(aux != NULL)
		{
			printf("\n-->Se ha eliminado el Nino/Nina con la identificacion ingresada");
			free(aux);
		}			
	
	}else{
		printf( "\n***No se han encontrado Ninos(as) registrados***");
	}
	

	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void mostrarNinos(struct ListaNinos *LNinos){

	struct Nino *iNino;
	
	printf("\n+-------------------------------------------------------------------+\n");
	printf( "                      Lista de Ninos y Ninas" );
	printf("\n+-------------------------------------------------------------------+\n");
	

	if(LNinos->inicio!=NULL)
	{
        iNino = LNinos->inicio;
        int cont=1;
        	printf(" Cedula        Nombre                  Nombre de Usuario\n" ); 
        while(iNino!=NULL){
            printf("\n %s          %s                      %s\n" , iNino->cedula, iNino->nombre_completo, iNino->nombre_usuario);
            iNino = iNino->siguiente;

        }
        printf("\n+-------------------------------------------------------------------+\n");		
		
	}else{
		printf( "\n***No se han encontrado Ninos registrados***");
	}

}


/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void mostrarComp(struct ListaComport *LComp){

	struct Comportamiento *iComp;
	
	printf("\n+-------------------------------------------------------------------+\n");
	printf( "                      Lista de Comportamientos" );
	printf("\n+-------------------------------------------------------------------+\n");
	

	if(LComp->inicio!=NULL)
	{
        iComp = LComp->inicio;
        int cont=1;
        	printf(" Cedula        Nombre Padre            Fecha de Registro\n" ); 
        while(iComp!=NULL){
            printf("\n %s          %s                      %s\n" , iComp->cedula_nino, iComp->nombre_padre_madre, iComp->fecha_registro);
            iComp = iComp->siguiente;

        }
        printf("\n+-------------------------------------------------------------------+\n");		
		
	}else{
		printf( "\n***No se han encontrado Ninos registrados***");
	}

}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void validarComp(struct ListaComport *LComp, const char identificacion []){

	struct Comportamiento *iComp;
	int contador=0, comp=3;
	
	printf("\n+----------------------------+\n");
	printf( " Validación de Comportamiento" );
	printf("\n+----------------------------+\n");
	

	if(LComp->inicio!=NULL)
	{
        iComp = LComp->inicio;
        while(iComp!=NULL){
            comp=strcmp(identificacion,iComp->cedula_nino);
	        if(comp==0)
			{
				comp=strcmp("2",iComp->indicacion);
		        if(comp==0)
				{
					contador++;
				}
			}
			iComp = iComp->siguiente;

        }		
		
	}else{
		printf( "\n***No se han encontrado Ninos registrados***");
	}
	
	if(contador>=6){
		printf( "\n***El nino(a) tiene 6 o mas comportamiento MALOS)***");
	}else{
		printf( "\n***El nino(a) tiene menos de 6 comportamiento MALOS)***");
	}

}

/****************************************************************Gestion de Ayudantes***********************************************************************************************/

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void registrarAyudante(struct ListaAyudantes *LAyudantes){
    system( "CLS" );
    printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf(" Registro de Ayudantes de Santa\n");
		printf("*********************************\n");	
		
	struct AydanteSanta *ayudante;

    ayudante=(struct AydanteSanta *) malloc (sizeof(struct AydanteSanta));
			
    do{
	printf("\n Ingrese la Identificacion: (Ejm.105450656) \n");
	gets(ayudante->identificacion);

        if((validarIdentificacion(LAyudantes, ayudante->identificacion ))==1){
            printf("\n**Esta cedula ya ha sido registrada**\n ");
        }else{
            break;
        }
    }while(1);
    
    printf("\n Ingrese el Nombre del Ayudante: (Ejm.Juan Perez) \n");
    gets(ayudante->nombre);
    printf("\n Ingrese el Puesto del ayudante: (Ejm.Empacador) \n");
    gets(ayudante->puesto);
    printf("\n Ingrese la funcion que cumple en ese puesto: (Ejm. Colaboro con...) \n");
    gets(ayudante->funcionPuesto);
    printf("\n Ingrese la fecha en la que empezo a trabajar con santa: (Ejm. 20/12/2020) \n");
    gets(ayudante->fechaComienzo);
    
    if(LAyudantes->inicio == NULL) 
	{
		LAyudantes->inicio = ayudante;
		LAyudantes->inicio->siguiente = NULL; 
		LAyudantes->inicio->anterior = NULL; 
		LAyudantes->final = LAyudantes->inicio;

	}
	else
	{	
		LAyudantes->final->siguiente = ayudante;
		LAyudantes->final->siguiente->siguiente = NULL; 
		LAyudantes->final->siguiente->anterior = LAyudantes->final; 
		LAyudantes->final = LAyudantes->final->siguiente;
	}
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
int validarIdentificacion(struct ListaAyudantes *LAyudantes, const char identificacion []){

    struct AydanteSanta *i = LAyudantes->inicio;
    int comp=3;
	
    if(LAyudantes->inicio != NULL)
    {
        while( i != NULL){
			comp=strcmp(identificacion,i->identificacion);
	        if(comp==0)
			{
                return 1;
            }
            i = i->siguiente;
        }
    }
    return 0;
}


/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void modificarAyudante(struct ListaAyudantes *LAyudantes){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Modificar Info. de Ayudantes\n" );
	printf("*********************************\n");
	
	struct AydanteSanta *ayudante;
	int hallado=0, comp=3, resp;
	char id[15], respuesta[2], nombre[50], puesto[50], funcionPuesto[50], fechaComienzo[10]; 
	
	
    if(LAyudantes->inicio!=NULL)
	{
		
		printf("\n Ingrese el numero de identificacion: (Ejm. 105450656) \n ");
    	gets(id);
		
        ayudante = LAyudantes->inicio;
        while(ayudante!=NULL){
            comp=strcmp(id,ayudante->identificacion);
            if(comp==0){
            	printf("\n+------------------------------------+");
				printf("\n      Datos del  Ayudante " );
            	printf("\n+------------------------------------+");
                printf("\n  Identificacion: %s \n", ayudante->identificacion );
                printf("\n  Nombre: %s \n", ayudante->nombre);
                printf("\n  Puesto: %s \n", ayudante->puesto);
                printf("\n  Funcion que desempeña en el puesto: %s \n", ayudante->funcionPuesto);
                printf("\n  Fecha en que empezo a trabajar con santa: %s \n", ayudante->fechaComienzo );
                printf("+-------------------------------------+\n");
                
                //Modificar el Nombre Completo
                do{
			        printf("\nDesea modificar el Nombre? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese el valor para el Nombre: (Ej. Juan Perez) \n");
			    	gets(nombre);	
					strcpy(ayudante->nombre,nombre);
				}
				
				//Modificar el Puesto
				do{
			        printf("\nDesea modificar el Puesto? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese el puesto: (Ejm.Empacador) \n");
			    	gets(puesto);	
					strcpy(ayudante->puesto,puesto);
				}
				//Modificar la funcion
				do{
			        printf("\nDesea modificar la Funcion que desempeña en el puesto? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese la funcion que desempeña en ese puesto: (Ejm. Colaboro con...) \n");
			    	gets(funcionPuesto);	
					strcpy(ayudante->funcionPuesto,funcionPuesto);
				}
				//Modificar la fecha
				do{
			        printf("\nDesea modificar la Fecha en que empezo a trabajar con santa? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese la fecha en la que empezo a trabajar con santa: (Ejm. 20/12/2020) \n");
			    	gets(fechaComienzo);	
					strcpy(ayudante->fechaComienzo,fechaComienzo);
				}
      
                hallado=1;
				break;
			}
			ayudante = ayudante->siguiente;
        }
        
		if(hallado==0){
			printf( "\n***No se ha encontrado un Nino/Nina para la identificacion ingresada***");
		}
		
	}else{
		printf( "\n***No se han encontrado Ninos registrados***");
	}
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}


/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void eliminarAyudante(struct ListaAyudantes *LAyudantes){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Eliminar Info. de Ayudantes\n" );
	printf("*********************************\n");
	
	
	
	struct AydanteSanta *aux= LAyudantes->inicio;
	int hallado=0, comp=3;
	char id[15]; 
	
    if(LAyudantes->inicio!=NULL)
	{
		
		printf("\n Ingrese el numero de identificacion: (Ejm. 105450656) \n ");
    	gets(id);
	
		comp=strcmp(id,LAyudantes->inicio->identificacion);
        if(comp==0)
		{
			if(LAyudantes->inicio == LAyudantes->final){ 
				LAyudantes->final = NULL;
				LAyudantes->inicio = NULL;
			}else{
				LAyudantes->inicio = LAyudantes->inicio->siguiente;
				LAyudantes->inicio->anterior = NULL;
			}
			hallado=1;				
		}
		else 
		{
			while(aux != NULL)
			{
				comp=strcmp(id,aux->identificacion);
		        if(comp==0)
				{
					aux->anterior->siguiente = aux->siguiente;
					if(aux != LAyudantes->final)
						aux->siguiente->anterior = aux->anterior;
					else if(aux == LAyudantes->final) 
						LAyudantes->final = LAyudantes->final->anterior;					
					
					hallado=1;
					break;
					
				}
				aux = aux->siguiente;					
			}

		}
		
		if(hallado==0){
			printf( "\n***No se ha encontrado un AYUDANTE para la identificacion ingresada***");
		}
		
		if(aux != NULL)
		{
			printf("\n-->Se ha eliminado el AYUDANTE con la identificacion ingresada");
			free(aux);
		}			
	
	}else{
		printf( "\n***No se han encontrado AYUDANTES registrados***");
	}
	

	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/****************************************************************Gestion de Juguetes***********************************************************************************************/

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void registrarJuguetes(){
	
  
	system( "CLS" );
    printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("      Registro de Juguetes\n" );
	printf("*********************************\n");
	
	struct Juguete *nuevo;
    nuevo = (struct Juguete *) malloc (sizeof(struct Juguete));

    printf("\n-->Ingrese el Codigo del Juguete: (Ej. 001) \n");
    gets(nuevo->codigo);
    
    do{
        printf("\n-->Ingrese el Nombre de Juguete: \n");
    	gets(nuevo->nombre);
	
        if(validarNombreJuguete(nuevo->nombre)==1){
            printf("\n**Esta Juguete ya ha sido registrado**\n ");
        }else{
            break;
        }
    }while(1);
    
    
    printf("\n-->Ingrese una Descripcion para el Juguete:\n");
    gets(nuevo->descripcion);
    printf("\n-->Ingrese la Categoria a la que pertenece el Juguete: \n");
    gets(nuevo->categoria);
    printf("\n-->Ingrese el Rango de edad para la que se recomienda el juguete (Ej. 6-10) \n");
    gets(nuevo->rango_edad);
    printf("\n-->Ingrese el Costo total de fabricacion del juguete :\n");
    gets(nuevo->costo_fabricacion);
    
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if (jugueteRaiz == NULL)
        jugueteRaiz = nuevo;
    else
    {
        struct Juguete *anterior, *aux;
        anterior = NULL;
        aux = jugueteRaiz;
        while (aux != NULL)
        {
            anterior = aux;
            if ( strcmp(aux->nombre, nuevo->nombre)> 0 ){
            	aux = aux->izq;
			}
                
            else{
                aux = aux->der;
			}
           
        }
        if (strcmp(anterior->nombre, nuevo->nombre) > 0){
        	anterior->izq = nuevo;
		}else{
        	anterior->der = nuevo;
		}
            
        
            
    }
    
	printf("\n+------------------------------+\n");
	printf( "      Lista de Juguetes" );
	printf("\n+------------------------------+\n");
	
	printf(" Codigo - Nombre \n" ); 
	
	mostrarJuguetes(jugueteRaiz);
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
int validarNombreJuguete(char nombre []){

	struct Juguete* iJuguete;
	
	iJuguete = buscarJuguete(jugueteRaiz, nombre);
	
	if(iJuguete!=NULL)
	{
		return 1;
	}else{
		return 0;
	}

    
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
struct Juguete* buscarJuguete(struct Juguete *arbol, char jugueteBuscado[]){
	struct Juguete *aux = arbol;
	
	if(aux != NULL)
	{
		if( strcmp(jugueteBuscado, aux->nombre) < 0){
			buscarJuguete(aux->izq, jugueteBuscado);
		}
		else if(strcmp(jugueteBuscado, aux->nombre) > 0){
			buscarJuguete(aux->der, jugueteBuscado);
		}
		else
			return aux;	
	}
	else
		return NULL;	
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void modificarJuguetes(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Modificar Info. de Juguetes\n" );
	printf("*********************************\n");
	
	struct Juguete* iJuguete;
	int comp=3, resp;
	char codigo[15], respuesta[2], nombre[50], descripcion[150], categoria[50],rango_edad[20], costo_fabricacion[15];
	
    if(jugueteRaiz!=NULL)
	{
		
		printf("\n Ingrese el nombre del juguete: \n ");
    	gets(nombre);
		
		iJuguete = buscarJuguete(jugueteRaiz, nombre);
		
		if(iJuguete!=NULL)
		{
		   	printf("\n+------------------------------------+");
			printf("\n      Datos del Juguete " );
	    	printf("\n+------------------------------------+");
	        printf("\n  Nombre: %s \n", iJuguete->nombre);
	        printf("  Codigo: %s \n", iJuguete->codigo);
	        printf("  Descripcion: %s \n", iJuguete->descripcion);
	        printf("  Categoria: %s \n", iJuguete->categoria);
	        printf("  Rango de Edad: %s \n", iJuguete->rango_edad);
	        printf("  Costo de Fabricacion: %s \n", iJuguete->costo_fabricacion);
	        printf("+-------------------------------------+\n");
	                
	        //Modificar el Codigo del juguete
	        do{
		        printf("\nDesea modificar el Codigo? (1-Si 2-No)\n" );
	        	gets(respuesta);
				resp=atoi(respuesta);
	        
		        if(resp==1 || resp==2){
		            break;
		        }
		    }while(1);
	        
	        if(resp==1){
	        	printf("\n-->Ingrese el valor para el Codigo: \n");
		    	gets(codigo);	
				strcpy(iJuguete->codigo,codigo);
			}
			
			//Modificar la Descripcion del juguete
	        do{
		        printf("\nDesea modificar la Descripcion? (1-Si 2-No)\n" );
	        	gets(respuesta);
				resp=atoi(respuesta);
	        
		        if(resp==1 || resp==2){
		            break;
		        }
		    }while(1);
	        
	        if(resp==1){
	        	printf("\n-->Ingrese el valor para la descripcion: \n");
		    	gets(descripcion);	
				strcpy(iJuguete->descripcion,descripcion);
			}
			
			//Modificar la Categoria del juguete
	        do{
		        printf("\nDesea modificar la Categoria? (1-Si 2-No)\n" );
	        	gets(respuesta);
				resp=atoi(respuesta);
	        
		        if(resp==1 || resp==2){
		            break;
		        }
		    }while(1);
	        
	        if(resp==1){
	        	printf("\n-->Ingrese el valor para la Categoria: \n");
		    	gets(categoria);	
				strcpy(iJuguete->categoria,categoria);
			}
			
			//Modificar el Rango de Edad del juguete
	        do{
		        printf("\nDesea modificar el Rango de Edad? (1-Si 2-No)\n" );
	        	gets(respuesta);
				resp=atoi(respuesta);
	        
		        if(resp==1 || resp==2){
		            break;
		        }
		    }while(1);
	        
	        if(resp==1){
	        	printf("\n-->Ingrese el valor para Rango de Edad: (Ej. 6-10)\n");
		    	gets(rango_edad);	
				strcpy(iJuguete->rango_edad,rango_edad);
			}
			
			//Modificar el Costo de Fabricacion  del juguete
	        do{
		        printf("\nDesea modificar el Costo de Fabricacion ? (1-Si 2-No)\n" );
	        	gets(respuesta);
				resp=atoi(respuesta);
	        
		        if(resp==1 || resp==2){
		            break;
		        }
		    }while(1);
	        
	        if(resp==1){
	        	printf("\n-->Ingrese el valor para el Costo de Fabricacion: \n");
		    	gets(costo_fabricacion);	
				strcpy(iJuguete->costo_fabricacion,costo_fabricacion);
			}
			
			
        }else{
			printf( "\n***No se ha encontrado un Juguete con el Nombre ingresado***");
		}
		
	}else{
		printf( "\n***No se han encontrado Juguetes registrados***");
	}
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
struct Juguete *borrarJuguete(struct Juguete *aux, char porBorrar[]){
 	
	struct Juguete *temporal, *siguiente;
	
	if (aux == NULL)
        return NULL;	
	
	if(strcmp(aux->nombre, porBorrar) < 0 )
	{
		printf("Dentro1");
		aux->izq = borrarJuguete(aux->izq, porBorrar);
	}
	else if(strcmp(aux->nombre, porBorrar) > 0 )
	{
		printf("Dentro2");
		aux->der = borrarJuguete(aux->der, porBorrar);
	}
	else
	{
		printf("Dentro3");
		//Borrado de nodo con dos hijos	
		if (aux->izq != NULL && aux->der!=NULL)
        {
        	siguiente = aux->der;
        	while (siguiente->izq)
			{
				siguiente = siguiente->izq;
			}
			aux = siguiente;
			aux->der = borrarJuguete(aux->der, siguiente->nombre);	        	
		}
		else
		{
			printf("Dentro4");
			temporal = aux;
			if(aux->izq != NULL)//Borrado de Nodo con un hijo (izq)
			{
				aux=aux->izq;
			}
			else if(aux->der!=NULL)//Borrado de Nodo con un hijo (der)
			{
				aux=aux->der;
			}
			else //Borrado de nodo sin hijos
			{
				aux=NULL;
			}
			free(temporal);
		}
	}	
	return aux;
 }

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void eliminarJuguete(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Eliminar Info. de un Juguete\n" );
	printf("*********************************\n");
	
	struct Juguete *borrar;
    borrar = (struct Juguete *) malloc (sizeof(struct Juguete));
	char nombreJuguete[50], opcion[3];
	
    if(jugueteRaiz!=NULL)
	{

		printf("\n Ingrese el nombre del juguete: \n ");
    	gets(nombreJuguete);
		
		borrar = buscarJuguete(jugueteRaiz, nombreJuguete);
		
		if(borrar!=NULL)
		{
		   	printf("\n+------------------------------------+");
			printf("\n      Datos del Juguete " );
	    	printf("\n+------------------------------------+");
	        printf("\n  Nombre: %s \n", borrar->nombre);
	        printf("  Codigo: %s \n", borrar->codigo);
	        printf("  Descripcion: %s \n", borrar->descripcion);
	        printf("  Categoria: %s \n", borrar->categoria);
	        printf("  Rango de Edad: %s \n", borrar->rango_edad);
	        printf("  Costo de Fabricacion: %s \n", borrar->costo_fabricacion);
	        printf("+-------------------------------------+\n");
	       	
			do{
				printf("\n-->Desea eliminar este juguete?:\n");
		    	printf("<--Digite 1-SI, 2-NO: \n");
				gets(opcion);
				
				if (strcmp(opcion ,"2")==0){
					break;			
				}
		
				if (strcmp(opcion ,"1")==0){
					jugueteRaiz = borrarJuguete(jugueteRaiz, nombreJuguete);
					break;						
				}
			
			}while(1); 
			
        }else{
			printf( "\n***No se ha encontrado un Juguete para el Nombre ingresado***");
		}
		
	}else{
		printf( "\n***No se han encontrado Juguetes registrados***");
	}
	
	mostrarJuguetes(jugueteRaiz);
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void mostrarJuguetes(struct Juguete *recorrer){
    
	if (recorrer != NULL)//Imprime en En Orden
    {
        mostrarJuguetes(recorrer->izq);
		printf("\n%s - %s",recorrer->codigo, recorrer->nombre);
        mostrarJuguetes(recorrer->der);
    }
}


/****************************************************************Gestion de Cartas***********************************************************************************************/
/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void registrarCartas(struct ListaNinos *LNinos, struct ListaCarta *LCarta, struct ListaDeseo *LDeseo){
  
	system( "CLS" );
    printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("       Registro de Cartas\n" );
	printf("*********************************\n");

    struct Carta *carta;
    struct Deseo *deseo;
    struct Juguete *buscado;
    buscado = (struct Juguete *) malloc (sizeof(struct Juguete));
    
    char identificacion[20], anno[10], nombreJuguete[50], opcion[3], opcion2[3];
    
    int juguetesRegistrados=0;

    do{
       do{
	        printf("\n-->Ingrese el numero de Identificacion: (Ej. 105450656) \n");
	        gets(identificacion);
		
	        if(validarCedula(LNinos, identificacion)!=1){
	            printf("\n**Esta Identificacion no ha sido registrada**\n ");
	        }else{
	            break;
	        }
	    }while(1);
	
		printf("\n-->Ingrese el Anno que corresponda:\n");
		gets(anno);
	
        if(validarCarta(LCarta, identificacion, anno)==1){
            printf("\n**La identificacion ya tiene registrada una carta para el anno ingresado**\n ");
        }else{
            break;
        }
    }while(1);
    
    
	
    if(jugueteRaiz!=NULL)
	{
		printf("*********************************\n");
		printf("        Agregar Juguetes\n" );
		printf("*********************************\n");
		
		strcpy(opcion, "1");
	    
	    do{
	    	
			if (strcmp(opcion ,"1")==0){
				
				carta=(struct Carta *) malloc (sizeof(struct Carta));
				
				printf("\n-->Ingrese el nombre del juguete que desea agregar:\n");
	        	gets(nombreJuguete);
				
				buscado = buscarJuguete(jugueteRaiz, nombreJuguete);
				
				if(buscado!=NULL)
				{
				   	printf("\n+------------------------------------+");
					printf("\n        Datos del Juguete " );
			    	printf("\n+------------------------------------+");
			        printf("\n  Nombre: %s \n", buscado->nombre);
			        printf("  Codigo: %s \n", buscado->codigo);
			        printf("  Descripcion: %s \n", buscado->descripcion);
			        printf("  Categoria: %s \n", buscado->categoria);
			        printf("  Rango de Edad: %s \n", buscado->rango_edad);
			        printf("+-------------------------------------+\n");
			       	
					do{
						printf("\n-->Desea agregar este juguete?:\n");
				    	printf("   Digite 1-Carta para Santa"); 
						printf("\n          2-Lista de Deseos");
						printf("\n          3-Omitir\n<--");
						gets(opcion2);
							
						if (strcmp(opcion2 ,"1")==0){
							
							juguetesRegistrados=contarJuguetes(LCarta, identificacion, anno);
							
							if(juguetesRegistrados==1){
								printf( "\n***Ya se han registrado 10 juguetes en la Carta para Santa***");
								break;
							}else{
								strcpy(carta->identificacion, identificacion);
								strcpy(carta->anno, anno);
								strcpy(carta->nombre_juguete, nombreJuguete);
								strcpy(carta->estado, "Solicitado");
								
								if(LCarta->inicio == NULL) 
								{
									LCarta->inicio = carta;
									LCarta->inicio->siguiente = NULL; 
									LCarta->inicio->anterior = NULL; 
									LCarta->final = LCarta->inicio;
								}
								else
								{	
									LCarta->final->siguiente = carta;
									LCarta->final->siguiente->siguiente = NULL; 
									LCarta->final->siguiente->anterior = LCarta->final; 
									LCarta->final = LCarta->final->siguiente;
								}					
							}
							break;
								
						}
						
						if (strcmp(opcion2 ,"2")==0){
							
							deseo=(struct Deseo *) malloc (sizeof(struct Deseo));
							
							strcpy(deseo->anno, carta->anno);
							strcpy(deseo->identificacion, carta->identificacion);
							strcpy(deseo->nombre_juguete, carta->nombre_juguete);
							
							if(LDeseo->inicio == NULL) 
							{
								LDeseo->inicio = deseo;
								LDeseo->inicio->siguiente = NULL; 
								LDeseo->inicio->anterior = NULL; 
								LDeseo->final = LDeseo->inicio;
							}
							else
							{	
								LDeseo->final->siguiente = deseo;
								LDeseo->final->siguiente->siguiente = NULL; 
								LDeseo->final->siguiente->anterior = LDeseo->final; 
								LDeseo->final = LDeseo->final->siguiente;
							}
							break;						
						}
						
						if (strcmp(opcion2 ,"3")==0){
							break;			
						}
					
					}while(1); 
					
		        }else{
					printf( "\n***No se ha encontrado un Juguete con el Nombre ingresado***");
				}
								
				printf("\n-->Desea agregar otro juguete?:\n");
				printf("   Digite 1-SI, 2-NO\n<--");
				gets(opcion);
				
				if (strcmp(opcion ,"2")==0){
					printf("\n+-------------------------------------+\n");
					break;			
				}
				printf("\n+-------------------------------------+\n");					
			}	
		
		}while(1);	
		
	}else{
		printf( "\n***No se han encontrado Juguetes registrados***");
	}
       
	mostrarCarta(LCarta, carta->identificacion, carta->anno);
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
int validarCarta(struct ListaCarta *LCarta, const char identificacion [], const char anno []){

    struct Carta *i= LCarta->inicio;
    int comp1=3, comp2=3;

    if(LCarta->inicio!=NULL)
    {
        while( i!= NULL){
			comp1=strcmp(identificacion,i->identificacion);
			comp1=strcmp(identificacion,i->anno);
	        if(comp1==0 && comp2==0)
			{
                return 1;
            }
            i = i->siguiente;
        }
    }

    return 0;
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
int contarJuguetes(struct ListaCarta *LCarta, const char identificacion [], const char anno []){

    struct Carta *i= LCarta->inicio;
    int comp1=3, comp2=3, cont=0;

    if(LCarta->inicio!=NULL)
    {
        while( i!= NULL){
			comp1=strcmp(identificacion,i->identificacion);
			comp1=strcmp(identificacion,i->anno);
	        if(comp1==0 && comp2==0)
			{
                cont++;
            }
            i = i->siguiente;
        }
    }
    
    if(cont>=10){
        return 1;
    }else{
    	return 0;
	}

    
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void modificarCarta(struct ListaCarta *LCarta){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Modificar una Carta para Santa\n" );
	printf("*********************************\n");
	
//	struct Nino *iNino;
//	int hallado=0, comp=3, resp;
//	char id[15], respuesta[2], nombre[50], usuario[20], correo[50], domicilio[20], 
//		  nacimiento[15], edad[5], necesidades[150]; 
//	
//	
//    if(LNinos->inicio!=NULL)
//	{
//		
//		printf("\n Ingrese el numero de identificacion: (Ejm. 105450656) \n ");
//    	gets(id);
//		
//        iNino = LNinos->inicio;
//        while(iNino!=NULL){
//            
//            comp=strcmp(id,iNino->cedula);
//            if(comp==0){
//            	printf("\n+------------------------------------+");
//				printf("\n      Datos del  Nino/Nina " );
//            	printf("\n+------------------------------------+");
//                printf("\n  Identificacion: %s \n", iNino->cedula);
//                printf("  Nombre Completo: %s \n", iNino->nombre_completo);
//                printf("  Correo: %s \n", iNino->correo);
//                printf("  Domicilio: %s \n", iNino->codigo_domicilio);
//                printf("  Fecha de Nacimiento: %s \n", iNino->fecha_nacimiento);
//                printf("  Edad: %s \n", iNino->edad);
//                printf("  Necesidades Especiales: %s \n", iNino->necesidades_esp );
//                printf("+-------------------------------------+\n");
//                
//                
//                //Modificar el Nombre Completo
//                do{
//			        printf("\nDesea modificar el Nombre? (1-Si 2-No)\n" );
//                	gets(respuesta);
//					resp=atoi(respuesta);
//                
//			        if(resp==1 || resp==2){
//			            break;
//			        }
//			    }while(1);
//                
//                if(resp==1){
//                	printf("\n-->Ingrese el valor para el Nombre: (Ej. Juan Perez) \n");
//			    	gets(nombre);	
//					strcpy(iNino->nombre_completo,nombre);
//				}
//				           
//                hallado=1;
//				break;
//			}
//			iNino = iNino->siguiente;
//
//        }
//        
//		if(hallado==0){
//			printf( "\n***No se ha encontrado un Nino/Nina para la identificacion ingresada***");
//		}
//		
//	}else{
//		printf( "\n***No se han encontrado Ninos(as) registrados***");
//	}
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void consultarCarta(struct ListaCarta *LCarta){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Consultar una Carta para Santa\n" );
	printf("*********************************\n");
	
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void mostrarCarta(struct ListaCarta *LCarta, const char identificacion [], const char anno []){

	struct Carta *iCarta;
	
	printf("\n+-------------------------------------------------------------------+\n");
	printf( "                      Carta para Santa" );
	printf("\n+-------------------------------------------------------------------+\n");
	printf("\n+Identificacion: %s    -    Anno: %s\n", identificacion, anno);
	printf("\n+-------------------------------------------------------------------+\n");
	
	if(LCarta->inicio!=NULL)
	{
        iCarta = LCarta->inicio;
        int cont=1;
        	printf(" Nombre del juguete     -    Estado del Juguete\n" ); 
        while(iCarta!=NULL){
            printf("\n %s     -      %s  \n" , iCarta->nombre_juguete, iCarta->estado);
            iCarta = iCarta->siguiente;

        }
        printf("\n+-------------------------------------------------------------------+\n");		
		
	}else{
		printf( "\n***No se han encontrado Juguetes registrados en la Carta para Santa***");
	}
	
//	struct Deseo *iDeseo;
//	
//	printf("\n+-------------------------------------------------------------------+\n");
//	printf( "                      Lista de Deseos" );
//	printf("\n+-------------------------------------------------------------------+\n");
//	printf("\n+Identificacion: %s    -    Anno: %s\n", identificacion, anno);
//	printf("\n+-------------------------------------------------------------------+\n");
//	
//	if(LDeseo->inicio!=NULL)
//	{
//        iDeseo = LDeseo->inicio;
//        int cont=1;
//        	printf(" Nombre del juguete \n" ); 
//        while(iDeseo!=NULL){
//            printf("\n %s \n" , iDeseo->nombre_juguete);
//            iDeseo = iDeseo->siguiente;
//
//        }
//        printf("\n+-------------------------------------------------------------------+\n");		
//		
//	}else{
//		printf( "\n***No se han encontrado Juguetes registrados en la Lista de Deseos***");
//	}
}



int main(){ 

	MenuPrincipal();    
	return 0; 
}


