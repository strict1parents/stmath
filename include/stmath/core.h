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



static inline int st_max_i(int x, int y)
{
	return (x>y)? x:y;
}

static inline st_real st_max_r(st_real x, st_real y)
{
	return (x>y)? x:y;
}

static inline int st_min_i(int x, int y)
{
	return (x<y)? x:y;
}

static inline st_real st_min_r(st_real x, st_real y)
{
	return (x<y)? x:y;
}

static inline int st_abs_i(int x)
{
	return (x<0)? -x:x;
}

static inline st_real st_abs_r(st_real a) 
{
  return (a<0.0)? -a:a;
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
/*
static inline int st_cpsign_i(int x, int y)
{
	return (y<0)? x*(-1):x;
}
*/
static inline st_real st_cpsign(st_real x, st_real y)
{
	return (y<0.0)? x*(-1.0):x;
}

/*#define st_pow(x,y) _Generic((x), \
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

#define st_is_equal(x,y) _Generic((x), \
      int: st_is_equal_i, \
      st_real: st_is_equal_r, \
      default: st_is_equal_r \
)(x,y)

#define st_is_finite(x) _Generic((x), \
      int: st_is_finite_i, \
      st_real: st_is_finite_r, \
      default: st_is_finite_r \
)(x)

#define st_hypot(x,y) _Generic((x), \
      int: st_hypot_i, \
      st_real: st_hypot_r, \
      default: st_hypot_r, \
)(x,y)*/

#define st_max(x,y) _Generic((x), \
      int: st_max_i, \
      st_real: st_max_r, \
      default: st_max_r \
)(x,y)

#define st_min(x,y) _Generic((x), \
      int: st_min_i, \
      st_real: st_min_r, \
      default: st_min_r \
)(x,y)
/*
#define st_sumarr(x) _Generic((x), \
      int: st_sumarr_i, \
      st_real: st_sumarr_r, \
      default: st_sumarr_r \
)(x)
*/

int                         st_max_i(int x, int y);
st_real                     st_max_r(st_real x, st_real);
int                         st_min_i(int x, int y);
st_real                     st_min_r(st_real x, st_real y);
//st_real                     st_pow_i(int base, int exp);
st_real                     st_pow(st_real base, int exp);
//int                         st_sqrt_i(int x);
st_real                     st_sqrt(st_real x);
st_real                     st_rt(st_real x, int power);
//int                         st_fact_i(uint32_t x);
st_real                     st_fact(st_real x);
void                        st_round(st_real *x);
st_real                     st_exp(int x);
//int                         st_cbrt_i(int x);
st_real                     st_cbrt(st_real x);
st_real                     st_sin(st_real x);
st_real                     st_cos(st_real x);
st_real                     st_tan(st_real x);
st_real                     st_cot(st_real x);
st_real                     st_sec(st_real x);
st_real                     st_csc(st_real x);
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
//void                        st_swap_i(int *x, int *y);
void                        st_swap(st_real *x, st_real *y);
//st_real                     st_derivative_i(int (*func)(int), int x);
st_real                     st_derivative(st_real (*func)(st_real), st_real x);
//bool                        st_is_equal_i(int x, int y);
bool                        st_is_equal(st_real x, st_real y);
//bool                        st_is_finite_i(int x);
bool                        st_is_finite(st_real x);
//st_real                     st_hypot_i(int x, int y);
st_real                     st_hypot(st_real x, st_real y);
//int                         st_sumarr_i(const int  *arr, size_t size);
st_real                     st_sumarr(const st_real *arr, size_t size);
st_real                     st_dist(st_real x1, st_real y1, st_real x2, st_real y2);




#ifdef __cplusplus
}
#endif

#endif 
