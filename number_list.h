#include <stddef.h>
#include <stdbool.h>

typedef struct number_list {
    double* values;
    size_t size;
} number_list_t;

void rplusl(const double, const number_list_t*, number_list_t*);

void lplusr(const number_list_t*, const double, number_list_t*);

bool lplusl(const number_list_t*, const number_list_t*, number_list_t*);

void rminusl(const double, const number_list_t*, number_list_t*);

void lminusr(const number_list_t*, const double, number_list_t*);

bool lminusl(const number_list_t*, const number_list_t*, number_list_t*);

void rmultl(const double, const number_list_t*, number_list_t*);

void lmultr(const number_list_t*, const double, number_list_t*);

bool lmultl(const number_list_t*, const number_list_t*, number_list_t*);

void rdivl(const double, const number_list_t*, number_list_t*);

void ldivr(const number_list_t*, const double, number_list_t*);

bool ldivl(const number_list_t*, const number_list_t*, number_list_t*);

void negl(const number_list_t*, number_list_t*);

bool leql(const number_list_t*, const number_list_t*, const double);

double minl(const number_list_t*);

double maxl(const number_list_t*);

double suml(const number_list_t*);

double prodl(const number_list_t*);

double meanl(const number_list_t*);

double medianl(const number_list_t*);

void model(const number_list_t*, const double, number_list_t*);

double rangel(const number_list_t*);

double midrangel(const number_list_t*);

double variancel(const number_list_t*);

double stddevl(const number_list_t*);

bool subl(const number_list_t*, const size_t, const size_t, number_list_t*);
