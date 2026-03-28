# ORBSTORE
## Gestión de Ventas de Producto Único
## Autores
- ***David Cañizares***
- ***Sebastián Orbe***
- ***Derek Yépez***
## Descripción General
Este es un programa desarrollado en lenguaje C diseñado para ayudar a un pequeño comerciante a administrar el flujo de inventario y ventas de un producto específico de manera eficiente y sencilla.

## Problema que soluciona
Un comerciante necesita una herramienta digital que sustituya el registro manual para:
- Registrar un producto con su ID, nombre, stock inicial y precio.
- Controlar las ventas verificando la disponibilidad en tiempo real.
- Reabastecer el inventario cuando sea necesario.
- Visualizar reportes de ganancias acumuladas.

## Características Principales
- **Interfaz por Consola**: Menú interactivo y repetitivo fácil de navegar.
- **Validación de Datos**: El sistema impide el ingreso de valores negativos en stock, precios o cantidades de venta.
- **Control de Flujo**: No permite realizar operaciones de venta o consulta si el producto no ha sido registrado previamente (usando una variable bandera nombrada auxiliarProd).
- **Cálculo Automático**: Genera el total de ganancias multiplicando las unidades vendidas por el precio unitario establecido.

## Herramientas Utilizadas
- **Lenguaje:** C
- **Librerías Estándar:** stdio.h, string.h
- **Librerías Específicas (Windows):** conio.h (utilizada para mejorar la experiencia en el ejecutable .exe).

## Uso del Programa
Al iniciar, se presentará el menú de OrbStore:

- **Registrar Datos:** El primer paso obligatorio. Define qué vendes y a cuánto.
- *Cambiar datos del producto:* Es posible cambiar información eligiendo entre 2 opciones (agregar nuevo producto o cambiar un aspecto específico).
- **Vender Unidades:** Resta unidades del stock y suma a las ganancias.
- *Agregar un descuento:* Es posible agregar un descuento en cada compra.
- **Reabastecer:** Incrementa el stock disponible.
- **Consultar Información:** Muestra el estado actual del producto (ID, Nombre, Stock, Precio y Ventas).
- **Mostrar Ganancias:** Reporte financiero rápido.
- **Salir:** Cierra la aplicación y deja un mensaje de gracias por el uso.
