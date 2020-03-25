#include "indice.h"
#include "Empleado.h"

void indice::pack() {
	char caract[10];

	in_buff[0] = 0;
	strcat(in_buff, cedula);
	strcat(in_buff, "|");
	sprintf(caract, "%d", offset);

	strcat(in_buff, caract);
	strcat(in_buff, "|");


	for (size_t i = strlen(in_buff); i < 50; i++)
	{
		in_buff[i] = ' ';
	}
}

void indice::unPack() {
	char se = '|';
	char temp[30];
	char *c = in_buff;
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
	offset = atoi(temp);
}

void indice::crearIndex() {
	ofstream escri;
	ifstream f;
	Empleado p;

	escri.open("indice.txt", ios::trunc);
	f.open("empleado.txt");

	if (!escri) {
		cout << "No se pudo leer";
		return;
	}
	int ofset = 0;
	f.seekg(0, ios::end);
	int size = f.tellg();
	f.seekg(0, ios::beg);

	while (!f.eof()) {
		ofset = f.tellg();
		f.read(p.in_buffer, 100);
		p.unPack();

		strcpy(cedula, p.cedula);
		offset = ofset;
		pack();
		if (size > ofset && in_buff[0] != '*')
			escri.write(in_buff, 50);
	}
	f.close();
	escri.close();
}

void indice::cargarlista() {
	indice i;
	list <indice> lis;
	ifstream f;
	f.open("indice.txt");
	f.seekg(0, ios::end);
	int sz = f.tellg();
	f.seekg(0, ios::beg);
	int curPtr = 0;

	while (!f.eof()) {
		curPtr = f.tellg();
		f.read(in_buff, 50);
		unPack();

		strcpy(i.cedula, cedula);

		i.offset = offset;
		if (sz > curPtr)
			lis.push_back(i);

	}

	for (auto it = lis.begin(); it != lis.end(); it++)
	{
		cout << it->cedula << "|" << (int)it->offset << endl;
	}
}