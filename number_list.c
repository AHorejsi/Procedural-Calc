#define _USE_MATH_DEFINES

#include "stdio.h"


#include <math.h>
#include <float.h>
#include <string.h>
#include <stdlib.h>
#include "number_list.h"
#include "imaginary.h"

void rplusl(const double left, const NumberList* right, NumberList* result) {
    lplusr(right, left, result);
}

void lplusr(const NumberList* left, const double right, NumberList* result) {
    double* values = (double*)malloc(left->size * sizeof(double));

    for (size_t index = 0; index < left->size; ++index) {
        values[index] = left->values[index] + right;
    }

    free(result->values);
    result->values = values;
    result->size = left->size;
}

bool lplusl(const NumberList* left, const NumberList* right, NumberList* result) {
    if (left->size != right->size) {
        return false;
    }

    double* values = (double*)malloc(left->size * sizeof(double));

    for (size_t index = 0; index < left->size; ++index) {
        values[index] = left->values[index] + right->values[index];
    }

    free(result->values);
    result->values = values;
    result->size = left->size;

    return true;
}

void rminusl(const double left, const NumberList* right, NumberList* result) {
    double* values = (double*)malloc(right->size * sizeof(double));

    for (size_t index = 0; index < right->size; ++index) {
        values[index] = left - right->values[index];
    }

    free(result->values);
    result->values = values;
    result->size = right->size;
}

void lminusr(const NumberList* left, const double right, NumberList* result) {
    double* values = (double*)malloc(left->size * sizeof(double));

    for (size_t index = 0; index < left->size; ++index) {
        values[index] = left->values[index] - right;
    }

    free(result->values);
    result->values = values;
    result->size = left->size;
}

bool lminusl(const NumberList* left, const NumberList* right, NumberList* result) {
    if (left->size != right->size) {
        return false;
    }

    double* values = (double*)malloc(left->size * sizeof(double));

    for (size_t index = 0; index < left->size; ++index) {
        values[index] = left->values[index] - right->values[index];
    }

    free(result->values);
    result->values = values;
    result->size = left->size;

    return true;
}

void rmultl(const double left, const NumberList* right, NumberList* result) {
    lmultr(right, left, result);
}

void lmultr(const NumberList* left, const double right, NumberList* result) {
    double* values = (double*)malloc(left->size * sizeof(double));

    for (size_t index = 0; index < left->size; ++index) {
        values[index] = left->values[index] * right;
    }

    free(result->values);
    result->values = values;
    result->size = left->size;
}

bool lmultl(const NumberList* left, const NumberList* right, NumberList* result) {
    if (left->size != right->size) {
        return false;
    }

    double* values = (double*)malloc(left->size * sizeof(double));

    for (size_t index = 0; index < left->size; ++index) {
        values[index] = left->values[index] * right->values[index];
    }

    free(result->values);
    result->values = values;
    result->size = left->size;

    return true;
}

void rdivl(const double left, const NumberList* right, NumberList* result) {
    double* values = (double*)malloc(right->size * sizeof(double));

    for (size_t index = 0; index < right->size; ++index) {
        values[index] = left / right->values[index];
    }

    free(result->values);
    result->values = values;
    result->size = right->size;
}

void ldivr(const NumberList* left, const double right, NumberList* result) {
    double* values = (double*)malloc(left->size * sizeof(double));

    for (size_t index = 0; index < left->size; ++index) {
        values[index] = left->values[index] / right;
    }

    free(result->values);
}

bool ldivl(const NumberList* left, const NumberList* right, NumberList* result) {
    if (left->size != right->size) {
        return false;
    }

    double* values = (double*)malloc(left->size * sizeof(double));

    for (size_t index = 0; index < left->size; ++index) {
        values[index] = left->values[index] / right->values[index];
    }

    free(result->values);
    result->values = values;
    result->size = left->size;

    return true;
}

void negl(const NumberList* list, NumberList* result) {
    lmultr(list, -1, result);
}

bool leql(const NumberList* left, const NumberList* right, const double range) {
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

double minl(const NumberList* list) {
    double minValue = DBL_MAX;

    for (size_t index = 0; index < list->size; ++index) {
        if (minValue < list->values[index]) {
            minValue = list->values[index];
        }
    }

    return minValue;
}

double maxl(const NumberList* list) {
    double maxValue = -DBL_MAX;

    for (size_t index = 0; index < list->size; ++index) {
        if (maxValue < list->values[index]) {
            maxValue = list->values[index];
        }
    }

    return maxValue;
}

double suml(const NumberList* list) {
    double result = 0;

    for (size_t index = 0; index < list->size; ++index) {
        result += list->values[index];
    }

    return result;
}

double prodl(const NumberList* list) {
    if (0 == list->size) {
        return 0;
    }

    double result = 1;

    for (size_t index = 0; index < list->size; ++index) {
        result *= list->values[index];
    }

    return result;
}

double meanl(const NumberList* list) {
    return suml(list) / list->size;
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

double medianl(const NumberList* list) {
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

void _make_number_list_from_mode(double* values, size_t size, NumberList* result) {
    double byteSize = size * sizeof(double);
    double* resultValues = (double*)malloc(byteSize);
    memcpy(resultValues, values, byteSize);

    free(values);
    free(result->values);

    result->values = resultValues;
    result->size = size;
}

void model(const NumberList* list, const double range, NumberList* result) {
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

double rangel(const NumberList* list) {
    return maxl(list) - minl(list);
}

double midrangel(const NumberList* list) {
    return (maxl(list) + minl(list)) / 2;
}

double variancel(const NumberList* list) {
    double result = 0;
    
    double meanValue = meanl(list);
    for (size_t index = 0; index < list->size; ++index) {
        double diff = list->values[index] - meanValue;
        result += diff * diff;
    }

    return result / (list->size - 1);
}

double stddevl(const NumberList* list) {
    return sqrt(variancel(list));
}
