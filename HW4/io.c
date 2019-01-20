/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include <stdio.h>
#include "hw4_io.h"
void write_polynomial4(double a0, double a1, double a2, double a3, double);
void write_polynomial3(double a0, double a1, double a2, double a3);
/*Reads four numbers from the user as the coefficients of a degree-3 polynomial*/
int read_polynomial3(double * a0, double * a1, double * a2, double * a3)
{
	printf("Enter the a3: \n");
	scanf("%lf", a3);
	printf("Enter the a2: \n");
	scanf("%lf", a2);
	printf("Enter the a1: \n");
	scanf("%lf", a1);
	printf("Enter the a0: \n");
	scanf("%lf", a0);
	write_polynomial3(*a0,*a1,*a2,*a3);
	return 0;
}
/*Reads five numbers from the user as the coefficients of a degree-4 polynomial*/
int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4)
{
	printf("Enter the a4: \n");
	scanf("%lf", a4);
	printf("Enter the a3: \n");
	scanf("%lf", a3);
	printf("Enter the a2: \n");
	scanf("%lf", a2);
	printf("Enter the a1: \n");
	scanf("%lf", a1);
	printf("Enter the a0: \n");
	scanf("%lf", a0);
	write_polynomial4(*a0,*a1,*a2,*a3,*a4);
	return 0;
}
/*Write degree-3 polynomial like a3 coefficient of x^3, a2 coefficient of x^2 etc. */
void write_polynomial3(double a0, double a1, double a2, double a3)
{
	char x='x';
	if(a3!=0)
	{
		if(a3==-1)
			printf("-%c^3",x);
		else if(a3==1)
			printf("%c^3",x);
		else 
			printf("%g%c^3",a3,x);
	}
	if(a2!=0)
	{
		if(a2>0)
			printf("+");
		if(a2==-1)
			printf("-%c^2",x);
		if(a2==1)
			printf("%c^2",x);
		else
			printf("%g%c^2",a2,x);
	}
	if(a1!=0)
	{
		if(a1>0 )
			printf("+");
		if(a1==-1)
			printf("-%c",x);
		else if(a1==1)
			printf("%c",x);
		else 
			printf("%g%c",a1,x);
	}
	if(a0!=0 )
	{
		if(a0>0 )
			printf("+");
		if(a0!=0)
			printf("%g",a0);
	}
}
/*Write degree-4 polynomial like a3 coefficient of x^3, a2 coefficient of x^2 etc.*/
void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{	
	char x='x';
	if(a4!=0)
	{
		if(a4==-1)
			printf("-%c^4",x);
		else if(a4==1)
			printf("%c^4",x);
		else
			printf("%g%c^4",a4,x);
	}
	if(a3!=0)
	{
		if(a3>0 )
			printf("+");
		if(a3==-1)
			printf("-%c^3",x);
		else if(a3==1)
			printf("%c^3",x);
		else 
			printf("%g%c^3",a3,x);
	}
	if(a2!=0)
	{
		if(a2>0 )
			printf("+");
		if(a2==-1)
			printf("-%c^2",x);
		else if(a2==1)
			printf("%c^2",x);
		else 
			printf("%g%c^2",a2,x);
	}
	if(a1!=0)
	{
		if(a1>0 )
			printf("+");
		if(a1==-1)
			printf("-%c",x);
		else if(a1==1)
			printf("%c",x);
		else 
			printf("%g%c",a1,x);
	}
	if(a0!=0)
	{
		if(a0>0 )
			printf("+");
		if(a0!=0)
			printf("%g",a0);
	}

}
