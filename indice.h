#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <limits>
#include <string.h>
#include <list>
#include <fstream>
#pragma warning (disable : 4996)
#pragma pack(1)
using namespace std;

class indice {
private:


public:
	indice() = default;
	char cedula[13];
	int offset;
	void pack();
	void unPack();
	char in_buff[50];

	void crearIndex();
	void cargarlista();
	//void leerArchRegis();
};
