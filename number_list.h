#include <stddef.h>
#include "imaginary.h"

typedef struct real_list_t {
    double* nums;
    size_t size;
} RealList;

typedef struct complex_list_t {
    Complex* nums;
    size_t size;
} ComplexList;

typedef struct quaternion_list_t {
    Quaternion* nums;
    size_t size;
} QuaternionList;

void rplusrl(double, RealList*, RealList*);

void rlplusr(RealList*, double, RealList*);

void cplusrl(Complex*, RealList*, ComplexList*);

void rlplusc(RealList*, Complex*, ComplexList*);

void qplusrl(Quaternion*, RealList*, QuaternionList*);

void rlplusq(RealList*, Quaternion*, QuaternionList*);

void rpluscl(double, ComplexList*, ComplexList*);

void clplusr(ComplexList*, double, ComplexList*);

void cpluscl(Complex*, ComplexList*, ComplexList*);

void clplusc(ComplexList*, Complex*, ComplexList*);

void qpluscl(Quaternion*, ComplexList*, QuaternionList*);

void clplusq(ComplexList*, Quaternion*, QuaternionList*);

void rplusql(double, QuaternionList*, QuaternionList*);

void qlplusr(QuaternionList*, double, QuaternionList*);

void cplusql(Complex*, QuaternionList*, QuaternionList*);

void qlplusc(QuaternionList*, Complex*, QuaternionList*);

void qplusql(Quaternion*, QuaternionList*, QuaternionList*);

void qlplusq(QuaternionList*, Quaternion*, QuaternionList*);

void rlplusrl(RealList*, RealList*, RealList*);

void rlpluscl(RealList*, ComplexList*, ComplexList*);

void clplusrl(ComplexList*, RealList*, ComplexList*);

void clpluscl(ComplexList*, ComplexList*, ComplexList*);

void rlplusql(RealList*, QuaternionList*, QuaternionList*);

void qlplusrl(QuaternionList*, RealList*, QuaternionList*);

void clplusql(ComplexList*, QuaternionList*, QuaternionList*);

void qlpluscl(QuaternionList*, ComplexList*, QuaternionList*);

void qlplusql(QuaternionList*, QuaternionList*, QuaternionList*);

void rminusrl(double, RealList*, RealList*);

void rlminusr(RealList*, double, RealList*);

void cminusrl(Complex*, RealList*, ComplexList*);

void rlminusc(RealList*, Complex*, ComplexList*);

void qminusrl(Quaternion*, RealList*, QuaternionList*);

void rlminusq(RealList*, Quaternion*, QuaternionList*);

void rminuscl(double, ComplexList*, ComplexList*);

void clminusr(ComplexList*, double, ComplexList*);

void cminuscl(Complex*, ComplexList*, ComplexList*);

void clminusc(ComplexList*, Complex*, ComplexList*);

void qminuscl(Quaternion*, ComplexList*, QuaternionList*);

void clminusq(ComplexList*, Quaternion*, QuaternionList*);

void rminusql(double, QuaternionList*, QuaternionList*);

void qlminusr(QuaternionList*, double, QuaternionList*);

void cminusql(Complex*, QuaternionList*, QuaternionList*);

void qlminusc(QuaternionList*, Complex*, QuaternionList*);

void qminusql(Quaternion*, QuaternionList*, QuaternionList*);

void qlminusq(QuaternionList*, Quaternion*, QuaternionList*);

void rlminusrl(RealList*, RealList*, RealList*);

void rlminuscl(RealList*, ComplexList*, ComplexList*);

void clminusrl(ComplexList*, RealList*, ComplexList*);

void clminuscl(ComplexList*, ComplexList*, ComplexList*);

void rlminusql(RealList*, QuaternionList*, QuaternionList*);

void qlminusrl(QuaternionList*, RealList*, QuaternionList*);

void clminusql(ComplexList*, QuaternionList*, QuaternionList*);

void qlminuscl(QuaternionList*, ComplexList*, QuaternionList*);

void qlminusql(QuaternionList*, QuaternionList*, QuaternionList*);

void rmultrl(double, RealList*, RealList*);

void rlmultr(RealList*, double, RealList*);

void cmultrl(Complex*, RealList*, ComplexList*);

void rlmultc(RealList*, Complex*, ComplexList*);

void qmultrl(Quaternion*, RealList*, QuaternionList*);

void rlmultq(RealList*, Quaternion*, QuaternionList*);

void rmultcl(double, ComplexList*, ComplexList*);

void clmultr(ComplexList*, double, ComplexList*);

void cmultcl(Complex*, ComplexList*, ComplexList*);

void clmultc(ComplexList*, Complex*, ComplexList*);

void qmultcl(Quaternion*, ComplexList*, QuaternionList*);

void clmultq(ComplexList*, Quaternion*, QuaternionList*);

void rmultql(double, QuaternionList*, QuaternionList*);

void qlmultr(QuaternionList*, double, QuaternionList*);

void cmultql(Complex*, QuaternionList*, QuaternionList*);

void qlmultc(QuaternionList*, Complex*, QuaternionList*);

void qmultql(Quaternion*, QuaternionList*, QuaternionList*);

void qlmultq(QuaternionList*, Quaternion*, QuaternionList*);

void rlmultrl(RealList*, RealList*, RealList*);

void rlmultcl(RealList*, ComplexList*, ComplexList*);

void clmultrl(ComplexList*, RealList*, ComplexList*);

void clmultcl(ComplexList*, ComplexList*, ComplexList*);

void rlmultql(RealList*, QuaternionList*, QuaternionList*);

void qlmultrl(QuaternionList*, RealList*, QuaternionList*);

void clmultql(ComplexList*, QuaternionList*, QuaternionList*);

void qlmultcl(QuaternionList*, ComplexList*, QuaternionList*);

void qlmultql(QuaternionList*, QuaternionList*, QuaternionList*);

void rdivrl(double, RealList*, RealList*);

void rldivr(RealList*, double, RealList*);

void cdivrl(Complex*, RealList*, ComplexList*);

void rldivc(RealList*, Complex*, ComplexList*);

void qdivrl(Quaternion*, RealList*, QuaternionList*);

void rldivq(RealList*, Quaternion*, QuaternionList*);

void rdivcl(double, ComplexList*, ComplexList*);

void cldivr(ComplexList*, double, ComplexList*);

void cdivcl(Complex*, ComplexList*, ComplexList*);

void cldivc(ComplexList*, Complex*, ComplexList*);

void qdivcl(Quaternion*, ComplexList*, QuaternionList*);

void cldivq(ComplexList*, Quaternion*, QuaternionList*);

void rdivql(double, QuaternionList*, QuaternionList*);

void qldivr(QuaternionList*, double, QuaternionList*);

void cdivql(Complex*, QuaternionList*, QuaternionList*);

void qldivc(QuaternionList*, Complex*, QuaternionList*);

void qdivql(Quaternion*, QuaternionList*, QuaternionList*);

void qldivq(QuaternionList*, Quaternion*, QuaternionList*);

void rldivrl(RealList*, RealList*, RealList*);

void rldivcl(RealList*, ComplexList*, ComplexList*);

void cldivrl(ComplexList*, RealList*, ComplexList*);

void cldivcl(ComplexList*, ComplexList*, ComplexList*);

void rldivql(RealList*, QuaternionList*, QuaternionList*);

void qldivrl(QuaternionList*, RealList*, QuaternionList*);

void cldivql(ComplexList*, QuaternionList*, QuaternionList*);

void qldivcl(QuaternionList*, ComplexList*, QuaternionList*);

void qldivql(QuaternionList*, QuaternionList*, QuaternionList*);

void rpowrl(double, RealList*, RealList*);

void rlpowr(RealList*, double, RealList*);

void cpowrl(Complex*, RealList*, ComplexList*);

void rlpowc(RealList*, Complex*, ComplexList*);

void qpowrl(Quaternion*, RealList*, QuaternionList*);

void rlpowq(RealList*, Quaternion*, QuaternionList*);

void rpowcl(double, ComplexList*, ComplexList*);

void clpowr(ComplexList*, double, ComplexList*);

void cpowcl(Complex*, ComplexList*, ComplexList*);

void clpowc(ComplexList*, Complex*, ComplexList*);

void qpowcl(Quaternion*, ComplexList*, QuaternionList*);

void clpowq(ComplexList*, Quaternion*, QuaternionList*);

void rpowql(double, QuaternionList*, QuaternionList*);

void qlpowr(QuaternionList*, double, QuaternionList*);

void cpowql(Complex*, QuaternionList*, QuaternionList*);

void qlpowc(QuaternionList*, Complex*, QuaternionList*);

void qpowql(Quaternion*, QuaternionList*, QuaternionList*);

void qlpowq(QuaternionList*, Quaternion*, QuaternionList*);

void rlpowrl(RealList*, RealList*, RealList*);

void rlpowcl(RealList*, ComplexList*, ComplexList*);

void clpowrl(ComplexList*, RealList*, ComplexList*);

void clpowcl(ComplexList*, ComplexList*, ComplexList*);

void rlpowql(RealList*, QuaternionList*, QuaternionList*);

void qlpowrl(QuaternionList*, RealList*, QuaternionList*);

void clpowql(ComplexList*, QuaternionList*, QuaternionList*);

void qlpowcl(QuaternionList*, ComplexList*, QuaternionList*);

void qlpowql(QuaternionList*, QuaternionList*, QuaternionList*);

int rleqrl(RealList*, RealList*, double);

int rleqcl(RealList*, ComplexList*, double);

int cleqrl(ComplexList*, RealList*, double);

int cleqcl(ComplexList*, ComplexList*, double);

int rleqql(RealList*, QuaternionList*, double);

int qleqrl(QuaternionList*, RealList*, double);

int cleqql(ComplexList*, QuaternionList*, double);

int qleqcl(QuaternionList*, ComplexList*, double);

int qleqql(QuaternionList*, QuaternionList*, double);

void rlmin(RealList*, double*);

void rlmax(RealList*, double*);

void rlsum(RealList*, double*);

void clsum(ComplexList*, Complex*);

void qlsum(QuaternionList*, Quaternion*);

void rlmean(RealList*, double*);

void clmean(ComplexList*, Complex*);

void qlmean(QuaternionList*, Quaternion*);

void rlmedian(RealList*, double*);

void rlmode(RealList*, double*);

void clmode(ComplexList*, ComplexList*);

void qlmode(QuaternionList*, Quaternion*);

void rlmidrange(RealList*, double*);

void rlrange(RealList*, double*);

void rlvariance(RealList*, double*);

void clvariance(ComplexList*, Complex*);

void qlvariance(QuaternionList*, Quaternion*);

void rlstddev(RealList*, double*);

void clstddev(ComplexList*, Complex*);

void qlstddev(QuaternionList*, Quaternion*);
