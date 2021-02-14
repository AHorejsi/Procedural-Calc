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

void rmplusrm(RealMatrix*, RealMatrix*, RealMatrix*);

void rmpluscm(RealMatrix*, ComplexMatrix*, RealMatrix*);

void cmplusrm(ComplexMatrix*, RealMatrix*, ComplexMatrix*);

void cmpluscm(ComplexMatrix*, ComplexMatrix*, ComplexMatrix*);

void rmplusqm(RealMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void qmplusrm(QuaternionMatrix*, RealMatrix*, QuaternionMatrix*);

void cmplusqm(ComplexMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void qmpluscm(QuaternionMatrix*, ComplexMatrix*, QuaternionMatrix*);

void qmplusqm(QuaternionMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void rmminusrm(RealMatrix*, RealMatrix*, RealMatrix*);

void rmminuscm(RealMatrix*, ComplexMatrix*, RealMatrix*);

void cmminusrm(ComplexMatrix*, RealMatrix*, ComplexMatrix*);

void cmminuscm(ComplexMatrix*, ComplexMatrix*, ComplexMatrix*);

void rmminusqm(RealMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void qmminusrm(QuaternionMatrix*, RealMatrix*, QuaternionMatrix*);

void cmminusqm(ComplexMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void qmminuscm(QuaternionMatrix*, ComplexMatrix*, QuaternionMatrix*);

void qmminusqm(QuaternionMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void rmultrm(double, RealMatrix*, RealMatrix*);

void rmmultr(RealMatrix*, double, RealMatrix*);

void cmultrm(Complex*, RealMatrix*, ComplexMatrix*);

void rmmultc(RealMatrix*, Complex*, RealMatrix*);

void qmultrm(Quaternion*, RealMatrix*, QuaternionMatrix*);

void rmmultq(RealMatrix*, Quaternion*, QuaternionMatrix*);

void rmultcm(double, ComplexMatrix*, ComplexMatrix*);

void cmmultr(ComplexMatrix*, double, ComplexMatrix*);

void cmultcm(Complex*, ComplexMatrix*, ComplexMatrix*);

void cmmultc(ComplexMatrix*, Complex*, RealMatrix*);

void qmultcm(Quaternion*, ComplexMatrix*, QuaternionMatrix*);

void cmmultq(ComplexMatrix*, Quaternion*, QuaternionMatrix*);

void rmultqm(double, QuaternionMatrix*, QuaternionMatrix*);

void qmmultr(QuaternionMatrix*, double, QuaternionMatrix*);

void cmultqm(Complex*, QuaternionMatrix*, QuaternionMatrix*);

void qmmultc(QuaternionMatrix*, Complex*, QuaternionMatrix*);

void qmultqm(Quaternion*, QuaternionMatrix*, QuaternionMatrix*);

void qmmultq(QuaternionMatrix*, Quaternion*, QuaternionMatrix*);

void rmmultrm(RealMatrix*, RealMatrix*, RealMatrix*);

void rmmultcm(RealMatrix*, ComplexMatrix*, RealMatrix*);

void cmmultrm(ComplexMatrix*, RealMatrix*, ComplexMatrix*);

void cmmultcm(ComplexMatrix*, ComplexMatrix*, ComplexMatrix*);

void rmmultqm(RealMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void qmmultrm(QuaternionMatrix*, RealMatrix*, QuaternionMatrix*);

void cmmultqm(ComplexMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void qmmultcm(QuaternionMatrix*, ComplexMatrix*, QuaternionMatrix*);

void qmmultqm(QuaternionMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void rmscalerm(RealMatrix*, RealMatrix*, RealMatrix*);

void rmscalecm(RealMatrix*, ComplexMatrix*, RealMatrix*);

void cmscalerm(ComplexMatrix*, RealMatrix*, ComplexMatrix*);

void cmscalecm(ComplexMatrix*, ComplexMatrix*, ComplexMatrix*);

void rmscaleqm(RealMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void qmscalerm(QuaternionMatrix*, RealMatrix*, QuaternionMatrix*);

void cmscaleqm(ComplexMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void qmscalecm(QuaternionMatrix*, ComplexMatrix*, QuaternionMatrix*);

void qmscaleqm(QuaternionMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void rmdivr(RealMatrix*, double, RealMatrix*);

void rmdivc(RealMatrix*, Complex*, ComplexMatrix*);

void rmdivq(RealMatrix*, Quaternion*, QuaternionMatrix*);

void cmdivr(ComplexMatrix*, double, ComplexMatrix*);

void cmdivc(ComplexMatrix*, Complex*, ComplexMatrix*);

void cmdivq(RealMatrix*, Quaternion*, QuaternionMatrix*);

void qmdivr(QuaternionMatrix*, double, QuaternionMatrix*);

void qmdivc(QuaternionMatrix*, Complex*, QuaternionMatrix*);

void qmdivq(QuaternionMatrix*, Quaternion*, QuaternionMatrix*);

void rmdivrm(RealMatrix*, RealMatrix*, RealMatrix*);

void rmdivcm(RealMatrix*, ComplexMatrix*, RealMatrix*);

void cmdivrm(ComplexMatrix*, RealMatrix*, ComplexMatrix*);

void cmdivcm(ComplexMatrix*, ComplexMatrix*, ComplexMatrix*);

void rmdivqm(RealMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void qmdivrm(QuaternionMatrix*, RealMatrix*, QuaternionMatrix*);

void cmdivqm(ComplexMatrix*, QuaternionMatrix*, QuaternionMatrix*);

void qmdivcm(QuaternionMatrix*, ComplexMatrix*, QuaternionMatrix*);

void qmdivqm(QuaternionMatrix*, QuaternionMatrix*, QuaternionMatrix*);

int rmeqrm(RealMatrix*, RealMatrix*, double);

int rmeqcm(RealMatrix*, ComplexMatrix*, double);

int cmeqrm(ComplexMatrix*, RealMatrix*, double);

int cmeqcm(ComplexMatrix*, ComplexMatrix*, double);

int rmeqqm(RealMatrix*, QuaternionMatrix*, double);

int qmeqrm(QuaternionMatrix*, RealMatrix*, double);

int cmeqqm(ComplexMatrix*, QuaternionMatrix*, double);

int qmeqcm(QuaternionMatrix*, ComplexMatrix*, double);

int qmeqqm(QuaternionMatrix*, QuaternionMatrix*);

void cmconj(ComplexMatrix*, ComplexMatrix*);

void qmconj(QuaternionMatrix*, QuaternionMatrix*);

void rmdet(RealMatrix*, double*);

void cmdet(ComplexMatrix*, Complex*);

void qmdet(QuaternionMatrix*, Quaternion*);

void rminv(RealMatrix*, RealMatrix*);

void cminv(ComplexMatrix*, ComplexMatrix*);

void qminv(QuaternionMatrix*, QuaternionMatrix*);

void rmtranspose(RealMatrix*, RealMatrix*);

void cmtranspose(ComplexMatrix*, ComplexMatrix*);

void qmtranspose(QuaternionMatrix*, QuaternionMatrix*);
