/*Algoritmos y Estructuras de Datos - Grupo 1
	Proyecto Programado 2 
	Estudiantes: Jose Altamirano Salazar - 2020426159
	             Josu� Brenes Alfaro - 2020054427
*/
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Archivos\EnviarCorreo\Mail.h" 

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

typedef struct CartaEntregable CartaEntregable;
typedef struct ListaEntregables ListaEntregables;
typedef struct LugPorVisitar LugPorVisitar;
typedef struct ListaPorVisitar ListaPorVisitar;

//Procedimientos para Menus de Opciones
void MenuPrincipal();
void GestionNinos();
void GestionJuguetes();
void GestionDomicilios();
void GestionAyudantes();
void GestionCartas();
void GestionEntregas();
void AnalisisDeDatos();

void cargarValores();
int cargarNinos(struct ListaNinos *LNinos);
int cargarJugCarta(struct ListaJugCarta *LJugCarta);
int cargarCartas(struct ListaCartas *LCartas);
int cargarDeseos(struct ListaDeseos *LDeseos);
int cargarComp(struct ListaComport *LComp);
int cargarAyudantes(struct ListaAyudantes *LAyudantes);
void insertarJuguete(struct Juguete *nuevo );
int cargarJuguetes();

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
void guardarJuguetes();
void escribirJuguete(struct Juguete *iJuguete, FILE *ArchJuguetes);

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
void enviarCorreo(struct ListaNinos *LNinos, const char identificacion []);

//Procedimientos para el Analisis de Datos
void juguetesPorAnno(struct ListaJugCarta *LJugCarta);
int obtenerDomicilio(struct ListaNinos *LNinos, const char identificacion [], char *domicilio);
int contarJuguetesPorCarta(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno []);
void masMenosJuguetes(struct ListaCartas *LCartas, struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta);
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

//Procedimientos para la Gestion de Entregas
void entregaTodos(struct ListaCartas *LCartas, struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta);
void entregaPorTipo();
void insertarEnRecorrido(Domicilio* domicilio);
Domicilio *extraerLugar();
void reiniciarDomicilios();
void dijkstraTodos(struct ListaEntregables *LEntregables, const char destino[50]);
void dijkstraPorTipo(struct ListaEntregables *LEntregables, const char destino[50], const char tipo[10]);
void registrarPoloNorte();
void obtenerEntregables(struct ListaCartas *LCartas, struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta, struct ListaPorVisitar *LPorVisitar, struct ListaEntregables *LEntregables );
int validarJugParaEntregar( struct ListaJugCarta *LJugCarta,const char identificacion[],const char anno[]);
void agregarLugarPorVisitar(struct ListaPorVisitar *LPorVisitar, const char domicilio[]);

//Funciones para persistencia de datos
void guardarNinos(struct ListaNinos *LNinos);
void guardarComportamiento(struct ListaComport *LComp);
void guardarAyudantes(struct ListaAyudantes *LAyudantes);
void guardarJugCarta(struct ListaJugCarta *LJugCarta);
void guardarDeseo(struct ListaDeseos *LDeseos);
void guardarCartas(struct ListaCartas *LCartas);
void guardarDomiciliosYRutas();

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
};

struct Recorrido{
	Domicilio *nombre_lugar;
	Recorrido *siguiente;
};

struct CartaEntregable{
	char identificacion[50];
	char domicilio[50];
	char anno[50];
	CartaEntregable *siguiente;
};

struct ListaEntregables{
	CartaEntregable *inicio;
	CartaEntregable *final;
};

struct LugPorVisitar{
	char nombre_Lugar[50];
	LugPorVisitar *siguiente;
};

struct ListaPorVisitar{
	int contador;
	LugPorVisitar *inicio;
	LugPorVisitar *final;
};

/****************************************************************Punteros a Listas y Valores Iniciales***********************************************************************************************/

Juguete *jugueteRaiz=NULL;
Domicilio *lugarInicial=NULL;
Recorrido *lugarPartida=NULL;
Recorrido *lugarLlegada=NULL;
ListaNinos *LNinos;
ListaComport *LComp;
ListaAyudantes *LAyudantes;
ListaCartas *LCartas;
ListaJugCarta *LJugCarta;
ListaDeseos *LDeseos;

/*
	Entradas: Ninguna
	Salidas: Invoca a las funciones que obtiene los valores de las listas, arbol y grafo registrados en los archivos de texto
	Restricciones: Ninguna.
*/
void cargarValores(){
	char opcion;
	int resultado;

	//Obtener valores de Lista de Ninos
	LNinos = (struct ListaNinos *) malloc(sizeof(struct ListaNinos));
	LNinos->inicio = NULL;
	LNinos->final = NULL;
	resultado = cargarNinos(LNinos);
	
	//Obtener valores de Lista de Comportamientos
	LComp = (struct ListaComport *) malloc(sizeof(struct ListaComport));
	LComp->inicio = NULL;
	LComp->final = NULL;
	resultado = cargarComp(LComp);
	
	//Obtener valores de Lista de Ayudante
	LAyudantes = (struct ListaAyudantes *) malloc(sizeof(struct ListaAyudantes));
	LAyudantes->inicio = NULL;
	LAyudantes->final = NULL;
	resultado = cargarAyudantes(LAyudantes);
		
	//Obtener valores de Lista de Cartas
	LCartas = (struct ListaCartas *) malloc(sizeof(struct ListaCartas));
	LCartas->inicio = NULL;
	LCartas->final = NULL;
	resultado = cargarCartas(LCartas);
	
	//Obtener valores de Lista de Juguetes por Carta
	LJugCarta = (struct ListaJugCarta *) malloc(sizeof(struct ListaJugCarta));
	LJugCarta->inicio = NULL;
	LJugCarta->final = NULL;
	resultado = cargarJugCarta(LJugCarta);
	
	//Obtener valores de Lista de Deseos
	LDeseos = (struct ListaDeseos *) malloc(sizeof(struct ListaDeseos));
	LDeseos->inicio = NULL;
	LDeseos->final = NULL;
	resultado = cargarDeseos(LDeseos);
	
	cargarJuguetes();
	
	cargarDomicilios();
	
	if(lugarInicial==NULL){
		registrarPoloNorte();
	}else{
		cargarRutas();
	}
		
}

/*
    Entradas: Una cadena de caracteres.
    Salidas: La cadena de caracteres recibida, sustituyendo el valor de los campos con un salto de linea (\n) por un caracter nulo.
    Restricciones: El parametro debe corresponder con el tipo cadena de caracteres.
*/
void borrarSaltoLinea(char linea[]){
    int i;
    for(i=0; linea[i]!='\0'; i++){
        if(linea[i] == '\n'){
            linea[i]='\0';
            break;
        }
    }
}


/*
    Entradas: Un puntero a una lista del tipo ListaNinos.
    Salidas: Una lista  enlazada con los diferentes valores de la estructura.
    Restricciones: Ninguna.
*/
int cargarNinos(struct ListaNinos *LNinos){

    FILE* ArchNinos;

    struct Nino *aux;

    char linea [256];
    int numLectura=0;

    ArchNinos = fopen("Archivos\\ArchNinos.txt","r");

    if(ArchNinos==NULL){
        return 0;
    }else{
    	while(fgets(linea, 256, (FILE *) ArchNinos)){
	    	if(numLectura == 0){
				aux =(struct Nino *) malloc (sizeof(struct Nino));
				strcpy(aux->cedula,linea);
				borrarSaltoLinea(aux->cedula);
				numLectura++;
				
			}else if(numLectura == 1){
				strcpy(aux->nombre_completo,linea);
				borrarSaltoLinea(aux->nombre_completo);
				numLectura++;
				
			}else if(numLectura == 2){
				strcpy(aux->nombre_usuario,linea);
				borrarSaltoLinea(aux->nombre_usuario);
				numLectura++;
				
			}else if(numLectura == 3){
				strcpy(aux->correo,linea);
				borrarSaltoLinea(aux->correo);
				numLectura++;
				
			}else if(numLectura == 4){
				strcpy(aux->lugar_domicilio,linea);
				borrarSaltoLinea(aux->lugar_domicilio);
				numLectura++;
				
			}else if(numLectura == 5){
				strcpy(aux->fecha_nacimiento,linea);
				borrarSaltoLinea(aux->fecha_nacimiento);
				numLectura++;
				
			}else if(numLectura == 6){
				strcpy(aux->edad,linea);
				borrarSaltoLinea(aux->edad);
				numLectura++;
				
			}else{
				strcpy(aux->necesidades_esp,linea);
				borrarSaltoLinea(aux->necesidades_esp);
				
				if(LNinos->inicio == NULL) 
	            {
	                //Inserta al inicio de la lista
	                LNinos->inicio = aux;
	                LNinos->inicio->siguiente = NULL; 
	                LNinos->final = LNinos->inicio;
	
	            }else{
	                //Inserta al final de la lista
	                LNinos->final->siguiente = aux; 
	                LNinos->final->siguiente->siguiente = NULL; 
	                LNinos->final = LNinos->final->siguiente;
	            }	
				numLectura = 0;
			}
	    }
        fclose(ArchNinos);
    }
    return 1;
}

/*
    Entradas: Un puntero a una lista del tipo ListaJugCarta.
    Salidas: Una lista enlazada con los diferentes valores de la estructura.
    Restricciones: Ninguna.
*/
int cargarJugCarta(struct ListaJugCarta *LJugCarta){

    FILE* ArchJugCarta;

    struct JuguetesCarta *aux;

    char linea [256];
    int numLectura=0;

    ArchJugCarta = fopen("Archivos\\ArchJugCarta.txt","r");

    if(ArchJugCarta==NULL){
        return 0;
    }else{
    	while(fgets(linea, 256, (FILE *) ArchJugCarta)){
	    	if(numLectura == 0){
				aux =(struct JuguetesCarta *) malloc (sizeof(struct JuguetesCarta));
				strcpy(aux->identificacion,linea);
				borrarSaltoLinea(aux->identificacion);
				numLectura++;
				
			}else if(numLectura == 1){
				strcpy(aux->anno,linea);
				borrarSaltoLinea(aux->anno);
				numLectura++;
				
			}else if(numLectura == 2){
				strcpy(aux->nombre_juguete,linea);
				borrarSaltoLinea(aux->nombre_juguete);
				numLectura++;
				
			}else{
				strcpy(aux->estado,linea);
				borrarSaltoLinea(aux->estado);
				
				if(LJugCarta->inicio == NULL) 
	            {
	                //Inserta al inicio de la lista
	                LJugCarta->inicio = aux;
	                LJugCarta->inicio->siguiente = NULL; 
	                LJugCarta->final = LJugCarta->inicio;
	
	            }else{
	                //Inserta al final de la lista
	                LJugCarta->final->siguiente = aux; 
	                LJugCarta->final->siguiente->siguiente = NULL; 
	                LJugCarta->final = LJugCarta->final->siguiente;
	            } 	
				numLectura = 0;
			}
	    }
        fclose(ArchJugCarta);
    }
    return 1;

}

/*
    Entradas: Un puntero a una lista del tipo ListaCartas.
    Salidas: Una lista enlazada con los diferentes valores de la estructura.
    Restricciones: Ninguna.
*/
int cargarCartas(struct ListaCartas *LCartas){

    FILE* ArchCartas;

    struct Carta *aux;
    char linea [256];
    int numLectura=0;

    ArchCartas = fopen("Archivos\\ArchCartas.txt","r");

    if(ArchCartas==NULL){
        return 0;
    }else{
    	while(fgets(linea, 256, (FILE *) ArchCartas)){
	    	if(numLectura == 0){
				aux =(struct Carta *) malloc (sizeof(struct Carta));
				strcpy(aux->identificacion,linea);
				borrarSaltoLinea(aux->identificacion);
				numLectura++;
			}else if(numLectura == 1){
				strcpy(aux->anno,linea);
				borrarSaltoLinea(aux->anno);
				numLectura++;
			}else if(numLectura == 2){
				strcpy(aux->estado,linea);
				borrarSaltoLinea(aux->estado);
				numLectura++;
			}else{
				strcpy(aux->procesada_por,linea);
				borrarSaltoLinea(aux->procesada_por);
				
				if(LCartas->inicio == NULL) 
	            {
	                //Inserta al inicio de la lista
	                LCartas->inicio = aux;
	                LCartas->inicio->siguiente = NULL; 
	                LCartas->final = LCartas->inicio;
	
	            }else{
	                //Inserta al final de la lista
	                LCartas->final->siguiente = aux; 
	                LCartas->final->siguiente->siguiente = NULL; 
	                LCartas->final = LCartas->final->siguiente;
	            }	
				numLectura = 0;
			}
	    }
        fclose(ArchCartas);
    }
    return 1;

}

/*
    Entradas: Un puntero a una lista del tipo ListaDeseos.
    Salidas: Una lista enlazada con los diferentes valores de la estructura.
    Restricciones: Ninguna.
*/
int cargarDeseos(struct ListaDeseos *LDeseos){

    FILE* ArchDeseos;

    struct Deseo *aux;

    char linea [256];
    int numLectura=0;

    ArchDeseos = fopen("Archivos\\ArchDeseos.txt","r");

    if(ArchDeseos==NULL){
        return 0;
    }else{
    	while(fgets(linea, 256, (FILE *) ArchDeseos)){
	    	if(numLectura == 0){
				aux =(struct Deseo *) malloc (sizeof(struct Deseo));
				strcpy(aux->identificacion,linea);
				borrarSaltoLinea(aux->identificacion);
				numLectura++;
				
			}else if(numLectura == 1){
				strcpy(aux->anno,linea);
				borrarSaltoLinea(aux->anno);
				numLectura++;
				
			}else{
				strcpy(aux->nombre_juguete,linea);
				borrarSaltoLinea(aux->nombre_juguete);
				
				if(LDeseos->inicio == NULL) 
	            {
	                //Inserta al inicio de la lista
	                LDeseos->inicio = aux;
	                LDeseos->inicio->siguiente = NULL; 
	                LDeseos->final = LDeseos->inicio;
	
	            }else{
	                //Inserta al final de la lista
	                LDeseos->final->siguiente = aux; 
	                LDeseos->final->siguiente->siguiente = NULL; 
	                LDeseos->final = LDeseos->final->siguiente;
	            }	
				numLectura = 0;
			}
	    }
        fclose(ArchDeseos);
    }
    return 1;

}


/*
    Entradas: Un puntero a una lista del tipo ListaComport.
    Salidas: Una lista  enlazada con los diferentes valores de la estructura.
    Restricciones: Ninguna.
*/
int cargarComp(struct ListaComport *LComp){

    FILE* ArchComp;

    struct Comportamiento *aux;

    char linea [256];
    int numLectura=0;

    ArchComp = fopen("Archivos\\ArchComp.txt","r");

    if(ArchComp==NULL){
        return 0;
    }else{
    	while(fgets(linea, 256, (FILE *) ArchComp)){
	    	if(numLectura == 0){
				aux =(struct Comportamiento *) malloc (sizeof(struct Comportamiento));
				strcpy(aux->cedula_nino,linea);
				borrarSaltoLinea(aux->cedula_nino);
				numLectura++;
				
			}else if(numLectura == 1){
				strcpy(aux->descripcion,linea);
				borrarSaltoLinea(aux->descripcion);
				numLectura++;
				
			}else if(numLectura == 2){
				strcpy(aux->fecha_registro,linea);
				borrarSaltoLinea(aux->fecha_registro);
				numLectura++;
				
			}else if(numLectura == 3){
				strcpy(aux->indicacion,linea);
				borrarSaltoLinea(aux->indicacion);
				numLectura++;
				
			}else{
				strcpy(aux->nombre_padre_madre,linea);
				borrarSaltoLinea(aux->nombre_padre_madre);
				
				if(LComp->inicio == NULL) 
	            {
	                //Inserta al inicio de la lista
	                LComp->inicio = aux;
	                LComp->inicio->siguiente = NULL; 
	                LComp->final = LComp->inicio;
	
	            }else{
	                //Inserta al final de la lista
	                LComp->final->siguiente = aux; 
	                LComp->final->siguiente->siguiente = NULL; 
	                LComp->final = LComp->final->siguiente;
	            }	
				numLectura = 0;
			}
	    }
        fclose(ArchComp);
    }
    return 1;

}

/*
    Entradas: Un puntero a una lista del tipo ListaAyudantes.
    Salidas: Una lista  enlazada con los diferentes valores de la estructura.
    Restricciones: Ninguna.
*/
int cargarAyudantes(struct ListaAyudantes *LAyudantes){

    FILE* ArchAyudantes;

    struct AydanteSanta *aux;
    char linea [256];
    int numLectura=0;

    ArchAyudantes = fopen("Archivos\\ArchAyudantes.txt","r");

    if(ArchAyudantes==NULL){
        return 0;
    }else{
    	while(fgets(linea, 256, (FILE *) ArchAyudantes)){
	    	if(numLectura == 0){
				aux =(struct AydanteSanta *) malloc (sizeof(struct AydanteSanta));
				strcpy(aux->identificacion,linea);
				borrarSaltoLinea(aux->identificacion);
				numLectura++;
			}else if(numLectura == 1){
				strcpy(aux->nombre,linea);
				borrarSaltoLinea(aux->nombre);
				numLectura++;
			}else if(numLectura == 2){
				strcpy(aux->puesto,linea);
				borrarSaltoLinea(aux->puesto);
				numLectura++;
			}else if(numLectura == 3){
				strcpy(aux->funcionPuesto,linea);
				borrarSaltoLinea(aux->funcionPuesto);
				numLectura++;
			}else{
				strcpy(aux->fechaComienzo,linea);
				borrarSaltoLinea(aux->fechaComienzo);
				if(LAyudantes->inicio == NULL) 
	            {
	                //Inserta al inicio de la lista
	                LAyudantes->inicio = aux;
	                LAyudantes->inicio->siguiente = NULL; 
	                LAyudantes->final = LAyudantes->inicio;
	
	            }else{
	                //Inserta al final de la lista
	                LAyudantes->final->siguiente = aux; 
	                LAyudantes->final->siguiente->siguiente = NULL; 
	                LAyudantes->final = LAyudantes->final->siguiente;
	            } 	
				numLectura = 0;
			}
	    }
        fclose(ArchAyudantes);
    }
    return 1;

}


/*
    Entradas: Un puntero a un tipo Juguete
    Salidas: Se a�ade el objeto recibido al Arbol Binario de Juguetes
    Restricciones: Ninguna.
*/
void insertarJuguete(struct Juguete *nuevo ){
         
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

}

/*
    Entradas: Un puntero a una lista del tipo ListaAyudantes.
    Salidas: Una lista  enlazada con los diferentes valores de la estructura.
    Restricciones: Ninguna.
*/
int cargarJuguetes(){

    FILE* ArchJuguetes;

    struct Juguete *aux;
    char linea [256];
    int numLectura=0;
        
	ArchJuguetes = fopen("Archivos\\ArchJuguetes.txt","r");

    if(ArchJuguetes==NULL){
        return 0;
    }else{
    	while(fgets(linea, 256, (FILE *) ArchJuguetes)){
	    	if(numLectura == 0){
				aux = (struct Juguete *) malloc (sizeof(struct Juguete));
				strcpy(aux->codigo,linea);
				borrarSaltoLinea(aux->codigo);
				numLectura++;
			}else if(numLectura == 1){
				strcpy(aux->nombre,linea);
				borrarSaltoLinea(aux->nombre);
				numLectura++;
			}else if(numLectura == 2){
				strcpy(aux->descripcion,linea);
				borrarSaltoLinea(aux->descripcion);
				numLectura++;
			}else if(numLectura == 3){
				strcpy(aux->categoria,linea);
				borrarSaltoLinea(aux->categoria);
				numLectura++;
			}else if(numLectura == 4){
				strcpy(aux->rango_edad,linea);
				borrarSaltoLinea(aux->rango_edad);
				numLectura++;
			}else{
				strcpy(aux->costo_fabricacion,linea);
				borrarSaltoLinea(aux->costo_fabricacion);
				insertarJuguete(aux);  	
				numLectura = 0;
			}
	    }
           
        fclose(ArchJuguetes);
    }
    return 1;

}

/*
    Entradas: Ninguna
    Salidas: Se cargan los valores de los domicilios registrados a la lista.
    Restricciones: Ninguna.
*/
int cargarDomicilios(){
	Domicilio* aux;
	Domicilio* aux2;
	
	char buffer[20], linea [256];
    int numLectura=0;

	FILE* ArchDomicilios;

    if(aux!=NULL)
	{	
		ArchDomicilios=fopen("Archivos\\ArchDomicilios.txt","a+");
			
		if(ArchDomicilios==NULL){
			return 0;	
		}else{
	    	while(fgets(linea, 256, (FILE *) ArchDomicilios)){
		    	if(numLectura == 0){
					aux =(struct Domicilio *) malloc (sizeof(struct Domicilio));
					strcpy(aux->codigo,linea);
					borrarSaltoLinea(aux->codigo);
					numLectura++;
					
				}else if(numLectura == 1){
					strcpy(aux->nombre_lugar,linea);
					borrarSaltoLinea(aux->nombre_lugar);
					numLectura++;
					
				}else if(numLectura == 2){
					strcpy(aux->codigo_postal,linea);
					borrarSaltoLinea(aux->codigo_postal);
					numLectura++;
					
				}else if(numLectura == 3){
					borrarSaltoLinea(linea);
					aux->visitado=atoi(linea);
					numLectura++;
					
				}else if(numLectura == 4){
					borrarSaltoLinea(linea);
					aux->terminado=atoi(linea);
					numLectura++;
				
				}else if(numLectura == 5){
					borrarSaltoLinea(linea);
					aux->monto=atoi(linea);
					numLectura++;
					
				}else{
					strcpy(aux->anterior,linea);
					borrarSaltoLinea(aux->anterior);
					
					aux->siguiente=NULL;
				    aux->adyacencia=NULL;
				    if(lugarInicial==NULL){
				        lugarInicial=aux;
				    }else{
				        aux2=lugarInicial;
				        while(aux2->siguiente!=NULL){
				            aux2=aux2->siguiente;
				        }
				        aux2->siguiente=aux;
				    }	
					numLectura = 0;
				}
		    }
		}	
		fclose(ArchDomicilios);		
	}else{
		return 0;
	}
	return 1;
}

/*
    Entradas: Ninguna.
    Salidas: Se agregan los valores de las rutas a los domicilios registrados.
    Restricciones: Ninguna.
*/
int cargarRutas(){

    FILE* ArchRutas;

	struct Domicilio *origen, *destino;
	struct Ruta *aux;
    char linea [256], lugar_origen[50], lugar_destino[50];
    int numLectura=0;

    ArchRutas = fopen("Archivos\\ArchRutas.txt","r");

    if(ArchRutas==NULL){
        return 0;
    }else{
    	while(fgets(linea, 256, (FILE *) ArchRutas)){
	    	if(numLectura == 0){
				aux =(struct Ruta *) malloc (sizeof(struct Ruta));
				strcpy(lugar_origen, linea);
				borrarSaltoLinea(lugar_origen);
				numLectura++;
			}else if(numLectura == 1){
				strcpy(lugar_destino,linea);
				borrarSaltoLinea(lugar_destino);
				numLectura++;
			}else if(numLectura == 2){
				strcpy(aux->tiempo_estimado,linea);
				borrarSaltoLinea(aux->tiempo_estimado);
				numLectura++;
			}else if(numLectura == 3){
				strcpy(aux->distancia,linea);
				borrarSaltoLinea(aux->distancia);
				numLectura++;
			}else{
				strcpy(aux->tipo_ruta,linea);
				borrarSaltoLinea(aux->tipo_ruta);
				
				origen = validarDomicilio(lugar_origen);
				destino = validarDomicilio(lugar_destino);
				aux->siguiente = NULL;
				
				if(origen!=NULL && destino!=NULL){
					agregarRuta(origen, destino, aux);
				}

				numLectura = 0;
			}
	    }
        fclose(ArchRutas);
    }
    return 1;

}

/****************************************************************Men�s de Opciones***********************************************************************************************/
/*
	Entradas: Un n�mero (tipo char) en un rango de 0 a 7 para escoger una de las opciones disponibles en el men�. 
	Salidas: Llamada a las dem�s funciones de men�s.
	Restricciones: Solo se deben ingresar n�meros en un rango de 0 a 7.
*/
void MenuPrincipal(){
	char opcion;
	
	cargarValores();
	
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
            case '5': GestionCartas(LNinos, LJugCarta, LCartas, LDeseos, LAyudantes, LComp);
				break;
			case '6': GestionEntregas(LCartas, LNinos, LJugCarta);
				break;
			case '7': AnalisisDeDatos(LJugCarta, LCartas, LComp, LNinos);
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
	Entradas: Un n�mero (tipo char) en un rango de 0 a 4 para escoger una de las opciones disponibles en el men�. 
	Salidas: Llamada a las dem�s funciones para la gesti�n de de Ninos (registro, modificaci�n, borrado de ni�os, 
			 y registro de comportamiento)
	Restricciones: Solo se deben ingresar n�meros en un rango de 0 a 4.
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
				case '5': mostrarComp(LComp);
						  getchar();
					break;
				case '6': mostrarNinos(LNinos);
						  getchar();
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
	Entradas: Un n�mero (tipo char) en un rango de 0 a 4 para escoger una de las opciones disponibles en el men�. 
	Salidas: Llamada a las dem�s funciones para la gesti�n de de Juguetes (registro, modificaci�n, borrado, 
			 y entrega de juguetes)
	Restricciones: Solo se deben ingresar n�meros en un rango de 0 a 4.
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
				case '4': mostrarJuguetes(jugueteRaiz);
						  getchar();
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
	Entradas: Un n�mero (tipo char) en un rango de 0 a 6 para escoger una de las opciones disponibles en el men�. 
	Salidas: Llamada a las dem�s funciones para la gesti�n de Domicilios y Rutas (registro, modificaci�n, borrado 
			 de Domicilios, y registro, modificaci�n, borrado de Rutas entre Domicilios)
	Restricciones: Solo se deben ingresar n�meros en un rango de 0 a 6.
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
		printf("\n\n<--Digite una opcion (0-7): ");	
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
	Entradas: Un n�mero (tipo char) en un rango de 0 a 3 para escoger una de las opciones disponibles en el men�. 
	Salidas: Llamada a las dem�s funciones para la gesti�n de Ayudantes de Santa (registro, modificaci�n, borrado 
			 de Ayudantes)
	Restricciones: Solo se deben ingresar n�meros en un rango de 0 a 3.
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
	Entradas: Un n�mero (tipo char) en un rango de 0 a 4 para escoger una de las opciones disponibles en el men�. 
	Salidas: Llamada a las dem�s funciones para la gesti�n de Cartas y Listas de Deseos (registro, modificaci�n,  
			 consulta y procesamiento de Cartas para Santa)
	Restricciones: Solo se deben ingresar n�meros en un rango de 0 a 4.
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
	Entradas: Un n�mero (tipo char) en un rango de 0 a 2 para escoger una de las opciones disponibles en el men�. 
	Salidas: Llamada a las dem�s funciones para la entrega de juguetes (para todas las rutas, para un tipo de ruta)  
			 consulta y procesamiento de Cartas para Santa)
	Restricciones: Solo se deben ingresar n�meros en un rango de 0 a 3.
*/
void GestionEntregas(struct ListaCartas *LCartas, struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta){
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
		printf("\n 1. Entrega para TODAS las Rutas.");
		printf("\n 2. Entrega para un TIPO de Ruta.");
		printf("\n\n<--Digite una opcion (0-2): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': entregaTodos(LCartas, LNinos, LJugCarta);
					break;
				case '2': entregaPorTipo(LCartas, LNinos, LJugCarta);
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
	Entradas: Un n�mero (tipo char) en un rango de 0 a 7 para escoger una de las opciones disponibles en el men�. 
	Salidas: Llamada a las dem�s funciones de Analisis de Datos
	Restricciones: Solo se deben ingresar n�meros en un rango de 0 a 7.
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
				case '2': masMenosJuguetes(LCartas, LNinos, LJugCarta);
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


/****************************************************************Gestion de Ni�os***********************************************************************************************/

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
    
	guardarNinos(LNinos);
	
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
	    
		guardarComportamiento(LComp);
		
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
			    	gets(correo);	
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
	
	guardarNinos(LNinos);
	
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
	
	guardarNinos(LNinos);
	
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
	Entradas: Una lista de tipo ListaNinos para tomar los datos que deben guardarse en el Archivo de ni�os
	Salidas: Se  guardan los valores de la lista de Ni�os en un archivo especifico
	Restricciones: Ninguna.
*/
void guardarNinos(struct ListaNinos *LNinos){

	struct Nino *iNino;
	
	FILE* ArchNinos;

    if(LNinos->inicio!=NULL)
	{
		remove("Archivos\\ArchNinos.txt");
		ArchNinos=fopen("Archivos\\ArchNinos.txt","a+");
		
		if(ArchNinos==NULL){
			printf("\n Error al intentar usar el archivo de Ninos(as).\n");	
		}else{
			iNino = LNinos->inicio;
	        while(iNino!=NULL){
				fprintf(ArchNinos,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", iNino->cedula, iNino->nombre_completo, iNino->nombre_usuario, iNino->correo, iNino->lugar_domicilio, iNino->fecha_nacimiento, iNino->edad, iNino->necesidades_esp );

				iNino = iNino->siguiente;
        	}
        	
		}	
		fclose(ArchNinos);	
		
	}else{
		printf( "\n***No se han encontrado Ninos(as) registrados***");
	}
}

/*
	Entradas: Una lista de tipo ListaComport para tomar los datos que deben guardarse en el Archivo de comportamientos
	Salidas: Se  guardan los valores de la lista de comportamientos en un archivo especifico
	Restricciones: Ninguna.
*/
void guardarComportamiento(struct ListaComport *LComp){

	struct Comportamiento *iComp;
	
	FILE* ArchComp;

    if(LComp->inicio!=NULL)
	{
		remove("Archivos\\ArchComp.txt");
		ArchComp=fopen("Archivos\\ArchComp.txt","a+");
		
		if(ArchComp==NULL){
			printf("\n Error al intentar usar el archivo de Comportamientos.\n");	
		}else{
			iComp = LComp->inicio;
	        while(iComp!=NULL){
				fprintf(ArchComp,"%s\n%s\n%s\n%s\n%s\n\n", iComp->cedula_nino, iComp->descripcion, iComp->fecha_registro, iComp->indicacion, iComp->nombre_padre_madre );

				iComp = iComp->siguiente;
        	}
        	
		}	
		fclose(ArchComp);	
		
	}else{
		printf( "\n***No se han encontrado Comportamientos registrados***");
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
	
	guardarAyudantes(LAyudantes);
	
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
                printf("\n  Funcion que desempena en el puesto: %s \n", ayudante->funcionPuesto);
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
			        printf("\nDesea modificar la Funcion que desempena en el puesto? (1-Si 2-No)\n" );
                	gets(respuesta);
					resp=atoi(respuesta);
                
			        if(resp==1 || resp==2){
			            break;
			        }
			    }while(1);
                
                if(resp==1){
                	printf("\n-->Ingrese la funcion que desempe�a en ese puesto: (Ejm. Colaboro con...) \n");
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
	
	guardarAyudantes(LAyudantes);
	
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
	
	guardarAyudantes(LAyudantes);

	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}


/*
	Entradas: Una lista de tipo ListaAyudantes para tomar los datos que deben guardarse en el Archivo de Ayudantes
	Salidas: Se guardan los valores de la lista de Ayudantes en un archivo especifico
	Restricciones: Ninguna.
*/
void guardarAyudantes(struct ListaAyudantes *LAyudantes){

	struct AydanteSanta *iAyudante;
	
	FILE* ArchAyudantes;

    if(LAyudantes->inicio!=NULL)
	{
		remove("Archivos\\ArchAyudantes.txt");
		ArchAyudantes=fopen("Archivos\\ArchAyudantes.txt","a+");
		
		if(ArchAyudantes==NULL){
			printf("\n Error al intentar usar el archivo de Ayudantes.\n");	
		}else{
			iAyudante = LAyudantes->inicio;
	        while(iAyudante!=NULL){
				fprintf(ArchAyudantes,"%s\n%s\n%s\n%s\n%s\n", iAyudante->identificacion, iAyudante->nombre, iAyudante->puesto, iAyudante->funcionPuesto, iAyudante->fechaComienzo);

				iAyudante = iAyudante->siguiente;
        	}
        	
		}	
		fclose(ArchAyudantes);	
		
	}else{
		remove("Archivos\\ArchAyudantes.txt");
	}
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

	guardarJuguetes();
	
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
	
	guardarJuguetes();
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: El nodo padre del Arbol de Juguetes  y el nombre del juguete por borrar
	Salidas: Se borran los datos un nodo de tipo Juguete seg�n su posici�n en el Arbol.
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
					printf("\n-->Se ha eliminado el Juguete con el nombre ingresado");
					break;						
				}
			
			}while(1); 
			
        }else{
			printf( "\n***No se ha encontrado un Juguete para el Nombre ingresado***");
		}
		
	}else{
		printf( "\n***No se han encontrado Juguetes registrados***");
	}
	
	guardarJuguetes();
	
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

/*
	Entradas: Ninguna
	Salidas: Se realza la escitura de los valores de un Juguete en un archivo de texto.
	Restricciones: Ninguna.
*/
void escribirJuguete(struct Juguete *iJuguete, FILE *ArchJuguetes){
    if (iJuguete != NULL)
    {
        fprintf(ArchJuguetes,"%s\n%s\n%s\n%s\n%s\n%s\n", iJuguete->codigo, iJuguete->nombre, iJuguete->descripcion, iJuguete->categoria, iJuguete->rango_edad, iJuguete->costo_fabricacion);
        escribirJuguete(iJuguete->izq, ArchJuguetes);
        escribirJuguete(iJuguete->der, ArchJuguetes);
    }
}

/*
	Entradas: Ninguna
	Salidas: Se guardan los valores del arbol de juguetes en un archivo de texto.
	Restricciones: Ninguna.
*/
void guardarJuguetes(){

	FILE* ArchJuguetes;

    if(jugueteRaiz!=NULL)
	{
		remove("Archivos\\ArchJuguetes.txt");
		ArchJuguetes=fopen("Archivos\\ArchJuguetes.txt","a+");
		
		if(ArchJuguetes==NULL){
			printf("\n Error al intentar usar el archivo de Ayudantes.\n");	
		}else{
			escribirJuguete(jugueteRaiz, ArchJuguetes);	
		}	
		fclose(ArchJuguetes);	
		
	}else{
		remove("Archivos\\ArchJuguetes.txt");
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
		strcpy(carta->procesada_por, "Sin Procesar");
		
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
				
				if (strcmp(opcion ,"1")!=0){
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
	
	guardarCartas(LCartas);
	guardarJugCarta(LJugCarta);
	guardarDeseo(LDeseos);
	
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
			comp1=strcmp(anno,i->anno);
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
	
	guardarCartas(LCartas);
	guardarJugCarta(LJugCarta);
	guardarDeseo(LDeseos);
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: Una lista de tipo ListaCarta, otra ListaJugCarta y otra ListaDeseos para tomar los datos de los juguetes de una Carta para Santa y una lista de deseos
	Salidas: Se muestran los datos de una Carta para Santa y de una Lista de Deseos en caso de que exista, para el anno e identificaci�n ingresados 
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
	Salidas: Se muestran los datos de una Carta para Santa en caso de que exista, para el anno e identificaci�n ingresados 
	Restricciones: Ninguna.
*/
void mostrarCarta(struct ListaCartas *LCartas, struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno []){

	struct JuguetesCarta *iJugCarta = LJugCarta->inicio;
	
	int registrados=0, encontrada=0;
	
	char estado[30];
	
	obtenerEstadoCarta(LCartas, identificacion, anno, estado);
	
	struct Carta *iCarta = LCartas->inicio;
	
	if(LCartas->inicio!=NULL)
	{

        while(iJugCarta!=NULL){
            if(strcmp(iCarta->identificacion, identificacion)==0 && strcmp(iCarta->anno,anno)==0){
   				
   				printf("\n\n+-------------------------------------------------------------------+\n");
				printf( "                        CARTA PARA SANTA" );
				printf("\n+-------------------------------------------------------------------+\n");
				printf("\n  Identificacion: %s   -   Anno: %s \n", iCarta->identificacion, iCarta->anno);
				printf("\n+-------------------------------------------------------------------+\n");
		                    	
            	if(strcmp(iCarta->estado, "Procesada")==0 || strcmp(iCarta->estado, "Cancelada")==0){
            		printf("\n  Estado: %s   -   Id. Ayudante: %s\n", iCarta->estado, iCarta->procesada_por);
					printf("\n+-------------------------------------------------------------------+\n");
				}else{
					printf("\n  Estado: %s \n", iCarta->estado);
					printf("\n+-------------------------------------------------------------------+\n");
				}
            	
            	encontrada=1;
            	break;
			}	
            iCarta = iCarta->siguiente;
            
        }		
		if(encontrada==0){
			printf( "\n***No se han encontrado una Carta para Santa con los datos ingresados***");
		}
	}else{
		printf( "\n***No se han encontrado Cartas para Santa registradas***");		
	}	
	
	
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
	Salidas: Se muestran los datos de una Lista de Deseos en caso de que exista, para el anno e identificaci�n ingresados 
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
            printf("\nIdentificacion: %s    -    Anno: %s   -   Estado: %s\n", iCarta->identificacion, iCarta->anno, iCarta->estado);
            iCarta = iCarta->siguiente;
        }		
		
	}else{
		printf( "\n***No se han encontrado Cartas para Santa registradas***");
	}
	
	printf("\n+-------------------------------------------------------------------+\n");
}

/*
	Entradas: Una lista de tipo ListaCarta, otra de tipo ListaNinos y un char que denote un anno
	Salidas: Un lista de cartas con el Idde cada nino para un anno especifico recibido
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
	Entradas: Una lista de tipo ListaNinos, un char que denote una identificacion y un puntero a un char
	Salidas: Se realiza un llenado del ultimo par�metro con la informaci�n que corresponda al nombre del
			nino con la identificaci�n recibida
	Restricciones: Ninguna
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
	Entradas: Una lista de tipo ListaCartas, un char que denote una identificacion, otro un anno y un puntero a un char
	Salidas: Se realiza un llenado del ultimo par�metro con la informaci�n que corresponda al estado de la carta
			la identificaci�n recibida y anno recibidos
	Restricciones: Ninguna
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
	
	printf("\n+------------------------------------------------+\n");
	printf( "          Validacion de Comportamiento" );
	printf("\n+------------------------------------------------+\n");
	
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
		printf( "\n***No se han encontrado Comportamientos registrados***");
		printf("\n+------------------------------------------------+\n");
		return 0;
	}
	
	if(contador>=6){
		printf("\n***El nino(a) tiene 6 o MAS comportamiento MALOS***");
		printf("\n+------------------------------------------------+\n");
		return 1;
	}else{
		printf("\n-->El nino(a) tiene MENOS de 6 comportamiento MALOS");
		printf("\n+------------------------------------------------+\n");
		return 0;
	}

}


/*
	Entradas: Una lista de tipo ListaCartas, otra ListaNinos, otra ListaJugCarta, otra ListaAyudantes y una ListaAComport
	Salidas: Se realiza el procesado de una de las cartas, y de sus juguetes, ya sea para aceptar o rechazar cada uno.
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
		
		//Mostrar lista de ni�os que registraron una carta (con Identificaci�n y nombre)
		printf("\n-->Ingrese el Anno que corresponda consultar:\n");
		gets(anno);
		
		mostrarCartasPorAnno(LCartas, LNinos, anno);
		
		do{ //Solicitar identificacion del ni�o
			printf("\n-->Ingrese el numero de Identificacion del Nino(a): (Ej. 105450656) \n");
			gets(identificacion);
			
			if(validarCarta(LCartas, identificacion, anno)!=1){
			    printf("\n**No se tiene registrada una carta para la identificaci�n y anno ingresados**\n ");
			}else{//Mostrar detalle de la carta para ese a�o e identificaci�n
			    mostrarCarta(LCartas, LJugCarta, identificacion, anno);
				break;
			}
		
		}while(1);

		do{ //Registrar los datos de Ayudante que proceso la carta

			printf("\n\n-->Ingrese la Identificacion del Ayudante de Santa: (Ejm.105450656) \n");
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
	    	enviarCorreo(LNinos, identificacion);
	    	
		}else{ //- de 6 malos comportamientos 
			
			//Consultar por cada juguete
			iJugCarta = LJugCarta->inicio;
			int registrados=0;

			if(LJugCarta->inicio!=NULL)
			{
		        
		        while(iJugCarta!=NULL){
		            if(strcmp(iJugCarta->identificacion, identificacion)==0 && strcmp(iJugCarta->anno,anno)==0){
		            	printf("\n\t+------------------------------+\n");
						printf( "\t        Procesar Juguete" );
						printf("\n\t+------------------------------+\n");
						
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
								printf("\n   **Opci�n no valida**\n ");
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
		
	guardarCartas(LCartas);
	guardarJugCarta(LJugCarta);
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: Una lista de tipo ListaNinos, y un char dque denota la identificacion de un Nino(a)
	Salidas: Se realiza la actualizacion del archivo que contine la direccion del destinatario con el correo del Nino(a)
			 y se envia un correo a ste notificando la cancelacion de la Carta para Santa.
	Restricciones: Ninguna.
*/
void enviarCorreo(struct ListaNinos *LNinos, const char identificacion []){

	struct Nino *iNino;
	char destinatario [80];
	
	FILE* ArchDestinatario;
	
	if(LNinos->inicio!=NULL)
	{
        iNino = LNinos->inicio;
        while(iNino!=NULL){

	        if(strcmp(identificacion,iNino->cedula)==0)
			{
				strcpy(destinatario, iNino->correo);
				
				remove("Archivos\\EnviarCorreo\\Destinatario.txt");
				ArchDestinatario=fopen("Archivos\\EnviarCorreo\\Destinatario.txt","a+");
				
				if(ArchDestinatario==NULL){
					printf("\n Error al intentar usar el archivo Destinatario.\n");	
				}else{
					fprintf(ArchDestinatario, "%s", destinatario);
				}
					
				fclose(ArchDestinatario);	
				
				SendMail(0);
							
				break;
			}
			iNino = iNino->siguiente;
        }
	}

}

/*
	Entradas: Una lista de tipo ListaCartas, un char que denote una identificacion, otro un anno, otro un estado y otro el id de un ayudante
	Salidas: Se varia el estado de un objeto tipo Carta de la lista, seg�n indique el par�metro del estado
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


/*
	Entradas: Una lista de tipo ListaJugCarta para tomar los datos que deben guardarse en el Archivo de Juguetes por Carta
	Salidas: Se guardan los valores de la lista de juguetes por carta en un archivo especifico
	Restricciones: Ninguna.
*/
void guardarJugCarta(struct ListaJugCarta *LJugCarta){

	struct JuguetesCarta *iJugCarta;
	
	FILE* ArchJugCarta;

    if(LJugCarta->inicio!=NULL)
	{
		remove("Archivos\\ArchJugCarta.txt");
		ArchJugCarta=fopen("Archivos\\ArchJugCarta.txt","a+");
		
		if(ArchJugCarta==NULL){
			printf("\n Error al intentar usar el archivo de Juguetes en Cartas.\n");	
		}else{
			iJugCarta = LJugCarta->inicio;
	        while(iJugCarta!=NULL){
				fprintf(ArchJugCarta,"%s\n%s\n%s\n%s\n", iJugCarta->identificacion, iJugCarta->anno, iJugCarta->nombre_juguete, iJugCarta->estado);

				iJugCarta = iJugCarta->siguiente;
        	}	
		}	
		fclose(ArchJugCarta);	
		
	}else{
		remove("Archivos\\ArchJugCarta.txt");
	}
}


/*
	Entradas: Una lista de tipo ListaJugCarta para tomar los datos que deben guardarse en el Archivo de Cartas
	Salidas: Se guardan los valores de la lista de Cartas en un archivo especifico
	Restricciones: Ninguna.
*/
void guardarCartas(struct ListaCartas *LCartas){

	struct Carta *iCarta;
	
	FILE* ArchCartas;

    if(LCartas->inicio!=NULL)
	{
		remove("Archivos\\ArchCartas.txt");
		ArchCartas=fopen("Archivos\\ArchCartas.txt","a+");
		
		if(ArchCartas==NULL){
			printf("\n Error al intentar usar el archivo de Cartas para Santa.\n");	
		}else{
			iCarta = LCartas->inicio;
	        while(iCarta!=NULL){
				fprintf(ArchCartas,"%s\n%s\n%s\n%s\n", iCarta->identificacion, iCarta->anno, iCarta->estado, iCarta->procesada_por);

				iCarta = iCarta->siguiente;
        	}	
		}	
		fclose(ArchCartas);	
		
	}else{
		remove("Archivos\\ArchCartas.txt");
	}
}

/*
	Entradas: Una lista de tipo ListaDeseos para tomar los datos que deben guardarse en el Archivo de Deseos
	Salidas: Se guardan los valores de la lista de deseos en un archivo especifico
	Restricciones: Ninguna.
*/
void guardarDeseo(struct ListaDeseos *LDeseos){

	struct Deseo *iDeseo;
	
	FILE* ArchDeseos;

    if(LDeseos->inicio!=NULL)
	{
		remove("Archivos\\ArchDeseos.txt");
		ArchDeseos=fopen("Archivos\\ArchDeseos.txt","a+");
		
		if(ArchDeseos==NULL){
			printf("\n Error al intentar usar el archivo de Deseos.\n");	
		}else{
			iDeseo = LDeseos->inicio;
	        while(iDeseo!=NULL){
				fprintf(ArchDeseos,"%s\n%s\n%s\n", iDeseo->identificacion, iDeseo->anno, iDeseo->nombre_juguete);

				iDeseo = iDeseo->siguiente;
        	}
        	
		}	
		fclose(ArchDeseos);	
		
	}else{
		remove("Archivos\\ArchDeseos.txt");
	}
}

/****************************************************************Gestion de Domicilios y Rutas ************************************************************************************/
/*
	Entradas: Ninguna
	Salidas: Se agrega un nuevo domicilio a la estructura del Grafo 
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
    
    guardarDomiciliosYRutas();
    
    printf("\n+++ Informacion registrada correctamente +++\n" );
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: Un char que denote el nombre de un lugar de domicilio
	Salidas: Se valida que no exista un nodo con el mismo nombre dentro del Grafo 
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
	Entradas: Ninguna
	Salidas: Se agrega una nueva Ruta a la estructura del Grafo 
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
    
	guardarDomiciliosYRutas();
	
	printf("\n+++ Informacion registrada correctamente +++\n" );
		
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}


/*
	Entradas: Un puntero a un domicilio de origen, otro al destino y otro a una ruta
	Salidas: Se agrega una nueva Ruta a la lista de adyacencias de un vertice del Grafo
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
	Entradas: Ninguna
	Salidas: Se modifica un Domicilio registrado en la estructura del Grafo 
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
		
	guardarDomiciliosYRutas();
	
	printf("\n+++ Informacion registrada correctamente +++\n" );
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: Ninguna
	Salidas: Se modifica un Ruta registrada para un vertice de la estructura del Grafo 
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
	
	guardarDomiciliosYRutas();
    
    printf("\n+++ Informacion registrada correctamente +++\n" );
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: Ninguna
	Salidas: Se elimina un Domicilio registrado en la estructura del Grafo y todas sus adyacencias
	Restricciones: Ninguna.
*/
void eliminarDomicilio(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Eliminar Info. de un Domiclio\n" );
	printf("*********************************\n");
	
	struct Domicilio *domicilio=lugarInicial, *anterior;
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
	
	guardarDomiciliosYRutas();
		
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	

}

/*
	Entradas: Ninguna
	Salidas: Se elimina un Ruta registrada para un vertice de la estructura del Grafo para un lugar de destino determinado
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
	Entradas: Ninguna
	Salidas: Se elimina un Ruta registrada en la estructura del Grafo 
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
	
	guardarDomiciliosYRutas();
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();
		
	
}


/*
	Entradas: Ninguna
	Salidas: Se muestra una lista con los datos de los Domicilios registrados como vertices del Grafo
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
	Entradas: Ninguna
	Salidas: Se muestra una lista con los datos de los Domicilios registrados como vertices del Grafo y de las rutas
			 asociadas a estos
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
    	printf(" Origen  ->  Destino ( tipo , duracion)\n"); 
		printf("***********************************\n"); 
	    
		while(iDomicilio!=NULL){   
		    printf("  >> %s-> ",iDomicilio->nombre_lugar);
	       
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
	Entradas: Ninguna
	Salidas: Se realiza el registro del Polo Norte como lugar de domicilio inicial.
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
	
	guardarDomiciliosYRutas();
}

/*
	Entradas: Ninguna
	Salidas: Se guardan los Domicilios en un archivo de texto.
	Restricciones: Ninguna.
*/
void guardarDomiciliosYRutas(){

	Domicilio* iDomicilio=lugarInicial;
	Ruta* iRuta;
	
	char buffer[20];

	FILE* ArchDomicilios;
	FILE* ArchRutas;

    if(iDomicilio!=NULL)
	{
		remove("Archivos\\ArchDomicilios.txt");
		remove("Archivos\\ArchRutas.txt");
		
		ArchDomicilios=fopen("Archivos\\ArchDomicilios.txt","a+");
		ArchRutas=fopen("Archivos\\ArchRutas.txt","a+");
			
		if(ArchDomicilios==NULL){
			printf("\n Error al intentar usar el archivo de Ayudantes.\n");	
		}else{
			while(iDomicilio!=NULL){   
			    fprintf(ArchDomicilios,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n",iDomicilio->codigo, iDomicilio->nombre_lugar, iDomicilio->codigo_postal, itoa(iDomicilio->visitado, buffer, 10), itoa(iDomicilio->terminado, buffer, 10), itoa(iDomicilio->monto, buffer, 10), iDomicilio->anterior);
		        
				if(iDomicilio->adyacencia != NULL){

					iRuta=iDomicilio->adyacencia;
					
					while(iRuta!=NULL){                               /*         Origen                  Destino         */                                             
					    fprintf(ArchRutas,"%s\n%s\n%s\n%s\n%s\n",iDomicilio->nombre_lugar, iRuta->lugar->nombre_lugar, iRuta->tiempo_estimado, iRuta->distancia, iRuta->tipo_ruta);
		                iRuta=iRuta->siguiente;
		            }
				}
				
				iDomicilio=iDomicilio->siguiente;
		    }
		}	
		fclose(ArchDomicilios);	
		fclose(ArchRutas);
		
		
	}else{
		remove("Archivos\\ArchDomicilios.txt");
		remove("Archivos\\ArchRutas.txt");
	}
}

/**************************************************************** Gestion de Entregas  ***********************************************************************************************/

/*
	Entradas: Una lista de tipo ListaCartas, otra ListaNinos y otra ListaJugCarta
	Salidas: Se simula el env�o de los juguetes listos para entregar, para las cartas procesadas, y para todas las rutas
	Restricciones: Ninguna.
*/
void entregaTodos(struct ListaCartas *LCartas, struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("   Entrega a Todas las Rutas\n" );
	printf("*********************************\n");
	
	if(LCartas->inicio!=NULL){

		struct ListaPorVisitar *LPorVisitar;
		LPorVisitar = (struct ListaPorVisitar *) malloc(sizeof(struct ListaPorVisitar));
		LPorVisitar->inicio = NULL;
		LPorVisitar->final = NULL;
		
		struct ListaEntregables *LEntregables;
		LEntregables = (struct ListaEntregables *) malloc(sizeof(struct ListaEntregables));
		LEntregables->inicio = NULL;
		LEntregables->final = NULL;
			
		//Obtener Cartas por Entregar y Lugares por visitar
		obtenerEntregables(LCartas, LNinos, LJugCarta, LPorVisitar, LEntregables);
		
		if(LEntregables->inicio!=NULL){
			
			if(LPorVisitar->inicio!=NULL){
						
				struct LugPorVisitar *iLugarPorVisitar=LPorVisitar->inicio;	
		
				iLugarPorVisitar=LPorVisitar->inicio;
				
				//Llamar a la funci�n con el Algoritmo de Dijkstra
				while(iLugarPorVisitar!=NULL){

					dijkstraTodos(LEntregables, iLugarPorVisitar->nombre_Lugar);
					
					iLugarPorVisitar=iLugarPorVisitar->siguiente;
				}
				
			}else{
				printf( "\n***No se han encontrado Domicilios por visitar***");
			}		
			
		}else{
			printf( "\n***No se han encontrado Cartas listas para entregar***");
		}
		
	}else{
		printf( "\n***No se han encontrado Cartas registradas***");
	}
	

	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: Una lista de tipo ListaCartas, otra ListaNinos y otra ListaJugCarta
	Salidas: Se simula el env�o de los juguetes listos para entregar, para las cartas procesadas, y para un tipo de ruta dado
	Restricciones: Ninguna.
*/
void entregaPorTipo(struct ListaCartas *LCartas, struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("   Entrega Por Tipo de Ruta\n" );
	printf("*********************************\n");
	
	char tipo_ruta [10];
	
	if(LCartas->inicio!=NULL){
		
		printf("\n-->Ingrese el tipo de ruta (T->terrestre, A->aerea o M->maritima): \n");
    	gets(tipo_ruta); 

		struct ListaPorVisitar *LPorVisitar;
		LPorVisitar = (struct ListaPorVisitar *) malloc(sizeof(struct ListaPorVisitar));
		LPorVisitar->inicio = NULL;
		LPorVisitar->final = NULL;
		
		struct ListaEntregables *LEntregables;
		LEntregables = (struct ListaEntregables *) malloc(sizeof(struct ListaEntregables));
		LEntregables->inicio = NULL;
		LEntregables->final = NULL;
			
		//Obtener Cartas por Entregar y Lugares por visitar
		obtenerEntregables(LCartas, LNinos, LJugCarta, LPorVisitar, LEntregables);
		
		if(LEntregables->inicio!=NULL){
			
			if(LPorVisitar->inicio!=NULL){
				
				struct LugPorVisitar *iLugarPorVisitar=LPorVisitar->inicio;	
		
				iLugarPorVisitar=LPorVisitar->inicio;	
				
				//Llamar a la funci�n con el Algoritmo de Dijkstra
				while(iLugarPorVisitar!=NULL){

					dijkstraPorTipo(LEntregables, iLugarPorVisitar->nombre_Lugar, tipo_ruta);
					
					iLugarPorVisitar=iLugarPorVisitar->siguiente;
				}
				
			}else{
				printf( "\n***No se han encontrado Domicilios por visitar***");
			}		
			
		}else{
			printf( "\n***No se han encontrado Cartas listas para entregar***");
		}
		
	}else{
		printf( "\n***No se han encontrado Cartas registradas***");
	}
	

	printf("\n\nPresione una tecla para regresar..." );
	getchar();
}

/*
	Entradas: Un puntero a un Domicilio
	Salidas: Se a�ade e ldomicilio recibido a la Lista De Domicilios que deben ser visitados
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
	Entradas: Ninguna
	Salidas: Se retorna el valor del nombre del ultimo domilcio agregado al recorrido
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
	Entradas: Ninguna 
	Salidas: Se reinician los valores de las variables "visitado" y "terminado" para todos los Domicilios registrados
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
	Entradas: Una lista de tipo ListaEntregables
	Salidas: Se muestra el recorrido para entregar los juguetes sin importar el tipo de ruta
	Restricciones: Ninguna.
*/
void dijkstraTodos(struct ListaEntregables *LEntregables, const char destino[50]){
		
	Domicilio *iDomicilio = lugarInicial;
	char origen[50];
	
	strcpy(origen, "Polo Norte");

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

	printf("\n-->Recorrido: ");
	insertarEnRecorrido(iDomicilio);
	while(lugarLlegada!=NULL){

		printf("->%s ",extraerLugar()->nombre_lugar);
	}
	printf("\n");
	
	struct CartaEntregable *iEntregable = LEntregables->inicio;
	
	printf("\nIdentificacion del Nino(a)   -  Anno ");
	printf("\n---------------------------------");
	
	while(iEntregable!=NULL){

		if(strcmp(iEntregable->domicilio, destino)==0){
			printf("\n  -> %s  -  %s", iEntregable->identificacion, iEntregable->anno);
		}

		iEntregable=iEntregable->siguiente;
	}
	
	printf("\n---------------------------------");	
	reiniciarDomicilios();
}

 /*
	Entradas: Una lista de tipo ListaEntregables
	Salidas: Se muestra el recorrido para entregar los juguetes seg�n un tipo de ruta
	Restricciones: Ninguna.
*/
void dijkstraPorTipo(struct ListaEntregables *LEntregables, const char destino[50], const char tipo[10]){
		
	Domicilio *iDomicilio = lugarInicial;
	char origen[50];
	
	strcpy(origen, "Polo Norte");

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
			if(strcmp(iRuta->tipo_ruta, tipo)==0){
				if(iRuta->lugar->monto==-1 || (iDomicilio->monto+atoi(iRuta->tiempo_estimado))<iRuta->lugar->monto){
			    	iRuta->lugar->monto=iDomicilio->monto+atoi(iRuta->tiempo_estimado);
			    	strcpy(iRuta->lugar->anterior, iDomicilio->nombre_lugar);
				}
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

	printf("\n-->Recorrido: ");
	insertarEnRecorrido(iDomicilio);
	while(lugarLlegada!=NULL){

		printf("->%s ",extraerLugar()->nombre_lugar);
	}
	printf("\n");
	
	struct CartaEntregable *iEntregable = LEntregables->inicio;
	
	printf("\nIdentificacion del Nino(a)   -  Anno ");
	printf("\n---------------------------------");
	while(iEntregable!=NULL){

		if(strcmp(iEntregable->domicilio, destino)==0){
			printf("\n  -> %s  -  %s", iEntregable->identificacion, iEntregable->anno);
		}

		iEntregable=iEntregable->siguiente;
	}
	
	printf("\n---------------------------------");	
	reiniciarDomicilios();
}

/*
	Entradas: Una lista de tipo ListaCartas, otra ListaNinos, otra ListaJugCarta, otra ListaPorVisitar y otra ListaEntregables
	Salidas: Se agregan a la lista de entregables los datos de las cartas que hayan sido procesadas y poseean al menos un juguete con estado listo para entregar
	Restricciones: Ninguna.
*/
void obtenerEntregables(struct ListaCartas *LCartas, struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta, struct ListaPorVisitar *LPorVisitar, struct ListaEntregables *LEntregables ){
	int res=0;
	struct Carta *iCarta;
	struct LugPorVisitar *LugarPorVisitar;
	struct CartaEntregable *Entregable;
	
	char domicilio[50];
	
	if(LCartas->inicio!=NULL)
	{
		iCarta = LCartas->inicio;
		while( iCarta!= NULL){
			if (strcmp(iCarta->estado,"Procesada")==0){
				res = validarJugParaEntregar( LJugCarta,iCarta->identificacion, iCarta->anno);
				if (res==1){
					Entregable = (struct CartaEntregable *) malloc(sizeof(struct CartaEntregable));	
					obtenerDomicilio(LNinos,iCarta->identificacion, domicilio);
					
					strcpy(Entregable->identificacion,iCarta->identificacion);
					strcpy(Entregable->domicilio,domicilio);
					strcpy(Entregable->anno,iCarta->anno);
					
					if(LEntregables->inicio == NULL) 
					{
						LEntregables->inicio = Entregable;
						LEntregables->inicio->siguiente = NULL; 
						LEntregables->final = LEntregables->inicio;
				
					}
					else
					{	
						LEntregables->final->siguiente = Entregable;
						LEntregables->final->siguiente->siguiente = NULL;  
						LEntregables->final = LEntregables->final->siguiente;
					}
					
					agregarLugarPorVisitar(LPorVisitar, Entregable->domicilio);
									
				}		
			}			
			iCarta = iCarta->siguiente;
		}
		
	}else{
		printf("***NO hay cartas para entregar***");
	}
	
}

 /*
	Entradas: Una lista de tipo ListaJugCarta, y un char que denote un identificacion y otro un anno  
	Salidas: Se determian si se tiene un juguete asociado a una carta que posea un estado listo para entregar
	Restricciones: Ninguna.
*/
int validarJugParaEntregar( struct ListaJugCarta *LJugCarta,const char identificacion[],const char anno[]){
	struct JuguetesCarta *iJuguete = LJugCarta->inicio;
	if(iJuguete!=NULL)
	{
		while( iJuguete!= NULL){
			if (strcmp(iJuguete->anno,anno)==0 && strcmp(iJuguete->identificacion, identificacion)==0 ){
				if (strcmp(iJuguete->estado,"Listo para entregar")==0){
					return 1;
				}
			}			
			iJuguete = iJuguete->siguiente;
		}
		return 0;		
	}else{
		return 0;
	}
}

 /*
	Entradas: Una lista de tipo ListaPorVisitar, y un char que denota el nombre de un domicilio
	Salidas: Se agrega el lugar recibido a la lista de lugares por visitar 
	Restricciones: Ninguna.
*/
void agregarLugarPorVisitar(struct ListaPorVisitar *LPorVisitar, const char domicilio[]){
	int hallado=0;
	struct LugPorVisitar *iLugarPorVisitar=LPorVisitar->inicio;
	
	if(iLugarPorVisitar==NULL)
	{
		iLugarPorVisitar =(struct LugPorVisitar *) malloc (sizeof(struct LugPorVisitar));
				
		strcpy(iLugarPorVisitar->nombre_Lugar, domicilio);
		LPorVisitar->contador = 1;
		
		LPorVisitar->inicio = iLugarPorVisitar;
		LPorVisitar->inicio->siguiente = NULL;
		LPorVisitar->final = LPorVisitar->inicio;	
		
	}else{	
		for(iLugarPorVisitar = LPorVisitar->inicio; iLugarPorVisitar != NULL; iLugarPorVisitar = iLugarPorVisitar->siguiente){
			
			if(strcmp(iLugarPorVisitar->nombre_Lugar,domicilio)==0){
				hallado=1;
				break;
			}
		}
		if(hallado!=1){
			iLugarPorVisitar =(struct LugPorVisitar *) malloc (sizeof(struct LugPorVisitar));
			
			strcpy(iLugarPorVisitar->nombre_Lugar, domicilio);
			LPorVisitar->contador = 1;
			
			LPorVisitar->final->siguiente = iLugarPorVisitar;
			LPorVisitar->final->siguiente->siguiente = NULL;  
			LPorVisitar->final = LPorVisitar->final->siguiente;
		}
	}
}


/****************************************************************Analisis de Datos***********************************************************************************************/
/*
	Entradas: Una lista de tipo ListaJugCarta
	Salidas: Se muestra una lista de los a�os registrados y la cantidad de juguetes para cada uno
	Restricciones: Ninguna
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
	Entradas: Una lista de tipo ListaNinos, un char que denote la identificacion y un puntero que apunte a un char 
	Salidas: Se almacena en el ultimo par�metro recibido el el nombre del domicilio asociado a la identificacion del nino recibida
	Restricciones: Ninguna
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
	Entradas: Una lista de tipo LJugCarta, un char que denote la identificacion y otro un anno
	Salidas: Se cuentan cuantos juguetes se han asignado a esta carta y se retorna este valor
	Restricciones: Ninguna
*/
int contarJuguetesPorCarta(struct ListaJugCarta *LJugCarta, const char identificacion [], const char anno []){

    struct JuguetesCarta *i= LJugCarta->inicio;
    
    int cantidad_juguetes=0;

    if(LNinos->inicio!=NULL)
    {
        while( i!= NULL){
	        if(strcmp(identificacion,i->identificacion)==0 && strcmp(anno,i->anno)==0)
			{
                cantidad_juguetes++;
            }
            i = i->siguiente;
        }
    }

    return cantidad_juguetes;
}

/*
	Entradas: Una lista de tipo ListaCartas y otra de tipo ListaNinos
	Salidas: Se muestra la cantida
	Restricciones: Ninguna
*/
void masMenosJuguetes(struct ListaCartas *LCartas, struct ListaNinos *LNinos, struct ListaJugCarta *LJugCarta){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Lugares con Mas/Menos Juguetes\n" );
	printf("*********************************\n");
		
	struct Carta *iCarta = LCartas->inicio;
	struct Nino *iNino = LNinos->inicio;
	struct CartaSolicitada *iCartaSolic, *nCartaSolic;
	struct PilaCartas *PCartas;
	PCartas = (struct PilaCartas *) malloc(sizeof(struct PilaCartas));
	PCartas->tope = NULL;
	
	char domicilio[50];
	int resultado=0, hallado=0, mayor=0, menor=0, cant_juguetes;
		
	//Conteo de las Cartas Procesadas	
	if(LCartas->inicio!=NULL)
	{
        iCarta = LCartas->inicio;
		while( iCarta!= NULL){
		
			resultado=obtenerDomicilio(LNinos, iCarta->identificacion, domicilio);
			
			if(resultado==1){
				
				cant_juguetes = contarJuguetesPorCarta(LJugCarta, iCarta->identificacion, iCarta->anno );
				
				if(PCartas->tope==NULL)
				{
					nCartaSolic =(struct CartaSolicitada *) malloc (sizeof(struct CartaSolicitada));
										
					strcpy(nCartaSolic->domicilio, domicilio);
					nCartaSolic->cantidad = cant_juguetes;
					
					nCartaSolic->siguiente = PCartas->tope;
					PCartas->tope = nCartaSolic;
					
				}else{	
					for(iCartaSolic = PCartas->tope; iCartaSolic!= NULL; iCartaSolic = iCartaSolic->siguiente){
						
						if(strcmp(domicilio,iCartaSolic->domicilio)==0){
							iCartaSolic->cantidad = (iCartaSolic->cantidad)+cant_juguetes;
							hallado=1;
							break;
						}
					}		
					
					if(hallado!=1){
						nCartaSolic =(struct CartaSolicitada *) malloc (sizeof(struct CartaSolicitada));
						
						strcpy(nCartaSolic->domicilio, domicilio);
						nCartaSolic->cantidad = cant_juguetes;
						
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
		printf( " -->Lugar con MAS Juguetes: %s", domicilio);
		printf( "\n    -->Total de Juguetes: %d", mayor);
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
		
		printf( " -->Lugar con MENOS Juguetes: %s", domicilio );
		printf( "\n    -->Total de Juguetes: %d", menor );
		printf("\n+-----------------------------------------+\n");
	
	}else{
		printf( "\n***No se han encontrado Cartas registradas***");
	}	
	
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: Una lista de tipo ListaCartas
	Salidas: Se muestra una lista de los a�os registrados y las cartas aprobadas para cada uno
	Restricciones: Ninguna
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
	Entradas: Una lista de tipo ListaCartas
	Salidas: Se muestra una lista de los a�os registrados y las cartas rechazadas o canceladas para cada uno
	Restricciones: Ninguna
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
	Entradas: Una lista de tipo ListaComport
	Salidas: Se denotan el total de comportamientos Buenos y Malos registrados 
	Restricciones: Ninguna
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
			}else if (strcmp(iComp->indicacion, "2")==0){
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
	Entradas: Una lista de tipo ListaCartas
	Salidas: Se muestra una lista de los ayudantes y de la cantidad de cartas procesadas por cada uno
	Restricciones: Ninguna
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
		printf( "  Identificaci�n    -   Cartas Procesadas" );
		printf("\n+----------------------------------------+\n");
		
		iCartaProc = CProc->tope;
			
		if(CProc->tope!=NULL)
		{
	        while(iCartaProc!=NULL){
	            if (strcmp(iCartaProc->procesada_por,"Sin Procesar")!=0)
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
	Entradas: Una lista de tipo ListaJugSolicitados
	Salidas: Se ordenan  de forma descendente los elementos contenidos en la lista recibida como parametro
	Restricciones: Ninguna
*/
void ordenarTopJuguetes(struct ListaJugSolicitados *TopJuguetes){

	struct JugSolicitado *i, *j, *temp;

	i = TopJuguetes->inicio;
	while( i->siguiente!= NULL){
		j = i->siguiente;

		while( j!= NULL){

			if(i->cantidad < j->cantidad){
				printf("\n ordenarTopJuguetes %d", i->cantidad);
				printf("\n ordenarTopJuguetes %d", j->cantidad);
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
	Entradas: Una lista de tipo ListaJugSolicitados
	Salidas: Se muestra un a lista del los 10 jueguetes mas solictados para las cartas registradas
	Restricciones: Ninguna
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
			printf( "\n***No se han encontrado juguetes solicitados***");
		}
						
		ordenarTopJuguetes(TopJuguetes);
		
		//Mostrar cantidades contadas
		printf("\n+------------------------------------------+\n");
		printf( "  Nombre del Juguete   -  Cant. Solicitudes" );
		printf("\n+------------------------------------------+\n");
		
		iJugSolicitado = TopJuguetes->inicio;
		cont=0;
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
			printf( "\n***No se han encontrado juguetes solicitados***");
		}
				
		
	}else{
		printf( "\n***No se han encontrado juguetes solicitados***");
	}
	

	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}


int main(){ 

	MenuPrincipal();    
	return 0; 
}


