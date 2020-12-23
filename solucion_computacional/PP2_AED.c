/*Algoritmos y Estructuras de Datos - Grupo 1
	Proyecto Programado 2 
	Estudiantes: Jose Altamirano Salazar - 2020426159
	             Josué Brenes Alfaro - 2020054427
*/
  
#include <stdio.h>
#include <stdlib.h>

//Tipos para la gestion de los datos de cada elemento
typedef struct Nino Nino;
typedef struct ListaNinos ListaNinos;

typedef struct AydanteSanta AydanteSanta;
typedef struct PilaAyudantes PilaAyudantes;

//Procedimientos para Menus de Opciones
void MenuPrincipal();
void GestionNinos();
void GestionJuguetes();
void GestionDomicilios();
void GestionAyudantes();
void GestionCartas();
void AnalisisDeDatos();

//Procedimientos para gestion de de Ninos/as
void registrarNinos(struct ListaNinos *LNinos);
void mostrarNinos(struct ListaNinos *LNinos);



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
    
};

struct ListaNinos {
	Nino *inicio;
	Nino *final;
};

struct AydanteSanta{
    char identificacion[15];
    char nombre[50];
    char puesto[50];
    char funcionPuesto[50];
    char fechaComienzo[10];
    AydanteSanta *siguiente;  
};

struct PilaAyudantes{
    AydanteSanta *Tope;  
};



//struct Requerimiento{
//    char identificador[50];
//    char tipo[20];
//    char descripcion[200];
//    char riesgo[60];
//    char dependencia[10];
//    char recursos[55];
//    char estado [15];
//    char esfuerzo[5];
//    char oficina [15];
//    Requerimiento *siguiente;
//
//};


/****************************************************************Menús de Opciones***********************************************************************************************/

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
            case '1': GestionNinos(LNinos);
                break;
			case '2': GestionJuguetes();
                break;
            case '3': GestionDomicilios();
                break;
			case '4': GestionAyudantes();
                break;
            case '5': GestionCartas();
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
void GestionNinos(struct ListaNinos *LNinos){
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
		printf("\n 3. ELIMINAR informacion de un nino o nina.");
		printf("\n 4. MODIFICAR informacion de un nino o nina.");
		printf("\n\n<--Digite una opcion (0-4): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': registrarNinos(LNinos);
					break;
				case '2': MenuPrincipal();
					break;
				case '3': MenuPrincipal();
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
		printf("\n 3. ENTREGAR Juguetes de Cartas registradas.");
		printf("\n\n<--Digite una opcion (0-3): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': MenuPrincipal();
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
void GestionAyudantes(){
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
		printf("\n\n<--Digite una opcion (1-7): ");	
		opcion=getchar();
		
		while((ch = getchar()) != EOF && ch != '\n');
			switch(opcion){
				case '1': MenuPrincipal();
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
void GestionCartas(){
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
				case '1': MenuPrincipal();
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

//    do{
        printf("\n-->Ingrese el numero de Identificacion: (Ej.105450656) \n");
        gets(nino->cedula);

//        if(validarCedula(nino->cedula)==1){
//            printf("\n**Esta Identificacion ya ha sido registrada**\n ");
//        }else{
//            break;
//        }
//    }while(1);
    
    printf("\n-->Ingrese el Nombre Completo: (Ej. Juan Perez) \n");
    gets(nino->nombre_completo);
    printf("\n-->Ingrese el Nombre de Usuario: (Ej. juanp123) \n");
    gets(nino->nombre_usuario);
    printf("\n-->Ingrese el Correo Electronico: (Ej. juanp123@correo.com) \n");
    gets(nino->correo);
    printf("\n-->Ingrese el Código del Domicilio (Ej. DOM-001): \n");
    gets(nino->codigo_domicilio);
    printf("\n-->Ingrese el Fecha de Nacimiento (Ej. 12/12/2000) \n");
    gets(nino->fecha_nacimiento);
    printf("\n-->Ingrese la Edad del nino/nina:\n");
    gets(nino->edad);
    printf("\n-->Ingrese alguna necesidad especial: \n");
    gets(nino->necesidades_esp);
    
    if(LNinos->inicio == NULL) 
	{
		LNinos->inicio = nino;
		LNinos->inicio->siguiente = NULL; 
		LNinos->final = LNinos->inicio;

	}
	else
	{	
		LNinos->final->siguiente = nino;
		LNinos->final->siguiente->siguiente = NULL; 
		LNinos->final = LNinos->final->siguiente;
	}	
    
	mostrarNinos(LNinos);
    
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
	getchar();
}

/****************************************************************Gestion de Ayudantes***********************************************************************************************/

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void registrarMiembro(){
    system( "CLS" );
    printf("\n\n*********************************\n");
		printf("        Sistema NaviTEC \n");
		printf("*********************************\n");
		printf(" Registro de Ayudantes de Santa\n");
		printf("*********************************\n");
	
    struct PilaAyudantes *ayudante;
    ayudante=(struct PilaAyudantes *) malloc (sizeof(struct PilaAyudantes));
		
    //do{
	printf("\n Ingrese la Identificacion: (Ejm.105450656) \n");
	gets(ayudante->Tope->identificacion);

        //if(validarCedula(ayudante->cedula)==1){
        //    printf("\n**Esta cedula ya ha sido registrada**\n ");
        //}else{
        //    break;
        //}
    //}while(1);
    
    printf("\n Ingrese el Nombre del Ayudante: (Ejm.Juan Perez) \n");
    gets(ayudante->Tope->nombre);
    printf("\n Ingrese el Puesto del ayudante: (Ejm.Empacador) \n");
    gets(ayudante->Tope->puesto);
    printf("\n Ingrese la funcion que cumple en ese puesto: (Ejm. Colaboro con...) \n");
    gets(ayudante->Tope->funcionPuesto);
    printf("\n Ingrese la fecha en la que empezó a trabajar con santa: (Ejm. 20/12/2020) \n");
    gets(ayudante->Tope->fechaComienzo);
    
    if(ayudante->Tope==NULL);{
		ayudante=ayudante->Tope;
	}
	else{
		ayudante->Tope=ayudante->Tope->siguiente;
		ayudante=ayudante->Tope; 	
	}

    //guardarMiembro(miembro);
    //free(miembro);
    getchar();
}

/*
	Entradas: 
	Salidas:
	Restricciones: 
*/
void eliminarInfoAyudante(){
	system( "CLS" );
    printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Registro de Ayudantes de Santa\n");
	printf("*********************************\n");
	
	printf("Ingrese la identificacion del ayudante que desea eliminar:");
	char consulta[15];
	gets(consulta);

    struct PilaAyudantes *ayudante;
    struct AydanteSanta *i;
    
    ayudante=(struct PilaAyudantes *) malloc (sizeof(struct PilaAyudantes));
 
    i=ayudante->Tope;
    
    for(i ; i==NULL ; i->siguiente){
  		if (strcmp(consulta,i->identificacion)==1){
  			printf("Se a eliminado el ayudante: %s", i->nombre);
		  	free(i);	
		  }	
	}

}


int main(){ 

	MenuPrincipal();    
	return 0; 
}
