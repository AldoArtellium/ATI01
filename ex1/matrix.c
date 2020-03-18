#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

Matrix *null_matrix;

Matrix *create_matrix (int line, int row)  {
    Matrix *a;

    a = malloc(sizeof(Matrix));

    a->line = line;
    a->row = row;
    

    a->table = malloc( a->row * sizeof(double *) );

    for (int i = 0; i < a->row; ++i) {
        a->table[i] = malloc( a->line * sizeof(double) );
    }
    return a;
}

void delete_matrix (Matrix *a) {
    if (a != null_matrix) {
        for (int i = 0; i < a->row; i++) {
            free(a->table[i]);
        }
        free(a->table);
        free(a);
    }else{
        free(a);
    }
}

TabMatrix *create_tabmatrix ()  {
    TabMatrix *a;
    a = malloc(sizeof(TabMatrix));
    a->matrices = malloc(sizeof(Matrix *));
    a->length = 0;

    return a;
}

void print_tabmatrix (TabMatrix *a, int numtab) {
    print_matrix(a->matrices[numtab]);
}

void resize_tabmatrix (TabMatrix *a, size_t b) {
    a->matrices = (Matrix **)realloc(a->matrices, (b + 1) * sizeof(Matrix *));
    if (a->matrices == NULL){
        printf("Error: memory not allocated\n");
        exit(1);
    }
}

void append_tabmatrix (TabMatrix *a, Matrix *b) {
    a->matrices[a->length] = b;

    resize_tabmatrix(a, a->length+1);
    a->length++;
}

void appendtomatrix_tabmatrix (TabMatrix *a, int b, double num, int line, int row) {
    a->matrices[b]->table[line][row] = num;
}

void delete_tabmatrix (TabMatrix *a) {
    for (int i = 0; i < a->length; i++) {
        delete_matrix(a->matrices[i]);
    }
    free(a);
}

void print_matrix (Matrix *a) {
    if (a != null_matrix) {
        for (int i = 0; i < a->row; ++i) {
            for (int z = 0; z < a->line; ++z) {
                printf("%f ", a->table[i][z]);
            }
            printf("\n");
        }
    }
}

void reset_matrix (Matrix *a) {
    if (a != null_matrix) {
        for (int i = 0; i < a->row; ++i) {
            for (int z = 0; z < a->line; ++z) {
                a->table[i][z] = 0;
            }
        }
    }
}

Matrix *add_matrix (Matrix *a, Matrix *b) {
    if ((a->row == b->row && a->line == b->line) && (a != null_matrix && b != null_matrix)) {

        int row = a->row;
        int line = a->line;

        Matrix *c = create_matrix(line, row);
        
        for (int z = 0; z < row; ++z) {
            for (int i = 0; i < line; ++i) {
                c->table[i][z] = a->table[i][z] + b->table[i][z];
            }
        }
        return c;
    }
    return null_matrix;
}

Matrix *multiply_matrix (Matrix *a, Matrix *b) {
    if ((a->row == b->line) && (a != null_matrix && b != null_matrix)) {
        int row = b->row;
        int line = a->line;

        Matrix *c = create_matrix(line, row);
        double sum = 0.0;
        for (int i = 0; i < line; ++i) {
            for (int z = 0; z < row; ++z) {
                sum = 0.0;
                for (int j = 0; j < b->line; ++j) {
                    sum += (a->table[j][i] * b->table[z][j]);
                }
                c->table[z][i] = sum;
            }
        }
        return c;
    }
    return null_matrix;
}

double trace_matrix(Matrix *a) {
    if (a->row == a->line && a != null_matrix) {
        double trace;
        for (int i = 0; i < a->row; ++i) {
            trace *= a->table[i][i];
        }
        return trace;
    }else{
        return 0;
    }
}

double determ_matrix(Matrix *a) {
    if (a->row == a->line && a != null_matrix) {
        double det; 
        if (a->row == 1) {
            return a->table[0][0];
        }else if (a->row == 2) {
            det=(a->table[0][0]*a->table[1][1]-a->table[0][1]*a->table[1][0]);
            return det;
        }else {
            Matrix *temp = create_matrix(a->row, a->line);
            temp->row = a->row;
            temp->line = a->row;

            int h, k;

            for (int p = 0; p < a->row; ++p){
                h = 0;
                k = 0;
                for (int i = 1; i < a->row; ++i) {
                    for (int j = 0; j < a->row; ++j) {
                        if (j == p) {
                            continue;
                        }

                        temp->table[k][h] = a->table[i][j];
                        k++;
                        if (k == a->row-1) {
                            h++;
                            k = 0;
                        }
                    }
                }

                temp->row--; temp->line--;
                det = det + a->table[0][p] * pow(-1,p) * determ_matrix(temp);
                temp->row++; temp->line++;
            }
            delete_matrix(temp);
            return det;
        }
    }else {
        return 0;
    }
}