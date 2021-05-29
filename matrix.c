#include <stdio.h>


#include <math.h>
#include <stdlib.h>
#include "matrix.h"

bool equal_dimensions(const matrix_t* left, const matrix_t* right) {
    return left->rows == right->rows && left->cols == right->cols;
}

bool multipliable(const matrix_t* left, const matrix_t* right) {
    return left->cols == right->rows;
}

bool divisible(const matrix_t* left, const matrix_t* right) {
    return multipliable(left, right) && is_square(right);
}

bool is_square(const matrix_t* mat) {
    return mat->rows == mat->cols;
}

double** _make_table(const size_t rows, const size_t cols) {
    double** table = (double**)malloc(rows * sizeof(double*));

    for (size_t index = 0; index < rows; ++index) {
        table[index] = (double*)malloc(cols * sizeof(double));
    }

    return table;
}

void _destroy_table(matrix_t* mat) {
    if (NULL != mat->table) {
        for (size_t i = 0; i < mat->rows; ++i) {
            free(mat->table[i]);
        }

        free(mat->table);
    }
}

void _destroy_table_array(double** table, const size_t rows) {
    if (NULL != table) {
        for (size_t i = 0; i < rows; ++i) {
            free(table[i]);
        }

        free(table);
    }
}

void _mplusm_in_place(const matrix_t* other, matrix_t* result) {
    for (size_t i = 0; i < other->rows; ++i) {
        for (size_t j = 0; j < other->cols; ++j) {
            result->table[i][j] += other->table[i][j];
        }
    }
}

bool mplusm(const matrix_t* left, const matrix_t* right, matrix_t* result) {
    if (!equal_dimensions(left, right)) {
        return false;
    }

    if (left == result) {
        _mplusm_in_place(right, result);
    }
    else if (right == result) {
        _mplusm_in_place(left, result);
    }
    else {
        double** table = _make_table(left->rows, left->cols);

        for (size_t i = 0; i < left->rows; ++i) {
            for (size_t j = 0; j < left->cols; ++j) {
                table[i][j] = left->table[i][j] + right->table[i][j];
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = left->rows;
        result->cols = left->cols;
    }

    return true;
}

void _mminusm_in_place_where_left_is_result(const matrix_t* other, matrix_t* result) {
    for (size_t i = 0; i < other->rows; ++i) {
        for (size_t j = 0; j < other->cols; ++j) {
            result->table[i][j] -= other->table[i][j];
        }
    }
}

void _mminusm_in_place_where_right_is_result(const matrix_t* other, matrix_t* result) {
    for (size_t i = 0; i < other->rows; ++i) {
        for (size_t j = 0; j < other->cols; ++j) {
            result->table[i][j] = other->table[i][j] - result->table[i][j];
        }
    }
}

bool mminusm(const matrix_t* left, const matrix_t* right, matrix_t* result) {
    if (!equal_dimensions(left, right)) {
        return false;
    }

    if (left == result) {
        _mminusm_in_place_where_left_is_result(right, result);
    }
    else if (right == result) {
        _mminusm_in_place_where_right_is_result(left, result);
    }
    else {
        double** table = _make_table(left->rows, left->cols);

        for (size_t i = 0; i < left->rows; ++i) {
            for (size_t j = 0; j < left->cols; ++j) {
                table[i][j] = left->table[i][j] - right->table[i][j];
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = left->rows;
        result->cols = left->cols;
    }

    return true;
}

void rmultm(const double left, const matrix_t* right, matrix_t* result) {
    mmultr(right, left, result);
}

void _mmultr_in_place(const double value, matrix_t* result) {
    for (size_t i = 0; i < result->rows; ++i) {
        for (size_t j = 0; j < result->cols; ++j) {
            result->table[i][j] *= value;
        }
    }
}

void mmultr(const matrix_t* left, const double right, matrix_t* result) {
    if (left == result) {
        _mmultr_in_place(right, result);
    }
    else {
        double** table = _make_table(left->rows, left->cols);

        for (size_t i = 0; i < left->rows; ++i) {
            for (size_t j = 0; j < left->cols; ++j) {
                table[i][j] = left->table[i][j] * right;
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = left->rows;
        result->cols = left->cols;
    }
}

bool mmultm(const matrix_t* left, const matrix_t* right, matrix_t* result) {
    if (!multipliable(left, right)) {
        return false;
    }

    double** table = _make_table(left->rows, right->cols);

    for (size_t row = 0; row < left->rows; ++row) {
        for (size_t col = 0; col < right->cols; ++col) {
            double value = 0;

            for (size_t index = 0; index < left->rows; ++index) {
                value += left->table[row][index] * right->table[index][col];
            }

            table[row][col] = value;
        }
    }

    _destroy_table(result);
    result->table = table;
    result->rows = left->rows;
    result->cols = right->cols;

    return true;
}

void mdivr(const matrix_t* left, const double right, matrix_t* result) {
    mmultr(left, 1 / right, result);
}

bool mdivm(const matrix_t* left, const matrix_t* right, matrix_t* result) {
    if (!divisible(left, right)) {
        return false;
    }

    matrix_t invOfRight = { NULL, -1, -1 };
    
    invm(right, &invOfRight);
    mmultm(left, &invOfRight, result);

    _destroy_table(&invOfRight);

    return true;
}

void negm(const matrix_t* mat, matrix_t* result) {
    mmultr(mat, -1, result);
}

double _detm(const matrix_t* mat) {
    if (2 == mat->rows) {
        return mat->table[0][0] * mat->table[1][1] - mat->table[0][1] * mat->table[1][0];;
    }
    else {
        double result = 0;

        for (size_t column = 0; column < mat->cols; ++column) {
            matrix_t submatrix = { NULL, -1, -1 };
            subm(mat, 0, column, &submatrix);

            result += pow(-1, column) * mat->table[0][column] * _detm(&submatrix);
            _destroy_table(&submatrix);
        }

        return result;
    }
}

bool detm(const matrix_t* mat, double* result) {
    if (!is_square(mat)) {
        return false;
    }

    *result = (1 == mat->rows) ? mat->table[0][0] : _detm(mat);

    return true;
}

void _minorm(const matrix_t* mat, matrix_t* temp) {
    for (size_t i = 0; i < mat->rows; ++i) {
        for (size_t j = 0; j < mat->cols; ++j) {
            matrix_t sub = { NULL, -1, -1 };

            subm(mat, i, j, &sub);
            detm(&sub, temp->table[i] + j);

            _destroy_table(&sub);
        }
    }
}

bool invm(const matrix_t* mat, matrix_t* result) {
    if (!is_square(mat)) {
        return false;
    }

    double detValue;
    detm(mat, &detValue);

    if (0 == detValue) {
        return false;
    }

    if (1 == mat->rows) {
        result->table[0][0] = 1 / detValue;
    }
    else if (2 == mat->rows) {
        double val00 = mat->table[1][1] / detValue;
        double val01 = -mat->table[0][1] / detValue;
        double val10 = -mat->table[1][0] / detValue;
        double val11 = mat->table[0][0] / detValue;

        mat->table[0][0] = val00;
        mat->table[0][1] = val01;
        mat->table[1][0] = val10;
        mat->table[1][1] = val11;
    }
    else {
        matrix_t temp = { _make_table(mat->rows, mat->cols), mat->rows, mat->cols };
        _minorm(mat, &temp);
        cofactorsm(&temp, &temp);
        transposem(&temp, &temp);
        mdivr(&temp, detValue, &temp);

        _destroy_table(result);
        result->table = temp.table;
        result->rows = temp.rows;
        result->cols = temp.cols;
    }

    return true;
}

void _transposem_in_place(matrix_t* result) {
    size_t rowEnd = result->rows - 1;
    size_t i = 0;

    while (i < rowEnd) {
        size_t j = i + 1;

        while (j < result->cols) {
            double temp = result->table[i][j];
            result->table[i][j] = result->table[j][i];
            result->table[j][i] = temp;

            ++j;
        }

        ++i;
    }
}

void transposem(const matrix_t* mat, matrix_t* result) {
    if (mat == result && is_square(mat)) {
        _transposem_in_place(result);
    }
    else {
        double** table = _make_table(mat->cols, mat->rows);

        for (size_t i = 0; i < mat->cols; ++i) {
            for (size_t j = 0; j < mat->rows; ++j) {
                table[i][j] = mat->table[j][i];
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = mat->cols;
        result->cols = mat->rows;
    }
}

void _add_rows_in_place(const size_t fromRow, const size_t toRow, matrix_t* result) {
    for (size_t col = 0; col < result->cols; ++col) {
        result->table[toRow][col] += result->table[fromRow][col];
    }
}

void add_rows(const matrix_t* mat, const size_t fromRow, const size_t toRow, matrix_t* result) {
    if (mat == result) {
        _add_rows_in_place(fromRow, toRow, result);
    }
    else {
        double** table = _make_table(mat->rows, mat->cols);

        for (size_t i = 0; i < mat->rows; ++i) {
            if (i == toRow) {
                for (size_t j = 0; j < mat->cols; ++j) {
                    table[i][j] = mat->table[i][j];
                }
            }
            else {
                for (size_t j = 0; j < mat->cols; ++j) {
                    table[i][j] = mat->table[i][j] + mat->table[fromRow][j];
                }
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = mat->rows;
        result->cols = mat->cols;
    }
}

void _row_mult_in_place(const size_t row, const double value, matrix_t* result) {
    for (size_t col = 0; col < result->cols; ++col) {
        result->table[row][col] *= value;
    }
}

void row_mult(const matrix_t* mat, const size_t row, const double value, matrix_t* result) {
    if (mat == result) {
        _row_mult_in_place(row, value, result);
    }
    else {
        double** table = _make_table(mat->rows, mat->cols);

        for (size_t i = 0; i < mat->rows; ++i) {
            if (i == row) {
                for (size_t j = 0; j < mat->cols; ++j) {
                    table[i][j] = mat->table[i][j];
                }
            }
            else {
                for (size_t j = 0; j < mat->cols; ++j) {
                    table[i][j] = mat->table[i][j] * value;
                }
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = mat->rows;
        result->cols = mat->cols;
    }
}

void _row_swap_in_place(const size_t row1, const size_t row2, matrix_t* result) {
    double* temp = result->table[row1];
    result->table[row1] = result->table[row2];
    result->table[row2] = temp;
}

void row_swap(const matrix_t* mat, const size_t row1, const size_t row2, matrix_t* result) {
    if (mat == result) {
        _row_swap_in_place(row1, row2, result);
    }
    else {
        double** table = _make_table(mat->rows, mat->cols);

        for (size_t i = 0; i < mat->rows; ++i) {
            if (i == row1) {
                for (size_t j = 0; j < mat->cols; ++j) {
                    table[i][j] = mat->table[row2][j];
                }
            }
            else if (i == row2) {
                for (size_t j = 0; j < mat->cols; ++j) {
                    table[i][j] = mat->table[row1][j];
                }
            }
            else {
                for (size_t j = 0; j < mat->cols; ++j) {
                    table[i][j] = mat->table[i][j];
                }
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = mat->rows;
        result->cols = mat->cols;
    }
}

void _add_cols_in_place(const size_t fromCol, const size_t toCol, matrix_t* result) {
    for (size_t row = 0; row < result->rows; ++row) {
        result->table[row][toCol] += result->table[row][fromCol];
    }
}

void add_cols(const matrix_t* mat, const size_t fromCol, const size_t toCol, matrix_t* result) {
    if (mat == result) {
        _add_cols_in_place(fromCol, toCol, result);
    }
    else {
        double** table = _make_table(mat->rows, mat->cols);

        for (size_t i = 0; i < mat->rows; ++i) {
            for (size_t j = 0; j < mat->cols; ++j) {
                table[i][j] = mat->table[i][j];

                if (j == toCol) {
                    table[i][j] += mat->table[i][fromCol];
                }
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = mat->rows;
        result->cols = mat->cols;
    }
}

void _col_mult_in_place(const size_t col, const double value, matrix_t* result) {
    for (size_t row = 0; row < result->rows; ++row) {
        result->table[row][col] *= value;
    }
}

void col_mult(const matrix_t* mat, const size_t col, const double value, matrix_t* result) {
    if (mat == result) {
        _col_mult_in_place(col, value, result);
    }
    else {
        double** table = _make_table(mat->rows, mat->cols);

        for (size_t i = 0; i < mat->rows; ++i) {
            for (size_t j = 0; j < mat->cols; ++j) {
                table[i][j] = mat->table[i][j];

                if (j == col) {
                    table[i][j] *= value;
                }
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = mat->rows;
        result->cols = mat->cols;
    }
}

void _col_swap_in_place(const size_t col1, const size_t col2, matrix_t* result) {
    for (size_t row = 0; row < result->rows; ++row) {
        double temp = result->table[row][col1];
        result->table[row][col1] = result->table[row][col2];
        result->table[row][col2] = temp;
    }
}

void col_swap(const matrix_t* mat, const size_t col1, const size_t col2, matrix_t* result) {
    if (mat == result) {
        _col_swap_in_place(col1, col2, result);
    }
    else {
        double** table = _make_table(mat->rows, mat->cols);

        for (size_t i = 0; i < mat->rows; ++i) {
            for (size_t j = 0; j < mat->cols; ++j) {
                if (j == col1) {
                    table[i][j] = mat->table[i][col2];
                }
                else if (j == col2) {
                    table[i][j] = mat->table[i][col1];
                }
                else {
                    table[i][j] = mat->table[i][j];
                }
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = mat->rows;
        result->cols = mat->cols;
    }
}

bool subm(const matrix_t* mat, const size_t rowIndex, const size_t colIndex, matrix_t* result) {
    if (rowIndex < 0 || rowIndex >= mat->rows || colIndex < 0 || colIndex >= mat->cols) {
        return false;
    }

    size_t rowSize = mat->rows - 1;
    size_t colSize = mat->cols - 1;
    double** subtable = _make_table(rowSize, colSize);

    size_t subtableRow = 0; 
    for (size_t i = 0; i < mat->rows; ++i) {
        if (i != rowIndex) {
            size_t subtableCol = 0;

            for (size_t j = 0; j < mat->cols; ++j) {
                if (j != colIndex) {
                    subtable[subtableRow][subtableCol] = mat->table[i][j];
                    ++subtableCol;
                }
            }

            ++subtableRow;   
        }
    }

    _destroy_table(result);
    result->table = subtable;
    result->rows = rowSize;
    result->cols = colSize;

    return true;
}

void _cofactorsm_in_place(matrix_t* result) {
    for (size_t i = 0; i < result->rows; ++i) {
        for (size_t j = 0; j < result->cols; ++j) {
            if (0 == i % 2 ^ 0 == j % 2) {
                result->table[i][j] = -result->table[i][j];
            }
        }
    }
}

void cofactorsm(const matrix_t* mat, matrix_t* result) {
    if (mat == result) {
        _cofactorsm_in_place(result);
    }
    else {
        double** table = _make_table(mat->rows, mat->cols);

        for (size_t i = 0; i < mat->rows; ++i) {
            for (size_t j = 0; j < mat->cols; ++j) {
                if (0 == i % 2 ^ 0 == j % 2) {
                    table[i][j] = -mat->table[i][j];
                }
                else {
                    table[i][j] = mat->table[i][j];
                }
            }
        }

        _destroy_table(result);
        result->table = table;
        result->rows = mat->rows;
        result->cols = mat->cols;
    }
}
