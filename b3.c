//#include <cstdio>
#include <locale.h>
#include <string.h>
//#include <ctime>
//#include <cwchar>
// geht bei mit Umlauten und ß bei kompilieren mit: g++ ... $(ncursesw5-config --cflags) $(ncursesw5-config --libs)
#include <ncurses.h>
int main(void)
{
	setlocale(LC_ALL,"");
	char first[24];
	char last[32];
	initscr();
	keypad(stdscr,1);
	addstr("Vorname? ");
	refresh();
	getstr(first);

	addstr("Nachname? ");
	refresh();
	getstr(last);

	printw("Pleased to meet you, %s %s!\n",first,last);
	printw("Vornamenlänge: %u\n",strlen(first));
	for(int i=0;i<strlen(first);i++) {
		printw("%u: %c (%d) \n",i,first[i],(unsigned char)first[i]);
	}
	refresh();
	getch();

	endwin();
	return 0;
}
