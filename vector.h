#include <stddef.h>
#include <stdbool.h>

typedef struct vector {
    double* position;
    size_t dimensions;
} Vector;

bool vplusv(const Vector*, const Vector*, Vector*);

bool vminusv(const Vector*, const Vector*, Vector*);

void vmultr(const Vector*, const double, Vector*);

void rmultv(const double, const Vector*, Vector*);

bool vdotv(const Vector*, const Vector*, double*);

bool vcrossv(const Vector*, const Vector*, Vector*);

void vdivr(const Vector*, const double, Vector*);

void negv(const Vector*, Vector*);

bool veqv(const Vector*, const Vector*, const double);

double absv(const Vector*);

void normv(const Vector*, Vector*);

bool angle(const Vector*, const Vector*, double*);

bool dist(const Vector*, const Vector*, double*);
