#include <math.h>
#include "vector.h"
#include "imaginary.h"

bool vplusv(const Vector* left, const Vector* right, Vector* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    double* position = (double*)malloc(left->dimensions * sizeof(double));

    for (size_t index = 0; index < left->dimensions; ++index) {
        position[index] = left->position[index] + right->position[index];
    }

    free(result->position);
    result->position = position;
    result->dimensions = left->dimensions;

    return true;
}

bool vminusv(const Vector* left, const Vector* right, Vector* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    double* position = (double*)malloc(left->dimensions * sizeof(double));

    for (size_t index = 0; index < left->dimensions; ++index) {
        position[index] = left->position[index] - right->position[index];
    }

    free(result->position);
    result->position = position;
    result->dimensions = left->dimensions;

    return true;
}

void rmultv(const double left, const Vector* right, Vector* result) {
    vmultr(right, left, result);
}

void vmultr(const Vector* left, const double right, Vector* result) {
    double* position = (double*)malloc(left->dimensions * sizeof(double));

    for (size_t index = 0; index < left->dimensions; ++index) {
        position[index] = left->position[index] * right;
    }

    free(result->position);
    result->position = position;
    result->dimensions = left->dimensions;
}

bool vdotv(const Vector* left, const Vector* right, double* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }
    
    *result = 0;

    for (size_t index = 0; index < left->dimensions; ++index) {
        *result += left->position[index] * right->position[index];
    }

    return true;
}

bool vcrossv(const Vector* left, const Vector* right, Vector* result) {
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

void vdivr(const Vector* left, const double right, Vector* result) {
    vmultr(left, 1 / right, result);
}

void negv(const Vector* vec, Vector* result) {
    vmultr(vec, -1, result);
}

bool veqv(const Vector* left, const Vector* right, const double range) {
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

double absv(const Vector* vec) {
    double result = 0;

    for (size_t index = 0; index < vec->dimensions; ++index) {
        result += vec->position[index] * vec->position[index];
    }

    return sqrt(result);
}

void normv(const Vector* vec, Vector* result) {
    vdivr(vec, absv(vec), result);
}

bool anglev(const Vector* left, const Vector* right, double* result) {
    double dotProduct;
    
    if (vdotv(left, right, &dotProduct)) {
        *result = acos(dotProduct / (absv(left) * absv(right)));

        return true;
    }
    else {
        return false;
    }
}

bool vdistv(const Vector* left, const Vector* right, double* result) {
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