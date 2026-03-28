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

#include <stdio.h> 
#include <conio.h>
#include <string.h>

// Prototipos — ESTO es lo que faltaba para poder compilar
void mostrarMenu();
void mostrarSubMenu();

int main(){
    int opcion, stock=0, cantidadVender=0, reabastecimiento, ventasTotales=0, descuento;
    float precio, ganancia=0, valorDescuento, pcondes;
    char nombre[20];
    char id[20];

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

    do{
        mostrarMenu();
        scanf("%d", &opcion);

        while(opcion > 6 || opcion < 1){
            printf("Dato invalido. Vuelva a ingresar una opcion: ");
            scanf("%d", &opcion);
        }

        switch(opcion){
            case 1:
                printf("¿Que desea hacer? (0 para cancelar)\n");
                printf("1. Registrar un nuevo producto (toda la información actual se eliminará)\n");
                printf("2. Cambiar datos del producto actual (se conservará la información actual)\n");
                scanf("%d", &opcion);

                while(opcion > 2 || opcion < 0){ 
                    printf("Dato invalido. Vuelva a ingresar una opcion: ");
                    scanf("%d", &opcion);
                }

                if(opcion == 0){
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
                        mostrarSubMenu();
                        scanf("%d", &opcion);

                        while(opcion > 4 || opcion < 1){ 
                            printf("Dato invalido. Vuelva a ingresar una opcion: ");
                            scanf("%d", &opcion);
                        }
                        
                        switch(opcion){
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

            case 2:
                printf("\n==== VENTA DE PRODUCTO ====\n");
                printf("Ingrese la cantidad a vender: (0 para cancelar)\n ");
                scanf("%d", &cantidadVender);

                while(cantidadVender < 0){
                    printf("Dato nulo o negativo. Vuelva a ingresar.\n");
                    printf("Ingrese la cantidad a vender: ");
                    scanf("%d", &cantidadVender);
                }

                if(cantidadVender == 0){
                    break;
                }

                if(cantidadVender > stock || stock == 0){
                    printf("No existe suficiente stock para realizar la venta.\n");
                    printf("Stock actual: %d\n", stock);
                } else {
                    printf("¿Desea añadir un porcentaje de descuento a la compra?\n");
                    printf("1.Si\n");
                    printf("2.No\n");
                    printf("Ingrese una opción: ");
                    scanf("%d", &descuento);

                    while(descuento > 2 || descuento < 1){
                        printf("Dato invalido. Vuelva a ingresar una opcion: 1.Si o 2.No\n");
                        printf("Ingrese una opción: ");
                        scanf("%d", &descuento);
                    }

                    if(descuento == 1){
                        printf("Ingrese el valor del descuento:\n");
                        printf("Descuento: ");
                        scanf("%f", &valorDescuento);
                        pcondes = precio - (precio * (valorDescuento / 100));
                    }

                    printf("%d UNIDADES DE %s VENDIDAS!\n", cantidadVender, nombre);
                    stock -= cantidadVender;
                    ventasTotales += cantidadVender;
                    ganancia += (cantidadVender * precio);
                }
                break;

            case 3:
                printf("\n==== REABASTECER PRODUCTO ====\n");
                printf("Ingrese la cantidad a agregar al stock: (0 para cancelar)\n ");
                scanf("%d", &reabastecimiento);

                if(reabastecimiento == 0){
                    break;
                }

                while(reabastecimiento < 0){
                    printf("Dato nulo o invalido. Ingrese un valor positivo.\n");
                    printf("Ingrese la cantidad a agregar al stock: ");
                    scanf("%d", &reabastecimiento);
                }
                stock += reabastecimiento;

                printf("==== HA AGREGADO %d UNIDADES AL STOCK! ====\n", reabastecimiento);
                break;

            case 4:
                printf("\n====== %s ======\n", nombre);
                printf("ID: %s\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock: %d\n", stock);
                printf("Precio Unitario: $%.2f\n", precio);
                break;

            case 5:
                printf("\n==== GANANCIAS OBTENIDAS ====\n");
                printf("Ventas Totales: %d\n", ventasTotales);
                printf("Ganancia Total: $%.2f\n", ganancia);
                break;

            case 6:
                printf("\n==== ORBSTORE A SU SERVICIO ====\n");
                printf("Saliendo del programa...\n");
                break;
        }
    }while(opcion != 6);
    
    getch();
    return 0;
}

void mostrarMenu(){
    printf("\n===============================\n");
    printf("            ORBSTORE             \n");
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

void mostrarSubMenu(){
    printf("Elija el dato que desee cambiar: \n");
    printf("1. Nombre del producto\n");
    printf("2. ID del producto\n");
    printf("3. Stock del producto\n");
    printf("4. Precio unitario del producto\n");
    printf("Seleccione una opción: ");
}