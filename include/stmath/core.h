#ifndef STMATH_CORE_H
#define STMATH_CORE_H

#ifdef __cplusplus
  extern "C" {
#endif

#ifdef ST_MATH_USE_FLOAT 
  typedef float st_real;
#else
  typedef double st_real;
#endif

typedef unsigned int uint32_t


st_real      st_pow(st_real base, int exp);
st_real      st_sqrt(st_real x);
st_real      st_abs(st_real a);
st_real      st_min(st_real a, st_real b);
st_real      st_max(st_real a, st_real b);
int          st_fact(uint32_t x);
int          st_sign(st_real x);
void         st_round(st_real *x);



#ifdef __cplusplus
}
#endif

#endif 
