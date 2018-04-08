
#include <stdio.h>
#include <math.h>
#include "complex.h"


/*   A to F */
void read_comp (complex *cmp , double x , double y)
{
    cmp->real = x;
    cmp->imagin = y;
}


void print_comp(complex cmp)
{
    printf("Complex Number:");
    printf("%.2f + %.2fi\n", cmp.real , cmp.imagin);
}

void add_comp(complex a , complex b)
{
	complex c;

	c.real =  (a.real + b.real);
	c.imagin = (a.imagin + b.imagin);
	print_comp(c);
}

void sub_comp(complex a , complex b)
{
	complex c;

		c.real =  (a.real - b.real);
		c.imagin = (a.imagin - b.imagin);
		print_comp(c);

}


void mult_comp_real(complex a , double b)
{
	complex c;

	c.real = (a.real * b);
	c.imagin = (a.imagin * b);
	print_comp(c);

}

void mult_comp_img(complex a , double b)
{
    complex c;
    c.real = a.imagin * b * -1;
    c.imagin = a.real * b;
    print_comp(c);
}


void mult_comp_comp(complex a , complex b)
{
    complex c;

    c.real = (a.real * b.real) - (a.imagin * b.imagin);
    c.imagin = (a.real * b.imagin) + (a.imagin * b.real);
    print_comp(c);
}

void abs_comp(complex a)
{
    complex c;

    c.real  =  sqrt(pow(a.real,2) + pow( a.imagin , 2));
    print_comp(c);
}