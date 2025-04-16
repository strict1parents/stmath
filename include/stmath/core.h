#ifndef STMATH_CORE_H
#define STMATH_CORE_H


#include "consts.h"


#ifdef __cplusplus
  extern "C" {
#endif

#ifdef ST_MATH_USE_FLOAT 
  typedef float st_real;
#else
  typedef double st_real;
#endif

typedef unsigned int uint32_t


static inline st_real st_abs(st_real a) 
{
  return (a<0)? -a:a;
}

static inline st_real st_min(st_real a, st_real b)
{
  return (a<b)? a:b;
}

static inline st_real st_max(st_real a, st_real b)
{
  return (a>b)? a:b;
}

static inline st_real st_sign(st_real x)
{
  return (x<0) -1:(x==0)? 0:1;
}

static inline int st_mod(int a, int b)
{
  return (b==0)? 0:(a%b);
}


st_real                     st_pow(st_real base, int exp);
st_real                     st_sqrt(st_real x);
int                         st_fact(uint32_t x);
void                        st_round(st_real *x);


#ifdef __cplusplus
}
#endif

#endif 
