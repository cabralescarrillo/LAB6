
// Laboratorio 6. trabajo realizado donde se debe determinar los dias transcurridos desde una fecha establecida en este caso el nacimiento de una persona
// realizado por Luis Alfredo Cabrales Carrillo
// basado en este trabajo :http://www.cplusplus.com/reference/ctime/difftime/
#include <stdio.h>     
#include <time.h>  //implementamos una nueva libreria que es time.h que sirve para usar los objetos de tiempo unix 
#include <iostream>

using namespace std;
int main ()
{
  time_t now;    //definimos la variable del tiempo actual, el momento en el que se realiza la operación 
  struct tm nacimiento; //con esta funcion se define una estructura con la que definiremos la fecha exacta de donde se empezara a tener en cuent el tiempo 
  double seconds;
  int ano;  //definimos una variable para el año de nacimento 
  int mes;   //definimos una variable para el mes de nacimento
  int dia;  //definimos una variable para el dia de nacimento
  double dias;
  cout<<"año de nacimiento ";   //se le pide al usuario que dijite su año de nacimiento
  cin>>ano;
  cout<<"mes de nacimiento ";  //se le pide al usuario que dijite su mes de nacimiento
  cin>>mes;
  cout<<"dia de nacimiento "; //se le pide al usuario que dijite su dia de nacimiento
  cin>>dia;

  time(&now);  

  nacimiento = *localtime(&now);    

  nacimiento.tm_hour = 0; nacimiento.tm_min = 0; nacimiento.tm_sec = 0;  // con la estructura definida anteriormente aqui empezamos a definor todas las variables de tiempo a las que nos interesan que son año, mes y dia las definimos las demas las rellenamos con 0
  nacimiento.tm_mon = mes-1;  nacimiento.tm_mday = dia+1;  
  nacimiento.tm_year=ano-1900;
  seconds = difftime(now,mktime(&nacimiento));  //la funcion difftime genera la diferencia entre dos momentos definidos despues de unix
  dias=seconds/86400; //convertimos los seguntos obtenidos en dias 

  printf ("%.f dias desde tu fecha de nacimiento.\n", dias); //imprimimos el resultado 

  return 0;
}