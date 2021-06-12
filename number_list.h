#include <stddef.h>
#include <stdbool.h>

typedef struct real_list {
    double* values;
    size_t size;
} real_list_t;

void rplusrl(const double, const real_list_t*, real_list_t*);

void rlplusr(const real_list_t*, const double, real_list_t*);

bool rlplusrl(const real_list_t*, const real_list_t*, real_list_t*);

void rminusrl(const double, const real_list_t*, real_list_t*);

void rlminusr(const real_list_t*, const double, real_list_t*);

bool rlminusrl(const real_list_t*, const real_list_t*, real_list_t*);

void rmultrl(const double, const real_list_t*, real_list_t*);

void rlmultr(const real_list_t*, const double, real_list_t*);

bool rlmultrl(const real_list_t*, const real_list_t*, real_list_t*);

void rdivrl(const double, const real_list_t*, real_list_t*);

void rldivr(const real_list_t*, const double, real_list_t*);

bool rldivrl(const real_list_t*, const real_list_t*, real_list_t*);

void negrl(const real_list_t*, real_list_t*);

bool rleqrl(const real_list_t*, const real_list_t*, const double);

double minrl(const real_list_t*);

double maxrl(const real_list_t*);

double sumrl(const real_list_t*);

double prodrl(const real_list_t*);

double meanrl(const real_list_t*);

double medianrl(const real_list_t*);

void moderl(const real_list_t*, const double, real_list_t*);

double rangel(const real_list_t*);

double midrangel(const real_list_t*);

double variancel(const real_list_t*);

double stddevl(const real_list_t*);

bool subl(const real_list_t*, const size_t, const size_t, real_list_t*);
