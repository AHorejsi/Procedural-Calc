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
} const QuaternionList;

void rplusrl(const double, const RealList*, RealList*);

void rlplusr(const RealList*, const double, RealList*);

void cplusrl(const Complex*, const RealList*, ComplexList*);

void rlplusc(const RealList*, const Complex*, ComplexList*);

void qplusrl(const Quaternion*, const RealList*, QuaternionList*);

void rlplusq(const RealList*, const Quaternion*, QuaternionList*);

void rpluscl(const double, const ComplexList*, ComplexList*);

void clplusr(const ComplexList*, const double, ComplexList*);

void cpluscl(const Complex*, const ComplexList*, ComplexList*);

void clplusc(const ComplexList*, const Complex*, ComplexList*);

void qpluscl(const Quaternion*, const ComplexList*, QuaternionList*);

void clplusq(const ComplexList*, const Quaternion*, QuaternionList*);

void rplusql(const double, const QuaternionList*, QuaternionList*);

void qlplusr(const QuaternionList*, const double, QuaternionList*);

void cplusql(const Complex*, const QuaternionList*, QuaternionList*);

void qlplusc(const QuaternionList*, const Complex*, QuaternionList*);

void qplusql(const Quaternion*, const QuaternionList*, QuaternionList*);

void qlplusq(const QuaternionList*, const Quaternion*, QuaternionList*);

void rlplusrl(const RealList*, const RealList*, RealList*);

void rlpluscl(const RealList*, const ComplexList*, ComplexList*);

void clplusrl(const ComplexList*, const RealList*, ComplexList*);

void clpluscl(const ComplexList*, const ComplexList*, ComplexList*);

void rlplusql(const RealList*, const QuaternionList*, QuaternionList*);

void qlplusrl(const QuaternionList*, const RealList*, QuaternionList*);

void clplusql(const ComplexList*, const QuaternionList*, QuaternionList*);

void qlpluscl(const QuaternionList*, const ComplexList*, QuaternionList*);

void qlplusql(const QuaternionList*, const QuaternionList*, QuaternionList*);

void rminusrl(const double, const RealList*, RealList*);

void rlminusr(const RealList*, const double, RealList*);

void cminusrl(const Complex*, const RealList*, ComplexList*);

void rlminusc(const RealList*, const Complex*, ComplexList*);

void qminusrl(const Quaternion*, const RealList*, QuaternionList*);

void rlminusq(const RealList*, const Quaternion*, QuaternionList*);

void rminuscl(const double, const ComplexList*, ComplexList*);

void clminusr(const ComplexList*, const double, ComplexList*);

void cminuscl(const Complex*, const ComplexList*, ComplexList*);

void clminusc(const ComplexList*, const Complex*, ComplexList*);

void qminuscl(const Quaternion*, const ComplexList*, QuaternionList*);

void clminusq(const ComplexList*, const Quaternion*, QuaternionList*);

void rminusql(const double, const QuaternionList*, QuaternionList*);

void qlminusr(const QuaternionList*, const double, QuaternionList*);

void cminusql(const Complex*, const QuaternionList*, QuaternionList*);

void qlminusc(const QuaternionList*, const Complex*, QuaternionList*);

void qminusql(const Quaternion*, const QuaternionList*, QuaternionList*);

void qlminusq(const QuaternionList*, const Quaternion*, QuaternionList*);

void rlminusrl(const RealList*, const RealList*, RealList*);

void rlminuscl(const RealList*, const ComplexList*, ComplexList*);

void clminusrl(const ComplexList*, const RealList*, ComplexList*);

void clminuscl(const ComplexList*, const ComplexList*, ComplexList*);

void rlminusql(const RealList*, const QuaternionList*, QuaternionList*);

void qlminusrl(const QuaternionList*, const RealList*, QuaternionList*);

void clminusql(const ComplexList*, const QuaternionList*, QuaternionList*);

void qlminuscl(const QuaternionList*, const ComplexList*, QuaternionList*);

void qlminusql(const QuaternionList*, const QuaternionList*, QuaternionList*);

void rmultrl(const double, const RealList*, RealList*);

void rlmultr(const RealList*, const double, RealList*);

void cmultrl(const Complex*, const RealList*, ComplexList*);

void rlmultc(const RealList*, const Complex*, ComplexList*);

void qmultrl(const Quaternion*, const RealList*, QuaternionList*);

void rlmultq(const RealList*, const Quaternion*, QuaternionList*);

void rmultcl(const double, const ComplexList*, ComplexList*);

void clmultr(const ComplexList*, const double, ComplexList*);

void cmultcl(const Complex*, const ComplexList*, ComplexList*);

void clmultc(const ComplexList*, const Complex*, ComplexList*);

void qmultcl(const Quaternion*, const ComplexList*, QuaternionList*);

void clmultq(const ComplexList*, const Quaternion*, QuaternionList*);

void rmultql(const double, const QuaternionList*, QuaternionList*);

void qlmultr(const QuaternionList*, const double, QuaternionList*);

void cmultql(const Complex*, QuaternionList*, QuaternionList*);

void qlmultc(const QuaternionList*, const Complex*, QuaternionList*);

void qmultql(const Quaternion*, const QuaternionList*, QuaternionList*);

void qlmultq(const QuaternionList*, const Quaternion*, QuaternionList*);

void rlmultrl(const RealList*, const RealList*, RealList*);

void rlmultcl(const RealList*, const ComplexList*, ComplexList*);

void clmultrl(const ComplexList*, const RealList*, ComplexList*);

void clmultcl(const ComplexList*, const ComplexList*, ComplexList*);

void rlmultql(const RealList*, const QuaternionList*, QuaternionList*);

void qlmultrl(const QuaternionList*, const RealList*, QuaternionList*);

void clmultql(const ComplexList*, const QuaternionList*, QuaternionList*);

void qlmultcl(const QuaternionList*, const ComplexList*, QuaternionList*);

void qlmultql(const QuaternionList*, const QuaternionList*, QuaternionList*);

void rdivrl(const double, const RealList*, RealList*);

void rldivr(const RealList*, const double, RealList*);

void cdivrl(const Complex*, const RealList*, ComplexList*);

void rldivc(const RealList*, const Complex*, ComplexList*);

void qdivrl(const Quaternion*, const RealList*, QuaternionList*);

void rldivq(const RealList*, const Quaternion*, QuaternionList*);

void rdivcl(const double, const ComplexList*, ComplexList*);

void cldivr(const ComplexList*, const double, ComplexList*);

void cdivcl(const Complex*, const ComplexList*, ComplexList*);

void cldivc(const ComplexList*, const Complex*, ComplexList*);

void qdivcl(const Quaternion*, const ComplexList*, QuaternionList*);

void cldivq(const ComplexList*, const Quaternion*, QuaternionList*);

void rdivql(const double, const QuaternionList*, QuaternionList*);

void qldivr(const QuaternionList*, const double, QuaternionList*);

void cdivql(const Complex*, const QuaternionList*, QuaternionList*);

void qldivc(const QuaternionList*, const Complex*, QuaternionList*);

void qdivql(const Quaternion*, const QuaternionList*, QuaternionList*);

void qldivq(const QuaternionList*, const Quaternion*, QuaternionList*);

void rldivrl(const RealList*, const RealList*, RealList*);

void rldivcl(const RealList*, const ComplexList*, ComplexList*);

void cldivrl(const ComplexList*, const RealList*, ComplexList*);

void cldivcl(const ComplexList*, const ComplexList*, ComplexList*);

void rldivql(const RealList*, const QuaternionList*, QuaternionList*);

void qldivrl(const QuaternionList*, const RealList*, QuaternionList*);

void cldivql(const ComplexList*, const QuaternionList*, QuaternionList*);

void qldivcl(const QuaternionList*, const ComplexList*, QuaternionList*);

void qldivql(const QuaternionList*, const QuaternionList*, QuaternionList*);

void rpowrl(const double, const RealList*, RealList*);

void rlpowr(const RealList*, const double, RealList*);

void cpowrl(const Complex*, const RealList*, ComplexList*);

void rlpowc(const RealList*, const Complex*, ComplexList*);

void qpowrl(const Quaternion*, const RealList*, QuaternionList*);

void rlpowq(const RealList*, const Quaternion*, QuaternionList*);

void rpowcl(const double, const ComplexList*, ComplexList*);

void clpowr(const ComplexList*, const double, ComplexList*);

void cpowcl(const Complex*, const ComplexList*, ComplexList*);

void clpowc(const ComplexList*, const Complex*, ComplexList*);

void qpowcl(const Quaternion*, const ComplexList*, QuaternionList*);

void clpowq(const ComplexList*, const Quaternion*, QuaternionList*);

void rpowql(const double, const QuaternionList*, QuaternionList*);

void qlpowr(const QuaternionList*, const double, QuaternionList*);

void cpowql(const Complex*, const QuaternionList*, QuaternionList*);

void qlpowc(const QuaternionList*, const Complex*, QuaternionList*);

void qpowql(const Quaternion*, const QuaternionList*, QuaternionList*);

void qlpowq(const QuaternionList*, const Quaternion*, QuaternionList*);

void rlpowrl(const RealList*, const RealList*, RealList*);

void rlpowcl(const RealList*, const ComplexList*, ComplexList*);

void clpowrl(const ComplexList*, const RealList*, ComplexList*);

void clpowcl(const ComplexList*, const ComplexList*, ComplexList*);

void rlpowql(const RealList*, const QuaternionList*, QuaternionList*);

void qlpowrl(const QuaternionList*, const RealList*, QuaternionList*);

void clpowql(const ComplexList*, const QuaternionList*, QuaternionList*);

void qlpowcl(const QuaternionList*, const ComplexList*, QuaternionList*);

void qlpowql(const QuaternionList*, const QuaternionList*, QuaternionList*);

void rlneg(const RealList*, RealList*);

void clneg(const ComplexList*, ComplexList*);

void qlneg(const QuaternionList*, QuaternionList*);

int rleqrl(const RealList*, const RealList*, const double);

int rleqcl(const RealList*, const ComplexList*, const double);

int cleqrl(const ComplexList*, const RealList*, const double);

int cleqcl(const ComplexList*, const ComplexList*, const double);

int rleqql(const RealList*, const QuaternionList*, const double);

int qleqrl(const QuaternionList*, const RealList*, const double);

int cleqql(const ComplexList*, const QuaternionList*, const double);

int qleqcl(const QuaternionList*, const ComplexList*, const double);

int qleqql(const QuaternionList*, const QuaternionList*, const double);

void rlmin(const RealList*, double*);

void rlmax(const RealList*, double*);

void rlsum(const RealList*, double*);

void clsum(const ComplexList*, Complex*);

void qlsum(const QuaternionList*, Quaternion*);

void rlmean(const RealList*, double*);

void clmean(const ComplexList*, Complex*);

void qlmean(const QuaternionList*, Quaternion*);

void rlmedian(const RealList*, double*);

void rlmode(const RealList*, double*);

void clmode(const ComplexList*, ComplexList*);

void qlmode(const QuaternionList*, Quaternion*);

void rlmidrange(const RealList*, double*);

void rlrange(const RealList*, double*);

void rlvariance(const RealList*, double*);

void clvariance(const ComplexList*, Complex*);

void qlvariance(const QuaternionList*, Quaternion*);

void rlstddev(const RealList*, double*);

void clstddev(const ComplexList*, Complex*);

void qlstddev(const QuaternionList*, Quaternion*);
