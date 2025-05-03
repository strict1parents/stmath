#ifndef STMATH_ALG_H
#define STMATH_ALG_h

#include "consts.h"


#ifdef __cplusplus 
	extern "C" {
#endif

typedef struct st_complex { 
	st_real real;
	st_real img;	
} st_complex; 


void							st_add_comp(struct st_complex *A, const struct st_complex *B);
void							st_mult_comp(struct st_complex *A, const struct st_complex *B);


#ifdef __cplusplus
}
#endif

#endif

