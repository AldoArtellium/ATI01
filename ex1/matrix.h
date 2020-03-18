#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct Matrix_s {
    int line;
    int row;
    double **table;
} Matrix;

typedef struct TabMatrix_s {
	Matrix **matrices;
	int length;
} TabMatrix;

Matrix *create_matrix (int, int);
void delete_matrix (Matrix *);
void print_matrix (Matrix *);
void reset_matrix (Matrix *);

TabMatrix *create_tabmatrix ();
void print_tabmatrix (TabMatrix *);
void append_tabmatrix (TabMatrix *, Matrix *);
void appendtomatrix_tabmatrix (TabMatrix *, int, double, int, int);
void delete_tabmatrix (TabMatrix *);
void increase_tabmatrix (TabMatrix *);

Matrix *add_matrix (Matrix *, Matrix *);
Matrix *multiply_matrix (Matrix *, Matrix *);
double trace_matrix(Matrix *);
double determ_matrix(Matrix *);

#endif