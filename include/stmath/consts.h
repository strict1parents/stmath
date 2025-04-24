#ifndef ST_MATH_CONSTS_H
#define ST_MATH_CONSTS_H


#ifdef ST_MATH_USE_FLOAT
  #define st_e          2.7182818f
  #define st_pi         3.1415926f
  #define st_epsilon    1e-5f
  #define st_twoPI      2.0*st_pi
  #define st_ln2        0.6931472f
  #define st_ln10       2.30258509f
  #define st_nan        (0.0f/0.0f)
  #define G 5.0f
  #define G_COEFFS 6
  static const st_real g_coeffs[G_COEFFS] = {
          1.0000000f,
          76.1800917f,
          -86.5053203f,
          24.0140982f,
          -1.2317396f,
          0.0012086f
        };
#else 
  #define st_e          2.718281828459045
  #define st_pi         3.141592653589793
  #define st_epsilon    1e-10
  #define st_twoPI      2.0*st_pi
  #define st_ln2        0.6931471805599453
  #define st_ln10       2.30258509299404568402
  #define st_nan        (0.0/0.0)
  #define G 7.0
  #define G_COEFFS 9
  static const st_real g_coeffs[G_COEFFS] = {
          0.99999999999980993,
          676.5203681218851,
          -1259.1392167224028,
          771.32342877765313,
          -176.61502916214059,
          12.507343278686905,
          -0.13857109526572012,
          9.9843695780195716e-6,
          1.5056327351493116e-7
        };
#endif

#ifndef st_inf
  #define st_inf (1.0/0.0)
#endif

#endif
