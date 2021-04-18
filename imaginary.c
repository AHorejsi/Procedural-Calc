#define _USE_MATH_DEFINES

#include <math.h>
#include "imaginary.h"

const Complex IMAG0 = { 0, 1 };
const Quaternion IMAG1 = { 0, 0, 1, 0 };
const Quaternion IMAG2 = { 0, 0, 0, 1 };

void rplusc(const double left, const Complex* right, Complex* result) {
    cplusr(right, left, result);
}

void cplusr(const Complex* left, const double right, Complex* result) {
    result->real = left->real + right;
    result->imag0 = left->imag0;
}

void cplusc(const Complex* left, const Complex* right, Complex* result) {
    result->real = left->real + right->real;
    result->imag0 = left->imag0 + right->imag0;
}

void rplusq(const double left, const Quaternion* right, Quaternion* result) {
    qplusr(right, left, result);
}

void qplusr(const Quaternion* left, const double right, Quaternion* result) {
    result->real = left->real + right;
    result->imag0 = left->imag0;
    result->imag1 = left->imag1;
    result->imag2 = left->imag2;
}

void cplusq(const Complex* left, const Quaternion* right, Quaternion* result) {
    qplusc(right, left, result);
}

void qplusc(const Quaternion* left, const Complex* right, Quaternion* result) {
    result->real = left->real + right->real;
    result->imag0 = left->imag0 + right->imag0;
    result->imag1 = left->imag1;
    result->imag2 = left->imag2;
}

void qplusq(const Quaternion* left, const Quaternion* right, Quaternion* result) {
    result->real = left->real + right->real;
    result->imag0 = left->imag0 + right->imag0;
    result->imag1 = left->imag1 + right->imag1;
    result->imag2 = left->imag2 + right->imag2;
}

void rminusc(const double left, const Complex* right, Complex* result) {
    result->real = left - right->real;
    result->imag0 = -right->imag0;
}

void cminusr(const Complex* left, const double right, Complex* result) {
    result->real = left->real - right;
    result->imag0 = left->imag0;
}

void cminusc(const Complex* left, const Complex* right, Complex* result) {
    result->real = left->real - right->real;
    result->imag0 = left->imag0 - right->imag0;
}

void rminusq(const double left, const Quaternion* right, Quaternion* result) {
    result->real = left - right->real;
    result->imag0 = -right->imag0;
    result->imag1 = -right->imag1;
    result->imag2 = -right->imag2;
}

void qminusr(const Quaternion* left, const double right, Quaternion* result) {
    result->real = left->real - right;
    result->imag0 = left->imag0;
    result->imag1 = left->imag1;
    result->imag2 = left->imag2;
}

void cminusq(const Complex* left, const Quaternion* right, Quaternion* result) {
    result->real = left->real - right->real;
    result->imag0 = left->imag0 - right->imag0;
    result->imag1 = -right->imag1;
    result->imag2 = -right->imag2;
}

void qminusc(const Quaternion* left, const Complex* right, Quaternion* result) {
    result->real = left->real - right->real;
    result->imag0 = left->imag0 - right->imag0;
    result->imag1 = left->imag1;
    result->imag2 = left->imag2;
}

void qminusq(const Quaternion* left, const Quaternion* right, Quaternion* result) {
    result->real = left->real - right->real;
    result->imag0 = left->imag0 - right->imag0;
    result->imag1 = left->imag1 - right->imag1;
    result->imag2 = left->imag2 - right->imag2;
}

void rmultc(const double left, const Complex* right, Complex* result) {
    cmultr(right, left, result);
}

void cmultr(const Complex* left, const double right, Complex* result) {
    result->real = left->real * right;
    result->imag0 = left->imag0 * right;
}

void cmultc(const Complex* left, const Complex* right, Complex* result) {
    double realResult = left->real * right->real - left->imag0 * right->imag0;
    double imag0Result = left->real * right->imag0 + left->imag0 * right->real;

    result->real = realResult;
    result->imag0 = imag0Result;
}

void rmultq(const double left, const Quaternion* right, Quaternion* result) {
    qmultr(right, left, result);
}

void qmultr(const Quaternion* left, const double right, Quaternion* result) {
    result->real = left->real * right;
    result->imag0 = left->imag0 * right;
    result->imag1 = left->imag1 * right;
    result->imag2 = left->imag2 * right;
}

void cmultq(const Complex* left, const Quaternion* right, Quaternion* result) {
    double realResult = left->real * right->real - left->imag0 * right->imag0;
    double imag0Result = left->real * right->imag0 + right->real * left->imag0;
    double imag1Result = left->real * right->imag1 - left->imag0 * right->imag2;
    double imag2Result = left->real * right->imag2 + left->imag0 * right->imag1;

    result->real = realResult;
    result->imag0 = imag0Result;
    result->imag1 = imag1Result;
    result->imag2 = imag2Result;
}

void qmultc(const Quaternion* left, const Complex* right, Quaternion* result) {
    double realResult = left->real * right->real - left->imag0 * right->imag0;
    double imag0Result = left->real * right->imag0 + left->imag0 * right->real;
    double imag1Result = left->imag1 * right->real + left->imag2 * right->imag0;
    double imag2Result = -left->imag1 * right->imag0 + left->imag2 * right->real;

    result->real = realResult;
    result->imag0 = imag0Result;
    result->imag1 = imag1Result;
    result->imag2 = imag2Result;
}

void qmultq(const Quaternion* left, const Quaternion* right, Quaternion* result) {
    double realResult = left->real * right->real - left->imag0 * right->imag0 - left->imag1 * right->imag1 - left->imag2 * right->imag2;
    double imag0Result = left->real * right->imag0 + left->imag0 * right->real - left->imag1 * right->imag2 + left->imag2 * right->imag1;
    double imag1Result = left->real * right->imag1 + left->imag0 * right->imag2 + left->imag1 * right->real - left->imag2 * right->imag0;
    double imag2Result = left->real * right->imag2 - left->imag0 * right->imag1 + left->imag1 * right->imag0 + left->imag2 * right->real;

    result->real = realResult;
    result->imag0 = imag0Result;
    result->imag1 = imag1Result;
    result->imag2 = imag2Result;
}

void rdivc(const double left, const Complex* right, Complex* result) {
    Complex leftAsComplex = { left, 0 };
    cdivc(&leftAsComplex, right, result);
}

void cdivr(const Complex* left, const double right, Complex* result) {
    result->real = left->real / right;
    result->imag0 = left->imag0 / right;
}

void cdivc(const Complex* left, const Complex* right, Complex* result) {
    Complex conjOfRight;
    Complex numerator;
    Complex denominator;

    conjc(right, &conjOfRight);
    cmultc(left, &conjOfRight, &numerator);
    cmultc(right, &conjOfRight, &denominator);
    cdivr(&numerator, denominator.real, result);
}

void rdivq(const double left, const Quaternion* right, Quaternion* result) {
    double denominator = right->real * right->real + right->imag0 * right->imag0 + right->imag1 * right->imag1 + right->imag2 * right->imag2;

    result->real = left * right->real / denominator;
    result->imag0 = -left * right->imag0 / denominator;
    result->imag1 = -left * right->imag1 / denominator;
    result->imag2 = -left * right->imag2 / denominator;
}

void qdivr(const Quaternion* left, const double right, Quaternion* result) {
    result->real = left->real / right;
    result->imag0 = left->imag0 / right;
    result->imag1 = left->imag1 / right;
    result->imag2 = left->imag2 / right;
}

void cdivq(const Complex* left, const Quaternion* right, Quaternion* result) {
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

void qdivc(const Quaternion* left, const Complex* right, Quaternion* result) {
    Complex conjOfRight;
    Quaternion numerator;
    Complex denominator;

    conjc(right, &conjOfRight);
    qmultc(left, &conjOfRight, &numerator);
    cmultc(right, &conjOfRight, &denominator);
    qdivr(&numerator, denominator.real, result);
}

void qdivq(const Quaternion* left, const Quaternion* right, Quaternion* result) {
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

void rpowc(const double left, const Complex* right, Complex* result) {
    Complex leftAsComplex = { left, 0 };
    cpowc(&leftAsComplex, right, result);
}

void cpowr(const Complex* left, const double right, Complex* result) {
    Complex rightAsComplex = { right, 0 };
    cpowc(left, &rightAsComplex, result);
}

void cpowc(const Complex* left, const Complex* right, Complex* result) {
    bool leftIsZero = (0 == left->real) && (0 == left->imag0);
    bool rightIsZero = (0 == right->real) && (0 == right->imag0);

    if (leftIsZero && rightIsZero) {
        result->real = NAN;
        result->imag0 = NAN;
    }
    else if (leftIsZero) {
        result->real = 0;
        result->imag0 = 0;
    }
    else if (rightIsZero) {
        result->real - 1;
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

void rpowq(const double left, const Quaternion* right, Quaternion* result) {
    Quaternion a;

    rmultq(log(left), right, &a);
    expq(&a, result);
}

void qpowr(const Quaternion* left, const double right, Quaternion* result) {
    Quaternion a;
    Quaternion b;

    logq(left, &a);
    qmultr(&a, right, &b);
    expq(&b, result);
}

void cpowq(const Complex* left, const Quaternion* right, Quaternion* result) {
    Complex a;
    Quaternion b;

    logc(left, &a);
    cmultq(&a, right, &b);
    expq(&b, result);
}

void qpowc(const Quaternion* left, const Complex* right, Quaternion* result) {
    Quaternion a;
    Quaternion b;

    logq(left, &a);
    qmultc(&a, right, &b);
    expq(&b, result);
}

void qpowq(const Quaternion* left, const Quaternion* right, Quaternion* result) {
    Quaternion a;
    Quaternion b;

    logq(left, &a);
    qmultq(&a, right, &b);
    expq(&b, result);
}

void negc(const Complex* com, Complex* result) {
    result->real = -com->real;
    result->imag0 = -com->imag0;
}

void negq(const Quaternion* quat, Quaternion* result) {
    result->real = -quat->real;
    result->imag0 = -quat->imag0;
    result->imag1 = -quat->imag1;
    result->imag2 = -quat->imag2;
}

bool reqr(const double left, const double right, const double range) {
    return abs(left - right) <= range;
}

bool reqc(const double left, const Complex* right, const double range) {
    return ceqr(right, left, range);
}

bool ceqr(const Complex* left, const double right, const double range) {
    return abs(left->real - right) <= range && abs(left->imag0) <= range;
}

bool ceqc(const Complex* left, const Complex* right, const double range) {
    return abs(left->real - right->real) <= range && abs(left->imag0 - right->imag0) <= range;
}

bool reqq(const double left, const Quaternion* right, const double range) {
    return qeqr(right, left, range);
}

bool qeqr(const Quaternion* left, const double right, const double range) {
    return abs(left->real - right) <= range && abs(left->imag0) <= range && abs(left->imag1) <= range && abs(left->imag2) <= range;
}

bool ceqq(const Complex* left, const Quaternion* right, const double range) {
    return qeqc(right, left, range);
}

bool qeqc(const Quaternion* left, const Complex* right, const double range) {
    return abs(left->real - right->real) <= range && abs(left->imag0 - right->imag0) <= range && abs(left->imag1) <= range && abs(left->imag2) <= range;
}

bool qeqq(const Quaternion* left, const Quaternion* right, const double range) {
    return abs(left->real - right->real) <= range && abs(left->imag0 - right->imag0) <= range && abs(left->imag1 - right->imag1) <= range && abs(left->imag2 - right->imag2) <= range;
}

void conjc(const Complex* com, Complex* result) {
    result->real = com->real;
    result->imag0 = -com->imag0;
}

void conjq(const Quaternion* quat, Quaternion* result) {
    result->real = quat->real;
    result->imag0 = -quat->imag0;
    result->imag1 = -quat->imag1;
    result->imag2 = -quat->imag2;
}

void normc(const Complex* com, Complex* result) {
    cdivr(com, absc(com), result);
}

void normq(const Quaternion* quat, Quaternion* result) {
    qdivr(quat, absq(quat), result);
}

double absc(const Complex* com) {
    return sqrt(com->real * com->real + com->imag0 * com->imag0);
}

double absq(const Quaternion* quat) {
    return sqrt(quat->real * quat->real + quat->imag0 * quat->imag0 + quat->imag1 * quat->imag1 + quat->imag2 * quat->imag2);
}

void invc(const Complex* com, Complex* result) {
    rdivc(1, com, result);
}

void invq(const Quaternion* quat, Quaternion* result) {
    Quaternion conjugate;
    double denominator = quat->real * quat->real + quat->imag0 * quat->imag0 + quat->imag1 * quat->imag1 + quat->imag2 * quat->imag2;

    conjq(quat, &conjugate);
    qdivr(&conjugate, denominator, result);
}

double argc(const Complex* com) {
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

void sinc(const Complex* com, Complex* result) {
    Complex a;
    Complex b;
    Complex c;
    Complex d;
    Complex e;
    Complex f;
    Complex g = { 0, 2 };
    
    cmultc(&IMAG0, com, &a);
    negc(&IMAG0, &b);
    cmultc(&b, com, &c);
    expc(&a, &d);
    expc(&c, &e);
    cminusc(&d, &e, &f);
    cdivc(&f, &g, result);
}

void cosc(const Complex* com, Complex* result) {
    Complex a;
    Complex b;
    Complex c;
    Complex d;
    Complex e;
    Complex f;

    negc(com, &a);
    cmultc(com, &IMAG0, &b);
    cmultc(&a, &IMAG0, &c);
    expc(&b, &d);
    expc(&c, &e);
    cplusc(&d, &e, &f);
    cdivr(&f, 2, result);
}

void tanc(const Complex* com, Complex* result) {
    Complex sinValue;
    Complex cosValue;

    sinc(com, &sinValue);
    cosc(com, &cosValue);
    cdivc(&sinValue, &cosValue, result);
}

void sinhc(const Complex* com, Complex* result) {
    Complex a;
    Complex b;
    Complex c;
    Complex d;

    negc(com, &a);
    expc(com, &b);
    expc(&a, &c);
    cminusc(&b, &c, &d);
    cdivr(&d, 2, result);
}

void coshc(const Complex* com, Complex* result) {
    Complex a;
    Complex b;
    Complex c;
    Complex d;

    negc(com, &a);
    expc(com, &b);
    expc(&a, &c);
    cplusc(&b, &c, &d);
    cdivr(&d, 2, result);
}

void tanhc(const Complex* com, Complex* result) {
    Complex sinhValue;
    Complex coshValue;

    sinhc(com, &sinhValue);
    coshc(com, &coshValue);
    cdivc(&sinhValue, &coshValue, result);
}

void asinc(const Complex* com, Complex* result) {
    Complex a;
    Complex b;
    Complex c;
    Complex d;
    Complex e;
    Complex f;
    Complex g;

    negc(&IMAG0, &a);
    cmultc(com, com, &b);
    rminusc(1, &b, &c);
    sqrtc(&c, &d);
    cmultc(&IMAG0, com, &e);
    cplusc(&e, &d, &f);
    logc(&f, &g);
    cmultc(&a, &g, result);
}

void acosc(const Complex* com, Complex* result) {
    Complex a;
    Complex b;
    Complex c;
    Complex d;
    Complex e;
    Complex f;
    Complex g;

    cmultc(com, com, &a);
    rminusc(1, &a, &b);
    sqrtc(&b, &c);
    cmultc(&IMAG0, com, &d);
    cplusc(&c, &d, &e);
    logc(&e, &f);
    cmultc(&IMAG0, &f, &g);
    rplusc(M_PI_2, &g, result);
}

void atanc(const Complex* com, Complex* result) {
    Complex a;
    Complex b;
    Complex c;
    Complex d;
    Complex e;
    Complex f;
    Complex g;

    cmultc(&IMAG0, com, &a);
    rminusc(1, &a, &b);
    rplusc(1, &a, &c);
    logc(&b, &d);
    logc(&c, &e);
    cminusc(&d, &e, &f);
    cmultc(&IMAG0, &f, &g);
    cdivr(&g, 2, result);
}

void asinhc(const Complex* com, Complex* result) {
    Complex a;
    Complex b;
    Complex c;
    Complex d;

    cmultc(com, com, &a);
    rplusc(1, &a, &b);
    sqrtc(&b, &c);
    cplusc(com, &c, &d);
    logc(&d, result);
}

void acoshc(const Complex* com, Complex* result) {
    Complex a;
    Complex b;
    Complex c;
    Complex d;
    Complex e;
    Complex f;

    cplusr(com, 1, &a);
    cminusr(com, 1, &b);
    sqrtc(&a, &c);
    sqrtc(&b, &d);
    cmultc(&c, &d, &e);
    cplusc(com, &e, &f);
    logc(&f, result);
}

void atanhc(const Complex* com, Complex* result) {
    Complex a;
    Complex b;
    Complex c;
    Complex d;
    Complex e;

    rplusc(1, com, &a);
    rminusc(1, com, &b);
    logc(&a, &c);
    logc(&b, &d);
    cminusc(&c, &d, &e);
    cdivr(&e, 2, result);
}

void sqrtc(const Complex* com, Complex* result) {
    cpowr(com, 0.5, result);
}

void sqrtq(const Quaternion* quat, Quaternion* result) {
    qpowr(quat, 0.5, result);
}

void logc(const Complex* com, Complex* result) {
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

void logq(const Quaternion* quat, Quaternion* result) {
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
        Quaternion a = { 0, quat->imag0, quat->imag1, quat->imag2 };
        double b = absq(quat);

        Quaternion c;
        Quaternion d;

        normq(&a, &c);
        qmultr(&c, acos(quat->real / b), &d);
        rplusq(log(b), &d, result);
    }
}

void log10c(const Complex* com, Complex* result) {
    Complex a;

    logc(com, &a);
    cdivr(&a, log(10), result);
}

void log10q(const Quaternion* quat, Quaternion* result) {
    Quaternion a;

    logq(quat, &a);
    qdivr(&a, log(10), result);
}

void expc(const Complex* com, Complex* result) {
    rpowc(M_E, com, result);
}

void expq(const Quaternion* quat, Quaternion* result) {
    Quaternion a = { 0, quat->imag0, quat->imag1, quat->imag2 };
    double b = absq(&a);
    
    Quaternion c;
    Quaternion d;
    Quaternion e;
    
    normq(&a, &c);
    qmultr(&c, sin(b), &d);
    rplusq(cos(b), &d, &e);
    rmultq(exp(quat->real), &e, result);
}
