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

static inline bool st_is_inf(st_real x) 
{
  return x==st_inf || x==-(st_inf);
}

static inline bool st_is_nan(st_real x)
{
  return x!=x;
}

static inline bool st_even(int x)
{
  return (x%2==0);
}

static inline bool st_odd(int x)
{
  return (x%2==1);
}

static inline bool st_is_zero(st_real x)
{
  return x<st_epsilon;
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

#define st_cbrt(x) _Generic((x), \
      int: st_cbrt_i, \
      st_real: st_cbrt_r, \
      default: st_cbrt_r \
)(x)

#define st_cpsign(x,y) _Generic((x), \
      int: st_cpsign_i, \
      st_real: st_cpsign_r, \
      default: st_cpsign_r \
)(x,y)

#define st_swap(x,y) _Generic((x), \
      int: st_swap_i, \
      st_real: st_swap_r, \
      default: st_swap_r \
)(x,y)

#define st_derivative(x,y) _Generic((x), \
      int: st_derivative_i, \
      st_real: st_derivative_r, \
      default: st_derivative_r \
)(x,y)


st_real                     st_pow_i(int base, int exp);
st_real                     st_pow_r(st_real base, int exp);
int                         st_sqrt_i(int x);
st_real                     st_sqrt_r(st_real x);
st_real                     st_rt(st_real x, int power);
int                         st_fact_i(uint32_t x);
st_real                     st_fact_r(st_real x);
void                        st_round(st_real *x);
st_real                     st_exp(int x);
int                         st_cbrt_i(int x);
st_real                     st_cbrt_r(st_real x);
st_real                     st_sin(st_real x);
st_real                     st_cos(st_real x);
st_real                     st_tan(st_real x);
st_real                     st_cot(st_real x);
st_real                     st_sec(st_real x);
st_real                     st_csc(st_real x);
int                         st_cpsign_i(int x, int y);
st_real                     st_cpsign_r(st_real x, st_real y);
st_real                     st_gamma(st_real x);
st_real                     st_degrees(st_real x);
st_real                     st_radians(st_real x);
st_real                     st_log2(st_real x);
st_real                     st_ln(st_real x);
st_real                     st_log10(st_real x);
st_real                     st_log(int base, st_real x);
st_real                     st_lgamma(st_real x);
st_real                     st_clamp(st_real x, st_real min, st_real max);
st_real                     st_frac(st_real x);
void                        st_swap_i(int *x, int *y);
void                        st_swap_r(st_real *x, st_real *y);
st_real                     st_derivative_i(int (*func)(int), int x);
st_real                     st_derivative_r(st_real (*func)(st_real), st_real x);



#ifdef __cplusplus
}
#endif

#endif 
