typedef struct complex_t {
    double real;
    double imag0;
} Complex;

typedef struct quaternion_t {
    double real;
    double imag0;
    double imag1;
    double imag2;
} Quaternion;

extern const Complex IMAG0;
extern const Quaternion IMAG1;
extern const Quaternion IMAG2;

void rplusc(const double, const Complex*, Complex*);

void cplusr(const Complex*, const double, Complex*);

void cplusc(const Complex*, const Complex*, Complex*);

void rplusq(const double, const Quaternion*, Quaternion*);

void qplusr(const Quaternion*, const double, Quaternion*);

void cplusq(const Complex*, const Quaternion*, Quaternion*);

void qplusc(const Quaternion*, const Complex*, Quaternion*);

void qplusq(const Quaternion*, const Quaternion*, Quaternion*);

void rminusc(const double, const Complex*, Complex*);

void cminusr(const Complex*, const double, Complex*);

void cminusc(const Complex*, const Complex*, Complex*);

void rminusq(const double, const Quaternion*, Quaternion*);

void qminusr(const Quaternion*, const double, Quaternion*);

void cminusq(const Complex*, const Quaternion*, Quaternion*);

void qminusc(const Quaternion*, const Complex*, Quaternion*);

void qminusq(const Quaternion*, const Quaternion*, Quaternion*);

void rmultc(const double, const Complex*, Complex*);

void cmultr(const Complex*, const double, Complex*);

void cmultc(const Complex*, const Complex*, Complex*);

void rmultq(const double, const Quaternion*, Quaternion*);

void qmultr(const Quaternion*, const double, Quaternion*);

void cmultq(const Complex*, const Quaternion*, Quaternion*);

void qmultc(const Quaternion*, const Complex*, Quaternion*);

void qmultq(const Quaternion*, const Quaternion*, Quaternion*);

void rdivc(const double, const Complex*, Complex*);

void cdivr(const Complex*, const double, Complex*);

void cdivc(const Complex*, const Complex*, Complex*);

void rdivq(const double, const Quaternion*, Quaternion*);

void qdivr(const Quaternion*, const double, Quaternion*);

void cdivq(const Complex*, const Quaternion*, Quaternion*);

void qdivc(const Quaternion*, const Complex*, Quaternion*);

void qdivq(const Quaternion*, const Quaternion*, Quaternion*);

void rpowc(const double, const Complex*, Complex*);

void cpowr(const Complex*, const double, Complex*);

void cpowc(const Complex*, const Complex*, Complex*);

void rpowq(const double, const Quaternion*, Quaternion*);

void qpowr(const Quaternion*, const double, Quaternion*);

void cpowq(const Complex*, const Quaternion*, Quaternion*);

void qpowc(const Quaternion*, const Complex*, Quaternion*);

void qpowq(const Quaternion*, const Quaternion*, Quaternion*);

void cneg(const Complex*, Complex*);

void qneg(const Quaternion*, Quaternion*);

int reqc(const double, const Complex*, const double);

int ceqr(const Complex*, const double, const double);

int ceqc(const Complex*, const Complex*, const double);

int reqq(const double, const Quaternion*, const double);

int qeqr(const Quaternion*, const double, const double);

int ceqq(const Complex*, const Quaternion*, const double);

int qeqc(const Quaternion*, const Complex*, const double);

int qeqq(const Quaternion*, const Quaternion*, const double);

void cconj(const Complex*, Complex*);

void qconj(const Quaternion*, Quaternion*);

void cnorm(const Complex*, Complex*);

void qnorm(const Quaternion*, Quaternion*);

void cabs(const Complex*, double*);

void qabs(const Quaternion*, double*);

void csin(const Complex*, Complex*);

void ccos(const Complex*, Complex*);

void ctan(const Complex*, Complex*);

void csinh(const Complex*, Complex*);

void ccosh(const Complex*, Complex*);

void ctanh(const Complex*, Complex*);

void casin(const Complex*, Complex*);

void cacos(const Complex*, Complex*);

void catan(const Complex*, Complex*);

void casinh(const Complex*, Complex*);

void cacosh(const Complex*, Complex*);

void catanh(const Complex*, Complex*);

void clog(const Complex*, Complex*);

void qlog(const Quaternion*, Quaternion*);

void clog10(const Complex*, Complex*);

void qlog10(const Quaternion*, Quaternion*);

void cexp(const Complex*, Complex*);

void qexp(const Quaternion*, Quaternion*);
