#include <stdio.h>
#include <stdlib.h>

// Definimos las funciones del código

void funcionSalir();
int verificarPrimo(int num, int medio);
void descomponerPrimo(int numero, int divisor);
void descomponerPrimoAux(int numero);

void funcionSalir(){ // Función para finalizar el código
  printf("Programa Finalizado\n");
  exit(-1); // Finaliza el código, de la librería stdolib.h
}

int verificarPrimo(int num,int medio){ // Creamos una función para verficar si un número es primo.

  // Casos

  // Caso Número 1
  if(medio==1) // Sabemos que i es la división entre 2 de nuestro número, y esto será 1 solo si nuestro número num es 2, con esto establecemos que el número 2 será necesariamente un número primo.
    return 1; // y básicamente el único primo par.

  // Caso Número 2
  else if (num <= 1) // Inmediatamente debemos establecer un caso base para nuestra recursión, nuestro número a evaluar no debe ser menor o igual a 1.
    return 0;

   else // Cuando no se llega a ningún caso base, se inicia la recursión
      if(num%medio==0) // Si el resto entre el número y la mitad de este es 0, significará que el número es un compuesto
        return 0;
      else
        verificarPrimo(num,medio-1); // Se vuelve a llamar a la función con el mismo número inicial pero con la mitad del número -1, es decir: n/2-1... n/2-2... n/2-3... n/2-n.

}

void descomponerPrimo(int numero, int divisor){
  // En el primer argumento pasamos el número completo, es decir, el número de entrada inicial.
  // En el segundo argumento pasamos nuestro divisor inicial, por deducción sabemos que dividiendo un número n, su factor para encontrar a n, será el divisor*n
  // ya sabiendo eso, necesitaremos el factor más bajo que pueda existir para nuestro número compuesto, en este caso será el número 2, ya que el 2 es un número primo
  // y además necesariamente deberá dividir a nuestro número compuesto si es mayor que 2 y además es compuesto, como podría ser en el caso del 4 o del 6...

  if (divisor == 1) // Establecemos el caso base de nuestra función
    printf("Descomposición Finalizada\n");

  int retorno;

  retorno = verificarPrimo(divisor, divisor/2); // Hacemos la verficación del número primo

  if (retorno == 1){ // En este caso, cuando retorne 1 el número a verficar será primo, por lo tanto pasará lo siguiente:
    if (numero%divisor == 0){ // En el caso de que no exista resto entre el número y nuestro divisor, mostará por pantalla el número divisor.
    printf("\n");
    printf("%i\n",divisor);
    printf("\n");
    descomponerPrimo(numero/divisor, divisor); // Como se puede dividir, hacemos el mismo proceso para el mismo divisor hasta llegar al siguiente caso.
    }

  else
    descomponerPrimo(numero, divisor-1); // Como sabemos que el resto es diferente de 0, es decir que numero%divisor == 1 o n número natural, significará que la división no será entera
    // y esto significará que debemos buscar otro número para seguir dividiendo a nuestro número.
  }

  else if (divisor > 1)
    descomponerPrimo(numero, divisor-1); // Esto sucederá en el caso de que el retorno sea un número par, pero antes debemos verificar que el número sea mayor a 0 para no caer en un bucle

}

void descomponerPrimoAux(int numero){

  descomponerPrimo(numero, numero/2); // Nuestra función sin retorno tendrá el objetivo de llamar a la función de descomposición con dos argumentos, esto para establecer nuestro caso base y comparar
  // y para escribir correctamente nuestra recursión

  return;

}

int main(){

   int numero, medio, retorno; // Declaramos variables que utilizaremos
   printf("Ingresa un número: "); // Mostramos lo que vamos a solicitar
   scanf("%d",&numero); // Guardamos el tipo de dato entero en una variable numero

   if (numero == 1){
     printf("El número %i no es un número primo ni compuesto\n", numero); // El número 1 es el único número que no es primo ni compuesto, por lo tanto si es ingresado, queda descartado automáticamente
     funcionSalir();}

   if (numero == 0){
     printf("El número %i es un número neutro\n", numero); // El número 0 es un número neutro y además no existe declarada en la aritmética la división por 0, por lo tanto no podemos descomponerlo.
     funcionSalir();}


   medio = numero/2; // Guardamos la mitad del número obtenido para posteriormente obtener el retorno de nuestra función de verificación por recursión.

   retorno = verificarPrimo(numero,medio); // Guardamos el retorno de nuestra función en una variable para comparar y hacer algo en cada caso, respectivamente.

   if (retorno == 1)
     printf("El número %i es un número primo, por lo tanto sólo se puede descomponer por %i\n", numero, numero); // Cuando nuestra función nos retorna 1, significará que el número es un número primo, por lo tanto
     // el proceso no puede seguir y no podremos descomponer.

   else{ // Cuando obtenemos otro retorno que sea diferente de 1, es decir, será y es necesariamente 0, significará que el número será un número compuesto, ya sabiendo esto podemos aplicar el teorema
   // fundamental de la aritmética, que nos dice que cualquier número n compuesto, puede ser escrito como factor de números primos.
   printf("Los factores primos que componen al número %i son los números: \n", numero); // Mostramos un mensaje para señalar que los siguientes serán los números primos factores de n compuesto.
   descomponerPrimoAux(numero); // Llamamos a nuestra función auxiliar para la descomposición.
   funcionSalir();
    }

  return 0;
}
