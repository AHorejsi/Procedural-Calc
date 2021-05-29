#include <stddef.h>
#include <stdbool.h>

typedef struct matrix {
    double** table;
    size_t rows;
    size_t cols;
} matrix_t;

bool equal_dimensions(const matrix_t*, const matrix_t*);

bool multipliable(const matrix_t*, const matrix_t*);

bool divisible(const matrix_t*, const matrix_t*);

bool is_square(const matrix_t*);

bool mplusm(const matrix_t*, const matrix_t*, matrix_t*);

bool mminusm(const matrix_t*, const matrix_t*, matrix_t*);

void rmultm(const double, const matrix_t*, matrix_t*);

void mmultr(const matrix_t*, const double, matrix_t*);

bool mmultm(const matrix_t*, const matrix_t*, matrix_t*);

void mdivr(const matrix_t*, const double, matrix_t*);

bool mdivm(const matrix_t*, const matrix_t*, matrix_t*);

void negm(const matrix_t*, matrix_t*);

bool detm(const matrix_t*, double*);

bool invm(const matrix_t*, matrix_t*);

void transposem(const matrix_t*, matrix_t*);

void add_rows(const matrix_t*, const size_t, const size_t, matrix_t*);

void row_mult(const matrix_t*, const size_t, const double, matrix_t*);

void row_swap(const matrix_t*, const size_t, const size_t, matrix_t*);

void add_cols(const matrix_t*, const size_t, const size_t, matrix_t*);

void col_mult(const matrix_t*, const size_t, const double, matrix_t*);

void col_swap(const matrix_t*, const size_t, const size_t, matrix_t*);

bool subm(const matrix_t*, const size_t, const size_t, matrix_t*);

void cofactorsm(const matrix_t*, matrix_t*);
