/**
 * @file data.h
 * @briefAbstraction of data monubilation function documination
 *
 * This header file provides an abstraction of reading and
 * writing to data via function calls.
 *
 * @author Abdulrahman Mohamed
 * @date march 1 2020
 *
 */

#ifndef __DATA__
#define __DATA__

/**
 * @brief convert data from a standard integer type into an ASCII string
 *
 * @param data data that need to convert to string
 * @param ptr ptr to an empty array of character
 * @param base ase that you need to convert to
 *
 * @return  the length of the converted data.
 */
unsigned char my_itoa(int data, unsigned char * ptr, unsigned int base);

/**
 * @brief  convert data back from an ASCII represented string into an integer type.
 *
 *
 * @param ptr ptr to the string that needed to be converted
 * @param digits number of digits in this string
 * @param base base that in formalla to
 *
 * @return  the length of the converted data.
 */
int my_atoi(unsigned char * ptr, unsigned char digits, unsigned int base);


#endif
