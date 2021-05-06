#include <stddef.h>
#include <stdbool.h>

typedef struct number_list {
    double* values;
    size_t size;
} NumberList;

void rplusl(const double, const NumberList*, NumberList*);

void lplusr(const NumberList*, const double, NumberList*);

bool lplusl(const NumberList*, const NumberList*, NumberList*);

void rminusl(const double, const NumberList*, NumberList*);

void lminusr(const NumberList*, const double, NumberList*);

bool lminusl(const NumberList*, const NumberList*, NumberList*);

void rmultl(const double, const NumberList*, NumberList*);

void lmultr(const NumberList*, const double, NumberList*);

bool lmultl(const NumberList*, const NumberList*, NumberList*);

void rdivl(const double, const NumberList*, NumberList*);

void ldivr(const NumberList*, const double, NumberList*);

bool ldivl(const NumberList*, const NumberList*, NumberList*);

void negl(const NumberList*, NumberList*);

bool leql(const NumberList*, const NumberList*, const double);

double minl(const NumberList*);

double maxl(const NumberList*);

double suml(const NumberList*);

double prodl(const NumberList*);

double meanl(const NumberList*);

double medianl(const NumberList*);

void model(const NumberList*, const double, NumberList*);

double rangel(const NumberList*);

double midrangel(const NumberList*);

double variancel(const NumberList*);

double stddevl(const NumberList*);
