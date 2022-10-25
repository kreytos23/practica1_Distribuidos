
#include <stdio.h>
#include <Socket_Cliente.h>
#include <Socket.h>

main ()
{
	/*
	* Declaramos del socket y buffer para datos
	*/
	int Socket_Con_Servidor;
   int Longitud_Cadena = 0;
   int Aux;
	char Cadena[100];

	/*
	* Se abre la conexion con el servidor, pasando el nombre del ordenador
	* y el servicio solicitado.
	* "localhost" corresponde al nombre del mismo ordenador en el que
	* estamos corriendo. Esta dado de alta en /etc/hosts
	* "cpp_java" es un servicio dado de alta en /etc/services.
   * El servicio debe ser 6000 que es el puerto que va a atender el servidor
   * java.
	*/
	Socket_Con_Servidor = Abre_Conexion_Inet ("localhost", "cpp_java");
	if (Socket_Con_Servidor == 1)
	{
		printf ("No puedo establecer conexion con el servidor\n");
		exit (-1);
	}

   
   Lee_Socket (Socket_Con_Servidor, (char *)&Aux, sizeof(int));
   Longitud_Cadena = ntohl (Aux);
   

   Lee_Socket (Socket_Con_Servidor, Cadena, Longitud_Cadena);
   printf ("Cliente C: Recibido %s\n", Cadena);
   
	
	strcpy (Cadena, "Sistemas Distribuidos");
   Longitud_Cadena = 28;

  
   Aux = htonl (Longitud_Cadena);
   Escribe_Socket (Socket_Con_Servidor, (char *)&Aux, sizeof(Longitud_Cadena));
   

   
	Escribe_Socket (Socket_Con_Servidor, Cadena, Longitud_Cadena);
   printf ("Cliente C: Enviado %s\n", Cadena);

	
	close (Socket_Con_Servidor);
}
