#include "stmath.h"



st_real st_pow(st_real base, int exp)
{
  if (exp==0) return 1.0; 
  st_real result=1.0;
  for (int i=0; i<st_abs(exp); ++i) {
    result*=base;
  }
  return (exp<0)? 1/result:result; 
}

st_real st_sqrt(st_real x) 
{
  if (x <= 0) return st_nan;
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
  if (x==0) return st_nan;
  int negative = x<0.0;
	if (negative) {
		x*=(-1);
	}
  int i=0;
  int maxiter=100;
  st_real result=x/power;
  if (st_abs(result)<st_epsilon)  result=1.0;
  while (st_abs(st_pow(result,power)-x)>st_epsilon && i++<maxiter) {
    result=((power-1)*result+x/st_pow(result,power-1))/power;
  }
  if (negative && power%2==1) result*=-1;
  return result;
}

st_real st_cbrt(st_real x) 
{
  if (x==0.0) return st_nan;
  int negative = x<0.0;
	if (negative) {
		x*=(-1);
	}
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

st_real st_fact(st_real x)
{
  if (x<0) return st_nan;
  if (x==0) return 1.0;
  if (x>171.6) return st_inf;
  return st_gamma(x+1.0);
}

void st_round(st_real *x)
{
  if (!x) return;
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

st_real st_sec(st_real x)
{
  if(st_abs(st_cos(x))<st_epsilon) return st_nan;
  return 1/st_cos(x);
}

st_real st_csc(st_real x)
{
  if (st_abs(st_sin(x))<st_epsilon) return st_nan;
  return 1/st_sin(x);
}

st_real st_gamma(st_real x)
{
  if (x<=0.0) return st_nan;
  if (x>171.6) return st_inf;
  const int g =7;
  st_real a = 0.99999999999980993;
  for (int i=0; i<G_COEFFS; ++i) {
    a+=g_coeffs[i]/(x+i);
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
  if (x<=0.0) return st_nan;
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
    result+=t/i;
    t*=t2; 
  } 
  result*=2;
  result+=k*st_ln2;
  return result;
}

st_real st_log10(st_real x)
{
  return st_ln(x)/st_ln10;  
}

st_real st_log(int base, st_real x)
{
  return st_ln(x)/st_ln((st_real)base);
}

st_real st_lgamma(st_real x)
{
  if (x<=0.0) return st_nan;
  x-=1.0;
  st_real a = g_coeffs[0];
  for (int i=0; i<G_COEFFS; ++i) {
    a+=g_coeffs[i]/(x+i);
  }
  st_real t=x+G+0.5;
  return st_ln(st_sqrt(st_twoPI))+(x+0.5)*st_ln(t)-t+st_ln(a);
}

st_real st_clamp(st_real x, st_real min, st_real max)
{
  if (x<min) return min;
  if (x>max) return max;
  return x;
}

st_real st_frac(st_real x)
{
  return x-(st_real)((int)(x));
}

void st_swap(st_real *x, st_real *y)
{
  st_real temp;
  temp=*x;
  *x=*y;
  *y=temp; 
}

st_real st_derivative(st_real (*func)(st_real), st_real x)
{
  if (!func) return st_nan;
  st_real h = st_sqrt(st_epsilon);
  return ((*func)(x+h)-(*func)(x-h))/(2*h);
}

st_real st_hypot(st_real x, st_real y)
{
  st_real max=st_max(x,y);
  st_real min=st_min(x,y);
  if (max==0.0) return 0.0;
  return max*st_sqrt(1.0+(min/max)*(min/max));
}

st_real st_sumarr(const st_real *arr, size_t size)
{
  st_real result=0;
  for (int i=0; i<size; ++i) {
    result+=*arr;
    arr++;
  }
  return result;
}

st_real st_dist(st_real x1, st_real y1, st_real x2, st_real y2)
{
  return st_sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void st_add_comp(struct st_complex *A, const struct st_complex *B)
{
	A->real=A->real+B->real;
	A->img=A->img+B->img;
}

void st_mult_comp(struct st_complex *A, const struct st_complex *B)
{
	st_real a = A->real;
	st_real b = A->img;
	A->real=(a*B->real)-(b*B->img);
	A->img=(a*B->img)+(b*B->real);
}

st_real st_abs_comp(const struct st_complex *A) 
{
	if (!A) return 0;
	return st_sqrt((A->real)*(A->real)+(A->img)*(A->img));
}
