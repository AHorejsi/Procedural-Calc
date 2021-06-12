#include <math.h>
#include <stdlib.h>
#include "vector.h"

void _rvplusrv_in_place(const real_vector_t* other, real_vector_t* result) {
    for (size_t index = 0; index < other->dimensions; ++index) {
        result->position[index] += other->position[index];
    }
}

bool rvplusrv(const real_vector_t* left, const real_vector_t* right, real_vector_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    if (left == result) {
        _rvplusrv_in_place(right, result);
    }
    else if (right == result) {
        _rvplusrv_in_place(left, result);
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

void _rvpluscv_in_place(const real_vector_t* other, complex_vector_t* result) {
    for (size_t index = 0; index < other->dimensions; ++index) {
        complex_t* resultPtr = result->position + index;
        rplusc(other->position[index], resultPtr, resultPtr);
    }
}

bool rvpluscv(const real_vector_t* left, const complex_vector_t* right, complex_vector_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    if (right == result) {
        _rvpluscv_in_place(left, result);
    }
    else {
        complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));

        for (size_t index = 0; index < left->dimensions; ++index) {
            rplusc(left->position[index], right->position + index, position + index);
        }

        free(result->position);
        result->position = position;
        result->dimensions = left->dimensions;
    }

    return true;
}

bool cvplusrv(const complex_vector_t* left, const real_vector_t* right, complex_vector_t* result) {
    rvpluscv(right, left, result);
}

void _cvpluscv_in_place(const complex_vector_t* other, complex_vector_t* result) {
    for (size_t index = 0; index < other->dimensions; ++index) {
        complex_t* resultPtr = result->position + index;
        cplusc(other->position + index, resultPtr, resultPtr);
    }
}

bool cvpluscv(const complex_vector_t* left, const complex_vector_t* right, complex_vector_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    if (left == result) {
        _cvpluscv_in_place(right, result);
    }
    else if (right == result) {
        _cvpluscv_in_place(left, result);
    }
    else {
        complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));

        for (size_t index = 0; index < left->dimensions; ++index) {
            cplusc(left->position + index, right->position + index, result->position + index);
        }

        free(result->position);
        result->position = position;
        result->dimensions = left->dimensions;
    }

    return true;
}

void _rvminusrv_in_place(const real_vector_t* other, real_vector_t* result) {
    for (size_t index = 0; index < other->dimensions; ++index) {
        result->position[index] -= other->position[index];
    }
}

bool rvminusrv(const real_vector_t* left, const real_vector_t* right, real_vector_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    if (left == result) {
        _rvminusrv_in_place(right, result);
    }
    else if (right == result) {
        _rvminusrv_in_place(left, result);
        negrv(result, result);
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

void _rvminuscv_in_place(const real_vector_t* other, complex_vector_t* result) {
    for (size_t index = 0; index < other->dimensions; ++index) {
        complex_t* resultPtr = result->position + index;
        rminusc(other->position[index], resultPtr, resultPtr);
    }
}

bool rvminuscv(const real_vector_t* left, const complex_vector_t* right, complex_vector_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    if (right == result) {
        _rvminuscv_in_place(left, result);
    }
    else {
        complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));

        for (size_t index = 0; index < left->dimensions; ++index) {
            rminusc(left->position[index], right->position + index, result->position + index);
        }

        free(result->position);
        result->position = position;
        result->dimensions = left->dimensions;

        return true;
    }
}

void _cvminusrv_in_place(const real_vector_t* other, complex_vector_t* result) {
    for (size_t index = 0; index < other->dimensions; ++index) {
        complex_t* resultPtr = result->position + index;
        cminusr(resultPtr, other->position[index], resultPtr);
    }
}

bool cvminusrv(const complex_vector_t* left, const real_vector_t* right, complex_vector_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    if (left == result) {
        _cvminusrv_in_place(right, result);
    }
    else {
        complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));

        for (size_t index = 0; index < left->dimensions; ++index) {
            cminusr(left->position + index, right->position[index], result->position + index);
        }

        free(result->position);
        result->position = position;
        result->dimensions = left->dimensions;
    }

    return true;
}

void _cvminuscv_in_place(const complex_vector_t* other, complex_vector_t* result) {
    for (size_t index = 0; index < other->dimensions; ++index) {
        complex_t* resultPtr = result->position + index;
        cminusc(resultPtr, other->position + index, resultPtr);
    }
}

bool cvminuscv(const complex_vector_t* left, const complex_vector_t* right, complex_vector_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    if (left == result) {
        _cvminuscv_in_place(right, result);
    }
    else if (right == result) {
        _cvminuscv_in_place(left, result);
        negcv(result, result);
    }
    else {
        complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));

        for (size_t index = 0; index < left->dimensions; ++index) {
            cplusc(left->position + index, right->position, position + index);
        }

        free(result->position);
        result->position = position;
        result->dimensions = left->dimensions;
    }

    return true;
}

void rmultrv(const double left, const real_vector_t* right, real_vector_t* result) {
    rvmultr(right, left, result);
}

void _rvmultr_in_place(const double value, real_vector_t* result) {
    for (size_t index = 0; index < result->dimensions; ++index) {
        result->position[index] *= value;
    }
}

void rvmultr(const real_vector_t* left, const double right, real_vector_t* result) {
    if (left == result) {
        _rvmultr_in_place(right, result);
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

void cmultrv(const complex_t* left, const real_vector_t* right, complex_vector_t* result) {
    rvmultc(right, left, result);
}

void rvmultc(const real_vector_t* left, const complex_t* right, complex_vector_t* result) {
    complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));

    for (size_t index = 0; index < left->dimensions; ++index) {
        rmultc(left->position[index], right, position + index);
    }

    free(result->position);
    result->position = position;
    result->dimensions = left->dimensions;
}

void rmultcv(const double left, const complex_vector_t* right, complex_vector_t* result) {
    cvmultr(right, left, result);
}

void _cvmultr_in_place(const double other, complex_vector_t* result) {
    for (size_t index = 0; index < result->dimensions; ++index) {
        complex_t* resultPtr = result->position + index;
        cmultr(resultPtr, other, resultPtr);
    }
}

void cvmultr(const complex_vector_t* left, const double right, complex_vector_t* result) {
    if (left == result) {
        _cvmultr_in_place(right, result);
    }
    else {
        complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));

        for (size_t index = 0; index < left->dimensions; ++index) {
            cmultr(left->position + index, right, position + index);
        }

        free(result->position);
        result->position = position;
        result->dimensions = left->dimensions;
    }
}

void cmultcv(const complex_t* left, const complex_vector_t* right, complex_vector_t* result) {
    cvmultc(right, left, result);
}

void _cvmultc_in_place(const complex_t* other, complex_vector_t* result) {
    for (size_t index = 0; index < result->dimensions; ++index) {
        complex_t* resultPtr = result->position + index;
        cmultc(resultPtr, other, resultPtr);
    }
}

void cvmultc(const complex_vector_t* left, const complex_t* right, complex_vector_t* result) {
    if (left == result) {
        _cvmultc_in_place(right, result);
    }
    else {
        complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));

        for (size_t index = 0; index < left->dimensions; ++index) {
            cmultc(left->position + index, right, position + index);
        }

        free(result->position);
        result->position = position;
        result->dimensions = left->dimensions;
    }
}

bool rvdotrv(const real_vector_t* left, const real_vector_t* right, double* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }
    
    *result = 0;

    for (size_t index = 0; index < left->dimensions; ++index) {
        *result += left->position[index] * right->position[index];
    }

    return true;
}

bool rvdotcv(const real_vector_t* left, const complex_vector_t* right, complex_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    result->real = 0;
    result->imag0 = 0;

    for (size_t index = 0; index < left->dimensions; ++index) {
        complex_t com;
        rmultc(left->position[index], right->position + index, &com);

        cplusc(result, &com, result);
    }

    return true;
}

bool cvdotrv(const complex_vector_t* left, const real_vector_t* right, complex_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    result->real = 0;
    result->imag0 = 0;

    for (size_t index = 0; index < left->dimensions; ++index) {
        complex_t com;
        cmultr(left->position + index, right->position[index], &com);

        cplusc(result, &com, result);
    }

    return true;
}

bool cvdotcv(const complex_vector_t* left, const complex_vector_t* right, complex_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    result->real = 0;
    result->imag0 = 0;

    for (size_t index = 0; index < left->dimensions; ++index) {
        complex_t com;
        cmultc(left->position + index, right->position + index, &com);

        cplusc(result, &com, result);
    }

    return true;
}

bool rvcrossrv(const real_vector_t* left, const real_vector_t* right, real_vector_t* result) {
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

bool rvcrosscv(const real_vector_t* left, const complex_vector_t* right, complex_vector_t* result) {
    if (!(3 == left->dimensions && left->dimensions == right->dimensions)) {
        return false;
    }

    complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));
    
    complex_t a;
    complex_t b;

    rmultc(left->position[1], right->position + 2, &a);
    rmultc(left->position[2], right->position + 1, &b);
    cminusc(&a, &b, position);

    rmultc(left->position[2], right->position, &a);
    rmultc(left->position[0], right->position + 2, &b);
    cminusc(&a, &b, position + 1);

    rmultc(left->position[0], right->position + 1, &a);
    rmultc(left->position[1], right->position, &b);
    cminusc(&a, &b, position + 2);
    
    free(result->position);
    result->position = position;
    result->dimensions = left->dimensions;

    return true;
}

bool cvcrossrv(const complex_vector_t* left, const real_vector_t* right, complex_vector_t* result) {
    if (!(3 == left->dimensions && left->dimensions == right->dimensions)) {
        return false;
    }

    complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));

    complex_t a;
    complex_t b;

    cmultr(left->position + 1, right->position[2], &a);
    cmultr(left->position + 2, right->position[1], &b);
    cminusc(&a, &b, position);

    cmultr(left->position + 2, right->position[0], &a);
    cmultr(left->position, right->position[2], &b);
    cminusc(&a, &b, position + 1);

    cmultr(left->position, right->position[1], &a);
    cmultr(left->position + 1, right->position[0], &b);
    cminusc(&a, &b, position + 2);

    free(result->position);
    result->position = position;
    result->dimensions = left->dimensions;

    return true;
}

bool cvcrosscv(const complex_vector_t* left, const complex_vector_t* right, complex_vector_t* result) {
    if (!(3 == left->dimensions && left->dimensions == right->dimensions)) {
        return false;
    }

    complex_t* position = (complex_t*)malloc(left->dimensions * sizeof(complex_t));

    complex_t a;
    complex_t b;

    cmultc(left->position + 1, right->position + 2, &a);
    cmultc(left->position + 2, right->position + 1, &b);
    cminusc(&a, &b, position);

    cmultc(left->position + 2, right->position, &a);
    cmultc(left->position, right->position + 2, &b);
    cminusc(&a, &b, position + 1);

    cmultc(left->position, right->position + 1, &a);
    cmultc(left->position + 1, right->position, &b);
    cminusc(&a, &b, position + 2);

    free(result->position);
    result->position = position;
    result->dimensions = left->dimensions;

    return true;
}

void rvdivr(const real_vector_t* left, const double right, real_vector_t* result) {
    rvmultr(left, 1 / right, result);
}

void rvdivc(const real_vector_t* left, const complex_t* right, complex_vector_t* result) {
    complex_t invOfRight;
    invc(right, &invOfRight);

    rvmultc(left, &invOfRight, result);
}

void cvdivr(const complex_vector_t* left, const double right, complex_vector_t* result) {
    cvmultr(left, 1 / right, result);
}

void cvdivc(const complex_vector_t* left, const complex_t* right, complex_vector_t* result) {
    complex_t invOfRight;
    invc(right, &invOfRight);

    cvmultc(left, &invOfRight, result);
}

void negrv(const real_vector_t* vec, real_vector_t* result) {
    rvmultr(vec, -1, result);
}

void negcv(const complex_vector_t* vec, complex_vector_t* result) {
    cvmultr(vec, -1, result);
}

bool rveqrv(const real_vector_t* left, const real_vector_t* right, const double range) {
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

bool rveqcv(const real_vector_t* left, const complex_vector_t* right, const double range) {
    cveqrv(right, left, range);
}

bool cveqrv(const complex_vector_t* left, const real_vector_t* right, const double range) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    for (size_t index = 0; index < left->dimensions; ++index) {
        if (!ceqr(left->position + index, right->position[index], range)) {
            return false;
        }
    }

    return true;
}

bool cveqcv(const complex_vector_t* left, const complex_vector_t* right, const double range) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    for (size_t index = 0; index < left->dimensions; ++index) {
        if (!ceqc(left->position + index, right->position + index, range)) {
            return false;
        }
    }

    return true;
}

double absrv(const real_vector_t* vec) {
    double result = 0;

    for (size_t index = 0; index < vec->dimensions; ++index) {
        result += vec->position[index] * vec->position[index];
    }

    return sqrt(result);
}

void abscv(const complex_vector_t* vec, complex_t* result) {
    result->real = 0;
    result->imag0 = 0;

    for (size_t index = 0; index < vec->dimensions; ++index) {
        complex_t com;
        cvdotcv(vec, vec, &com);

        cplusc(result, &com, result);
    }

    sqrtc(result, result);
}

void normrv(const real_vector_t* vec, real_vector_t* result) {
    rvdivr(vec, absrv(vec), result);
}

void normcv(const complex_vector_t* vec, complex_vector_t* result) {
    complex_t divisor;
    abscv(vec, &divisor);
    cvdivc(vec, &divisor, result);
}

bool rvanglerv(const real_vector_t* left, const real_vector_t* right, double* result) {
    double dotProduct;
    
    if (rvdotrv(left, right, &dotProduct)) {
        *result = acos(dotProduct / (absrv(left) * absrv(right)));

        return true;
    }
    else {
        return false;
    }
}

bool rvanglecv(const real_vector_t* left, const complex_vector_t* right, complex_t* result) {
    complex_t dotProduct;

    if (rvdotcv(left, right, &dotProduct)) {
        double a;
        complex_t b;

        a = absrv(left);
        abscv(right, &b);
        rmultc(a, &b, &b);
        cdivc(&dotProduct, &b, result);

        return true;
    }
    else {
        return false;
    }
}

bool cvanglerv(const complex_vector_t* left, const real_vector_t* right, complex_t* result) {
    complex_t dotProduct;

    if (cvdotrv(left, right, &dotProduct)) {
        complex_t a;
        double b;

        abscv(left, &a);
        b = absrv(right);
        cmultr(&a, b, &a);
        cdivc(&dotProduct, &a, result);

        return true;
    }
    else {
        return false;
    }
}

bool cvanglecv(const complex_vector_t* left, const complex_vector_t* right, complex_t* result) {
    complex_t dotProduct;

    if (cvdotcv(left, right, &dotProduct)) {
        complex_t a;
        complex_t b;

        abscv(left, &a);
        abscv(right, &b);
        cmultc(&a, &b, &a);
        cdivc(&dotProduct, &a, result);

        return true;
    }
    else {
        return false;
    }
}

bool rvdistrv(const real_vector_t* left, const real_vector_t* right, double* result) {
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

bool rvdistcv(const real_vector_t* left, const complex_vector_t* right, complex_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    result->real = 0;
    result->imag0 = 0;

    for (size_t index = 0; index < left->dimensions; ++index) {
        complex_t a;
        
        rminusc(left->position[index], right->position + index, &a);
        cmultc(&a, &a, &a);
        cplusc(result, &a, result);
    }

    return true;
}

bool cvdistrv(const complex_vector_t* left, const real_vector_t* right, complex_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }
    
    result->real = 0;
    result->imag0 = 0;

    for (size_t index = 0; index < left->dimensions; ++index) {
        complex_t a;

        cminusr(left->position + index, right->position[index], &a);
        cmultc(&a, &a, &a);
        cplusc(result, &a, result);
    }

    return true;
}

bool cvdistcv(const complex_vector_t* left, const complex_vector_t* right, complex_t* result) {
    if (left->dimensions != right->dimensions) {
        return false;
    }

    result->real = 0;
    result->imag0 = 0;

    for (size_t index = 0; index < left->dimensions; ++index) {
        complex_t a;

        cminusc(left->position + index, right->position + index, &a);
        cmultc(&a, &a, &a);
        cplusc(result, &a, result);
    }

    return true;
}
