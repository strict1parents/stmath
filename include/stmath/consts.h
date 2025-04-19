#ifndef ST_MATH_CONSTS_H
#define ST_MATH_CONSTS_H


#ifdef ST_MATH_USE_FLOAT
  #define st_e          2.7182818f
  #define st_pi         3.1415926f
  #define st_epsilon    1e-5f
  #define st_twoPI      2.0*st_pi
#else 
  #define st_e          2.718281828459045
  #define st_pi         3.141592653589793
  #define st_epsilon    1e-10
  #define st_twoPI      2.0*st_pi
#endif

#ifndef st_inf
  #define st_inf (1.0/0.0)
#endif

#endif
