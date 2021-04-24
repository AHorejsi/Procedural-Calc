#include <stdbool.h>

typedef struct complex {
    double real;
    double imag0;
} Complex;

typedef struct quaternion {
    double real;
    double imag0;
    double imag1;
    double imag2;
} Quaternion;

extern const Complex IMAG0;
extern const Quaternion IMAG1;
extern const Quaternion IMAG2;

void rplusc(const double, const Complex*, Complex*);

void cplusr(const Complex*, const double, Complex*);

void cplusc(const Complex*, const Complex*, Complex*);

void rplusq(const double, const Quaternion*, Quaternion*);

void qplusr(const Quaternion*, const double, Quaternion*);

void cplusq(const Complex*, const Quaternion*, Quaternion*);

void qplusc(const Quaternion*, const Complex*, Quaternion*);

void qplusq(const Quaternion*, const Quaternion*, Quaternion*);

void rminusc(const double, const Complex*, Complex*);

void cminusr(const Complex*, const double, Complex*);

void cminusc(const Complex*, const Complex*, Complex*);

void rminusq(const double, const Quaternion*, Quaternion*);

void qminusr(const Quaternion*, const double, Quaternion*);

void cminusq(const Complex*, const Quaternion*, Quaternion*);

void qminusc(const Quaternion*, const Complex*, Quaternion*);

void qminusq(const Quaternion*, const Quaternion*, Quaternion*);

void rmultc(const double, const Complex*, Complex*);

void cmultr(const Complex*, const double, Complex*);

void cmultc(const Complex*, const Complex*, Complex*);

void rmultq(const double, const Quaternion*, Quaternion*);

void qmultr(const Quaternion*, const double, Quaternion*);

void cmultq(const Complex*, const Quaternion*, Quaternion*);

void qmultc(const Quaternion*, const Complex*, Quaternion*);

void qmultq(const Quaternion*, const Quaternion*, Quaternion*);

void rdivc(const double, const Complex*, Complex*);

void cdivr(const Complex*, const double, Complex*);

void cdivc(const Complex*, const Complex*, Complex*);

void rdivq(const double, const Quaternion*, Quaternion*);

void qdivr(const Quaternion*, const double, Quaternion*);

void cdivq(const Complex*, const Quaternion*, Quaternion*);

void qdivc(const Quaternion*, const Complex*, Quaternion*);

void qdivq(const Quaternion*, const Quaternion*, Quaternion*);

void rpowc(const double, const Complex*, Complex*);

void cpowr(const Complex*, const double, Complex*);

void cpowc(const Complex*, const Complex*, Complex*);

void rpowq(const double, const Quaternion*, Quaternion*);

void qpowr(const Quaternion*, const double, Quaternion*);

void cpowq(const Complex*, const Quaternion*, Quaternion*);

void qpowc(const Quaternion*, const Complex*, Quaternion*);

void qpowq(const Quaternion*, const Quaternion*, Quaternion*);

void negc(const Complex*, Complex*);

void negq(const Quaternion*, Quaternion*);

bool reqr(const double, const double, const double);

bool reqc(const double, const Complex*, const double);

bool ceqr(const Complex*, const double, const double);

bool ceqc(const Complex*, const Complex*, const double);

bool reqq(const double, const Quaternion*, const double);

bool qeqr(const Quaternion*, const double, const double);

bool ceqq(const Complex*, const Quaternion*, const double);

bool qeqc(const Quaternion*, const Complex*, const double);

bool qeqq(const Quaternion*, const Quaternion*, const double);

void conjc(const Complex*, Complex*);

void conjq(const Quaternion*, Quaternion*);

void normc(const Complex*, Complex*);

void normq(const Quaternion*, Quaternion*);

double absc(const Complex*);

double absq(const Quaternion*);

void invc(const Complex*, Complex*);

void invq(const Quaternion*, Quaternion*);

double argc(const Complex*);

void sinc(const Complex*, Complex*);

void cosc(const Complex*, Complex*);

void tanc(const Complex*, Complex*);

void sinhc(const Complex*, Complex*);

void coshc(const Complex*, Complex*);

void tanhc(const Complex*, Complex*);

void asinc(const Complex*, Complex*);

void acosc(const Complex*, Complex*);

void atanc(const Complex*, Complex*);

void asinhc(const Complex*, Complex*);

void acoshc(const Complex*, Complex*);

void atanhc(const Complex*, Complex*);

void sqrtc(const Complex*, Complex*);

void sqrtq(const Quaternion*, Quaternion*);

void logc(const Complex*, Complex*);

void logq(const Quaternion*, Quaternion*);

void log10c(const Complex*, Complex*);

void log10q(const Quaternion*, Quaternion*);

void expc(const Complex*, Complex*);

void expq(const Quaternion*, Quaternion*);
