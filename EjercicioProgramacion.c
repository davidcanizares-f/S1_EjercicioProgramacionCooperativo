/*
FACULTAD DE INGENIERÍA Y CIENCIAS APLICADAS
        INGENIERÍA DE SOFTWARE
            PROGRAMACIÓN I
Ejercicio de Programación Cooperativo
Autores: 
    David Cañizares 
    Sebastián Orbe
    Derek Yánez.
Fecha: 2026-03-26.

========= GESTIÓN DE VENTAS DE UN PRODUCTO =======

*/

//Inclusión de librerías
#include <stdio.h>   //Librería estándar de entrada y salida
#include <conio.h>  //Librería para usar getch() y presentar de mejor manera el archivo ejecutable .exe
#include <string.h> //Librería para manejar cadenas

//Procedimiento que muestra el menú de opciones del programa.
void mostrarMenu();

int main(){
    int auxiliarProd = 0; //Se usa para validar las opciones del menú de la 2 a la 6.
    int opcion, stock=0, cantidadVender=0, reabastecimiento, ventasTotales=0;
    float precio, ganancia=0;
    char nombre[20]; //Se declara un arreglo de caracteres (cadena) con 20 índices (19 espacios para letras), para
                     //asegurar que todas las letras entren dentro de la cadena.
    char id[20]; //Se declara y crea una variable que almacene el ID. Puesto que este puede ser alfanumérico, se declara
                 //como cadena.

    do{ //Se crea un lazo "do-While" para mostrar el menú y las opciones mientras se cumpla una condición dada.
        mostrarMenu(); //Se invoca a la función que muestra el menú.
        scanf("%d", &opcion);

        while(opcion > 6 || opcion < 1){ //Validación de entrada del menú. Se evalúa que se escoja de 1 a 6.
            printf("Dato invalido. Vuelva a ingresar una opcion: ");
            scanf("%d", &opcion);
        }

        switch(opcion){
            case 1: //Registra los datos del producto.
                auxiliarProd = 1; //Se cambia el valor a 1 para "decir" que existe ya un producto registrado.
                ventasTotales = 0; //Se asigna 0 para que se reinicie dicha cantidad en caso de querer sustituir el producto.
                printf("==== DATOS DEL PRODUCTO ====\n");

                printf("ID: "); //Se pide ingreso del ID.
                scanf("%s", id);

                printf("Nombre: "); //Se pide ingreso del nombre del producto.
                scanf("%s", nombre);


                printf("Stock: "); //se pide ingreso del stock
                scanf("%d", &stock);
                while(stock < 0){//Se valida que el stock no sea menor que 0 (negativo)
                    printf("Dato invalido. Ingrese un numero positivo: ");
                    scanf("%d", &stock);
                }

                printf("Precio Unitario: ");
                scanf("%f", &precio);
                while(precio <= 0){
                    printf("Dato nulo o negativo. Vuelva a ingresar el precio: ");
                    scanf("%f", &precio);
                }
                break;

            case 2: //Vender unidades de producto.
                if(auxiliarProd == 1){ //Se valida que primero se registren los datos del producto para realizar la acción.
                    printf("\n==== VENTA DE PRODUCTO ====\n");
                    printf("Ingrese la cantidad a vender: "); //Se pide la cantidad a vender del producto.
                    scanf("%d", &cantidadVender);

                    while(cantidadVender <= 0){ //Se valida que la cantidad a vender no sea negativa. Y se vuelve a pedir la cantidad.
                        printf("Dato nulo o negativo. Vuelva a ingresar.\n");
                        printf("Ingrese la cantidad a vender: ");
                        scanf("%d", &cantidadVender);
                    }

                    if(cantidadVender > stock || stock == 0){ //Se valida que exista suficiente stock para realizar la venta.
                        printf("No existe suficiente stock para realizar la venta.\n");
                        printf("Stock actual: %d\n", stock);
                    } else { //En el caso de que el stock sea mayor a la venta, se venden dichas unidades y se disminuye el stock.
                        printf("%d UNIDADES DE %s VENDIDAS!\n", cantidadVender, nombre);
                        stock -= cantidadVender;
                        ventasTotales += cantidadVender; //Se acumula la cantidad de ventas realizadas para calcular las totales.
                    }

                } else {
                    printf("\nNo existe producto para realizar esta accion.\n");
                }
                break;

            case 3: //Reabastecer producto.
                if(auxiliarProd == 1){
                    printf("\n==== REABASTECER PRODUCTO ====\n");
                    printf("Ingrese la cantidad a agregar al stock: "); //Se pide la cantidad a agregar al stock.
                    scanf("%d", &reabastecimiento);

                    while(reabastecimiento <= 0){ //Se valida que el dato ingresado no sea negativo o 0. Y se vuelve a pedir el dato.
                        printf("Dato nulo o invalido. Ingrese un valor positivo.\n");
                        printf("Ingrese la cantidad a agregar al stock: ");
                        scanf("%d", &reabastecimiento);
                    }
                    stock += reabastecimiento; //Se suma la cantidad reabastecida al stock.

                    printf("==== HA AGREGADO %d UNIDADES AL STOCK! ====\n", reabastecimiento);
                } else {
                    printf("\nNo existe producto para realizar esta accion.\n");
                }
                break;

            case 4: //Consultar información actualizada del producto.
                if(auxiliarProd == 1){
                    printf("\n====== %s ======\n", nombre); //Se imprime el nombre del producto.
                    //Se imprimen sus características actualziadas.
                    printf("ID: %s\n", id);
                    printf("Nombre: %s\n", nombre);
                    printf("Stock: %d\n", stock);
                    printf("Precio Unitario: $%.2f\n", precio);
                    printf("Cantidad Vendida: %d", ventasTotales); //Adcicionalmente se muestra la cantidad vendida de producto,

                } else {
                    printf("\nNo existe producto para realizar esta accion.\n");
                }
                break;
            case 5: //Calcular y mostrar las ganancias obtenidas.
                if(auxiliarProd == 1){
                    ganancia = ventasTotales*precio; //Se multiplica las ventas totales por el precio unitario.
                    printf("\n==== GANANCIAS OBTENIDAS ====\n");
                    printf("Ventas Totales: %d\n", ventasTotales); //Se muestra adicionalmente las ventas.
                    printf("Ganancia Total: $%.2f\n", ganancia);
                } else {
                    printf("\nNo existe producto para realizar esta accion.\n");
                }
                break;
            case 6: //Salir del programa
                printf("\n==== ORBSTORE A SU SERVICIO ====\n");
                printf("Saliendo del programa...\n");
                break;
        }
    }while(opcion!=6); //mientras la opción sea diferente de 6, el bucle se seguirpa repitiendo.
    
    getch(); //obtiene un dato aleatorio para cerrar el ejecutable cuando esto se realize, y así poder visualizar todo
             //el programa.

    return 0;
     
}

//////////////////
//Funciones o procedimientos usados

//Procedimiento que muestra el menú de opciones del programa.
void mostrarMenu(){
    printf("\n===============================\n");
    printf("            ORBSTORE             \n"); //Este es un nombre inventado por nosotros para la tienda ficticia.
    printf("================================");
    printf("\n==== GESTION DE VENTAS ====\n");
    printf("1. Registrar Datos del Producto.\n");
    printf("2. Vender Unidades del Producto.\n");
    printf("3. Reabastecer el producto\n");
    printf("4. Consultar Informacion Actualizada del Producto\n");
    printf("5. Mostrar Ganancias Obtenidas\n");
    printf("6. Salir del Programa.\n");
    printf("Seleccione una opcion: ");

}