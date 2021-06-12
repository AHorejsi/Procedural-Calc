#define _USE_MATH_DEFINES

#include <math.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
#include "number_list.h"
#include "imaginary.h"

void rplusrl(const double left, const real_list_t* right, real_list_t* result) {
    rlplusr(right, left, result);
}

void _lplusr_in_place(const double value, real_list_t* result) {
    for (size_t index = 0; index < result->size; ++index) {
        result->values[index] += value;
    }
}

void rlplusr(const real_list_t* left, const double right, real_list_t* result) {
    if (left == result) {
        _lplusr_in_place(right, result);
    }
    else {
        double* values = (double*)malloc(left->size * sizeof(double));

        for (size_t index = 0; index < left->size; ++index) {
            values[index] = left->values[index] + right;
        }

        free(result->values);
        result->values = values;
        result->size = left->size;
    }
}

void _lplusl_in_place(const real_list_t* other, real_list_t* result) {
    for (size_t index = 0; index < other->size; ++index) {
        result->values[index] += other->values[index];
    }
}

bool rlplusrl(const real_list_t* left, const real_list_t* right, real_list_t* result) {
    if (left->size != right->size) {
        return false;
    }

    if (left == result) {
        _lplusl_in_place(right, result);
    }
    else if (right == result) {
        _lplusl_in_place(left, result);
    }
    else {
        double* values = (double*)malloc(left->size * sizeof(double));

        for (size_t index = 0; index < left->size; ++index) {
            values[index] = left->values[index] + right->values[index];
        }

        free(result->values);
        result->values = values;
        result->size = left->size;
    }

    return true;
}

void _rminusl_in_place(const double value, real_list_t* result) {
    for (size_t index = 0; index < result->size; ++index) {
        result->values[index] = value - result->values[index];
    }
}

void rminusrl(const double left, const real_list_t* right, real_list_t* result) {
    if (right == result) {
        _rminusl_in_place(left, result);
    }
    else {
        double* values = (double*)malloc(right->size * sizeof(double));

        for (size_t index = 0; index < right->size; ++index) {
            values[index] = left - right->values[index];
        }

        free(result->values);
        result->values = values;
        result->size = right->size;
    }
}

void _lminusr_in_place(const double value, real_list_t* result) {
    for (size_t index = 0; index < result->size; ++index) {
        result->values[index] -= value;
    }
}

void rlminusr(const real_list_t* left, const double right, real_list_t* result) {
    if (left == result) {
        _lminusr_in_place(right, result);
    }
    else {
        double* values = (double*)malloc(left->size * sizeof(double));

        for (size_t index = 0; index < left->size; ++index) {
            values[index] = left->values[index] - right;
        }

        free(result->values);
        result->values = values;
        result->size = left->size;
    }
}

void _lminusl_in_place(const real_list_t* other, real_list_t* result) {
    for (size_t index = 0; index < other->size; ++index) {
        result->values[index] -= other->values[index];
    }
}

bool rlminusrl(const real_list_t* left, const real_list_t* right, real_list_t* result) {
    if (left->size != right->size) {
        return false;
    }

    if (left == result) {
        _lminusl_in_place(right, result);
    }
    else if (right == result) {
        _lminusl_in_place(left, result);
    }
    else {
        double* values = (double*)malloc(left->size * sizeof(double));

        for (size_t index = 0; index < left->size; ++index) {
            values[index] = left->values[index] - right->values[index];
        }

        free(result->values);
        result->values = values;
        result->size = left->size;
    }

    return true;
}

void rmultrl(const double left, const real_list_t* right, real_list_t* result) {
    rlmultr(right, left, result);
}

void _lmultr_in_place(const double value, real_list_t* result) {
    for (size_t index = 0; index < result->size; ++index) {
        result->values[index] *= value;
    }
}

void rlmultr(const real_list_t* left, const double right, real_list_t* result) {
    if (left == result) {
        _lmultr_in_place(right, result);
    }
    else {
        double* values = (double*)malloc(left->size * sizeof(double));

        for (size_t index = 0; index < left->size; ++index) {
            values[index] = left->values[index] * right;
        }

        free(result->values);
        result->values = values;
        result->size = left->size;
    }
}

void _lmultl_in_place(const real_list_t* other, real_list_t* result) {
    for (size_t index = 0; index < other->size; ++index) {
        result->values[index] *= other->values[index];
    }
}

bool rlmultrl(const real_list_t* left, const real_list_t* right, real_list_t* result) {
    if (left->size != right->size) {
        return false;
    }

    if (left == result) {
        _lmultl_in_place(right, result);
    }
    else if (right == result) {
        _lmultl_in_place(left, result);
    }
    else {
        double* values = (double*)malloc(left->size * sizeof(double));

        for (size_t index = 0; index < left->size; ++index) {
            values[index] = left->values[index] * right->values[index];
        }

        free(result->values);
        result->values = values;
        result->size = left->size;
    }

    return true;
}

void _rdivl_in_place(const double value, real_list_t* result) {
    for (size_t index = 0; index < result->size; ++index) {
        result->values[index] = value / result->values[index];
    }
}

void rdivrl(const double left, const real_list_t* right, real_list_t* result) {
    if (right == result) {
        _rdivl_in_place(left, result);
    }
    else {
        double* values = (double*)malloc(right->size * sizeof(double));

        for (size_t index = 0; index < right->size; ++index) {
            values[index] = left / right->values[index];
        }

        free(result->values);
        result->values = values;
        result->size = right->size;
    }
}

void _ldivr_in_place(const double value, real_list_t* result) {
    for (size_t index = 0; index < result->size; ++index) {
        result->values[index] /= value;
    }
}

void rldivr(const real_list_t* left, const double right, real_list_t* result) {
    if (left == result) {
        _ldivr_in_place(right, result);
    }
    else {
        double* values = (double*)malloc(left->size * sizeof(double));

        for (size_t index = 0; index < left->size; ++index) {
            values[index] = left->values[index] / right;
        }

        free(result->values);
        result->values = values;
        result->size = left->size;
    }
}

void _ldivl_in_place(const real_list_t* other, real_list_t* result) {
    for (size_t index = 0; index < other->size; ++index) {
        result->values[index] /= other->values[index];
    }
}

bool rldivrl(const real_list_t* left, const real_list_t* right, real_list_t* result) {
    if (left->size != right->size) {
        return false;
    }

    if (left == result) {
        _ldivl_in_place(right, result);
    }
    else if (right == result) {
        _ldivl_in_place(left, result);
    }
    else {
        double* values = (double*)malloc(left->size * sizeof(double));

        for (size_t index = 0; index < left->size; ++index) {
            values[index] = left->values[index] / right->values[index];
        }

        free(result->values);
        result->values = values;
        result->size = left->size;
    }

    return true;
}

void negrl(const real_list_t* list, real_list_t* result) {
    rlmultr(list, -1, result);
}

bool rleqrl(const real_list_t* left, const real_list_t* right, const double range) {
    if (left->size != right->size) {
        return false;
    }

    for (size_t index = 0; index < left->size; ++index) {
        if (!reqr(left->values[index], right->values[index], range)) {
            return false;
        }
    }

    return true;
}

double minrl(const real_list_t* list) {
    double minValue = DBL_MAX;

    for (size_t index = 0; index < list->size; ++index) {
        if (minValue < list->values[index]) {
            minValue = list->values[index];
        }
    }

    return minValue;
}

double maxrl(const real_list_t* list) {
    double maxValue = -DBL_MAX;

    for (size_t index = 0; index < list->size; ++index) {
        if (maxValue < list->values[index]) {
            maxValue = list->values[index];
        }
    }

    return maxValue;
}

double sumrl(const real_list_t* list) {
    double result = 0;

    for (size_t index = 0; index < list->size; ++index) {
        result += list->values[index];
    }

    return result;
}

double prodrl(const real_list_t* list) {
    if (0 == list->size) {
        return 0;
    }

    double result = 1;

    for (size_t index = 0; index < list->size; ++index) {
        result *= list->values[index];
    }

    return result;
}

double meanrl(const real_list_t* list) {
    return sumrl(list) / list->size;
}

size_t _partition(double* arr, size_t low, size_t high) {
    double pivot = arr[low];
    size_t i = low - 1;
    size_t j = high + 1;

    while (true) {
        do {
            ++i;
        } while (arr[i] < pivot);

        do {
            --j;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        double temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
}

double _quick_select(double* arr, size_t low, size_t high, size_t index) {
    size_t partitionIndex = _partition(arr, low, high);

    if (partitionIndex == index) {
        return arr[index];
    }
    else if (partitionIndex > index) {
        return _quick_select(arr, low, partitionIndex - 1, index);
    }
    else {
        return _quick_select(arr, partitionIndex + 1, high, index);
    }
}

double medianrl(const real_list_t* list) {
    size_t byteSize = list->size * sizeof(double);
    double* copyArr = (double*)malloc(byteSize);
    memcpy(copyArr, list->values, byteSize);

    double result;
    if (0 == list->size % 2) {
        double lowerMiddle = _quick_select(copyArr, 0, list->size - 1, list->size / 2);
        double upperMiddle = _quick_select(copyArr, 0, list->size - 1, list->size / 2 + 1);
        
        result = (lowerMiddle + upperMiddle) / 2;
    }
    else {
        result = _quick_select(copyArr, 0, list->size, list->size / 2 + 1);
    }

    free(copyArr);

    return result;
}

int _compare(const void* left, const void* right) {
    double leftValue = *(double*)left;
    double rightValue = *(double*)right;

    if (leftValue < rightValue) {
        return -1;
    }
    else if (leftValue > rightValue) {
        return 1;
    }
    else {
        return 0;
    }
}

void _make_number_list_from_mode(double* values, size_t size, real_list_t* result) {
    double byteSize = size * sizeof(double);
    double* resultValues = (double*)malloc(byteSize);
    memcpy(resultValues, values, byteSize);

    free(values);
    free(result->values);

    result->values = resultValues;
    result->size = size;
}

void moderl(const real_list_t* list, const double range, real_list_t* result) {
    size_t sizeOfDouble = sizeof(double);
    size_t byteSize = list->size * sizeOfDouble;
    double* copyArr = (double*)malloc(byteSize);
    
    memcpy(copyArr, list->values, byteSize);
    qsort(copyArr, list->size, sizeOfDouble, _compare);

    double* mode = (double*)malloc(byteSize);
    size_t modeIndex = 0;
    size_t modeCount = -1;
    size_t index = 0;
    size_t currentCount = 1;
    
    while (index < list->size) {
        while (index < list->size - 1 && reqr(copyArr[index], copyArr[index + 1], range)) {
            ++currentCount;
            ++index;
        }

        if (1 != currentCount) {
            if (currentCount == modeCount || -1 == modeCount) {
                mode[modeIndex] = copyArr[index];
                ++modeIndex;
            }
            else if (currentCount > modeCount) {
                modeIndex = 0;
                modeCount = currentCount;

                mode[modeIndex] = copyArr[index];
            }
        }
        
        currentCount = 1;
        ++index;
    }

    free(copyArr);

    _make_number_list_from_mode(mode, modeIndex, result);
}

double rangel(const real_list_t* list) {
    return maxrl(list) - minrl(list);
}

double midrangel(const real_list_t* list) {
    return (maxrl(list) + minrl(list)) / 2;
}

double variancel(const real_list_t* list) {
    double result = 0;
    
    double meanValue = meanrl(list);
    for (size_t index = 0; index < list->size; ++index) {
        double diff = list->values[index] - meanValue;
        result += diff * diff;
    }

    return result / (list->size - 1);
}

double stddevl(const real_list_t* list) {
    return sqrt(variancel(list));
}

bool subl(const real_list_t* list, const size_t startIndex, const size_t endIndex, real_list_t* result) {
    if (startIndex < 0 || startIndex >= list->size) {
        return false;
    }
    if (endIndex < 0 || endIndex > list->size) {
        return false;
    }

    size_t size = endIndex - startIndex;
    size_t byteSize = size * sizeof(double);
    double* values = (double*)malloc(byteSize);
    memcpy(values, list->values + startIndex, byteSize);

    free(result->values);
    result->values = values;
    result->size = size;

    return true;
}
