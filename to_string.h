#include "imaginary.h"
#include "vector.h"
#include "number_list.h"
#include "matrix.h"

void to_string_c(const Complex*, char*);

void to_string_q(const Quaternion*, char*);

void to_string_rv(const RealVector*, char*);

void to_string_cv(const ComplexVector*, char*);

void to_string_qv(const QuaternionVector*, char*);

void to_string_rl(const RealList*, char*);

void to_string_cl(const ComplexList*, char*);

void to_string_ql(const QuaternionList*, char*);

void to_string_rm(const RealMatrix*, char*);

void to_string_cm(const ComplexMatrix*, char*);

void to_string_qm(const QuaternionMatrix*, char*);
