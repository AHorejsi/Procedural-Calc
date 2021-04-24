#include <stddef.h>

typedef struct matrix {
    double** table;
    size_t rows;
    size_t cols;
} Matrix;
