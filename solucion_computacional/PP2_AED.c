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

typedef struct JuguetesCarta JuguetesCarta;
typedef struct ListaJugCarta ListaJugCarta;

typedef struct Carta Carta;
typedef struct ListaCartas ListaCartas;

typedef struct Deseo Deseo;
typedef struct ListaDeseos ListaDeseos;

typedef struct CartaProcesada CartaProcesada;
typedef struct PilaCartasProcesadas PilaCartasProcesadas;

typedef struct JugSolicitado JugSolicitado;
typedef struct PilaJugSolicitados PilaJugSolicitados;

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
void registrarCartas(struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta, struct ListaCartas *LCartas, struct ListaDeseos *LDeseos);
int validarCarta(struct ListaCartas *LCartas, const char identificacion [], const char anno []);
int contarJuguetes(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno []);
void modificarCarta(struct ListaCartas *LCartas, struct ListaJugCarta *LJugCarta, struct ListaDeseos *LDeseos);
void consultarCarta(struct ListaCartas *LCartas, struct ListaDeseos *LDeseos, struct ListaJugCarta *LJugCarta);
void mostrarCarta(struct ListaJugCarta *LJugCarta, struct ListaDeseos *LDeseos, const char identificacion [], const char anno []);
void agregarJuguete(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno [], const char nombreJuguete []);
int eliminarJugueteCarta(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno [], const char nombreJuguete []);
void agregarDeseo(struct ListaDeseos *LDeseos, const char identificacion [], const char anno [], const char nombreJuguete []);
int eliminarDeseo(struct ListaDeseos *LDeseos, const char identificacion [], const char anno [], const char nombreJuguete []);
void mostrarListaCartas(struct ListaCartas *LCartas);

//Procedimientos para el Analisis de Datos
void juguetesPorAnno(struct ListaJugCarta *LJugCarta);
void masMenosCartas(struct ListaCartas *LCartas);
void aprobadasPorAnno(struct ListaCartas *LCartas);
void rechazadasPorAnno(struct ListaCartas *LCartas);
void comportRegistrados(struct ListaComport *LComp);
void cartasPorAyudante(struct ListaCartas *LCartas);
void juguetesMasPedidos(struct ListaJugCarta *LJugCarta);

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

struct JuguetesCarta{
    char identificacion[12];
	char anno[50];
    char nombre_juguete[20];
    char estado[50];
    JuguetesCarta *siguiente;
    JuguetesCarta *anterior;
    
};

struct ListaJugCarta{
	JuguetesCarta *inicio;
	JuguetesCarta *final;
};

struct Carta{
    char identificacion[12];
	char anno[50];
    char estado[50];
    char procesada_por[50];
    Carta *siguiente;
    Carta *anterior;
    
};

struct ListaCartas{
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

struct ListaDeseos{
	Deseo *inicio;
	Deseo *final;
};

struct CartaProcesada{
    char procesada_por[50];
    int cantidad;
    CartaProcesada *siguiente; 
};

struct PilaCartasProcesadas{
	CartaProcesada *tope;
};

struct JugSolicitado{
    char nombre_juguete[50];
    int cantidad;
    JugSolicitado *siguiente; 
};

struct PilaJugSolicitados{
	JugSolicitado *tope;
};

/****************************************************************Menús de Opciones***********************************************************************************************/

Juguete *jugueteRaiz=NULL;

/*
	Entradas: Un número (tipo char) en un rango de 0 a 7 para escoger una de las opciones disponibles en el menú. 
	Salidas: Llamada a las demás funciones de menús.
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
	
	struct ListaCartas *LCartas;
	LCartas = (struct ListaCartas *) malloc(sizeof(struct ListaCartas));
	LCartas->inicio = NULL;
	LCartas->final = NULL;
	
	struct ListaJugCarta *LJugCartas;
	LJugCartas = (struct ListaJugCarta *) malloc(sizeof(struct ListaJugCarta));
	LJugCartas->inicio = NULL;
	LJugCartas->final = NULL;
	
	struct ListaDeseos *LDeseos;
	LDeseos = (struct ListaDeseos *) malloc(sizeof(struct ListaDeseos));
	LDeseos->inicio = NULL;
	LDeseos->final = NULL;
	
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
            case '5': GestionCartas(LNinos, LJugCartas, LCartas, LDeseos);
				break;
			case '6': AnalisisDeDatos(LJugCartas, LCartas, LComp);
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
	Entradas: Un número (tipo char) en un rango de 0 a 4 para escoger una de las opciones disponibles en el menú. 
	Salidas: Llamada a las demás funciones para la gestión de de Ninos (registro, modificación, borrado de niños, 
			 y registro de comportamiento)
	Restricciones: Solo se deben ingresar números en un rango de 0 a 4.
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
	Entradas: Un número (tipo char) en un rango de 0 a 4 para escoger una de las opciones disponibles en el menú. 
	Salidas: Llamada a las demás funciones para la gestión de de Juguetes (registro, modificación, borrado, 
			 y entrega de juguetes)
	Restricciones: Solo se deben ingresar números en un rango de 0 a 4.
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
}


/*
	Entradas: Un número (tipo char) en un rango de 0 a 6 para escoger una de las opciones disponibles en el menú. 
	Salidas: Llamada a las demás funciones para la gestión de Domicilios y Rutas (registro, modificación, borrado 
			 de Domicilios, y registro, modificación, borrado de Rutas entre Domicilios)
	Restricciones: Solo se deben ingresar números en un rango de 0 a 6.
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
}


/*
	Entradas: Un número (tipo char) en un rango de 0 a 3 para escoger una de las opciones disponibles en el menú. 
	Salidas: Llamada a las demás funciones para la gestión de Ayudantes de Santa (registro, modificación, borrado 
			 de Ayudantes)
	Restricciones: Solo se deben ingresar números en un rango de 0 a 3.
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
		printf("\n\n<--Digite una opcion (0-3): ");	
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
	Entradas: Un número (tipo char) en un rango de 0 a 4 para escoger una de las opciones disponibles en el menú. 
	Salidas: Llamada a las demás funciones para la gestión de Cartas y Listas de Deseos (registro, modificación,  
			 consulta y procesamiento de Cartas para Santa)
	Restricciones: Solo se deben ingresar números en un rango de 0 a 4.
*/
void GestionCartas(struct ListaNinos *LNinos, struct ListaJugCarta *LJugCartas, struct ListaCartas *LCartas, struct ListaDeseos *LDeseos){
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
		printf("\n 2. MODIFICAR una Carta para Santa.");
		printf("\n 3. CONSULTAR una Carta para Santa.");
		printf("\n 4. PROCESAR una Carta para Santa.");
		printf("\n\n<--Digite una opcion (0-4): ");	
		opcion=getchar();
				
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': registrarCartas(LNinos, LJugCartas, LCartas, LDeseos);
					break;
				case '2': modificarCarta(LCartas, LJugCartas, LDeseos);
					break;
				case '3': consultarCarta(LCartas, LDeseos, LJugCartas);
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
}


/*
	Entradas: Un número (tipo char) en un rango de 0 a 7 para escoger una de las opciones disponibles en el menú. 
	Salidas: Llamada a las demás funciones de Analisis de Datos
	Restricciones: Solo se deben ingresar números en un rango de 0 a 7.
*/
void AnalisisDeDatos(struct ListaJugCarta *LJugCarta, struct ListaCartas *LCartas, struct ListaComport *LComp){
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
		printf("\n 2. Lugar donde se solicitaron mas y menos juguetes ");
		printf("\n 3. Cantidad de ninos a los que se les aprobo su carta por anno ");
		printf("\n 4. Cantidad de ninos a los que se les rechazo su carta por anno ");
		printf("\n 5. Cantidad de comportamientos buenos y malos registrados");
		printf("\n 6. Cantidad de cartas procesadas segun ayudante. ");
		printf("\n 7. Top 10 de los juguetes mas pedidos  ");
		printf("\n\n<--Digite una opcion (0-7): ");		
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': juguetesPorAnno(LJugCarta);
					break;
				case '2': masMenosCartas(LCartas);
					break;
				case '3': aprobadasPorAnno(LCartas);
					break;
				case '4': rechazadasPorAnno(LCartas);
					break;
				case '5': comportRegistrados(LComp);
					break;
				case '6': cartasPorAyudante(LCartas);
					break;
				case '7': juguetesMasPedidos(LJugCarta);
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

/****************************************************************Gestion de Niños***********************************************************************************************/

/*
	Entradas: Una lista de tipo ListaNinos para almacenar los datos de un Nino/Nina
	Salidas: Se agrega un nuevo nodo de tipo Nino a la lista recibida.
	Restricciones: Ninguna.
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
    printf("\n+---------------------------------------------+\n");
	printf( "       Lista de Domicilios" );
	printf("\n+---------------------------------------------+\n");
	printf("\n Codigo          Lugar        Codigo Postal ");
	printf("\n+---------------------------------------------+\n");
	printf("\n DOM-001   El Carmen, Cartago		  30103 ");
	printf("\n DOM-002   Pocosol, San Carlos      21013");
	printf("\n DOM-003   San Pedro, San Jose      11501 ");
	printf("\n DOM-004   La Cruz, Guanacaste      51001");
	printf("\n+---------------------------------------------+\n");
    printf("\n-->Ingrese el Codigo del Domicilio (Ej. DOM-001): \n");
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
    
//	mostrarNinos(LNinos);
	
	printf("\n+++ Informacion registrada correctamente +++" );
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: Una lista de tipo ListaNinos  y otra de ListaComport para almacenar los datos del comportamiento
			  de un Nino/Nina antes registrado
	Salidas: Se agrega un nuevo nodo de tipo Comportamiento a la lista recibida.
	Restricciones: Ninguna.
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
	    
//		mostrarComp(LComp);
//		validarComp(LComp, comport->cedula_nino);
		printf("\n+++ Informacion registrada correctamente +++" );
	
	}else{
		printf( "\n***No se han encontrado Ninos(as) registrados***");
	}
	
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: Una lista de tipo ListaNinos y una char identificacion para consultar los datos de un Nino/Nina
	Salidas: 1 si ya existe un nodo con la misma identificacion y 0 si no existe.
	Restricciones: Ninguna.
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
	Entradas: Una lista de tipo ListaNinos para tomar los datos de un Nino/Nina
	Salidas: Se modifican los datos un nodo de tipo Nino de la lista recibida.
	Restricciones: Ninguna.
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
                	printf("\n+---------------------------------------------+\n");
					printf( "       Lista de Domicilios" );
					printf("\n+---------------------------------------------+\n");
					printf("\n Codigo          Lugar        Codigo Postal ");
					printf("\n+---------------------------------------------+\n");
					printf("\n DOM-001   El Carmen, Cartago		  30103 ");
					printf("\n DOM-003   San Pedro, San Jose      11501 ");
					printf("\n DOM-004   La Cruz, Guanacaste      51001");
					printf("\n+---------------------------------------------+\n");
                	printf("\n-->Ingrese el Codigo del Domicilio (Ej. DOM-001): \n");
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
	Entradas: Una lista de tipo ListaNinos para tomar los datos de un Nino/Nina
	Salidas: Se eliminan los datos un nodo de tipo Nino de la lista recibida.
	Restricciones: Ninguna.
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
	Entradas: Una lista de tipo ListaNinos para tomar los datos de un Nino/Nina
	Salidas: Se muestran los datos un nodo de tipo Nino de la lista recibida.
	Restricciones: Ninguna.
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
	Entradas: Una lista de tipo ListaComport para tomar los datos de comportamiento de un Nino/Nina
	Salidas: Se muestran los datos un nodo de tipo Nino de la lista recibida.
	Restricciones: Ninguna.
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
	Entradas: Una lista de tipo ListaComport para tomar los datos de comportamiento de un Nino/Nina
	Salidas: Se muestran los datos un nodo de tipo Comportamiento de la lista recibida.
	Restricciones: Ninguna.
*/
void validarComp(struct ListaComport *LComp, const char identificacion []){

	struct Comportamiento *iComp;
	int contador=0, comp=3;
	
	printf("\n+----------------------------+\n");
	printf( " Validacion de Comportamiento" );
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
	Entradas: Una lista de tipo ListaAyudantes para almacenar los datos de un Ayudante de Santa
	Salidas: Se agrega un nuevo nodo de tipo AyudanteSanta a la lista recibida.
	Restricciones: Ninguna.
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
    printf("\n Ingrese la fecha en la que empezo a trabajar con Santa: (Ejm. 20/12/2020) \n");
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
	
	printf("\n+++ Informacion registrada correctamente +++" );
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: Una lista de tipo ListaAyudantes y una char identificacion para consultar los datos de un Ayudante de Santa
	Salidas: 1 si ya existe un nodo con la misma identificacion y 0 si no existe.
	Restricciones: Ninguna.
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
	Entradas: Una lista de tipo ListaAyudantes para tomar los datos de un Ayudante de Santa
	Salidas: Se modifican los datos un nodo de tipo AyudanteSanta de la lista recibida.
	Restricciones: Ninguna.
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
                printf("\n  Fecha en que empezo a trabajar con Santa: %s \n", ayudante->fechaComienzo );
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
			printf( "\n***No se ha encontrado un Ayudante para la identificacion ingresada***");
		}
		
	}else{
		printf( "\n***No se han encontrado Ayudantes registrados***");
	}
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}


/*
	Entradas: Una lista de tipo ListaAyudantes para tomar los datos de un Ayudante de Santa
	Salidas: Se eliminan los datos un nodo de tipo Ayudante de la lista recibida.
	Restricciones: Ninguna.
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
			printf( "\n***No se ha encontrado un Ayudante para la identificacion ingresada***");
		}
		
		if(aux != NULL)
		{
			printf("\n-->Se ha eliminado el Ayudante con la identificacion ingresada");
			free(aux);
		}			
	
	}else{
		printf( "\n***No se han encontrado Ayudantes registrados***");
	}
	

	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/****************************************************************Gestion de Juguetes***********************************************************************************************/

/*
	Entradas: Una nodo de tipo Juguete para adjuntar los datos de uno nuevo a un Arbol binario de Busqueda
	Salidas: Se agrega un nuevo nodo de tipo Juguete al Arbol binario de Busqueda
	Restricciones: Ninguna.
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

    printf("\n-->Ingrese el Codigo del Juguete: (Ej. JUG-001) \n");
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
    
//	printf("\n+------------------------------+\n");
//	printf( "      Lista de Juguetes" );
//	printf("\n+------------------------------+\n");
//	
//	printf(" Codigo - Nombre \n" ); 
//	
//	mostrarJuguetes(jugueteRaiz);

	printf("\n+++ Informacion registrada correctamente +++" );
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: El nodo raiz del Arbol de juguetes y una char nombre para consultar los datos de un Juguete
	Salidas: 1 si ya existe un nodo con el mismo nombre y 0 si no existe.
	Restricciones: Ninguna.
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
	Entradas: El nodo padre del Arbol de Juguetes  y el nombre del juguete buscado
	Salidas: 1 si existe un nodo con el mismo nombre y 0 si no existe.
	Restricciones: Ninguna.
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
	Entradas: El nodo raiz del Arbol de Juguetes para tomar los datos de un Juguete
	Salidas: Se modifican los datos un nodo de tipo Juguete del arbol recibido.
	Restricciones: Ninguna.
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
	Entradas: El nodo padre del Arbol de Juguetes  y el nombre del juguete por borrar
	Salidas: Se borran los datos un nodo de tipo Juguete según su posición en el Arbol.
	Restricciones: Ninguna.
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
	Entradas: El nodo raiz del Arbol de Juguetes para tomar los datos de un Juguete
	Salidas: Se modifican los datos un nodo de tipo Juguete del arbol recibido.
	Restricciones: Ninguna.
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
//					jugueteRaiz = borrarJuguete(jugueteRaiz, nombreJuguete);
					printf("\n-->Se ha eliminado el Ayudante con la identificacion ingresada");
					break;						
				}
			
			}while(1); 
			
        }else{
			printf( "\n***No se ha encontrado un Juguete para el Nombre ingresado***");
		}
		
	}else{
		printf( "\n***No se han encontrado Juguetes registrados***");
	}
	
//	mostrarJuguetes(jugueteRaiz);
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: El nodo raiz del Arbol de Juguetes para tomar los datos de un Juguete
	Salidas: Se muestran los datos un nodo de tipo Juguete del arbol recibido.
	Restricciones: Ninguna.
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
	Entradas: Una lista de tipo ListaCarta para almacenar los datos de una Carta para Santa
	Salidas: Se agrega un nuevo nodo de tipo Carta a la lista recibida.
	Restricciones: Ninguna.
*/
void registrarCartas(struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta, struct ListaCartas *LCartas, struct ListaDeseos *LDeseos){
  
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
    carta=(struct Carta *) malloc (sizeof(struct Carta));
    
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
	
        if(validarCarta(LCartas, identificacion, anno)==1){
            printf("\n**La identificacion ya tiene registrada una carta para el anno ingresado**\n ");
        }else{
            break;
        }
        
    }while(1);
    
    
	
    if(jugueteRaiz!=NULL)
	{
		strcpy(carta->identificacion, identificacion);
		strcpy(carta->anno, anno);
		strcpy(carta->estado, "Solicitada");
		
		if(LCartas->inicio == NULL) 
		{
			LCartas->inicio = carta;
			LCartas->inicio->siguiente = NULL; 
			LCartas->inicio->anterior = NULL; 
			LCartas->final = LCartas->inicio;
		}
		else
		{	
			LCartas->final->siguiente = carta;
			LCartas->final->siguiente->siguiente = NULL; 
			LCartas->final->siguiente->anterior = LCartas->final; 
			LCartas->final = LCartas->final->siguiente;
		}
		
//		mostrarListaCartas(LCartas);
								
		printf("*********************************\n");
		printf("        Agregar Juguetes\n" );
		printf("*********************************\n");
		
		strcpy(opcion, "1");
	    
	    do{
	    	
			if (strcmp(opcion ,"1")==0){
						
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
						printf("\n-->Desea agregar este juguete?:");
				    	printf("\nDigite 1-Carta para Santa"); 
						printf("\n       2-Lista de Deseos");
						printf("\n       3-Omitir\n<--");
						gets(opcion2);
							
						if (strcmp(opcion2 ,"1")==0){
							
							juguetesRegistrados=contarJuguetes(LJugCarta, identificacion, anno);
							
							if(juguetesRegistrados==1){
								printf( "\n***Ya se han registrado 10 juguetes en la Carta para Santa***");
								break;
							}else{	
								agregarJuguete(LJugCarta, identificacion, anno, nombreJuguete);											
							}
							break;
								
						}
						
						if (strcmp(opcion2 ,"2")==0){
							
							agregarDeseo(LDeseos, identificacion, anno, nombreJuguete);
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
       
	mostrarCarta(LJugCarta, LDeseos, carta->identificacion, carta->anno);
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: Una lista de tipo ListaCarta, un char identificacion y otro Anno para consultar los datos de una carta para Santa
	Salidas: 1 si ya existe un nodo con la misma identificacion y Anno, y 0 si no existe.
	Restricciones: Ninguna.
*/
int validarCarta(struct ListaCartas *LCartas, const char identificacion [], const char anno []){

    struct Carta *i= LCartas->inicio;
    int comp1=3, comp2=3;

    if(LCartas->inicio!=NULL)
    {
        while( i!= NULL){
	        if(strcmp(i->identificacion,identificacion) == 0 && strcmp(i->anno,anno) == 0)
			{
                return 1;
            }
            i = i->siguiente;
        }
    }

    return 0;
}

/*
	Entradas: Una lista de tipo ListaCarta, un char identificacion y otro Anno para consultar los datos de una carta para Santa
	Salidas: 1 si ya existen 10 un nodos con la misma identificacion y Anno, y 0 si no existen.
	Restricciones: Ninguna.
*/
int contarJuguetes(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno []){

    struct JuguetesCarta *i= LJugCarta->inicio;
    int comp1=3, comp2=3, cont=0;

    if(LJugCarta->inicio!=NULL)
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
	Entradas: Una lista de tipo ListaJugCarta, un char identificacion, otro Anno, y el nombre de un juguete, para agregar los datos de un juguete una carta para Santa
	Salidas: Se agrega un nuevo nodo de tipo Juguete a la lista recibida.
	Restricciones: Ninguna.
*/
void agregarJuguete(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno [], const char nombreJuguete []){

    struct JuguetesCarta *solicitado;
    solicitado = (struct JuguetesCarta *) malloc (sizeof(struct JuguetesCarta));

    strcpy(solicitado->identificacion, identificacion);
    strcpy(solicitado->anno, anno);
    strcpy(solicitado->nombre_juguete, nombreJuguete);
    strcpy(solicitado->estado, "Solicitado");

    if(LJugCarta->inicio == NULL) 
    {
        LJugCarta->inicio = solicitado;
        LJugCarta->inicio->siguiente = NULL; 
        LJugCarta->inicio->anterior = NULL; 
        LJugCarta->final = LJugCarta->inicio;
    }
    else
    {
        LJugCarta->final->siguiente = solicitado;
        LJugCarta->final->siguiente->siguiente = NULL; 
        LJugCarta->final->siguiente->anterior = LJugCarta->final; 
        LJugCarta->final = LJugCarta->final->siguiente;
    }

}

/*
	Entradas: Una lista de tipo ListaJugCarta, un char identificacion, otro Anno, y el nombre de un juguete, para eliminar los datos de un juguete una carta para Santa
	Salidas: Se elimina un nodo de tipo Juguete a la lista recibida.
	Restricciones: Ninguna.
*/
int eliminarJugueteCarta(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno [], const char nombreJuguete []){

    struct JuguetesCarta *eliminado = LJugCarta->inicio;
    
    if(LJugCarta->inicio!=NULL)
	{
	
		if(strcmp(eliminado->anno,anno) == 0 && strcmp(eliminado->identificacion,identificacion) == 0 && strcmp(eliminado->nombre_juguete,nombreJuguete) == 0){
			if(LJugCarta->inicio == LJugCarta->final){ 
				LJugCarta->final = NULL;
				LJugCarta->inicio = NULL;
			}else{
				LJugCarta->inicio = LJugCarta->inicio->siguiente;
				LJugCarta->inicio->anterior = NULL;
			}
			
		  	printf("\n-->El juguete se ha eliminado de la Carta para Santa");
		  	free(eliminado);
            return 1;
							
		}
		else 
		{
			while (eliminado != NULL){
	    	
		        if (strcmp(eliminado->anno,anno) == 0 && strcmp(eliminado->identificacion,identificacion) == 0 && strcmp(eliminado->nombre_juguete,nombreJuguete) == 0){
		               
					    eliminado->anterior->siguiente = eliminado->siguiente;
		                if(eliminado != LJugCarta->final)
		                    eliminado->siguiente->anterior = eliminado->anterior;
		                else if(eliminado == LJugCarta->final) 
		                    LJugCarta->final = LJugCarta->final->anterior;
		
		                printf("\n-->El juguete se ha eliminado de la Carta para Santa");
		                free(eliminado);
		                return 1;
		                
		        }
		        
		        eliminado = eliminado->siguiente;
		    }
		}
	}else{
		printf( "\n***No se han encontrado Juguetes registrados***");
	}

    
    printf("**El juguete solicitado NO existe en la Carta para Santa***");
	return 0;

}


/*
	Entradas: Una lista de tipo ListaDeseos, un char identificacion, otro Anno, y el nombre de un juguete, para agregar los datos de un juguete una carta para Santa
	Salidas: Se agrega un nuevo nodo de tipo Deseo a la lista recibida.
	Restricciones: Ninguna.
*/
void agregarDeseo(struct ListaDeseos *LDeseos, const char identificacion [], const char anno [], const char nombreJuguete []){

    struct Deseo *deseo;
    deseo=(struct Deseo *) malloc (sizeof(struct Deseo));

    strcpy(deseo->anno, anno);
    strcpy(deseo->identificacion, identificacion);
    strcpy(deseo->nombre_juguete, nombreJuguete);

    if(LDeseos->inicio == NULL) 
    {
        LDeseos->inicio = deseo;
        LDeseos->inicio->siguiente = NULL; 
        LDeseos->inicio->anterior = NULL; 
        LDeseos->final = LDeseos->inicio;
    }
    else
    {
        LDeseos->final->siguiente = deseo;
        LDeseos->final->siguiente->siguiente = NULL; 
        LDeseos->final->siguiente->anterior = LDeseos->final; 
        LDeseos->final = LDeseos->final->siguiente;
    }

}

/*
	Entradas: Una lista de tipo ListaJugCarta, un char identificacion, otro Anno, y el nombre de un juguete, para eliminar los datos de un juguete una lista de deseos
	Salidas: Se elimina un nodo de tipo Deseo a la lista recibida.
	Restricciones: Ninguna.
*/
int eliminarDeseo(struct ListaDeseos *LDeseos, const char identificacion [], const char anno [], const char nombreJuguete []){

    struct Deseo *eliminado =  LDeseos->inicio;

	if(LDeseos->inicio!=NULL)
	{
	
		if(strcmp(eliminado->anno,anno) == 0 && strcmp(eliminado->identificacion,identificacion) == 0 && strcmp(eliminado->nombre_juguete,nombreJuguete) == 0){
			if(LDeseos->inicio == LDeseos->final){ 
				LDeseos->final = NULL;
				LDeseos->inicio = NULL;
			}else{
				LDeseos->inicio = LDeseos->inicio->siguiente;
				LDeseos->inicio->anterior = NULL;
			}
			
			printf("\n-->El juguete se ha eliminado de la Lista de Deseos");
            free(eliminado);
            return 1;
							
		}
		else 
		{
			while (eliminado != NULL){
	    	
		        if (strcmp(eliminado->anno,anno) == 0 && strcmp(eliminado->identificacion,identificacion) == 0 && strcmp(eliminado->nombre_juguete,nombreJuguete) == 0){
		               
					    eliminado->anterior->siguiente = eliminado->siguiente;
		                if(eliminado != LDeseos->final)
		                    eliminado->siguiente->anterior = eliminado->anterior;
		                else if(eliminado == LDeseos->final) 
		                    LDeseos->final = LDeseos->final->anterior;
		
		                printf("\n-->El juguete se ha eliminado de la Lista de Deseos");
		                free(eliminado);
		                return 1;
		                
		        }
		        
		        eliminado = eliminado->siguiente;
		    }
		}
	}else{
		printf( "\n***No se han encontrado Deseos registrados***");
	}

    
    printf("**El juguete solicitado NO existe en la Lista de Deseos***");
	return 0;
}

/*
	Entradas: Una lista de tipo ListaCarta, un char identificacion y otro Anno para consultar los datos de una carta para Santa
	Salidas: Se modifican los datos un nodo de tipo Carta de la lista recibida.
	Restricciones: Ninguna.
*/
void modificarCarta(struct ListaCartas *LCartas, struct ListaJugCarta *LJugCarta, struct ListaDeseos *LDeseos){
	
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Modificar una Carta para Santa\n" );
	printf("*********************************\n");

	struct Juguete *buscado;
	buscado = (struct Juguete *) malloc (sizeof(struct Juguete));
	char identificacion[20], anno[10], nombreJuguete[50], opcion[3], opcion2[3];
    int juguetesRegistrados=0, resultado=0;
	
    if(LCartas->inicio!=NULL){
    	
    	mostrarListaCartas(LCartas);

        printf("\n-->Ingrese el numero de Identificacion: (Ej. 105450656) \n");
        gets(identificacion);
	
		printf("\n-->Ingrese el Anno que corresponda:\n");
		gets(anno);
	
        if(validarCarta(LCartas, identificacion, anno)==1){
        	
            mostrarCarta(LJugCarta, LDeseos, identificacion, anno);

			do{
				printf("\n-->Elija la operacion que desea realizar?:");
		    	printf("\nDigite 1-Agregar Juguete a la Carta para Santa"); 
				printf("\n       2-Eliminar Juguete de la Carta para Santa");
				printf("\n       3-Mover Juguete de la Lista de Deseos a la");
				printf("\n         Carta para Santa");
				printf("\n       4-Omitir operacion\n<--");
				gets(opcion);
					
				if (strcmp(opcion ,"1")==0){//Agregar un juguete
					
					juguetesRegistrados=contarJuguetes(LJugCarta, identificacion, anno);
					
					if(juguetesRegistrados==1){
						printf( "\n***Ya se han registrado 10 juguetes en la Carta para Santa***");
						break;
					}else{
														
						printf("\n-->Ingrese el nombre del juguete que desea agregar:\n");
			        	gets(nombreJuguete);
						
						buscado = buscarJuguete(jugueteRaiz, nombreJuguete);
						
						if(buscado!=NULL){
						   	printf("\n+------------------------------------+");
							printf("\n        Datos del Juguete " );
					    	printf("\n+------------------------------------+");
					        printf("\n  Nombre: %s \n", buscado->nombre);
					        printf("  Codigo: %s \n", buscado->codigo);
					        printf("  Descripcion: %s \n", buscado->descripcion);
					        printf("  Categoria: %s \n", buscado->categoria);
					        printf("  Rango de Edad: %s \n", buscado->rango_edad);
					        printf("+-------------------------------------+\n");
					        
					        printf("\n-->Desea agregar este juguete?:");
					    	printf("\nDigite 1-Si"); 
							printf("\n       2-No\n<--");
							gets(opcion2);
					        
					        if (strcmp(opcion ,"1")==0){
					        	agregarJuguete(LJugCarta, identificacion, anno, nombreJuguete);	
					        	printf("\n-->El juguete se ha agregado a la Carta para Santa\n");
							}
					        
					    }else{
							printf( "\n***No se ha encontrado un Juguete con el Nombre ingresado***");
						}
						
					}
					break;
							
				}
					
				if (strcmp(opcion ,"2")==0){
					
					printf("\n-->Ingrese el nombre del juguete que desea eliminar de la carta:\n");
			        gets(nombreJuguete);
					
					resultado=eliminarJugueteCarta(LJugCarta, identificacion, anno, nombreJuguete);
					
					break;						
				}
				
				if (strcmp(opcion ,"3")==0){
					
					juguetesRegistrados=contarJuguetes(LJugCarta, identificacion, anno);
					
					if(juguetesRegistrados==1){
						printf( "\n***Ya se han registrado 10 juguetes en la Carta para Santa***");
						break;
					}else{
														
						printf("\n-->Ingrese el nombre del juguete que desea mover:\n");
			        	gets(nombreJuguete);
						
						resultado = eliminarDeseo(LDeseos, identificacion, anno, nombreJuguete);
						
						if(resultado==1){
							agregarJuguete(LJugCarta, identificacion, anno, nombreJuguete);
							
							printf("\n-->El juguete se ha movido a la Carta para Santa\n");
						}
						
					}
					
					break;			
				}
				
				if (strcmp(opcion ,"4")==0){
					break;			
				}
					
			}while(strcmp(opcion ,"1")!=0);	
	
		}else{
			printf("\n**No se tiene una carta para la identificacion y el anno ingresados**\n ");
		}
		
	}else{
		printf( "\n***No se han encontrado Cartas para Santa registradas***");
	}
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: Una lista de tipo ListaCarta, otra ListaJugCarta y otra ListaDeseos para tomar los datos de los juguetes de una Carta para Santa y una lista de deseos
	Salidas: Se muestran los datos de una Carta para Santa y de una Lista de Deseos en caso de que exista, para el anno e identificación ingresados 
	Restricciones: Ninguna.
*/
void consultarCarta(struct ListaCartas *LCartas, struct ListaDeseos *LDeseos, struct ListaJugCarta *LJugCarta){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Consultar una Carta para Santa\n" );
	printf("*********************************\n");
	
	char identificacion[20], anno[10];
	
	if(LCartas->inicio!=NULL){
    	
    	mostrarListaCartas(LCartas);

        printf("\n-->Ingrese el numero de Identificacion: (Ej. 105450656) \n");
        gets(identificacion);
	
		printf("\n-->Ingrese el Anno que corresponda:\n");
		gets(anno);
	
        if(validarCarta(LCartas, identificacion, anno)==1){
        	
            mostrarCarta(LJugCarta, LDeseos, identificacion, anno);
	
		}else{
			printf("\n**No se tiene una carta para la identificacion y el anno ingresados**\n ");
		}
		
	}else{
		printf( "\n***No se han encontrado Cartas para Santa registradas***");
	}
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: Una lista de tipo ListaCarta, otra ListaJugCarta y otra ListaDeseos, un char identificacion y otro Anno, para tomar los datos de los juguetes de una Carta para 
			   Santa y una lista de deseos
	Salidas: Se muestran los datos de una Carta para Santa y de una Lista de Deseos en caso de que exista, para el anno e identificación ingresados 
	Restricciones: Ninguna.
*/
void mostrarCarta(struct ListaJugCarta *LJugCarta, struct ListaDeseos *LDeseos, const char identificacion [], const char anno []){

	struct JuguetesCarta *iJugCarta = LJugCarta->inicio;
	
	printf("\n\n+-------------------------------------------------------------------+\n");
	printf( "                        CARTA PARA SANTA" );
	printf("\n+-------------------------------------------------------------------+\n");
	printf("\n+Identificacion: %s    -    Anno: %s\n", identificacion, anno);
	printf("\n+-------------------------------------------------------------------+\n");
	
	if(LJugCarta->inicio!=NULL)
	{
        int cont=1;
        printf(" Nombre del juguete     -    Estado del Juguete\n" ); 

        while(iJugCarta!=NULL){
            printf("\n %s     -      %s  \n" , iJugCarta->nombre_juguete, iJugCarta->estado);
            iJugCarta = iJugCarta->siguiente;
        }
        printf("\n+-------------------------------------------------------------------+\n");		
		
	}else{
		printf( "\n***No se han encontrado Juguetes registrados en la Carta para Santa***");
		printf("\n+-------------------------------------------------------------------+\n");
	}
	
	struct Deseo *iJugDeseo = LDeseos->inicio;
	
	printf("\n+-------------------------------------------------------------------+\n");
	printf( "                        LISTA DE DESEOS" );
	printf("\n+-------------------------------------------------------------------+\n");
	
	if(LDeseos->inicio!=NULL)
	{
        int cont=1;
        printf(" Nombre del juguete \n" ); 

        while(iJugDeseo!=NULL){
            printf("\n %s   \n" , iJugDeseo->nombre_juguete);
            iJugDeseo = iJugDeseo->siguiente;
        }
        printf("\n+-------------------------------------------------------------------+\n");		
		
	}else{
		printf( "\n***No se han encontrado Juguetes registrados en la Lista de Deseos***");
		printf("\n+-------------------------------------------------------------------+\n");
	}
	
}

/*
	Entradas: Una lista de tipo ListaCarta para tomar los datos de los juguetes de una Carta para Santa 
	Salidas: Se muestran los datos de todo los nodos de tipo Carta de la lista recibida.
	Restricciones: Ninguna.
*/
void mostrarListaCartas(struct ListaCartas *LCartas){

	struct Carta *iCarta = LCartas->inicio;
	
	printf("\n+-------------------------------------------------------------------+\n");
	printf( "                      CARTAS PARA SANTA REGISTRADAS" );
	printf("\n+-------------------------------------------------------------------+\n");
		
	if(LCartas->inicio!=NULL)
	{
        while(iCarta!=NULL){
            printf("\n+Identificacion: %s    -    Anno: %s   -   Estado: %s\n", iCarta->identificacion, iCarta->anno, iCarta->estado);
            iCarta = iCarta->siguiente;
        }		
		
	}else{
		printf( "\n***No se han encontrado Cartas para Santa registradas***");
	}
	
	printf("\n+-------------------------------------------------------------------+\n");
}


/****************************************************************Analisis de Datos***********************************************************************************************/
/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void juguetesPorAnno(struct ListaJugCarta *LJugCarta){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Juguetes solicitados por Anno\n" );
	printf("*********************************\n");
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void masMenosCartas(struct ListaCartas *LCartas){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Lugares con mas/menos cartas\n" );
	printf("*********************************\n");
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void aprobadasPorAnno(struct ListaCartas *LCartas){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Cartas aprobadas por Anno\n" );
	printf("*********************************\n");
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void rechazadasPorAnno(struct ListaCartas *LCartas){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Cartas rechazadas por Anno\n" );
	printf("*********************************\n");
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void comportRegistrados(struct ListaComport *LComp){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("    Comportamientos Registrados\n" );
	printf("*********************************\n");
	
	struct Comportamiento *iComp;
	int compBuenos=0, compMalos=0;
	
	if(LComp->inicio!=NULL)
	{
        iComp = LComp->inicio;
        while(iComp!=NULL){
            if(strcmp(iComp->indicacion, "1")==0){
            	compBuenos++;
			}else if (strcmp(iComp->indicacion, "1")==0){
				compMalos++;
			}else{
				break;
			}
            iComp = iComp->siguiente;

        }

		printf("\n+-----------------------------------------+\n");
		printf( " -->Total Comportamientos BUENOS: %d", compBuenos );
		printf("\n+-----------------------------------------+\n");
		printf( " -->Total Comportamientos MALOS: %d", compMalos );
		printf("\n+-----------------------------------------+\n");
		
	}else{
		printf( "\n***No se han encontrado Comportamientos registrados***");
	}
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void cartasPorAyudante(struct ListaCartas *LCartas){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Cartas procesadas según Ayudante\n" );
	printf("*********************************\n");
		
	struct Carta *iCarta = LCartas->inicio;
	struct CartaProcesada *iCartaProc, *nCartaProc;
	struct PilaCartasProcesadas *CProc;
	CProc = (struct PilaCartasProcesadas *) malloc(sizeof(struct PilaCartasProcesadas));
	CProc->tope = NULL;
		
	//Conteo de las Cartas Procesadas	
	if(LCartas->inicio!=NULL)
	{
        iCarta = LCartas->inicio;
		while( iCarta!= NULL){
		
			if(CProc->tope==NULL)
			{
				nCartaProc =(struct CartaProcesada *) malloc (sizeof(struct CartaProcesada));
						
				strcpy(nCartaProc->procesada_por, iCarta->procesada_por);
				nCartaProc->cantidad = 1;
				
				nCartaProc->siguiente = CProc->tope;
				CProc->tope = nCartaProc;
				
			}else{	
				for(iCartaProc = CProc->tope; iCartaProc!= NULL; iCartaProc = iCartaProc->siguiente){
					
					if(strcmp(iCarta->procesada_por,iCartaProc->procesada_por)==0){
						iCartaProc->cantidad = iCartaProc->cantidad+1;
						break;
					}else{
						nCartaProc =(struct CartaProcesada *) malloc (sizeof(struct CartaProcesada));
						
						strcpy(nCartaProc->procesada_por, iCarta->procesada_por);
						nCartaProc->cantidad = 1;
						
						nCartaProc->siguiente = CProc->tope;
						CProc->tope = nCartaProc;
						break;
					}
					
				}
			}
			iCarta = iCarta->siguiente;
		}
		
		//Mostrar cantidades contadas
		printf("\n+----------------------------------------+\n");
		printf( "  Identificación    -   Cartas Procesadas" );
		printf("\n+----------------------------------------+\n");
		
		iCartaProc = CProc->tope;
			
		if(CProc->tope!=NULL)
		{
	        while(iCartaProc!=NULL){
	            printf("\n %s   -   %d", iCartaProc->procesada_por, iCartaProc->cantidad);
	            iCartaProc = iCartaProc->siguiente;
	        }		
			
		}else{
			printf( "\n***No se han encontrado Cartas para Santa procesadas***");
		}
				
		
	}else{
		printf( "\n***No se han encontrado Cartas para Santa registradas***");
	}
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void juguetesMasPedidos(struct ListaJugCarta *LJugCarta){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Top de Juguetes mas solicitados\n" );
	printf("*********************************\n");
	
	struct JuguetesCarta *iJugCarta;
	struct JugSolicitado *iJugSolicitado, *nJugSolicitado;
	
	struct PilaJugSolicitados *JugSolic;
	JugSolic = (struct PilaJugSolicitados *) malloc(sizeof(struct PilaJugSolicitados));
	JugSolic->tope = NULL;

    //Conteo de las Juguetes Solicitados	
	if(LJugCarta->inicio!=NULL)
	{
        iJugCarta = LJugCarta->inicio;
		while( iJugCarta!= NULL){
			
			if(JugSolic->tope==NULL)
			{
				nJugSolicitado =(struct JugSolicitado *) malloc (sizeof(struct JugSolicitado));
					
				strcpy(nJugSolicitado->nombre_juguete, iJugCarta->nombre_juguete);
				nJugSolicitado->cantidad = 1;
				
				nJugSolicitado->siguiente = JugSolic->tope;
				JugSolic->tope = nJugSolicitado;
			}else{
				for(iJugSolicitado = JugSolic->tope; iJugSolicitado!= NULL; iJugSolicitado = iJugSolicitado->siguiente){
				
					if(strcmp(iJugCarta->nombre_juguete,iJugSolicitado->nombre_juguete)==0){
						iJugSolicitado->cantidad = iJugSolicitado->cantidad+1;
						break;
					}else{
						nJugSolicitado =(struct JugSolicitado *) malloc (sizeof(struct JugSolicitado));
						
						strcpy(nJugSolicitado->nombre_juguete, iJugCarta->nombre_juguete);
						nJugSolicitado->cantidad = 1;
						
						nJugSolicitado->siguiente = JugSolic->tope;
						JugSolic->tope = nJugSolicitado;
						break;
					}
					
				}
			}
						
			iJugCarta = iJugCarta->siguiente;
		}
		
		//Mostrar cantidades contadas
		printf("\n+----------------------------------------+\n");
		printf( "  Nombre del Juguete    -   Cant. Solicitudes" );
		printf("\n+----------------------------------------+\n");
		
		iJugSolicitado = JugSolic->tope;
			
		if(JugSolic->tope!=NULL)
		{
	        while(iJugSolicitado!=NULL){
	            printf("\n %s   -   %d", iJugSolicitado->nombre_juguete, iJugSolicitado->cantidad);
	            iJugSolicitado = iJugSolicitado->siguiente;
	        }		
			
		}else{
			printf( "\n***No se han encontrado juguetes solicitados 1***");
		}
				
		
	}else{
		printf( "\n***No se han encontrado juguetes solicitados 2***");
	}
	

	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}


int main(){ 

	MenuPrincipal();    
	return 0; 
}


