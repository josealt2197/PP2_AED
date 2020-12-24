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
	
	struct ListaComport *LComp;
	LComp = (struct ListaComport *) malloc(sizeof(struct ListaComport));
	LComp->inicio = NULL;
	LComp->final = NULL;
	
	struct ListaAyudantes *LAyudantes;
	LAyudantes = (struct ListaAyudantes *) malloc(sizeof(struct ListaAyudantes));
	LAyudantes->inicio = NULL;
	LAyudantes->final = NULL;
	
	
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
                printf("  Descripcion: %s \n", iNino->nombre_completo);
                printf("  Riesgo: %s \n", iNino->correo);
                printf("  Dependencia: %s \n", iNino->codigo_domicilio);
                printf("  Recursos: %s \n", iNino->fecha_nacimiento);
                printf("  Estado: %s \n", iNino->edad);
                printf("  Esfuerzo: %s \n", iNino->necesidades_esp );
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
	
    if(i != NULL)
    {
        while( i= NULL){
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


int main(){ 

	MenuPrincipal();    
	return 0; 
}
