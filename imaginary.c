#define _USE_MATH_DEFINES

#include <math.h>
#include "imaginary.h"

const complex_t IMAG0 = { 0, 1 };
const quaternion_t IMAG1 = { 0, 0, 1, 0 };
const quaternion_t IMAG2 = { 0, 0, 0, 1 };

void rplusc(const double left, const complex_t* right, complex_t* result) {
    cplusr(right, left, result);
}

void cplusr(const complex_t* left, const double right, complex_t* result) {
    result->real = left->real + right;
    result->imag0 = left->imag0;
}

void cplusc(const complex_t* left, const complex_t* right, complex_t* result) {
    result->real = left->real + right->real;
    result->imag0 = left->imag0 + right->imag0;
}

void rplusq(const double left, const quaternion_t* right, quaternion_t* result) {
    qplusr(right, left, result);
}

void qplusr(const quaternion_t* left, const double right, quaternion_t* result) {
    result->real = left->real + right;
    result->imag0 = left->imag0;
    result->imag1 = left->imag1;
    result->imag2 = left->imag2;
}

void cplusq(const complex_t* left, const quaternion_t* right, quaternion_t* result) {
    qplusc(right, left, result);
}

void qplusc(const quaternion_t* left, const complex_t* right, quaternion_t* result) {
    result->real = left->real + right->real;
    result->imag0 = left->imag0 + right->imag0;
    result->imag1 = left->imag1;
    result->imag2 = left->imag2;
}

void qplusq(const quaternion_t* left, const quaternion_t* right, quaternion_t* result) {
    result->real = left->real + right->real;
    result->imag0 = left->imag0 + right->imag0;
    result->imag1 = left->imag1 + right->imag1;
    result->imag2 = left->imag2 + right->imag2;
}

void rminusc(const double left, const complex_t* right, complex_t* result) {
    result->real = left - right->real;
    result->imag0 = -right->imag0;
}

void cminusr(const complex_t* left, const double right, complex_t* result) {
    result->real = left->real - right;
    result->imag0 = left->imag0;
}

void cminusc(const complex_t* left, const complex_t* right, complex_t* result) {
    result->real = left->real - right->real;
    result->imag0 = left->imag0 - right->imag0;
}

void rminusq(const double left, const quaternion_t* right, quaternion_t* result) {
    result->real = left - right->real;
    result->imag0 = -right->imag0;
    result->imag1 = -right->imag1;
    result->imag2 = -right->imag2;
}

void qminusr(const quaternion_t* left, const double right, quaternion_t* result) {
    result->real = left->real - right;
    result->imag0 = left->imag0;
    result->imag1 = left->imag1;
    result->imag2 = left->imag2;
}

void cminusq(const complex_t* left, const quaternion_t* right, quaternion_t* result) {
    result->real = left->real - right->real;
    result->imag0 = left->imag0 - right->imag0;
    result->imag1 = -right->imag1;
    result->imag2 = -right->imag2;
}

void qminusc(const quaternion_t* left, const complex_t* right, quaternion_t* result) {
    result->real = left->real - right->real;
    result->imag0 = left->imag0 - right->imag0;
    result->imag1 = left->imag1;
    result->imag2 = left->imag2;
}

void qminusq(const quaternion_t* left, const quaternion_t* right, quaternion_t* result) {
    result->real = left->real - right->real;
    result->imag0 = left->imag0 - right->imag0;
    result->imag1 = left->imag1 - right->imag1;
    result->imag2 = left->imag2 - right->imag2;
}

void rmultc(const double left, const complex_t* right, complex_t* result) {
    cmultr(right, left, result);
}

void cmultr(const complex_t* left, const double right, complex_t* result) {
    result->real = left->real * right;
    result->imag0 = left->imag0 * right;
}

void cmultc(const complex_t* left, const complex_t* right, complex_t* result) {
    double realResult = left->real * right->real - left->imag0 * right->imag0;
    double imag0Result = left->real * right->imag0 + left->imag0 * right->real;

    result->real = realResult;
    result->imag0 = imag0Result;
}

void rmultq(const double left, const quaternion_t* right, quaternion_t* result) {
    qmultr(right, left, result);
}

void qmultr(const quaternion_t* left, const double right, quaternion_t* result) {
    result->real = left->real * right;
    result->imag0 = left->imag0 * right;
    result->imag1 = left->imag1 * right;
    result->imag2 = left->imag2 * right;
}

void cmultq(const complex_t* left, const quaternion_t* right, quaternion_t* result) {
    double realResult = left->real * right->real - left->imag0 * right->imag0;
    double imag0Result = left->real * right->imag0 + left->imag0 + right->real;
    double imag1Result = left->real * right->imag1 - left->imag0 * right->imag2;
    double imag2Result = left->real * right->imag2 + left->imag0 * right->imag1;

    result->real = realResult;
    result->imag0 = imag0Result;
    result->imag1 = imag1Result;
    result->imag2 = imag2Result;
}

void qmultc(const quaternion_t* left, const complex_t* right, quaternion_t* result) {
    double realResult = left->real * right->real - left->imag0 * right->imag0;
    double imag0Result = left->real * right->imag0 + left->imag0 * right->real;
    double imag1Result = left->imag1 * right->real + left->imag2 * right->imag0;
    double imag2Result = -left->imag1 * right->imag0 + left->imag2 * right->real;

    result->real = realResult;
    result->imag0 = imag0Result;
    result->imag1 = imag1Result;
    result->imag2 = imag2Result;
}

void qmultq(const quaternion_t* left, const quaternion_t* right, quaternion_t* result) {
    double realResult = left->real * right->real - left->imag0 * right->imag0 - left->imag1 * right->imag1 - left->imag2 * right->imag2;
    double imag0Result = left->real * right->imag0 + left->imag0 * right->real - left->imag1 * right->imag2 + left->imag2 * right->imag1;
    double imag1Result = left->real * right->imag1 + left->imag0 * right->imag2 + left->imag1 * right->real - left->imag2 * right->imag0;
    double imag2Result = left->real * right->imag2 - left->imag0 * right->imag1 + left->imag1 * right->imag0 + left->imag2 * right->real;

    result->real = realResult;
    result->imag0 = imag0Result;
    result->imag1 = imag1Result;
    result->imag2 = imag2Result;
}

void rdivc(const double left, const complex_t* right, complex_t* result) {
    complex_t leftAsComplex = { left, 0 };
    cdivc(&leftAsComplex, right, result);
}

void cdivr(const complex_t* left, const double right, complex_t* result) {
    result->real = left->real / right;
    result->imag0 = left->imag0 / right;
}

void cdivc(const complex_t* left, const complex_t* right, complex_t* result) {
    complex_t conjOfRight;
    complex_t numerator;
    complex_t denominator;

    conjc(right, &conjOfRight);
    cmultc(left, &conjOfRight, &numerator);
    cmultc(right, &conjOfRight, &denominator);
    cdivr(&numerator, denominator.real, result);
}

void rdivq(const double left, const quaternion_t* right, quaternion_t* result) {
    double denominator = right->real * right->real + right->imag0 * right->imag0 + right->imag1 * right->imag1 + right->imag2 * right->imag2;

    result->real = left * right->real / denominator;
    result->imag0 = -left * right->imag0 / denominator;
    result->imag1 = -left * right->imag1 / denominator;
    result->imag2 = -left * right->imag2 / denominator;
}

void qdivr(const quaternion_t* left, const double right, quaternion_t* result) {
    result->real = left->real / right;
    result->imag0 = left->imag0 / right;
    result->imag1 = left->imag1 / right;
    result->imag2 = left->imag2 / right;
}

void cdivq(const complex_t* left, const quaternion_t* right, quaternion_t* result) {
    double denominator = right->real * right->real + right->imag0 * right->imag0 + right->imag1 * right->imag1 + right->imag2 * right->imag2;

    double realResult = (left->real * right->real + left->imag0 * right->imag0) / denominator;
    double imag0Result = (left->imag0 * right->real - left->real * right->imag0) / denominator;
    double imag1Result = (-left->real * right->imag1 - left->imag0 * right->imag2) / denominator;
    double imag2Result = (left->imag0 * right->imag1 - left->real * right->imag2) / denominator;

    result->real = realResult;
    result->imag0 = imag0Result;
    result->imag1 = imag1Result;
    result->imag2 = imag2Result;
}

void qdivc(const quaternion_t* left, const complex_t* right, quaternion_t* result) {
    complex_t conjOfRight;
    quaternion_t numerator;
    complex_t denominator;

    conjc(right, &conjOfRight);
    qmultc(left, &conjOfRight, &numerator);
    cmultc(right, &conjOfRight, &denominator);
    qdivr(&numerator, denominator.real, result);
}

void qdivq(const quaternion_t* left, const quaternion_t* right, quaternion_t* result) {
    double denominator = right->real * right->real + right->imag0 * right->imag0 + right->imag1 * right->imag1 + right->imag2 * right->imag2;

    double realResult = (left->real * right->real + left->imag0 * right->imag0 + left->imag1 * right->imag1 + left->imag2 * right->imag2) / denominator;
    double imag0Result = (left->real * right->imag0 - left->imag0 * right->real - left->imag1 * right->imag2 + left->imag2 * right->imag1) / denominator;
    double imag1Result = (left->real * right->imag1 + left->imag0 * right->imag2 - left->imag1 * right->real - left->imag2 * right->imag0) / denominator;
    double imag2Result = (left->real * right->imag2 - left->imag0 * right->imag1 + left->imag1 * right->imag0 - left->imag2 * right->real) / denominator;

    result->real = realResult;
    result->imag0 = imag0Result;
    result->imag1 = imag1Result;
    result->imag2 = imag2Result;
}

void rpowc(const double left, const complex_t* right, complex_t* result) {
    complex_t leftAsComplex = { left, 0 };
    cpowc(&leftAsComplex, right, result);
}

void cpowr(const complex_t* left, const double right, complex_t* result) {
    complex_t rightAsComplex = { right, 0 };
    cpowc(left, &rightAsComplex, result);
}

void cpowc(const complex_t* left, const complex_t* right, complex_t* result) {
    bool leftIsZero = (0 == left->real) && (0 == left->imag0);
    bool rightIsZero = (0 == right->real) && (0 == right->imag0);

    if (rightIsZero) {
        result->real = 1;
        result->imag0 = 0;
    }
    else if (leftIsZero) {
        result->real = 0;
        result->imag0 = 0;
    }
    else {
        double a = left->real * left->real + left->imag0 * left->imag0;
        double b = pow(a, right->real / 2);
        double c = argc(left);
        double d = right->real * c + 0.5 * right->imag0 * log(a);
        double e = b * exp(-right->imag0 * c);

        result->real = e * cos(d);
        result->imag0 = e * sin(d);
    }
}

void rpowq(const double left, const quaternion_t* right, quaternion_t* result) {
    rmultq(log(left), right, result);
    expq(result, result);
}

void qpowr(const quaternion_t* left, const double right, quaternion_t* result) {
    quaternion_t a;
    quaternion_t b;

    logq(left, &a);
    qmultr(&a, right, &b);
    expq(&b, result);
}

void cpowq(const complex_t* left, const quaternion_t* right, quaternion_t* result) {
    complex_t a;
    quaternion_t b;

    logc(left, &a);
    cmultq(&a, right, &b);
    expq(&b, result);
}

void qpowc(const quaternion_t* left, const complex_t* right, quaternion_t* result) {
    quaternion_t a;
    quaternion_t b;

    logq(left, &a);
    qmultc(&a, right, &b);
    expq(&b, result);
}

void qpowq(const quaternion_t* left, const quaternion_t* right, quaternion_t* result) {
    quaternion_t a;
    quaternion_t b;

    logq(left, &a);
    qmultq(&a, right, &b);
    expq(&b, result);
}

void negc(const complex_t* com, complex_t* result) {
    result->real = -com->real;
    result->imag0 = -com->imag0;
}

void negq(const quaternion_t* quat, quaternion_t* result) {
    result->real = -quat->real;
    result->imag0 = -quat->imag0;
    result->imag1 = -quat->imag1;
    result->imag2 = -quat->imag2;
}

bool reqr(const double left, const double right, const double range) {
    return fabs(left - right) <= range;
}

bool reqc(const double left, const complex_t* right, const double range) {
    return ceqr(right, left, range);
}

bool ceqr(const complex_t* left, const double right, const double range) {
    return fabs(left->real - right) <= range && fabs(left->imag0) <= range;
}

bool ceqc(const complex_t* left, const complex_t* right, const double range) {
    return fabs(left->real - right->real) <= range && fabs(left->imag0 - right->imag0) <= range;
}

bool reqq(const double left, const quaternion_t* right, const double range) {
    return qeqr(right, left, range);
}

bool qeqr(const quaternion_t* left, const double right, const double range) {
    return fabs(left->real - right) <= range && fabs(left->imag0) <= range && fabs(left->imag1) <= range && fabs(left->imag2) <= range;
}

bool ceqq(const complex_t* left, const quaternion_t* right, const double range) {
    return qeqc(right, left, range);
}

bool qeqc(const quaternion_t* left, const complex_t* right, const double range) {
    return fabs(left->real - right->real) <= range && fabs(left->imag0 - right->imag0) <= range && fabs(left->imag1) <= range && fabs(left->imag2) <= range;
}

bool qeqq(const quaternion_t* left, const quaternion_t* right, const double range) {
    return fabs(left->real - right->real) <= range && fabs(left->imag0 - right->imag0) <= range && fabs(left->imag1 - right->imag1) <= range && fabs(left->imag2 - right->imag2) <= range;
}

void conjc(const complex_t* com, complex_t* result) {
    result->real = com->real;
    result->imag0 = -com->imag0;
}

void conjq(const quaternion_t* quat, quaternion_t* result) {
    result->real = quat->real;
    result->imag0 = -quat->imag0;
    result->imag1 = -quat->imag1;
    result->imag2 = -quat->imag2;
}

void normc(const complex_t* com, complex_t* result) {
    cdivr(com, absc(com), result);
}

void normq(const quaternion_t* quat, quaternion_t* result) {
    qdivr(quat, absq(quat), result);
}

double absc(const complex_t* com) {
    return sqrt(com->real * com->real + com->imag0 * com->imag0);
}

double absq(const quaternion_t* quat) {
    return sqrt(quat->real * quat->real + quat->imag0 * quat->imag0 + quat->imag1 * quat->imag1 + quat->imag2 * quat->imag2);
}

void invc(const complex_t* com, complex_t* result) {
    rdivc(1, com, result);
}

void invq(const quaternion_t* quat, quaternion_t* result) {
    quaternion_t conjugate;
    double denominator = quat->real * quat->real + quat->imag0 * quat->imag0 + quat->imag1 * quat->imag1 + quat->imag2 * quat->imag2;

    conjq(quat, &conjugate);
    qdivr(&conjugate, denominator, result);
}

double argc(const complex_t* com) {
    if (0 == com->real) {
        if (com->imag0 < 0) {
            return -M_PI_2;
        }
        else if (com->imag0 > 0) {
            return M_PI_2;
        }
        else {
            return NAN;
        }
    }
    else {
        return atan2(com->imag0, com->real);
    }
}

void sinc(const complex_t* com, complex_t* result) {
    complex_t a;
    complex_t b;
    complex_t c;
    complex_t d;
    complex_t e;
    complex_t f;
    complex_t g = { 0, 2 };
    
    cmultc(&IMAG0, com, &a);
    negc(&IMAG0, &b);
    cmultc(&b, com, &c);
    expc(&a, &d);
    expc(&c, &e);
    cminusc(&d, &e, &f);
    cdivc(&f, &g, result);
}

void cosc(const complex_t* com, complex_t* result) {
    complex_t a;
    complex_t b;
    complex_t c;
    complex_t d;
    complex_t e;
    complex_t f;

    negc(com, &a);
    cmultc(com, &IMAG0, &b);
    cmultc(&a, &IMAG0, &c);
    expc(&b, &d);
    expc(&c, &e);
    cplusc(&d, &e, &f);
    cdivr(&f, 2, result);
}

void tanc(const complex_t* com, complex_t* result) {
    complex_t sinValue;
    complex_t cosValue;

    sinc(com, &sinValue);
    cosc(com, &cosValue);
    cdivc(&sinValue, &cosValue, result);
}

void sinhc(const complex_t* com, complex_t* result) {
    complex_t a;
    complex_t b;
    complex_t c;
    complex_t d;

    negc(com, &a);
    expc(com, &b);
    expc(&a, &c);
    cminusc(&b, &c, &d);
    cdivr(&d, 2, result);
}

void coshc(const complex_t* com, complex_t* result) {
    complex_t a;
    complex_t b;
    complex_t c;
    complex_t d;

    negc(com, &a);
    expc(com, &b);
    expc(&a, &c);
    cplusc(&b, &c, &d);
    cdivr(&d, 2, result);
}

void tanhc(const complex_t* com, complex_t* result) {
    complex_t sinhValue;
    complex_t coshValue;

    sinhc(com, &sinhValue);
    coshc(com, &coshValue);
    cdivc(&sinhValue, &coshValue, result);
}

void asinc(const complex_t* com, complex_t* result) {
    complex_t a;
    complex_t b;
    complex_t c;
    complex_t d;
    complex_t e;
    complex_t f;
    complex_t g;

    negc(&IMAG0, &a);
    cmultc(com, com, &b);
    rminusc(1, &b, &c);
    sqrtc(&c, &d);
    cmultc(&IMAG0, com, &e);
    cplusc(&e, &d, &f);
    logc(&f, &g);
    cmultc(&a, &g, result);
}

void acosc(const complex_t* com, complex_t* result) {
    complex_t a;
    complex_t b;
    complex_t c;
    complex_t d;
    complex_t e;
    complex_t f;
    complex_t g;

    cmultc(com, com, &a);
    rminusc(1, &a, &b);
    sqrtc(&b, &c);
    cmultc(&IMAG0, com, &d);
    cplusc(&c, &d, &e);
    logc(&e, &f);
    cmultc(&IMAG0, &f, &g);
    rplusc(M_PI_2, &g, result);
}

void atanc(const complex_t* com, complex_t* result) {
    complex_t a;
    complex_t b;
    complex_t c;
    complex_t d;
    complex_t e;
    complex_t f;
    complex_t g;

    cmultc(&IMAG0, com, &a);
    rminusc(1, &a, &b);
    rplusc(1, &a, &c);
    logc(&b, &d);
    logc(&c, &e);
    cminusc(&d, &e, &f);
    cmultc(&IMAG0, &f, &g);
    cdivr(&g, 2, result);
}

void asinhc(const complex_t* com, complex_t* result) {
    complex_t a;
    complex_t b;
    complex_t c;
    complex_t d;

    cmultc(com, com, &a);
    rplusc(1, &a, &b);
    sqrtc(&b, &c);
    cplusc(com, &c, &d);
    logc(&d, result);
}

void acoshc(const complex_t* com, complex_t* result) {
    complex_t a;
    complex_t b;
    complex_t c;
    complex_t d;
    complex_t e;
    complex_t f;

    cplusr(com, 1, &a);
    cminusr(com, 1, &b);
    sqrtc(&a, &c);
    sqrtc(&b, &d);
    cmultc(&c, &d, &e);
    cplusc(com, &e, &f);
    logc(&f, result);
}

void atanhc(const complex_t* com, complex_t* result) {
    complex_t a;
    complex_t b;
    complex_t c;
    complex_t d;
    complex_t e;

    rplusc(1, com, &a);
    rminusc(1, com, &b);
    logc(&a, &c);
    logc(&b, &d);
    cminusc(&c, &d, &e);
    cdivr(&e, 2, result);
}

void sqrtc(const complex_t* com, complex_t* result) {
    cpowr(com, 0.5, result);
}

void sqrtq(const quaternion_t* quat, quaternion_t* result) {
    qpowr(quat, 0.5, result);
}

void logc(const complex_t* com, complex_t* result) {
    double argValue = argc(com);

    if (NAN == argValue) {
        result->real = NAN;
        result->imag0 = NAN;
    }
    else {
        result->real = log(absc(com));
        result->imag0 = argValue;
    }
}

void logq(const quaternion_t* quat, quaternion_t* result) {
    if (0 == quat->imag0 && 0 == quat->imag1 && 0 == quat->imag2) {
        if (0 == quat->real) {
            result->real = NAN;
            result->imag0 = NAN;
            result->imag1 = NAN;
            result->imag2 = NAN;
        }
        else {
            result->real = log(quat->real);
            result->imag0 = 0;
            result->imag1 = 0;
            result->imag2 = 0;
        }
    }
    else {
        quaternion_t a = { 0, quat->imag0, quat->imag1, quat->imag2 };
        double b = absq(quat);

        quaternion_t c;
        quaternion_t d;

        normq(&a, &c);
        qmultr(&c, acos(quat->real / b), &d);
        rplusq(log(b), &d, result);
    }
}

void log10c(const complex_t* com, complex_t* result) {
    complex_t a;

    logc(com, &a);
    cdivr(&a, log(10), result);
}

void log10q(const quaternion_t* quat, quaternion_t* result) {
    quaternion_t a;

    logq(quat, &a);
    qdivr(&a, log(10), result);
}

void expc(const complex_t* com, complex_t* result) {
    rpowc(M_E, com, result);
}

void expq(const quaternion_t* quat, quaternion_t* result) {
    quaternion_t a = { 0, quat->imag0, quat->imag1, quat->imag2 };
    double b = absq(&a);
    
    quaternion_t c;
    quaternion_t d;
    quaternion_t e;
    
    normq(&a, &c);
    qmultr(&c, sin(b), &d);
    rplusq(cos(b), &d, &e);
    rmultq(exp(quat->real), &e, result);
}
