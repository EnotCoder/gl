#include <ncurses.h>

int main() {
    	initscr();           // Инициализация ncurses
    	noecho();            // Не отображать введенные символы
    	cbreak();            // Отключить буферизацию ввода
    	//keypad(stdscr, TRUE); // Обрабатывать специальные клавиши
	for (int i =0;i<23;i++){
		printw("%d\n", i + 1);	
	};
	move(7,0);
	refresh();           // Обновить экран

    	return 0;
}

