
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void juguetesPorAnno(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Juguetes solicitados por Anno\n" );
	printf("*********************************\n");
	
	
	//Mostrar cantidades contadas
	printf("\n+----------------------------------------+\n");
	printf( "  Anno del juguete    -   Cant. Solicitudes" );
	printf("\n+----------------------------------------+\n");		
	
	printf("\n 2020  -  4");
	printf("\n 2019  -  1");
	printf("\n 2018  -  2");

	printf("\n+----------------------------------------+\n");
	
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void masMenosCartas(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Lugares con mas/menos cartas\n" );
	printf("*********************************\n");
	
	printf("+-----------------------------------------+\n");
	printf( " -->Lugar con MENOS Cartas: DOM-001" );
	printf( "\n    -->Total de Cartas: 3" );
	printf("\n+-----------------------------------------+\n");
	printf( " -->Lugar con MAS Cartas: DOM-003" );
	printf( "\n    -->Total de Cartas: 1" );
	printf("\n+-----------------------------------------+\n");
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void aprobadasPorAnno(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Cartas aprobadas por Anno\n" );
	printf("*********************************\n");
	
	//Mostrar cantidades contadas
	printf("\n+----------------------------------------+\n");
	printf( "  Anno de la Carta    -   Cant. Aprobadas" );
	printf("\n+----------------------------------------+\n");
		
	printf("\n 2020  -  2");
	printf("\n 2019  -  0");
	printf("\n 2018  -  1");

	printf("\n+----------------------------------------+\n");
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void rechazadasPorAnno(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("  Cartas Rechazadas por Anno\n" );
	printf("*********************************\n");
	
	
	//Mostrar cantidades contadas
	printf("\n+----------------------------------------+\n");
	printf( "  Anno de la Carta    -   Cant. Rechazadas" );
	printf("\n+----------------------------------------+\n");
		
	printf("\n 2020  -  1");
	printf("\n 2019  -  0");
	printf("\n 2018  -  0");

	printf("\n+----------------------------------------+\n");
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}


/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void comportRegistrados(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf("    Comportamientos Registrados\n" );
	printf("*********************************\n");
	
	
	printf("+-----------------------------------------+\n");
	printf( " -->Total Comportamientos BUENOS: 3" );
	printf("\n+-----------------------------------------+\n");
	printf( " -->Total Comportamientos MALOS: 7" );
	printf("\n+-----------------------------------------+\n");
		
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void cartasPorAyudante(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Cartas procesadas segun Ayudante\n" );
	printf("*********************************\n");
		
	
		
	//Mostrar cantidades contadas
	printf("\n+----------------------------------------+\n");
	printf( "  Identificación    -   Cartas Procesadas" );
	printf("\n+----------------------------------------+\n");
		
	printf("\n 105450658  -  2");
	printf("\n 105450657  -  2");

	printf("\n+----------------------------------------+\n");
	
	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}

/*
	Entradas: 
	Salidas: 
	Restricciones: 
*/
void juguetesMasPedidos(){
	system( "CLS" );
	printf("\n\n*********************************\n");
	printf("        Sistema NaviTEC \n");
	printf("*********************************\n");
	printf(" Top de Juguetes mas solicitados\n" );
	printf("*********************************\n");
	
	
	//Mostrar cantidades contadas
	printf("\n+----------------------------------------+\n");
	printf( "  Nombre del Juguete    -   Cant. Solicitudes" );
	printf("\n+----------------------------------------+\n");
		
	printf("\n Carrito  -  3");
	printf("\n Muneca  -  2");
	printf("\n Bicicleta  -  1");
	printf("\n Peluche  -  1");

	printf("\n+----------------------------------------+\n");

	printf("\n\nPresione una tecla para regresar..." );
	getchar();	
}



int main(){ 

	juguetesPorAnno();
	
	masMenosCartas();

	aprobadasPorAnno();

	rechazadasPorAnno();

	comportRegistrados();
	
	cartasPorAyudante();

	juguetesMasPedidos();
   
	return 0; 
}

