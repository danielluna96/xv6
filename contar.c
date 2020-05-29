#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  if(argc == 1){ //Se revisa que la cantidad de argumentos es 1, si es 1, ejecuta contar(0). Al recibir 0, se desplegaran todas las llamadas del sistema
  	contar(0);
  }	
  else if(argc == 2){//Revisa que la cantidad de argumentos son 2, toma el segundo argumento y lo pasa a contar()
     contar(atoi(argv[1]));
  }
  else{ //De no ser un caso anterior, ejecuta como debe usarse el comando
    printf(2, "Usage: contar [syscallid]\n");
    
  }
  exit();
}
