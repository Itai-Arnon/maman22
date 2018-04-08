#ifndef  COMPLEX_H
#define  COMPLEX_H




typedef struct complex{

char   name;
    double real;
    double imagin;

    }complex;

typedef struct ORDER_ARR{
    int func_no;
    int var1;
    int var2;
    double num1;
    double num2;
    }order;

/* places x and y in the real and imaginary part of cmp, respectively */
/* The only function that changes a variable*/
/* input: the new complex number|x:the real part |y:the imaginary part */
void read_comp(complex *cmp , double x , double y);

/*prints out cmplx number in a specific format
 * input: cmp - receives cmplx number  and prints real & imaginary
 * imaginary gets an i*/
void print_comp(complex cmp);

/*adds two cmplx numbers by adding the two real and the two imaginary parts seperately
 * input a: 1st cmplx b: 2nd cmplx */
void add_comp(complex a , complex b);

/*subtracts two cmplx numbers by subtracting the two real and the two imaginary parts seperately
 * input a: 1st cmplx b: 2nd cmplx */
void sub_comp(complex a , complex b);
/* multiplies one cmplx numbers by a scalar number. The multiplication once again is seperated
  input a: 1st cmplx  b: scalar */
void mult_comp_real(complex a , double b);
/* multiplies one cmplx numbers by an entirely imaginary number. The multiplication creates an i^2 multiplication.
  input a: 1st cmplx  b: imaginary only */
void mult_comp_img(complex a , double b);
/* multiplies one cmplx numbers by an complx  number. The multiplication creates diversity in the outcome
  input a: 1st cmplx  b: cmplx number */
void mult_comp_comp(complex a , complex b);
/*calculates the absolute value of a complex number, equaling the square root of the two parts imaginary and real
 * input  a: a complex number */
void abs_comp(complex a);



#endif

