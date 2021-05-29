#include <stddef.h>
#include <stdbool.h>

typedef struct vector {
    double* position;
    size_t dimensions;
} vector_t;

bool vplusv(const vector_t*, const vector_t*, vector_t*);

bool vminusv(const vector_t*, const vector_t*, vector_t*);

void vmultr(const vector_t*, const double, vector_t*);

void rmultv(const double, const vector_t*, vector_t*);

bool vdotv(const vector_t*, const vector_t*, double*);

bool vcrossv(const vector_t*, const vector_t*, vector_t*);

void vdivr(const vector_t*, const double, vector_t*);

void negv(const vector_t*, vector_t*);

bool veqv(const vector_t*, const vector_t*, const double);

double absv(const vector_t*);

void normv(const vector_t*, vector_t*);

bool anglev(const vector_t*, const vector_t*, double*);

bool vdistv(const vector_t*, const vector_t*, double*);
