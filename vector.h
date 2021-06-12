#include <stddef.h>
#include <stdbool.h>
#include "imaginary.h"

typedef struct real_vector {
    double* position;
    size_t dimensions;
} real_vector_t;

typedef struct complex_vector {
    complex_t* position;
    size_t dimensions;
} complex_vector_t;

bool rvplusrv(const real_vector_t*, const real_vector_t*, real_vector_t*);

bool rvpluscv(const real_vector_t*, const complex_vector_t*, complex_vector_t*);

bool cvplusrv(const complex_vector_t*, const real_vector_t*, complex_vector_t*);

bool cvpluscv(const complex_vector_t*, const complex_vector_t*, complex_vector_t*);

bool rvminusrv(const real_vector_t*, const real_vector_t*, real_vector_t*);

bool rvminuscv(const real_vector_t*, const complex_vector_t*, complex_vector_t*);

bool cvminusrv(const complex_vector_t*, const real_vector_t*, complex_vector_t*);

bool cvminuscv(const complex_vector_t*, const complex_vector_t*, complex_vector_t*);

void rmultrv(const double, const real_vector_t*, real_vector_t*);

void rvmultr(const real_vector_t*, const double, real_vector_t*);

void cmultrv(const complex_t*, const real_vector_t*, complex_vector_t*);

void rvmultc(const real_vector_t*, const complex_t*, complex_vector_t*);

void rmultcv(const double, const complex_vector_t*, complex_vector_t*);

void cvmultr(const complex_vector_t*, const double, complex_vector_t*);

void cmultcv(const complex_t*, const complex_vector_t*, complex_vector_t*);

void cvmultc(const complex_vector_t*, const complex_t*, complex_vector_t*);

bool rvdotrv(const real_vector_t*, const real_vector_t*, double*);

bool rvdotcv(const real_vector_t*, const complex_vector_t*, complex_t*);

bool cvdotrv(const complex_vector_t*, const real_vector_t*, complex_t*);

bool cvdotcv(const complex_vector_t*, const complex_vector_t*, complex_t*);

bool rvcrossrv(const real_vector_t*, const real_vector_t*, real_vector_t*);

bool rvcrosscv(const real_vector_t*, const complex_vector_t*, complex_vector_t*);

bool cvcrossrv(const complex_vector_t*, const real_vector_t*, complex_vector_t*);

bool cvcrosscv(const complex_vector_t*, const complex_vector_t*, complex_vector_t*);

void rvdivr(const real_vector_t*, const double, real_vector_t*);

void rvdivc(const real_vector_t*, const complex_t*, complex_vector_t*);

void cvdivr(const complex_vector_t*, const double, complex_vector_t*);

void cvdivc(const complex_vector_t*, const complex_t*, complex_vector_t*);

void negrv(const real_vector_t*, real_vector_t*);

void negcv(const complex_vector_t*, complex_vector_t*);

bool rveqrv(const real_vector_t*, const real_vector_t*, const double);

bool rveqcv(const real_vector_t*, const complex_vector_t*, const double);

bool cveqrv(const complex_vector_t*, const real_vector_t*, const double);

bool cveqcv(const complex_vector_t*, const complex_vector_t*, const double);

double absrv(const real_vector_t*);

void abscv(const complex_vector_t*, complex_t*);

void normrv(const real_vector_t*, real_vector_t*);

void normcv(const complex_vector_t*, complex_vector_t*);

bool rvanglerv(const real_vector_t*, const real_vector_t*, double*);

bool rvanglecv(const real_vector_t*, const complex_vector_t*, complex_t*);

bool cvanglerv(const complex_vector_t*, const real_vector_t*, complex_t*);

bool cvanglecv(const complex_vector_t*, const complex_vector_t*, complex_t*);

bool rvdistrv(const real_vector_t*, const real_vector_t*, double*);

bool rvdistcv(const real_vector_t*, const complex_vector_t*, complex_t*);

bool cvdistrv(const complex_vector_t*, const real_vector_t*, complex_t*);

bool cvdistcv(const complex_vector_t*, const complex_vector_t*, complex_t*);
