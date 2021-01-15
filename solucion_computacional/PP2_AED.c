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

typedef struct CartaSolicitada CartaSolicitada;
typedef struct PilaCartas PilaCartas;

typedef struct JugSolicitado JugSolicitado;
typedef struct ListaJugSolicitados ListaJugSolicitados;
typedef struct PilaJugSolicitados PilaJugSolicitados;

typedef struct Domicilio Domicilio;
typedef struct Ruta Ruta;
typedef struct Recorrido Recorrido;

//Procedimientos para Menus de Opciones
void MenuPrincipal();
void GestionNinos();
void GestionJuguetes();
void GestionDomicilios();
void GestionAyudantes();
void GestionCartas();
void GestionEntregas();
void AnalisisDeDatos();

//Procedimientos para Gestion de Ninos/as
void registrarNinos(struct ListaNinos *LNinos);
void mostrarNinos(struct ListaNinos *LNinos);
void modificarNino(struct ListaNinos *LNinos);
void eliminarNino(struct ListaNinos *LNinos);
int validarCedula(struct ListaNinos *LNinos, const char identificacion []);
void registrarComportamiento(struct ListaNinos *LNinos, struct ListaComport *LComp);
void mostrarComp(struct ListaComport *LComp);
int validarComp(struct ListaComport *LComp, const char identificacion []);

//Procedimientos para Gestion de de Ayudantes de santa
void registrarAyudante(struct ListaAyudantes *LAyudantes);
int validarIdentificacion(struct ListaAyudantes *LAyudantes, const char identificacion []);
void modificarAyudante(struct ListaAyudantes *LAyudantes);
void eliminarAyudante(struct ListaAyudantes *LAyudantes);

//Procedimientos para Gestion de Juguetes
void registrarJuguetes();
void mostrarJuguetes(struct Juguete *recorrer);
void modificarJuguetes();
struct Juguete* buscarJuguete(struct Juguete *arbol, char jugueteBuscado[]);
struct Juguete *borrarJuguete(struct Juguete *aux, char porBorrar[]);
void eliminarJuguete();

//Procedimientos para Gestion de Cartas para Santa

	//  Funciones para Registro de cartas
void registrarCartas(struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta, struct ListaCartas *LCartas, struct ListaDeseos *LDeseos);
int validarCarta(struct ListaCartas *LCartas, const char identificacion [], const char anno []);
int contarJuguetes(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno []);


	//  Funciones para Modificar las cartas
void modificarCarta(struct ListaCartas *LCartas, struct ListaJugCarta *LJugCarta, struct ListaDeseos *LDeseos);
void agregarJuguete(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno [], const char nombreJuguete []);
int eliminarJugueteCarta(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno [], const char nombreJuguete []);
void agregarDeseo(struct ListaDeseos *LDeseos, const char identificacion [], const char anno [], const char nombreJuguete []);
int eliminarDeseo(struct ListaDeseos *LDeseos, const char identificacion [], const char anno [], const char nombreJuguete []);


	//  Funciones para Mostrar/Consultar lascartas
void consultarCarta(struct ListaCartas *LCartas, struct ListaDeseos *LDeseos, struct ListaJugCarta *LJugCarta);
void mostrarCarta(struct ListaCartas *LCartas, struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno []);
void mostrarListaDeDeseos(struct ListaDeseos *LDeseos, const char identificacion [], const char anno []);
void mostrarListaCartas(struct ListaCartas *LCartas);

	//  Funciones para Procesar las cartas
void procesarCartas(struct ListaCartas *LCartas, struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta, struct ListaAyudantes *LAyudantes, struct ListaComport *LComp);
void mostrarCartasPorAnno(struct ListaCartas *LCartas, struct ListaNinos *LNinos, const char anno []);
void obtenerNombre(struct ListaNinos *LNinos, const char id [], char *nombre);
void cambiarEstadoCarta(struct ListaCartas *LCartas, const char identificacion [], const char anno [], const char estado [], const char id_ayudante [] );
void obtenerEstadoCarta(struct ListaCartas *LCartas, const char id [], const char anno [], char *estado);

//Procedimientos para el Analisis de Datos
void juguetesPorAnno(struct ListaJugCarta *LJugCarta);
int obtenerDomicilio(struct ListaNinos *LNinos, const char identificacion [], char *domicilio);
void masMenosCartas(struct ListaCartas *LCartas, struct ListaNinos *LNinos);
void aprobadasPorAnno(struct ListaCartas *LCartas);
void rechazadasPorAnno(struct ListaCartas *LCartas);
void comportRegistrados(struct ListaComport *LComp);
void cartasPorAyudante(struct ListaCartas *LCartas);
void ordenarTopJuguetes(struct ListaJugSolicitados *TopJuguetes);
void juguetesMasPedidos(struct ListaJugCarta *LJugCarta);

//Procedimientos para Gestion de Domicilios y Rutas
void registrarDomicilio();
void registrarRuta();
Domicilio* validarDomicilio(const char nombre[]);
void agregarRuta(Domicilio* origen, Domicilio* destino, Ruta* nuevaRuta);
void visualizarGrafo();
int mostrarDomicilios();
void modificarDomicilio();
void modificarRuta();
void eliminarDomicilio();
void borrarRutas(const char lugar_Destino[]);
void eliminarRuta(); 
void insertarEnRecorrido(Domicilio* domicilio);
Domicilio *extraerLugar();
void reiniciarDomicilios();
void dijkstraTodos();
void registrarPoloNorte();

//Procedimientos para la Gestion de Entregas
void entregaTodos();
void entregaPorTipo();

struct Nino{
    char cedula[12];
	char nombre_completo[50];
    char nombre_usuario[20];
    char correo[50];
    char lugar_domicilio[20];
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

struct CartaSolicitada{
    char procesada_por[50];
    int cantidad;
    char domicilio[50];
    CartaSolicitada *siguiente; 
};

struct PilaCartas{
	CartaSolicitada *tope;
};

struct JugSolicitado{
    char nombre_juguete[50];
    char anno[50];
    int cantidad;
    JugSolicitado *siguiente; 
};

struct PilaJugSolicitados{
	JugSolicitado *tope;
};

struct ListaJugSolicitados{
	JugSolicitado *inicio;
	JugSolicitado *final;
};

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

struct Recorrido{
	Domicilio *nombre_lugar;
	Recorrido *siguiente;
};

/****************************************************************Menús de Opciones***********************************************************************************************/

Juguete *jugueteRaiz=NULL;
Domicilio *lugarInicial=NULL;
Recorrido *lugarPartida=NULL;
Recorrido *lugarLlegada=NULL;
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
	
	registrarPoloNorte();
	
	do{
        system( "CLS" );
        fflush(stdin);
        printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf("        Menu Principal\n" );
		printf("*********************************\n");
		printf( "\n 1 - Gestion de DOMICILIOS y RUTAS" );
		printf( "\n 2 - Gestion de NINOS(AS)" );
		printf( "\n 3 - Gestion de JUGUETES" );
	    printf( "\n 4 - Gestion de AYUDANTES DE SANTA" );	    
	    printf( "\n 5 - Gestion de CARTAS PARA SANTA" );
		printf( "\n 6 - ENTREGA de Juguetes" ); 
		printf( "\n 7 - Analisis de DATOS" );   
	    printf( "\n 8 - Salir" );
	    printf("\n\n<--Digite una opcion (1-8): ");
        opcion = getchar();
        
        switch ( opcion ){
            case '1': GestionDomicilios();
                break;
			case '2': GestionNinos(LNinos, LComp);
                break;
            case '3': GestionJuguetes(); 
                break;
			case '4': GestionAyudantes(LAyudantes);
                break;
            case '5': GestionCartas(LNinos, LJugCartas, LCartas, LDeseos, LAyudantes, LComp);
				break;
			case '6': GestionEntregas();
				break;
			case '7': AnalisisDeDatos(LJugCartas, LCartas, LComp, LNinos);
				break;
			case '8': exit(1);
				break;
            default:
            	fflush(stdin);
				printf("**Opcion no valida. Intente de nuevo.**\n");
				getchar();
                break;
        }
    } while (opcion!='8');    
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
		printf("\n 7. MOSTRAR domicilios y rutas");
		printf("\n\n<--Digite una opcion (0-6): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': registrarDomicilio();
					break;
				case '2': registrarRuta();
					break;
				case '3': modificarDomicilio();
					break;
				case '4': modificarRuta();
					break;
				case '5': eliminarDomicilio();
					break;
				case '6': eliminarRuta();
					break;
				case '7': visualizarGrafo();
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
void GestionCartas(struct ListaNinos *LNinos, struct ListaJugCarta *LJugCartas, struct ListaCartas *LCartas, struct ListaDeseos *LDeseos, struct ListaAyudantes *LAyudantes, struct ListaComport *LComp){
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
				case '4': procesarCartas(LCartas, LNinos, LJugCartas, LAyudantes, LComp);
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
	Salidas: 
	Restricciones: Solo se deben ingresar números en un rango de 0 a 3.
*/
void GestionEntregas(){
	char opcion, ch;	

	do{
		system( "CLS" );
		fflush(stdin);
		printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf("     Gestion de Entregas\n");
		printf("*********************************\n");
		printf("\n 0. REGRESAR al Menu Principal.");
		printf("\n 1. Entrega para TODOS las Rutas.");
		printf("\n 2. Entrega para un TIPO de Ruta.");
		printf("\n\n<--Digite una opcion (0-2): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': entregaTodos();
					break;
				case '2': entregaPorTipo();
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
void AnalisisDeDatos(struct ListaJugCarta *LJugCarta, struct ListaCartas *LCartas, struct ListaComport *LComp, struct ListaNinos *LNinos){
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
		printf("\n 1. Cantidad de juguetes solicitados por anno ");
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
				case '2': masMenosCartas(LCartas, LNinos);
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
    int resultado=0;

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
    
    resultado = mostrarDomicilios();
	if(resultado==0){
    	printf("\n\nPresione una tecla para regresar..." );
		getchar();
		return;
	}

	do{
		printf("\n-->Ingrese el Nombre del Lugar de Domicilio: \n");
    	gets(nino->lugar_domicilio);

	    if(validarDomicilio(nino->lugar_domicilio)==NULL){
	    	printf("\n**El nombre ingresado no corresponde con un Domicilio registrado**\n ");
		}else{
			break;
        }
        
    }while(1);
    
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
	int hallado=0, comp=3, resp, resultado=0;
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
                printf("  Domicilio: %s \n", iNino->lugar_domicilio);
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
                	resultado = mostrarDomicilios();
					if(resultado==0){
				    	printf("\n\nPresione una tecla para regresar..." );
						getchar();
						return;
					}
                		do{
							printf("\n-->Ingrese el Nombre del Lugar de Domicilio: \n");
					    	gets(domicilio);
					
						    if(validarDomicilio(domicilio)==NULL){
						    	printf("\n**El nombre ingresado no corresponde con un Domicilio registrado**\n ");
							}else{
								strcpy(iNino->lugar_domicilio,domicilio);
								break;
					        }
					        
					    }while(1);
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
		aux->izq = borrarJuguete(aux->izq, porBorrar);
	}
	else if(strcmp(aux->nombre, porBorrar) > 0 )
	{
		aux->der = borrarJuguete(aux->der, porBorrar);
	}
	else
	{
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
					jugueteRaiz = borrarJuguete(jugueteRaiz, nombreJuguete);
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
	    
	if (recorrer != NULL)
    {
        mostrarJuguetes(recorrer->izq);
		printf("       %s - %s - %s\n",recorrer->codigo, recorrer->nombre, recorrer->categoria);
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
	
	//Validar si ya fue registrada
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
				
				printf("\n+---------------------------------------------+\n");
				printf( "              Lista de Juguetes" );
				printf("\n+---------------------------------------------+\n");
				printf("        Codigo - Nombre  - Categoria ");
				printf("\n+---------------------------------------------+\n");
				mostrarJuguetes(jugueteRaiz);
				printf("\n+---------------------------------------------+\n");
						
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
     
	//Mostrar Carta y Lista de Desos resultante  
	mostrarCarta(LCartas, LJugCarta, carta->identificacion, carta->anno);
	mostrarListaDeDeseos(LDeseos, carta->identificacion, carta->anno);
	
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
        	
            mostrarCarta(LCartas, LJugCarta, identificacion, anno);
			mostrarListaDeDeseos(LDeseos, identificacion, anno);

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
						printf("\n+---------------------------------------------+\n");
						printf( "              Lista de Juguetes" );
						printf("\n+---------------------------------------------+\n");
						printf("        Codigo - Nombre  - Categoria ");
						printf("\n+---------------------------------------------+\n");
						mostrarJuguetes(jugueteRaiz);
						printf("\n+---------------------------------------------+\n");
														
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
        	
            mostrarCarta(LCartas, LJugCarta, identificacion, anno);
			mostrarListaDeDeseos(LDeseos, identificacion, anno);
			
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
	Entradas: Una lista de tipo ListaJugCarta  un char identificacion y otro Anno, para tomar los datos de los juguetes de una Carta para Santa 
	Salidas: Se muestran los datos de una Carta para Santa en caso de que exista, para el anno e identificación ingresados 
	Restricciones: Ninguna.
*/
void mostrarCarta(struct ListaCartas *LCartas, struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno []){

	struct JuguetesCarta *iJugCarta = LJugCarta->inicio;
	int registrados=0;
	
	char estado[30];
	
	obtenerEstadoCarta(LCartas, identificacion, anno, estado);
	
	printf("\n\n+-------------------------------------------------------------------+\n");
	printf( "                        CARTA PARA SANTA" );
	printf("\n+-------------------------------------------------------------------+\n");
	printf("\n  Identificacion: %s   -   Anno: %s   -   Estado: %s\n", identificacion, anno, estado);
	printf("\n+-------------------------------------------------------------------+\n");
	
	if(LJugCarta->inicio!=NULL)
	{
        int cont=1;
        printf(" Nombre del juguete     -    Estado del Juguete\n" ); 

        while(iJugCarta!=NULL){
            if(strcmp(iJugCarta->identificacion, identificacion)==0 && strcmp(iJugCarta->anno,anno)==0){
            	printf("\n %s     -      %s  \n" , iJugCarta->nombre_juguete, iJugCarta->estado);
            	registrados=1;
			}	
            iJugCarta = iJugCarta->siguiente;
            
        }		
		if(registrados==0){
			printf( "\n***No se han encontrado Juguetes registrados en la Carta para Santa***");
		}
	}else{
		printf( "\n***No se han encontrado Juguetes registrados en la Carta para Santa***");		
	}
	printf("\n+-------------------------------------------------------------------+\n");
		

}

/*
	Entradas: Una lista de tipo ListaDeseos, un char identificacion y otro Anno, para tomar los datos de los juguetes de una lista de deseos
	Salidas: Se muestran los datos de una Lista de Deseos en caso de que exista, para el anno e identificación ingresados 
	Restricciones: Ninguna.
*/
void mostrarListaDeDeseos(struct ListaDeseos *LDeseos, const char identificacion [], const char anno []){

	int registrados=0;
		
	struct Deseo *iJugDeseo = LDeseos->inicio;
	
	printf("\n+-------------------------------------------------------------------+\n");
	printf( "                        LISTA DE DESEOS" );
	printf("\n+-------------------------------------------------------------------+\n");
	
	if(LDeseos->inicio!=NULL)
	{
        int cont=1;
        printf(" Nombre del juguete \n" ); 

        while(iJugDeseo!=NULL){
            if(strcmp(iJugDeseo->identificacion, identificacion)==0 && strcmp(iJugDeseo->anno,anno)==0){
            	printf("\n %s   \n" , iJugDeseo->nombre_juguete);
            	registrados=1;
			}
            iJugDeseo = iJugDeseo->siguiente;
        }
        
        if(registrados==0){
			printf( "\n***No se han encontrado Juguetes registrados en la Lista de Deseos***");
		}	
				
		
	}else{
		printf( "\n***No se han encontrado Juguetes registrados en la Lista de Deseos***");
		
	}
	printf("\n+-------------------------------------------------------------------+\n");
	
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

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void mostrarCartasPorAnno(struct ListaCartas *LCartas, struct ListaNinos *LNinos, const char anno []){

	struct Carta *iCarta = LCartas->inicio;
	
	char nombre[50];
	
	printf("\n+---------------------------------------+\n");
	printf( "       CARTAS PARA SANTA REGISTRADAS\n" );
	printf( "              ANNO: %s\n",  anno);
	printf("+---------------------------------------+\n");
		
	if(LCartas->inicio!=NULL)
	{
		printf("\n  Identificacion  -  Nombre  -  Estado: \n");
        while(iCarta!=NULL){
            if(strcmp(iCarta->anno, anno)==0 && strcmp(iCarta->estado, "Solicitada")==0){
            	printf("\n %s  -   ", iCarta->identificacion);
            	obtenerNombre(LNinos, iCarta->identificacion ,nombre);
            	printf("%s  -   ", nombre);
            	printf("%s\n", iCarta->estado);
            	
			}
            iCarta = iCarta->siguiente;
        }		
		
	}else{
		printf( "\n***No se han encontrado Cartas para Santa registradas***");
	}
	
	printf("\n+---------------------------------------+\n");
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void obtenerNombre(struct ListaNinos *LNinos, const char id [], char *nombre){

	struct Nino *iNino;
	int hallado=0, comp=3;
	
    if(LNinos->inicio!=NULL)
	{
        iNino = LNinos->inicio;
        while(iNino!=NULL){
            
            comp=strcmp(id,iNino->cedula);
            if(comp==0){
            	
            	strcpy(nombre, iNino->nombre_completo);
            	   
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
}


/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void obtenerEstadoCarta(struct ListaCartas *LCartas, const char id [], const char anno [], char *estado){

	struct Carta *iCarta;	
	int hallado=0;
	
    if(LCartas->inicio!=NULL)
	{
        iCarta = LCartas->inicio;
        while(iCarta!=NULL){

            if(strcmp(id,iCarta->identificacion)==0 && strcmp(anno,iCarta->anno)==0){
            	
            	strcpy(estado, iCarta->estado);
            	   
                hallado=1;
				break;
			}
			iCarta = iCarta->siguiente;

        }
        
		if(hallado==0){
			printf( "\n***No se ha encontrado una Cartas para Santa con la informacion ingresada***");
		}
		
	}else{
		printf( "\n***No se han encontrado Cartas para Santa registrados***");
	}
}


/*
	Entradas: Una lista de tipo ListaComport para tomar los datos de comportamiento de un Nino/Nina
	Salidas: Se muestran los datos un nodo de tipo Comportamiento de la lista recibida.
	Restricciones: Ninguna.
*/
int validarComp(struct ListaComport *LComp, const char identificacion []){

	struct Comportamiento *iComp;
	int contador=0, comp=3;
	
	printf("\n\n+-------------------------------------------------------------------+\n");
	printf( "                    Validacion de Comportamiento" );
	printf("\n\n+-------------------------------------------------------------------+\n");
	
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
	
	if(contador>=1){
		printf( "\n***El nino(a) tiene 6 o MAS comportamiento MALOS***");
		printf("\n\n+-------------------------------------------------------------------+\n");
		return 1;
	}else{
		printf( "\n-->El nino(a) tiene MENOS de 6 comportamiento MALOS");
		printf("\n\n+-------------------------------------------------------------------+\n");
		return 0;
	}

}


/*
	Entradas:  
	Salidas: 
	Restricciones: Ninguna.
*/
void procesarCartas(struct ListaCartas *LCartas, struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta, 
					struct ListaAyudantes *LAyudantes, struct ListaComport *LComp){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Procesar una Carta para Santa\n" );
	printf("*********************************\n");
	
	struct JuguetesCarta *iJugCarta ;
	char identificacion[20], anno[10], id_ayudante[50], opcion[3];
	int res=0;
	
	if(LCartas->inicio==NULL){
		printf( "\n***No se han encontrado Cartas para Santa registradas***");
	}else if (LAyudantes->inicio==NULL){
		printf( "\n***No se han encontrado Ayudantes de Santa registrados***");
	}else{
		
		//Mostrar lista de niños que registraron una carta (con Identificación y nombre)
		printf("\n-->Ingrese el Anno que corresponda consultar:\n");
		gets(anno);
		
		mostrarCartasPorAnno(LCartas, LNinos, anno);
		
		do{ //Solicitar identificacion del niño
			printf("\n-->Ingrese el numero de Identificacion del Nino(a): (Ej. 105450656) \n");
			gets(identificacion);
			
			if(validarCarta(LCartas, identificacion, anno)!=1){
			    printf("\n**No se tiene registrada una carta para la identificación y anno ingresados**\n ");
			}else{//Mostrar detalle de la carta para ese año e identificación
			    mostrarCarta(LCartas, LJugCarta, identificacion, anno);
				break;
			}
		
		}while(1);

		do{ //Registrar los datos de Ayudante que proceso la carta

			printf("\n Ingrese la Identificacion del Ayudante de Santa: (Ejm.105450656) \n");
			gets(id_ayudante);
		
	        if((validarIdentificacion(LAyudantes, id_ayudante ))!=1){
	            printf("\n**No se tiene un Ayudante registrado con la Identificacion ingresada**\n ");
	        }else{
	            break;
	        }
	        
	    }while(1);
	    
	    res=validarComp(LComp,identificacion);
	    
	    if(res==1){ //+ de 6 malos comportamientos
	    	//Cambiar estado Carta = Cancelada 
	    	cambiarEstadoCarta(LCartas, identificacion, anno, "Cancelada", id_ayudante);
	    	
	    	//Rechazar todos los Juguetes
	    	iJugCarta = LJugCarta->inicio;
			int registrados=0;

			if(LJugCarta->inicio!=NULL)
			{
		        
		        while(iJugCarta!=NULL){
		            if(strcmp(iJugCarta->identificacion, identificacion)==0 && strcmp(iJugCarta->anno,anno)==0){
						registrados=1;					
						
						strcpy(iJugCarta->estado, "Rechazado"); 
					}	
		            iJugCarta = iJugCarta->siguiente;
		            
		        }		
				if(registrados==0){
					printf( "\n***No se han encontrado Juguetes registrados en la Carta para Santa***");
				}
			}else{
				printf( "\n***No se han encontrado Juguetes registrados en la Carta para Santa***");		
			}
			
	    	//Enviar Correo
	    	
		}else{ //- de 6 malos comportamientos 
			
			//Consultar por cada juguete
			iJugCarta = LJugCarta->inicio;
			int registrados=0;

			if(LJugCarta->inicio!=NULL)
			{
		        
		        while(iJugCarta!=NULL){
		            if(strcmp(iJugCarta->identificacion, identificacion)==0 && strcmp(iJugCarta->anno,anno)==0){
		            	printf("\nNombre del juguete: %s   -   Estado del Juguete: %s\n" , iJugCarta->nombre_juguete, iJugCarta->estado ); 
						
						registrados=1;
						
						do{ 
							printf("\n-->Desea Aprobar este juguete?:");
					    	printf("\nDigite 1-Si"); 
							printf("\n       2-No\n<--");
							gets(opcion);
							
							if(strcmp(opcion ,"1")==0){
			            		strcpy(iJugCarta->estado, "Listo para entregar"); 
			            		printf("\n   -->Juguete listo para entregar" );
			            		break;
							}else if(strcmp(opcion ,"2")==0){
								strcpy(iJugCarta->estado, "Rechazado"); 
								printf("\n   -->Juguete rechazado\n " );
								break;
							}else{
								printf("\n   **Opción no valida**\n ");
							}

					    }while(1);
						printf("\n\n+-------------------------------------------------------------------+\n");
					}	
		            iJugCarta = iJugCarta->siguiente;

		        }		
				if(registrados==0){
					printf( "\n***No se han encontrado Juguetes registrados en la Carta para Santa***");
				}
			}else{
				printf( "\n***No se han encontrado Juguetes registrados en la Carta para Santa***");		
			}
			
			//Cambiar estado Carta = Procesada 
			cambiarEstadoCarta(LCartas, identificacion, anno, "Procesada", id_ayudante);
			
		}
		
		printf("\n+++ Carta procesada correctamente +++" );
			
	}
		
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas:  
	Salidas: 
	Restricciones: Ninguna.
*/
void cambiarEstadoCarta(struct ListaCartas *LCartas, const char identificacion [], const char anno [], const char estado [], const char id_ayudante [] ){
	struct Carta *iCarta = LCartas->inicio;
	
	if(LCartas->inicio!=NULL)
	{
        while(iCarta!=NULL){
            if(strcmp(iCarta->identificacion, identificacion)==0 && strcmp(iCarta->anno,anno)==0){			
				
				strcpy(iCarta->estado, estado); 
				strcpy(iCarta->procesada_por, id_ayudante); 
				
				break;
			}
			iCarta = iCarta->siguiente;
        }		
		
	}else{
		printf( "\n***No se han encontrado Cartas para Santa registradas***");
	}
	
}


/****************************************************************Gestion de Domicilios y Rutas ************************************************************************************/

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
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

    printf("\n-->Ingrese el Codigo para el Domicilio: \n");
    gets(nuevo->codigo);
    
    printf("\n-->Ingrese el Codigo Postal: \n");
    gets(nuevo->codigo_postal);
	
	nuevo->siguiente=NULL;
    nuevo->adyacencia=NULL;
    nuevo->visitado=nuevo->terminado=0;
    nuevo->monto=-1;
    strcpy(nuevo->anterior, "0");
    
	if(lugarInicial==NULL){
        lugarInicial=nuevo;
    }else{
        aux=lugarInicial;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
    }
    
    printf("\n+++ Informacion registrada correctamente +++\n" );
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
Domicilio* validarDomicilio(const char nombre[]){
	
	Domicilio* iDomicilio=lugarInicial;

    while(iDomicilio!=NULL){
        if(strcmp(iDomicilio->nombre_lugar,nombre)==0){
            break;
        }
        iDomicilio = iDomicilio->siguiente;
    }
    
    return iDomicilio;
} 

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/ 
void registrarRuta(){   
    system( "CLS" );
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
	
    if(lugarInicial==NULL){
         printf( "\n***No se han encontrado Domicilios registrados***");
         return;
    }
    
    fflush(stdin);
    
	//Agregar Origen
    do{
    	printf("\n-->Ingrese el Lugar de ORIGEN:  \n");
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
	
    printf("\n-->Ingrese el tipo de ruta (T->terrestre, A->aerea o M->maritima): \n");
    gets(nuevaRuta->tipo_ruta);  
    printf("\n-->Ingrese la Distancia entre ambos lugares (en km): \n");
    gets(nuevaRuta->distancia);  
    printf("\n-->Ingresar la Duracion de la Ruta (en minutos): \n");
    gets(nuevaRuta->tiempo_estimado);  
	
    agregarRuta(origen,destino,nuevaRuta);
    	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}


/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
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

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void modificarDomicilio(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("   Modificar Info. Domicilios\n" );
	printf("*********************************\n");
	
	Domicilio* domicilio=lugarInicial->siguiente;
	char lugar[50], codigo[30], postal[30], respuesta[2];
	int resp=0, hallado=0; 
	
	if(domicilio!=NULL){
		printf("\n Ingrese el nombre del lugar: \n ");
    	gets(lugar);
    	
		while(domicilio!=NULL){   

	        if(strcmp(lugar,domicilio->nombre_lugar)==0){
            	printf("\n+------------------------------------+");
				printf("\n      Datos del Lugar " );
            	printf("\n+------------------------------------+");
                printf("\n  Codigo: %s \n", domicilio->codigo);
                printf("  Nombre del Lugar:  %s \n", domicilio->nombre_lugar);
                printf("  Codigo Postal: %s \n", domicilio->codigo_postal);
                printf("+-------------------------------------+\n");
                
                do{
			        printf("\nDesea modificar el Codigo del Lugar? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese el valor para el Codigo: (Ej. DOM-001) \n");
			    	gets(codigo);	
					strcpy(domicilio->codigo,codigo);
				}
				
				do{
			        printf("\nDesea modificar el Codigo Postal? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese el valor para el Codigo Postal: \n");
			    	gets(postal);	
					strcpy(domicilio->codigo_postal,postal);
				}
   
                hallado=1;
				break;
			}
			
			domicilio=domicilio->siguiente;
	    }
	    
	    if(hallado==0){
			printf( "\n***No se ha encontrado un Lugar para el nombre ingresado***");
		}
	}else{
		printf("\n ***No se han encontrado Domicilios registrados***");
	}
		
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void modificarRuta(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("     Modificar Info. Rutas\n" );
	printf("*********************************\n");
	
	struct Ruta *iRuta;
	char lugar_origen[50], lugar_destino[50], tipo_ruta[30], tiempo_estimado[30], distancia[30], respuesta[2];
	int resp=0, domHallado=0, rutaHallado=0; 
		
	printf("\n-->Ingrese el Lugar de ORIGEN:  \n");
    gets(lugar_origen);
    printf("\n-->Ingrese el Lugar de DESTINO \n");
    gets(lugar_destino);
    printf("\n-->Ingrese el tipo de ruta (T->terrestre, A->aerea o M->maritima): \n");
    gets(tipo_ruta);
	
    Domicilio* iDomicilio = lugarInicial;
    
    if(lugarInicial!=NULL){
    	Domicilio* iDomicilio = lugarInicial;
    	
    	while(iDomicilio!=NULL){  
    
		    if(strcmp(iDomicilio->nombre_lugar,lugar_origen)==0){
				domHallado=1;
		    	if(iDomicilio->adyacencia!=NULL){
					
					iRuta = iDomicilio->adyacencia;

		    		while(iRuta !=NULL){

						if (strcmp(iRuta->lugar->nombre_lugar,lugar_destino)==0 && strcmp(iRuta->tipo_ruta,tipo_ruta)==0){
							printf("\n+------------------------------------+");
							printf("\n      Datos de la Ruta " );
			            	printf("\n+------------------------------------+");
			                printf("\n  Origen: %s\n", iDomicilio->nombre_lugar);
			                printf("  Destino:  %s\n", iRuta->lugar->nombre_lugar);
			                printf("  Duracion: %s\n",iRuta->tiempo_estimado);
			                printf("  Distancia: %s\n",iRuta->distancia);
			                printf("  Tipo de Ruta: %s\n", iRuta->tipo_ruta);
			                printf("+-------------------------------------+\n");
			                
			                do{
					        printf("\nDesea modificar el Tiempo Estimado? (1-Si 2-No)\n" );
		                	gets(respuesta);
							resp=atoi(respuesta);
		                
					        if(resp==1 || resp==2){
					            break;
					        }
		    				}while(1);
	        
			                if(resp==1){
			                	printf("\n-->Ingrese el tiempo estimado (en minutos) del recorrido :\n");
				    			gets(iRuta->tiempo_estimado);	
							}
							
							do{
						        printf("\nDesea modificar la Distancia? (1-Si 2-No)\n" );
			                	gets(respuesta);
								resp=atoi(respuesta);
			                
						        if(resp==1 || resp==2){
						            break;
						        }
						    }while(1);
			                
			                if(resp==1){
			                	printf("\n-->Ingrese la Distancia entre ambos lugares (en km): \n");
				    			gets(iRuta->distancia);	
							}     
			                rutaHallado=1;
							break;
						}
					iRuta=iRuta->siguiente;
			        }
					if(rutaHallado==0){
						printf( "\n***No se ha encontrado una Ruta con los datos ingresados***");
					}
				}
			}
    	iDomicilio=iDomicilio->siguiente;
		}
	}else{
		printf("*** NO hay Domicilios registrados***");
	}
	if(domHallado==0){
		printf( "\n***No se ha encontrado una Ruta con los datos ingresados***");
	}	
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void eliminarDomicilio(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Eliminar Info. de un Domiclio\n" );
	printf("*********************************\n");
	
	struct Domicilio *domicilio=lugarInicial->siguiente, *anterior;
	int hallado=0, comp=3;
	char lugar[50], opcion[3]; 
	
	if(domicilio!=NULL){
		printf("\n Ingrese el nombre del lugar: \n ");
    	gets(lugar);
    	
		while(domicilio!=NULL){   

	        if(strcmp(lugar,domicilio->nombre_lugar)==0){
            	printf("\n+------------------------------------+");
				printf("\n      Datos del Lugar " );
            	printf("\n+------------------------------------+");
                printf("\n  Codigo: %s \n", domicilio->codigo);
                printf("  Nombre del Lugar:  %s \n", domicilio->nombre_lugar);
                printf("  Codigo Postal: %s \n", domicilio->codigo_postal);
                printf("+-------------------------------------+\n");
                
                printf("\n-->Desea eliminar este domicilio?:\n");
		    	printf("<--Digite 1-SI, 2-NO: \n");
				gets(opcion);
				
				//Cancelar Eliminado
				if (strcmp(opcion ,"2")==0){
					hallado=1;
					break;			
				}
		
				//**Eliminar Domicilio** 
				if (strcmp(opcion ,"1")==0){
			        if(domicilio==lugarInicial)
					{
						if(domicilio->siguiente==NULL)
						{
							free(domicilio);
							lugarInicial=NULL;
						}else{
							lugarInicial=domicilio->siguiente;
							free(domicilio);
						}				
					}
					else 
					{
						
						anterior->siguiente = domicilio->siguiente;
						free(domicilio);
						
						
			
					}
					printf("\n-->Se ha eliminado el Domicilio con el nombre ingresado");
				}

				borrarRutas(lugar);
				hallado=1;
				break;
			}
			
			anterior=domicilio;
			domicilio=domicilio->siguiente;
	    }
	    
	    if(hallado==0){
			printf( "\n***No se ha encontrado un Domicilio para el nombre ingresado***");
		}

		
	}else{
		printf("\n ***No se han encontrado Domicilios registrados***");
	}
		
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	

}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void borrarRutas(const char lugar_Destino[]){
	struct Ruta *iRuta, *rutaAnterior;;
	Domicilio* iDomicilio = lugarInicial;
	while(iDomicilio!=NULL){  
		if(iDomicilio->adyacencia!=NULL){
			iRuta = iDomicilio->adyacencia;
			while(iRuta!=NULL){
				if(strcmp(iRuta->lugar->nombre_lugar,lugar_Destino)==0){
					if(iRuta==iDomicilio->adyacencia)
					{
						if(iRuta->siguiente==NULL)
						{
							free(iRuta);
							iDomicilio->adyacencia=NULL;
						}else{
							iDomicilio->adyacencia=iRuta->siguiente;
							free(iRuta);
						}				
					}
					else 
					{
						rutaAnterior->siguiente = iRuta->siguiente;
						free(iRuta);
			
					}
				}   	
			rutaAnterior=iRuta;
			iRuta=iRuta->siguiente;
	        }
		}
	iDomicilio=iDomicilio->siguiente;
	}
	
	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void eliminarRuta(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Eliminar Info. de una Ruta\n" );
	printf("*********************************\n");
	
	struct Ruta *iRuta, *rutaAnterior;
	char lugar_origen[50], lugar_destino[50], tipo_ruta[30], tiempo_estimado[30], distancia[30], respuesta[2];
	int resp=0, domHallado=0, rutaHallado=0; 
		
	printf("\n-->Ingrese el Lugar de ORIGEN:  \n");
    gets(lugar_origen);
    printf("\n-->Ingrese el Lugar de DESTINO \n");
    gets(lugar_destino);
    printf("\n-->Ingrese el tipo de ruta (terrestre, aerea o maritima): \n");
    gets(tipo_ruta);
	
    Domicilio* iDomicilio = lugarInicial;
    
    if(lugarInicial!=NULL){
    	Domicilio* iDomicilio = lugarInicial;
    	
    	while(iDomicilio!=NULL){  
    
		    if(strcmp(iDomicilio->nombre_lugar,lugar_origen)==0){
				domHallado=1;
		    	if(iDomicilio->adyacencia!=NULL){
					
					iRuta = iDomicilio->adyacencia;

		    		while(iRuta !=NULL){

						if (strcmp(iRuta->lugar->nombre_lugar,lugar_destino)==0 && strcmp(iRuta->tipo_ruta,tipo_ruta)==0){
							printf("\n+------------------------------------+");
							printf("\n      Datos de la Ruta " );
			            	printf("\n+------------------------------------+");
			                printf("\n  Origen: %s\n", iDomicilio->nombre_lugar);
			                printf("  Destino:  %s\n", iRuta->lugar->nombre_lugar);
			                printf("  Duracion: %s\n",iRuta->tiempo_estimado);
			                printf("  Distancia: %s\n",iRuta->distancia);
			                printf("  Tipo de Ruta: %s\n", iRuta->tipo_ruta);
			                printf("+-------------------------------------+\n");
			                
			                do{
					        printf("\nDesea Eliminar esta ruta? (1-Si 2-No)\n" );
		                	gets(respuesta);
							resp=atoi(respuesta);
		                
					        if(resp==1 || resp==2){
					            break;
					        }
		    				}while(1);
	        
			                if(resp==1){              	
						        if(iRuta==iDomicilio->adyacencia)
								{
									if(iRuta->siguiente==NULL)
									{
										free(iRuta);
										iDomicilio->adyacencia=NULL;
									}else{
										iDomicilio->adyacencia=iRuta->siguiente;
										free(iRuta);
									}				
								}
								else 
								{
									
									rutaAnterior->siguiente = iRuta->siguiente;
									free(iRuta);
						
								}
								printf("\n-->Se ha eliminado la Ruta con los datos ingresados");	
							}

			                rutaHallado=1;
							break;
						}
					rutaAnterior=iRuta;
					iRuta=iRuta->siguiente;
			        }
					if(rutaHallado==0){
						printf( "\n***No se ha encontrado una Ruta con los datos ingresados***");
					}
				}
			}
    	iDomicilio=iDomicilio->siguiente;
		}
	}else{
		printf("*** NO hay Domicilios registrados***");
	}
	if(domHallado==0){
		printf( "\n***No se ha encontrado una Ruta con los datos ingresados***");
	}	
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
		
	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
int mostrarDomicilios(){

	Domicilio* iDomicilio=lugarInicial->siguiente;

    printf("\n+---------------------------------------------+\n");
	printf( "              Lista de Domicilios" );
	printf("\n+---------------------------------------------+\n");
	printf("        Codigo - Lugar  - Codigo Postal ");
	printf("\n+---------------------------------------------+\n");
	
	if(iDomicilio!=NULL){
		while(iDomicilio!=NULL){   
		    printf("        %s - %s - %s \n",iDomicilio->codigo, iDomicilio->nombre_lugar, iDomicilio->codigo_postal);
	        iDomicilio=iDomicilio->siguiente;
	    }
	}else{
		printf("\n ***No se han encontrado Domicilios registrados***");
		printf("\n+---------------------------------------------+\n");
		return 0;
	}
	
	printf("\n+---------------------------------------------+\n");
	return 1;

}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void visualizarGrafo(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("***********************************\n");
	printf("  Lista de Rutas entre Domicilios\n" );
	printf("***********************************\n");
    Domicilio* iDomicilio=lugarInicial;
    
    Ruta* iRuta;
    
    if (iDomicilio != NULL){
    	printf("Origen  ->  Destino ( tipo , duracion)\n");  
    while(iDomicilio!=NULL){   
	    printf("%s-> ",iDomicilio->nombre_lugar);
       
	    if(iDomicilio->adyacencia!=NULL){
            iRuta=iDomicilio->adyacencia;
            
			while(iRuta!=NULL){ 
			    printf(" %s( %s, %s )",iRuta->lugar->nombre_lugar, iRuta->tipo_ruta, iRuta->tiempo_estimado);
                iRuta=iRuta->siguiente;
            }
        }

        printf("\n");
        iDomicilio=iDomicilio->siguiente;
    }
    printf("\n");
	}else{
		printf("***No hay Domicilios registrados***");
	}
    
    
    
    printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void registrarPoloNorte(){
	Domicilio* poloNorte=(Domicilio*)malloc(sizeof(Domicilio));

    strcpy(poloNorte->codigo, "001");
    strcpy(poloNorte->codigo_postal, "H0H0H0");
	strcpy(poloNorte->nombre_lugar, "Polo Norte");
	poloNorte->siguiente=NULL;
    poloNorte->adyacencia=NULL;
    poloNorte->visitado=0;
	poloNorte->terminado=0;
    poloNorte->monto=-1;
    strcpy(poloNorte->anterior, "0");
    
	lugarInicial=poloNorte;
	
}

/**************************************************************** Gestion de Entregas  ***********************************************************************************************/

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void entregaTodos(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("   Entrega a Todas las Rutas\n" );
	printf("*********************************\n");
	
	while(lugarLlegada!=NULL){

		dijkstraTodos();
		iDomicilio=iDomicilio->siguiente;
	}
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void entregaPorTipo(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("   Entrega a Por Tipo de Ruta\n" );
	printf("*********************************\n");
}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void insertarEnRecorrido(Domicilio* domicilio){
	Recorrido *nuevo=(Recorrido*)malloc(sizeof(Recorrido));
	nuevo->nombre_lugar=domicilio;
	nuevo->siguiente=NULL;
	if(lugarPartida==NULL){
		lugarPartida=nuevo;
		lugarLlegada=nuevo;
	}else{
	   nuevo->siguiente=lugarPartida;
	   lugarPartida=nuevo;    	
	}
}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
Domicilio *extraerLugar(){
	Recorrido *aux;
	
	if(lugarPartida==NULL){
		return NULL;
	}else{
		aux=lugarPartida;
		lugarPartida=lugarPartida->siguiente;
		aux->siguiente=NULL;
		if(lugarPartida==NULL)
			lugarLlegada=NULL;
	}
	
	Domicilio *resultado=aux->nombre_lugar;
	free(aux);
	
	return resultado;
}

/*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void reiniciarDomicilios(){
	if(lugarInicial!=NULL){
		Domicilio *aux= lugarInicial;
		while(aux!=NULL){
			aux->visitado=aux->terminado=0;
		    aux=aux->siguiente;
		}
	}
}
 
 /*
	Entradas: 
	Salidas: 
	Restricciones: Ninguna.
*/
void dijkstraTodos(char destino[50]){
	
	Domicilio *iDomicilio = lugarInicial;
	char origen[50] = "Polo Norte";

	while(iDomicilio!=NULL){

		if(strcmp(iDomicilio->nombre_lugar, origen)==0){
			iDomicilio->terminado=1;
			iDomicilio->monto=0;
			break;
		}
		iDomicilio=iDomicilio->siguiente;
	}
	if(iDomicilio==NULL){
		printf("***Domicilio no encontrado***\n");
		return;
	}
	while(iDomicilio!=NULL){

		Ruta *iRuta=iDomicilio->adyacencia;
	    
		while(iRuta!=NULL){

		    if(iRuta->lugar->monto==-1 || (iDomicilio->monto+atoi(iRuta->tiempo_estimado))<iRuta->lugar->monto){
		    	iRuta->lugar->monto=iDomicilio->monto+atoi(iRuta->tiempo_estimado);
		    	strcpy(iRuta->lugar->anterior, iDomicilio->nombre_lugar);
			}
		    iRuta=iRuta->siguiente;
	    }
	    
	    iDomicilio=lugarInicial;
	    
	    Domicilio *masCorto = lugarInicial;
	    
	    while(masCorto->anterior==0 || masCorto->terminado ==1){
	 
	    	masCorto=masCorto->siguiente;
		}
	    	
	    
		while(iDomicilio!=NULL){
		
	    	if(iDomicilio->monto<masCorto->monto && iDomicilio->terminado==0 && strcmp(iDomicilio->anterior, "0")!=0)
	    		masCorto=iDomicilio;
	    	iDomicilio=iDomicilio->siguiente;
		}
		
		iDomicilio=masCorto;
		iDomicilio->terminado=1;
		
		if(strcmp(iDomicilio->nombre_lugar,destino)==0)
			break;
	}
	while(strcmp(iDomicilio->anterior, "0")!=0){

		
		insertarEnRecorrido(iDomicilio);
		
		char temp[50];
		strcpy(temp, iDomicilio->anterior);

		iDomicilio=lugarInicial;
		while(strcmp(iDomicilio->nombre_lugar, temp)!=0){

		   iDomicilio=iDomicilio->siguiente;	
		}
	}
	
	
	printf("\n-->Entregando Juguetes en... %s", destino);

	printf("\n-->Recorrido:-->", origen, destino);
	insertarEnRecorrido(iDomicilio);
	while(lugarLlegada!=NULL){

		printf("%s ",extraerLugar()->nombre_lugar);
	}
	printf("\n");
	
	printf("\nIdentificación del Nino(a):");
	while(lugarLlegada!=NULL){

		printf("\n %s ", ->identficacion);
		iDomicilio=iDomicilio->siguiente;
	}
		
	reiniciarDomicilios();
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
	
	
	struct JuguetesCarta *iJugCarta;
	struct JugSolicitado *iJugSolicitado, *nJugSolicitado;
	
	struct PilaJugSolicitados *JugSolic;
	JugSolic = (struct PilaJugSolicitados *) malloc(sizeof(struct PilaJugSolicitados));
	JugSolic->tope = NULL;
	
	int hallado=0;

    //Conteo de las Juguetes Solicitados	
	if(LJugCarta->inicio!=NULL)
	{
        iJugCarta = LJugCarta->inicio;
		while( iJugCarta!= NULL){
			
			if(JugSolic->tope==NULL)
			{
				nJugSolicitado =(struct JugSolicitado *) malloc (sizeof(struct JugSolicitado));
					
				strcpy(nJugSolicitado->anno, iJugCarta->anno);
				nJugSolicitado->cantidad = 1;
				
				nJugSolicitado->siguiente = JugSolic->tope;
				JugSolic->tope = nJugSolicitado;
			}else{
				for(iJugSolicitado = JugSolic->tope; iJugSolicitado!= NULL; iJugSolicitado = iJugSolicitado->siguiente){
				
					if(strcmp(iJugCarta->anno,iJugSolicitado->anno)==0){
						iJugSolicitado->cantidad = iJugSolicitado->cantidad+1;
					hallado=1;
					break;
					}
				}
				
				if(hallado!=1){
					nJugSolicitado =(struct JugSolicitado *) malloc (sizeof(struct JugSolicitado));
						
					strcpy(nJugSolicitado->anno, iJugCarta->anno);
					nJugSolicitado->cantidad = 1;
					
					nJugSolicitado->siguiente = JugSolic->tope;
					JugSolic->tope = nJugSolicitado;

				}
				hallado=0;
			}
						
			iJugCarta = iJugCarta->siguiente;
		}
		
		//Mostrar cantidades contadas
		printf("\n+----------------------------------------+\n");
		printf( "  Anno del juguete    -   Cant. Solicitudes" );
		printf("\n+----------------------------------------+\n");
		
		iJugSolicitado = JugSolic->tope;
			
		if(JugSolic->tope!=NULL)
		{
	        while(iJugSolicitado!=NULL){
	            printf("\n         %s   -   %d", iJugSolicitado->anno, iJugSolicitado->cantidad);
	            iJugSolicitado = iJugSolicitado->siguiente;
	        }		
			
		}else{
			printf( "\n***No se han encontrado juguetes***");
		}
				
		
	}else{
		printf( "\n***No se han encontrado juguetes***");
	}
	
	
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
int obtenerDomicilio(struct ListaNinos *LNinos, const char identificacion [], char *domicilio){

    struct Nino *i= LNinos->inicio;
    int comp=3;

    if(LNinos->inicio!=NULL)
    {
        while( i!= NULL){
			comp=strcmp(identificacion,i->cedula);
	        if(comp==0)
			{
                strcpy(domicilio, i->lugar_domicilio);
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
void masMenosCartas(struct ListaCartas *LCartas, struct ListaNinos *LNinos){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Lugares con Mas/Menos cartas\n" );
	printf("*********************************\n");
		
	struct Carta *iCarta = LCartas->inicio;
	struct Nino *iNino = LNinos->inicio;
	struct CartaSolicitada *iCartaSolic, *nCartaSolic;
	struct PilaCartas *PCartas;
	PCartas = (struct PilaCartas *) malloc(sizeof(struct PilaCartas));
	PCartas->tope = NULL;
	
	char domicilio[50];
	int resultado=0, hallado=0, mayor=0, menor=0;
		
	//Conteo de las Cartas Procesadas	
	if(LCartas->inicio!=NULL)
	{
        iCarta = LCartas->inicio;
		while( iCarta!= NULL){
		
			resultado=obtenerDomicilio(LNinos, iCarta->identificacion, domicilio);
			
			if(resultado==1){
				if(PCartas->tope==NULL)
				{
					nCartaSolic =(struct CartaSolicitada *) malloc (sizeof(struct CartaSolicitada));
										
					strcpy(nCartaSolic->domicilio, domicilio);
					nCartaSolic->cantidad = 1;
					
					nCartaSolic->siguiente = PCartas->tope;
					PCartas->tope = nCartaSolic;
					
				}else{	
					for(iCartaSolic = PCartas->tope; iCartaSolic!= NULL; iCartaSolic = iCartaSolic->siguiente){
						
						if(strcmp(domicilio,iCartaSolic->domicilio)==0){
							iCartaSolic->cantidad = (iCartaSolic->cantidad)+1;
							hallado=1;
							break;
						}
					}		
					
					if(hallado!=1){
						nCartaSolic =(struct CartaSolicitada *) malloc (sizeof(struct CartaSolicitada));
						
						strcpy(nCartaSolic->domicilio, domicilio);
						nCartaSolic->cantidad = 1;
						
						nCartaSolic->siguiente = PCartas->tope;
						PCartas->tope = nCartaSolic;
	
					}
					
					hallado=0;
	
				}
			}
			
			iCarta = iCarta->siguiente;
		}
		
		//Obtener Mayor
		strcpy(domicilio,PCartas->tope->domicilio);
		mayor=PCartas->tope->cantidad; 
		for(iCartaSolic = PCartas->tope; iCartaSolic!= NULL; iCartaSolic = iCartaSolic->siguiente){
	
			if(iCartaSolic->cantidad>mayor){
				strcpy(domicilio, iCartaSolic->domicilio);
				mayor=iCartaSolic->cantidad;
				break;
			}
		} 
		
		printf("+-----------------------------------------+\n");
		printf( " -->Lugar con MAS Cartas: %s", domicilio);
		printf( "\n    -->Total de Cartas: %d", mayor);
		printf("\n+-----------------------------------------+\n");
		
		//Obtener Menor
		strcpy(domicilio,PCartas->tope->domicilio);
		menor=PCartas->tope->cantidad; 
		for(iCartaSolic = PCartas->tope; iCartaSolic!= NULL; iCartaSolic = iCartaSolic->siguiente){
	
			if(iCartaSolic->cantidad<menor){
				strcpy(domicilio, iCartaSolic->domicilio);
				menor=iCartaSolic->cantidad;
				break;
			}
		} 
		
		printf( " -->Lugar con MENOS Cartas: %s", domicilio );
		printf( "\n    -->Total de Cartas: %d", menor );
		printf("\n+-----------------------------------------+\n");
	
	}else{
		printf( "\n***No se han encontrado Cartas registradas***");
	}	
	
	
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
	
	
	struct Carta *iJugCarta;
	struct JugSolicitado *iJugSolicitado, *nJugSolicitado;
	
	struct PilaJugSolicitados *JugSolic;
	JugSolic = (struct PilaJugSolicitados *) malloc(sizeof(struct PilaJugSolicitados));
	JugSolic->tope = NULL;
	
	int hallado=0;

    //Conteo de las Juguetes Solicitados	
	if(LCartas->inicio!=NULL)
	{
        iJugCarta = LCartas->inicio;
		while( iJugCarta!= NULL){
			
			if(JugSolic->tope==NULL)
			{
				nJugSolicitado =(struct JugSolicitado *) malloc (sizeof(struct JugSolicitado));
					
				strcpy(nJugSolicitado->anno, iJugCarta->anno);
				if (strcmp(iJugCarta->estado,"Procesada")==0)
					nJugSolicitado->cantidad = 1;
				
				nJugSolicitado->siguiente = JugSolic->tope;
				JugSolic->tope = nJugSolicitado;
			}else{
				for(iJugSolicitado = JugSolic->tope; iJugSolicitado!= NULL; iJugSolicitado = iJugSolicitado->siguiente){
				
					if(strcmp(iJugCarta->anno,iJugSolicitado->anno)==0){
						if (strcmp(iJugCarta->estado,"Procesada")==0)
							iJugSolicitado->cantidad = iJugSolicitado->cantidad+1;
						hallado=1;
						break;	
					}
				}
				
				if(hallado!=1){
					nJugSolicitado =(struct JugSolicitado *) malloc (sizeof(struct JugSolicitado));
						
					strcpy(nJugSolicitado->anno, iJugCarta->anno);
					if (strcmp(iJugCarta->estado,"Procesada")==0)
						nJugSolicitado->cantidad = 1;
					
					nJugSolicitado->siguiente = JugSolic->tope;
					JugSolic->tope = nJugSolicitado;

				}
				hallado=0;
			}
						
			iJugCarta = iJugCarta->siguiente;
		}
		
		//Mostrar cantidades contadas
		printf("\n+----------------------------------------+\n");
		printf( "  Anno de la Carta    -   Cant. Aprobadas" );
		printf("\n+----------------------------------------+\n");
		
		iJugSolicitado = JugSolic->tope;
			
		if(JugSolic->tope!=NULL)
		{
	        while(iJugSolicitado!=NULL){
	            printf("\n         %s   -   %d", iJugSolicitado->anno, iJugSolicitado->cantidad);
	            iJugSolicitado = iJugSolicitado->siguiente;
	        }		
			
		}else{
			printf( "\n***No se han encontrado Cartas***");
		}
				
		
	}else{
		printf( "\n***No se han encontrado Cartas***");
	}
	
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
	
	struct Carta *iJugCarta;
	struct JugSolicitado *iJugSolicitado, *nJugSolicitado;
	
	struct PilaJugSolicitados *JugSolic;
	JugSolic = (struct PilaJugSolicitados *) malloc(sizeof(struct PilaJugSolicitados));
	JugSolic->tope = NULL;
	
	int hallado=0;

    //Conteo de las Juguetes Solicitados	
	if(LCartas->inicio!=NULL)
	{
        iJugCarta = LCartas->inicio;
		while( iJugCarta!= NULL){
			
			if(JugSolic->tope==NULL)
			{
				nJugSolicitado =(struct JugSolicitado *) malloc (sizeof(struct JugSolicitado));
					
				strcpy(nJugSolicitado->anno, iJugCarta->anno);
				if (strcmp(iJugCarta->estado,"Cancelada")==0)
					nJugSolicitado->cantidad = 1;
				
				nJugSolicitado->siguiente = JugSolic->tope;
				JugSolic->tope = nJugSolicitado;
			}else{
				for(iJugSolicitado = JugSolic->tope; iJugSolicitado!= NULL; iJugSolicitado = iJugSolicitado->siguiente){
				
					if(strcmp(iJugCarta->anno,iJugSolicitado->anno)==0){
						if (strcmp(iJugCarta->estado,"Cancelada")==0)
							iJugSolicitado->cantidad = iJugSolicitado->cantidad+1;
						hallado=1;
						break;
					}
					
				}
				
				if(hallado!=1){
					nJugSolicitado =(struct JugSolicitado *) malloc (sizeof(struct JugSolicitado));
						
					strcpy(nJugSolicitado->anno, iJugCarta->anno);
					if (strcmp(iJugCarta->estado,"Cancelada")==0)
						nJugSolicitado->cantidad = 1;
					
					nJugSolicitado->siguiente = JugSolic->tope;
					JugSolic->tope = nJugSolicitado;

				}
				hallado=0;
			}
						
			iJugCarta = iJugCarta->siguiente;
		}
		
		//Mostrar cantidades contadas
		printf("\n+----------------------------------------+\n");
		printf( "  Anno de la Carta    -   Cant. Rechazadas" );
		printf("\n+----------------------------------------+\n");
		
		iJugSolicitado = JugSolic->tope;
			
		if(JugSolic->tope!=NULL)
		{
	        while(iJugSolicitado!=NULL){
	            printf("\n         %s   -   %d", iJugSolicitado->anno, iJugSolicitado->cantidad);
	            iJugSolicitado = iJugSolicitado->siguiente;
	        }		
			
		}else{
			printf( "\n***No se han encontrado Cartas***");
		}
				
		
	}else{
		printf( "\n***No se han encontrado Cartas***");
	}
	
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

		printf("+-----------------------------------------+\n");
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
	printf(" Cartas procesadas segun Ayudante\n" );
	printf("*********************************\n");
		
	struct Carta *iCarta = LCartas->inicio;
	struct CartaSolicitada *iCartaProc, *nCartaProc;
	struct PilaCartas *CProc;
	CProc = (struct PilaCartas *) malloc(sizeof(struct PilaCartas));
	CProc->tope = NULL;
	
	int hallado=0;
		
	//Conteo de las Cartas Procesadas	
	if(LCartas->inicio!=NULL)
	{
        iCarta = LCartas->inicio;
		while( iCarta!= NULL){
		
			if(CProc->tope==NULL)
			{
				nCartaProc =(struct CartaSolicitada *) malloc (sizeof(struct CartaSolicitada));
						
				strcpy(nCartaProc->procesada_por, iCarta->procesada_por);
				nCartaProc->cantidad = 1;
				
				nCartaProc->siguiente = CProc->tope;
				CProc->tope = nCartaProc;
				
			}else{	
				for(iCartaProc = CProc->tope; iCartaProc!= NULL; iCartaProc = iCartaProc->siguiente){
					
					if(strcmp(iCarta->procesada_por,iCartaProc->procesada_por)==0){
						iCartaProc->cantidad = iCartaProc->cantidad+1;
						hallado=1;
						break;
					}
					
				}
				if(hallado!=1){
					nCartaProc =(struct CartaSolicitada *) malloc (sizeof(struct CartaSolicitada));
					
					strcpy(nCartaProc->procesada_por, iCarta->procesada_por);
					nCartaProc->cantidad = 1;
					
					nCartaProc->siguiente = CProc->tope;
					CProc->tope = nCartaProc;

				}
				hallado=0;
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
	            printf("\n   %s   -   %d", iCartaProc->procesada_por, iCartaProc->cantidad);
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
void ordenarTopJuguetes(struct ListaJugSolicitados *TopJuguetes){

	struct JugSolicitado *i, *j, *temp;

	i = TopJuguetes->inicio;
	while( i->siguiente!= NULL){
		j = i->siguiente;
		while( j!= NULL){
			
			if(i->cantidad < j->cantidad){
				
				//Guardar los valores del nodo i
				temp->cantidad = i->cantidad;
				strcpy(temp->nombre_juguete,i->nombre_juguete);
				
				//Asignar los valores del nodo j al nodo i
				i->cantidad = j->cantidad;			
				strcpy(temp->nombre_juguete,i->nombre_juguete);
				
				//Asignar los valores guardados del nodo i al nodo j
				j->cantidad = temp->cantidad;
				strcpy(temp->nombre_juguete,i->nombre_juguete);
				
			}			
			j = j->siguiente;
		}
		i = i->siguiente;
	}
	
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
	printf(" Top 10 Juguetes mas solicitados\n" );
	printf("*********************************\n");
	
	struct JuguetesCarta *iJugCarta;
	struct JugSolicitado *iJugSolicitado, *nJugSolicitado;
	
	struct ListaJugSolicitados *TopJuguetes;
	TopJuguetes = (struct ListaJugSolicitados *) malloc(sizeof(struct ListaJugSolicitados));
	TopJuguetes->inicio = NULL;
	TopJuguetes->final = NULL;
	int hallado=0;

    //Conteo de las Juguetes Solicitados	
	if(LJugCarta->inicio!=NULL)
	{
        iJugCarta = LJugCarta->inicio;
		while( iJugCarta!= NULL){
			if(TopJuguetes->inicio==NULL)
			{
				nJugSolicitado = (struct JugSolicitado *) malloc (sizeof(struct JugSolicitado));
					
				strcpy(nJugSolicitado->nombre_juguete, iJugCarta->nombre_juguete);
				nJugSolicitado->cantidad = 1;
				
				TopJuguetes->inicio = nJugSolicitado;
				TopJuguetes->final = nJugSolicitado;
			}else{

				for(iJugSolicitado = TopJuguetes->inicio; iJugSolicitado!= NULL; iJugSolicitado = iJugSolicitado->siguiente){

					if(strcmp(iJugCarta->nombre_juguete,iJugSolicitado->nombre_juguete)==0){
						iJugSolicitado->cantidad = (iJugSolicitado->cantidad)+1;
						hallado=1;
						break;
					}	
				}
				
				if(hallado==0){
					nJugSolicitado =(struct JugSolicitado *) malloc (sizeof(struct JugSolicitado));
					
					strcpy(nJugSolicitado->nombre_juguete, iJugCarta->nombre_juguete);
					nJugSolicitado->cantidad = 1;
					
					if(TopJuguetes->inicio == NULL) 
					{
						TopJuguetes->inicio = nJugSolicitado;
						TopJuguetes->final = nJugSolicitado;
					}else{
						TopJuguetes->final->siguiente = nJugSolicitado;
						TopJuguetes->final = TopJuguetes->final->siguiente;
					}

				}else{
					hallado=0;
				}
			}
			
			
			iJugCarta = iJugCarta->siguiente;
		}
				
		ordenarTopJuguetes(TopJuguetes);
		
		//Mostrar cantidades contadas
		printf("\n+------------------------------------------+\n");
		printf( "  Nombre del Juguete   -  Cant. Solicitudes" );
		printf("\n+------------------------------------------+\n");
		
		iJugSolicitado = TopJuguetes->inicio;
		int cont=0;
		if(TopJuguetes->inicio!=NULL)
		{
	        while(iJugSolicitado!=NULL){
	            printf("\n     %s   -   %d", iJugSolicitado->nombre_juguete, iJugSolicitado->cantidad);
	            iJugSolicitado = iJugSolicitado->siguiente;
	            cont++;
	            
	            if(cont==10){
	            	break;
				}
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


