#pragma once
#include "hashmap.h"

#ifndef DATABASE

typedef struct table {
	FILE* file;
	Table* library;
	long long int * keys;
	int size;
} table;

void startwork(table * tab);
void insertbook(table* tab, long long int Key, char * author, char * nameofbook, int freebooks, int booksatall);
void deletebook(table * tab,long long int Key);
void getbook(table * tab, long long  int Key);
void putbook(table * tab,long long  int Key);
void finishwork(table * tab);
#endif
