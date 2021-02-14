#include <stddef.h>
#include "imaginary.h"

typedef struct real_vector_t {
    double* values;
    size_t dimensions;
} RealVector;

typedef struct complex_vector_t {
    Complex* values;
    size_t dimensions;
} ComplexVector;

typedef struct quaternion_vector_t {
    Quaternion* values;
    size_t dimensions;
} QuaternionVector;

void rvplusrv(const RealVector*, const RealVector*, RealVector*);

void rvpluscv(const RealVector*, const ComplexVector*, ComplexVector*);

void cvplusrv(const ComplexVector*, const RealVector*, ComplexVector*);

void cvpluscv(const ComplexVector*, const ComplexVector*, ComplexVector*);

void rvplusqv(const RealVector*, const QuaternionVector*, QuaternionVector*);

void qvplusrv(const QuaternionVector*, const RealVector*, QuaternionVector*);

void cvplusqv(const ComplexVector*, const QuaternionVector*, QuaternionVector*);

void qvpluscv(const QuaternionVector*, const ComplexVector*, QuaternionVector*);

void qvplusqv(const QuaternionVector*, const QuaternionVector*, QuaternionVector*);

void rvminusrv(const RealVector*, const RealVector*, RealVector*);

void rvminuscv(const RealVector*, const ComplexVector*, ComplexVector*);

void cvminusrv(const ComplexVector*, const RealVector*, ComplexVector*);

void cvminuscv(const ComplexVector*, const ComplexVector*, ComplexVector*);

void rvminusqv(const RealVector*, const QuaternionVector*, QuaternionVector*);

void qvminusrv(const QuaternionVector*, const RealVector*, QuaternionVector*);

void cvminusqv(const ComplexVector*, const QuaternionVector*, QuaternionVector*);

void qvminuscv(const QuaternionVector*, const ComplexVector*, QuaternionVector*);

void qvminusqv(const QuaternionVector*, const QuaternionVector*, QuaternionVector*);

void rmultrv(const double, const RealVector*, RealVector*);

void rvmultr(const RealVector*, const double, RealVector*);

void cmultrv(const Complex*, const RealVector*, ComplexVector*);

void rvmultc(const RealVector*, const Complex*, ComplexVector*);

void qmultrv(const Quaternion*, const RealVector*, QuaternionVector*);

void rvmultq(const RealVector*, const Quaternion*, QuaternionVector*);

void rmultcv(const double, const ComplexVector*, ComplexVector*);

void cvmultr(const ComplexVector*, const double, ComplexVector*);

void cmultcv(const Complex*, const ComplexVector*, ComplexVector*);

void cvmultc(const ComplexVector*, const Complex*, ComplexVector*);

void qmultcv(const Quaternion*, const ComplexVector*, QuaternionVector*);

void cvmultq(const ComplexVector*, const Quaternion*, QuaternionVector*);

void rmultqv(const double, const QuaternionVector*, QuaternionVector*);

void qvmultr(const QuaternionVector*, const double, QuaternionVector*);

void cmultqv(const Complex*, const QuaternionVector*, QuaternionVector*);

void qvmultc(const QuaternionVector*, const Complex*, QuaternionVector*);

void qmultqv(const Quaternion*, const QuaternionVector*, QuaternionVector*);

void qvmultq(const QuaternionVector*, const Quaternion*, QuaternionVector*);

void rvdotrv(const RealVector*, const RealVector*, double*);

void rvdotcv(const RealVector*, const ComplexVector*, Complex*);

void cvdotrv(const ComplexVector*, const RealVector*, Complex*);

void cvdotcv(const ComplexVector*, const ComplexVector*, Complex*);

void rvdotqv(const RealVector*, const QuaternionVector*, Quaternion*);

void qvdotrv(const QuaternionVector*, const RealVector*, Quaternion*);

void cvdotqv(const ComplexVector*, const QuaternionVector*, Quaternion*);

void qvdotcv(const QuaternionVector*, const ComplexVector*, Quaternion*);

void qvdotqv(const QuaternionVector*, const QuaternionVector*, Quaternion*);

void rvcrossrv(const RealVector*, const RealVector*, RealVector*);

void rvcrosscv(const RealVector*, const ComplexVector*, ComplexVector*);

void cvcrossrv(const ComplexVector*, const RealVector*, ComplexVector*);

void cvcrosscv(const ComplexVector*, const ComplexVector*, ComplexVector*);

void rvcrossqv(const RealVector*, const QuaternionVector*, QuaternionVector*);

void qvcrossrv(const QuaternionVector*, const RealVector*, QuaternionVector*);

void cvcrossqv(const ComplexVector*, QuaternionVector*, QuaternionVector*);

void qvcrosscv(const QuaternionVector*, const ComplexVector*, QuaternionVector*);

void qvcrossqv(const QuaternionVector*, const QuaternionVector*, QuaternionVector*);

void rvdivr(const RealVector*, const double, RealVector*);

void rvdivc(const RealVector*, const Complex*, ComplexVector*);

void rvdivq(const RealVector*, const Quaternion*, QuaternionVector*);

void cvdivr(const ComplexVector*, const double, ComplexVector*);

void cvdivc(const ComplexVector*, const Complex*, ComplexVector*);

void cvdivq(const ComplexVector*, const Quaternion*, QuaternionVector*);

void qvdivr(const QuaternionVector*, const double, QuaternionVector*);

void qvdivc(const QuaternionVector*, const Complex*, QuaternionVector*);

void qvdivq(const QuaternionVector*, const Quaternion*, QuaternionVector*);

void rvneg(const RealVector*, RealVector*);

void cvneg(const ComplexVector*, ComplexVector*);

void qvneg(const QuaternionVector*, QuaternionVector*);

int rveqrv(const RealVector*, const RealVector*, const double);

int rveqcv(const RealVector*, const ComplexVector*, const double);

int cveqrv(const ComplexVector*, const RealVector*, const double);

int cveqcv(const ComplexVector*, const ComplexVector*, const double);

int rveqqv(const RealVector*, const QuaternionVector*, const double);

int qveqrv(const QuaternionVector*, const RealVector*, const double);

int cveqqv(const ComplexVector*, const QuaternionVector*, const double);

int qveqcv(const QuaternionVector*, const ComplexVector*, const double);

int qveqqv(const QuaternionVector*, const QuaternionVector*, const double);

void rvmagn(const RealVector*, double*);

void cvmagn(const ComplexVector*, Complex*);

void qvmagn(const QuaternionVector*, Quaternion*);

void rvnorm(const RealVector*, RealVector*);

void cvnorm(const ComplexVector*, ComplexVector*);

void qvnorm(const QuaternionVector*, QuaternionVector*);

void rvangle(const RealVector*, double*);

void cvangle(const ComplexVector*, Complex*);

void rvdistrv(const RealVector*, RealVector*, double*);

void rvdistcv(const RealVector*, const ComplexVector*, Complex*);

void cvdistrv(const ComplexVector*, const RealVector*, Complex*);

void cvdistcv(const ComplexVector*, const ComplexVector*, Complex*);

void rvdistqv(const RealVector*, const QuaternionVector*, Quaternion*);

void qvdistrv(const QuaternionVector*, const RealVector*, Quaternion*);

void cvdistqv(const ComplexVector*, const QuaternionVector*, Quaternion*);

void qvdistcv(const QuaternionVector*, const ComplexVector*, Quaternion*);

void qvdistqv(const QuaternionVector*, const QuaternionVector*, Quaternion*);
