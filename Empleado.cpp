#include "Empleado.h"
#include <sstream>
#include <fstream>
#pragma warning (disable : 4996)
using namespace std;


Empleado::Empleado() {
	cedula[0] = 0;
	nombre[0] = 0;
	Apellido[0] = 0;
	direccion[0] = 0;
	ciudad[0] = 0;
	estado[0] = 0;
	zipCode[0] = 0;
	in_buffer[0] = 0;
	//SIZE = 0;
}

void Empleado::Print() {
	cout << cedula << " "
		<< nombre << " "
		<< Apellido << " "
		<< direccion << " "
		<< ciudad << " "
		<< estado << " "
		<< zipCode << "\n"
		<< flush;
}


void Empleado::setBBuffer(const char* buff) {
	memcpy(in_buffer, buff, MAX_BUFFER);
	unPack();
}

void Empleado::unPack() {
	//int size = 0;
	char se = '|';
	char temp[30];
	char *c = in_buffer;
	size_t j = 0;
	int pos = 0;

	for (size_t i = 0; c[i] != se; i++)
	{
		temp[j] = c[i];

		j++;
		pos++;
	}
	temp[j] = '\0';

	strcpy(cedula, temp);

	j = 0;
	pos = pos + 1;

	for (size_t i = pos; c[i] != se; i++)
	{
		temp[j] = c[i];

		j++;
		pos++;
	}
	temp[j] = '\0';

	strcpy(nombre, temp);

	j = 0;
	pos = pos + 1;
	for (size_t i = pos; c[i] != se; i++)
	{
		temp[j] = c[i];
		j++;
		pos++;
	}
	temp[j] = '\0';
	strcpy(Apellido, temp);

	j = 0;
	pos = pos + 1;
	for (size_t i = pos; c[i] != se; i++)
	{
		temp[j] = c[i];
		j++;
		pos++;
	}
	temp[j] = '\0';
	strcpy(direccion, temp);

	j = 0;
	pos = pos + 1;
	for (size_t i = pos; c[i] != se; i++)
	{
		temp[j] = c[i];
		j++;
		pos++;
	}
	temp[j] = '\0';
	strcpy(ciudad, temp);

	j = 0;
	pos = pos + 1;
	for (size_t i = pos; c[i] != se; i++)
	{
		temp[j] = c[i];
		j++;
		pos++;
	}
	temp[j] = '\0';
	strcpy(estado, temp);

	j = 0;
	pos = pos + 1;

	for (size_t i = pos; c[i] != se; i++)
	{
		temp[j] = c[i];
		j++;
		pos++;
	}
	temp[j] = '\0';
	strcpy(zipCode, temp);



}

void Empleado::Pack() {

	strcat(in_buffer, cedula);
	strcat(in_buffer, "|");

	strcat(in_buffer, nombre);
	strcat(in_buffer, "|");

	strcat(in_buffer, Apellido);
	strcat(in_buffer, "|");

	strcat(in_buffer, direccion);
	strcat(in_buffer, "|");

	strcat(in_buffer, ciudad);
	strcat(in_buffer, "|");

	strcat(in_buffer, estado);
	strcat(in_buffer, "|");

	strcat(in_buffer, zipCode);
	strcat(in_buffer, "|");

	SIZE = strlen(in_buffer);

	for (size_t i = SIZE; i < MAX_BUFFER; i++)
	{
		in_buffer[i] = ' ';
	}
}


void Empleado::Write() {
	cout << "Cedula: " << flush; cin.getline(cedula, sizeof(cedula));
	cout << "Nombres: " << flush; cin.getline(nombre, sizeof(nombre));
	cout << "Apellidos: " << flush; cin.getline(Apellido, sizeof(Apellido));
	cout << "Direccion: " << flush; cin.getline(direccion, sizeof(direccion));
	cout << "Ciudad: " << flush; cin.getline(ciudad, sizeof(ciudad));
	cout << "Estado: " << flush; cin.getline(estado, sizeof(estado));
	cout << "Zip Code: " << flush; cin.getline(zipCode, sizeof(zipCode));
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	Pack();
}
