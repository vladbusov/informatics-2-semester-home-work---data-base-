#include "menu.h"
#include <locale>
#define BOOKSIZE 200
#define AUTHORSIZE 200
#pragma warning(disable:4996)

void start(table *t){
	setlocale(LC_ALL, "Russian");
	int value = 0;
	printf("Начать работу (да-1/нет-0):\n");
	scanf("%1d", &value);
	switch (value){
	case 1:
		startwork(t);
		menu(t);
		break;
	case 0:
		exit(-1);
		break;
	default:
		exit(-1);
		break;
	}
}

void pushup() {
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < 5; i++)
	printf("*\n");
}

void menu(table *t){
	setlocale(LC_ALL, "Russian");
	int value = 0;
	printf("МЕНЮ:\nДобавить книгу:(выбор-0)\nУдалить книгу:(выбор-1)\nВзять книгу:(выбор-2)\nВернуть книгу:(выбор-3)\nЗакончить работу:(выбор-4)\n");
	scanf("%1d", &value);
	switch (value){
	case 0:
		insbook(t);
		break;
	case 1:
		delbook(t);
		break;
	case 2:
		gbook(t);
		break;
	case 3:
		pbook(t);
		break;
	case 4:
		leave(t);
		break;
	default:
		menu(t);
		break;
	}
}

void back(table *t){
	setlocale(LC_ALL, "Russian");
	int value = 0;
	printf("Вернуться в меню?(да - 1 / нет - 0):\n");
	scanf("%1d", &value);
	switch (value){
	case 1:
		menu(t);
	default:
		leave(t);
		break;
	}

}

void insbook(table *t){
	setlocale(LC_ALL, "Russian");
	long long int  Key;
	int freebooks;
	int booksatall;
	char * author = (char *)calloc(AUTHORSIZE, sizeof(char));
	char * nameofbook = (char *)calloc(BOOKSIZE, sizeof(char));
	printf("Введите,пожалуйста,ключ для книги:\n");
	scanf("%lld", &Key);
	printf("Теперь введите название книги:\n");
	scanf("%s", nameofbook);
	printf("Пожалуйста введите имя автора книги:\n");
	scanf("%s", author);
	printf("Введите количество свободных книг:\n");
	scanf("%d", &freebooks);
	printf("Введите количество данных книг всего:\n");
	scanf("%d", &booksatall);
	insertbook(t, Key, author, nameofbook, freebooks, booksatall);
	printf("Ваша книга успешно добавлена\n");
	back(t);
}
void delbook(table *t){
	setlocale(LC_ALL, "Russian");
	long long int  Key;
	printf("Введите,пожалуйста,ключ для книги, которую хотите удалить:\n");
	scanf("%lld", &Key);
	if (fullsearch(t->library, Key) != 0){
		deletebook(t, Key);
		printf("Книга успешно удалена:\n");
	}
	else {
		printf("У нас нет такой книги\n");
	}
	back(t);
}
void gbook(table *t){
	setlocale(LC_ALL, "Russian");
	long long int  Key;
	printf("Введите,пожалуйста,ключ для книги, которую хотите забрать:\n");
	scanf("%lld", &Key);
	if (fullsearch(t->library, Key) != 0){
		getbook(t, Key);
	}
	else {
		printf("У нас нет такой книги\n");
	}
	back(t);
}
void pbook(table *t){
	setlocale(LC_ALL, "Russian");
	long long int  Key;
	printf("Введите,пожалуйста,ключ для книги, которую хотите вернуть:\n");
	scanf("%lld", &Key);
	if (fullsearch(t->library, Key) != 0){
		putbook(t, Key);
	}
	else {
		printf("У нас нет такой книги\n");
	}
	back(t);
}
void leave(table *t){
	setlocale(LC_ALL, "Russian");
	finishwork(t);
	exit(0);
}
