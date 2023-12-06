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



/* @brief Function to convert a string to an integer */
FOUNDATIONAL_LIB_FUNC int string_to_int(const char *str) { return atoi(str); }



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

        ;
    }

    va_start(args, format);
    vsnprintf(result, len + 1, format, args);
    va_end(args);

    return result;
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



/* @brief Function to apply a transformation to each element of an array */
FOUNDATIONAL_LIB_FUNC void map_int(int *array, size_t size, int (*transform)(int))
{
    for (size_t i = 0; i < size; i++)
    {
        array[i] = transform(array[i]);
    }
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



/* @brief Function to reject elements based on a condition */
FOUNDATIONAL_LIB_FUNC void *reject_array(const void *source, size_t source_size, size_t elem_size, int (*condition)(const void *), size_t *result_size)
{
    /* @brief  Allocate memory for the result array */
    void *result = FOUNDATIONALLIB_MEMORY_ALLOCATOR_MALLOC(source_size * elem_size);
    if (result == NULL)
    {

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







#endif