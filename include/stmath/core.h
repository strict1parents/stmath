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

#define st_pow(x,y) _Generic((x), \
      int: st_pow_i, \
      st_real:  st_pow_r, \
      default: st_pow_r \
)(x,y)  

#define st_sqrt(x) _Generic((x), \
      int: st_sqrt_i, \
      st_real: st_sqrt_r, \
      default: st_sqrt_r \
)(x)

#define st_fact(x) _Generic((x), \
      uint32_t: st_fact_i, \
      st_real: st_fact_r, \
      default: st_fact_r \
)(x)

int                         st_pow_i(int base, int exp);
st_real                     st_pow_r(st_real base, int exp);
int                         st_sqrt_i(int x);
st_real                     st_sqrt_r(st_real x);
int                         st_fact_i(uint32_t x);
st_real                     st_fact_r(st_real x);
void                        st_round(st_real *x);
st_real                     st_exp(int x);


#ifdef __cplusplus
}
#endif

#endif 
