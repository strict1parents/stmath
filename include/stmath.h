#ifndef STMATH_H
#define STMATH_H


//--------


#ifdef __cplusplus
  extern "C" {
#endif
//---
#ifdef ST_MATH_USE_FLOAT
  typedef float st_real;
  #define st_e            2.7182818f
  #define st_pi           3.1415926f
  #define st_epsilon      1e-5f
#else 
  typedef double st_real;
  #define st_e            2.718281828459045
  #define st_pi           3.141592653589793
  #define st_epsilon      1e-10
#endif


//--------


st_real st_pow(st_real base, int exp);
st_real st_sqrt(st_real x);
st_real st_abs(st_real a);
int st_min(int a, int b);
int st_max(int a, int b);


#ifdef __cplusplus
}
#endif

#endif
