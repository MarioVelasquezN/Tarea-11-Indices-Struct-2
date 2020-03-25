#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <limits>
#include <string.h>
#include <list>
#pragma warning (disable : 4996)
#pragma pack(1)

#define MAX_BUFFER 100

using namespace std;

class Empleado {
private:
	
	

public:
	void Pack();
	void unPack();
	int SIZE;
	char in_buffer[MAX_BUFFER];
	char cedula[13];
	char nombre[10];
	char Apellido[10];
	char direccion[15];
	char ciudad[15];
	char estado[10];
	char zipCode[4];

	Empleado();
	

	void Print();
	void setBBuffer(const char*);
	void Write();
	void GetEmpleadoByName(string);
	int buscarEmpleado(const char*);
	void EliminarRegistro();
	void Compactar();
	void index();
	
};
