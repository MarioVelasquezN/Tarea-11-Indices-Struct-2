#include <limits>
#include <fstream>
#include <inttypes.h>
#include "Empleado.h"
#include "indice.h"

using namespace std;
#pragma warning (disable : 4996)


void ReadAll() {
	char buffer[MAX_BUFFER];
	Empleado p;
	ifstream f;
	cout << "Cedula	Nombres  Apellidos  Direccion Ciudad Estado ZipCode" << endl;
	f.open("empleado.txt",ios::in);
	if (f.fail()) {
		cout << "No encontro el alchivo empleado.txt" << endl;
		return;
	}

	while (1)
	{

		f.read(buffer,MAX_BUFFER);
		if (f.eof()) break;

		p.setBBuffer(buffer);
		p.Print();
	}
	f.close();
}
int WriteAll() {
	char c[100];
	c[0] = 0;
	Empleado p;

	ofstream f;
	f.open("empleado.txt",ios::app);
	while (1)
	{
		p.Write();
		f.seekp(0, ios::end);
		f.write(p.in_buffer,MAX_BUFFER);

		cout << "Desea Continuar? (S/N): " << flush; cin.getline(c, 100);
		if (strcmp(c, "N") == 0) break;
	}
	f.close();
	return 1;
}

void Empleado::GetEmpleadoByName(string nombre) {
	char buffer[MAX_BUFFER];
	bool cam = true;
	uint16_t r_size;
	Empleado p;
	int cont = 0;
	ifstream f;
	f.open("empleado.txt");
	if (!f) {
		cout << "Error al abrir el archivo empleado.txt";
		return;
	}
	while (cam){
		f.read(buffer, MAX_BUFFER);
		p.setBBuffer(buffer);
		cont=f.tellg();
		if (nombre == p.nombre) {
			p.Print();
			break;
		}
		else {
			f.tellg();
			cam = true;
		}
	}
	if (f.eof());
	f.close();
}

int Empleado::buscarEmpleado(const char* ID) {
	char buffer[MAX_BUFFER];
	bool cam = true;
	Empleado p;
	int cont = 0;
	ifstream f;
	indice i;
	f.open("indice.txt");
	if (!f) {
		cout << "Error al abrir el archivo empleado.txt";
		return 0;
	}
	while (!f.eof()){
		cont = f.tellg();
		f.read(i.in_buff, 50);
		i.unPack();

		if (strcmp(ID,i.cedula)==0) {
			return i.offset;
		}
	}
	return 0;
	f.close();
}
void Empleado::EliminarRegistro() {
	fstream ar;
	ar.open("empleado.txt");
	char aux[30];
	if (!ar) {
		cout << "Archivo no encontrado!!";
		return;
	}
	cout << "Introduzca un cedula para eliminar: ";
	cin >> aux;
	if (buscarEmpleado(aux) == -1) {
		cout << "No se encontro nombre";
		return;
	}
	else {
		ar.seekp(buscarEmpleado(aux));
		ar.put('*');
		ar.close();
	}
}

void Empleado::Compactar() {
	char buffer[MAX_BUFFER];
	bool cas = true;
	ifstream f;
	ofstream o;
	Empleado p;
	char *c = in_buffer;
	f.open("empleado.txt", ios::in);
	o.open("empleadonew.txt", ios::app);
	if (!f) {
		cout << "Archivo no pudo leerse!!";
		return;
	}

	f.seekg(0, ios::end);
	int sz = f.tellg();
	f.seekg(0, ios::beg);
	while (!f.eof())
	{

		f.read(buffer, MAX_BUFFER);
		if (f.eof()) break;;

		if (buffer[0] != '*')
			o.write(buffer, MAX_BUFFER);


	}
}

void Empleado::index() {
	char buff[MAX_BUFFER];
	char offset[5];
	//offset[2] = '/0';
	uint16_t size_off;
	ifstream leer;
	ofstream escribir;

	leer.open("empleado.txt");
	escribir.open("indice.txt", ios::app);

	if (!leer) {
		cout << "Archivo no pudo leerse!!";
		return;
	}

	
	while (!leer.eof())
	{
		int sz = leer.tellg();
		itoa(sz, offset, 10);
		leer.read(buff, MAX_BUFFER);
		if (leer.eof()) break;

		escribir.write(offset, sizeof(sz));
		//escribir.write(buff, MAX_BUFFER);
	}
}

int main(/*int argc, char **argv*/) {
	Empleado p;
	indice k;
	cout << p.buscarEmpleado("958");

	/*if (strcmp(argv[1], "1") == 0)*/ //WriteAll(); 
	/*if (strcmp(argv[1], "2") == 0)*/ //ReadAll();
	cout << endl;
	/*if (strcmp(argv[1], "3") == 0)*/ //p.GetEmpleadoByName("Wilmer");
	cout << endl;
	/*if (strcmp(argv[1], "4") == 0)*/ //p.EliminarRegistro();
	//p.Compactar();
	//p.indice();
	////k.crearIndex();
	k.cargarlista();
}
