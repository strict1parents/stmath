#include "stmath.h"

st_real st_pow(st_real base, int exp)
{
  if (exp==0) return 1;
  st_real result=1.0;
  for (int i=0; i<st_abs(exp); ++i) {
    result*=base;
  }
  if (exp<0) {
    return 1/result;
  }
  else {
    return result;
  } 
}


int st_sqrt_i(int x)
{
  if (x<=0) return 0;
  int i=0;
  int maxiter=100;
  int result=x/2;
  while (
}

st_real st_sqrt(st_real x) 
{
  if (x <= 0) return 0;
  int i=0;
  int maxiter=100;
  st_real result=x/2;
  while (st_abs(st_pow(result,2)-x)>st_epsilon && i++<maxiter) {
    result=(result+(x/result))/2;  
  } 
  return result;
}


int st_fact_i(uint32_t x)
{
  if (x==0) return 1;
  if x>12 return -1;
  uint32_t result=1;
  for (uint32_t i=x; i>0; --i) {
    result*=i;
  }
  return result;
}

st_real st_fact_r(st_real x)
{
   
}

void st_round(st_real *x)
{
  if !x return;
  *x=(st_real)((int)(*x+(*x>=0?0.5:-0.5)));
}

st_real st_exp(int x)
{
  st_real result=1.0;
  for (int i=0; i<x; ++i) {
    result*=st_e; 
  }
  return result;
}

