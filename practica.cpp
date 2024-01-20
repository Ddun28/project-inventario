#include <stdio.h>
 #include <stdlib.h>
 #include <windows.h>
 #include <conio.h>
 #include <direct.h>
 #include <time.h>
 #include <string.h>
 #include <fstream.h>
     
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

 //DECLÄRACION DE ALIAS
  FILE* archi;
 FILE* auxi;
 FILE* desin;

 //DECLÄRACION DE VARIABLES
 int Opc, Opcion1, Opcion2, Opcion3, op4,RE;
 char BBP[6];

 time_t tiempo=time(0);
 struct tm *tlocal=localtime(&tiempo);
 //PROGRAMA PRINCIPAL
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

     mkdir ("INVENTARIO");
       archi=fopen ("archivoInventario.txt","a+") ;
        fprintf(archi,"%s %d %s %s %s %s %s\n",PC.NBP, PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg, PC.Femod, PC.Fcdes);

         printf("\n\n\t\t\t\t\tDATOS  GUARDADOS EXITOSAMENTE\n");
         printf("\n\n\t\t\t\tDESEA REGISTRAR OTRO EQUIPO? (1 PARA SI): ");
         fflush(stdin);
         scanf("%d",&Opcion1);
       system("cls");  
     }while(Opcion1==1);
      fclose(archi);
      return;
 }

 void consultar(){
    int RE= 1, neq;
  system("cls");
  system("COLOR B0");

      do{
        char CBP[6]
          archi=fopen("archivoInventario.txt", "r");
           printf("\n\n\nConsultar de Equipos\n\n");
           printf("Ingrese Numero de bien publico:");
           cin >> CBP;

       do { int CBP;
           fread(&PC, sizeof(PC), 1, archi);
           CBP = strcmp (PC.NBP, CBP)
           if(CBP == 0){ 
            printf("\n\n\n ", PC.NBP, PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg, PC.Femod, PC.Fcdes);

            RE=1
            if(RE == 0 && eof(){
              printf("\n\n\n\n\n\n\nRegistro no encontrado");
            })
           } 
           }while (!eof());
           
            printf("\n\n\n\n\n\n\nDesea Hacer otra Busqueda? 1 para si")
            char RRC;
           } while (RRC == 1);

           archi.close();
           system ("pause");
            return ;  
       }

void modificar(){
  system("cls")

  ofstream archi;
  archi.open("archivoInventario.txt", ios::in);

  auxi.open("auxiliar.txt", ios::app);

  do{ char MDBP [6], int COMPA, RE;
  cout << "Numero de Bien publico de datos que sea modificar"; 
  cin >> MDBP;
  do{
    archi >> PC.NBP, PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg, PC.Femod, PC.Fcdes
    COMPA = strcmp(PC.NBP, MDBP); // se comparan los elementos
    if(COMPA == 0){
      RE=1;

    do{
      printf("\n\n\n\n\t\tDatos modificables");
      printf("\n\n\n 1 Marca");
      printf("\n\n\n 2 Departamento");
      printf("\n\n\n 3 Usuario");
      printf("\n\n\n 4 Salir");
      printf("\t\tElija dato a modificar");

        cin >> Opcion3;
          
          switch (Opcion3);
          {
          case 1:
          printf("\t\t\n\n Nueva Marca");
          cin >> PC.MARCA;
            break;

          case 2: 
          printf("\t\t\n\n Nuevo Departamento");
          cin >> PC.DPTO;
          break;

          case 3:
          printf("\t\t\n\n Nuevo Usuario"); 
          cin >> PC.USEQ;
            break;

          case 4:
          printf("\t\t\n\n Salir");
          Sleep(600);
          break;

          default :  //
               printf ("\t\t\t\t\n\n\nOpcion invalida!\n");
               printf ("\t\t\t\t\n\n\n");
               Sleep (600);
               break;
      } 
      } while (Opcion3!= 4)   
  }
  if(RE == 0 && archi.eof()){
    printf ("\t\t\t\t\n\n Registro no encontrado");
  } system("pause");
  
  archi << PC.NBP, PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg, PC.Femod, PC.Fcdes; 
  } while (!archi.eof());

  printf("Usted desea modificar otra cosa? 1 para si")
  char OM;

  cin >> OM;

 }whie(OM == '1');

  close(all)
  archi.close();
  auxi.close();

  remove("archivoInventario.txt");
  rename("auxiliar.txt");

  return;

}

void desincorporar(){
  system("cls");
  system("COLOR B0");

  ifstream DESIARCHI("DESINCORPOAR.TXT");
  ifstream DESIAUXI("DESINCORPOAR.TXT");
  ifstream DESIN("DESINCORPORAR.TXT");

  DESIARCHI.open("archivoInventario.txt", ios::in);
  DESIAUXI("auxiliar.txt", ios::app);
  DESIN.open("DESINCORPORAR.TXT", ios::app;);

  do{
    char DBP, RE=0;
    printf("\n\n\n Ingrese el numero de Bien Publico del equipo a desincorporar");
    cin >> DBP;

    do{
      int DESINCOMP;
      DESIARCHI >> PC.NBP, PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg, PC.Femod, PC.Fcdes;

      DESINCOMP = strcmp(PC.NBP, DBP);

      if(DESINCOMP == 0){
        RE=1

        cout << "NBP:" << PC.NBP << endl;
        cout << "\n\n MARCA:" << PC.MARCA << endl;
        cout << "\n\n MODELO:" << PC.MODELO << endl;

        do{
          printf("\n\n Desea desincorporar este equipo?")
          printf("\n\n\n\n\n 1 Para Desincorporar")
          printf("\n\n\n\n\n 2 Para salir sin desincorporar")

          cin >> op4;

          switch (op4)
          {
          case 1:
            strftime(PC.Fcdes, 9, "%d/%m/%y", tlocal);

            desin << PC.NBP, PC.MARCA;
            printf("\n\n Equipos Desincorporados");
            system("pause");
            break;

          case 2:
          DESIARCHI << PC.NBP,  PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg, PC.Femod, PC.Fcdes;
          printf("\n\n\n Saliendo sin desincorporar");
          system("pause");
          break;
          default:
          printf("\n\n Opcion invalida")
            break;
          } 
        } while(op4! && op4!=2);
      }else {
        DESIARCHI << PC.NBP, PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg, PC.Femod, PC.Fcdes;
      }
    }while(!DESIARCHI.eof())
    if (RE == 0 && DESIARCHI.eof());
  {
    printf("\n\n Ese Numero de Bien Publico no esta registrado");
    char op5;

    cout << "Desea repetir este modulo? 1 para si" << endl;
    cin >> op5;
  }
  }while (op5 == '1')
  DESIARCHI.close();
  DESIAUXI.close();
  desin.close();

  remove("archivoInventario.txt");
  rename("auxiliar.txt", "archivoInventario.txt");

  return;
}



void lista(){

  system("cls");
   system("COLOR B0");
  printf("Listado de equipos");

  archi=fopen("archivoInventario.txt", "a+");

  do{
    prinf("%s%s%s%s%s%s \n", ,PC.NBP, PC.NEQ, PC.USEQ, PC.DPTO, PC.Fereg, PC.Femod, PC.Fcdes);
  } 
  while (!eof(archi));

  fclose(archi);
  system ("pause");
  return;

}
 
