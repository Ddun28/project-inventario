//Daniel Dun seccion 1410112 C.I: 30.260.351

#include <stdio.h>
 #include <stdlib.h>
 #include <windows.h>
 #include <conio.h>
 #include <direct.h>
 #include <time.h>
 #include <string.h>
 #include <iostream>
     
 //DECLARACION DE MÒDULOS
  void registrar();
  void consultar();
  void modificar();
  void desincorporar();
  void lista();

   struct {
   char NBP[6];    //Numero de bien pubico
   int NEQ;         //Numero de equipo.
   char USEQ[20];  //Nombre de usuario
   char DPTO[30];  //departamento
   char Fereg[9];  //Fecha de registro.
   char Femod[9];  //Fecha de modificacion
   char Fcdes[9];  //Fecha de desincoporacion
 } PC;

 //Declaracion de alias
 FILE* archi;
 FILE* auxi;
 FILE* desin;

 //DECLÄRACION DE VARIABLES
 int Opc, Opcion1, Opcion2, Opcion3, op4,Re;
 char BBP[6];

 time_t tiempo=time(0);
 struct tm *tlocal=localtime(&tiempo);
 //Programa Principal
 int main ( ){
 do{
     system("cls");
     system("COLOR ED");
     printf("\t\t*******************************************************\n\n");
     printf("\t\t\t\tCONTROL DE INVENTARIO DE EQUIPOS\n\n");
     
     printf("\t\t\t1.INGRESAR DATOS DE UN EQUIPO\n");
     printf("\t\t\t2.CONSULTAR DATOS DE UN EQUIPO\n");
     printf("\t\t\t3.MODIFICAR DATOS DEL REGISTRO DE UN EQUIPO\n" );
     printf("\t\t\t4.DESINCORPORAR UN EQUIPO DEL INVENTARIO\n");
     printf("\t\t\t5.LISTADO DE EQUIPOS \n");
     printf("\t\t\t6.SALIR.\n\n");
     
     printf("\t\t\t\t\telija una opcion: ");
     scanf("%d",&Opc);
     switch(Opc){
         case 1 :    
             registrar();
             break;

         case 2 :    //
             consultar();
             break;

         case 3 :    
             modificar();
             break;

         case 4 :    //
             desincorporar();
             break;

         case 5 :    //
             lista();
             break;

         case 6 :
             printf ("\t\t\t\t \n\n\n Saliendo");
             Sleep(600);
             break;
     
         default :  //
              printf ("\t\t\t\t\n\n\nOpcion invalida!\n");
              printf ("\t\t\t\t\n\n\n");
              system ("pause");
              break;
     }   
   }while (Opc!= 6);
 } //fin del main

 //MÒDULOS

 void registrar() {
     system("cls");  
     system("COLOR B0");
     mkdir ("Inventario");
     archi=fopen("archivoInventario.txt", "a+");    
   do{
     printf("\t\t\t\tREGISTRO DE DATOS DE UN EQUIPO\n\n\n\n");
     
     printf("\t\tINGRESE NBP DEL EQUIPO:");
     fflush(stdin);
     scanf("%s",PC.NBP);

     printf("\t\tINGRESE NUMERO DEL EQUIPO:");
     fflush(stdin);
     scanf("%d",&PC.NEQ);

     printf("\t\tINGRESE NOMBRE DEL USUARIO DEL EQUIPO:");
     fflush(stdin);
     gets(PC.USEQ);

     fflush(stdin);  
     printf("\t\tINGRESE DEPARTAMENTO:");
     gets(PC.DPTO);

     //Para guardar fechas del registro

     strftime (PC.Fereg, 9,"%d/%m/%y",tlocal);
     strcpy (PC.Femod, "00/00/00");
     strcpy (PC.Fcdes, "00/00/00");  

        fprintf(archi,"%s %d %s %s %s %s %s\n",PC.NBP, PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg, PC.Femod, PC.Fcdes);

         printf("\n\n\t\t\t\t\tDATOS  GUARDADOS EXITOSAMENTE\n");
         printf("\n\n\t\t\t\tDESEA REGISTRAR OTRO EQUIPO? (1 PARA SI): ");
         //fflush(stdin);
         scanf("%d",&Opcion1);
       system("cls");  
     }while(Opcion1==1);
      fclose(archi);
      return;
 }

 void consultar(){
  system("COLOR B0");
  system("cls");
  printf("\n\n\nConsultar de Equipos\n\n");
  archi=fopen("archivoInventario.txt", "r");
  fflush(stdin);
  scanf("%s", BBP);
  Re=0;
  int compa;
      do{
        fscanf(archi ,"%s %d %s %s %s %s %s\n",PC.NBP,&PC.NEQ,PC.USEQ,PC.DPTO,PC.Fereg);
  compa=strcmp(BBP,PC.NBP);
    if(compa==0){
        Re=1;
        printf("\t\t\t Numero de Bien Publico: %s\n", PC.NBP);
        printf("\t\t\t Numero del Equipo %s\n", PC.NEQ);
        printf("\t\t\t Usuario %s\n", PC.USEQ);
        printf("\t\t\t Departamento %s\n", PC.DPTO);
        printf("\t\t\t Fecha de Registro %s\n", PC.Fereg);
        printf("\t\t\t Fecha de Modificacion %s\n", PC.Femod);
        printf("\t\t\t Fecha de Desincorporacion %s\n", PC.Fcdes);
        printf("\t\n\n");
        system("pause");
    }
     if(Re==0 && !feof(archi)){
        printf("\n\n\t Registro No encontrado");
        system("pause");
     }
      }while(Re==0 && !feof(archi));
      fclose(archi);
      return;
 }                   

void modificar(){
  system("cls");
  system("COLOR B0");
  Re=0;
  int compa;
    
 printf("\t\t\t\tMODIFICAR DATOS DE UN EQUIPO\n\n");
 archi=fopen("archivoInventario.txt","r");
 auxi=fopen("InventarioAux.txt","a+");
 printf("Ingrese el numero de Bien Publico:");
 fflush(stdin);
 scanf("%s",BBP);
  do{
 fscanf(archi,"%s %d %s %s %s %s %s\n",PC.NBP, &PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg);
 compa=strcmp(BBP,PC.NBP);
 if(compa==0){
    Re=1;
   do{
 printf("\t\t\tDatos modificables:\n\n");
 printf("\n\t\t1. Numero Del Equipo: %d",PC.NEQ);
 printf("\n\t\t2. Nombre del usuario del Equipo : %s",PC.USEQ);
 printf("\n\t\t3. Departamento: %s",PC.DPTO);
 printf("\n\t\t4. Salir del modulo de modificacion de datos");
 printf("\n\n\n\t\t\t\tOpcion:   ");
 scanf("%d",&Opcion2);
 switch  (Opcion2){
 case 1:
 printf("Nuevo Numero del Equipo:");
 fflush(stdin);
 scanf("%d",&PC.NEQ);
 break;
 case 2:
 printf("Nuevo nombre de usuario del equipo:");
 fflush(stdin);
 gets(PC.USEQ);
 break;

 fclose(archi);
 fclose(auxi);
 case 3:
 fflush(stdin);
 printf("\nNUEVO DEPARTAMENTO:");
 gets(PC.DPTO);
 break;
 case 4:
 strftime(PC.Femod,9,"%d/%m/%y",tlocal);
 printf("Datos modificados correctamente!\n");
 system ("pause");
 break;
 default :
 printf("\n\n\t\tOpcion Invalida \n");
 system ("pause");
 break;
 }
 if(Re==0 && feof(archi)){
 printf("\n\n\t\t\tRegistro de equipo no encontrado\n\n");
 system ("pause");
      }
    }while(Opcion2 != 4);
 }
 fprintf(auxi,"%s %d %s %s %s %s %s\n",PC.NBP, PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg);
 }while(!feof(archi));

 fclose(archi);
 fclose(auxi);
  remove("archivoInventario.txt");
  rename("InventarioAux.txt","archivoInventario.txt");
  return;
 }
  void desincorporar ()
     
{
         
system("cls");
 system("COLOR 75");
 printf("\t\t\t\tDesincorporacion de equipos\n\n");
 archi=fopen("archivoInventario.txt","r");
 auxi=fopen("InventarioAux.txt","a");
 desin=fopen("InventarioDesi.txt","a");
 fflush(stdin);
 printf("\n\n\t\tIngrese el numero de Bien Publico:");
 fflush(stdin);
 scanf("%s",BBP);
 Re=0;
 int compa;
 do{
 fscanf(archi,"%s %d %s %s %s %s %s\n",PC.NBP, &PC.NEQ, PC.USEQ, PC.DPTO, PC.Fcdes);
 compa=strcmp(BBP,PC.NBP);
 if(compa==0){
Re=1;    
printf("\n\t\tNumero del Bien Publico: %s",PC.NBP);
 printf("\n\t\tNumero del Equipo: %d",PC.NEQ);
 printf("\n\t\tUSUARIO:  %s",PC.USEQ);
 printf("\n\t\tDepartamento: %s",PC.DPTO);
 printf("\n\t\tFecha de Registro: %s",PC.Fereg);
 printf("\n\t\tFecha de modificacion del Registro: %s",PC.Femod);
 printf("\n\t\tFECHA DE DESINCORP. DEL EQUIPO: %s",PC.Fcdes);
 do{
 printf("\n\n\t\t1.DESINCORPORAR ESTE EQUIPO?\n");
 printf("\n\t\t2.SALIR SIN DESINCORPORAR\n");
 printf ("\n\n\t\tOpcion: ");
 scanf("%d",&Opcion3);
 switch  (Opcion3) {
 case  1:
 printf("\n\n\t\tEQUIPO DESINCORPORADO!\n");
 strftime (PC.Fcdes,9,"%d/%m/%y",tlocal);
 fprintf(desin,"%s %d %s %s %s %s %s\n",PC.NBP, &PC.NEQ, PC.USEQ, PC.DPTO, PC.Fcdes);
 compa=strcmp(BBP,PC.NBP);
 system("pause");
 break;
 case  2:
 fprintf(auxi,"%s %d %s %s %s %s %s\n",PC.NBP, &PC.NEQ, PC.USEQ, PC.DPTO, PC.Fcdes);
 printf("\n\n\t\tREGISTRO NO ELIMINADO \n");
 printf("\n\n\t\t");
 system("pause");
 break;
 default :
 printf("\n\n\t\t Opcion invalida!\n");
 printf("\n\n\t\t");
 system("pause");
 break;
 }
 }while(Opcion3 !=1 && Opcion3 !=2) ;
 }
 else{
 fprintf(auxi,"%s %d %s %s %s %s %s\n", PC.NBP, &PC.NEQ, PC.USEQ, PC.DPTO, PC.Fcdes);
 }
 }while (!feof (archi));
 if (Re==0 && feof (archi))
 {printf("\n\n\t\t\tREGISTRO DE EQUIPO NO ENCONTRADO\n\n" );
 printf("\n\n\t\t");
 system ("pause");}
 fclose(archi);
 fclose(auxi);
 fclose(desin);
 remove("archivoInventario.txt");
 rename("InventarioAux.txt","archivoInventario.txt");
 return;
  }
 


void lista(){

  system("cls");    
  system("cls");
 printf("\n\n\t\t\t\tListado de Equipos\n\n");
 archi=fopen("archivoInventario.txt","r");
 printf("\n Numero de Bien Publico    Nro de Equipo   Usuario   Dpto");
do{
               
fscanf(archi,"%s %d %s %s %s %s %s\n", PC.NBP, &PC.NEQ, PC.USEQ, PC.DPTO, PC.Fcdes);  
printf("%s      %d      %s     %s     %s    %s  ");
}while(!feof(archi));
 system ("pause");
 fclose(archi);
  system ("pause");
  return;

}
 
