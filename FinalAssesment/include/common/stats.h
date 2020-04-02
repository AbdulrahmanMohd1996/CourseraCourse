/**
 * @file <stats.c>
 * @brief <Header file for your C-programming code>
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
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief <A function that prints the statistics of an array including minimum, maximum, mean, and median.>
 *
 * <this function takes an input a pointer to 8-bit integer array. this will
 * prints the statistics of an array including minimum, maximum, mean, and median
 * and dont return any thing >
 *
 * @param <a_arr> <a pointer to 8-bit array>
 * @param <a_arr_length> <the length of the array that will display it statistics>
 *
 * @return <void>
 */
void print_statistics(unsigned char* a_arr, unsigned char a_arr_length );

#ifdef VERBOSE
/**
 * @brief < Given an array of data and a length, prints the array to the screen>
 *
 * <this function takes an input a pointer to 8-bit integer array. this will
 * prints the array data and dont return any thing >
 *
 * @param <a_arr> <a pointer to 8-bit array>
 * @param <a_arr_length> <the length of the array that will display it data>
 *
 * @return <void>
 */
void print_array(unsigned char* a_arr, unsigned char a_arr_length );
#endif

/**
 * @brief <Given an array of data and a length, returns the median value>
 *
 * <this function takes an input a pointer to 8-bit integer array. this will
 * Given an array of data and a length, returns the median value >
 *
 * @param <a_arr> <a pointer to 8-bit array>
 * @param <a_arr_length> <the length of the array that return it is median>
 *
 * @return <the median>
 */
unsigned char find_median(unsigned char* a_arr, unsigned char a_arr_length );

/**
 * @brief <Given an array of data and a length, returns the mean>
 *
 * <this function takes an input a pointer to 8-bit integer array. this will
 * Given an array of data and a length, returns the mean value >
 *
 * @param <a_arr> <a pointer to 8-bit array>
 * @param <a_arr_length> <the length of the array that return it is median>
 *
 * @return <the mean>
 */
unsigned char find_mean(unsigned char* a_arr, unsigned char a_arr_length );

/**
 * @brief <Given an array of data and a length, returns the maximum>
 *
 * <this function takes an input a pointer to 8-bit integer array. this will
 * Given an array of data and a length, returns the MAX value >
 *
 * @param <a_arr> <a pointer to 8-bit array>
 * @param <a_arr_length> <the length of the array that return it is median>
 *
 * @return <the MAX>
 */
unsigned char find_maximum(unsigned char* a_arr, unsigned char a_arr_length );

/**
 * @brief <Given an array of data and a length, returns the minimum>
 *
 * <this function takes an input a pointer to 8-bit integer array. this will
 * Given an array of data and a length, returns the MAX value >
 *
 * @param <a_arr> <a pointer to 8-bit array>
 * @param <a_arr_length> <the length of the array that return it is median>
 *
 * @return <the MIN>
 */
unsigned char find_minimum(unsigned char* a_arr, unsigned char a_arr_length );

/**
 * @brief <Given an array of data and a length, sorts the array from largest to smallest.>
 *
 * < Given an array of data and a length, sorts the array from largest to smallest.
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )>
 *
 * @param <a_arr> <a pointer to 8-bit array>
 * @param <a_arr_length> <the length of the array that return it is median>
 *
 * @return <VOID>
 */
void sort_array(unsigned char* a_arr, unsigned char a_arr_length);

#endif /* __STATS_H__ */
