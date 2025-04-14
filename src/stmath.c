#include "stmath.h"

/*st_real st_pow(st_real base, int exp)
{
  st_real result=1.0;
  for (int i=0; i<exp; ++i) {
    result*=base; 
  }    
  return result;
   
}
*/
st_real st_sqrt(st_real x) 
{
  st_real result=x/2;
  while (st_abs(st_pow(result,2)-x)>st_epsilon) {
    result=(result+(x/result))/2;  
  } 
  return result;
}

st_real st_abs(st_real a) 
{
  return (a<0)? -a:a;
}
