#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>
#define TYPEVALUE cell


#ifndef HASHMAP
typedef struct Table {
	long long int  Key;
	void * Value;
	int Size;
	int bitmap[32];
	Table ** table;
} Table;

typedef struct cell {
	long long int Key;
	char * author;
	char * nameofbook;
	int freebooks;
	int booksatall;
} cell;

long long int pow_new(int num, int power);
long long int calculhash(long long int Key);
int getfivebits(long long int H, int id);
int hash(long long int Key, int Order);
void insert(Table * t, long long int Key, TYPEVALUE * Value, int  size);
void insertlvl(Table *tab, long long int Key, TYPEVALUE * Value, int size, int lvl);
Table * fullsearch(Table *t, long long int Key);
Table* search(Table *tab, long long int Key_s, int lvl);
void print(Table *t);
void newTable(Table* t);
void deleteTable(Table *t);
void deletekey(Table *tab, long long int key);
Table* getparant(Table *tab, int Key_s, int lvl);
int getlvl(Table *tab, int Key_s, int lvl);
void printcell(cell* c);
void printbookinf(Table *t, long long int Key);
void printbookinfile(Table* t, long long int Key, FILE * f);
void printcellinfile(cell* c, FILE * f);
#endif
