#include <stddef.h>
#include <stdbool.h>

typedef struct matrix {
    double** table;
    size_t rows;
    size_t cols;
} Matrix;

bool equalDimensions(const Matrix*, const Matrix*);

bool multipliable(const Matrix*, const Matrix*);

bool divisible(const Matrix*, const Matrix*);

bool is_square(const Matrix*);

bool mplusm(const Matrix*, const Matrix*, Matrix*);

bool mminusm(const Matrix*, const Matrix*, Matrix*);

void rmultm(const double, const Matrix*, Matrix*);

void mmultr(const Matrix*, const double, Matrix*);

bool mmultm(const Matrix*, const Matrix*, Matrix*);

bool mdivm(const Matrix*, const Matrix*, Matrix*);

void negm(const Matrix*, Matrix*);

bool detm(const Matrix*, double*);

bool invm(const Matrix*, Matrix*);

void transposem(const Matrix*, Matrix*);

void add_rows(const Matrix*, const size_t, const size_t, Matrix*);

void row_multiply(const Matrix*, const size_t, const double, Matrix*);

void row_swap(const Matrix*, const size_t, const size_t, Matrix*);

void add_cols(const Matrix*, const size_t, const size_t, Matrix*);

void col_multiply(const Matrix*, const size_t, const double, Matrix*);

void col_swap(const Matrix*, const size_t, const size_t, Matrix*);
