#include<stdlib.h>
#include <iostream>
#include<mysql.h>
#include<string.h>
using namespace std;
int q_estado;
MYSQL_ROW fila;
MYSQL_RES * resultado;
MYSQL* conectar;


 int main()
{
	 // aqui se hace la conexion 
	 
	 int opciones;
	 cout << "\t\t\t\t-----ECHO POR EDWARD DANIEL LOPEZ CLAVE PAR TERMINADA EN 0-----\n" << endl;
	 cout << "\t\t-----MENU DE OPCIONES-----\n" << endl;
		 cout << "1. INGRESAR DATOS DE LA TABLA \n" << endl;
			 cout << "2.VER DATOS DE LA TABLA\n" << endl;
				cout << "3.ELIMINAR DATOS DE LA TABLA \n"<<endl;
					 cout << "4. VER DATOS ACTUALIZADOS DE LA TABLA\n" << endl;
						cout << "\n5. salir\n" << endl;
					 cin >> opciones;
					
					 conectar = mysql_init(0);
					 conectar = mysql_real_connect(conectar, "localhost", "root", "12345", "exam", 3306, NULL, 0);
					 string producto, descripcion, imagen, precio_costo, precio_venta, existencia;
					
					 switch (opciones)
					 {
					 case 1:
						 if (conectar) {
							 //cout << "conexion exitosa"<<endl;

							 cout << "\t-----LLene los siguientes datos----- \n" << endl;
							 cout << "ingrese nombre del producto" << endl;
							 cin >> producto;
							 cout << "ingrese la descripcion" << endl;
							 cin >> descripcion;
							 cout << "ingrese la imagen" << endl;
							 cin >> imagen;
							 cout << "ingrese el precio costo del producto" << endl;
							 cin >> precio_costo;
							 cout << "Ingrese el precio venta del producto" << endl;
							 cin >> precio_venta;
							 cout << "cuantos hay en existencia" << endl;
							 cin >> existencia;
							 //string insert ="insert into productos(producto,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingres)values('" + producto + "','" + descripcion + "','" + imagen + "',' + precio_costo + ',' + precio_venta + ',' + existencia + ','fecha_ingres')";
							 string insert = "insert into productos (producto,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingres)values('" + producto + "', '" + descripcion + "', '" + imagen + "', '" + precio_costo + "', '" + precio_venta + "', '" + existencia + "', current_time())";
							 const char* i = insert.c_str();
							 //aqui ejecuta la consulta
							 q_estado = mysql_query(conectar, i);
							 if (!q_estado) {
								 cout << "DATOS INGRESADOS EXISTOSAMENTE" << endl;
								 return main();
							 }
							 else { cout << "NO SE LOGRARON INGRESAR DATOS" << endl; }
						 } break;
					 case 2:
						 if (!q_estado) {

							 cout << "\t-----DATOS DE LA TABLA----- \n" << endl;
							 string consul = "select*from productos";
							 const char* c = consul.c_str();
							 q_estado = mysql_query(conectar, c);
							 resultado = mysql_store_result(conectar);
							 cout << "Id_producto" << "-----" << "Producto" << "-----" << "Descripcion" << "-----" << "Imagen" << "-----" << "Precio_costo" << "-----" << "Precio_venta" << "-----" << "Existencia" << "-----" << "Fecha" << endl;
							 while (fila = mysql_fetch_row(resultado)) {

								 cout << fila[0] << "\n" << fila[1] << "\n" << fila[2] << "\n" << fila[3] << "\n" << fila[4] << "\n" << fila[5] << "\n" << fila[6] << "\n" << fila[7] << endl;
								
							 }
							 return main();
						 }break;

					 case 3:
						 if (!q_estado) {
							 cout << "\t-----Eliminar datos de la tabla por Nombre producto----- \n" << endl;
							 string consuls = "delete  from productos where producto='" + producto + "'";
							 const char* d = consuls.c_str();
							 q_estado = mysql_query(conectar, d);
							 resultado = mysql_store_result(conectar);
							 cout << "ingrese el Nombre del producto para eliminar un producto" << endl;
							 cin >> producto;
							 cout << "\t-----Datos eliminados-----\n" << endl;
							 return main();
						 }
						 else {
							 cout << "No se lograron eliminar los datos" << endl;
						 }break;
					 case 4:
						 if (!q_estado) {
							 cout << "\t-----DATOS DE LA TABLA ACTUALIZADOS----- \n" << endl;
							 string consultar = "select*from productos";
							 const char* n = consultar.c_str();
							 q_estado = mysql_query(conectar, n);
							 resultado = mysql_store_result(conectar);
							 while (fila = mysql_fetch_row(resultado)) {
								 cout << "Id_producto" << "-----" << "Producto" << "-----" << "Descripcion" << "-----" << "Imagen" << "-----" << "Precio_costo" << "-----" << "Precio_venta" << "-----" << "Existencia" << "-----" << "Fecha" << endl;
								 cout << fila[0] << "\n" << fila[1] << "\n" << fila[2] << "\n" << fila[3] << "\n" << fila[4] << "\n" << fila[5] << "\n" << fila[6] << "\n" << fila[7] << endl;
								 return main();

							 }
						 }break;

					 case 5:
						 cout << "DESEA SALIR PRECIONE 0  SI QUIERE REGRESAR AL MENU PRECIONE 6" << endl;
						 if (opciones == 0) { return 0; }
						 break;

					 default: cout << "ESA OPCION NO EXISTE" << endl;
						 return main(); break;


						 }


						 
						 system("pause");
						 return 0;
						 
					 }