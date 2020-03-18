#ifndef MENU_H_
#define MENU_H_

#include <curses.h>
#include "matrix.h"

WINDOW *menu_win;

void menu_print (WINDOW *, char **, int, int);
int menu_choose (char **, int);
Matrix *menu_create_matrix ();
int menu_ask_number ();
void menu_enter_value (TabMatrix *);
void menu_print_tabmatrix (TabMatrix *)

#endif