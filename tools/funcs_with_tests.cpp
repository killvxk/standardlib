/*
    2023, Gregory Cohen <gregorycohen2@gmail.com>


    DONATION REQUEST: If this free software has helped you and you find
    it valuable, please consider making a donation to support the ongoing
    development and maintenance of this project. Your contribution helps
    ensure the availability of this library to the community and encourages
    further improvements.


                          Donations can be made at:
                 https://www.paypal.com/paypalme/cstandardlib



This code is in the public domain.

You are free to use it for any commercial or noncommercial purpose.

*/

#ifndef _FOUNDATIONALLIB_HEADER_GUARD
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

// structs (types)
struct Dict;
struct FrozenDict;
struct Set;
struct FrozenSet;


// Functions


// This code is in the Public domain.

#ifndef FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC
#define FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC malloc
#endif

#ifndef FOUNDATIONALLIB_MEMORY_ALLOCATOR_REALLOC
#define FOUNDATIONALLIB_MEMORY_ALLOCATOR_REALLOC realloc
#endif

#ifndef FOUNDATIONALLIB_MEMORY_ALLOCATOR_CALLOC
#define FOUNDATIONALLIB_MEMORY_ALLOCATOR_CALLOC calloc
#endif

#ifndef FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE
#define FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE free
#endif

#ifndef FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP
#define FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP strdup
#endif

#ifndef FOUNDATIONALLIB_HASH_INITIAL_CAPACITY
#define FOUNDATIONALLIB_HASH_INITIAL_CAPACITY 16
#endif

#ifndef FOUNDATIONALLIB_HASH_LOAD_FACTOR_THRESHOLD
#define FOUNDATIONALLIB_HASH_LOAD_FACTOR_THRESHOLD 0.75
#endif

#ifndef FOUNDATIONAL_LIB_FUNC
#define FOUNDATIONAL_LIB_FUNC static inline
#endif

#ifndef FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE
#define FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE static unsigned char
#endif

// When this is true, the functions kill the program on error; when this is false, they ALL fail silently. Toggle as you wish.
// This is the only global declared, 1 byte of overhead. But it's worth it to control the behavior of the functions.
FOUNDATIONAL_LIB_AGGRESSIVE_DIE_TYPE aggressive_die = true; // Default die (good for scripting etc)

#define set_aggressive_die(mode)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   \
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              \
        aggressive_die = (mode);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   \
    }
#define get_aggressive_die() (aggressive_die)

#ifndef die_aggressively_if_enabled
#define die_aggressively_if_enabled()                                                                                                                                                                                                                                                                                                                                                                                                                                                                              \
    if (aggressive_die)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            \
    {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              \
        printf("Error: %s: %s", __func__, strerror(errno));                                                                                                                                                                                                                                                                                                                                                                                                                                                        \
        exit(EXIT_FAILURE);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        \
    }
#endif

static inline void test_foundationallib_test_error_handler(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

/* @brief Frees an array and all of its elements (top pointer and 1 level deep). */
FOUNDATIONAL_LIB_FUNC void free_array(void **array, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(array[i]);
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(array);
}

/* @brief Function to print a uint array */
FOUNDATIONAL_LIB_FUNC void print_uint_array(const unsigned int *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%u", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}
/* @brief Function to print a uint array */
FOUNDATIONAL_LIB_FUNC void print_uint_ptr_array(const unsigned int **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%u", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a int array */
FOUNDATIONAL_LIB_FUNC void print_int_array(const int *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a int array */
FOUNDATIONAL_LIB_FUNC void print_int_ptr_array(const int **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a uchar array */
FOUNDATIONAL_LIB_FUNC void print_uchar_array(const unsigned char *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%c", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a uchar array */
FOUNDATIONAL_LIB_FUNC void print_uchar_ptr_array(const unsigned char **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%c", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a char array */
FOUNDATIONAL_LIB_FUNC void print_char_array(const char *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%c", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a char array */
FOUNDATIONAL_LIB_FUNC void print_char_ptr_array(const char **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%c", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}
FOUNDATIONAL_LIB_FUNC void print_string_array(char **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        fputs(array[i], stdout);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a ushort array */
FOUNDATIONAL_LIB_FUNC void print_ushort_array(const unsigned short *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%hu", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a ushort array */
FOUNDATIONAL_LIB_FUNC void print_ushort_ptr_array(const unsigned short **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%hu", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a short array */
FOUNDATIONAL_LIB_FUNC void print_short_array(const short *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a short array */
FOUNDATIONAL_LIB_FUNC void print_short_ptr_array(const short **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a ulong array */
FOUNDATIONAL_LIB_FUNC void print_ulong_array(const unsigned long *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%lu", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a ulong array */
FOUNDATIONAL_LIB_FUNC void print_ulong_ptr_array(const unsigned long **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%lu", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a long array */
FOUNDATIONAL_LIB_FUNC void print_long_array(const long *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%ld", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a long array */
FOUNDATIONAL_LIB_FUNC void print_long_ptr_array(const long **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%ld", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a ulong_long array */
FOUNDATIONAL_LIB_FUNC void print_ulong_long_array(const unsigned long long *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%llu", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a ulong_long array */
FOUNDATIONAL_LIB_FUNC void print_ulong_long_ptr_array(const unsigned long long **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%llu", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a long_long array */
FOUNDATIONAL_LIB_FUNC void print_long_long_array(const long long *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%lld", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a long_long array */
FOUNDATIONAL_LIB_FUNC void print_long_long_ptr_array(const long long **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%lld", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a float array */
FOUNDATIONAL_LIB_FUNC void print_float_array(const float *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%f", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a float array */
FOUNDATIONAL_LIB_FUNC void print_float_ptr_array(const float **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%f", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a double array */
FOUNDATIONAL_LIB_FUNC void print_double_array(const double *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%lf", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a double array */
FOUNDATIONAL_LIB_FUNC void print_double_ptr_array(const double **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%lf", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a size_t array */
FOUNDATIONAL_LIB_FUNC void print_size_t_array(const size_t *array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%zu", array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Function to print a size_t array */
FOUNDATIONAL_LIB_FUNC void print_size_t_ptr_array(const size_t **array, size_t size)
{
    putchar('[');
    for (size_t i = 0; i < size; i++)
    {
        printf("%zu", *array[i]);
        if (i < size - 1)
        {
            fputs(", ", stdout);
        }
    }
    puts("]");
}

/* @brief Duplicates an array of anything (void*) 1 level deep */
FOUNDATIONAL_LIB_FUNC void *arraydup(const void *arr, size_t num_mem, size_t size)
{
    const size_t tot_size = num_mem * size;
    char *duplicate = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(tot_size);

    if (duplicate == NULL)
    {
        /* @brief  Handle memory allocation failure */
        die_aggressively_if_enabled();
        return NULL;
    }

    for (size_t i = 0; i < tot_size; i++)
    {
        duplicate[i] = ((char *)arr)[i];
    }

    return (void *)duplicate;
}

/* @brief Alias */
FOUNDATIONAL_LIB_FUNC void *array_dup(const void *arr, size_t num_mem, size_t size) { return arraydup(arr, num_mem, size); }
/* @brief Alias */
FOUNDATIONAL_LIB_FUNC void *duparray(const void *arr, size_t num_mem, size_t size) { return arraydup(arr, num_mem, size); }
/* @brief Alias */
FOUNDATIONAL_LIB_FUNC void *dup_array(const void *arr, size_t num_mem, size_t size) { return arraydup(arr, num_mem, size); }

FOUNDATIONAL_LIB_FUNC int equal_uint(const unsigned int *array, const unsigned int *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_uint_ptr(const unsigned int **array, const unsigned int **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_int(const int *array, const int *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_int_ptr(const int **array, const int **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_uchar(const unsigned char *array, const unsigned char *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_uchar_ptr(const unsigned char **array, const unsigned char **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_char(const char *array, const char *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_char_ptr(const char **array, const char **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_ushort(const unsigned short *array, const unsigned short *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_ushort_ptr(const unsigned short **array, const unsigned short **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_short(const short *array, const short *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_short_ptr(const short **array, const short **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_ulong(const unsigned long *array, const unsigned long *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_ulong_ptr(const unsigned long **array, const unsigned long **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_long(const long *array, const long *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_long_ptr(const long **array, const long **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_ulong_long(const unsigned long long *array, const unsigned long long *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_ulong_long_ptr(const unsigned long long **array, const unsigned long long **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_long_long(const long long *array, const long long *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_long_long_ptr(const long long **array, const long long **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_float(const float *array, const float *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_float_ptr(const float **array, const float **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_double(const double *array, const double *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_double_ptr(const double **array, const double **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_size_t(const size_t *array, const size_t *array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int equal_size_t_ptr(const size_t **array, const size_t **array2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC char *string_to_json(const char *input_string)
{
    size_t escaped_length = 0;
    size_t i;

    /* @brief  Calculate the length of the escaped string */
    for (i = 0; input_string[i]; ++i)
    {
        if (input_string[i] == '"' || input_string[i] == '\\')
        {
            escaped_length += 2; // Need to escape with a backslash
        }
        else
        {
            escaped_length += 1; // No need for escaping
        }
    }

    size_t input_length = i;

    /* @brief  Calculate the length of the resulting JSON string */
    size_t json_length = escaped_length + 2; // 2 for double quotes

    /* @brief  Allocate memory for the JSON string */
    char *json_result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(json_length + 1); // +1 for null terminator

    if (json_result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    /* @brief  Add double quotes around the escaped string */
    json_result[0] = '"';

    size_t j = 1;
    for (i = 0; i < input_length; i++)
    {
        if (input_string[i] == '"' || input_string[i] == '\\')
        {
            json_result[j++] = '\\';
        }
        json_result[j++] = input_string[i];
    }

    json_result[json_length - 1] = '"';
    json_result[json_length] = '\0'; // Null-terminate the string

    return json_result;
}

/* @brief Function to trim leading and trailing whitespace from a string */
FOUNDATIONAL_LIB_FUNC char *strip(const char *str)
{
    size_t start = 0, end = strlen(str);

    /* @brief  Trim leading whitespace */
    while (isspace(str[start]))
    {
        start++;
    }

    /* @brief  Trim trailing whitespace */
    while (end > start && isspace(str[end - 1]))
    {
        end--;
    }

    /* @brief  Copy the stripped portion into a new string */
    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(end - start + 1);

    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    strncpy(result, str + start, end - start);
    result[end - start] = '\0';

    return result;
}

/* @brief Function to split a string into an array based on a delimiter */
FOUNDATIONAL_LIB_FUNC char **split(const char *str, char delimiter, size_t *count)
{
    /* @brief  Count the number of tokens */
    *count = 1;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == delimiter)
        {
            (*count)++;
        }
    }

    /* @brief  Allocate memory for the array of strings */
    char **result = (char **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(*count * sizeof(char *));
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    size_t tokenIndex = 0;
    size_t tokenStart = 0;

    /* @brief  Split the string into tokens */
    for (size_t i = 0; i <= strlen(str); i++)
    {
        if (str[i] == delimiter || str[i] == '\0')
        {
            size_t tokenLength = i - tokenStart;
            result[tokenIndex] = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(tokenLength + 1);

            if (result == NULL)
            {
                die_aggressively_if_enabled();
                return NULL;
            }
            strncpy(result[tokenIndex], str + tokenStart, tokenLength);
            result[tokenIndex][tokenLength] = '\0';
            tokenStart = i + 1;
            tokenIndex++;
        }
    }

    return result;
}

/* @brief Function to join an array of strings into a single string with a delimiter */
FOUNDATIONAL_LIB_FUNC char *join(const char **array, size_t count, const char *delimiter)
{
    size_t *lens = (size_t *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(sizeof(size_t) * count);
    if (lens == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }
    const size_t delimeter_length = strlen(delimiter);
    /* @brief  Calculate the total length of the resulting string */
    size_t totalLength = 1; // NUL byte
    for (size_t i = 0; i < count; i++)
    {
        const size_t new_len = strlen(array[i]);
        lens[i] = new_len;
        totalLength += new_len;
        if (i < count - 1)
        {
            totalLength += delimeter_length;
        }
    }

    /* @brief  Allocate memory for the resulting string */
    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(totalLength);
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    size_t array_index;

    size_t len_so_far = 0;

    /* @brief  Concatenate strings with the delimiter */
    for (array_index = 0; array_index < count; array_index++)
    {
        const size_t len = lens[array_index];

        /* @brief  Copy str */
        for (size_t x = 0; x < len; ++x)
        {
            result[len_so_far + x] = array[array_index][x];
        }

        len_so_far += len;
        if (array_index < count - 1)
        {
            /* @brief  Copy delimiter */
            for (size_t i = 0; i < delimeter_length; ++i)
            {
                result[len_so_far + i] = delimiter[i];
            }
            len_so_far += delimeter_length;
        }
    }

    result[len_so_far] = '\0';

    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(lens);

    return result;
}

FOUNDATIONAL_LIB_FUNC int test1()
{
    const char *original = "   Hello, world!   ";
    printf("Original: \"%s\"\n", original);

    /* @brief  Test strip function */
    char *stripped = strip(original);
    printf("Stripped: \"%s\"\n", stripped);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(stripped);

    /* @brief  Test split function */
    size_t count;
    char **tokens = split("apple,orange,banana", ',', &count);
    printf("Split into %zu tokens:\n", count);
    for (size_t i = 0; i < count; i++)
    {
        printf("%zu: \"%s\"\n", i + 1, tokens[i]);
        FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(tokens[i]);
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(tokens);

    /* @brief  Test join function */
    const char *fruits[] = {"apple", "orange", "banana"};
    char *joined = join(fruits, sizeof(fruits) / sizeof(fruits[0]), ",");
    printf("Joined: \"%s\"\n", joined);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(joined);

    return 0;
}

/* @brief Function to append a new element to the end of an array, returns the array */
FOUNDATIONAL_LIB_FUNC char **append(char ***array, size_t *string_size, const char *element)
{
    (*string_size)++;
    const size_t new_size = (size_t)((*string_size) + (*string_size) / 2) + 20;

    if (new_size > *string_size)
    {
        *array = (char **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_REALLOC(*array, new_size * sizeof(char *));
        if (*array == NULL)
        {
            die_aggressively_if_enabled();
            return NULL;
        }
    }

    if (((*array)[*string_size - 1] = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(element)) == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    return *array;
}

/* @brief Function to prepend a new element to the beginning of an array, returns the array (char**) */
FOUNDATIONAL_LIB_FUNC char **prepend(char ***array, size_t *count, const char *element)
{
    (*count)++;
    const size_t new_size = (size_t)((*count) + (*count) / 2) + 20;

    if (new_size > *count)
    {
        *array = (char **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_REALLOC(*array, new_size * sizeof(char *));
        if (*array == NULL)
        {
            die_aggressively_if_enabled();
            return NULL;
        }
    }

    memmove(*array + 1, *array, (*count - 1) * sizeof(char *));
    if (((*array)[0] = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(element)) == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    return *array;
}

/* @brief Function to get the length of an array */
FOUNDATIONAL_LIB_FUNC size_t array_length(const char **array, size_t count)
{
    size_t length = 0;
    for (size_t i = 0; i < count; i++)
    {
        length += strlen(array[i]);
    }
    return length;
}

FOUNDATIONAL_LIB_FUNC int test2()
{
    char **myArray = NULL;
    size_t count = 0;

    /* @brief  Append some elements */
    append(&myArray, &count, "World");
    append(&myArray, &count, "Hello");

    /* @brief  Prepend another element */
    prepend(&myArray, &count, " ");

    /* @brief  Print the array */
    printf("Array: ");
    for (size_t i = 0; i < count; i++)
    {
        printf("%s", myArray[i]);
    }
    printf("\n");

    /* @brief  Print the total length of strings in the array */
    size_t totalLength = array_length((const char **)myArray, count);
    printf("Total Length: %zu\n", totalLength);

    /* @brief  Free the memory */
    for (size_t i = 0; i < count; i++)
    {
        FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(myArray[i]);
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(myArray);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *shellescape(const char *input)
{
    size_t input_len = strlen(input);
    size_t escaped_len = 2 * input_len + 1;
    char *escaped = (char *)malloc(escaped_len);

    if (escaped == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    size_t j = 0;
    for (size_t i = 0; i < input_len; i++)
    {
        // Escape special characters
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == '*' || input[i] == '?' || input[i] == '\'' || input[i] == '"' || input[i] == '\\' || input[i] == '$' || input[i] == '`' || input[i] == '(' || input[i] == ')' || input[i] == '&' || input[i] == ';' || input[i] == '|' || input[i] == '>' || input[i] == '<')
        {
            escaped[j++] = '\\';
        }
        escaped[j++] = input[i];
    }

    escaped[j] = '\0';

    return escaped;
}

/* @brief Function to reverse a string */
FOUNDATIONAL_LIB_FUNC char *reverse_string(const char *str)
{
    char *new_str = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(str);
    if (new_str == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }
    size_t length = strlen(new_str);
    size_t i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = new_str[i];
        new_str[i] = new_str[j];
        new_str[j] = temp;
    }

    return new_str;
}

FOUNDATIONAL_LIB_FUNC int test3()
{
    /* @brief  Test shellescape function */
    const char *command = "echo Hello, world!";
    char *escapedCommand = shellescape(command);
    printf("Original command: %s\n", command);
    printf("Escaped command: %s\n", escapedCommand);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(escapedCommand);

    const char *unsafe_input = "Hello, world!'; rm -rf / # ( && | > <";
    char *escaped_input = shellescape(unsafe_input);

    printf("Unsafe Input: %s\n", unsafe_input);
    printf("Escaped Output: %s\n", escaped_input);

    free(escaped_input);

    /* @brief  Test reverse function */
    const char *original = "reverse";
    char *reversed = reverse_string(original);
    printf("\nOriginal string: %s\n", original);
    printf("Reversed string: %s\n", reversed);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(reversed);

    return 0;
}

FOUNDATIONAL_LIB_FUNC int starts_with(const char *str, const char *prefix) { return strncmp(str, prefix, strlen(prefix)) == 0; }

/* @brief Function to check if a string ends with a specified suffix */
FOUNDATIONAL_LIB_FUNC int ends_with(const char *str, const char *suffix)
{
    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);

    if (suffix_len > str_len)
    {
        return 0; // Suffix is longer than the string
    }

    return strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0;
}

FOUNDATIONAL_LIB_FUNC int test4()
{
    /* @brief  Test starts_with and ends_with functions */
    const char *text = "This is a sample text";
    const char *prefix = "This";
    const char *suffix = "text";
    printf("\nDoes the string start with \"%s\"? %s\n", prefix, starts_with(text, prefix) ? "Yes" : "No");
    printf("Does the string end with \"%s\"? %s\n", suffix, ends_with(text, suffix) ? "Yes" : "No");

    return 0;
}

/* @brief Function to replace all occurrences of a substring in a string */
FOUNDATIONAL_LIB_FUNC char *replace_all(const char *str, const char *old_substring, const char *new_substring)
{
    char *result = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(str);

    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    char *pos = result;

    while ((pos = strstr(pos, old_substring)) != NULL)
    {
        /* @brief  Calculate the lengths before and after the old substring */
        size_t before_len = pos - result;
        size_t after_len = strlen(pos + strlen(old_substring));

        /* @brief  Allocate memory for the modified string */
        char *new_str = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(before_len + strlen(new_substring) + after_len + 1);

        if (new_str == NULL)
        {
            die_aggressively_if_enabled();
            return NULL;
        }

        /* @brief  Copy the portions before, the new substring, and after */
        strncpy(new_str, result, before_len);
        strcpy(new_str + before_len, new_substring);
        strcpy(new_str + before_len + strlen(new_substring), pos + strlen(old_substring));

        /* @brief  Free the old result and update it */
        FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(result);
        result = new_str;

        /* @brief  Move the position after the newly inserted substring */
        pos = new_str + before_len + strlen(new_substring);
    }

    return result;
}

/* @brief Function to count the occurrences of a substring in a string */
FOUNDATIONAL_LIB_FUNC size_t count_occurrences(const char *str, const char *substring)
{
    size_t count = 0;
    const char *pos = str;

    while ((pos = strstr(pos, substring)) != NULL)
    {
        count++;
        pos += strlen(substring);
    }

    return count;
}

/* @brief Function to trim leading and trailing characters from a string */
FOUNDATIONAL_LIB_FUNC char *trim_chars(const char *str, const char *chars_to_trim)
{
    size_t start = 0, end = strlen(str);

    /* @brief  Trim leading characters */
    while (strchr(chars_to_trim, str[start]) != NULL)
    {
        start++;
    }

    /* @brief  Trim trailing characters */
    while (end > start && strchr(chars_to_trim, str[end - 1]) != NULL)
    {
        end--;
    }

    /* @brief  Copy the trimmed portion into a new string */
    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(end - start + 1);
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }
    strncpy(result, str + start, end - start);
    result[end - start] = '\0';

    return result;
}

FOUNDATIONAL_LIB_FUNC int test5()
{
    /* @brief  Test replace_all function */
    const char *sentence = "The quick brown fox jumps over the lazy dog.";
    const char *old_word = "fox";
    const char *new_word = "cat";
    char *replaced = replace_all(sentence, old_word, new_word);
    printf("Original sentence: %s\n", sentence);
    printf("Sentence after replacement: %s\n", replaced);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(replaced);

    /* @brief  Test count_occurrences function */
    const char *text = "How much wood would a woodchuck chuck if a woodchuck could chuck wood?";
    const char *word_to_count = "wood";
    size_t occurrences = count_occurrences(text, word_to_count);
    printf("\nOccurrences of \"%s\" in the text: %zu\n", word_to_count, occurrences);

    /* @brief  Test trim_chars function */
    const char *untrimmed = "   \tTrim me! \t\n";
    const char *chars_to_trim = " \t\n";
    char *trimmed = trim_chars(untrimmed, chars_to_trim);
    printf("\nOriginal string: \"%s\"\n", untrimmed);
    printf("Trimmed string: \"%s\"\n", trimmed);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(trimmed);

    return 0;
}

/* @brief Function to find the index of the first occurrence of a character in a string */
FOUNDATIONAL_LIB_FUNC ssize_t index_of(const char *str, char target)
{
    const char *result = strchr(str, target);
    return result != NULL ? result - str : -1;
}

/* @brief Function to find the index of the last occurrence of a character in a string */
FOUNDATIONAL_LIB_FUNC ssize_t last_index_of(const char *str, char target)
{
    const char *result = strrchr(str, target);
    return result != NULL ? result - str : -1;
}

/* @brief Function to concatenate multiple strings into a new string */
FOUNDATIONAL_LIB_FUNC char *concatenate(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(len1 + len2 + 1);
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }
    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

/* @brief Alias */
FOUNDATIONAL_LIB_FUNC char *concatenated(const char *str1, const char *str2) { return concatenate(str1, str2); }

FOUNDATIONAL_LIB_FUNC int test6()
{
    /* @brief  Test index_of and last_index_of functions */
    const char *sentence = "The quick brown fox jumps over the lazy dog.";
    char target_char = 'o';
    ssize_t first_occurrence = index_of(sentence, target_char);
    ssize_t last_occurrence = last_index_of(sentence, target_char);
    printf("String: \"%s\"\n", sentence);
    printf("Index of first occurrence of '%c': %zd\n", target_char, first_occurrence);
    printf("Index of last occurrence of '%c': %zd\n", target_char, last_occurrence);

    /* @brief  Test concatenate function */
    const char *greeting = "Hello, ";
    const char *name = "world!";
    char *combined = concatenate(greeting, name);
    printf("\nCombined string: \"%s\"\n", combined);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(combined);

    return 0;
}
FOUNDATIONAL_LIB_FUNC char *reverse_words(const char *str)
{
    /* @brief  Copy the input string to a mutable buffer */
    char *reversedStr = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(str);
    if (reversedStr == NULL)
    {
        /* @brief  Memory allocation failure */
        die_aggressively_if_enabled();
        return NULL;
    }

    /* @brief  Find the length of the string */
    size_t length = strlen(reversedStr);

    /* @brief  Reverse the entire string */
    for (size_t i = 0; i < length / 2; ++i)
    {
        char temp = reversedStr[i];
        reversedStr[i] = reversedStr[length - i - 1];
        reversedStr[length - i - 1] = temp;
    }

    /* @brief  Reverse each word in the string */
    char *start = reversedStr;
    char *end = reversedStr;

    while (*end)
    {
        if (*end == ' ')
        {
            /* @brief  Reverse the word */
            size_t wordLength = end - start;
            for (size_t i = 0; i < wordLength / 2; ++i)
            {
                char temp = start[i];
                start[i] = start[wordLength - i - 1];
                start[wordLength - i - 1] = temp;
            }
            start = end + 1; // Move to the next word
        }
        end++;
    }

    /* @brief  Reverse the last word (or the only word if there's only one) */
    size_t lastWordLength = end - start;
    for (size_t i = 0; i < lastWordLength / 2; ++i)
    {
        char temp = start[i];
        start[i] = start[lastWordLength - i - 1];
        start[lastWordLength - i - 1] = temp;
    }

    return reversedStr;
}

/* @brief Function to find the first non-repeating character in a string */
FOUNDATIONAL_LIB_FUNC char first_non_repeating(const char *str)
{
    size_t len = strlen(str);
    int char_count[256] = {0}; // Assuming ASCII characters

    /* @brief  Count occurrences of each character */
    for (size_t i = 0; i < len; i++)
    {
        char_count[(unsigned char)str[i]]++;
    }

    /* @brief  Find the first non-repeating character */
    for (size_t i = 0; i < len; i++)
    {
        if (char_count[(unsigned char)str[i]] == 1)
        {
            return str[i];
        }
    }

    return '\0'; // No non-repeating character found
}

FOUNDATIONAL_LIB_FUNC int test7()
{
    /* @brief  Test reverse_words function */
    const char *sentence = "The quick brown fox";
    char *reversed_words = reverse_words(sentence);
    printf("Original sentence: \"%s\"\n", sentence);
    printf("Sentence with reversed words: \"%s\"\n", reversed_words);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(reversed_words);

    /* @brief  Test first_non_repeating function */
    const char *string = "hello";
    char first_non_repeat = first_non_repeating(string);
    printf("\nFirst non-repeating character in \"%s\": %c\n", string, first_non_repeat);

    return 0;
}

/* @brief Function to check if a string contains only alphabetic characters */
FOUNDATIONAL_LIB_FUNC int is_alpha(const char *str)
{
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++)
    {
        if (!isalpha(str[i]))
        {
            return 0; // Contains non-alphabetic character
        }
    }

    return 1; // Contains only alphabetic characters
}

/* @brief Function to check if a string contains only numeric characters */
FOUNDATIONAL_LIB_FUNC int is_numeric(const char *str)
{
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0; // Contains non-numeric character
        }
    }

    return 1; // Contains only numeric characters
}

/* @brief Function to check if a string contains only alphanumeric characters */
FOUNDATIONAL_LIB_FUNC int is_alphanumeric(const char *str)
{
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++)
    {
        if (!isalnum(str[i]))
        {
            return 0; // Contains non-alphanumeric character
        }
    }

    return 1; // Contains only alphanumeric characters
}

/* @brief Function to count the number of vowels in a string */
FOUNDATIONAL_LIB_FUNC size_t count_vowels(const char *str)
{
    size_t len = strlen(str);
    const char *vowels = "aeiouAEIOU";
    size_t count = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (strchr(vowels, str[i]) != NULL)
        {
            count++;
        }
    }

    return count;
}

FOUNDATIONAL_LIB_FUNC int test8()
{
    /* @brief  Test is_alpha function */
    const char *alphabetic = "Hello";
    const char *non_alphabetic = "Hello123";
    printf("Is \"%s\" alphabetic? %s\n", alphabetic, is_alpha(alphabetic) ? "Yes" : "No");
    printf("Is \"%s\" alphabetic? %s\n", non_alphabetic, is_alpha(non_alphabetic) ? "Yes" : "No");

    /* @brief  Test is_numeric function */
    const char *numeric = "12345";
    const char *non_numeric = "123abc";
    printf("\nIs \"%s\" numeric? %s\n", numeric, is_numeric(numeric) ? "Yes" : "No");
    printf("Is \"%s\" numeric? %s\n", non_numeric, is_numeric(non_numeric) ? "Yes" : "No");

    /* @brief  Test is_alphanumeric function */
    const char *alphanumeric = "Hello123";
    const char *non_alphanumeric = "Hello_123";
    printf("\nIs \"%s\" alphanumeric? %s\n", alphanumeric, is_alphanumeric(alphanumeric) ? "Yes" : "No");
    printf("Is \"%s\" alphanumeric? %s\n", non_alphanumeric, is_alphanumeric(non_alphanumeric) ? "Yes" : "No");

    /* @brief  Test count_vowels function */
    const char *text = "This is a sample text.";
    size_t vowel_count = count_vowels(text);
    printf("\nNumber of vowels in the text: %zu\n", vowel_count);

    return 0;
}

/* @brief Function to find the longest common prefix among an array of strings, free the result */
FOUNDATIONAL_LIB_FUNC char *longest_common_prefix(const char **strings, size_t count)
{
    if (count == 0)
    {
        char *ret = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(""); // Empty string for an empty array
        if (ret == NULL)
        {
            die_aggressively_if_enabled();
            return NULL;
        }

        return ret;
    }

    size_t min_len = strlen(strings[0]);

    /* @brief  Find the minimum length among the strings */
    for (size_t i = 1; i < count; i++)
    {
        size_t current_len = strlen(strings[i]);
        if (current_len < min_len)
        {
            min_len = current_len;
        }
    }

    /* @brief  Compare characters across the strings until a mismatch is found */
    for (size_t i = 0; i < min_len; i++)
    {
        for (size_t j = 1; j < count; j++)
        {
            if (strings[j][i] != strings[0][i])
            {
                /* @brief  Mismatch found, return the prefix up to this point */
                char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(i + 1);
                if (result == NULL)
                {
                    die_aggressively_if_enabled();
                    return NULL;
                }
                strncpy(result, strings[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }

    /* @brief  All strings match up to the minimum length, return the entire prefix */
    char *dup = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(strings[0]);
    if (dup == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    return dup;
}

/* @brief Function to find the longest common suffix among an array of strings, free result */
FOUNDATIONAL_LIB_FUNC char *longest_common_suffix(const char **strings, size_t count)
{
    if (count == 0)
    {
        char *return_value = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(""); // Empty string for an empty array
        if (return_value == NULL)
        {
            die_aggressively_if_enabled();
            return NULL;
        }
        return return_value;
    }

    size_t min_len = strlen(strings[0]);

    /* @brief  Find the minimum length among the strings */
    for (size_t i = 1; i < count; i++)
    {
        size_t current_len = strlen(strings[i]);
        if (current_len < min_len)
        {
            min_len = current_len;
        }
    }

    /* @brief  Compare characters across the strings until a mismatch is found */
    for (size_t i = 0; i < min_len; i++)
    {
        for (size_t j = 1; j < count; j++)
        {
            size_t current_len = strlen(strings[j]);
            if (strings[j][current_len - i - 1] != strings[0][min_len - i - 1])
            {
                /* @brief  Mismatch found, return the suffix up to this point */
                char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(i + 1);
                if (result == NULL)
                {
                    die_aggressively_if_enabled();
                    return NULL;
                }
                strncpy(result, strings[0] + min_len - i, i);
                result[i] = '\0';
                return result;
            }
        }
    }

    /* @brief  All strings match up to the minimum length, return the entire suffix */
    char *return_value = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(strings[0] + min_len);
    if (return_value == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    return return_value;
}

/* @brief Function to convert an integer to a string */
FOUNDATIONAL_LIB_FUNC char *int_to_string(int number)
{
    char buffer[21]; // Assuming a maximum of 21 digits for an int, 2 ** 64 length
                     /* @brief  is 20 plus nul char */
    sprintf(buffer, "%d", number);
    char *return_value = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(buffer);
    if (return_value == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    return return_value;
}

FOUNDATIONAL_LIB_FUNC int test9()
{
    /* @brief  Test longest_common_prefix function */
    const char *words[] = {"apple", "apricot", "appetizer"};
    char *common_prefix = longest_common_prefix(words, sizeof(words) / sizeof(words[0]));
    printf("Longest common prefix: \"%s\"\n", common_prefix);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(common_prefix);

    /* @brief  Test longest_common_suffix function */
    const char *file_names[] = {"document.txt", "presentation.ppt", "spreadsheet.xlsx"};
    char *common_suffix = longest_common_suffix(file_names, sizeof(file_names) / sizeof(file_names[0]));
    printf("\nLongest common suffix: \"%s\"\n", common_suffix);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(common_suffix);

    /* @brief  Test int_to_string function */
    int number = 3232;
    char *str_number = int_to_string(number);
    printf("\nInteger: %d\n", number);
    printf("String representation: \"%s\"\n", str_number);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(str_number);

    return 0;
}

FOUNDATIONAL_LIB_FUNC double str_to_double(const char *str) { return atof(str); }

/* @brief Function to find the first occurrence of any character from a set in a string */
FOUNDATIONAL_LIB_FUNC ssize_t find_first_of(const char *str, const char *char_set)
{
    const char *result = strpbrk(str, char_set);
    return result != NULL ? result - str : -1;
}

/* @brief Function to find the last occurrence of any character from a set in a string */
FOUNDATIONAL_LIB_FUNC ssize_t find_last_of(const char *str, const char *char_set)
{
    size_t len = strlen(str);
    for (ssize_t i = len - 1; i >= 0; i--)
    {
        if (strchr(char_set, str[i]) != NULL)
        {
            return i;
        }
    }
    return -1;
}

FOUNDATIONAL_LIB_FUNC int test10()
{
    /* @brief  Test str_to_double function */
    const char *double_str = "3.14";
    double converted_double = str_to_double(double_str);
    printf("String: \"%s\"\n", double_str);
    printf("Converted to double: %f\n", converted_double);

    /* @brief  Test find_first_of and find_last_of functions */
    const char *sentence = "The quick brown fox jumps over the lazy dog.";
    const char *vowels = "aeiou";
    ssize_t first_vowel = find_first_of(sentence, vowels);
    ssize_t last_vowel = find_last_of(sentence, vowels);
    printf("\nString: \"%s\"\n", sentence);
    printf("Index of first vowel: %zd\n", first_vowel);
    printf("Index of last vowel: %zd\n", last_vowel);

    return 0;
}

/* @brief Function to remove leading and trailing whitespace from a string */
FOUNDATIONAL_LIB_FUNC char *trim_whitespace(const char *str)
{
    size_t start = 0, end = strlen(str);

    /* @brief  Trim leading whitespace */
    while (isspace(str[start]))
    {
        start++;
    }

    /* @brief  Trim trailing whitespace */
    while (end > start && isspace(str[end - 1]))
    {
        end--;
    }

    /* @brief  Copy the trimmed portion into a new string */
    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(end - start + 1);
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    strncpy(result, str + start, end - start);
    result[end - start] = '\0';

    return result;
}

/* @brief Function to reverse a string in place */
FOUNDATIONAL_LIB_FUNC void reverse_string_in_place(char *str)
{
    size_t len = strlen(str);

    /* @brief  Swap characters from both ends towards the center */
    for (size_t i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

FOUNDATIONAL_LIB_FUNC int test11()
{
    /* @brief  Test join function */
    const char *fruits[] = {"apple", "orange", "banana", "grape"};
    char *joined = join(fruits, sizeof(fruits) / sizeof(fruits[0]), ",");
    printf("Joined string: \"%s\"\n", joined);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(joined);

    /* @brief  Test trim_whitespace function */
    const char *untrimmed = "   \tTrim me! \t\n";
    char *trimmed = trim_whitespace(untrimmed);
    printf("\nOriginal string: \"%s\"\n", untrimmed);
    printf("Trimmed string: \"%s\"\n", trimmed);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(trimmed);

    /* @brief  Test reverse_string_in_place function */
    char to_reverse[] = "Reverse me!";
    printf("\nOriginal string: \"%s\"\n", to_reverse);
    reverse_string_in_place(to_reverse);
    printf("Reversed in place: \"%s\"\n", to_reverse);

    return 0;
}

/* @brief Function to check if a string is a valid integer */
FOUNDATIONAL_LIB_FUNC int is_valid_integer(const char *str)
{
    if (str == NULL || *str == '\0')
    {
        return 0; // Empty string is not a valid integer
    }

    /* @brief  Check for optional sign */
    if (*str == '+' || *str == '-')
    {
        str++;
    }

    /* @brief  Check for at least one digit */
    if (!isdigit(*str))
    {
        return 0;
    }

    /* @brief  Check for remaining digits */
    while (*str != '\0')
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        str++;
    }

    return 1; // Valid integer
}

/* @brief Function to check if two strings are anagrams */
FOUNDATIONAL_LIB_FUNC int are_anagrams(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    if (len1 != len2)
    {
        return 0; // Different lengths, not anagrams
    }

    /* @brief  Create character frequency arrays */
    int count1[256] = {0}; // Assuming ASCII characters
    int count2[256] = {0};

    /* @brief  Increment counts for characters in the first string */
    for (size_t i = 0; i < len1; i++)
    {
        count1[(unsigned char)str1[i]]++;
    }

    /* @brief  Decrement counts for characters in the second string */
    for (size_t i = 0; i < len2; i++)
    {
        count2[(unsigned char)str2[i]]--;
    }

    /* @brief  Check if both arrays have zeros, indicating anagrams */
    for (int i = 0; i < 256; i++)
    {
        if (count1[i] != 0 || count2[i] != 0)
        {
            return 0; // Non-zero count, not anagrams
        }
    }

    return 1; // Anagrams
}

FOUNDATIONAL_LIB_FUNC int test12()
{
    /* @brief  Test is_valid_integer function */
    const char *valid_integer = "12345";
    const char *invalid_integer = "12abc";
    printf("Is \"%s\" a valid integer? %s\n", valid_integer, is_valid_integer(valid_integer) ? "Yes" : "No");
    printf("Is \"%s\" a valid integer? %s\n", invalid_integer, is_valid_integer(invalid_integer) ? "Yes" : "No");

    /* @brief  Test replace_all_substrings function */
    const char *sentence = "The quick brown fox jumps over the lazy dog.";
    const char *old_word = "fox";
    const char *new_word = "cat";
    char *replaced = replace_all(sentence, old_word, new_word);
    printf("\nOriginal sentence: \"%s\"\n", sentence);
    printf("Sentence after replacement: \"%s\"\n", replaced);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(replaced);

    /* @brief  Test are_anagrams function */
    const char *word1 = "listen";
    const char *word2 = "silent";
    printf("\nAre \"%s\" and \"%s\" anagrams? %s\n", word1, word2, are_anagrams(word1, word2) ? "Yes" : "No");

    return 0;
}

/* @brief Function to find the length of the common prefix of two strings */
FOUNDATIONAL_LIB_FUNC size_t common_prefix_length(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t min_len = (len1 < len2) ? len1 : len2;

    for (size_t i = 0; i < min_len; i++)
    {
        if (str1[i] != str2[i])
        {
            return i; // Mismatch found, return current index
        }
    }

    return min_len; // No mismatch found, return the minimum length
}

/* @brief Function to find the length of the common suffix of two strings */
FOUNDATIONAL_LIB_FUNC size_t common_suffix_length(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t min_len = (len1 < len2) ? len1 : len2;

    for (size_t i = 1; i <= min_len; i++)
    {
        if (str1[len1 - i] != str2[len2 - i])
        {
            return i - 1; // Mismatch found, return previous index
        }
    }

    return min_len; // No mismatch found, return the minimum length
}

/* @brief Function to convert a string to title case */
FOUNDATIONAL_LIB_FUNC char *string_to_title_case(const char *str)
{
    size_t len = strlen(str);
    char *title_case = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(len + 1);

    if (title_case == NULL)
    {
        return NULL;
    }
    int make_upper = 1; // Start with the first character as uppercase

    for (size_t i = 0; i < len; i++)
    {
        if (isspace(str[i]))
        {
            make_upper = 1; // Set the flag to capitalize the next character
            title_case[i] = str[i];
        }
        else
        {
            title_case[i] = make_upper ? toupper(str[i]) : tolower(str[i]);
            make_upper = 0; // Reset the flag
        }
    }

    title_case[len] = '\0';

    return title_case;
}

FOUNDATIONAL_LIB_FUNC int test13()
{
    /* @brief  Test common_prefix_length function */
    const char *prefix1 = "apple";
    const char *prefix2 = "appetizer";
    size_t common_prefix_len = common_prefix_length(prefix1, prefix2);
    printf("Common prefix of \"%s\" and \"%s\": \"%.*s\"\n", prefix1, prefix2, (int)common_prefix_len, prefix1);

    /* @brief  Test common_suffix_length function */
    const char *suffix1 = "grape";
    const char *suffix2 = "ripe";
    size_t common_suffix_len = common_suffix_length(suffix1, suffix2);
    printf("\nCommon suffix of \"%s\" and \"%s\": \"%.*s\"\n", suffix1, suffix2, (int)common_suffix_len, suffix1 + strlen(suffix1) - common_suffix_len);

    /* @brief  Test to_title_case function */
    const char *sentence = "the quick brown fox";
    char *title_case = string_to_title_case(sentence);
    printf("\nOriginal sentence: \"%s\"\n", sentence);
    printf("Title case sentence: \"%s\"\n", title_case);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(title_case);

    return 0;
}

/* @brief Function to find the maximum element in an array of integers */
FOUNDATIONAL_LIB_FUNC int find_max(const int *array, size_t size)
{
    if (size == 0)
    {
        /* @brief  Handle empty array case */
        return -1;
    }

    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

/* @brief Function to find the minimum element in an array of integers */
FOUNDATIONAL_LIB_FUNC int find_min(const int *array, size_t size)
{
    if (size == 0)
    {
        /* @brief  Handle empty array case */
        return -1;
    }

    int min = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}

/* @brief Function to calculate the sum of elements in an array of integers */
FOUNDATIONAL_LIB_FUNC int calculate_sum(const int *array, size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

/* @brief Function to reverse an array of integers in place */
FOUNDATIONAL_LIB_FUNC void reverse_array(int *array, size_t size)
{
    for (size_t i = 0, j = size - 1; i < j; i++, j--)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

FOUNDATIONAL_LIB_FUNC int test14()
{
    /* @brief  Test find_max function */
    const int numbers_max[] = {12, 45, 78, 23, 56};
    size_t size_max = sizeof(numbers_max) / sizeof(numbers_max[0]);
    int max_value = find_max(numbers_max, size_max);
    printf("Maximum value in the array: %d\n", max_value);

    /* @brief  Test find_min function */
    const int numbers_min[] = {34, 67, 12, 89, 41};
    size_t size_min = sizeof(numbers_min) / sizeof(numbers_min[0]);
    int min_value = find_min(numbers_min, size_min);
    printf("\nMinimum value in the array: %d\n", min_value);

    /* @brief  Test calculate_sum function */
    const int numbers_sum[] = {5, 10, 15, 20, 25};
    size_t size_sum = sizeof(numbers_sum) / sizeof(numbers_sum[0]);
    int array_sum = calculate_sum(numbers_sum, size_sum);
    printf("\nSum of elements in the array: %d\n", array_sum);

    /* @brief  Test reverse_array function */
    int numbers_reverse[] = {1, 2, 3, 4, 5};
    size_t size_reverse = sizeof(numbers_reverse) / sizeof(numbers_reverse[0]);
    printf("\nOriginal array: ");
    for (size_t i = 0; i < size_reverse; i++)
    {
        printf("%d ", numbers_reverse[i]);
    }
    reverse_array(numbers_reverse, size_reverse);
    printf("\nReversed array: ");
    for (size_t i = 0; i < size_reverse; i++)
    {
        printf("%d ", numbers_reverse[i]);
    }
    printf("\n");

    return 0;
}

/* @brief Function to check if an array of integers is sorted in ascending order */
FOUNDATIONAL_LIB_FUNC int is_sorted_ascending(const int *array, size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] < array[i - 1])
        {
            return 0; // Not sorted in ascending order
        }
    }
    return 1; // Sorted in ascending order
}

/* @brief Function to check if an array of integers is sorted in descending order */
FOUNDATIONAL_LIB_FUNC int is_sorted_descending(const int *array, size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > array[i - 1])
        {
            return 0; // Not sorted in descending order
        }
    }
    return 1; // Sorted in descending order
}

/* @brief Function to remove duplicates from an array of integers and return the new */
/* @brief size */
FOUNDATIONAL_LIB_FUNC size_t remove_duplicates(int *array, size_t size)
{
    if (size <= 1)
    {
        return size; // No duplicates to remove
    }

    size_t unique_index = 1;
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] != array[i - 1])
        {
            array[unique_index++] = array[i];
        }
    }

    return unique_index;
}

/* @brief Function to rotate an array of integers to the right by a given number of */
/* @brief positions, -1 on error, 0 on no error */
FOUNDATIONAL_LIB_FUNC int rotate_array(int *array, size_t size, unsigned long positions)
{
    positions = positions % size; // Ensure positions is within array size

    if (positions == 0)
    {
        return 0; // No rotation needed
    }

    int *temp = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(positions * sizeof(int));

    if (temp == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    /* @brief  Copy the last 'positions' elements to temp */
    for (size_t i = size - positions, j = 0; i < size; i++, j++)
    {
        temp[j] = array[i];
    }

    /* @brief  Shift the remaining elements to the right */
    for (size_t i = size - 1; i >= positions; i--)
    {
        array[i] = array[i - positions];
    }

    /* @brief  Copy the elements from temp to the beginning of the array */
    for (size_t i = 0; i < positions; i++)
    {
        array[i] = temp[i];
    }

    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(temp);

    return 0;
}

FOUNDATIONAL_LIB_FUNC int test15()
{
    /* @brief  Test is_sorted_ascending function */
    const int ascending[] = {1, 2, 3, 5, 8, 13};
    size_t size_ascending = sizeof(ascending) / sizeof(ascending[0]);
    printf("Is the array sorted in ascending order? %s\n", is_sorted_ascending(ascending, size_ascending) ? "Yes" : "No");

    /* @brief  Test is_sorted_descending function */
    const int descending[] = {15, 10, 8, 6, 4, 1};
    size_t size_descending = sizeof(descending) / sizeof(descending[0]);
    printf("\nIs the array sorted in descending order? %s\n", is_sorted_descending(descending, size_descending) ? "Yes" : "No");

    /* @brief  Test remove_duplicates function */
    int with_duplicates[] = {2, 3, 3, 5, 7, 7, 8, 8, 8, 10};
    size_t size_duplicates = sizeof(with_duplicates) / sizeof(with_duplicates[0]);
    size_t new_size = remove_duplicates(with_duplicates, size_duplicates);
    printf("\nArray with duplicates: ");
    for (size_t i = 0; i < new_size; i++)
    {
        printf("%d ", with_duplicates[i]);
    }

    /* @brief  Test rotate_array function */
    int to_rotate[] = {1, 2, 3, 4, 5};
    size_t size_rotate = sizeof(to_rotate) / sizeof(to_rotate[0]);
    printf("\n\nOriginal array: ");
    for (size_t i = 0; i < size_rotate; i++)
    {
        printf("%d ", to_rotate[i]);
    }
    rotate_array(to_rotate, size_rotate, 2);
    printf("\nRotated array by 2 positions to the right: ");
    for (size_t i = 0; i < size_rotate; i++)
    {
        printf("%d ", to_rotate[i]);
    }
    printf("\n");

    return 0;
}

/* @brief Function to find the index of a specific element in an array of integers */
FOUNDATIONAL_LIB_FUNC ssize_t find_index(const int *array, size_t size, int target)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

/* @brief Function to check if two arrays of integers are equal */
FOUNDATIONAL_LIB_FUNC int are_arrays_equal(const int *array1, size_t size1, const int *array2, size_t size2)
{
    if (size1 != size2)
    {
        return 0; // Arrays of different sizes are not equal
    }

    for (size_t i = 0; i < size1; i++)
    {
        if (array1[i] != array2[i])
        {
            return 0; // Elements at the same index are different
        }
    }

    return 1; // Arrays are equal
}

/* @brief Function to merge two sorted arrays of integers into a new sorted array */
FOUNDATIONAL_LIB_FUNC int *merge_sorted_arrays(const int *array1, size_t size1, const int *array2, size_t size2, size_t *merged_size)
{
    size_t merged_capacity = size1 + size2;
    int *merged_array = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(merged_capacity * sizeof(int));

    if (merged_array == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    size_t i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (array1[i] <= array2[j])
        {
            merged_array[k++] = array1[i++];
        }
        else
        {
            merged_array[k++] = array2[j++];
        }
    }

    /* @brief  Copy the remaining elements from both arrays */
    while (i < size1)
    {
        merged_array[k++] = array1[i++];
    }

    while (j < size2)
    {
        merged_array[k++] = array2[j++];
    }

    *merged_size = k;
    int *ret = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_REALLOC(merged_array,
                                                               k * sizeof(int)); // Adjust the size of the merged array

    if (ret == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    return ret;
}

FOUNDATIONAL_LIB_FUNC int test16()
{
    /* @brief  Test find_index function */
    const int numbers_find[] = {10, 20, 30, 40, 50};
    size_t size_find = sizeof(numbers_find) / sizeof(numbers_find[0]);
    int target_find = 30;
    ssize_t index = find_index(numbers_find, size_find, target_find);
    printf("Index of %d in the array: %zd\n", target_find, index);

    /* @brief  Test are_arrays_equal function */
    const int array_equal1[] = {1, 2, 3, 4, 5};
    const int array_equal2[] = {1, 2, 3, 4, 5};
    size_t size_equal = sizeof(array_equal1) / sizeof(array_equal1[0]);
    printf("\nAre the arrays equal? %s\n", are_arrays_equal(array_equal1, size_equal, array_equal2, size_equal) ? "Yes" : "No");

    /* @brief  Test merge_sorted_arrays function */
    const int array_merge1[] = {2, 4, 6, 8, 10};
    const int array_merge2[] = {1, 3, 5, 7, 9};
    size_t size_merge1 = sizeof(array_merge1) / sizeof(array_merge1[0]);
    size_t size_merge2 = sizeof(array_merge2) / sizeof(array_merge2[0]);
    size_t merged_size;
    int *merged = merge_sorted_arrays(array_merge1, size_merge1, array_merge2, size_merge2, &merged_size);
    printf("\nMerged sorted array: ");
    for (size_t i = 0; i < merged_size; i++)
    {
        printf("%d ", merged[i]);
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(merged);

    return 0;
}

/* @brief Function to find the intersection of two arrays of integers */
FOUNDATIONAL_LIB_FUNC int *find_intersection(const int *array1, size_t size1, const int *array2, size_t size2, size_t *intersection_size)
{
    size_t min_size = (size1 < size2) ? size1 : size2;
    int *intersection = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(min_size * sizeof(int));

    if (intersection == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    size_t i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (array1[i] < array2[j])
        {
            i++;
        }
        else if (array1[i] > array2[j])
        {
            j++;
        }
        else
        {
            intersection[k++] = array1[i++];
            j++;
        }
    }

    *intersection_size = k;
    int *ret = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_REALLOC(intersection,
                                                               k * sizeof(int)); // Adjust the size of the intersection array

    if (ret == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    return ret;
}

/* @brief Function to perform a binary search on a sorted array and return the index of */
/* @brief the target element */
FOUNDATIONAL_LIB_FUNC ssize_t binary_search(const int *sorted_array, size_t size, int target)
{
    ssize_t low = 0;
    ssize_t high = size - 1;

    while (low <= high)
    {
        ssize_t mid = (low + high) / 2;

        if (sorted_array[mid] == target)
        {
            return mid; // Target found
        }
        else if (sorted_array[mid] < target)
        {
            low = mid + 1; // Search the right half
        }
        else
        {
            high = mid - 1; // Search the left half
        }
    }

    return -1; // Target not found
}

FOUNDATIONAL_LIB_FUNC int test17()
{
    /* @brief  Test find_intersection function */
    const int array_intersection1[] = {2, 4, 6, 8, 10};
    const int array_intersection2[] = {1, 3, 5, 6, 10};
    size_t size_intersection1 = sizeof(array_intersection1) / sizeof(array_intersection1[0]);
    size_t size_intersection2 = sizeof(array_intersection2) / sizeof(array_intersection2[0]);
    size_t intersection_size;
    int *intersection = find_intersection(array_intersection1, size_intersection1, array_intersection2, size_intersection2, &intersection_size);
    printf("Intersection of arrays: ");
    for (size_t i = 0; i < intersection_size; i++)
    {
        printf("%d ", intersection[i]);
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(intersection);

    /* @brief  Test binary_search function */
    const int sorted_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t size_sorted = sizeof(sorted_array) / sizeof(sorted_array[0]);
    int target_search = 5;
    ssize_t index = binary_search(sorted_array, size_sorted, target_search);
    printf("\n\nIndex of %d in the sorted array: %zd\n", target_search, index);

    return 0;
}

/* @brief Function to find the union of two arrays of integers */
FOUNDATIONAL_LIB_FUNC int *find_union(const int *array1, size_t size1, const int *array2, size_t size2, size_t *union_size)
{
    size_t max_size = size1 + size2;
    int *union_array = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(max_size * sizeof(int));

    if (union_array == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    size_t i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (array1[i] < array2[j])
        {
            union_array[k++] = array1[i++];
        }
        else if (array1[i] > array2[j])
        {
            union_array[k++] = array2[j++];
        }
        else
        {
            union_array[k++] = array1[i++];
            j++;
        }
    }

    /* @brief  Copy the remaining elements from both arrays */
    while (i < size1)
    {
        union_array[k++] = array1[i++];
    }

    while (j < size2)
    {
        union_array[k++] = array2[j++];
    }

    *union_size = k;
    int *ret = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_REALLOC(union_array,
                                                               k * sizeof(int)); // Adjust the size of the union array

    if (ret == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    return ret;
}

/* @brief Function to find the kth smallest element in an array of integers */
/* @brief (QuickSelect algorithm) */
FOUNDATIONAL_LIB_FUNC int find_kth_smallest(int *array, size_t size, size_t k)
{
    if (k > 0 && k <= size)
    {
        /* @brief  Perform QuickSelect */
        size_t low = 0;
        size_t high = size - 1;

        while (low <= high)
        {
            size_t pivot_index = low + rand() % (high - low + 1);
            int pivot = array[pivot_index];

            /* @brief  Partition the array */
            size_t i = low;
            size_t j = high;

            while (i <= j)
            {
                while (array[i] < pivot)
                {
                    i++;
                }

                while (array[j] > pivot)
                {
                    j--;
                }

                if (i <= j)
                {
                    /* @brief  Swap array[i] and array[j] */
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    i++;
                    j--;
                }
            }

            /* @brief  Recursively search in the appropriate partition */
            if (j >= k - 1)
            {
                high = j;
            }
            else
            {
                low = i;
            }
        }

        return array[k - 1];
    }

    // Error: Invalid value of k for find_kth_smallest.

    return -1;
}

FOUNDATIONAL_LIB_FUNC int test18()
{
    /* @brief  Test find_union function */
    const int array_union1[] = {2, 4, 6, 8, 10};
    const int array_union2[] = {1, 3, 5, 6, 10};
    size_t size_union1 = sizeof(array_union1) / sizeof(array_union1[0]);
    size_t size_union2 = sizeof(array_union2) / sizeof(array_union2[0]);
    size_t union_size;
    int *union_array = find_union(array_union1, size_union1, array_union2, size_union2, &union_size);
    printf("Union of arrays: ");
    for (size_t i = 0; i < union_size; i++)
    {
        printf("%d ", union_array[i]);
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(union_array);

    /* @brief  Test find_kth_smallest function */
    int array_kth_smallest[] = {5, 3, 8, 2, 1, 7, 4, 6};
    size_t size_kth_smallest = sizeof(array_kth_smallest) / sizeof(array_kth_smallest[0]);
    size_t k = 3;
    int kth_smallest = find_kth_smallest(array_kth_smallest, size_kth_smallest, k);
    printf("\n\n%dth smallest element in the array: %d\n", (int)k, kth_smallest);

    return 0;
}

/* @brief Function to find the maximum consecutive sum in an array of integers */
/* @brief (Kadane's Algorithm) */
FOUNDATIONAL_LIB_FUNC int find_maximum_consecutive_sum(const int *array, size_t size)
{
    if (size == 0)
    {
        /* @brief Handle empty array case */
        return -1;
    }

    int max_sum = array[0];
    int current_sum = array[0];

    for (size_t i = 1; i < size; i++)
    {
        current_sum = (current_sum + array[i] > array[i]) ? current_sum + array[i] : array[i];
        max_sum = (current_sum > max_sum) ? current_sum : max_sum;
    }

    return max_sum;
}

/* @brief Function to find the majority element in an array (Boyer-Moore Voting */
/* @brief Algorithm) */
FOUNDATIONAL_LIB_FUNC int find_majority_element(const int *array, size_t size)
{
    int candidate = array[0];
    size_t count = 1;

    for (size_t i = 1; i < size; i++)
    {
        if (array[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;

            if (count == 0)
            {
                candidate = array[i];
                count = 1;
            }
        }
    }

    /* @brief  Verify if the candidate is the majority element */
    count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == candidate)
        {
            count++;
        }
    }

    if (count > size / 2)
    {
        return candidate;
    }

    // Error: No majority element found

    return -1;
}

FOUNDATIONAL_LIB_FUNC int test19()
{
    /* @brief  Test find_maximum_consecutive_sum function */
    const int array_consecutive_sum[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    size_t size_consecutive_sum = sizeof(array_consecutive_sum) / sizeof(array_consecutive_sum[0]);
    int max_sum = find_maximum_consecutive_sum(array_consecutive_sum, size_consecutive_sum);
    printf("Maximum consecutive sum in the array: %d\n", max_sum);

    /* @brief  Test find_majority_element function */
    const int array_majority[] = {2, 2, 1, 1, 2, 2, 3, 3, 3, 2, 2};
    size_t size_majority = sizeof(array_majority) / sizeof(array_majority[0]);
    int majority_element = find_majority_element(array_majority, size_majority);
    printf("\nMajority element in the array: %d\n", majority_element);

    return 0;
}

/* @brief Function to find the leaders in an array (elements greater than all elements */
/* @brief to their right) */
FOUNDATIONAL_LIB_FUNC int *find_leaders(const int *array, size_t size, size_t *leaders_size)
{
    int max_right = array[size - 1];
    int *leaders = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(size * sizeof(int));

    if (leaders == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    size_t leader_count = 0;

    /* @brief  The last element is always a leader */
    leaders[leader_count++] = max_right;

    /* @brief  Traverse the array from right to left to find leaders */
    for (int i = size - 2; i >= 0; i--)
    {
        if (array[i] > max_right)
        {
            max_right = array[i];
            leaders[leader_count++] = max_right;
        }
    }

    *leaders_size = leader_count;
    int *ret = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_REALLOC(leaders,
                                                               leader_count * sizeof(int)); // Adjust the size of the leaders array

    if (ret == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    return ret;
}

/* @brief Function to find the equilibrium index in an array */
FOUNDATIONAL_LIB_FUNC ssize_t find_equilibrium_index(const int *array, size_t size)
{
    int total_sum = 0;
    int left_sum = 0;

    /* @brief  Calculate the total sum of the array */
    for (size_t i = 0; i < size; i++)
    {
        total_sum += array[i];
    }

    /* @brief  Traverse the array to find the equilibrium index */
    for (size_t i = 0; i < size; i++)
    {
        total_sum -= array[i];

        if (left_sum == total_sum)
        {
            return i;
        }

        left_sum += array[i];
    }

    return -1; // No equilibrium index found
}

FOUNDATIONAL_LIB_FUNC int test20()
{
    /* @brief  Test find_leaders function */
    const int array_leaders[] = {16, 17, 4, 3, 5, 2};
    size_t size_leaders = sizeof(array_leaders) / sizeof(array_leaders[0]);
    size_t leaders_size;
    int *leaders = find_leaders(array_leaders, size_leaders, &leaders_size);
    printf("Leaders in the array: ");
    for (size_t i = 0; i < leaders_size; i++)
    {
        printf("%d ", leaders[i]);
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(leaders);

    /* @brief  Test find_equilibrium_index function */
    const int array_equilibrium[] = {-7, 1, 5, 2, -4, 3, 0};
    size_t size_equilibrium = sizeof(array_equilibrium) / sizeof(array_equilibrium[0]);
    ssize_t equilibrium_index = find_equilibrium_index(array_equilibrium, size_equilibrium);
    printf("\n\nEquilibrium index in the array: %zd\n", equilibrium_index);

    return 0;
}

/* @brief Function to find the longest increasing subsequence in an array */
FOUNDATIONAL_LIB_FUNC int *find_longest_increasing_subsequence(const int *array, size_t size, size_t *subsequence_size)
{
    int *lis = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(size * sizeof(int));

    if (lis == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    int *previous_index = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(size * sizeof(int));

    if (previous_index == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    size_t lis_end = 0;

    /* @brief  Initialize lis array */
    for (size_t i = 0; i < size; i++)
    {
        lis[i] = 1; // Initialize lis to 1 for each element
        previous_index[i] = -1;
    }

    for (size_t i = 1; i < size; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (array[i] > array[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
                previous_index[i] = j;
            }
        }
        if (lis[i] > lis[lis_end])
        {
            lis_end = i;
        }
    }

    /* @brief  Reconstruct the LIS */
    size_t index = lis_end;
    size_t count = 0;
    while (index != (size_t)-1)
    {
        count++;
        index = previous_index[index];
    }

    int *longest_increasing_subsequence = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(count * sizeof(int));

    if (longest_increasing_subsequence == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    index = lis_end;
    for (size_t i = count; i > 0; i--)
    {
        longest_increasing_subsequence[i - 1] = array[index];
        index = previous_index[index];
    }

    *subsequence_size = count;
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(lis);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(previous_index);
    return longest_increasing_subsequence;
}

/* @brief Function to find the maximum length bitonic subarray in an array */
FOUNDATIONAL_LIB_FUNC int find_max_length_bitonic_subarray(const int *array, size_t size, size_t *max_length)
{
    int *increasing = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(size * sizeof(int));

    if (increasing == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    int *decreasing = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(size * sizeof(int));

    if (decreasing == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    increasing[0] = 1;
    decreasing[size - 1] = 1;

    /* @brief  Calculate the length of the increasing subarray ending at each position */
    for (size_t i = 1; i < size; i++)
    {
        increasing[i] = (array[i] > array[i - 1]) ? increasing[i - 1] + 1 : 1;
    }

    /* @brief  Calculate the length of the decreasing subarray starting at each position */
    for (size_t i = size - 2;; i--)
    {
        decreasing[i] = (array[i] > array[i + 1]) ? decreasing[i + 1] + 1 : 1;

        if (!i)
            break;
    }

    *max_length = 1;

    /* @brief  Find the maximum length bitonic subarray */
    for (size_t i = 0; i < size; i++)
    {
        size_t length = increasing[i] + decreasing[i] - 1;
        if (length > *max_length)
        {
            *max_length = length;
        }
    }

    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(increasing);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(decreasing);
    return 0;
}

FOUNDATIONAL_LIB_FUNC int test21()
{
    /* @brief  Test find_longest_increasing_subsequence function */
    const int array_lis[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    size_t size_lis = sizeof(array_lis) / sizeof(array_lis[0]);
    size_t lis_size;
    int *lis = find_longest_increasing_subsequence(array_lis, size_lis, &lis_size);
    printf("Longest increasing subsequence: ");
    for (size_t i = 0; i < lis_size; i++)
    {
        printf("%d ", lis[i]);
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(lis);

    /* @brief  Test find_max_length_bitonic_subarray function */
    const int array_bitonic[] = {12, 4, 78, 90, 45, 23};
    size_t size_bitonic = sizeof(array_bitonic) / sizeof(array_bitonic[0]);
    size_t max_length_bitonic;

    find_max_length_bitonic_subarray(array_bitonic, size_bitonic, &max_length_bitonic);
    printf("\n\nMaximum length bitonic subarray: %zu\n", max_length_bitonic);

    return 0;
}

/* @brief Function to generate a range of integers */
FOUNDATIONAL_LIB_FUNC int *generate_range(int start, int end, int step, size_t *range_size)
{
    if (start > end || step == 0)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    size_t size = (end - start) / step + 1;
    int *range = (int *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(size * sizeof(int));

    if (range == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    for (size_t i = 0, value = start; i < size; i++, value += step)
    {
        range[i] = value;
    }

    *range_size = size;
    return range;
}
FOUNDATIONAL_LIB_FUNC int test24()
{
    /* @brief  Test the new utility functions */
    const int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    size_t size = sizeof(array) / sizeof(array[0]);

    /* @brief  Print array */
    printf("Array: ");
    print_int_array(array, size);

    /* @brief  Generate a range of integers */
    size_t range_size;
    int *generated_range = generate_range(1, 10, 2, &range_size);
    printf("\nGenerated Range: ");
    print_int_array(generated_range, range_size);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(generated_range);

    return 0;
}

FOUNDATIONAL_LIB_FUNC int cmpstringp(const void *p1, const void *p2) { return strcmp(*(const char **)p1, *(const char **)p2); }

FOUNDATIONAL_LIB_FUNC void sort_strings(char **strings, size_t size) { qsort(strings, size, sizeof(char *), cmpstringp); }

FOUNDATIONAL_LIB_FUNC char **sorted_strings(char **strings, size_t size)
{
    char **dup = (char **)array_dup(strings, size, sizeof(char *));
    qsort(dup, size, sizeof(char *), cmpstringp);
    return dup;
}
FOUNDATIONAL_LIB_FUNC int cmp_uints(const void *a, const void *b) { return (*(unsigned int *)a - *(unsigned int *)b); }
FOUNDATIONAL_LIB_FUNC void sort_uints(unsigned int *uints, size_t size) { qsort(uints, size, sizeof(unsigned int), cmp_uints); }
FOUNDATIONAL_LIB_FUNC unsigned int *sorted_uints(unsigned int *uints, size_t size)
{
    unsigned int *dup_uints = (unsigned int *)duparray(uints, size, sizeof(unsigned int));
    qsort(uints, size, sizeof(unsigned int), cmp_uints);
    return dup_uints;
}

FOUNDATIONAL_LIB_FUNC int cmp_uint_ptrs(const void *a, const void *b) { return (*(unsigned int **)a - *(unsigned int **)b); }
FOUNDATIONAL_LIB_FUNC void sort_uint_ptrs(unsigned int **uint_ptrs, size_t size) { qsort(uint_ptrs, size, sizeof(unsigned int *), cmp_uint_ptrs); }
FOUNDATIONAL_LIB_FUNC unsigned int **sorted_uint_ptrs(unsigned int **uint_ptrs, size_t size)
{
    unsigned int **dup_uint_ptrs = (unsigned int **)duparray(uint_ptrs, size, sizeof(unsigned int *));
    qsort(uint_ptrs, size, sizeof(unsigned int *), cmp_uint_ptrs);
    return dup_uint_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_ints(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
FOUNDATIONAL_LIB_FUNC void sort_ints(int *ints, size_t size) { qsort(ints, size, sizeof(int), cmp_ints); }
FOUNDATIONAL_LIB_FUNC int *sorted_ints(int *ints, size_t size)
{
    int *dup_ints = (int *)duparray(ints, size, sizeof(int));
    qsort(ints, size, sizeof(int), cmp_ints);
    return dup_ints;
}

FOUNDATIONAL_LIB_FUNC int cmp_int_ptrs(const void *a, const void *b) { return (*(int **)a - *(int **)b); }
FOUNDATIONAL_LIB_FUNC void sort_int_ptrs(int **int_ptrs, size_t size) { qsort(int_ptrs, size, sizeof(int *), cmp_int_ptrs); }
FOUNDATIONAL_LIB_FUNC int **sorted_int_ptrs(int **int_ptrs, size_t size)
{
    int **dup_int_ptrs = (int **)duparray(int_ptrs, size, sizeof(int *));
    qsort(int_ptrs, size, sizeof(int *), cmp_int_ptrs);
    return dup_int_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_uchars(const void *a, const void *b) { return (*(unsigned char *)a - *(unsigned char *)b); }
FOUNDATIONAL_LIB_FUNC void sort_uchars(unsigned char *uchars, size_t size) { qsort(uchars, size, sizeof(unsigned char), cmp_uchars); }
FOUNDATIONAL_LIB_FUNC unsigned char *sorted_uchars(unsigned char *uchars, size_t size)
{
    unsigned char *dup_uchars = (unsigned char *)duparray(uchars, size, sizeof(unsigned char));
    qsort(uchars, size, sizeof(unsigned char), cmp_uchars);
    return dup_uchars;
}

FOUNDATIONAL_LIB_FUNC int cmp_uchar_ptrs(const void *a, const void *b) { return (*(unsigned char **)a - *(unsigned char **)b); }
FOUNDATIONAL_LIB_FUNC void sort_uchar_ptrs(unsigned char **uchar_ptrs, size_t size) { qsort(uchar_ptrs, size, sizeof(unsigned char *), cmp_uchar_ptrs); }
FOUNDATIONAL_LIB_FUNC unsigned char **sorted_uchar_ptrs(unsigned char **uchar_ptrs, size_t size)
{
    unsigned char **dup_uchar_ptrs = (unsigned char **)duparray(uchar_ptrs, size, sizeof(unsigned char *));
    qsort(uchar_ptrs, size, sizeof(unsigned char *), cmp_uchar_ptrs);
    return dup_uchar_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_chars(const void *a, const void *b) { return (*(char *)a - *(char *)b); }
FOUNDATIONAL_LIB_FUNC void sort_chars(char *chars, size_t size) { qsort(chars, size, sizeof(char), cmp_chars); }
FOUNDATIONAL_LIB_FUNC char *sorted_chars(char *chars, size_t size)
{
    char *dup_chars = (char *)duparray(chars, size, sizeof(char));
    qsort(chars, size, sizeof(char), cmp_chars);
    return dup_chars;
}

FOUNDATIONAL_LIB_FUNC int cmp_char_ptrs(const void *a, const void *b) { return (*(char **)a - *(char **)b); }
FOUNDATIONAL_LIB_FUNC void sort_char_ptrs(char **char_ptrs, size_t size) { qsort(char_ptrs, size, sizeof(char *), cmp_char_ptrs); }
FOUNDATIONAL_LIB_FUNC char **sorted_char_ptrs(char **char_ptrs, size_t size)
{
    char **dup_char_ptrs = (char **)duparray(char_ptrs, size, sizeof(char *));
    qsort(char_ptrs, size, sizeof(char *), cmp_char_ptrs);
    return dup_char_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_ushorts(const void *a, const void *b) { return (*(unsigned short *)a - *(unsigned short *)b); }
FOUNDATIONAL_LIB_FUNC void sort_ushorts(unsigned short *ushorts, size_t size) { qsort(ushorts, size, sizeof(unsigned short), cmp_ushorts); }
FOUNDATIONAL_LIB_FUNC unsigned short *sorted_ushorts(unsigned short *ushorts, size_t size)
{
    unsigned short *dup_ushorts = (unsigned short *)duparray(ushorts, size, sizeof(unsigned short));
    qsort(ushorts, size, sizeof(unsigned short), cmp_ushorts);
    return dup_ushorts;
}

FOUNDATIONAL_LIB_FUNC int cmp_ushort_ptrs(const void *a, const void *b) { return (*(unsigned short **)a - *(unsigned short **)b); }
FOUNDATIONAL_LIB_FUNC void sort_ushort_ptrs(unsigned short **ushort_ptrs, size_t size) { qsort(ushort_ptrs, size, sizeof(unsigned short *), cmp_ushort_ptrs); }
FOUNDATIONAL_LIB_FUNC unsigned short **sorted_ushort_ptrs(unsigned short **ushort_ptrs, size_t size)
{
    unsigned short **dup_ushort_ptrs = (unsigned short **)duparray(ushort_ptrs, size, sizeof(unsigned short *));
    qsort(ushort_ptrs, size, sizeof(unsigned short *), cmp_ushort_ptrs);
    return dup_ushort_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_shorts(const void *a, const void *b) { return (*(short *)a - *(short *)b); }
FOUNDATIONAL_LIB_FUNC void sort_shorts(short *shorts, size_t size) { qsort(shorts, size, sizeof(short), cmp_shorts); }
FOUNDATIONAL_LIB_FUNC short *sorted_shorts(short *shorts, size_t size)
{
    short *dup_shorts = (short *)duparray(shorts, size, sizeof(short));
    qsort(shorts, size, sizeof(short), cmp_shorts);
    return dup_shorts;
}

FOUNDATIONAL_LIB_FUNC int cmp_short_ptrs(const void *a, const void *b) { return (*(short **)a - *(short **)b); }
FOUNDATIONAL_LIB_FUNC void sort_short_ptrs(short **short_ptrs, size_t size) { qsort(short_ptrs, size, sizeof(short *), cmp_short_ptrs); }
FOUNDATIONAL_LIB_FUNC short **sorted_short_ptrs(short **short_ptrs, size_t size)
{
    short **dup_short_ptrs = (short **)duparray(short_ptrs, size, sizeof(short *));
    qsort(short_ptrs, size, sizeof(short *), cmp_short_ptrs);
    return dup_short_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_ulongs(const void *a, const void *b) { return (*(unsigned long *)a - *(unsigned long *)b); }
FOUNDATIONAL_LIB_FUNC void sort_ulongs(unsigned long *ulongs, size_t size) { qsort(ulongs, size, sizeof(unsigned long), cmp_ulongs); }
FOUNDATIONAL_LIB_FUNC unsigned long *sorted_ulongs(unsigned long *ulongs, size_t size)
{
    unsigned long *dup_ulongs = (unsigned long *)duparray(ulongs, size, sizeof(unsigned long));
    qsort(ulongs, size, sizeof(unsigned long), cmp_ulongs);
    return dup_ulongs;
}

FOUNDATIONAL_LIB_FUNC int cmp_ulong_ptrs(const void *a, const void *b) { return (*(unsigned long **)a - *(unsigned long **)b); }
FOUNDATIONAL_LIB_FUNC void sort_ulong_ptrs(unsigned long **ulong_ptrs, size_t size) { qsort(ulong_ptrs, size, sizeof(unsigned long *), cmp_ulong_ptrs); }
FOUNDATIONAL_LIB_FUNC unsigned long **sorted_ulong_ptrs(unsigned long **ulong_ptrs, size_t size)
{
    unsigned long **dup_ulong_ptrs = (unsigned long **)duparray(ulong_ptrs, size, sizeof(unsigned long *));
    qsort(ulong_ptrs, size, sizeof(unsigned long *), cmp_ulong_ptrs);
    return dup_ulong_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_longs(const void *a, const void *b) { return (*(long *)a - *(long *)b); }
FOUNDATIONAL_LIB_FUNC void sort_longs(long *longs, size_t size) { qsort(longs, size, sizeof(long), cmp_longs); }
FOUNDATIONAL_LIB_FUNC long *sorted_longs(long *longs, size_t size)
{
    long *dup_longs = (long *)duparray(longs, size, sizeof(long));
    qsort(longs, size, sizeof(long), cmp_longs);
    return dup_longs;
}

FOUNDATIONAL_LIB_FUNC int cmp_long_ptrs(const void *a, const void *b) { return (*(long **)a - *(long **)b); }
FOUNDATIONAL_LIB_FUNC void sort_long_ptrs(long **long_ptrs, size_t size) { qsort(long_ptrs, size, sizeof(long *), cmp_long_ptrs); }
FOUNDATIONAL_LIB_FUNC long **sorted_long_ptrs(long **long_ptrs, size_t size)
{
    long **dup_long_ptrs = (long **)duparray(long_ptrs, size, sizeof(long *));
    qsort(long_ptrs, size, sizeof(long *), cmp_long_ptrs);
    return dup_long_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_ulong_longs(const void *a, const void *b) { return (*(unsigned long long *)a - *(unsigned long long *)b); }
FOUNDATIONAL_LIB_FUNC void sort_ulong_longs(unsigned long long *ulong_longs, size_t size) { qsort(ulong_longs, size, sizeof(unsigned long long), cmp_ulong_longs); }
FOUNDATIONAL_LIB_FUNC unsigned long long *sorted_ulong_longs(unsigned long long *ulong_longs, size_t size)
{
    unsigned long long *dup_ulong_longs = (unsigned long long *)duparray(ulong_longs, size, sizeof(unsigned long long));
    qsort(ulong_longs, size, sizeof(unsigned long long), cmp_ulong_longs);
    return dup_ulong_longs;
}

FOUNDATIONAL_LIB_FUNC int cmp_ulong_long_ptrs(const void *a, const void *b) { return (*(unsigned long long **)a - *(unsigned long long **)b); }
FOUNDATIONAL_LIB_FUNC void sort_ulong_long_ptrs(unsigned long long **ulong_long_ptrs, size_t size) { qsort(ulong_long_ptrs, size, sizeof(unsigned long long *), cmp_ulong_long_ptrs); }
FOUNDATIONAL_LIB_FUNC unsigned long long **sorted_ulong_long_ptrs(unsigned long long **ulong_long_ptrs, size_t size)
{
    unsigned long long **dup_ulong_long_ptrs = (unsigned long long **)duparray(ulong_long_ptrs, size, sizeof(unsigned long long *));
    qsort(ulong_long_ptrs, size, sizeof(unsigned long long *), cmp_ulong_long_ptrs);
    return dup_ulong_long_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_long_longs(const void *a, const void *b) { return (*(long long *)a - *(long long *)b); }
FOUNDATIONAL_LIB_FUNC void sort_long_longs(long long *long_longs, size_t size) { qsort(long_longs, size, sizeof(long long), cmp_long_longs); }
FOUNDATIONAL_LIB_FUNC long long *sorted_long_longs(long long *long_longs, size_t size)
{
    long long *dup_long_longs = (long long *)duparray(long_longs, size, sizeof(long long));
    qsort(long_longs, size, sizeof(long long), cmp_long_longs);
    return dup_long_longs;
}

FOUNDATIONAL_LIB_FUNC int cmp_long_long_ptrs(const void *a, const void *b) { return (*(long long **)a - *(long long **)b); }
FOUNDATIONAL_LIB_FUNC void sort_long_long_ptrs(long long **long_long_ptrs, size_t size) { qsort(long_long_ptrs, size, sizeof(long long *), cmp_long_long_ptrs); }
FOUNDATIONAL_LIB_FUNC long long **sorted_long_long_ptrs(long long **long_long_ptrs, size_t size)
{
    long long **dup_long_long_ptrs = (long long **)duparray(long_long_ptrs, size, sizeof(long long *));
    qsort(long_long_ptrs, size, sizeof(long long *), cmp_long_long_ptrs);
    return dup_long_long_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_floats(const void *a, const void *b) { return (*(float *)a - *(float *)b); }
FOUNDATIONAL_LIB_FUNC void sort_floats(float *floats, size_t size) { qsort(floats, size, sizeof(float), cmp_floats); }
FOUNDATIONAL_LIB_FUNC float *sorted_floats(float *floats, size_t size)
{
    float *dup_floats = (float *)duparray(floats, size, sizeof(float));
    qsort(floats, size, sizeof(float), cmp_floats);
    return dup_floats;
}

FOUNDATIONAL_LIB_FUNC int cmp_float_ptrs(const void *a, const void *b) { return (*(float **)a - *(float **)b); }
FOUNDATIONAL_LIB_FUNC void sort_float_ptrs(float **float_ptrs, size_t size) { qsort(float_ptrs, size, sizeof(float *), cmp_float_ptrs); }
FOUNDATIONAL_LIB_FUNC float **sorted_float_ptrs(float **float_ptrs, size_t size)
{
    float **dup_float_ptrs = (float **)duparray(float_ptrs, size, sizeof(float *));
    qsort(float_ptrs, size, sizeof(float *), cmp_float_ptrs);
    return dup_float_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_doubles(const void *a, const void *b) { return (*(double *)a - *(double *)b); }
FOUNDATIONAL_LIB_FUNC void sort_doubles(double *doubles, size_t size) { qsort(doubles, size, sizeof(double), cmp_doubles); }
FOUNDATIONAL_LIB_FUNC double *sorted_doubles(double *doubles, size_t size)
{
    double *dup_doubles = (double *)duparray(doubles, size, sizeof(double));
    qsort(doubles, size, sizeof(double), cmp_doubles);
    return dup_doubles;
}

FOUNDATIONAL_LIB_FUNC int cmp_double_ptrs(const void *a, const void *b) { return (*(double **)a - *(double **)b); }
FOUNDATIONAL_LIB_FUNC void sort_double_ptrs(double **double_ptrs, size_t size) { qsort(double_ptrs, size, sizeof(double *), cmp_double_ptrs); }
FOUNDATIONAL_LIB_FUNC double **sorted_double_ptrs(double **double_ptrs, size_t size)
{
    double **dup_double_ptrs = (double **)duparray(double_ptrs, size, sizeof(double *));
    qsort(double_ptrs, size, sizeof(double *), cmp_double_ptrs);
    return dup_double_ptrs;
}

FOUNDATIONAL_LIB_FUNC int cmp_size_ts(const void *a, const void *b) { return (*(size_t *)a - *(size_t *)b); }
FOUNDATIONAL_LIB_FUNC void sort_size_ts(size_t *size_ts, size_t size) { qsort(size_ts, size, sizeof(size_t), cmp_size_ts); }
FOUNDATIONAL_LIB_FUNC size_t *sorted_size_ts(size_t *size_ts, size_t size)
{
    size_t *dup_size_ts = (size_t *)duparray(size_ts, size, sizeof(size_t));
    qsort(size_ts, size, sizeof(size_t), cmp_size_ts);
    return dup_size_ts;
}

FOUNDATIONAL_LIB_FUNC int cmp_size_t_ptrs(const void *a, const void *b) { return (*(size_t **)a - *(size_t **)b); }
FOUNDATIONAL_LIB_FUNC void sort_size_t_ptrs(size_t **size_t_ptrs, size_t size) { qsort(size_t_ptrs, size, sizeof(size_t *), cmp_size_t_ptrs); }
FOUNDATIONAL_LIB_FUNC size_t **sorted_size_t_ptrs(size_t **size_t_ptrs, size_t size)
{
    size_t **dup_size_t_ptrs = (size_t **)duparray(size_t_ptrs, size, sizeof(size_t *));
    qsort(size_t_ptrs, size, sizeof(size_t *), cmp_size_t_ptrs);
    return dup_size_t_ptrs;
}

FOUNDATIONAL_LIB_FUNC int test26()
{
    /* @brief  Sort an array */
    int array_to_sort[] = {5, 2, 9, 1, 5, 6};
    size_t array_size = sizeof(array_to_sort) / sizeof(array_to_sort[0]);

    printf("\nOriginal Array: ");
    for (size_t i = 0; i < array_size; i++)
    {
        printf("%d ", array_to_sort[i]);
    }

    sort_ints(array_to_sort, array_size);

    printf("\nSorted Array: ");
    for (size_t i = 0; i < array_size; i++)
    {
        printf("%d ", array_to_sort[i]);
    }

    /* @brief  Find the index of an element in an array */
    int target_element = 9;
    ssize_t index = find_index(array_to_sort, array_size, target_element);
    printf("\nIndex of %d in the array: %zd\n", target_element, index);

    return 0;
}

/* @brief Function to convert a string to an integer */
FOUNDATIONAL_LIB_FUNC int string_to_int(const char *str) { return atoi(str); }

FOUNDATIONAL_LIB_FUNC void test27()
{
    /* @brief  Convert a string to an integer */
    int converted_integer = string_to_int("121212");
    printf("Converted string to integer: %d\n", converted_integer);
}

#ifdef _WIN32
#define fseeko _fseeki64
#define ftello _ftelli64
#endif

FOUNDATIONAL_LIB_FUNC char *read_file_into_string(const char *filename, size_t *size)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        die_aggressively_if_enabled();
        return NULL; // Indicate error by returning NULL
    }

    // Determine the file size
    if (fseeko(file, 0, SEEK_END) != 0)
    {
        fclose(file);
        die_aggressively_if_enabled();
        return NULL;
    }

    off_t file_size = ftello(file);
    if (file_size == -1)
    {
        fclose(file);
        die_aggressively_if_enabled();
        return NULL;
    }

    // Set the size if the pointer is provided
    if (size != NULL)
    {
        *size = (size_t)file_size;
    }

    // Allocate memory for the file contents
    char *content = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(file_size + 1);
    if (content == NULL)
    {
        fclose(file);
        die_aggressively_if_enabled();
        return NULL;
    }

    // Read the file contents into the string
    size_t total_read = 0;
    const size_t file_size_size_t = (size_t)file_size;
    while (total_read < file_size_size_t)
    {
        size_t read_size = fread(content + total_read, 1, file_size - total_read, file);
        int error_code = ferror(file);

        if (read_size == 0)
        {
            if (error_code)
            {
                FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(content);
                fclose(file); // Don't need to error check here because things are going wrong.
                die_aggressively_if_enabled();
                return NULL;
            }
            else
            {
                break;
            }
        }
        total_read += read_size;
    }

    // Null-terminate the string
    content[total_read] = '\0';

    // Close the file
    if (fclose(file) != 0)
    {
        FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(content);
        die_aggressively_if_enabled();
        return NULL;
    }

    return content;
}

/* @brief Function to write a string to a file */
FOUNDATIONAL_LIB_FUNC int /* @brief error = -1, no error = 0 */ write_file(const char *filename, const char *content)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    /* @brief  Write the string to the file */
    size_t write_size;
    size_t total_written = 0;
    size_t content_length = strlen(content);
    while ((write_size = fwrite(content + total_written, 1, content_length - total_written, file)) > 0)
    {
        total_written += write_size;
    }

    // Close the file
    if (fclose(file) != 0)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    return 0;
}

FOUNDATIONAL_LIB_FUNC int test28()
{
    /* @brief  Test the file I/O functions */
    const char *filename = "ex_ample.txt";

    /* @brief  Write a string to a file */
    const char *content_to_write = "Hello, File I/O!";
    write_file(filename, content_to_write);
    printf("Content written to '%s':\n%s\n", filename, content_to_write);

    /* @brief  Read the entire contents of a file into a string */
    size_t string_size;
    char *content_read = read_file_into_string(filename, &string_size);
    printf("\nContent read from '%s':\n'%s'\n", filename, content_read);

    /* @brief  Free memory */
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(content_read);

    return 0;
}

/* @brief Function to append a string to a file */
FOUNDATIONAL_LIB_FUNC int append_data_to_file(const char *filename, const char *content, size_t content_size)
{
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    /* @brief  Append the string to the file */
    size_t write_size = fwrite(content, 1, content_size, file);
    if (write_size != content_size)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    /* @brief  Close the file */
    fclose(file);
    return 0;
}

#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#include <sys/stat.h>

FOUNDATIONAL_LIB_FUNC int file_exists(const char *filename)
{
#ifdef _WIN32
    return _access(filename, 0) == 0;
#else
    return access(filename, F_OK) == 0;
#endif
}

FOUNDATIONAL_LIB_FUNC int file_is_regular(const char *filename)
{
    struct stat st;
#ifdef _WIN32
    if (stat(filename, &st) == 0)
        return (st.st_mode & _S_IFREG) != 0;
#else
    if (stat(filename, &st) == 0)
        return S_ISREG(st.st_mode);
#endif
    return 0;
}

FOUNDATIONAL_LIB_FUNC int file_is_directory(const char *filename)
{
    struct stat st;
#ifdef _WIN32
    if (stat(filename, &st) == 0)
        return (st.st_mode & _S_IFDIR) != 0;
#else
    if (stat(filename, &st) == 0)
        return S_ISDIR(st.st_mode);
#endif
    return 0;
}

FOUNDATIONAL_LIB_FUNC int file_is_readable(const char *filename)
{
#ifdef _WIN32
    return _access(filename, 4) == 0; // 4 is for read permission on Windows
#else
    return access(filename, R_OK) == 0; // R_OK is for read permission on POSIX systems
#endif
}

FOUNDATIONAL_LIB_FUNC int file_is_writable(const char *filename)
{
#ifdef _WIN32
    return _access(filename, 2) == 0; // 2 is for write permission on Windows
#else
    return access(filename, W_OK) == 0; // W_OK is for write permission on POSIX systems
#endif
}

FOUNDATIONAL_LIB_FUNC int file_is_executable(const char *filename)
{
#ifdef _WIN32
    return _access(filename, 1) == 0; // 1 is for execute permission on Windows
#else
    return access(filename, X_OK) == 0; // X_OK is for execute permission on POSIX systems
#endif
}

FOUNDATIONAL_LIB_FUNC int test29()
{
    /* @brief  Test the new file I/O functions */
    const char *existing_filename = "existing_file.txt";
    const char *non_existing_filename = "non_existing_file.txt";

    /* @brief  Check if a file exists */
    printf("Does file '%s' exist? %s\n", existing_filename, file_exists(existing_filename) ? "Yes" : "No");
    printf("Does file '%s' exist? %s\n", non_existing_filename, file_exists(non_existing_filename) ? "Yes" : "No");

    /* @brief  Append a string to an existing file */
    const char *content_to_append = "\nThis line is appended!";
    append_data_to_file(existing_filename, content_to_append, strlen(content_to_append));
    printf("\nContent appended to '%s':\n%s\n", existing_filename, content_to_append);

    return 0;
}

/**
 * @brief Function to get the size of a file
 * @return -1 on error, 0 on no error
 */
FOUNDATIONAL_LIB_FUNC int get_file_size(const char *filename, size_t *size)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    // Determine the file size
    if (fseeko(file, 0, SEEK_END) != 0)
    {
        fclose(file);
        die_aggressively_if_enabled();
        return -1;
    }

    off_t file_size = ftello(file);
    if (file_size == -1)
    {
        fclose(file);
        die_aggressively_if_enabled();
        return -1;
    }

    // Close the file
    if (fclose(file) != 0)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    *size = file_size;
    return 0;
}

/* @brief Function to read a specific number of bytes from a file */
FOUNDATIONAL_LIB_FUNC char *read_bytes_from_file(const char *filename, size_t num_bytes)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    /* @brief  Allocate memory for the specified number of bytes */
    char *content = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(num_bytes + 1);
    if (content == NULL)
    {
        return NULL;
    }

    /* @brief  Read the specified number of bytes from the file */
    size_t total_read = 0;
    size_t read_size;
    while ((read_size = fread(content + total_read, 1, num_bytes - total_read, file)) > 0)
    {
        total_read += read_size;
        if (total_read >= num_bytes)
        {
            break; // Stop reading if we've reached the specified number of bytes
        }
    }

    /* @brief  Null-terminate the string */
    content[total_read] = '\0';

    /* @brief  Close the file */
    if (fclose(file) != 0)
    {
        FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(content);
        die_aggressively_if_enabled();
        return NULL;
    }

    return content;
}

FOUNDATIONAL_LIB_FUNC int test30()
{
    /* @brief  Test the new file I/O functions */
    const char *filename_for_size = "ex_ample.txt";
    size_t size;

    /* @brief  Get the size of a file */
    int error = get_file_size(filename_for_size, &size);
    if (error == -1)
    {
        test_foundationallib_test_error_handler("Error: Cannot get file size");
    }
    printf("Size of file '%s': %ld bytes\n", filename_for_size, size);

    /* @brief  Read a specific number of bytes from a file */
    size_t bytes_to_read = 15;
    char *bytes_read = read_bytes_from_file(filename_for_size, bytes_to_read);
    printf("\nFirst %zu bytes read from '%s':\n%s\n", bytes_to_read, filename_for_size, bytes_read);

    /* @brief  Free memory */
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(bytes_read);

    return 0;
}

/* @brief Function to remove a file
@return -1 on error, 0 on no error */
FOUNDATIONAL_LIB_FUNC int remove_file(const char *filename)
{
    if (remove(filename) != 0)
    {
        die_aggressively_if_enabled();
        return -1;
    }
    return 0;
}

FOUNDATIONAL_LIB_FUNC int test31()
{
    /* @brief  Test the new file-related functions */
    const char *file_to_remove = "file_to_remove.txt";

    /* @brief  Create a file to be removed */
    FILE *file_to_remove_ptr = fopen(file_to_remove, "w");
    if (file_to_remove_ptr == NULL)
    {
        test_foundationallib_test_error_handler("Error: Unable to create file");
    }
    fprintf(file_to_remove_ptr, "This file will be removed.");
    fclose(file_to_remove_ptr);

    printf("\nFile '%s' created.\n", file_to_remove);

    /* @brief  Remove the file */
    remove_file(file_to_remove);

    return 0;
}

FOUNDATIONAL_LIB_FUNC int /* @brief success? */ copy_file(const char *source_filename, const char *destination_filename)
{
    FILE *source_file = fopen(source_filename, "rb");
    if (source_file == NULL)
    {
        return -1;
    }

    FILE *destination_file = fopen(destination_filename, "wb");
    if (destination_file == NULL)
    {
        fclose(source_file);
        return -1;
    }

    char buffer[1024];
    size_t read_size;
    size_t write_size;

    while ((read_size = fread(buffer, 1, sizeof(buffer), source_file)) > 0)
    {
        // Handle interrupted system calls
        do
        {
            write_size = fwrite(buffer, 1, read_size, destination_file);
        } while (write_size < read_size && errno == EINTR);

        if (write_size != read_size)
        {
            fclose(source_file);
            fclose(destination_file);
            return -1;
        }
    }

    if (ferror(source_file) != 0)
    {
        fclose(source_file);
        fclose(destination_file);
        return -1;
    }

    if (fclose(source_file) != 0 || fclose(destination_file) != 0)
    {
        return -1;
    }

    return 0;
}
FOUNDATIONAL_LIB_FUNC int test32()
{
    /* @brief  Test the new file I/O functions */
    const char *source_file_to_copy = "source_file.txt";
    const char *destination_file_copy = "destination_file.txt";

    /* @brief  Copy the contents of one file to another */
    FILE *source_file_ptr = fopen(source_file_to_copy, "w");
    if (source_file_ptr == NULL)
    {
        test_foundationallib_test_error_handler("Error: Unable to create source file");
    }
    fprintf(source_file_ptr, "This is the source file content.");
    fclose(source_file_ptr);

    printf("Source file '%s' created.\n", source_file_to_copy);

    copy_file(source_file_to_copy, destination_file_copy);

    return 0;
}

#ifdef _WIN32
#include <windows.h>

/* @brief Function to list files in a directory using wildcard pattern on Windows */
FOUNDATIONAL_LIB_FUNC char **list_files_with_pattern(const char *directory, const char *pattern, size_t *len)
{
    char search_path[MAX_PATH];
    snprintf(search_path, MAX_PATH, "%s\\%s", directory, pattern);

    WIN32_FIND_DATA find_file_data;
    HANDLE find_handle = FindFirstFile(search_path, &find_file_data);

    if (find_handle == INVALID_HANDLE_VALUE)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    /* @brief  Count the number of files matching the pattern */
    int file_count = 0;
    do
    {
        if (!(find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            file_count++;
        }
    } while (FindNextFile(find_handle, &find_file_data) != 0);

    /* @brief  Allocate memory for the array of strings */
    char **files_array = (char **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC((file_count) * sizeof(char *));
    if (files_array == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    /* @brief  Populate the array with file names matching the pattern */
    int index = 0;
    FindClose(find_handle);
    find_handle = FindFirstFile(search_path, &find_file_data);
    do
    {
        if (!(find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            files_array[index] = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(find_file_data.cFileName);
            if (files_array[index] == NULL)
            {
                return NULL;
            }
            index++;
        }
    } while (FindNextFile(find_handle, &find_file_data) != 0);

    /* @brief  Close the find handle */
    FindClose(find_handle);

    *len = index;

    return files_array;
}

#else

/* @brief Function to list files in a directory using wildcard pattern on POSIX systems */
#include <dirent.h>
#include <fnmatch.h>

FOUNDATIONAL_LIB_FUNC char **list_files_with_pattern(const char *directory, const char *pattern, size_t *len)
{
    DIR *dir = opendir(directory);
    if (dir == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    /* @brief  Count the number of files matching the pattern */
    int file_count = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (fnmatch(pattern, entry->d_name, FNM_PERIOD) == 0)
        {
            file_count++;
        }
    }

    rewinddir(dir); // No errors with this function

    /* @brief  Allocate memory for the array of strings */
    char **files_array = (char **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC((file_count) * sizeof(char *));
    if (files_array == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    /* @brief  Populate the array with file names matching the pattern */
    size_t index = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (fnmatch(pattern, entry->d_name, FNM_PERIOD) == 0)
        {
            files_array[index] = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(entry->d_name);
            if (files_array[index] == NULL)
            {
                die_aggressively_if_enabled();
                return NULL;
            }
            index++;
        }
    }
    if (closedir(dir) == -1)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    *len = index;

    return files_array;
}

#endif

FOUNDATIONAL_LIB_FUNC int test33()
{
    /* @brief  Test the new function with preprocessor directives */
    const char *directory_path = "."; // Current directory
    const char *pattern = "*.txt";

    size_t len;
    char **files_array = list_files_with_pattern(directory_path, pattern, &len);

    /* @brief  Print the files in the array */
    printf("Files matching pattern '%s' in directory '%s' (length is %ld):\n", pattern, directory_path, len);
    for (size_t i = 0; i < len; i++)
    {
        printf("%s\n", files_array[i]);
    }

    /* @brief  Free memory allocated for the array */
    free_array((void **)files_array, len);

    return 0;
}

/* @brief Function to find the first non-repeating character in a string */
FOUNDATIONAL_LIB_FUNC char first_non_repeating_char(const char *str)
{
    int char_count[256] = {0}; // Assuming ASCII characters

    /* @brief  Count occurrences of each character */
    for (size_t i = 0; i < strlen(str); i++)
    {
        char_count[(unsigned char)str[i]]++;
    }

    /* @brief  Find the first non-repeating character */
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (char_count[(unsigned char)str[i]] == 1)
        {
            return str[i];
        }
    }

    /* @brief  If no non-repeating character is found, return a placeholder */
    return '\0';
}

FOUNDATIONAL_LIB_FUNC int test34()
{
    /* @brief  Test the niche string function */
    const char *test_str = "programming";
    printf("Original String: '%s'\n", test_str);

    /* @brief  Find the first non-repeating character */
    char non_repeating_char = first_non_repeating_char(test_str);
    if (non_repeating_char != '\0')
    {
        printf("First Non-Repeating Character: '%c'\n", non_repeating_char);
    }
    else
    {
        printf("No non-repeating character found.\n");
    }

    return 0;
}

/* @brief Function to find the majority element (element appearing more than n/2 times) */
/* @brief in an array */
FOUNDATIONAL_LIB_FUNC int majority_element(const int *arr, size_t size)
{
    int candidate = arr[0];
    int count = 1;

    /* @brief  Find a potential majority candidate */
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                candidate = arr[i];
                count = 1;
            }
        }
    }

    /* @brief  Verify if the candidate is a majority element */
    count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    if (count > (int)(size / 2))
    {
        return candidate;
    }
    else
    {
        /* @brief  If no majority element is found, return a placeholder */
        return -1;
    }
}

FOUNDATIONAL_LIB_FUNC int test35()
{
    /* @brief  Test the niche array function */
    int numbers[] = {2, 3, 2, 2, 4, 2, 5, 2};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);

    /* @brief  Find the majority element in the array */
    int majority = majority_element(numbers, array_size);
    if (majority != -1)
    {
        printf("Majority Element: %d\n", majority);
    }
    else
    {
        printf("No majority element found.\n");
    }

    return 0;
}

/* @brief Function to calculate the mean of an array of integers */
FOUNDATIONAL_LIB_FUNC double calculate_mean(const int *arr, size_t size)
{
    double sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}

/* @brief Function to calculate the median of an array of integers */
FOUNDATIONAL_LIB_FUNC double calculate_median(int *arr, size_t size)
{
    /* @brief  Sort the array (using a simple bubble sort for demonstration purposes) */
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                /* @brief  Swap elements if they are in the wrong order */
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    /* @brief  Calculate the median based on sorted array */
    if (size % 2 == 0)
    {
        /* @brief  If array size is even, return the average of the middle elements */
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
    else
    {
        /* @brief  If array size is odd, return the middle element */
        return arr[size / 2];
    }
}

/* @brief Function to calculate the mode of an array of integers */
FOUNDATIONAL_LIB_FUNC int calculate_mode(const int *arr, size_t size)
{
    /* @brief  Count occurrences of each number */
    int max_count = 0;
    int mode = arr[0];

    for (size_t i = 0; i < size; i++)
    {
        int count = 0;

        for (size_t j = 0; j < size; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }

        if (count > max_count)
        {
            max_count = count;
            mode = arr[i];
        }
    }

    return mode;
}

FOUNDATIONAL_LIB_FUNC int test36()
{
    /* @brief  Test the mean, median, and mode functions */
    int numbers[] = {3, 7, 1, 7, 5, 9, 7, 2};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);

    /* @brief  Calculate and display the mean */
    double mean = calculate_mean(numbers, array_size);
    printf("Mean: %.2f\n", mean);

    /* @brief  Calculate and display the median */
    double median = calculate_median(numbers, array_size);
    printf("Median: %.2f\n", median);

    /* @brief  Calculate and display the mode */
    int mode = calculate_mode(numbers, array_size);
    printf("Mode: %d\n", mode);

    return 0;
}

/* @brief Function to concatenate two strings */
FOUNDATIONAL_LIB_FUNC char *concatenate_strings(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(len1 + len2 + 1);
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

/* @brief Function to concatenate multiple strings */
FOUNDATIONAL_LIB_FUNC char *concatenate_multiple_strings(const char *strings[], size_t num_strings)
{
    size_t total_length = 0;

    /* @brief  Calculate the total length of the concatenated string */
    for (size_t i = 0; i < num_strings; i++)
    {
        total_length += strlen(strings[i]);
    }

    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(total_length + 1);
    if (result == NULL)
    {
        test_foundationallib_test_error_handler("Error: Memory allocation failed.\n");
        ;
    }

    /* @brief  Concatenate the strings */
    result[0] = '\0'; // Ensure the string is initially empty
    for (size_t i = 0; i < num_strings; i++)
    {
        strcat(result, strings[i]);
    }

    return result;
}

FOUNDATIONAL_LIB_FUNC int test37()
{
    /* @brief  Test the string concatenation functions */
    const char *str1 = "Hello, ";
    const char *str2 = "world!";
    const char *str3 = " How are you?";

    /* @brief  Concatenate two strings */
    char *concatenated_str = concatenate_strings(str1, str2);
    printf("Concatenated String 1: '%s'\n", concatenated_str);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(concatenated_str);

    /* @brief  Concatenate multiple strings */
    const char *strings[] = {str1, str2, str3};
    char *concatenated_multi_str = concatenate_multiple_strings(strings, sizeof(strings) / sizeof(strings[0]));
    printf("Concatenated String 2: '%s'\n", concatenated_multi_str);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(concatenated_multi_str);

    return 0;
}

/* @brief Copy a string in printf format. FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE() after */
FOUNDATIONAL_LIB_FUNC char *dup_format(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    /* @brief  Determine the length of the formatted string */
    int len = vsnprintf(NULL, 0, format, args);

    va_end(args);

    /* @brief  Allocate memory for the formatted string */
    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(len + 1);
    if (result == NULL)
    {
        test_foundationallib_test_error_handler("Error: Memory allocation failed.\n");
        ;
    }

    va_start(args, format);
    vsnprintf(result, len + 1, format, args);
    va_end(args);

    return result;
}

FOUNDATIONAL_LIB_FUNC void test38()
{
    /* @brief  Test the g_FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP_printf-like function */
    const char *name = "John";
    int age = 30;

    /* @brief  Format and duplicate the string */
    char *formatted_str = dup_format("Name: %s, Age: %d", name, age);
    printf("Formatted String: '%s'\n", formatted_str);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(formatted_str);
}

/* @brief Function similar to Python's format() using curly braces ({4}, {1}, {}, {2}, */
/* @brief etc.), note: pass arguments as strings */
FOUNDATIONAL_LIB_FUNC char *format_string(const char *format, ...)
{
    /* @brief  Initialize variable argument list */
    va_list args;
    va_start(args, format);

    /* @brief  Count the number of indices in the format string */
    int numIndices = 0;
    const char *ptr = format;
    while (*ptr)
    {
        if (*ptr == '{')
        {
            /* @brief  Check if the closing brace is present */
            const char *endPtr = strchr(ptr, '}');
            if (endPtr)
            {
                numIndices++;
                ptr = endPtr + 1; // Move to the character after closing brace
            }
            else
            {
                /* @brief  Error: Missing closing brace */
                va_end(args);
                die_aggressively_if_enabled();
                return NULL;
            }
        }
        else
        {
            ptr++;
        }
    }

    /* @brief  Create a dynamic array to store variable arguments */
    char **argArray = (char **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(numIndices * sizeof(char *));
    if (argArray == NULL)
    {
        /* @brief  Error: Memory allocation failed */
        va_end(args);
        die_aggressively_if_enabled();
        return NULL;
    }

    /* @brief  Populate the dynamic array with variable arguments */
    for (int i = 0; i < numIndices; i++)
    {
        argArray[i] = va_arg(args, char *);
    }

    /* @brief  Close the variable argument list */
    va_end(args);

    /* @brief  Interpolate the format string */
    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(1); // Start with an empty string

    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }
    result[0] = '\0';

    int last_index = 0;

    ptr = format;
    while (*ptr)
    {
        if (*ptr == '{')
        {
            const char *endPtr = strchr(ptr, '}');
            if (endPtr)
            {
                int index;

                if (endPtr == ptr + 1)
                {
                    index = last_index;
                    if (last_index < numIndices)
                        ++last_index;
                }
                else
                {
                    char indexStr[10];
                    /* @brief  Extract the index between braces */
                    strncpy(indexStr, ptr + 1, endPtr - ptr - 1);
                    indexStr[endPtr - ptr - 1] = '\0';
                    index = atoi(indexStr);
                }

                /* @brief  Check if the index is valid */
                if (index >= 0 && index < numIndices)
                {
                    /* @brief  Concatenate the corresponding argument to the result */
                    result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_REALLOC(result, strlen(result) + strlen(argArray[index]) + 1);

                    if (result == NULL)
                    {
                        die_aggressively_if_enabled();
                        return NULL;
                    }

                    strcat(result, argArray[index]);
                }
                else
                {
                    /* @brief  Error: Invalid index */
                    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(result);
                    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(argArray);
                    die_aggressively_if_enabled();
                    return NULL;
                }

                ptr = endPtr + 1;
            }
            else
            {
                /* @brief  Error: Missing closing brace */
                FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(result);
                FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(argArray);
                die_aggressively_if_enabled();
                return NULL;
            }
        }
        else
        {
            /* @brief  Concatenate non-indexed characters to the result */
            result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_REALLOC(result, strlen(result) + 2);
            if (result == NULL)
            {
                die_aggressively_if_enabled();
                return NULL;
            }

            strncat(result, ptr, 1);
            ptr++;
        }
    }

    /* @brief  Free the dynamic array */
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(argArray);

    return result;
}

FOUNDATIONAL_LIB_FUNC int test39()
{
    /* @brief  Test the format_string function */
    const char *name = "John";
    const char *age = "30";

    char *formatted_str = format_string("Name: {0}, Age: {1}", name, age);
    printf("Formatted String Python Style: '%s'\n", formatted_str);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(formatted_str);

    return 0;
}

/* @brief Function to apply a transformation to each element of an array */
FOUNDATIONAL_LIB_FUNC void map_int(int *array, size_t size, int (*transform)(int))
{
    for (size_t i = 0; i < size; i++)
    {
        array[i] = transform(array[i]);
    }
}

FOUNDATIONAL_LIB_FUNC int test_double_value(int value) { return value * 2; }
#include <assert.h>

FOUNDATIONAL_LIB_FUNC int test40()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);

    /* @brief  Apply the transformation (map) */
    int *dup = (int *)arraydup(numbers, array_size, sizeof(numbers[0]));

    map_int(dup, array_size, test_double_value);

    int array[] = {2, 4, 6, 8, 10};
    assert(equal_int(dup, array, array_size));

    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dup);

    /* @brief  Print the result */
    printf("Mapped Int Result: ");
    for (size_t i = 0; i < array_size; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}

/* @brief Function to perform a reduction on an array */
FOUNDATIONAL_LIB_FUNC int reduce_int(int *array, size_t size, int (*operation)(int, int))
{
    int result = array[0];
    for (size_t i = 1; i < size; i++)
    {
        result = operation(result, array[i]);
    }
    return result;
}

FOUNDATIONAL_LIB_FUNC int test_sum(int a, int b) { return a + b; }

FOUNDATIONAL_LIB_FUNC void test41()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);

    /* @brief  Perform the reduction (reduce) */
    int sum_result = reduce_int(numbers, array_size, test_sum);

    /* @brief  Print the result */
    printf("Reduced Result: %d\n", sum_result);
    assert(sum_result == 15);
}

/* @brief Function to filter elements based on a condition */
FOUNDATIONAL_LIB_FUNC size_t filter_int(int *source, size_t source_size, int *destination, int (*condition)(int))
{
    size_t count = 0;
    for (size_t i = 0; i < source_size; i++)
    {
        if (condition(source[i]))
        {
            destination[count++] = source[i];
        }
    }
    return count;
}

FOUNDATIONAL_LIB_FUNC int test_is_even(int value) { return value % 2 == 0; }

FOUNDATIONAL_LIB_FUNC void test42()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);

    int filtered_numbers[array_size]; // Assuming worst case (all elements pass
                                      /* @brief  the filter) */

    /* @brief  Perform the filtering (filter) */
    int *dup = (int *)arraydup(numbers, array_size, sizeof(numbers[0]));
    size_t filtered_size = filter_int(dup, array_size, filtered_numbers, test_is_even);
    int array[] = {2, 4};
    assert(equal_int(filtered_numbers, array, sizeof(array) / sizeof(array[0])));

    /* @brief  Print the result */
    printf("Filtered Result: ");
    for (size_t i = 0; i < filtered_size; i++)
    {
        printf("%d ", filtered_numbers[i]);
    }

    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dup);
}

/* @brief Function to apply a transformation to each element of an array (void* */
/* @brief version) */
FOUNDATIONAL_LIB_FUNC void map(void *array, size_t size, size_t elem_size, void (*transform)(void *))
{
    char *char_array = (char *)array;
    for (size_t i = 0; i < size; i++)
    {
        transform(char_array + i * elem_size);
    }
}

FOUNDATIONAL_LIB_FUNC void test_double_value_void(void *value)
{
    size_t *int_value = (size_t *)value;
    *int_value *= 2;
}

FOUNDATIONAL_LIB_FUNC void test43()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);
    size_t elem_size = sizeof(numbers[0]);

    /* @brief  Apply the transformation (map) */
    map(numbers, array_size, elem_size, test_double_value_void);

    /* @brief  Print the result */
    printf("Mapped Result (2, 4, 6, 8, 10): ");
    for (size_t i = 0; i < array_size; i++)
    {
        printf("%d ", numbers[i]);
    }
}

/* @brief Function to perform a reduction on an array (void* version) */
FOUNDATIONAL_LIB_FUNC void reduce(void *array, size_t size, size_t elem_size, void *result, void (*operation)(void *, void *))
{
    char *char_array = (char *)array;
    char *char_result = (char *)result;

    /* @brief  Initialize the result with the first element */
    for (size_t i = 0; i < elem_size; i++)
    {
        char_result[i] = char_array[i];
    }

    for (size_t i = 1; i < size; i++)
    {
        operation(char_result, char_array + i * elem_size);
    }
}

FOUNDATIONAL_LIB_FUNC void test_sum_void(void *a, void *b)
{
    int *int_a = (int *)a;
    int *int_b = (int *)b;
    *int_a += *int_b;
}

FOUNDATIONAL_LIB_FUNC int test44()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);
    size_t elem_size = sizeof(numbers[0]);

    int sum_result = 0;

    /* @brief  Perform the reduction (reduce) */
    reduce(numbers, array_size, elem_size, &sum_result, test_sum_void);

    /* @brief  Print the result */
    printf("Reduced Result: %d\n", sum_result);

    return 0;
}

/* @brief Function to filter elements based on a condition (void* version) */
FOUNDATIONAL_LIB_FUNC size_t filter(void *source, size_t source_size, size_t elem_size, void *destination, size_t dest_size, int (*condition)(void *))
{
    char *char_source = (char *)source;
    char *char_destination = (char *)destination;

    size_t count = 0;
    for (size_t i = 0; i < source_size; i++)
    {
        if (condition(char_source + i * elem_size))
        {
            if (count < dest_size)
            {
                for (size_t j = 0; j < elem_size; j++)
                {
                    char_destination[count * elem_size + j] = char_source[i * elem_size + j];
                }
            }
            count++;
        }
    }
    return count;
}

FOUNDATIONAL_LIB_FUNC int test_is_greater_than_5_void(void *value)
{
    int *int_value = (int *)value;
    return ((*int_value) > 5);
}

FOUNDATIONAL_LIB_FUNC int test_is_even_void(void *value)
{
    int *int_value = (int *)value;
    return ((*int_value) % 2) == 0;
}

FOUNDATIONAL_LIB_FUNC int test45()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);
    size_t elem_size = sizeof(numbers[0]);

    int filtered_numbers[array_size]; // Assuming worst case (all elements pass
                                      /* @brief  the filter) */

    /* @brief  Perform the filtering (filter) */
    size_t filtered_size = filter(numbers, array_size, elem_size, filtered_numbers, array_size, test_is_even_void);

    /* @brief  Print the result */
    printf("Filtered Result: ");
    for (size_t i = 0; i < filtered_size; i++)
    {
        printf("%d ", filtered_numbers[i]);
    }

    return 0;
}

/* @brief Implementation of list_comprehension */
FOUNDATIONAL_LIB_FUNC void *list_comprehension(const void *input_array, size_t array_size, size_t elem_size, void (*transform_func)(void *value), int (*filter_func)(void *value), size_t *result_size)
{
    /* @brief  Allocate memory for the result array */
    void *result = FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(array_size * elem_size);
    if (result == NULL)
    {
        /* @brief  Handle memory allocation error */
        die_aggressively_if_enabled();
        return NULL;
    }

    size_t count = 0; // Number of elements in the result array

    /* @brief  Iterate through the input array */
    for (size_t i = 0; i < array_size; ++i)
    {
        /* @brief  Apply the filter function */
        if (filter_func((void *)((char *)input_array + i * elem_size)))
        {
            /* @brief  Apply the transformation function */
            transform_func((void *)((char *)input_array + i * elem_size));

            /* @brief  Copy the transformed value to the result array */
            memcpy((char *)result + count * elem_size, (char *)input_array + i * elem_size, elem_size);

            count++;
        }
    }

    /* @brief  Update the result size */
    *result_size = count;

    return result;
}

FOUNDATIONAL_LIB_FUNC void test46() {}
FOUNDATIONAL_LIB_FUNC int test47()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);
    size_t elem_size = sizeof(numbers[0]);

    size_t result_size;

    /* @brief  Apply list comprehension with doubling transformation and even number */
    /* @brief  condition */
    int *result = (int *)list_comprehension(numbers, array_size, elem_size, test_double_value_void, test_is_greater_than_5_void, &result_size);

    /* @brief  Print the result */
    printf("List Comprehension Result: ");
    for (size_t i = 0; i < result_size; i++)
    {
        printf("%d ", (result)[i]);
    }
    printf("\n");

    /* @brief  Free the allocated memory */
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(result);

    return 0;
}

/* @brief Function to reject elements based on a condition */
FOUNDATIONAL_LIB_FUNC void *reject_array(const void *source, size_t source_size, size_t elem_size, int (*condition)(const void *), size_t *result_size)
{
    /* @brief  Allocate memory for the result array */
    void *result = FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(source_size * elem_size);
    if (result == NULL)
    {
        test_foundationallib_test_error_handler("Error: Memory allocation failed in reject_array");
    }

    size_t result_index = 0;

    /* @brief  Apply the rejection condition to each element */
    for (size_t i = 0; i < source_size; i++)
    {
        const void *current_source = (char *)source + i * elem_size;

        /* @brief  Check condition */
        if (!condition(current_source))
        {
            void *current_result = (char *)result + result_index * elem_size;
            memcpy(current_result, current_source, elem_size);
            result_index++;
        }
    }

    /* @brief  Set the result size */
    *result_size = result_index;

    return result;
}

/* @brief Function to select elements based on a condition */
FOUNDATIONAL_LIB_FUNC void *select_array(const void *source, size_t source_size, size_t elem_size, int (*condition)(const void *), size_t *result_size)
{
    /* @brief  Allocate memory for the result array */
    void *result = FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(source_size * elem_size);
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    size_t result_index = 0;

    /* @brief  Apply the selection condition to each element */
    for (size_t i = 0; i < source_size; i++)
    {
        const void *current_source = (char *)source + i * elem_size;

        /* @brief  Check condition */
        if (condition(current_source))
        {
            void *current_result = (char *)result + result_index * elem_size;
            memcpy(current_result, current_source, elem_size);
            result_index++;
        }
    }

    /* @brief  Set the result size */
    *result_size = result_index;

    return result;
}

FOUNDATIONAL_LIB_FUNC int test_reject_even(const void *value)
{
    const int *int_value = (const int *)value;
    return (*int_value) % 2 != 0;
}
FOUNDATIONAL_LIB_FUNC int test_select_even(const void *value)
{
    const int *int_value = (const int *)value;
    return (*int_value) % 2 == 0;
}

FOUNDATIONAL_LIB_FUNC int test48()
{
    int numbers[] = {1, 2, 3, 4, 5};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);
    size_t elem_size = sizeof(numbers[0]);

    size_t result_size;

    /* @brief  Apply reject with condition to reject even numbers */
    int *rejected_result = (int *)reject_array(numbers, array_size, elem_size, test_reject_even, &result_size);

    /* @brief  Print the rejected result */
    printf("Reject Result: ");
    for (size_t i = 0; i < result_size; i++)
    {
        printf("%d ", (rejected_result)[i]);
    }
    printf("\n");

    /* @brief  Free the allocated memory for rejected result */
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(rejected_result);

    /* @brief  Apply select with condition to select even numbers */
    int *selected_result = (int *)select_array(numbers, array_size, elem_size, test_select_even, &result_size);

    /* @brief  Print the selected result */
    printf("Select Result: ");
    for (size_t i = 0; i < result_size; i++)
    {
        printf("%d ", (selected_result)[i]);
    }
    printf("\n");

    /* @brief  Free the allocated memory for selected result */
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(selected_result);

    return 0;
}

FOUNDATIONAL_LIB_FUNC int test_remove_even(const void *value)
{
    const int *int_value = (const int *)value;
    return (*int_value) % 2 == 0;
}

FOUNDATIONAL_LIB_FUNC int test49() { return 0; }
FOUNDATIONAL_LIB_FUNC void test_to_uppercase_chars(const char *value)
{
    const char *char_value = (const char *)value;
    printf("%c ", (*char_value >= 'a' && *char_value <= 'z') ? (*char_value - 'a' + 'A') : *char_value);
}

FOUNDATIONAL_LIB_FUNC void test50() {}

/* @brief Function to replicate an array a specified number of times */
FOUNDATIONAL_LIB_FUNC void *replicate(const void *source, size_t source_size, size_t elem_size, size_t repetitions)
{
    size_t result_total_size = elem_size * source_size * repetitions;

    /* @brief  Allocate memory for the result array */
    void *result = FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(result_total_size);
    if (result == NULL)
    {
        test_foundationallib_test_error_handler("Error: Memory allocation failed in replicate");
    }

    /* @brief  Copy the source array to the result array multiple times */
    for (size_t i = 0; i < repetitions; i++)
    {
        memcpy((char *)result + (i * elem_size * source_size), source, elem_size * source_size);
    }

    return result;
}

FOUNDATIONAL_LIB_FUNC int test51()
{
    int numbers[] = {1, 2, 3};
    size_t int_array_size = sizeof(numbers) / sizeof(numbers[0]);
    size_t int_elem_size = sizeof(numbers[0]);

    char string[] = "abc";
    size_t char_array_size = sizeof(string) - 1; // Exclude null terminator
    size_t char_elem_size = sizeof(string[0]);

    /* @brief  Replicate the integer array [1, 2, 3] ten times */
    int *replicated_int_array = (int *)replicate(numbers, int_elem_size, int_array_size, 10);
    printf("Replicated Integer Array: ");
    print_int_array(replicated_int_array, 30);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(replicated_int_array);

    /* @brief  Replicate the character array "abc" five times */
    char *replicated_char_array = (char *)replicate(string, char_elem_size, char_array_size, 5);
    printf("Replicated Character Array: ");
    print_char_array(replicated_char_array, 15);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(replicated_char_array);

    return 0;
}

FOUNDATIONAL_LIB_FUNC int test52()
{
    short short_numbers[] = {1, 2, 3};
    size_t short_array_size = sizeof(short_numbers) / sizeof(short_numbers[0]);
    size_t short_elem_size = sizeof(short_numbers[0]);

    int int_numbers[] = {1, 2, 3};
    size_t int_array_size = sizeof(int_numbers) / sizeof(int_numbers[0]);
    size_t int_elem_size = sizeof(int_numbers[0]);

    double double_numbers[] = {1.1, 2.2, 3.3};
    size_t double_array_size = sizeof(double_numbers) / sizeof(double_numbers[0]);
    size_t double_elem_size = sizeof(double_numbers[0]);

    char string[] = "abc";
    size_t char_array_size = sizeof(string) - 1; // Exclude null terminator
    size_t char_elem_size = sizeof(string[0]);

    /* @brief  Replicate the short array [1, 2, 3] five times */
    short *replicated_short_array = (short *)replicate(short_numbers, short_elem_size, short_array_size, 5);
    printf("Replicated Short Array: ");
    print_short_array(replicated_short_array, 15);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(replicated_short_array);

    /* @brief  Replicate the integer array [1, 2, 3] three times */
    int *replicated_int_array = (int *)replicate(int_numbers, int_elem_size, int_array_size, 3);
    printf("Replicated Integer Array: ");
    print_int_array(replicated_int_array, 9);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(replicated_int_array);

    /* @brief  Replicate the double array [1.1, 2.2, 3.3] two times */
    double *replicated_double_array = (double *)replicate(double_numbers, double_elem_size, double_array_size, 2);
    printf("Replicated Double Array: ");
    print_double_array(replicated_double_array, 6);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(replicated_double_array);

    /* @brief  Replicate the character array "abc" four times */
    char *replicated_char_array = (char *)replicate(string, char_elem_size, char_array_size, 4);
    printf("Replicated Character Array: ");
    print_char_array(replicated_char_array, 12);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(replicated_char_array);

    return 0;
}

/* @brief Function to check if a string is empty */
FOUNDATIONAL_LIB_FUNC int is_empty_string(const char *str) { return (str == NULL || *str == '\0'); }

/* @brief Function to convert a string to lowercase */
FOUNDATIONAL_LIB_FUNC char *string_to_lowercase(char *str)
{
    char *new_str = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(str);
    char *orig_str = new_str;
    while (*new_str)
    {
        *new_str = tolower(*new_str);
        new_str++;
    }

    return orig_str;
}

/* @brief Function to convert a string to uppercase */
FOUNDATIONAL_LIB_FUNC char *string_to_uppercase(char *str)
{
    char *new_str = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(str);
    char *orig_str = new_str;
    while (*new_str)
    {
        *new_str = toupper(*new_str);
        new_str++;
    }

    return orig_str;
}

FOUNDATIONAL_LIB_FUNC int test53()
{
    char str[] = "   Hello, World!   ";

    printf("Original String: \"%s\"\n", str);

    /* @brief  Check if the string is empty */
    printf("Is Empty: %s\n", is_empty_string(str) ? "Yes" : "No");

    /* @brief  Convert the string to lowercase */
    char *new_str = string_to_lowercase(str);
    printf("To Lowercase: \"%s\"\n", new_str);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(new_str);

    /* @brief  Convert the string to uppercase */
    new_str = string_to_uppercase(str);
    printf("To Uppercase: \"%s\"\n", new_str);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(new_str);

    /* @brief  Check if the string starts with a prefix */
    printf("Starts With \"Hello\": %s\n", starts_with(str, "Hello") ? "Yes" : "No");

    /* @brief  Check if the string ends with a suffix */
    printf("Ends With \"World\": %s\n", ends_with(str, "World") ? "Yes" : "No");

    /* @brief  Trim leading and trailing whitespaces */
    char *with_whitespace_trimmed = trim_whitespace(str);
    printf("Trimmed Whitespace: \"%s\"\n", with_whitespace_trimmed);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(with_whitespace_trimmed);

    return 0;
}

/* @brief Function to calculate the average of elements in an integer array */
FOUNDATIONAL_LIB_FUNC double calculate_average(const int *array, size_t size)
{
    if (size == 0)
    {
        return 0.0;
    }

    int sum = calculate_sum(array, size);
    return (double)sum / size;
}

FOUNDATIONAL_LIB_FUNC int test54()
{
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    size_t arraySize = sizeof(array) / sizeof(array[0]);

    /* @brief  Find the maximum value in the array */
    int maxVal = find_max(array, arraySize);
    printf("Maximum Value: %d\n", maxVal);

    /* @brief  Find the minimum value in the array */
    int minVal = find_min(array, arraySize);
    printf("Minimum Value: %d\n", minVal);

    /* @brief  Calculate the sum of elements in the array */
    int sum = calculate_sum(array, arraySize);
    printf("Sum of Elements: %d\n", sum);

    /* @brief  Calculate the average of elements in the array */
    double average = calculate_average(array, arraySize);
    printf("Average of Elements: %.2f\n", average);

    return 0;
}

/* @brief Function to check if all characters in a string are uppercase */
FOUNDATIONAL_LIB_FUNC int is_string_upper(const char *str)
{
    while (*str)
    {
        if (!isupper(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

/* @brief Function to check if all characters in a string are lowercase */
FOUNDATIONAL_LIB_FUNC int is_string_lower(const char *str)
{
    while (*str)
    {
        if (!islower(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

/* @brief Function to check if all characters in a string are alphanumeric */
FOUNDATIONAL_LIB_FUNC int is_string_alphanumeric(const char *str)
{
    while (*str)
    {
        if (!isalnum(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

/* @brief Function to check if all characters in a string are digits */
FOUNDATIONAL_LIB_FUNC int is_string_digit(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

/* @brief Function to check if all characters in a string are spaces */
FOUNDATIONAL_LIB_FUNC int is_string_space(const char *str)
{
    while (*str)
    {
        if (!isspace(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int test55()
{
    const char *uppercaseStr = "HELLO";
    const char *lowercaseStr = "world";
    const char *alphanumericStr = "Hello123";
    const char *digitStr = "12345";
    const char *spaceStr = "   ";

    printf("Is Uppercase: %s\n", is_string_upper(uppercaseStr) ? "Yes" : "No");
    printf("Is Lowercase: %s\n", is_string_lower(lowercaseStr) ? "Yes" : "No");
    printf("Is Alphanumeric: %s\n", is_string_alphanumeric(alphanumericStr) ? "Yes" : "No");
    printf("Is Digit: %s\n", is_string_digit(digitStr) ? "Yes" : "No");
    printf("Is Space: %s\n", is_string_space(spaceStr) ? "Yes" : "No");

    return 0;
}

/* @brief Function to check if all elements in an integer array are even */
FOUNDATIONAL_LIB_FUNC int are_all_elements_even(const int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] % 2 != 0)
        {
            return 0;
        }
    }
    return 1;
}

/* @brief Function to check if all elements in an integer array are odd */
FOUNDATIONAL_LIB_FUNC int are_all_elements_odd(const int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            return 0;
        }
    }
    return 1;
}

/* @brief Function to check if all elements in an integer array are positive */
FOUNDATIONAL_LIB_FUNC int are_all_elements_positive(const int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] <= 0)
        {
            return 0;
        }
    }
    return 1;
}

/* @brief Function to check if all elements in an integer array are negative */
FOUNDATIONAL_LIB_FUNC int are_all_elements_negative(const int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] >= 0)
        {
            return 0;
        }
    }
    return 1;
}

/* @brief Function to check if all elements in an integer array are zeros */
FOUNDATIONAL_LIB_FUNC int are_all_elements_zero(const int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC void test56()
{
    int evenArray[] = {2, 4, 6, 8, 10};
    int oddArray[] = {1, 3, 5, 7, 9};
    int positiveArray[] = {1, 2, 3, 4, 5};

    size_t arraySize = sizeof(evenArray) / sizeof(evenArray[0]);

    printf("Are All Elements Even: %s\n", are_all_elements_even(evenArray, arraySize) ? "Yes" : "No");
    printf("Are All Elements Odd: %s\n", are_all_elements_odd(oddArray, arraySize) ? "Yes" : "No");
    printf("Are All Elements Positive: %s\n", are_all_elements_positive(positiveArray, arraySize) ? "Yes" : "No");
}

/* @brief Function to check if all characters in a string are alphabetic */
FOUNDATIONAL_LIB_FUNC int is_string_alpha(const char *str)
{
    while (*str)
    {
        if (!isalpha(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

/* @brief Function to check if all characters in a string are printable */
FOUNDATIONAL_LIB_FUNC int is_string_printable(const char *str)
{
    while (*str)
    {
        if (!isprint(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC void test57()
{
    const char *alphaStr = "HelloWorld";
    const char *digitStr = "12345";
    const char *alphanumericStr = "Hello123";
    const char *printableStr = "Hello, World!";

    printf("Is Alphabetic: %s\n", is_string_alpha(alphaStr) ? "Yes" : "No");
    printf("Is Digit: %s\n", is_string_digit(digitStr) ? "Yes" : "No");
    printf("Is Alphanumeric: %s\n", is_string_alphanumeric(alphanumericStr) ? "Yes" : "No");
    printf("Is Printable: %s\n", is_string_printable(printableStr) ? "Yes" : "No");
}

/* @brief Function to check if a string array contains only digits */
FOUNDATIONAL_LIB_FUNC int is_array_digit(const char *arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        const char *str = arr[i];
        while (*str)
        {
            if (!isdigit(*str))
            {
                return 0;
            }
            str++;
        }
    }
    return 1;
}

/* @brief Function to check if a string array contains at least one uppercase, one */
/* @brief lowercase, and one digit */
FOUNDATIONAL_LIB_FUNC int has_mixed_characters(const char *arr[], size_t size)
{
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;

    for (size_t i = 0; i < size; i++)
    {
        const char *str = arr[i];
        while (*str)
        {
            if (isupper(*str))
            {
                has_upper = 1;
            }
            else if (islower(*str))
            {
                has_lower = 1;
            }
            else if (isdigit(*str))
            {
                has_digit = 1;
            }
            str++;
        }
    }

    return (has_upper && has_lower && has_digit);
}

/* @brief Function to check if a string array contains only uppercase characters */
FOUNDATIONAL_LIB_FUNC int is_array_upper(const char *arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        const char *str = arr[i];
        while (*str)
        {
            if (!isupper(*str))
            {
                return 0;
            }
            str++;
        }
    }
    return 1;
}

/* @brief Function to check if a string array contains only lowercase characters */
FOUNDATIONAL_LIB_FUNC int is_array_lower(const char *arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        const char *str = arr[i];
        while (*str)
        {
            if (!islower(*str))
            {
                return 0;
            }
            str++;
        }
    }
    return 1;
}

FOUNDATIONAL_LIB_FUNC int test58()
{
    const char *strongArray1[] = {"STRONGPASS", "ANOTHERPASS"};
    const char *strongArray2[] = {"StrongPass123", "AnotherPass456"};
    const char *weakArray[] = {"weakpass", "anotherweak"};

    size_t arraySize1 = sizeof(strongArray1) / sizeof(strongArray1[0]);
    size_t arraySize2 = sizeof(strongArray2) / sizeof(strongArray2[0]);
    size_t weakArraySize = sizeof(weakArray) / sizeof(weakArray[0]);

    printf("Is Array Upper: %s\n", is_array_upper(strongArray1, arraySize1) ? "Yes" : "No");
    printf("Is Array Lower: %s\n", is_array_lower(strongArray1, arraySize1) ? "Yes" : "No");
    printf("Is Array Digit: %s\n", is_array_digit(strongArray2, arraySize2) ? "Yes" : "No");
    printf("Has Mixed Characters: %s\n", has_mixed_characters(strongArray2, arraySize2) ? "Yes" : "No");

    printf("\nWeak Array Checks:\n");
    printf("Is Array Upper: %s\n", is_array_upper(weakArray, weakArraySize) ? "Yes" : "No");
    printf("Is Array Lower: %s\n", is_array_lower(weakArray, weakArraySize) ? "Yes" : "No");
    printf("Is Array Digit: %s\n", is_array_digit(weakArray, weakArraySize) ? "Yes" : "No");
    printf("Has Mixed Characters: %s\n", has_mixed_characters(weakArray, weakArraySize) ? "Yes" : "No");

    return 0;
}

FOUNDATIONAL_LIB_FUNC int test59()
{
    const char *stringArray1[] = {"HELLO", "WORLD"};
    const char *stringArray2[] = {"Hello123", "Another456"};
    const char *stringArray3[] = {"lowercase", "123numbers"};
    const char *stringArray4[] = {"UPPERCASE", "symbols!@#"};

    size_t arraySize1 = sizeof(stringArray1) / sizeof(stringArray1[0]);
    size_t arraySize2 = sizeof(stringArray2) / sizeof(stringArray2[0]);
    size_t arraySize3 = sizeof(stringArray3) / sizeof(stringArray3[0]);
    size_t arraySize4 = sizeof(stringArray4) / sizeof(stringArray4[0]);

    printf("Is Array Upper: %s\n", is_array_upper(stringArray1, arraySize1) ? "Yes" : "No");
    printf("Is Array Lower: %s\n", is_array_lower(stringArray3, arraySize3) ? "Yes" : "No");
    printf("Is Array Digit: %s\n", is_array_digit(stringArray2, arraySize2) ? "Yes" : "No");
    printf("Has Mixed Characters: %s\n", has_mixed_characters(stringArray4, arraySize4) ? "Yes" : "No");

    return 0;
}

// Function to find unique strings in the input array
FOUNDATIONAL_LIB_FUNC int string_array_uniq(const char **arr, size_t size, char ***output, size_t *output_size)
{
    // Count the number of unique strings
    size_t count = 0;

    // Check for invalid inputs
    if (arr == NULL || output == NULL || output_size == NULL)
    {
        return -1;
    }

    // Allocate memory for the array to store unique strings
    *output = (char **)malloc(size * sizeof(char *));
    if (*output == NULL)
    {
        // Memory allocation failed
        die_aggressively_if_enabled();
        return -1;
    }

    // Initialize all elements to NULL
    for (size_t i = 0; i < size; i++)
    {
        (*output)[i] = NULL;
    }

    // Iterate through the input array to find unique strings
    for (size_t i = 0; i < size; i++)
    {
        int isUnique = 1;

        // Check if the current string is not equal to any previous strings
        for (size_t j = 0; j < count; j++)
        {
            if ((*output)[j] != NULL && strcmp(arr[i], (*output)[j]) == 0)
            {
                isUnique = 0; // Not unique
                break;
            }
        }

        if (isUnique)
        {
            // Allocate memory for the new string and copy it
            (*output)[count] = ((char **)arr)[i]; // No strdup used.
            if ((*output)[count] == NULL)
            {
                // Memory allocation failed
                die_aggressively_if_enabled();
                return -1;
            }

            count++;
        }
    }

    // Set the output size
    *output_size = count;

    return 0; // Success
}

FOUNDATIONAL_LIB_FUNC int test60()
{
    const char *stringArray[] = {("apple"), ("banana"), ("apple"), ("orange"), ("banana"), ("kiwi")};

    size_t arraySize = sizeof(stringArray) / sizeof(stringArray[0]);

    /* @brief  Before uniq */
    printf("Before Uniq ruby:\n");
    for (size_t i = 0; i < arraySize; i++)
    {
        printf("%s ", stringArray[i]);
    }
    printf("\n");

    char **uniqueArr;
    size_t uniqueSize;

    /*   Apply uniq */
    if (string_array_uniq(stringArray, arraySize, &uniqueArr, &uniqueSize) == -1)
    {
        test_foundationallib_test_error_handler("Error with array uniq");
    }

    /* @brief  After uniq */
    printf("After Uniq ruby:\n");
    for (size_t i = 0; i < uniqueSize; i++)
    {
        printf("%s ", uniqueArr[i]);
    }
    printf("\n");

    free(uniqueArr);

    return 0;
}

/* @brief Function to remove consecutive duplicate strings from an array (Bash-style) */
FOUNDATIONAL_LIB_FUNC void string_array_uniq_adjacent(char *arr[], size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] != NULL && strcmp(arr[i], arr[i - 1]) == 0)
        {
            /* @brief  Found a consecutive duplicate, FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE memory and set to NULL */
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(arr[i]);
            arr[i] = NULL;
        }
    }
}

FOUNDATIONAL_LIB_FUNC int test61()
{
    const char *stringArray[] = {FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP("apple"), FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP("banana"), FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP("apple"), FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP("orange"), FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP("banana"), FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP("kiwi")};

    size_t arraySize = sizeof(stringArray) / sizeof(stringArray[0]);

    /* @brief  Before uniq */
    printf("Before Uniq bash:\n");
    for (size_t i = 0; i < arraySize; i++)
    {
        printf("%s ", stringArray[i]);
    }
    printf("\n");

    /* @brief  Apply uniq */
    string_array_uniq_adjacent((char **)stringArray, arraySize);

    /* @brief  After uniq */
    printf("After Uniq bash\n");
    for (size_t i = 0; i < arraySize; i++)
    {
        if (stringArray[i] == NULL)
        {
            test_foundationallib_test_error_handler("Should not be null. this is an error");
        }
        printf("%s ", stringArray[i]);
        FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE((void *)stringArray[i]);
    }
    printf("\n");

    return 0;
}

/* @brief Function to concatenate three strings */
FOUNDATIONAL_LIB_FUNC char *concatenate_three_strings(const char *str1, const char *str2, const char *str3)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t len3 = strlen(str3);

    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(len1 + len2 + len3 + 1);
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);

    return result;
}

/* @brief Function to concatenate four strings */
FOUNDATIONAL_LIB_FUNC char *concatenate_four_strings(const char *str1, const char *str2, const char *str3, const char *str4)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t len3 = strlen(str3);
    size_t len4 = strlen(str4);

    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(len1 + len2 + len3 + len4 + 1);
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    strcat(result, str4);

    return result;
}

/* @brief Function to concatenate five strings */
FOUNDATIONAL_LIB_FUNC char *concatenate_five_strings(const char *str1, const char *str2, const char *str3, const char *str4, const char *str5)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t len3 = strlen(str3);
    size_t len4 = strlen(str4);
    size_t len5 = strlen(str5);

    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(len1 + len2 + len3 + len4 + len5 + 1);
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    strcat(result, str4);
    strcat(result, str5);

    return result;
}

FOUNDATIONAL_LIB_FUNC int test63()
{
    const char *str1 = "Hello, ";
    const char *str2 = "World! ";
    const char *str3 = "How ";
    const char *str4 = "are ";
    const char *str5 = "you?";

    char *result_three = concatenate_three_strings(str1, str2, str3);
    char *result_four = concatenate_four_strings(str1, str2, str3, str4);
    char *result_five = concatenate_five_strings(str1, str2, str3, str4, str5);

    printf("Concatenate Three Strings: %s\n", result_three);
    printf("Concatenate Four Strings: %s\n", result_four);
    printf("Concatenate Five Strings: %s\n", result_five);

    /* @brief  Free the memory for the concatenated strings */
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(result_three);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(result_four);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(result_five);

    return 0;
}

/* @brief Function to apply a map operation on files, works with strings, -1 on error, 0 on non error */
FOUNDATIONAL_LIB_FUNC int map_files_into_strings(const char *directory, char *(*map_function)(const char *file_string_data, size_t string_size))
{
    DIR *dir = opendir(directory);
    if (dir == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        { // Regular file
            char *file_data;
            size_t size;

            file_data = read_file_into_string(entry->d_name, &size);
            char *new_str = map_function(file_data, size);
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(file_data);
            write_file(entry->d_name, file_data);
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(new_str);
        }
    }

    if (closedir(dir) == -1)
    {
        die_aggressively_if_enabled();
        return -1;
    }
    return 0;
}

/* @brief Function to apply a filter operation on files, -1 on error, 0 on non error, filter function returns 1 on keep, 0 on delete */
FOUNDATIONAL_LIB_FUNC int filter_files(const char *directory, int (*filter_function)(const char *filename))
{
    DIR *dir = opendir(directory);
    if (dir == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
        test_foundationallib_test_error_handler("Unable to open directory");
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        {
            if (!filter_function(entry->d_name))
                remove_file(entry->d_name);
        }
    }
    if (closedir(dir) == -1)
    {
        die_aggressively_if_enabled();
        return -1;
    }
    return 0;
}

/* @brief Function to apply a reduce operation on files */
FOUNDATIONAL_LIB_FUNC char *reduce_files(const char *directory, const char *out_file, char *(*reduce_function)(char *value1, ...))
{
    DIR *dir = opendir(directory);
    if (dir == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }
    struct dirent *entry;

    char *last_value = NULL;
    char *value = NULL;
    while ((entry = readdir(dir)) != NULL)
    {
        // Regular file
        if (entry->d_type == DT_REG)
        {
            size_t size;
            value = read_file_into_string(entry->d_name, &size);

            char *new_value = reduce_function(last_value, value, entry->d_name);
            if (last_value)
            {
                FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(last_value);
            }

            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(value);
            last_value = new_value;

            remove_file(entry->d_name);
        }
    }

    if (closedir(dir) == -1)
    {
        die_aggressively_if_enabled();
        return NULL;
    }
    write_file(out_file, (value));

    return last_value;
}

FOUNDATIONAL_LIB_FUNC void test_print_filename(const char *filename) { printf("%s\n", filename); }
FOUNDATIONAL_LIB_FUNC int test_filter_by_extension(const char *filename) { return strstr(filename, ".txt") != NULL; }
FOUNDATIONAL_LIB_FUNC int test_count_files() { return 0; }

FOUNDATIONAL_LIB_FUNC int test64()
{

    /* @brief  Map operation (print file names) */
    printf("Map Operation:\n");
    /* @brief     map_files_into_strings(current_directory, print_filename); */

    /* @brief  Filter operation (print files with a certain extension) */
    printf("\nFilter Operation:\n");
    /* @brief     filter_files(current_directory, filter_by_extension); */

    /* @brief  Reduce operation (count the number of files) */
    /* @brief     int total_files = reduce_files(current_directory, count_files, 0); */
    printf("\nReduce Operation: Total Files\n");

    return 0;
}

/* @brief Dict */
struct KeyValue
{
    char *key;
    void *value;
    struct KeyValue *next;
};

struct SetKey
{
    char *key;
    void *value;
    struct KeyValue *next;
};
struct Dict
{
    struct KeyValue **table;
    size_t capacity;
    size_t size;
};

FOUNDATIONAL_LIB_FUNC struct Dict *dict_new_instance()
{
    struct Dict *dict = (struct Dict *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct Dict));
    if (!dict)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    dict->capacity = FOUNDATIONALLIB_HASH_INITIAL_CAPACITY;
    dict->size = 0;
    dict->table = (struct KeyValue **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_CALLOC(FOUNDATIONALLIB_HASH_INITIAL_CAPACITY, sizeof(struct KeyValue *));
    if (!dict->table)
    {
        FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict);
        die_aggressively_if_enabled();
        return NULL;
    }

    return dict;
}

FOUNDATIONAL_LIB_FUNC void dict_destructor(struct Dict *dict)
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            struct KeyValue *nextPair = currentPair->next;
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(currentPair->key);
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(currentPair);
            currentPair = nextPair;
        }
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict->table);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict);
}

FOUNDATIONAL_LIB_FUNC unsigned int dict_hash(const char *key, size_t capacity)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash = (hash << 5) + *key++;
    }
    return hash % capacity;
}

FOUNDATIONAL_LIB_FUNC int dict_resize(struct Dict *dict)
{
    size_t newCapacity = dict->capacity + dict->capacity / 2 + 1;
    struct KeyValue **newTable = (struct KeyValue **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_CALLOC(newCapacity, sizeof(struct KeyValue *));
    if (!newTable)
    {
        dict_destructor(dict);
        die_aggressively_if_enabled();
        return -1;
    }

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair)
        {
            struct KeyValue *nextPair = currentPair->next;
            unsigned int newIndex = dict_hash(currentPair->key, newCapacity);
            currentPair->next = newTable[newIndex];
            newTable[newIndex] = currentPair;
            currentPair = nextPair;
        }
    }

    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict->table);
    dict->table = newTable;
    dict->capacity = newCapacity;

    return 0;
}

FOUNDATIONAL_LIB_FUNC void dict_del(struct Dict *dict, const char *key)
{
    size_t index = dict_hash(key, dict->capacity);

    struct KeyValue *current = dict->table[index];
    struct KeyValue *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            /* @brief  Key found, remove the entry */
            if (prev == NULL)
            {
                /* @brief  If it's the first node in the linked list */
                dict->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            /* @brief  Free memory */
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(current->key);
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(current);

            /* @brief  Update size */
            dict->size--;

            return;
        }

        /* @brief  Move to the next node in the linked list */
        prev = current;
        current = current->next;
    }
}

FOUNDATIONAL_LIB_FUNC int dict_add(struct Dict *dict, const char *key, void *value)
{
    if ((double)dict->size / dict->capacity > FOUNDATIONALLIB_HASH_LOAD_FACTOR_THRESHOLD)
    {
        if (dict_resize(dict) == -1)
        {
            // Don't need to re die aggressively if enabled here because dict resize does it.
            return -1;
        }
    }

    unsigned int index = dict_hash(key, dict->capacity);

    struct KeyValue *newPair = (struct KeyValue *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct KeyValue));
    if (newPair == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    newPair->key = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(key);
    newPair->value = value;
    newPair->next = dict->table[index];
    dict->table[index] = newPair;

    dict->size++;

    return 0;
}

FOUNDATIONAL_LIB_FUNC void *dict_get(struct Dict *dict, const char *key)
{
    unsigned int index = dict_hash(key, dict->capacity);
    struct KeyValue *currentPair = dict->table[index];

    while (currentPair != NULL)
    {
        if (strcmp(currentPair->key, key) == 0)
        {
            return currentPair->value;
        }

        // Hash collision, continue with linked list.
        currentPair = currentPair->next;
    }

    return NULL;
}

FOUNDATIONAL_LIB_FUNC void *dict_get_check(struct Dict *dict, const char *key, int *key_is_in_dict)
{
    unsigned int index = dict_hash(key, dict->capacity);
    struct KeyValue *currentPair = dict->table[index];

    while (currentPair != NULL)
    {
        if (strcmp(currentPair->key, key) == 0)
        {
            *key_is_in_dict = 1;
            return currentPair->value;
        }
        currentPair = currentPair->next;
    }

    *key_is_in_dict = 0;
    return NULL;
}

struct FrozenDict
{
    struct KeyValue **table;
    size_t capacity;
    size_t size;
};

FOUNDATIONAL_LIB_FUNC void frozen_dict_destructor(struct FrozenDict *dict)
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            struct KeyValue *nextPair = currentPair->next;
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(currentPair->key);
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(currentPair);
            currentPair = nextPair;
        }
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict->table);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict);
}

FOUNDATIONAL_LIB_FUNC struct FrozenDict *frozen_dict_new_instance(size_t num_args, ...)
{
    struct FrozenDict *dict = (struct FrozenDict *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct FrozenDict));
    if (dict == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    dict->capacity = FOUNDATIONALLIB_HASH_INITIAL_CAPACITY;
    dict->size = 0;
    dict->table = (struct KeyValue **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_CALLOC(FOUNDATIONALLIB_HASH_INITIAL_CAPACITY, sizeof(struct KeyValue *));
    if (!dict->table)
    {

        frozen_dict_destructor(dict);
        die_aggressively_if_enabled();
        return NULL;
    }

    va_list args;
    va_start(args, num_args);

    for (size_t i = 0; i < num_args; ++i)
    {
        char *key;
        void *value;

        key = va_arg(args, char *);
        value = va_arg(args, void *);
        dict_add((struct Dict *)dict, key, value);
    }

    va_end(args); // Clean up the va_list

    return dict;
}
FOUNDATIONAL_LIB_FUNC void *frozen_dict_get(struct FrozenDict *dict, const char *key)
{
    unsigned int index = dict_hash(key, dict->capacity);
    struct KeyValue *currentPair = dict->table[index];

    while (currentPair != NULL)
    {
        if (strcmp(currentPair->key, key) == 0)
        {
            return currentPair->value;
        }
        currentPair = currentPair->next;
    }

    return NULL;
}

FOUNDATIONAL_LIB_FUNC void *frozen_dict_get_check(struct FrozenDict *dict, const char *key, int *key_is_in_dict)
{
    unsigned int index = dict_hash(key, dict->capacity);
    struct KeyValue *currentPair = dict->table[index];

    while (currentPair != NULL)
    {
        if (strcmp(currentPair->key, key) == 0)
        {
            *key_is_in_dict = 1;
            return currentPair->value;
        }
        currentPair = currentPair->next;
    }

    *key_is_in_dict = 0;
    return NULL;
}

FOUNDATIONAL_LIB_FUNC void dict_iter(struct Dict *dict, void (*callback)(char *key, void *value))
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *current = dict->table[i];

        while (current != NULL)
        {
            /* @brief  Call the callback function with the key and value */
            callback(current->key, current->value);

            /* @brief  Move to the next node in the linked list */
            current = current->next;
        }
    }
}

FOUNDATIONAL_LIB_FUNC size_t dict_size(struct Dict *dict) { return dict->size; }

FOUNDATIONAL_LIB_FUNC size_t frozen_dict_size(struct FrozenDict *dict) { return dict->size; }
FOUNDATIONAL_LIB_FUNC int dict_to_array(struct Dict *dict, char ***keys, void ***values, size_t *size_of_keys_and_values)
{ /* @brief return size of keys and values (they are always the same) */
    *keys = (char **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(dict->size * sizeof(char *));
    if (*keys == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    *values = (void **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(dict->size * sizeof(void *));
    if (*values == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    size_t index = 0;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            (*keys)[index] = (currentPair->key);
            (*values)[index] = currentPair->value;
            ++index;
            currentPair = currentPair->next;
        }
    }

    *size_of_keys_and_values = dict->size;

    return 0;
}

FOUNDATIONAL_LIB_FUNC size_t frozen_dict_to_array(struct FrozenDict *dict, char ***keys, void ***values, size_t *size_of_keys_and_values)
{ /* @brief return size of keys and values (they are always the same) */
    /* @brief return size of keys and values (they are always the same) */
    *keys = (char **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(dict->size * sizeof(char *));
    if (*keys == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    *values = (void **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(dict->size * sizeof(void *));
    if (*values == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    size_t index = 0;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            (*keys)[index] = (currentPair->key);
            (*values)[index] = currentPair->value;
            ++index;
            currentPair = currentPair->next;
        }
    }

    *size_of_keys_and_values = dict->size;
}

FOUNDATIONAL_LIB_FUNC void dict_del_keys(char **keys) { FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(keys); }

FOUNDATIONAL_LIB_FUNC void dict_del_values(void **values) { FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(values); }

/* @brief Convert a frozen dictionary to a string representation */
FOUNDATIONAL_LIB_FUNC char *dict_to_string(struct Dict *dict, int pointer_or_string) /* @brief 0 = pointer, 1 = string */
{
    /* @brief  Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /* @brief  Calculate the length of the string representation for each key-value pair */
            total_length += strlen(currentPair->key) + 2; // 2 for ": "
            if (pointer_or_string == 0)
            {
                total_length += snprintf(NULL, 0, "%p", currentPair->value); // Calculate the length of the value string
            }
            else
            {
                total_length += snprintf(NULL, 0, "%s", (char *)currentPair->value); // Calculate the length of the value string
            }
            total_length += 2; // 2 for ", "
            currentPair = currentPair->next;
        }
    }

    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(total_length + 1); // Add 1 for the null-terminator, at least 3 chars additional
    if (!result)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /* @brief  Append the key and value to the string representation */
            if (pointer_or_string == 0)
            {
                index += snprintf(result + index, total_length - index, "%s: %p", currentPair->key, currentPair->value);
            }
            else if (pointer_or_string == 1)
            {
                index += snprintf(result + index, total_length - index, "%s: %s", currentPair->key, (char *)currentPair->value);
            }
            currentPair = currentPair->next;

            /* @brief  Add a separator (comma) if there are more elements */
            if (index < total_length - 2)
            {
                result[index++] = ',';
                result[index++] = ' ';
            }
        }
    }

    if (dict->capacity)
        index -= 2;
    result[index++] = '}';  // Null-terminate the string
    result[index++] = '\0'; // Null-terminate the string
    return result;
}

/* @brief Convert a frozen dictionary to a string representation */
FOUNDATIONAL_LIB_FUNC char *frozen_dict_to_string(struct FrozenDict *dict, int pointer_or_string) /* @brief 0 = pointer, 1 = string */
{
    /* @brief  Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /* @brief  Calculate the length of the string representation for each key-value pair */
            total_length += strlen(currentPair->key) + 2; // 2 for ": "
            if (pointer_or_string == 0)
            {
                total_length += snprintf(NULL, 0, "%p", currentPair->value); // Calculate the length of the value string
            }
            else
            {
                total_length += snprintf(NULL, 0, "%s", (char *)currentPair->value); // Calculate the length of the value string
            }
            total_length += 2; // 2 for ", "
            currentPair = currentPair->next;
        }
    }

    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(total_length + 1); // Add 1 for the null-terminator, at least 3 chars additional
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /* @brief  Append the key and value to the string representation */
            if (pointer_or_string == 0)
            {
                index += snprintf(result + index, total_length - index, "%s: %p", currentPair->key, currentPair->value);
            }
            else if (pointer_or_string == 1)
            {
                index += snprintf(result + index, total_length - index, "%s: %s", currentPair->key, (char *)currentPair->value);
            }
            currentPair = currentPair->next;

            /* @brief  Add a separator (comma) if there are more elements */
            if (index < total_length - 2)
            {
                result[index++] = ',';
                result[index++] = ' ';
            }
        }
    }

    if (dict->capacity)
        index -= 2;
    result[index++] = '}';  // Null-terminate the string
    result[index++] = '\0'; // Null-terminate the string
    return result;
}

FOUNDATIONAL_LIB_FUNC void frozen_dict_del_keys(char **keys) { FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(keys); }

FOUNDATIONAL_LIB_FUNC void frozen_dict_del_values(void **values) { FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(values); }

/* @brief Set */

FOUNDATIONAL_LIB_FUNC void test65()
{
    struct Dict *myDict = dict_new_instance();

    void *value = dict_get(myDict, "banana");
    printf("The value for 'banana' is: %ld\n", (long int)value);

    dict_add(myDict, "banana", (void *)"is curved.");

    dict_add(myDict, "apple", (void *)"is red or green");

    dict_add(myDict, "cat", (void *)"is cute");

    dict_add(myDict, "dog", (void *)"barks a lot");

    dict_add(myDict, "frog", (void *)"ribbits");

    dict_add(myDict, "man", (void *)"walks");
    value = dict_get(myDict, "banana");
    printf("The value for 'banana' is: %ld\n", (long int)value);

    char **keys;

    void **values;

    size_t size_of_keys_and_values;
    if (dict_to_array(myDict, &keys, &values, &size_of_keys_and_values) == -1)
    {
        test_foundationallib_test_error_handler("Error dict to array");
    }

    puts("Printing dict keys");
    print_string_array(keys, dict_size(myDict));
    puts("Printing dict values");
    print_string_array((char **)values, dict_size(myDict));

    puts("To a");

    char *dict = dict_to_string(myDict, 0 /* @brief pointer */);
    puts(dict);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict);

    dict = dict_to_string(myDict, 1 /* @brief string */);
    puts(dict);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict);

    /* @brief  FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(keys); FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(values) works also */
    dict_del_keys(keys);
    dict_del_values(values);
    dict_destructor(myDict);

    struct FrozenDict *myFrozenDict = frozen_dict_new_instance(2, "apple", 5, "banana", 8);

    value = frozen_dict_get(myFrozenDict, "banana");
    printf("The value for 'banana' is: %ld\n", (long int)value);
    value = frozen_dict_get(myFrozenDict, "apple");
    printf("The value for 'apple' is: %ld\n", (long int)value);

    printf("Frozendict size is %ld\n", frozen_dict_size(myFrozenDict));

    frozen_dict_destructor(myFrozenDict);
}

struct Key
{
    char *key;
    struct Key *next;
};
struct Set
{
    struct Key **table;
    size_t capacity;
    size_t size;
};

FOUNDATIONAL_LIB_FUNC void set_destructor(struct Set *dict)
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            struct Key *nextPair = currentPair->next;
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(currentPair->key);
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(currentPair);
            currentPair = nextPair;
        }
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict->table);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict);
}

FOUNDATIONAL_LIB_FUNC struct Set *set_new_instance()
{
    struct Set *dict = (struct Set *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct Set));
    if (dict == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    dict->capacity = FOUNDATIONALLIB_HASH_INITIAL_CAPACITY;
    dict->size = 0;
    dict->table = (struct Key **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_CALLOC(FOUNDATIONALLIB_HASH_INITIAL_CAPACITY, sizeof(struct Key *));
    if (!dict->table)
    {

        set_destructor(dict);
        die_aggressively_if_enabled();
        return NULL;
    }

    return dict;
}
FOUNDATIONAL_LIB_FUNC unsigned int set_hash(const char *key, size_t capacity)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash = (hash << 5) + *key++;
    }
    return hash % capacity;
}

FOUNDATIONAL_LIB_FUNC int set_resize(struct Set *dict)
{
    size_t newCapacity = dict->capacity + dict->capacity / 2 + 1;
    struct Key **newTable = (struct Key **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_CALLOC(newCapacity, sizeof(struct Key *));
    if (!newTable)
    {
        set_destructor(dict);
        die_aggressively_if_enabled();
        return -1;
    }

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair)
        {
            struct Key *nextPair = currentPair->next;
            unsigned int newIndex = set_hash(currentPair->key, newCapacity);
            currentPair->next = newTable[newIndex];
            newTable[newIndex] = currentPair;
            currentPair = nextPair;
        }
    }

    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict->table);
    dict->table = newTable;
    dict->capacity = newCapacity;

    return 0;
}

FOUNDATIONAL_LIB_FUNC void set_del(struct Set *dict, const char *key)
{
    size_t index = set_hash(key, dict->capacity);

    struct Key *current = dict->table[index];
    struct Key *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            /* @brief  Key found, remove the entry */
            if (prev == NULL)
            {
                /* @brief  If it's the first node in the linked list */
                dict->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            /* @brief  Free memory */
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(current->key);
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(current);

            /* @brief  Update size */
            dict->size--;

            return;
        }

        /* @brief  Move to the next node in the linked list */
        prev = current;
        current = current->next;
    }
}

FOUNDATIONAL_LIB_FUNC int set_add(struct Set *dict, const char *key)
{
    if ((double)dict->size / dict->capacity > FOUNDATIONALLIB_HASH_LOAD_FACTOR_THRESHOLD)
    {
        if (set_resize(dict) == -1)
        {
            // Don't need to re die aggressively if enabled here because set_resize does it.
            return -1;
        }
    }

    unsigned int index = set_hash(key, dict->capacity);

    struct Key *newPair = (struct Key *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct Key));
    if (newPair == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    newPair->key = FOUNDATIONALLIB_MEMORY_ALLOCATOR_STRDUP(key);
    newPair->next = dict->table[index];
    dict->table[index] = newPair;

    dict->size++;

    return 0;
}

/* @brief Set.in? */
FOUNDATIONAL_LIB_FUNC int set_in(struct Set *dict, const char *key)
{
    unsigned int index = set_hash(key, dict->capacity);
    struct Key *currentPair = dict->table[index];

    while (currentPair != NULL)
    {
        if (strcmp(currentPair->key, key) == 0)
        {
            return 1;
        }
        currentPair = currentPair->next;
    }

    return 0;
}

struct FrozenSet
{
    struct Key **table;
    size_t capacity;
    size_t size;
};

FOUNDATIONAL_LIB_FUNC void frozen_set_destructor(struct FrozenSet *dict)
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            struct Key *nextPair = currentPair->next;
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(currentPair->key);
            FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(currentPair);
            currentPair = nextPair;
        }
    }
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict->table);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(dict);
}

FOUNDATIONAL_LIB_FUNC struct FrozenSet *frozen_set_new_instance(size_t num_args, ...)
{
    struct FrozenSet *dict = (struct FrozenSet *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(sizeof(struct FrozenSet));
    if (dict == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    dict->capacity = FOUNDATIONALLIB_HASH_INITIAL_CAPACITY;
    dict->size = 0;
    dict->table = (struct Key **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_CALLOC(FOUNDATIONALLIB_HASH_INITIAL_CAPACITY, sizeof(struct Key *));
    if (dict->table == NULL)
    {
        frozen_set_destructor(dict);
        die_aggressively_if_enabled();
        return NULL;
    }

    va_list args;
    va_start(args, num_args);

    for (size_t i = 0; i < num_args; ++i)
    {
        char *key;

        key = va_arg(args, char *);
        set_add((struct Set *)dict, key);
    }

    va_end(args); // Clean up the va_list

    return dict;
}
FOUNDATIONAL_LIB_FUNC int frozen_set_in(struct FrozenSet *dict, const char *key)
{
    unsigned int index = set_hash(key, dict->capacity);
    struct Key *currentPair = dict->table[index];

    while (currentPair != NULL)
    {
        if (strcmp(currentPair->key, key) == 0)
        {
            return 1;
        }
        currentPair = currentPair->next;
    }

    return 0;
}

FOUNDATIONAL_LIB_FUNC void set_iter(struct Set *dict, void (*callback)(char *key))
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *current = dict->table[i];

        while (current != NULL)
        {
            /* @brief  Call the callback function with the key and value */
            callback(current->key);

            /* @brief  Move to the next node in the linked list */
            current = current->next;
        }
    }
}

FOUNDATIONAL_LIB_FUNC size_t set_size(struct Set *dict) { return dict->size; }

FOUNDATIONAL_LIB_FUNC size_t frozen_set_size(struct FrozenSet *dict) { return dict->size; }
FOUNDATIONAL_LIB_FUNC int set_to_array(struct Set *set, char ***keys, size_t *size_of_keys)
{ /* @brief return size of keys and values (they are always the same) */
    *keys = (char **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(set->size * sizeof(char *));

    if (!*keys)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    size_t index = 0;
    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct Key *currentPair = set->table[i];
        while (currentPair != NULL)
        {
            (*keys)[index] = (currentPair->key);
            ++index;
            currentPair = currentPair->next;
        }
    }

    *size_of_keys = set->size;
    return 0;
}

FOUNDATIONAL_LIB_FUNC int frozen_set_to_array(struct FrozenSet *set, char ***keys, size_t *size_of_keys)
{ /* @brief return size of keys and values (they are always the same) */
    *keys = (char **)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(set->size * sizeof(char *));

    if (*keys == NULL)
    {
        die_aggressively_if_enabled();
        return -1;
    }

    size_t index = 0;
    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct Key *currentPair = set->table[i];
        while (currentPair != NULL)
        {
            (*keys)[index] = (currentPair->key);
            ++index;
            currentPair = currentPair->next;
        }
    }

    *size_of_keys = set->size;
    return set->size;
}

FOUNDATIONAL_LIB_FUNC void set_del_keys(char **keys) { FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(keys); }

/* @brief Convert a frozen dictionary to a string representation */
FOUNDATIONAL_LIB_FUNC char *set_to_string(struct Set *set) /* @brief 0 = pointer, 1 = string */
{
    /* @brief  Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct Key *currentPair = set->table[i];
        while (currentPair != NULL)
        {
            /* @brief  Calculate the length of the string representation for each key-value pair */
            total_length += strlen(currentPair->key);
            total_length += 2; // 2 for ", "
            currentPair = currentPair->next;
        }
    }

    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(total_length + 1); // Add 1 for the null-terminator, at least 3 chars
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct Key *currentPair = set->table[i];
        while (currentPair != NULL)
        {
            /* @brief  Append the key and value to the string representation */
            index += snprintf(result + index, total_length - index, "%s", currentPair->key);
            currentPair = currentPair->next;

            /* @brief  Add a separator (comma) if there are more elements */
            if (index < total_length - 2)
            {
                result[index++] = ',';
                result[index++] = ' ';
            }
        }
    }

    if (set->capacity)
        index -= 2;
    result[index++] = '}';  // Null-terminate the string
    result[index++] = '\0'; // Null-terminate the string
    return result;
}

/* @brief Convert a frozen dictionary to a string representation */
FOUNDATIONAL_LIB_FUNC char *frozen_set_to_string(struct FrozenSet *set) /* @brief 0 = pointer, 1 = string */
{
    /* @brief  Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct Key *currentPair = set->table[i];
        while (currentPair != NULL)
        {
            /* @brief  Calculate the length of the string representation for each key-value pair */
            total_length += strlen(currentPair->key);
            total_length += 2; // 2 for ", "
            currentPair = currentPair->next;
        }
    }

    char *result = (char *)FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(total_length + 1); // Add 1 for the null-terminator, at least 3 chars
    if (result == NULL)
    {
        die_aggressively_if_enabled();
        return NULL;
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct Key *currentPair = set->table[i];
        while (currentPair != NULL)
        {
            /* @brief  Append the key and value to the string representation */
            index += snprintf(result + index, total_length - index, "%s", currentPair->key);
            currentPair = currentPair->next;

            /* @brief  Add a separator (comma) if there are more elements */
            if (index < total_length - 2)
            {
                result[index++] = ',';
                result[index++] = ' ';
            }
        }
    }

    if (set->capacity)
        index -= 2;
    result[index++] = '}';  // Null-terminate the string
    result[index++] = '\0'; // Null-terminate the string
    return result;
}

FOUNDATIONAL_LIB_FUNC void frozen_set_del_keys(char **keys) { FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(keys); }

FOUNDATIONAL_LIB_FUNC void frozen_set_iter(struct Set *set, void (*callback)(char *key))
{
    for (size_t i = 0; i < set->capacity; ++i)
    {
        struct Key *current = set->table[i];

        while (current != NULL)
        {
            /* @brief  Call the callback function with the key and value */
            callback(current->key);

            /* @brief  Move to the next node in the linked list */
            current = current->next;
        }
    }
}

FOUNDATIONAL_LIB_FUNC void test66()
{
    struct Set *set = set_new_instance();

    int value = set_in(set, "banana");
    printf("The value for 'banana' is: %ld\n", (long int)value);

    set_add(set, "banana");

    set_add(set, "apple");

    set_add(set, "cat");

    set_add(set, "dog");

    set_add(set, "frog");

    set_add(set, "man");
    value = set_in(set, "banana");
    printf("Set | The value for 'banana' is: %ld\n", (long int)value);

    char **keys;
    size_t size_of_keys;

    if (set_to_array(set, &keys, &size_of_keys) == -1)
    {
        test_foundationallib_test_error_handler("Error set_to_array");
    }

    puts("Printing set keys");
    print_string_array(keys, set_size(set));

    puts("To a");

    char *s = set_to_string(set);
    puts(s);
    FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(s);

    /* @brief  FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(keys); FOUNDATIONALLIB_MEMORY_ALLOCATOR_FREE(values) works also */
    set_del_keys(keys);
    set_destructor(set);

    struct FrozenSet *f = frozen_set_new_instance(3, "apple", "banana", "frog");

    value = frozen_set_in(f, "banana");
    printf("Frozenset | The value for 'banana' is: %ld\n", (long int)value);
    value = frozen_set_in(f, "apple");
    printf("Frozenset | The value for 'apple' is: %ld\n", (long int)value);

    printf("Frozenset | Frozenset size is %ld\n", frozen_set_size(f));

    frozen_set_destructor(f);
}

FOUNDATIONAL_LIB_FUNC void test67()
{
    struct Set *set = set_new_instance();

    // Adding values to the set
    set_add(set, "banana");
    set_add(set, "apple");
    set_add(set, "cat");

    puts("Adding an additional 20,000 members to the set");

    for (int i = 0; i < 200 * 100; i++)
    {
        if (i % 50000 == 0)
        {
            printf("%d\n", i);
        }
        char value[20]; // Adjust the size based on your needs
        snprintf(value, sizeof(value), "%d_value", i);
        set_add(set, value);
    }

    // Cleanup
    set_destructor(set);
    set = NULL;

    struct Dict *dict = dict_new_instance();

    dict_add(dict, "foo", (void *)"bar");
    puts("Adding an additional 20,000 members to the dict");

    for (int i = 0; i < 200 * 100; i++)
    {

        if (i % 50000 == 0)
        {
            printf("%d\n", i);
        }
        char value[20]; // Adjust the size based on your needs
        snprintf(value, sizeof(value), "%d_value", i);
        char key[20]; // Adjust the size based on your needs
        snprintf(key, sizeof(value), "%d_key", i);

        dict_add(dict, key, value);
    }

    dict_destructor(dict);

    dict = NULL;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    test18();
    test19();
    test20();
    test21();
    test24();
    test26();
    test27();
    test28();
    test29();
    test30();
    test31();
    test32();
    test33();
    test34();
    test35();
    test36();
    test37();
    test38();
    test39();
    test40();
    test41();
    test42();
    test43();
    test44();
    test45();
    test46();
    test47();
    test48();
    test49();
    test50();
    test51();
    test52();
    test53();
    test54();
    test55();
    test56();
    test57();
    test58();
    test59();
    test60();
    test61();
    test63();
    test64();
    test65();
    test66();
    test67();

    size_t len;
    char **array = list_files_with_pattern(".", "html*", &len);
    fputs("HTML files in current directory: ", stdout);
    print_string_array(array, len);

    int a[] = {1, 2, 3, 4, 5};

    print_int_array(a, 5);

    free_array((void **)array, len);

    puts("All tests pass.");
}

#endif