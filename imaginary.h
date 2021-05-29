#include <stdbool.h>

typedef struct complex {
    double real;
    double imag0;
} complex_t;

typedef struct quaternion {
    double real;
    double imag0;
    double imag1;
    double imag2;
} quaternion_t;

extern const complex_t IMAG0;
extern const quaternion_t IMAG1;
extern const quaternion_t IMAG2;

void rplusc(const double, const complex_t*, complex_t*);

void cplusr(const complex_t*, const double, complex_t*);

void cplusc(const complex_t*, const complex_t*, complex_t*);

void rplusq(const double, const quaternion_t*, quaternion_t*);

void qplusr(const quaternion_t*, const double, quaternion_t*);

void cplusq(const complex_t*, const quaternion_t*, quaternion_t*);

void qplusc(const quaternion_t*, const complex_t*, quaternion_t*);

void qplusq(const quaternion_t*, const quaternion_t*, quaternion_t*);

void rminusc(const double, const complex_t*, complex_t*);

void cminusr(const complex_t*, const double, complex_t*);

void cminusc(const complex_t*, const complex_t*, complex_t*);

void rminusq(const double, const quaternion_t*, quaternion_t*);

void qminusr(const quaternion_t*, const double, quaternion_t*);

void cminusq(const complex_t*, const quaternion_t*, quaternion_t*);

void qminusc(const quaternion_t*, const complex_t*, quaternion_t*);

void qminusq(const quaternion_t*, const quaternion_t*, quaternion_t*);

void rmultc(const double, const complex_t*, complex_t*);

void cmultr(const complex_t*, const double, complex_t*);

void cmultc(const complex_t*, const complex_t*, complex_t*);

void rmultq(const double, const quaternion_t*, quaternion_t*);

void qmultr(const quaternion_t*, const double, quaternion_t*);

void cmultq(const complex_t*, const quaternion_t*, quaternion_t*);

void qmultc(const quaternion_t*, const complex_t*, quaternion_t*);

void qmultq(const quaternion_t*, const quaternion_t*, quaternion_t*);

void rdivc(const double, const complex_t*, complex_t*);

void cdivr(const complex_t*, const double, complex_t*);

void cdivc(const complex_t*, const complex_t*, complex_t*);

void rdivq(const double, const quaternion_t*, quaternion_t*);

void qdivr(const quaternion_t*, const double, quaternion_t*);

void cdivq(const complex_t*, const quaternion_t*, quaternion_t*);

void qdivc(const quaternion_t*, const complex_t*, quaternion_t*);

void qdivq(const quaternion_t*, const quaternion_t*, quaternion_t*);

void rpowc(const double, const complex_t*, complex_t*);

void cpowr(const complex_t*, const double, complex_t*);

void cpowc(const complex_t*, const complex_t*, complex_t*);

void rpowq(const double, const quaternion_t*, quaternion_t*);

void qpowr(const quaternion_t*, const double, quaternion_t*);

void cpowq(const complex_t*, const quaternion_t*, quaternion_t*);

void qpowc(const quaternion_t*, const complex_t*, quaternion_t*);

void qpowq(const quaternion_t*, const quaternion_t*, quaternion_t*);

void negc(const complex_t*, complex_t*);

void negq(const quaternion_t*, quaternion_t*);

bool reqr(const double, const double, const double);

bool reqc(const double, const complex_t*, const double);

bool ceqr(const complex_t*, const double, const double);

bool ceqc(const complex_t*, const complex_t*, const double);

bool reqq(const double, const quaternion_t*, const double);

bool qeqr(const quaternion_t*, const double, const double);

bool ceqq(const complex_t*, const quaternion_t*, const double);

bool qeqc(const quaternion_t*, const complex_t*, const double);

bool qeqq(const quaternion_t*, const quaternion_t*, const double);

void conjc(const complex_t*, complex_t*);

void conjq(const quaternion_t*, quaternion_t*);

void normc(const complex_t*, complex_t*);

void normq(const quaternion_t*, quaternion_t*);

double absc(const complex_t*);

double absq(const quaternion_t*);

void invc(const complex_t*, complex_t*);

void invq(const quaternion_t*, quaternion_t*);

double argc(const complex_t*);

void sinc(const complex_t*, complex_t*);

void cosc(const complex_t*, complex_t*);

void tanc(const complex_t*, complex_t*);

void sinhc(const complex_t*, complex_t*);

void coshc(const complex_t*, complex_t*);

void tanhc(const complex_t*, complex_t*);

void asinc(const complex_t*, complex_t*);

void acosc(const complex_t*, complex_t*);

void atanc(const complex_t*, complex_t*);

void asinhc(const complex_t*, complex_t*);

void acoshc(const complex_t*, complex_t*);

void atanhc(const complex_t*, complex_t*);

void sqrtc(const complex_t*, complex_t*);

void sqrtq(const quaternion_t*, quaternion_t*);

void logc(const complex_t*, complex_t*);

void logq(const quaternion_t*, quaternion_t*);

void log10c(const complex_t*, complex_t*);

void log10q(const quaternion_t*, quaternion_t*);

void expc(const complex_t*, complex_t*);

void expq(const quaternion_t*, quaternion_t*);
