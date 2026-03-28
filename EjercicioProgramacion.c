/*
FACULTAD DE INGENIERÍA Y CIENCIAS APLICADAS
        INGENIERÍA DE SOFTWARE
            PROGRAMACIÓN I
Ejercicio de Programación Cooperativo
Autores: 
    David Cañizares 
    Sebastián Orbe
    Derek Yépez.
Fecha: 2026-03-26.

========= GESTIÓN DE VENTAS DE UN PRODUCTO =======

*/

//Inclusión de librerías
#include <stdio.h> 
#include <conio.h>
#include <string.h>

//Funciones a utilizar
void mostrarMenu();
void mostrarSubMenu();

int main(){
    int opcion, stock=0, cantidadVender=0, reabastecimiento, ventasTotales=0, descuento;
    float precio, ganancia=0, valorDescuento, pcondes;
    char nombre[20]; //Se declara una cadena de 20 caracteres
    char id[20]; //Se declara y crea una variable que almacene el ID (alfanumerico)

    //Preguntar los datos iniciales (obligatorio al iniciar, pero pueden cambiarse luego)

    printf("==== DATOS DEL PRODUCTO ====\n");

    printf("ID: "); 
    fgets(id, 20, stdin); //Se usa fgets en vez de scanf para leer más de una palabra

    printf("Nombre: "); 
    fgets(nombre, 20, stdin);


    printf("Stock: ");
    scanf("%d", &stock);
    while(stock < 0){   //Se valida que el stock no sea menor que 0 (negativo)
        printf("Dato invalido. Ingrese un numero positivo: ");
        scanf("%d", &stock);
    }

    printf("Precio Unitario: ");
    scanf("%f", &precio);
    while(precio <= 0){
        printf("Dato nulo o negativo. Vuelva a ingresar el precio: ");
        scanf("%f", &precio);
    }

    do{ //Se crea un lazo "do-While" para mostrar el menú y las opciones mientras se cumpla una condición dada.
        mostrarMenu(); //Se invoca a la función que muestra el menú (void).
        scanf("%d", &opcion);

        while(opcion > 6 || opcion < 1){ //Validación de entrada del menú. Se evalúa que se escoja de 1 a 6.
            printf("Dato invalido. Vuelva a ingresar una opcion: ");
            scanf("%d", &opcion);
        }

        switch(opcion){
            case 1: //Modificar los datos manualmente
                printf("Que desea hacer? (0 para cancelar)\n");
                printf("1. Registrar un nuevo producto (toda la informacion actual se eliminara)\n");
                printf("2. Cambiar datos del producto actual (se conservara la informacion actual)\n");
                scanf("%d", &opcion);

                while(opcion > 2 || opcion < 0){ 
                printf("Dato invalido. Vuelva a ingresar una opcion: ");
                scanf("%d", &opcion);
                }
                if (opcion == 0){
                    break;
                }

                switch(opcion){
                    case 1:
                        printf("==== DATOS DEL PRODUCTO ====\n");

                        printf("ID: "); 
                        fgets(id, 20, stdin);

                        printf("Nombre: "); 
                        fgets(nombre, 20, stdin);


                        printf("Stock: ");
                        scanf("%d", &stock);
                        while(stock < 0){
                            printf("Dato invalido. Ingrese un numero positivo: ");
                            scanf("%d", &stock);
                        }

                        printf("Precio Unitario: ");
                        scanf("%f", &precio);
                        while(precio <= 0){
                            printf("Dato nulo o negativo. Vuelva a ingresar el precio: ");
                            scanf("%f", &precio);
                        }

                        ventasTotales=0;
                        ganancia=0;

                        break;
                    
                    case 2:
                        mostrarSubMenu(); //Se invoca la funcion que llama el submenu de la opcion 1
                        scanf("%d", &opcion);

                        while(opcion > 4 || opcion < 1){ 
                        printf("Dato invalido. Vuelva a ingresar una opcion: ");
                        scanf("%d", &opcion);
                        }
                        
                        switch (opcion){
                        case 1:
                            printf("Nombre: "); 
                            fgets(nombre, 20, stdin);                            
                            break;

                        case 2:
                            printf("ID: "); 
                            fgets(id, 20, stdin);
                            break;

                        case 3:
                            printf("Stock: ");
                            scanf("%d", &stock);
                            while(stock < 0){
                                printf("Dato invalido. Ingrese un numero positivo: ");
                                scanf("%d", &stock);
                            }
                            break;

                        case 4:
                            printf("Precio Unitario: ");
                            scanf("%f", &precio);
                            while(precio <= 0){
                                printf("Dato nulo o negativo. Vuelva a ingresar el precio: ");
                                scanf("%f", &precio);
                            }
                            break;
                        }
                        break; 
                }        
                break;  

            case 2: //Vender unidades de producto.
                printf("\n==== VENTA DE PRODUCTO ====\n");
                printf("Ingrese la cantidad a vender: (0 para cancelar)\n ");
                scanf("%d", &cantidadVender);

                while(cantidadVender < 0){ //Se valida que la cantidad a vender no sea negativa. Y se vuelve a pedir la cantidad.
                    printf("Dato negativo invalido. Vuelva a ingresar.\n");
                    printf("Ingrese la cantidad a vender: ");
                    scanf("%d", &cantidadVender);
                }

                if (cantidadVender == 0){
                    break;
                }

                if(cantidadVender > stock || stock == 0){ //Se valida que exista suficiente stock para realizar la venta.
                    printf("No existe suficiente stock para realizar la venta.\n");
                    printf("Stock actual: %d\n", stock);
                } else { //En el caso de que el stock sea mayor a la venta, se venden dichas unidades y se disminuye el stock.

                        printf("Desea agregar un porcentaje de descuento a la compra?\n");
                        printf("1.Si\n");
                        printf("2.No\n");
                        printf("Ingrese una opcion: ");
                        scanf("%d", &descuento);
                    while(descuento>2 || descuento<1){
                        printf("Dato invalido. Vuelva a ingresar una opcion: 1.Si o 2.No\n");
                        printf("Ingrese una opcion: ");
                        scanf("%d", &descuento);
                    }                  

                    if(descuento==1){
                        printf("Ingrese el valor del descuento:\n");
                        printf("Descuento: ");
                        scanf("%f", &valorDescuento);
                        while(valorDescuento < 0){
                            printf("Dato negativo invalido. Vuelva a ingresar.\n");
                            printf("Ingrese el valor del descuento:\n");
                            printf("Descuento: ");
                            scanf("%f", &valorDescuento);
                        }
                        pcondes = precio-(precio*(valorDescuento/100));
                        ganancia += (pcondes * cantidadVender);
                    } else {
                        ganancia += (cantidadVender * precio);
                    }
                        
                    printf("%d UNIDADES VENDIDAS DE %s\n", cantidadVender, nombre);
                    stock -= cantidadVender;
                    ventasTotales += cantidadVender; //Se acumula la cantidad de ventas realizadas para calcular las totales.
                }
                break;

            case 3: //Reabastecer producto.
                printf("\n==== REABASTECER PRODUCTO ====\n");
                printf("Ingrese la cantidad a agregar al stock: (0 para cancelar)\n "); //Se pide la cantidad a agregar al stock.
                scanf("%d", &reabastecimiento);

                if (reabastecimiento == 0){
                    break;
                }

                while(reabastecimiento < 0){ //Se valida que el dato ingresado no sea negativo o 0. Y se vuelve a pedir el dato.
                    printf("Dato invalido. Ingrese un valor positivo.\n");
                    printf("Ingrese la cantidad a agregar al stock: ");
                    scanf("%d", &reabastecimiento);
                }
                stock += reabastecimiento; //Se suma la cantidad reabastecida al stock.

                printf("==== HA AGREGADO %d UNIDADES AL STOCK! ====\n", reabastecimiento);
                break;

            case 4: //Consultar información actualizada del producto.
                printf("\n>>>>>> %s \n", nombre); 
                //Se imprimen sus características actualziadas.
                printf("ID: %s", id);
                printf("Nombre: %s", nombre);
                printf("Stock: %d\n", stock);
                printf("Precio Unitario: $%.2f\n", precio);
                printf("Cantidad Vendida: %d", ventasTotales); //Adcicionalmente se muestra la cantidad vendida de producto,

                break;

            case 5: //Calcular y mostrar las ganancias obtenidas.
                printf("\n==== GANANCIAS OBTENIDAS ====\n");
                printf("Ventas Totales: %d\n", ventasTotales); //Se muestra adicionalmente las ventas.
                printf("Ganancia Total: $%.2f\n", ganancia);

                break;

            case 6: //Salir del programa
                printf("\n==== ORBSTORE A SU SERVICIO ====\n");
                printf("Saliendo del programa...\n");
                break;
        }
    }while(opcion!=6); //mientras la opción sea diferente de 6, el bucle se seguirpa repitiendo.
    
    getch(); //obtiene un dato aleatorio para cerrar el ejecutable cuando esto se realize y evitar problemas con el .exe

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
    printf("1. Cambiar datos del producto.\n");
    printf("2. Vender Unidades del Producto.\n");
    printf("3. Reabastecer el producto\n");
    printf("4. Consultar Informacion Actualizada del Producto\n");
    printf("5. Mostrar Ganancias Obtenidas\n");
    printf("6. Salir del Programa.\n");
    printf("Seleccione una opcion: ");

}

//Procedimiento que muestra el submenu para la opcion 1 del programa
void mostrarSubMenu(){
    printf("Elija el dato que desee cambiar: \n");
    printf("1. Nombre del producto\n");
    printf("2. ID del producto\n");
    printf("3. Stock del producto\n");
    printf("4. Precio unitario del producto\n");
    printf("Seleccione una opcion: ");
}