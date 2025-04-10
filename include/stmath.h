#ifndef STMATH_H
#define STMATH_H


//--------


#ifdef __cplusplus
  extern "C" {
#endif
//---
#ifdef ST_MATH_USE_FLOAT
  typedef float st_real;
#else 
  typedef double st_real;
#endif


//--------


st_real st_pow(st_real base, int exp);
st_real st_sqrt(st_real x);


#ifdef __cplusplus
}
#endif

#endif
