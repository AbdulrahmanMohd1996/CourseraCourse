/**
 * @file <stats.c>
 * @brief <Implementation file for my C-programming code>
 *
 * <write a couple of functions that can analyze an array of unsigned char data items and report analytics
 *  on the maximum, minimum, mean, and median of the data set. In addition, you will need to reorder this data set
 *  from large to small. All statistics should be rounded down to the nearest integer. After analysis and sorting is done,
 *  print that data to the screen in nicely formatted presentation.>
 *
 * @author <Abdulrahman Mohamed>
 * @date <3/24/2020 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
	/*need to sort the array first*/
	sort_array( test , SIZE );

  /* Statistics and Printing Functions Go Here */
  print_statistics(test,SIZE);
  return 0;
}

void print_statistics(unsigned char* a_arr, unsigned char a_arr_length )
{
	printf("this array :\n");
	print_array(a_arr,a_arr_length);
	printf("array after sorting:\n");
	print_array(a_arr,a_arr_length);
	printf("and it is statistics :\n");
	printf("the median: %d\n", find_median(a_arr,a_arr_length));
	printf("the mean: %d\n", find_mean(a_arr,a_arr_length ));
	printf("the MAX: %d\n", find_maximum(a_arr,a_arr_length ));
	printf("the MIN: %d\n", find_minimum(a_arr,a_arr_length));
}


void print_array(unsigned char* a_arr, unsigned char a_arr_length )
{
	/*create an iterration local variable*/
	unsigned char i;

	for(i=0;i<a_arr_length;i++)
	{
		/*loop till the array is finished and print it is element*/
		printf("%d ",a_arr[i]);
	}
	printf("\n\n");
}

unsigned char find_median(unsigned char* a_arr, unsigned char a_arr_length )
{
	if( 0 == ( a_arr_length % 2 )) /*if the array is even*/
	{
		/* the median will be the mean of the two middle number in the array*/
		return ( ( ( a_arr[ ( a_arr_length / 2 ) ] ) + ( a_arr[ ( (a_arr_length/2) + 1 ) ] )  ) / 2 ); /* return the median*/
	}
	else /* if odd */
	{
		return a_arr[ ( (a_arr_length/2) + 1 ) ] ; /* return the median*/
	}

}

unsigned char find_mean(unsigned char* a_arr, unsigned char a_arr_length )
{
	unsigned long long int  sum=0; /* the sum of the array will be saved in this variable*/
	unsigned char i; /* loop itterartion variable*/

	for(i=0;i<a_arr_length;i++)
	{
		/*calculating the sum for all the array data*/
		sum+=a_arr[i];
	}
	return (sum/a_arr_length); /* return the mean*/

}

unsigned char find_maximum(unsigned char* a_arr, unsigned char a_arr_length )
{
	/* the max value and make an inital value of the first elemnt in the arr*/
	unsigned char max=a_arr[0];
	unsigned char i;

	for (i=1;i<a_arr_length;i++)
	{
		/* loop in the all array and check for the max value*/
		if(a_arr[i]>max)
		{
			max=a_arr[i];
		}
	}

	return max;
}

unsigned char find_minimum(unsigned char* a_arr, unsigned char a_arr_length )
{
	/* the max value and make an inital value of the first elemnt in the arr*/
	unsigned char min=a_arr[0];
	unsigned char i;

	for (i=1;i<a_arr_length;i++)
	{
		/* loop in the all array and check for the max value*/
		if(a_arr[i]<min)
		{
			min=a_arr[i];
		}
	}

	return min;
}

void sort_array(unsigned char* a_arr, unsigned char a_arr_length)
{
	/* I will use the bubble sort algorithm in this function*/
	/* iw ill use two counter in this function*/
	unsigned char i;
	unsigned char j;
	unsigned char temp; /* temp variable for the swap*/
	for(i=0;i<(a_arr_length-1);i++)
	{
		for(j=0;j<(a_arr_length-i-1);j++)
		{
			if(a_arr[j]<a_arr[j+1])
			{
				temp=a_arr[j];
				a_arr[j]=a_arr[j+1];
				a_arr[j+1]=temp;
			}
		}
	}

}
