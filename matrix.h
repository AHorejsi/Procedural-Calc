#include <stddef.h>
#include "imaginary.h"

typedef struct real_matrix_t {
    double** table;
    size_t rows;
    size_t cols;
} RealMatrix;

typedef struct complex_matrix_t {
    Complex** table;
    size_t rows;
    size_t cols;
} ComplexMatrix;

typedef struct quaternion_matrix_t {
    Quaternion** table;
    size_t rows;
    size_t cols;
} QuaternionMatrix;

void rmplusrm(const RealMatrix*, const RealMatrix*, RealMatrix*);

void rmpluscm(const RealMatrix*, const ComplexMatrix*, RealMatrix*);

void cmplusrm(const ComplexMatrix*, const RealMatrix*, ComplexMatrix*);

void cmpluscm(const ComplexMatrix*, const ComplexMatrix*, ComplexMatrix*);

void rmplusqm(const RealMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void qmplusrm(const QuaternionMatrix*, const RealMatrix*, QuaternionMatrix*);

void cmplusqm(const ComplexMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void qmpluscm(const QuaternionMatrix*, const ComplexMatrix*, QuaternionMatrix*);

void qmplusqm(const QuaternionMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void rmminusrm(const RealMatrix*, const RealMatrix*, RealMatrix*);

void rmminuscm(const RealMatrix*, const ComplexMatrix*, RealMatrix*);

void cmminusrm(const ComplexMatrix*, const RealMatrix*, ComplexMatrix*);

void cmminuscm(const ComplexMatrix*, const ComplexMatrix*, ComplexMatrix*);

void rmminusqm(const RealMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void qmminusrm(const QuaternionMatrix*, const RealMatrix*, QuaternionMatrix*);

void cmminusqm(const ComplexMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void qmminuscm(const QuaternionMatrix*, const ComplexMatrix*, QuaternionMatrix*);

void qmminusqm(const QuaternionMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void rmultrm(const double, const RealMatrix*, RealMatrix*);

void rmmultr(const RealMatrix*, const double, RealMatrix*);

void cmultrm(const Complex*, const RealMatrix*, ComplexMatrix*);

void rmmultc(const RealMatrix*, const Complex*, RealMatrix*);

void qmultrm(const Quaternion*, const RealMatrix*, QuaternionMatrix*);

void rmmultq(const RealMatrix*, const Quaternion*, QuaternionMatrix*);

void rmultcm(const double, const ComplexMatrix*, ComplexMatrix*);

void cmmultr(const ComplexMatrix*, const double, ComplexMatrix*);

void cmultcm(const Complex*, const ComplexMatrix*, ComplexMatrix*);

void cmmultc(const ComplexMatrix*, const Complex*, RealMatrix*);

void qmultcm(const Quaternion*, const ComplexMatrix*, QuaternionMatrix*);

void cmmultq(const ComplexMatrix*, const Quaternion*, QuaternionMatrix*);

void rmultqm(const double, const QuaternionMatrix*, QuaternionMatrix*);

void qmmultr(const QuaternionMatrix*, const double, QuaternionMatrix*);

void cmultqm(const Complex*, const QuaternionMatrix*, QuaternionMatrix*);

void qmmultc(const QuaternionMatrix*, const Complex*, QuaternionMatrix*);

void qmultqm(const Quaternion*, const QuaternionMatrix*, QuaternionMatrix*);

void qmmultq(const QuaternionMatrix*, const Quaternion*, QuaternionMatrix*);

void rmmultrm(const RealMatrix*, const RealMatrix*, RealMatrix*);

void rmmultcm(const RealMatrix*, const ComplexMatrix*, RealMatrix*);

void cmmultrm(const ComplexMatrix*, const RealMatrix*, ComplexMatrix*);

void cmmultcm(const ComplexMatrix*, const ComplexMatrix*, ComplexMatrix*);

void rmmultqm(const RealMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void qmmultrm(const QuaternionMatrix*, const RealMatrix*, QuaternionMatrix*);

void cmmultqm(const ComplexMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void qmmultcm(const QuaternionMatrix*, const ComplexMatrix*, QuaternionMatrix*);

void qmmultqm(const QuaternionMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void rmscalerm(const RealMatrix*, const RealMatrix*, RealMatrix*);

void rmscalecm(const RealMatrix*, const ComplexMatrix*, RealMatrix*);

void cmscalerm(const ComplexMatrix*, const RealMatrix*, ComplexMatrix*);

void cmscalecm(const ComplexMatrix*, const ComplexMatrix*, ComplexMatrix*);

void rmscaleqm(const RealMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void qmscalerm(const QuaternionMatrix*, const RealMatrix*, QuaternionMatrix*);

void cmscaleqm(const ComplexMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void qmscalecm(const QuaternionMatrix*, const ComplexMatrix*, QuaternionMatrix*);

void qmscaleqm(const QuaternionMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void rmdivr(const RealMatrix*, const double, RealMatrix*);

void rmdivc(const RealMatrix*, const Complex*, ComplexMatrix*);

void rmdivq(const RealMatrix*, const Quaternion*, QuaternionMatrix*);

void cmdivr(const ComplexMatrix*, const double, ComplexMatrix*);

void cmdivc(const ComplexMatrix*, const Complex*, ComplexMatrix*);

void cmdivq(const RealMatrix*, const Quaternion*, QuaternionMatrix*);

void qmdivr(const QuaternionMatrix*, const double, QuaternionMatrix*);

void qmdivc(const QuaternionMatrix*, const Complex*, QuaternionMatrix*);

void qmdivq(const QuaternionMatrix*, const Quaternion*, QuaternionMatrix*);

void rmdivrm(const RealMatrix*, const RealMatrix*, RealMatrix*);

void rmdivcm(const RealMatrix*, const ComplexMatrix*, RealMatrix*);

void cmdivrm(const ComplexMatrix*, const RealMatrix*, ComplexMatrix*);

void cmdivcm(const ComplexMatrix*, const ComplexMatrix*, ComplexMatrix*);

void rmdivqm(const RealMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void qmdivrm(const QuaternionMatrix*, const RealMatrix*, QuaternionMatrix*);

void cmdivqm(const ComplexMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void qmdivcm(const QuaternionMatrix*, const ComplexMatrix*, QuaternionMatrix*);

void qmdivqm(const QuaternionMatrix*, const QuaternionMatrix*, QuaternionMatrix*);

void rmneg(const RealMatrix*, RealMatrix*);

void cmneg(const ComplexMatrix*, ComplexMatrix*);

void qmneg(const QuaternionMatrix*, QuaternionMatrix*);

int rmeqrm(const RealMatrix*, const RealMatrix*, const double);

int rmeqcm(const RealMatrix*, const ComplexMatrix*, const double);

int cmeqrm(const ComplexMatrix*, const RealMatrix*, const double);

int cmeqcm(const ComplexMatrix*, const ComplexMatrix*, const double);

int rmeqqm(const RealMatrix*, const QuaternionMatrix*, const double);

int qmeqrm(const QuaternionMatrix*, const RealMatrix*, const double);

int cmeqqm(const ComplexMatrix*, const QuaternionMatrix*, const double);

int qmeqcm(const QuaternionMatrix*, const ComplexMatrix*, const double);

int qmeqqm(const QuaternionMatrix*, const QuaternionMatrix*, const double);

void cmconj(const ComplexMatrix*, ComplexMatrix*);

void qmconj(const QuaternionMatrix*, QuaternionMatrix*);

void rmdet(const RealMatrix*, double*);

void cmdet(const ComplexMatrix*, Complex*);

void qmdet(const QuaternionMatrix*, Quaternion*);

void rminv(const RealMatrix*, RealMatrix*);

void cminv(const ComplexMatrix*, ComplexMatrix*);

void qminv(const QuaternionMatrix*, QuaternionMatrix*);

void rmtranspose(const RealMatrix*, RealMatrix*);

void cmtranspose(const ComplexMatrix*, ComplexMatrix*);

void qmtranspose(const QuaternionMatrix*, QuaternionMatrix*);
