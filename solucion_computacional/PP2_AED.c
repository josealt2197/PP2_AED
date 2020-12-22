/*Algoritmos y Estructuras de Datos - Grupo 1
	Proyecto Programado 2 
	Estudiantes: Jose Altamirano Salazar - 2020426159
	             Josué Brenes Alfaro - 2020054427
*/
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Tipos para la gestion de los datos de cada elemento
//typedef struct Requerimiento Requerimiento;

//Procedimientos para Menus de Opciones
void MenuPrincipal();
void GestionNinos();
void GestionJuguetes();
void GestionDomicilios();
void GestionAyudantes();
void GestionCartas();
void AnalisisDeDatos();

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
            case '1': GestionNinos();
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
void GestionNinos(){
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
		printf("\n 2. ELIMINAR informacion de un Ayudante de Santa.");
		printf("\n 3. MODIFICAR informacion de un Ayudante de Santa.");
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


int main(){ 

	MenuPrincipal();    
	return 0; 
}
