//#include <cstdio>
#include <locale.h>
//#include <ctime>
//#include <cwchar>
#include <ncurses.h>
int main(void)
{
	char first[24];
	char last[32];
	//std::setlocale(LC_ALL,"de_DE.UTF-8");
	setlocale(LC_ALL,"");
	initscr();
	echo();
	cbreak();
	keypad(stdscr,1);
	curs_set(0);
	attron(A_UNDERLINE);
	mvprintw(0,24,"NCURSES ALTCHARSET CHARACTERS\n");
  refresh();
	char tal[0];
	int pos=0;
	while (1) {
		int erg=getch();
		tal[pos++]=erg;
    if (erg==KEY_F(9) || pos>=29) break;
	}
	tal[pos]=0;
	mvprintw(3,1,"tal: %s\n",tal);
	refresh();
  char berg[30];
	printw("String eingeben: ");
	refresh();
	getstr(berg);
	printw("%s",berg);
	for(int i=0;;i++) {
		if (berg[i]==0) break;
		printw("%i: %c (%i)\n",i,berg[i],berg[i]<0?berg[i]+255:berg[i]);
	}

	attroff(A_UNDERLINE);
	printw(" ");
	// waddch(stdscr,'ö');
//	addch('aböäüÖÄÜßc');
	//refresh();
	addch('\n');
	getch();
	endwin();
	return 0;
}
