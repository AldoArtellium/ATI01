#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
//#include <time.h>
#include "matrix.h"
#include "menu.h"

/* ################ Main ################ */

int main (int argc, char const *argv[]) {
    enum { INTERACTIVE_MODE, FILE_MODE } mode = INTERACTIVE_MODE;
    size_t argz;
    for (argz = 1; (int)argz < argc && argv[argz][0] == '-'; argz++){
        switch (argv[argz][1]) {
            case 'i': mode = INTERACTIVE_MODE; break;
            case 'f': mode = FILE_MODE; break;
            default:
                fprintf(stderr, "Usage: %s [-i] [-f FILE]\n", argv[0]);
                exit(EXIT_FAILURE);
        }   
    }

    if (mode == INTERACTIVE_MODE){
        TabMatrix *a = create_tabmatrix();

        int quit = 0;

        // Chaines de carac pour menu
        char *_home[] = {"Create Matrix", "Manipulate Matrix", "Operators", "Print Matrix", "Exit"};
        char *_manipulate_matrix[] = {"Enter value", "Reset matrix", "Back"};
        char *_operators[] = {"Determinant", "Multiply", "Add", "Trace", "Back"};

        while (quit == 0) {
            switch (menu_choose(_home, sizeof(_home) / sizeof(char **))) {
                case 1:
                    append_tabmatrix(a, menu_create_matrix());
                    break;

                case 2:
                    switch (menu_choose(_manipulate_matrix, sizeof(_manipulate_matrix) / sizeof(char **))) {
                        case 1:
                            menu_enter_value(a);
                            break;

                        case 2:
                            
                            break;
                            
                        case sizeof(_manipulate_matrix) / sizeof(char **):
                            break;
                    }
                    break;

                case 3:
                    switch (menu_choose(_operators, sizeof(_operators) / sizeof(char **))) {
                        case 1:

                            break;
                        case sizeof(_operators) / sizeof(char **):
                            break;
                    }
                    break;

                case 4:
                    
                    break;

                case (sizeof(_home) / sizeof(char **)):
                    quit = 1;
                    break;
            }
        }
        delete_tabmatrix(a);
    }else if (mode == FILE_MODE){
        //convert file
    }
}

/*               Tests               */

// int main()
// {
//     if (1) {
//         Matrix **matrices = calloc(1, sizeof(Matrix *));
//         for (int i = 0; i < 10000; ++i) {
//             increase_matrice(&matrices, i);
//             matrices[i] = create_matrix(20,20);
//             printf("\n\n%d\n", i);
//             print_matrix(matrices[i]);
//         }
//         for (int i = 0; i < 10000; ++i) {
//             delete_matrix(matrices[i]);
//         }

//         printf("A=\n");
//         print_matrix(a);

//         printf("\nB=\n");
//         print_matrix(b);

//         Matrix *c = add_matrix(a, b);
//         printf("\nC=\n");
//         print_matrix(c);

//         Matrix *d = multiply_matrix(a, b);
//         printf("\nD=C*B\n");
//         print_matrix(d);

//         printf("tr(A)=%f\n", trace_matrix(a));

//         printf("det(A)=%f\n", determ_matrix(a));

//         delete_matrix(a);
//         delete_matrix(b);
//         delete_matrix(c);
//         delete_matrix(d);

//         return 0;
//     }
//     return 0;
// }
