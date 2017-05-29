#include "menu.h"
#include <locale>


int main(){
	setlocale(LC_ALL, "Russian");
	table books1;
	start(&books1);
	system("PAUSE");
	return 0;
}
