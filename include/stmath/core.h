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


st_real st_pow(st_real base, int exp);
st_real st_sqrt(st_real x);
st_real st_abs(st_real a);
st_real st_min(st_real a, st_real b);
st_real st_max(st_real a, st_real b);


#ifdef __cplusplus
}
#endif

#endif 
