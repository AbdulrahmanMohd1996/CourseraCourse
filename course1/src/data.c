/**
 * @file data.c
 * @brief Abstraction of data monubilation function defeniitions
 *
 * This source file provides an abstraction of
 * monubilation to data via function calls.
 *
 * @author Abdulrahman Mohamed
 * @date march 1 2020
 *
 */

#include "data.h"
#include "memory.h"

#define TRUE 1
#define FALSE 0


unsigned char my_itoa(int data, unsigned char * ptr, unsigned int base)
{
	unsigned char dataCntr=0;
	unsigned char dataIsNeg=FALSE;

	if(0==data)
	{
		*ptr='0';
		dataCntr++;

	}

	if(data<0 && base==10)
	{
		data*=-1;
		dataIsNeg=TRUE;
	}

	while(data!=0 && dataCntr<16)
	{
		if(data%base>9)
		{
			*(ptr+dataCntr)='A'+((data%base)-10);
		}
		else
		{
			*(ptr+dataCntr)='0'+data%base;
		}


		dataCntr++;
		data/=base;
	}

	if(dataIsNeg)
	{
		*(ptr+dataCntr)='-';
		dataCntr++;
	}

	my_reverse(ptr,dataCntr);

	*(ptr+dataCntr)='\0';
	dataCntr++;

	return dataCntr;
}



int my_atoi(char * ptr, unsigned char digits, unsigned int base)
{
	unsigned char dataCntr=0;
	unsigned char dataIsNeg=FALSE;
	int numb=0;
	unsigned long my_base=1;

	if(*(ptr)=='-' && 10 == base)
	{
		dataIsNeg=TRUE;
	}

	while(dataCntr < digits)
	{
		if(*(ptr+digits-dataCntr-1) >= '0' && *(ptr+digits-dataCntr-1) <= '9' )
		{

			numb+=(*(ptr+digits-dataCntr-1)-'0')*my_base;

		}
		else if((*(ptr+digits-dataCntr-1) >= 'A' && *(ptr+digits-dataCntr-1) <= 'Z') || (*(ptr+digits-dataCntr-1) >= 'a' && *(ptr+digits-dataCntr-1) <= 'z'))
		{
			numb+=((*(ptr+digits-dataCntr-1)-'A')+10)*my_base;

		}
		else
		{
			numb+=0;
		}

		dataCntr++;
		my_base*=base;
	}
	if(dataIsNeg)
	{
		numb*=-1;
	}
	return numb;
}
