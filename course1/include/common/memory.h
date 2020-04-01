/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);


/**
 * @brief move from the source location to the destination.
 *
 * This function takes two byte pointers (one source and one destination) and a
 * length of bytes to move from the source location to the destination.
 *
 * @param src Pointer to source address
 * @param dst Pointer to distenation address
 * @param length length of moved elemnts
 *
 * @return a pointer to the destination (dst).
 */
unsigned char * my_memmove(unsigned char * src, unsigned char * dst, unsigned long length);

/**
 * @brief copy from the source location to the destination.
 *
 * This function takes two byte pointers (one source and one destination) and a
 * length of bytes to copy from the source location to the destination.
 *
 * @param src Pointer to source address
 * @param dst Pointer to distenation address
 * @param length length of copied elemnts
 *
 * @return a pointer to the destination (dst).
*/
unsigned char  * my_memcopy(unsigned char  * src, unsigned char  * dst, unsigned long  length);


/**
 * @brief set all locations of that memory to a given value.
 *
 * This should take a pointer to a source memory location,
 * a length in bytes and set all locations of that memory to a given value.
 *
 * @param src Pointer to source address
 * @param length length of set elemnts
 * @param value the value that wanted to set with
 *
 * @return Should return a pointer to the source (src).
*/
unsigned char * my_memset(unsigned char * src, unsigned long length, unsigned char value);

/**
 * @brief set all locations of that memory to zero.
 *
 * This should take a pointer to a source memory location,
 * a length in bytes and set all locations of that memory to zero.
 *
 * @param src Pointer to source address
 * @param length length of set elemnts
 *
 * @return Should return a pointer to the source.
*/
unsigned char * my_memzero(unsigned char * src, unsigned long length);

/**
 * @brief  reverse the order of all of the bytes.
 *
 * This should take a pointer to a memory location and a
 * length in bytes and reverse the order of all of the bytes.
 *
 * @param src Pointer to source address
 * @param length length of set elemnts
 *
 * @return Should return a pointer to the source.
*/
unsigned char * my_reverse(unsigned char * src, unsigned long length);

/**
 * @brief  allocate in dynamic memory
 *
 * This should take number of words to allocate in dynamic memory
 *
 * @param length length of set elemnts
 *
 * @return a pointer to memory if successful, or a Null Pointer if not successful
*/
int * reserve_words(unsigned long length);

/**
 * @brief  free a dynamic memory allocation
 *
 * Should free a dynamic memory allocation by providing the pointer src to the function
 *
 * @param src src that will be freed
 *
 * @return void
*/
void free_words(int * src);

#endif /* __MEMORY_H__ */
