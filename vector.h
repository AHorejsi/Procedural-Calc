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

void rvplusrv(RealVector*, RealVector*, RealVector*);

void rvpluscv(RealVector*, ComplexVector*, ComplexVector*);

void cvplusrv(ComplexVector*, RealVector*, ComplexVector*);

void cvpluscv(ComplexVector*, ComplexVector*, ComplexVector*);

void rvplusqv(RealVector*, QuaternionVector*, QuaternionVector*);

void qvplusrv(QuaternionVector*, RealVector*, QuaternionVector*);

void cvplusqv(ComplexVector*, QuaternionVector*, QuaternionVector*);

void qvpluscv(QuaternionVector*, ComplexVector*, QuaternionVector*);

void qvplusqv(QuaternionVector*, QuaternionVector*, QuaternionVector*);

void rvminusrv(RealVector*, RealVector*, RealVector*);

void rvminuscv(RealVector*, ComplexVector*, ComplexVector*);

void cvminusrv(ComplexVector*, RealVector*, ComplexVector*);

void cvminuscv(ComplexVector*, ComplexVector*, ComplexVector*);

void rvminusqv(RealVector*, QuaternionVector*, QuaternionVector*);

void qvminusrv(QuaternionVector*, RealVector*, QuaternionVector*);

void cvminusqv(ComplexVector*, QuaternionVector*, QuaternionVector*);

void qvminuscv(QuaternionVector*, ComplexVector*, QuaternionVector*);

void qvminusqv(QuaternionVector*, QuaternionVector*, QuaternionVector*);

void rmultrv(double, RealVector*, RealVector*);

void rvmultr(RealVector*, double, RealVector*);

void cmultrv(Complex*, RealVector*, ComplexVector*);

void rvmultc(RealVector*, Complex*, ComplexVector*);

void qmultrv(Quaternion*, RealVector*, QuaternionVector*);

void rvmultq(RealVector*, Quaternion*, QuaternionVector*);

void rmultcv(double, ComplexVector*, ComplexVector*);

void cvmultr(ComplexVector*, double, ComplexVector*);

void cmultcv(Complex*, ComplexVector*, ComplexVector*);

void cvmultc(ComplexVector*, Complex*, ComplexVector*);

void qmultcv(Quaternion*, ComplexVector*, QuaternionVector*);

void cvmultq(ComplexVector*, Quaternion*, QuaternionVector*);

void rmultqv(double, QuaternionVector*, QuaternionVector*);

void qvmultr(QuaternionVector*, double, QuaternionVector*);

void cmultqv(Complex*, QuaternionVector*, QuaternionVector*);

void qvmultc(QuaternionVector*, Complex*, QuaternionVector*);

void qmultqv(Quaternion*, QuaternionVector*, QuaternionVector*);

void qvmultq(QuaternionVector*, Quaternion*, QuaternionVector*);

void rvdotrv(RealVector*, RealVector*, double*);

void rvdotcv(RealVector*, ComplexVector*, Complex*);

void cvdotrv(ComplexVector*, RealVector*, Complex*);

void cvdotcv(ComplexVector*, ComplexVector*, Complex*);

void rvdotqv(RealVector*, QuaternionVector*, Quaternion*);

void qvdotrv(QuaternionVector*, RealVector*, Quaternion*);

void cvdotqv(ComplexVector*, QuaternionVector*, Quaternion*);

void qvdotcv(QuaternionVector*, ComplexVector*, Quaternion*);

void qvdotqv(QuaternionVector*, QuaternionVector*, Quaternion*);

void rvcrossrv(RealVector*, RealVector*, RealVector*);

void rvcrosscv(RealVector*, ComplexVector*, ComplexVector*);

void cvcrossrv(ComplexVector*, RealVector*, ComplexVector*);

void cvcrosscv(ComplexVector*, ComplexVector*, ComplexVector*);

void rvcrossqv(RealVector*, QuaternionVector*, QuaternionVector*);

void qvcrossrv(QuaternionVector*, RealVector*, QuaternionVector*);

void cvcrossqv(ComplexVector*, QuaternionVector*, QuaternionVector*);

void qvcrosscv(QuaternionVector*, ComplexVector*, QuaternionVector*);

void qvcrossqv(QuaternionVector*, QuaternionVector*, QuaternionVector*);

void rvdivr(RealVector*, double, RealVector*);

void rvdivc(RealVector*, Complex*, ComplexVector*);

void rvdivq(RealVector*, Quaternion*, QuaternionVector*);

void cvdivr(ComplexVector*, double, ComplexVector*);

void cvdivc(ComplexVector*, Complex*, ComplexVector*);

void cvdivq(ComplexVector*, Quaternion*, QuaternionVector*);

void qvdivr(QuaternionVector*, double, QuaternionVector*);

void qvdivc(QuaternionVector*, Complex*, QuaternionVector*);

void qvdivq(QuaternionVector*, Quaternion*, QuaternionVector*);

int rveqrv(RealVector*, RealVector*, double);

int rveqcv(RealVector*, ComplexVector*, double);

int cveqrv(ComplexVector*, RealVector*, double);

int cveqcv(ComplexVector*, ComplexVector*, double);

int rveqqv(RealVector*, QuaternionVector*, double);

int qveqrv(QuaternionVector*, RealVector*, double);

int cveqqv(ComplexVector*, QuaternionVector*, double);

int qveqcv(QuaternionVector*, ComplexVector*, double);

int qveqqv(QuaternionVector*, QuaternionVector*, double);

void rvmagn(RealVector*, double*);

void cvmagn(ComplexVector*, Complex*);

void qvmagn(QuaternionVector*, Quaternion*);

void rvnorm(RealVector*, RealVector*);

void cvnorm(ComplexVector*, ComplexVector*);

void qvnorm(QuaternionVector*, QuaternionVector*);

void rvangle(RealVector*, double*);

void cvangle(ComplexVector*, Complex*);

void rvdistrv(RealVector*, RealVector*, double*);

void rvdistcv(RealVector*, ComplexVector*, Complex*);

void cvdistrv(ComplexVector*, RealVector*, Complex*);

void cvdistcv(ComplexVector*, ComplexVector*, Complex*);

void rvdistqv(RealVector*, QuaternionVector*, Quaternion*);

void qvdistrv(QuaternionVector*, RealVector*, Quaternion*);

void cvdistqv(ComplexVector*, QuaternionVector*, Quaternion*);

void qvdistcv(QuaternionVector*, ComplexVector*, Quaternion*);

void qvdistqv(QuaternionVector*, QuaternionVector*, Quaternion*);
