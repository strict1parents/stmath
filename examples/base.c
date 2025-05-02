#include <stdio.h>
//#define ST_MATH_USE_FLOAT
#include "stmath.h" 




int main() 
{
//			Example of st_max
	st_real maximum = st_max(5.0,1.0);
	printf("The maximum value is %.2lf\n", maximum);
//			Example of st_min
	st_real minimum = st_min(-1.0,7.0);
	printf("The minimum value is %.2lf\n", minimum);
//			Example of st_abs
	st_real value = -1.25;
	st_real absolute = st_abs(value);
	printf("The absolute value is %.2lf\n", absolute);		
//			Example of st_sign
	st_real negativenumber=-1.0;
	st_real positivenumber=1.0;
	st_real zeroo=0.0;
	printf("Signs of: neg: %lf; pos: %lf; zero: %lf\n", negativenumber, positivenumber, zeroo);
//			Example of st_is_inf
	printf("Use of st_is_inf on actual infinity: %b and also on random number: %b\n", st_is_inf(st_inf), st_is_inf(5));
//			Example of st_is_nan
	printf("Use of st_is_nan on actual not a number: %b and also on random number: %b\n", st_is_nan(st_nan), st_is_nan(5));
//			Example of st_is_zero
	printf("Use of st_is_zero: %i\n", st_is_zero(0.0));
//			Example of st_cpsign
	printf("Use of st_cpsign:\n");
	st_real a = 5.0;
	st_real b = -1.0;
	printf("The old value of a: %lf\nThe new value of a after copy: %lf\n",a,st_cpsign(&a,b));
//			Example of st_is_equal
	printf("Use of st_is_equal: %d\n", st_is_equal(5.0,5.0));
//			Example of st_is_finite
	printf("Use of st_is_finite: %d\n", st_is_finite(st_inf));
//			Example of st_add_comp
	st_complex A1;
	st_complex B1;
	A1.real=5;
	A1.img=1;
	B1.real=10;
	B1.img=1;
	st_add_comp(&A1,&B1);
	printf("The real part after: %lf\n and imaganary part after: %lf\n",A1.real, A1.img);
	return 0;
}
