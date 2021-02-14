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

void rplusc(double, Complex*, Complex*);

void cplusr(Complex*, double, Complex*);

void cplusc(Complex*, Complex*, Complex*);

void rplusq(double, Quaternion*, Quaternion*);

void qplusr(Quaternion*, double, Quaternion*);

void cplusq(Complex*, Quaternion*, Quaternion*);

void qplusc(Quaternion*, Complex*, Quaternion*);

void qplusq(Quaternion*, Quaternion*, Quaternion*);

void rminusc(double, Complex*, Complex*);

void cminusr(Complex*, double, Complex*);

void cminusc(Complex*, Complex*, Complex*);

void rminusq(double, Quaternion*, Quaternion*);

void qminusr(Quaternion*, double, Quaternion*);

void cminusq(Complex*, Quaternion*, Quaternion*);

void qminusc(Quaternion*, Complex*, Quaternion*);

void qminusq(Quaternion*, Quaternion*, Quaternion*);

void rmultc(double, Complex*, Complex*);

void cmultr(Complex*, double, Complex*);

void cmultc(Complex*, Complex*, Complex*);

void rmultq(double, Quaternion*, Quaternion*);

void qmultr(Quaternion*, double, Quaternion*);

void cmultq(Complex*, Quaternion*, Quaternion*);

void qmultc(Quaternion*, Complex*, Quaternion*);

void qmultq(Quaternion*, Quaternion*, Quaternion*);

void rdivc(double, Complex*, Complex*);

void cdivr(Complex*, double, Complex*);

void cdivc(Complex*, Complex*, Complex*);

void rdivq(double, Quaternion*, Quaternion*);

void qdivr(Quaternion*, double, Quaternion*);

void cdivq(Complex*, Quaternion*, Quaternion*);

void qdivc(Quaternion*, Complex*, Quaternion*);

void qdivq(Quaternion*, Quaternion*, Quaternion*);

void rpowc(double, Complex*, Complex*);

void cpowr(Complex*, double, Complex*);

void cpowc(Complex*, Complex*, Complex*);

void rpowq(double, Quaternion*, Quaternion*);

void qpowr(Quaternion*, double, Quaternion*);

void cpowq(Complex*, Quaternion*, Quaternion*);

void qpowc(Quaternion*, Complex*, Quaternion*);

void qpowq(Quaternion*, Quaternion*, Quaternion*);

int reqc(double, Complex*, double);

int ceqr(Complex*, double, double);

int ceqc(Complex*, Complex*, double);

int reqq(double, Quaternion*, double);

int qeqr(Quaternion*, double, double);

int ceqq(Complex*, Quaternion*, double);

int qeqc(Quaternion*, Complex*, double);

int qeqq(Quaternion*, Quaternion*, double);

void cconj(Complex*, Complex*);

void qconj(Quaternion*, Quaternion*);

void cnorm(Complex*, Complex*);

void qnorm(Quaternion*, Quaternion*);

void cabs(Complex*, double*);

void qabs(Quaternion*, double*);

void csin(Complex*, Complex*);

void ccos(Complex*, Complex*);

void ctan(Complex*, Complex*);

void csinh(Complex*, Complex*);

void ccosh(Complex*, Complex*);

void ctanh(Complex*, Complex*);

void casin(Complex*, Complex*);

void cacos(Complex*, Complex*);

void catan(Complex*, Complex*);

void casinh(Complex*, Complex*);

void cacosh(Complex*, Complex*);

void catanh(Complex*, Complex*);

void clog(Complex*, Complex*);

void qlog(Quaternion*, Quaternion*);

void clog10(Complex*, Complex*);

void qlog10(Quaternion*, Quaternion*);

void cexp(Complex*, Complex*);

void qexp(Quaternion*, Quaternion*);
