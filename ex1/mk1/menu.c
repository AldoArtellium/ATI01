#include <string.h>
#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "matrix.h"

/* ################ Menu ################ */

void menu_print(WINDOW *menu_win, char **choices, int n_choices, int highlight) {
    int x, y, i;

    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for(i = 0; i < n_choices; ++i)
    {   if(highlight == i + 1) /* High light the present choice */
        {   wattron(menu_win, A_REVERSE); 
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        }
        else
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        ++y;
    }
    wrefresh(menu_win);
}

int menu_choose (char **choices, int n_choices) {
    int highlight = 1, choice = 0, c, row, col;
    initscr();
    refresh();
    clear();
    noecho();
    cbreak();   /* Line buffering disabled. pass on everything */
    getmaxyx(stdscr, row, col);

    int WIDTH = 0;
    for (int i = 0; i < n_choices; ++i)
    {
        if (WIDTH < (int)strlen(choices[i])) {
            WIDTH = (int)strlen(choices[i]);
        }
    }
    WIDTH += 4;
    int HEIGHT = n_choices + 4;

    int startx = (col - WIDTH) / 2 ;
    int starty = (row - HEIGHT) / 2;
    menu_win = newwin(HEIGHT, WIDTH, starty, startx);

    keypad(menu_win, TRUE);
    mvprintw(0, (col - strlen("Matrix Calculator"))/2, "Matrix Calculator");
    refresh();
    menu_print(menu_win, choices, n_choices, highlight);

    while (choice == 0) {   
        c = wgetch(menu_win);
        switch (c) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;

            case KEY_DOWN:
                if (highlight == n_choices)
                    highlight = 1;
                else 
                    ++highlight;
                break;

            case 10:
                choice = highlight;
                break;

            case q:
            	highlight = n_choices;
            	break;

            default:
                mvprintw(row-2, 0, "'%c': Dont correspond to anything", c);
                refresh();
                break;
        }
        menu_print(menu_win, choices, n_choices, highlight);
    }   
    clrtoeol();
    refresh();
    endwin();

    return choice;
}

Matrix *menu_create_matrix () {
	Matrix *a;

    int matrix_row, matrix_line;
    printf("line: ");
    scanf("%d", &matrix_line);
    printf("row: ");
    scanf("%d", &matrix_row); 

    a = create_matrix(matrix_line, matrix_row);

    return a;
}

int menu_ask_number() {
	int matrix_number;
    printf("Matrix number: ");
	scanf("%d", &matrix_number);
	return matrix_number;
}

void menu_enter_value (TabMatrix *a) {
    for (int i = 0; i < a ->length; i++) {
	   printf("%d, ", i);
    }
    printf("\n");

    int matrix_row, matrix_line, tabnum;
    double num;
    printf("Tab number: ");
    scanf("%d", &tabnum); 
    printf("line: ");
    scanf("%d", &matrix_line);
    printf("row: ");
    scanf("%d", &matrix_row); 
    printf("Number (double): ");
    scanf("%lf", &num);
    appendtomatrix_tabmatrix(a, tabnum, num, matrix_line, matrix_row);
}

void menu_print_tabmatrix (TabMatrix *a) {
    int tabnum;
    printf("Tab number: ");
    scanf("%d", &tabnum); 
    print_tabmatrix(a, tabnum);
}