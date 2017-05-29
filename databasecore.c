#include "databasecore.h"
#include <locale>
#define BOOKSIZE 200
#define AUTHORSIZE 200
#pragma warning(disable:4996)



void startwork(table * tab){
	long long int  Key;

	int freebooks;
	int booksatall;
	char c;
	int n = 0;
	tab->size = 0;

	tab->keys = (long long int *)calloc(1, sizeof(long long int));

	tab->library = (Table*)calloc(1, sizeof(Table));
		tab->library->table = (Table **)calloc(32, sizeof(Table *));
	for (int i = 0; i < 32; i++){
		tab->library->bitmap[i] = 0;
		tab->library->table[i] = (Table *)calloc(1, sizeof(Table));
	}


	tab->file = fopen("books.cvs", "r");
	c = '\0';

	printf("*********   СЧИТАННЫЕ КНИГИ:   *********\n");
	
	do {
		char * author = (char *)calloc(AUTHORSIZE, sizeof(char));
		char * nameofbook = (char *)calloc(BOOKSIZE, sizeof(char));
		do {
			printf("***************************************\n");
			fscanf(tab->file, "%lld", &Key);
			printf("%lld\n", Key);
			fgetc(tab->file);
			c = '\0';
			n = 0;
			while (c != ';'){
				c = fgetc(tab->file);
				if (n < AUTHORSIZE){
					author[n] = c;
					n++;
				}
				else{
					printf("err input\n");
					exit(-1);
				}
			}
			author[n - 1] = '\0';
			printf("%s\n", author);
			n = 0;
			c = '\0';

			while (c != ';'){
				c = fgetc(tab->file);
				if (n < BOOKSIZE){
					nameofbook[n] = c;
					n++;
				}
				else{
					printf("err input\n");
					exit(-1);
				}
			}
			nameofbook[n - 1] = '\0';
			printf("%s\n", nameofbook);

			fscanf_s(tab->file, "%d", &booksatall);
			printf("%d\n", booksatall);
			fgetc(tab->file);
			fscanf_s(tab->file, "%d", &freebooks);
			printf("%d\n", freebooks);
				c = fgetc(tab->file);
		} while (c != '\n' && c != EOF);
		printf("***************************************\n");

		insertbook(tab, Key, author, nameofbook, freebooks, booksatall);
		author = NULL;
		nameofbook = NULL;
	} while ( feof(tab->file) == 0);
	fclose(tab->file);
}
void insertbook(table* tab, long long int Key, char * author, char * nameofbook, int freebooks, int booksatall){
	cell* newc = (cell *)calloc(1, sizeof(cell));
	newc->Key = Key;
	newc->author = author;
	newc->nameofbook = nameofbook;
	newc->freebooks = freebooks;
	newc->booksatall = booksatall;


	long long int *arr = (long long int *)realloc(tab->keys, (tab->size + 1)*sizeof(long long int));
	tab->keys = arr;
	tab->keys[tab->size] = Key;
	tab->size++;


	insert(tab->library, Key, newc, 1);
}
void deletebook(table * tab, long long int Key){
	for (int i = 0; i < tab->size; i++)
		if (Key == tab->keys[i]){
			for (int j = i; j < tab->size; j++)
				tab->keys[j] = tab->keys[j+1];
			tab->size--;
			tab->keys[tab->size] = NULL;
		}
	deletekey(tab->library, Key);

}
void getbook(table * tab, long long int Key){
	Table *t = fullsearch(tab->library, Key);
	if (((cell *)t->Value)->freebooks > 0){
		((cell *)t->Value)->freebooks--;
	}
	else {
		printf("Данные книги закончились!\n");
	}
}
void putbook(table * tab, long long int Key){
	Table *t = fullsearch(tab->library, Key);
	((cell *)t->Value)->freebooks++;
}
void finishwork(table * tab){
	remove("books.cvs");
	tab->file = fopen("books.cvs", "w");
	for (int i = 0; i < (tab->size-1); i++)
		printbookinfile(tab->library, tab->keys[i], tab->file);
	Table * p = fullsearch(tab->library,tab->keys[tab->size - 1]);
	if (p != 0)
	fprintf(tab->file, "%lld;%s;%s;%d;%d", ((cell *)p->Value)->Key, ((cell *)p->Value)->author, ((cell *)p->Value)->nameofbook, ((cell *)p->Value)->booksatall, ((cell *)p->Value)->freebooks);
}
