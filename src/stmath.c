#include "stmath.h"


st_real st_pow_i(int base, int exp)
{
  if (exp==0) return 1;
  st_real result = 1;
  for (int i=0; i<st_abs(exp); ++i) {
    result*=base;
  }
  return (exp<0)? 1/result: result;
}


st_real st_pow_r(st_real base, int exp)
{
  if (exp==0) return 1.0; 
  st_real result=1.0;
  for (int i=0; i<st_abs(exp); ++i) {
    result*=base;
  }
  return (exp<0)? 1/result:result; 
}


int st_sqrt_i(int x)
{
  if (x<=0) return 0;
  int i=0;
  int maxiter=100;
  int result=x/2;
  int prev=0;
  while (result!=prev && i++<maxiter) {
    prev=result;
    result=(result+x/result)/2;
  }
  return result;
}

st_real st_sqrt_r(st_real x) 
{
  if (x <= 0) return -1.0;
  int i=0;
  int maxiter=100;
  st_real result=x/2;
  while (st_abs(st_pow(result,2)-x)>st_epsilon && i++<maxiter) {
    result=(result+(x/result))/2;  
  } 
  return result;
}

st_real st_rt(st_real x, int power)
{
  if (x==0) return 0.0;
  int negative = x<0.0;
  negative? x*(-1): x=x; 
  int i=0;
  int maxiter=100;
  st_real result=x/power;
  if (st_abs(result)<st_epsilon)  result=1.0;
  while (st_abs(st_pow(result,power)-x)>st_epsilon && i++<maxiter) {
    result=(1/power)*((power-1)*result+(x/st_pow(result,power-1))/power;
  }
  if (negative && power%2==1) result*=-1;
  return result;
}

int st_cbrt_i(int x)
{
  if (x==0) return 0;
  int negative = x<0;
  negative? x*(-1): x=x;
  int i=0;
  int maxiter=100;
  int prev=0;
  int result=x/3;
  while (result!=prev && i++<maxiter) {
    prev=result;
    result=(2*result+x/(result*result))/3;
  } 
  return (negative)? result*(-1):result;
}

st_real st_cbrt_r(st_real x) 
{
  if (x==0.0) return 0.0;
  int negative = x<0.0;
  negative? x*(-1): x=x;
  int i=0;
  int maxiter=100;
  st_real result=x/3.0;
  st_real prev=0.0;
  if (st_abs(result)<st_epsilon) result=1.0;
  while (st_abs(result-prev)>st_epsilon && i++<maxiter) {
    prev=result;
    result=(2.0*result+x/(result*result))/3.0;
  }
  return (negative)? result*(-1):result;
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
  if (x<0) return 0.0;
  if (x==0) return 1.0;
  if (x>171.6) return st_inf;
  return st_gamma(x+1.0);
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

st_real st_sin(st_real x)
{
  while (x>st_pi) x-= st_twoPI;
  while (x<-st_pi) x+= st_twoPI;
  st_real temp=x;
  st_real result=0;
  int sign = 1;
  for (int i=1; i<13; i+=2) {
    temp*=x*x/((i-1)*i);
    result+=sign*temp;   
    sign*=-1;
  }
  return result;
}

st_real st_cos(st_real x)
{
  while (x>st_pi) x-= st_twoPI;
  while (x<-st_pi) x+= st_twoPI;
  st_real temp=1.0;
  st_real result=1.0;
  int sign = 1;
  for (int i=2; i<12; i+=2) {
    temp*=x*x/((i-1)*i);
    result+=sign*temp;
    sign*=-1;   
  }
  return result;
}

st_real st_tan(st_real x)
{
  while (x>st_pi) x-=st_twoPI;
  while (x<-st_pi) x+=st_twoPI;
  const st_real coeffs[]= {
    1.0,
    1.0/3.0,
    2.0/15.0,
    17.0/315.0,
    62.0/2835.0
  };
  st_real result=0.0;
  st_real x_pow=x;
  for (int i=0; i<5; ++i) {
    result+=coeffs[i]*x_pow;
    x_pow*=x*x;
  }
  return result;

}

st_real st_cot(st_real x)
{
  st_real t = st_tan(x);
  if (st_abs(t)<st_epsilon) return st_inf; 
  return 1.0/t;
}

int st_cpsign_i(int x, int y)
{
  return (y<0)? x*(-1): x;
}

st_real st_cpsign_r(st_real x, st_real y)
{
  return (y<0.0)? x*(-1.0):x;
}

st_real st_gamma(st_real x)
{
  if (x<=0.0) return 0.0;
  if (x>171.6) return st_inf;
  
  static const st_real p[] = {
    676.5203681218851,
    -1259.1392167224028,
    771.32342877765313,
    -176.61502916214059,
    12.507343278686905,
    -0.13857109526572012,
    9.9843695780195716e-6,
    1.5056327351493116e-7
  };
  
  const int g =7;
  st_real a = 0.99999999999980993;
  for (int i=0; i<8; ++i) {
    a+=p[i]/(x+i);
  }
  st_real t=x+g+0.5;
  return st_sqrt(st_twoPI) * st_pow(t,x+0.5) * st_exp(-t) *a;

}

st_real st_degrees(st_real x)
{
  return x*(180.0/st_pi);
}

st_real st_radians(st_real x)
{
  return x*(st_pi/180.0);
}

st_real st_log2(st_real x)
{
  return st_ln(x)/st_ln2;  
}

st_real st_ln(st_real x)
{
  if (x<=0.0) return -1.0;
  if (x==1.0) return 0.0;
  if (x==st_e) return 1.0;
  int k=0;
  while (x>2.0) {
    x/=2.0;
    k++;
  }
  while (x<0.5) {
    x*=2.0;
    k--;
  }
  st_real t=(x-1)/(x+1);
  st_real result=0.0;
  st_real t2=t*t;
  for (int i=1; i<30; i+=2) {
    result+=t/n;
    t*=t2; 
  } 
  result*=2;
  result+=k*st_ln2;
  return result;
}
