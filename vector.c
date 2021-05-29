#include <math.h>
#include <stdlib.h>
#include "vector.h"
#include "imaginary.h"

void _vplusv_in_place(const vector_t* other, vector_t* result) {
    for (size_t index = 0; index < other->dimensions; ++index) {
        result->position[index] += other->position[index];
    }
}

bool vplusv(const vector_t* left, const vector_t* right, vector_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    if (left == result) {
        _vplusv_in_place(right, result);
    }
    else if (right == result) {
        _vplusv_in_place(left, result);
    }
    else {
        double* position = (double*)malloc(left->dimensions * sizeof(double));

        for (size_t index = 0; index < left->dimensions; ++index) {
            position[index] = left->position[index] + right->position[index];
        }

        free(result->position);
        result->position = position;
        result->dimensions = left->dimensions;
    }

    return true;
}

void _vminusv_in_place(const vector_t* other, vector_t* result) {
    for (size_t index = 0; index < other->dimensions; ++index) {
        result->position[index] -= other->position[index];
    }
}

bool vminusv(const vector_t* left, const vector_t* right, vector_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    if (left == result) {
        _vminusv_in_place(right, result);
    }
    else if (right == result) {
        _vminusv_in_place(left, result);
    }
    else {
        double* position = (double*)malloc(left->dimensions * sizeof(double));

        for (size_t index = 0; index < left->dimensions; ++index) {
            position[index] = left->position[index] - right->position[index];
        }

        free(result->position);
        result->position = position;
        result->dimensions = left->dimensions;
    }

    return true;
}

void rmultv(const double left, const vector_t* right, vector_t* result) {
    vmultr(right, left, result);
}

void _vmultr_in_place(const double value, vector_t* result) {
    for (size_t index = 0; index < result->dimensions; ++index) {
        result->position[index] *= value;
    }
}

void vmultr(const vector_t* left, const double right, vector_t* result) {
    if (left == result) {
        _vmultr_in_place(right, result);
    }
    else {
        double* position = (double*)malloc(left->dimensions * sizeof(double));

        for (size_t index = 0; index < left->dimensions; ++index) {
            position[index] = left->position[index] * right;
        }

        free(result->position);
        result->position = position;
        result->dimensions = left->dimensions;
    }
}

bool vdotv(const vector_t* left, const vector_t* right, double* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }
    
    *result = 0;

    for (size_t index = 0; index < left->dimensions; ++index) {
        *result += left->position[index] * right->position[index];
    }

    return true;
}

bool vcrossv(const vector_t* left, const vector_t* right, vector_t* result) {
    if (!(3 == left->dimensions && left->dimensions == right->dimensions)) {
        return false;
    }

    double* position = (double*)malloc(left->dimensions * sizeof(double));
    position[0] = left->position[1] * right->position[2] - left->position[2] * right->position[1];
    position[1] = left->position[2] * right->position[0] - left->position[0] * right->position[2];
    position[2] = left->position[0] * right->position[1] - left->position[1] * right->position[0];

    free(result->position);
    result->position = position;
    result->dimensions = left->dimensions;

    return true;
}

void vdivr(const vector_t* left, const double right, vector_t* result) {
    vmultr(left, 1 / right, result);
}

void negv(const vector_t* vec, vector_t* result) {
    vmultr(vec, -1, result);
}

bool veqv(const vector_t* left, const vector_t* right, const double range) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    for (size_t index = 0; index < left->dimensions; ++index) {
        if (!reqr(left->position[index], right->position[index], range)) {
            return false;
        }
    }

    return true;
}

double absv(const vector_t* vec) {
    double result = 0;

    for (size_t index = 0; index < vec->dimensions; ++index) {
        result += vec->position[index] * vec->position[index];
    }

    return sqrt(result);
}

void normv(const vector_t* vec, vector_t* result) {
    vdivr(vec, absv(vec), result);
}

bool anglev(const vector_t* left, const vector_t* right, double* result) {
    double dotProduct;
    
    if (vdotv(left, right, &dotProduct)) {
        *result = acos(dotProduct / (absv(left) * absv(right)));

        return true;
    }
    else {
        return false;
    }
}

bool vdistv(const vector_t* left, const vector_t* right, double* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    *result = 0;

    for (size_t index = 0; index < left->dimensions; ++index) {
        double diff = left->position[index] - right->position[index];
        *result += diff * diff;
    }

    *result = sqrt(*result);

    return true;
}
