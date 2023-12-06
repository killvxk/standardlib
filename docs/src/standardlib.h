/*
    Copyright (c) 2023, Gregory Cohen <gregorycohen2@gmail.com>


    DONATION REQUEST: If this free software has helped you and you find
    it valuable, please consider making a donation to support the ongoing
    development and maintenance of this project. Your contribution helps
    ensure the availability of this library to the community and encourages
    further improvements.


                          Donations can be made at:
                 https://www.paypal.com/paypalme/cstandardlib


                               All rights reserved.



    While the standardlib software library and this "generate custom standardlib"
    file are licensed under the BSD-3 license, the resultant code generated
    from this "generate custom standardlib" script is EXPRESSLY public domain,
    and you are the legal owner if you use it, and can choose any license
    you wish for the resultant code, even if the resultant code is exactly the
    same as the original standardlib library. In this way, this library does
    not limit or restrict the user with licensing complications.







    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions, and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions, and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the [organization] nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
    USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs (types)
struct Dict;
struct FrozenDict;
struct Set;
struct FrozenSet;


// Functions
static inline char *concatenate(const char *str1, const char *str2);
static inline char *concatenate_five_strings(const char *str1, const char *str2, const char *str3, const char *str4, const char *str5);
static inline char *concatenate_four_strings(const char *str1, const char *str2, const char *str3, const char *str4);
static inline char *concatenate_multiple_strings(const char *strings[], size_t num_strings);
static inline char *concatenate_strings(const char *str1, const char *str2);
static inline char *concatenate_three_strings(const char *str1, const char *str2, const char *str3);
static inline char *dict_to_s(struct Dict *dict, int pointer_or_string);
static inline char *dup_format(const char *format, ...);
static inline char first_non_repeating_char(const char *str);
static inline char first_non_repeating(const char *str);
static inline char *format_string(const char *format, ...);
static inline char *frozen_dict_to_s(struct FrozenDict *dict, int pointer_or_string);
static inline char *frozen_set_to_s(struct FrozenSet *dict);
static inline char *int_to_str(int number);
static inline char *join(const char **array, size_t count, const char *delimiter);
static inline char **list_files_with_pattern(const char *directory, const char *pattern, size_t *len);
static inline char *longest_common_prefix(const char **strings, size_t count);
static inline char *longest_common_suffix(const char **strings, size_t count);
static inline char *read_bytes_from_file(const char *filename, size_t num_bytes);
static inline char *read_file(const char *filename);
static inline char *replace_all(const char *str, const char *old_substring, const char *new_substring);
static inline char *reverse_string(const char *str);
static inline char *reverse_words(const char *str);
static inline char *set_to_s(struct Set *dict);
static inline char *shellescape(const char *str);
static inline char **sorted_char_ptrs(char **char_ptrs, size_t size);
static inline char *sorted_chars(char *chars, size_t size);
static inline char **sorted_strings(char **strings, size_t size);
static inline char **split(const char *str, char delimiter, size_t *count);
static inline char *string_to_json(const char *input_string);
static inline char *string_to_lowercase(char *str);
static inline char *string_to_uppercase(char *str);
static inline char *strip(const char *str);
static inline char *to_lowercase(const char *str);
static inline char *to_title_case(const char *str);
static inline char *to_uppercase(const char *str);
static inline char *trim_chars(const char *str, const char *chars_to_trim);
static inline char *trim_whitespace(const char *str);
static inline double calculate_average(const int *array, size_t size);
static inline double calculate_mean(const int *arr, size_t size);
static inline double calculate_median(int *arr, size_t size);
static inline double **sorted_double_ptrs(double **double_ptrs, size_t size);
static inline double *sorted_doubles(double *doubles, size_t size);
static inline float **sorted_float_ptrs(float **float_ptrs, size_t size);
static inline float *sorted_floats(float *floats, size_t size);
static inline int are_all_elements_even(const int *array, size_t size);
static inline int are_all_elements_negative(const int *array, size_t size);
static inline int are_all_elements_odd(const int *array, size_t size);
static inline int are_all_elements_positive(const int *array, size_t size);
static inline int are_all_elements_zero(const int *array, size_t size);
static inline int are_anagrams(const char *str1, const char *str2);
static inline int are_arrays_equal(const int *array1, size_t size1, const int *array2, size_t size2);
static inline int calculate_mode(const int *arr, size_t size);
static inline int calculate_sum(const int *array, size_t size);
static inline int ends_with(const char *str, const char *suffix);
static inline int equal_char(const char *array, const char *array2, size_t size);
static inline int equal_char_ptr(const char **array, const char **array2, size_t size);
static inline int equal_double(const double *array, const double *array2, size_t size);
static inline int equal_double_ptr(const double **array, const double **array2, size_t size);
static inline int equal_float(const float *array, const float *array2, size_t size);
static inline int equal_float_ptr(const float **array, const float **array2, size_t size);
static inline int equal_int(const int *array, const int *array2, size_t size);
static inline int equal_int_ptr(const int **array, const int **array2, size_t size);
static inline int equal_long(const long *array, const long *array2, size_t size);
static inline int equal_long_long(const long long *array, const long long *array2, size_t size);
static inline int equal_long_long_ptr(const long long **array, const long long **array2, size_t size);
static inline int equal_long_ptr(const long **array, const long **array2, size_t size);
static inline int equal_short(const short *array, const short *array2, size_t size);
static inline int equal_short_ptr(const short **array, const short **array2, size_t size);
static inline int equal_size_t(const size_t *array, const size_t *array2, size_t size);
static inline int equal_size_t_ptr(const size_t **array, const size_t **array2, size_t size);
static inline int equal_uchar(const unsigned char *array, const unsigned char *array2, size_t size);
static inline int equal_uchar_ptr(const unsigned char **array, const unsigned char **array2, size_t size);
static inline int equal_uint(const unsigned int *array, const unsigned int *array2, size_t size);
static inline int equal_uint_ptr(const unsigned int **array, const unsigned int **array2, size_t size);
static inline int equal_ulong(const unsigned long *array, const unsigned long *array2, size_t size);
static inline int equal_ulong_long(const unsigned long long *array, const unsigned long long *array2, size_t size);
static inline int equal_ulong_long_ptr(const unsigned long long **array, const unsigned long long **array2, size_t size);
static inline int equal_ulong_ptr(const unsigned long **array, const unsigned long **array2, size_t size);
static inline int equal_ushort(const unsigned short *array, const unsigned short *array2, size_t size);
static inline int equal_ushort_ptr(const unsigned short **array, const unsigned short **array2, size_t size);
static inline int file_exists(const char *filename);
static inline int file_is_directory(const char *filename);
static inline int file_is_executable(const char *filename);
static inline int file_is_readable(const char *filename);
static inline int file_is_regular(const char *filename);
static inline int file_is_writable(const char *filename);
static inline int *find_intersection(const int *array1, size_t size1, const int *array2, size_t size2, size_t *intersection_size);
static inline int find_kth_smallest(int *array, size_t size, size_t k);
static inline int *find_leaders(const int *array, size_t size, size_t *leaders_size);
static inline int *find_longest_increasing_subsequence(const int *array, size_t size, size_t *subsequence_size);
static inline int find_majority_element(const int *array, size_t size);
static inline int find_max(const int *array, size_t size);
static inline int find_maximum_consecutive_sum(const int *array, size_t size);
static inline int find_min(const int *array, size_t size);
static inline int *find_union(const int *array1, size_t size1, const int *array2, size_t size2, size_t *union_size);
static inline int frozen_set_in(struct FrozenSet *dict, const char *key);
static inline int *generate_range(int start, int end, int step, size_t *range_size);
static inline int has_mixed_characters(const char *arr[], size_t size);
static inline int is_alpha(const char *str);
static inline int is_alphanumeric(const char *str);
static inline int is_array_digit(const char *arr[], size_t size);
static inline int is_array_lower(const char *arr[], size_t size);
static inline int is_array_upper(const char *arr[], size_t size);
static inline int is_numeric(const char *str);
static inline int is_palindrome(const char *str);
static inline int is_sorted_ascending(const int *array, size_t size);
static inline int is_sorted_descending(const int *array, size_t size);
static inline int is_string_alpha(const char *str);
static inline int is_string_alphanumeric(const char *str);
static inline int is_string_digit(const char *str);
static inline int is_string_lower(const char *str);
static inline int is_string_printable(const char *str);
static inline int is_string_space(const char *str);
static inline int is_string_upper(const char *str);
static inline int is_valid_integer(const char *str);
static inline int majority_element(const int *arr, size_t size);
static inline int *merge_sorted_arrays(const int *array1, size_t size1, const int *array2, size_t size2, size_t *merged_size);
static inline int set_in(struct Set *dict, const char *key);
static inline int **sorted_int_ptrs(int **int_ptrs, size_t size);
static inline int *sorted_ints(int *ints, size_t size);
static inline long get_file_size(const char *filename);
static inline long long **sorted_long_long_ptrs(long long **long_long_ptrs, size_t size);
static inline long long *sorted_long_longs(long long *long_longs, size_t size);
static inline long **sorted_long_ptrs(long **long_ptrs, size_t size);
static inline long *sorted_longs(long *longs, size_t size);
static inline short **sorted_short_ptrs(short **short_ptrs, size_t size);
static inline short *sorted_shorts(short *shorts, size_t size);
static inline size_t array_length(const char **array, size_t count);
static inline size_t common_prefix_length(const char *str1, const char *str2);
static inline size_t common_suffix_length(const char *str1, const char *str2);
static inline size_t count_occurrences(const char *str, const char *substring);
static inline size_t count_vowels(const char *str);
static inline size_t dict_size(struct Dict *dict);
static inline size_t dict_to_a(struct Dict *dict, char ***keys, void ***values);
static inline size_t find_max_length_bitonic_subarray(const int *array, long size);
static inline size_t frozen_dict_size(struct FrozenDict *dict);
static inline size_t frozen_dict_to_a(struct FrozenDict *dict, char ***keys, void ***values);
static inline size_t frozen_set_size(struct FrozenSet *dict);
static inline size_t frozen_set_to_a(struct FrozenSet *dict, char ***keys, void ***values);
static inline size_t remove_duplicates(int *array, size_t size);
static inline size_t set_size(struct Set *dict);
static inline size_t set_to_a(struct Set *dict, char ***keys);
static inline size_t **sorted_size_t_ptrs(size_t **size_t_ptrs, size_t size);
static inline size_t *sorted_size_ts(size_t *size_ts, size_t size);
static inline ssize_t binary_search(const int *sorted_array, size_t size, int target);
static inline ssize_t find_equilibrium_index(const int *array, size_t size);
static inline ssize_t find_first_of(const char *str, const char *char_set);
static inline ssize_t find_index(const int *array, size_t size, int target);
static inline ssize_t find_last_of(const char *str, const char *char_set);
static inline ssize_t index_of(const char *str, char target);
static inline ssize_t last_index_of(const char *str, char target);
static inline struct Dict *dict_new_instance();
static inline struct FrozenDict *frozen_dict_new_instance(size_t num_args, ...);
static inline struct FrozenSet *frozen_set_new_instance(size_t num_args, ...);
static inline struct Set *set_new_instance();
static inline unsigned char **sorted_uchar_ptrs(unsigned char **uchar_ptrs, size_t size);
static inline unsigned char *sorted_uchars(unsigned char *uchars, size_t size);
static inline unsigned int dict_hash(const char *key, size_t capacity);
static inline unsigned int set_hash(const char *key, size_t capacity);
static inline unsigned int **sorted_uint_ptrs(unsigned int **uint_ptrs, size_t size);
static inline unsigned int *sorted_uints(unsigned int *uints, size_t size);
static inline unsigned long long **sorted_ulong_long_ptrs(unsigned long long **ulong_long_ptrs, size_t size);
static inline unsigned long long *sorted_ulong_longs(unsigned long long *ulong_longs, size_t size);
static inline unsigned long **sorted_ulong_ptrs(unsigned long **ulong_ptrs, size_t size);
static inline unsigned long *sorted_ulongs(unsigned long *ulongs, size_t size);
static inline unsigned short **sorted_ushort_ptrs(unsigned short **ushort_ptrs, size_t size);
static inline unsigned short *sorted_ushorts(unsigned short *ushorts, size_t size);
static inline void append(char ***array, size_t *count, const char *element);
static inline void append_to_file(const char *filename, const char *content);
static inline void *arraydup(const void *arr, size_t num_mem, size_t size);
static inline void array_uniq_adjacent(char *arr[], size_t size);
static inline void array_uniq(char *arr[], size_t size);
static inline void copy_file(const char *source_filename, const char *destination_filename);
static inline void dict_add(struct Dict *dict, const char *key, void *value);
static inline void dict_del(struct Dict *dict, const char *key);
static inline void dict_destructor(struct Dict *dict);
static inline void *dict_get_check(struct Dict *dict, const char *key, int *key_is_in_dict);
static inline void *dict_get(struct Dict *dict, const char *key);
static inline void dict_resize(struct Dict *dict);
static inline void free_array(void **array, size_t len);
static inline void frozen_dict_destructor(struct FrozenDict *dict);
static inline void *frozen_dict_get_check(struct FrozenDict *dict, const char *key, int *key_is_in_dict);
static inline void *frozen_dict_get(struct FrozenDict *dict, const char *key);
static inline void frozen_set_destructor(struct FrozenSet *dict);
static inline void prepend(char ***array, size_t *count, const char *element);
static inline void print_char_array(const char *array, size_t size);
static inline void print_char_ptr_array(const char **array, size_t size);
static inline void print_double_array(const double *array, size_t size);
static inline void print_double_ptr_array(const double **array, size_t size);
static inline void print_float_array(const float *array, size_t size);
static inline void print_float_ptr_array(const float **array, size_t size);
static inline void print_int_array(const int *array, size_t size);
static inline void print_int_ptr_array(const int **array, size_t size);
static inline void print_long_array(const long *array, size_t size);
static inline void print_long_long_array(const long long *array, size_t size);
static inline void print_long_long_ptr_array(const long long **array, size_t size);
static inline void print_long_ptr_array(const long **array, size_t size);
static inline void print_short_array(const short *array, size_t size);
static inline void print_short_ptr_array(const short **array, size_t size);
static inline void print_size_t_array(const size_t *array, size_t size);
static inline void print_size_t_ptr_array(const size_t **array, size_t size);
static inline void print_string_array(char **array, size_t size);
static inline void print_uchar_array(const unsigned char *array, size_t size);
static inline void print_uchar_ptr_array(const unsigned char **array, size_t size);
static inline void print_uint_array(const unsigned int *array, size_t size);
static inline void print_uint_ptr_array(const unsigned int **array, size_t size);
static inline void print_ulong_array(const unsigned long *array, size_t size);
static inline void print_ulong_long_array(const unsigned long long *array, size_t size);
static inline void print_ulong_long_ptr_array(const unsigned long long **array, size_t size);
static inline void print_ulong_ptr_array(const unsigned long **array, size_t size);
static inline void print_ushort_array(const unsigned short *array, size_t size);
static inline void print_ushort_ptr_array(const unsigned short **array, size_t size);
static inline void remove_file(const char *filename);
static inline void *replicate(const void *source, size_t source_size, size_t elem_size, size_t repetitions);
static inline void reverse_array(int *array, size_t size);
static inline void reverse_in_place(char *str);
static inline void rotate_array(int *array, size_t size, unsigned long positions);
static inline void set_add(struct Set *dict, const char *key);
static inline void set_del(struct Set *dict, const char *key);
static inline void set_destructor(struct Set *dict);
static inline void set_resize(struct Set *dict);
static inline void standardlib_error_handler(const char *message);
static inline void transpose(int **matrix, size_t rows, size_t cols);
static inline void write_file(const char *filename, const char *content);
/* See standardlib github repository for license information (https://www.github.com/gregoryc/standardlib) */

/*

==2189186==
==2189186== HEAP SUMMARY:
==2189186==     in use at exit: 0 bytes in 0 blocks
==2189186==   total heap usage: 800,241 allocs, 800,241 frees, 26,986,198 bytes allocated
==2189186==
==2189186== All heap blocks were freed -- no leaks are possible
==2189186==
==2189186== For lists of detected and suppressed errors, rerun with: -s
==2189186== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/
const int STANDARDLIB_HASH_INITIAL_CAPACITY = 16;
const double STANDARDLIB_HASH_LOAD_FACTOR_THRESHOLD = 0.75;

/* Customize this as needed. */
static inline void standardlib_error_handler(const char *message)
{
    perror(message);
    exit(1);
}

static inline void free_array(void **array, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        free(array[i]);
    }
    free(array);
}

/* Function to print a uint array */
static inline void print_uint_array(const unsigned int *array, size_t size)
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

/* Function to print a uint array */
static inline void print_uint_ptr_array(const unsigned int **array, size_t size)
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

/* Function to print a int array */
static inline void print_int_array(const int *array, size_t size)
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

/* Function to print a int array */
static inline void print_int_ptr_array(const int **array, size_t size)
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

/* Function to print a uchar array */
static inline void print_uchar_array(const unsigned char *array, size_t size)
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

/* Function to print a uchar array */
static inline void print_uchar_ptr_array(const unsigned char **array, size_t size)
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

/* Function to print a char array */
static inline void print_char_array(const char *array, size_t size)
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

/* Function to print a char array */
static inline void print_char_ptr_array(const char **array, size_t size)
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
static inline void print_string_array(char **array, size_t size)
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

/* Function to print a ushort array */
static inline void print_ushort_array(const unsigned short *array, size_t size)
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

/* Function to print a ushort array */
static inline void print_ushort_ptr_array(const unsigned short **array, size_t size)
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

/* Function to print a short array */
static inline void print_short_array(const short *array, size_t size)
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

/* Function to print a short array */
static inline void print_short_ptr_array(const short **array, size_t size)
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

/* Function to print a ulong array */
static inline void print_ulong_array(const unsigned long *array, size_t size)
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

/* Function to print a ulong array */
static inline void print_ulong_ptr_array(const unsigned long **array, size_t size)
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

/* Function to print a long array */
static inline void print_long_array(const long *array, size_t size)
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

/* Function to print a long array */
static inline void print_long_ptr_array(const long **array, size_t size)
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

/* Function to print a ulong_long array */
static inline void print_ulong_long_array(const unsigned long long *array, size_t size)
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

/* Function to print a ulong_long array */
static inline void print_ulong_long_ptr_array(const unsigned long long **array, size_t size)
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

/* Function to print a long_long array */
static inline void print_long_long_array(const long long *array, size_t size)
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

/* Function to print a long_long array */
static inline void print_long_long_ptr_array(const long long **array, size_t size)
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

/* Function to print a float array */
static inline void print_float_array(const float *array, size_t size)
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

/* Function to print a float array */
static inline void print_float_ptr_array(const float **array, size_t size)
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

/* Function to print a double array */
static inline void print_double_array(const double *array, size_t size)
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

/* Function to print a double array */
static inline void print_double_ptr_array(const double **array, size_t size)
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

/* Function to print a size_t array */
static inline void print_size_t_array(const size_t *array, size_t size)
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

/* Function to print a size_t array */
static inline void print_size_t_ptr_array(const size_t **array, size_t size)
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

static inline void *arraydup(const void *arr, size_t num_mem, size_t size)
{
    const size_t tot_size = num_mem * size;
    char *duplicate = (char *)malloc(tot_size);

    if (duplicate == NULL)
    {
        /*  Handle memory allocation failure */
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < tot_size; i++)
    {
        duplicate[i] = ((char *)arr)[i];
    }

    return (void *)duplicate;
}

/* Aliases */
static inline void *array_dup(const void *arr, size_t num_mem, size_t size) { return arraydup(arr, num_mem, size); }
static inline void *duparray(const void *arr, size_t num_mem, size_t size) { return arraydup(arr, num_mem, size); }
static inline void *dup_array(const void *arr, size_t num_mem, size_t size) { return arraydup(arr, num_mem, size); }

static inline int equal_uint(const unsigned int *array, const unsigned int *array2, size_t size)
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

static inline int equal_uint_ptr(const unsigned int **array, const unsigned int **array2, size_t size)
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

static inline int equal_int(const int *array, const int *array2, size_t size)
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

static inline int equal_int_ptr(const int **array, const int **array2, size_t size)
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

static inline int equal_uchar(const unsigned char *array, const unsigned char *array2, size_t size)
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

static inline int equal_uchar_ptr(const unsigned char **array, const unsigned char **array2, size_t size)
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

static inline int equal_char(const char *array, const char *array2, size_t size)
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

static inline int equal_char_ptr(const char **array, const char **array2, size_t size)
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

static inline int equal_ushort(const unsigned short *array, const unsigned short *array2, size_t size)
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

static inline int equal_ushort_ptr(const unsigned short **array, const unsigned short **array2, size_t size)
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

static inline int equal_short(const short *array, const short *array2, size_t size)
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

static inline int equal_short_ptr(const short **array, const short **array2, size_t size)
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

static inline int equal_ulong(const unsigned long *array, const unsigned long *array2, size_t size)
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

static inline int equal_ulong_ptr(const unsigned long **array, const unsigned long **array2, size_t size)
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

static inline int equal_long(const long *array, const long *array2, size_t size)
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

static inline int equal_long_ptr(const long **array, const long **array2, size_t size)
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

static inline int equal_ulong_long(const unsigned long long *array, const unsigned long long *array2, size_t size)
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

static inline int equal_ulong_long_ptr(const unsigned long long **array, const unsigned long long **array2, size_t size)
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

static inline int equal_long_long(const long long *array, const long long *array2, size_t size)
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

static inline int equal_long_long_ptr(const long long **array, const long long **array2, size_t size)
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

static inline int equal_float(const float *array, const float *array2, size_t size)
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

static inline int equal_float_ptr(const float **array, const float **array2, size_t size)
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

static inline int equal_double(const double *array, const double *array2, size_t size)
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

static inline int equal_double_ptr(const double **array, const double **array2, size_t size)
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

static inline int equal_size_t(const size_t *array, const size_t *array2, size_t size)
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

static inline int equal_size_t_ptr(const size_t **array, const size_t **array2, size_t size)
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

static inline char *string_to_json(const char *input_string)
{
    size_t input_length = strlen(input_string);
    size_t escaped_length = 0;

    /*  Calculate the length of the escaped string */
    for (size_t i = 0; i < input_length; i++)
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

    /*  Calculate the length of the resulting JSON string */
    size_t json_length = escaped_length + 2; // 2 for double quotes

    /*  Allocate memory for the JSON string */
    char *json_result = (char *)malloc(json_length + 1); // +1 for null terminator

    if (json_result == NULL)
    {
        standardlib_error_handler("Memory allocation failed in string_to_json");
    }

    /*  Add double quotes around the escaped string */
    json_result[0] = '"';

    size_t j = 1;
    for (size_t i = 0; i < input_length; i++)
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

/* Function to trim leading and trailing whitespace from a string */
static inline char *strip(const char *str)
{
    size_t start = 0, end = strlen(str);

    /*  Trim leading whitespace */
    while (isspace(str[start]))
    {
        start++;
    }

    /*  Trim trailing whitespace */
    while (end > start && isspace(str[end - 1]))
    {
        end--;
    }

    /*  Copy the stripped portion into a new string */
    char *result = (char *)malloc(end - start + 1);
    strncpy(result, str + start, end - start);
    result[end - start] = '\0';

    return result;
}

/* Function to split a string into an array based on a delimiter */
static inline char **split(const char *str, char delimiter, size_t *count)
{
    /*  Count the number of tokens */
    *count = 1;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == delimiter)
        {
            (*count)++;
        }
    }

    /*  Allocate memory for the array of strings */
    char **result = (char **)malloc(*count * sizeof(char *));

    size_t tokenIndex = 0;
    size_t tokenStart = 0;

    /*  Split the string into tokens */
    for (size_t i = 0; i <= strlen(str); i++)
    {
        if (str[i] == delimiter || str[i] == '\0')
        {
            size_t tokenLength = i - tokenStart;
            result[tokenIndex] = (char *)malloc(tokenLength + 1);
            strncpy(result[tokenIndex], str + tokenStart, tokenLength);
            result[tokenIndex][tokenLength] = '\0';
            tokenStart = i + 1;
            tokenIndex++;
        }
    }

    return result;
}

/* Function to join an array of strings into a single string with a delimiter */
static inline char *join(const char **array, size_t count, const char *delimiter)
{
    size_t *lens = (size_t *)malloc(sizeof(size_t) * count);
    const size_t delimeter_length = strlen(delimiter);
    /*  Calculate the total length of the resulting string */
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

    /*  Allocate memory for the resulting string */
    char *result = (char *)malloc(totalLength);
    size_t array_index = 0;

    size_t len_so_far = 0;

    /*  Concatenate strings with the delimiter */
    for (; array_index < count; array_index++)
    {
        const size_t len = lens[array_index];

        /*  Copy str */
        for (size_t x = 0; x < len; ++x)
        {
            result[len_so_far + x] = array[array_index][x];
        }

        len_so_far += len;
        if (array_index < count - 1)
        {
            /*  Copy delimiter */
            for (size_t i = 0; i < delimeter_length; ++i)
            {
                result[len_so_far + i] = delimiter[i];
            }
            len_so_far += delimeter_length;
        }
    }

    result[len_so_far] = '\0';

    free(lens);

    return result;
}



/* Function to append a new element to the end of an array */
static inline void append(char ***array, size_t *count, const char *element)
{
    (*count)++;
    const size_t new_size = (size_t)(1.5 * (*count)) + 20;

    if (new_size > *count)
    {
        *array = (char **)realloc(*array, new_size * sizeof(char *));
    }

    (*array)[*count - 1] = strdup(element);
}

/* Function to prepend a new element to the beginning of an array */
static inline void prepend(char ***array, size_t *count, const char *element)
{
    (*count)++;
    const size_t new_size = (size_t)(1.5 * (*count)) + 20;

    if (new_size > *count)
    {
        *array = (char **)realloc(*array, new_size * sizeof(char *));
    }

    memmove(*array + 1, *array, (*count - 1) * sizeof(char *));
    (*array)[0] = strdup(element);
}

/* Function to get the length of an array */
static inline size_t array_length(const char **array, size_t count)
{
    size_t length = 0;
    for (size_t i = 0; i < count; i++)
    {
        length += strlen(array[i]);
    }
    return length;
}



/* Function to escape a string for use as a shell command argument */
static inline char *shellescape(const char *str)
{
    size_t len = strlen(str);
    char *escaped = (char *)malloc(2 * len + 3); // Maximum expansion is doubling + quotes + null terminator

    /*  Add quotes around the string */
    escaped[0] = '"';
    size_t i, j;
    for (i = 1, j = 0; j < len; i++, j++)
    {
        if (str[j] == '"')
        {
            escaped[i++] = '\\'; // Escape double quotes
        }
        escaped[i] = str[j];
    }
    escaped[i++] = '"';
    escaped[i] = '\0';

    return escaped;
}

/* Function to reverse a string */
static inline char *reverse_string(const char *str)
{
    char *new_str = strdup(str);
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



static inline char *to_lowercase(const char *str)
{
    size_t len = strlen(str);
    char *lowercase = (char *)malloc(len + 1);

    for (size_t i = 0; i < len; i++)
    {
        lowercase[i] = tolower(str[i]);
    }
    lowercase[len] = '\0';

    return lowercase;
}

/* Function to convert a string to uppercase */
static inline char *to_uppercase(const char *str)
{
    size_t len = strlen(str);
    char *uppercase = (char *)malloc(len + 1);

    for (size_t i = 0; i < len; i++)
    {
        uppercase[i] = toupper(str[i]);
    }
    uppercase[len] = '\0';

    return uppercase;
}

static inline int starts_with(const char *str, const char *prefix) { return strncmp(str, prefix, strlen(prefix)) == 0; }

/* Function to check if a string ends with a specified suffix */
static inline int ends_with(const char *str, const char *suffix)
{
    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);

    if (suffix_len > str_len)
    {
        return 0; // Suffix is longer than the string
    }

    return strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0;
}



/* Function to replace all occurrences of a substring in a string */
static inline char *replace_all(const char *str, const char *old_substring, const char *new_substring)
{
    char *result = strdup(str);
    char *pos = result;

    while ((pos = strstr(pos, old_substring)) != NULL)
    {
        /*  Calculate the lengths before and after the old substring */
        size_t before_len = pos - result;
        size_t after_len = strlen(pos + strlen(old_substring));

        /*  Allocate memory for the modified string */
        char *new_str = (char *)malloc(before_len + strlen(new_substring) + after_len + 1);

        /*  Copy the portions before, the new substring, and after */
        strncpy(new_str, result, before_len);
        strcpy(new_str + before_len, new_substring);
        strcpy(new_str + before_len + strlen(new_substring), pos + strlen(old_substring));

        /*  Free the old result and update it */
        free(result);
        result = new_str;

        /*  Move the position after the newly inserted substring */
        pos = new_str + before_len + strlen(new_substring);
    }

    return result;
}

/* Function to count the occurrences of a substring in a string */
static inline size_t count_occurrences(const char *str, const char *substring)
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

/* Function to trim leading and trailing characters from a string */
static inline char *trim_chars(const char *str, const char *chars_to_trim)
{
    size_t start = 0, end = strlen(str);

    /*  Trim leading characters */
    while (strchr(chars_to_trim, str[start]) != NULL)
    {
        start++;
    }

    /*  Trim trailing characters */
    while (end > start && strchr(chars_to_trim, str[end - 1]) != NULL)
    {
        end--;
    }

    /*  Copy the trimmed portion into a new string */
    char *result = (char *)malloc(end - start + 1);
    strncpy(result, str + start, end - start);
    result[end - start] = '\0';

    return result;
}



/* Function to find the index of the first occurrence of a character in a string */
static inline ssize_t index_of(const char *str, char target)
{
    const char *result = strchr(str, target);
    return result != NULL ? result - str : -1;
}

/* Function to find the index of the last occurrence of a character in a string */
static inline ssize_t last_index_of(const char *str, char target)
{
    const char *result = strrchr(str, target);
    return result != NULL ? result - str : -1;
}

/* Function to concatenate multiple strings into a new string */
static inline char *concatenate(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char *result = (char *)malloc(len1 + len2 + 1);
    strcpy(result, str1);
    strcat(result, str2);

    return result;
}


static inline char *reverse_words(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    /*  Copy the input string to a mutable buffer */
    char *reversedStr = strdup(str);
    if (reversedStr == NULL)
    {
        /*  Memory allocation failure */
        return NULL;
    }

    /*  Find the length of the string */
    size_t length = strlen(reversedStr);

    /*  Reverse the entire string */
    for (size_t i = 0; i < length / 2; ++i)
    {
        char temp = reversedStr[i];
        reversedStr[i] = reversedStr[length - i - 1];
        reversedStr[length - i - 1] = temp;
    }

    /*  Reverse each word in the string */
    char *start = reversedStr;
    char *end = reversedStr;

    while (*end)
    {
        if (*end == ' ')
        {
            /*  Reverse the word */
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

    /*  Reverse the last word (or the only word if there's only one) */
    size_t lastWordLength = end - start;
    for (size_t i = 0; i < lastWordLength / 2; ++i)
    {
        char temp = start[i];
        start[i] = start[lastWordLength - i - 1];
        start[lastWordLength - i - 1] = temp;
    }

    return reversedStr;
}

/* Function to check if a string is a palindrome */
static inline int is_palindrome(const char *str)
{
    size_t len = strlen(str);

    for (size_t i = 0, j = len - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

/* Function to find the first non-repeating character in a string */
static inline char first_non_repeating(const char *str)
{
    size_t len = strlen(str);
    int char_count[256] = {0}; // Assuming ASCII characters

    /*  Count occurrences of each character */
    for (size_t i = 0; i < len; i++)
    {
        char_count[(unsigned char)str[i]]++;
    }

    /*  Find the first non-repeating character */
    for (size_t i = 0; i < len; i++)
    {
        if (char_count[(unsigned char)str[i]] == 1)
        {
            return str[i];
        }
    }

    return '\0'; // No non-repeating character found
}



/* Function to check if a string contains only alphabetic characters */
static inline int is_alpha(const char *str)
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

/* Function to check if a string contains only numeric characters */
static inline int is_numeric(const char *str)
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

/* Function to check if a string contains only alphanumeric characters */
static inline int is_alphanumeric(const char *str)
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

/* Function to count the number of vowels in a string */
static inline size_t count_vowels(const char *str)
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



/* Function to find the longest common prefix among an array of strings */
static inline char *longest_common_prefix(const char **strings, size_t count)
{
    if (count == 0)
    {
        return strdup(""); // Empty string for an empty array
    }

    size_t min_len = strlen(strings[0]);

    /*  Find the minimum length among the strings */
    for (size_t i = 1; i < count; i++)
    {
        size_t current_len = strlen(strings[i]);
        if (current_len < min_len)
        {
            min_len = current_len;
        }
    }

    /*  Compare characters across the strings until a mismatch is found */
    for (size_t i = 0; i < min_len; i++)
    {
        for (size_t j = 1; j < count; j++)
        {
            if (strings[j][i] != strings[0][i])
            {
                /*  Mismatch found, return the prefix up to this point */
                char *result = (char *)malloc(i + 1);
                strncpy(result, strings[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }

    /*  All strings match up to the minimum length, return the entire prefix */
    return strdup(strings[0]);
}

/* Function to find the longest common suffix among an array of strings */
static inline char *longest_common_suffix(const char **strings, size_t count)
{
    if (count == 0)
    {
        return strdup(""); // Empty string for an empty array
    }

    size_t min_len = strlen(strings[0]);

    /*  Find the minimum length among the strings */
    for (size_t i = 1; i < count; i++)
    {
        size_t current_len = strlen(strings[i]);
        if (current_len < min_len)
        {
            min_len = current_len;
        }
    }

    /*  Compare characters across the strings until a mismatch is found */
    for (size_t i = 0; i < min_len; i++)
    {
        for (size_t j = 1; j < count; j++)
        {
            size_t current_len = strlen(strings[j]);
            if (strings[j][current_len - i - 1] != strings[0][min_len - i - 1])
            {
                /*  Mismatch found, return the suffix up to this point */
                char *result = (char *)malloc(i + 1);
                strncpy(result, strings[0] + min_len - i, i);
                result[i] = '\0';
                return result;
            }
        }
    }

    /*  All strings match up to the minimum length, return the entire suffix */
    return strdup(strings[0] + min_len);
}

/* Function to convert an integer to a string */
static inline char *int_to_str(int number)
{
    char buffer[21]; // Assuming a maximum of 21 digits for an int, 2 ** 64 length
                     /*  is 20 plus nul char */
    sprintf(buffer, "%d", number);
    return strdup(buffer);
}



static inline double str_to_double(const char *str) { return atof(str); }

/* Function to find the first occurrence of any character from a set in a string */
static inline ssize_t find_first_of(const char *str, const char *char_set)
{
    const char *result = strpbrk(str, char_set);
    return result != NULL ? result - str : -1;
}

/* Function to find the last occurrence of any character from a set in a string */
static inline ssize_t find_last_of(const char *str, const char *char_set)
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



/* Function to remove leading and trailing whitespace from a string */
static inline char *trim_whitespace(const char *str)
{
    size_t start = 0, end = strlen(str);

    /*  Trim leading whitespace */
    while (isspace(str[start]))
    {
        start++;
    }

    /*  Trim trailing whitespace */
    while (end > start && isspace(str[end - 1]))
    {
        end--;
    }

    /*  Copy the trimmed portion into a new string */
    char *result = (char *)malloc(end - start + 1);
    strncpy(result, str + start, end - start);
    result[end - start] = '\0';

    return result;
}

/* Function to reverse a string in place */
static inline void reverse_in_place(char *str)
{
    size_t len = strlen(str);

    /*  Swap characters from both ends towards the center */
    for (size_t i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}



/* Function to check if a string is a valid integer */
static inline int is_valid_integer(const char *str)
{
    if (str == NULL || *str == '\0')
    {
        return 0; // Empty string is not a valid integer
    }

    /*  Check for optional sign */
    if (*str == '+' || *str == '-')
    {
        str++;
    }

    /*  Check for at least one digit */
    if (!isdigit(*str))
    {
        return 0;
    }

    /*  Check for remaining digits */
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

/* Function to check if two strings are anagrams */
static inline int are_anagrams(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    if (len1 != len2)
    {
        return 0; // Different lengths, not anagrams
    }

    /*  Create character frequency arrays */
    int count1[256] = {0}; // Assuming ASCII characters
    int count2[256] = {0};

    /*  Increment counts for characters in the first string */
    for (size_t i = 0; i < len1; i++)
    {
        count1[(unsigned char)str1[i]]++;
    }

    /*  Decrement counts for characters in the second string */
    for (size_t i = 0; i < len2; i++)
    {
        count2[(unsigned char)str2[i]]--;
    }

    /*  Check if both arrays have zeros, indicating anagrams */
    for (int i = 0; i < 256; i++)
    {
        if (count1[i] != 0 || count2[i] != 0)
        {
            return 0; // Non-zero count, not anagrams
        }
    }

    return 1; // Anagrams
}



/* Function to find the length of the common prefix of two strings */
static inline size_t common_prefix_length(const char *str1, const char *str2)
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

/* Function to find the length of the common suffix of two strings */
static inline size_t common_suffix_length(const char *str1, const char *str2)
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

/* Function to convert a string to title case */
static inline char *to_title_case(const char *str)
{
    size_t len = strlen(str);
    char *title_case = (char *)malloc(len + 1);
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



/* Function to find the maximum element in an array of integers */
static inline int find_max(const int *array, size_t size)
{
    if (size == 0)
    {
        /*  Handle empty array case */
        standardlib_error_handler("Error: Empty array passed to find_max.\n");
        ;
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

/* Function to find the minimum element in an array of integers */
static inline int find_min(const int *array, size_t size)
{
    if (size == 0)
    {
        /*  Handle empty array case */
        standardlib_error_handler("Error: Empty array passed to find_min.\n");
        ;
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

/* Function to calculate the sum of elements in an array of integers */
static inline int calculate_sum(const int *array, size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

/* Function to reverse an array of integers in place */
static inline void reverse_array(int *array, size_t size)
{
    for (size_t i = 0, j = size - 1; i < j; i++, j--)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}



/* Function to check if an array of integers is sorted in ascending order */
static inline int is_sorted_ascending(const int *array, size_t size)
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

/* Function to check if an array of integers is sorted in descending order */
static inline int is_sorted_descending(const int *array, size_t size)
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

/* Function to remove duplicates from an array of integers and return the new */
/* size */
static inline size_t remove_duplicates(int *array, size_t size)
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

/* Function to rotate an array of integers to the right by a given number of */
/* positions */
static inline void rotate_array(int *array, size_t size, unsigned long positions)
{
    positions = positions % size; // Ensure positions is within array size

    if (positions == 0)
    {
        return; // No rotation needed
    }

    int *temp = (int *)malloc(positions * sizeof(int));

    /*  Copy the last 'positions' elements to temp */
    for (size_t i = size - positions, j = 0; i < size; i++, j++)
    {
        temp[j] = array[i];
    }

    /*  Shift the remaining elements to the right */
    for (size_t i = size - 1; i >= positions; i--)
    {
        array[i] = array[i - positions];
    }

    /*  Copy the elements from temp to the beginning of the array */
    for (size_t i = 0; i < positions; i++)
    {
        array[i] = temp[i];
    }

    free(temp);
}



/* Function to find the index of a specific element in an array of integers */
static inline ssize_t find_index(const int *array, size_t size, int target)
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

/* Function to check if two arrays of integers are equal */
static inline int are_arrays_equal(const int *array1, size_t size1, const int *array2, size_t size2)
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

/* Function to merge two sorted arrays of integers into a new sorted array */
static inline int *merge_sorted_arrays(const int *array1, size_t size1, const int *array2, size_t size2, size_t *merged_size)
{
    size_t merged_capacity = size1 + size2;
    int *merged_array = (int *)malloc(merged_capacity * sizeof(int));

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

    /*  Copy the remaining elements from both arrays */
    while (i < size1)
    {
        merged_array[k++] = array1[i++];
    }

    while (j < size2)
    {
        merged_array[k++] = array2[j++];
    }

    *merged_size = k;
    return (int *)realloc(merged_array,
                          k * sizeof(int)); // Adjust the size of the merged array
}



/* Function to find the intersection of two arrays of integers */
static inline int *find_intersection(const int *array1, size_t size1, const int *array2, size_t size2, size_t *intersection_size)
{
    size_t min_size = (size1 < size2) ? size1 : size2;
    int *intersection = (int *)malloc(min_size * sizeof(int));

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
    return (int *)realloc(intersection,
                          k * sizeof(int)); // Adjust the size of the intersection array
}

/* Function to perform a binary search on a sorted array and return the index of */
/* the target element */
static inline ssize_t binary_search(const int *sorted_array, size_t size, int target)
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



/* Function to find the union of two arrays of integers */
static inline int *find_union(const int *array1, size_t size1, const int *array2, size_t size2, size_t *union_size)
{
    size_t max_size = size1 + size2;
    int *union_array = (int *)malloc(max_size * sizeof(int));

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

    /*  Copy the remaining elements from both arrays */
    while (i < size1)
    {
        union_array[k++] = array1[i++];
    }

    while (j < size2)
    {
        union_array[k++] = array2[j++];
    }

    *union_size = k;
    return (int *)realloc(union_array,
                          k * sizeof(int)); // Adjust the size of the union array
}

/* Function to find the kth smallest element in an array of integers */
/* (QuickSelect algorithm) */
static inline int find_kth_smallest(int *array, size_t size, size_t k)
{
    if (k > 0 && k <= size)
    {
        /*  Perform QuickSelect */
        size_t low = 0;
        size_t high = size - 1;

        while (low <= high)
        {
            size_t pivot_index = low + rand() % (high - low + 1);
            int pivot = array[pivot_index];

            /*  Partition the array */
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
                    /*  Swap array[i] and array[j] */
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    i++;
                    j--;
                }
            }

            /*  Recursively search in the appropriate partition */
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

    standardlib_error_handler("Error: Invalid value of k for find_kth_smallest.\n");
    return -1;
}



/* Function to find the maximum consecutive sum in an array of integers */
/* (Kadane's Algorithm) */
static inline int find_maximum_consecutive_sum(const int *array, size_t size)
{
    if (size == 0)
    {
        standardlib_error_handler("Error: Empty array passed to find_maximum_consecutive_sum.\n");
        ;
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

/* Function to find the majority element in an array (Boyer-Moore Voting */
/* Algorithm) */
static inline int find_majority_element(const int *array, size_t size)
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

    /*  Verify if the candidate is the majority element */
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
    else
    {
        standardlib_error_handler("Error: No majority element found.\n");
    }

    return -1;
}



/* Function to find the leaders in an array (elements greater than all elements */
/* to their right) */
static inline int *find_leaders(const int *array, size_t size, size_t *leaders_size)
{
    int max_right = array[size - 1];
    int *leaders = (int *)malloc(size * sizeof(int));
    size_t leader_count = 0;

    /*  The last element is always a leader */
    leaders[leader_count++] = max_right;

    /*  Traverse the array from right to left to find leaders */
    for (int i = size - 2; i >= 0; i--)
    {
        if (array[i] > max_right)
        {
            max_right = array[i];
            leaders[leader_count++] = max_right;
        }
    }

    *leaders_size = leader_count;
    return (int *)realloc(leaders,
                          leader_count * sizeof(int)); // Adjust the size of the leaders array
}

/* Function to find the equilibrium index in an array */
static inline ssize_t find_equilibrium_index(const int *array, size_t size)
{
    int total_sum = 0;
    int left_sum = 0;

    /*  Calculate the total sum of the array */
    for (size_t i = 0; i < size; i++)
    {
        total_sum += array[i];
    }

    /*  Traverse the array to find the equilibrium index */
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



/* Function to find the longest increasing subsequence in an array */
static inline int *find_longest_increasing_subsequence(const int *array, size_t size, size_t *subsequence_size)
{
    int *lis = (int *)malloc(size * sizeof(int));
    int *previous_index = (int *)malloc(size * sizeof(int));
    size_t lis_end = 0;

    /*  Initialize lis array */
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

    /*  Reconstruct the LIS */
    size_t index = lis_end;
    size_t count = 0;
    while (index != (size_t)-1)
    {
        count++;
        index = previous_index[index];
    }

    int *longest_increasing_subsequence = (int *)malloc(count * sizeof(int));
    index = lis_end;
    for (size_t i = count; i > 0; i--)
    {
        longest_increasing_subsequence[i - 1] = array[index];
        index = previous_index[index];
    }

    *subsequence_size = count;
    free(lis);
    free(previous_index);
    return longest_increasing_subsequence;
}

/* Function to find the maximum length bitonic subarray in an array */
static inline size_t find_max_length_bitonic_subarray(const int *array, long size)
{
    int *increasing = (int *)malloc(size * sizeof(int));
    int *decreasing = (int *)malloc(size * sizeof(int));

    increasing[0] = 1;
    decreasing[size - 1] = 1;

    /*  Calculate the length of the increasing subarray ending at each position */
    for (long i = 1; i < size; i++)
    {
        increasing[i] = (array[i] > array[i - 1]) ? increasing[i - 1] + 1 : 1;
    }

    /*  Calculate the length of the decreasing subarray starting at each position */
    for (long i = size - 2; i >= 0; i--)
    {
        decreasing[i] = (array[i] > array[i + 1]) ? decreasing[i + 1] + 1 : 1;
    }

    size_t max_length = 1;

    /*  Find the maximum length bitonic subarray */
    for (long i = 0; i < size; i++)
    {
        size_t length = increasing[i] + decreasing[i] - 1;
        if (length > max_length)
        {
            max_length = length;
        }
    }

    free(increasing);
    free(decreasing);
    return max_length;
}



/* Function to generate a range of integers */
static inline int *generate_range(int start, int end, int step, size_t *range_size)
{
    if (start > end || step == 0)
    {
        standardlib_error_handler("Error: Invalid parameters for generate_range.\n");
        ;
    }

    size_t size = (end - start) / step + 1;
    int *range = (int *)malloc(size * sizeof(int));

    for (size_t i = 0, value = start; i < size; i++, value += step)
    {
        range[i] = value;
    }

    *range_size = size;
    return range;
}


static inline int cmpstringp(const void *p1, const void *p2) { return strcmp(*(const char **)p1, *(const char **)p2); }

static inline void sort_strings(char **strings, size_t size) { qsort(strings, size, sizeof(char *), cmpstringp); }

static inline char **sorted_strings(char **strings, size_t size)
{
    char **dup = (char **)array_dup(strings, size, sizeof(char *));
    qsort(dup, size, sizeof(char *), cmpstringp);
    return dup;
}
static inline int cmp_uints(const void *a, const void *b) { return (*(unsigned int *)a - *(unsigned int *)b); }
static inline void sort_uints(unsigned int *uints, size_t size) { qsort(uints, size, sizeof(unsigned int), cmp_uints); }
static inline unsigned int *sorted_uints(unsigned int *uints, size_t size)
{
    unsigned int *dup_uints = (unsigned int *)duparray(uints, size, sizeof(unsigned int));
    qsort(uints, size, sizeof(unsigned int), cmp_uints);
    return dup_uints;
}

static inline int cmp_uint_ptrs(const void *a, const void *b) { return (*(unsigned int **)a - *(unsigned int **)b); }
static inline void sort_uint_ptrs(unsigned int **uint_ptrs, size_t size) { qsort(uint_ptrs, size, sizeof(unsigned int *), cmp_uint_ptrs); }
static inline unsigned int **sorted_uint_ptrs(unsigned int **uint_ptrs, size_t size)
{
    unsigned int **dup_uint_ptrs = (unsigned int **)duparray(uint_ptrs, size, sizeof(unsigned int *));
    qsort(uint_ptrs, size, sizeof(unsigned int *), cmp_uint_ptrs);
    return dup_uint_ptrs;
}

static inline int cmp_ints(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
static inline void sort_ints(int *ints, size_t size) { qsort(ints, size, sizeof(int), cmp_ints); }
static inline int *sorted_ints(int *ints, size_t size)
{
    int *dup_ints = (int *)duparray(ints, size, sizeof(int));
    qsort(ints, size, sizeof(int), cmp_ints);
    return dup_ints;
}

static inline int cmp_int_ptrs(const void *a, const void *b) { return (*(int **)a - *(int **)b); }
static inline void sort_int_ptrs(int **int_ptrs, size_t size) { qsort(int_ptrs, size, sizeof(int *), cmp_int_ptrs); }
static inline int **sorted_int_ptrs(int **int_ptrs, size_t size)
{
    int **dup_int_ptrs = (int **)duparray(int_ptrs, size, sizeof(int *));
    qsort(int_ptrs, size, sizeof(int *), cmp_int_ptrs);
    return dup_int_ptrs;
}

static inline int cmp_uchars(const void *a, const void *b) { return (*(unsigned char *)a - *(unsigned char *)b); }
static inline void sort_uchars(unsigned char *uchars, size_t size) { qsort(uchars, size, sizeof(unsigned char), cmp_uchars); }
static inline unsigned char *sorted_uchars(unsigned char *uchars, size_t size)
{
    unsigned char *dup_uchars = (unsigned char *)duparray(uchars, size, sizeof(unsigned char));
    qsort(uchars, size, sizeof(unsigned char), cmp_uchars);
    return dup_uchars;
}

static inline int cmp_uchar_ptrs(const void *a, const void *b) { return (*(unsigned char **)a - *(unsigned char **)b); }
static inline void sort_uchar_ptrs(unsigned char **uchar_ptrs, size_t size) { qsort(uchar_ptrs, size, sizeof(unsigned char *), cmp_uchar_ptrs); }
static inline unsigned char **sorted_uchar_ptrs(unsigned char **uchar_ptrs, size_t size)
{
    unsigned char **dup_uchar_ptrs = (unsigned char **)duparray(uchar_ptrs, size, sizeof(unsigned char *));
    qsort(uchar_ptrs, size, sizeof(unsigned char *), cmp_uchar_ptrs);
    return dup_uchar_ptrs;
}

static inline int cmp_chars(const void *a, const void *b) { return (*(char *)a - *(char *)b); }
static inline void sort_chars(char *chars, size_t size) { qsort(chars, size, sizeof(char), cmp_chars); }
static inline char *sorted_chars(char *chars, size_t size)
{
    char *dup_chars = (char *)duparray(chars, size, sizeof(char));
    qsort(chars, size, sizeof(char), cmp_chars);
    return dup_chars;
}

static inline int cmp_char_ptrs(const void *a, const void *b) { return (*(char **)a - *(char **)b); }
static inline void sort_char_ptrs(char **char_ptrs, size_t size) { qsort(char_ptrs, size, sizeof(char *), cmp_char_ptrs); }
static inline char **sorted_char_ptrs(char **char_ptrs, size_t size)
{
    char **dup_char_ptrs = (char **)duparray(char_ptrs, size, sizeof(char *));
    qsort(char_ptrs, size, sizeof(char *), cmp_char_ptrs);
    return dup_char_ptrs;
}

static inline int cmp_ushorts(const void *a, const void *b) { return (*(unsigned short *)a - *(unsigned short *)b); }
static inline void sort_ushorts(unsigned short *ushorts, size_t size) { qsort(ushorts, size, sizeof(unsigned short), cmp_ushorts); }
static inline unsigned short *sorted_ushorts(unsigned short *ushorts, size_t size)
{
    unsigned short *dup_ushorts = (unsigned short *)duparray(ushorts, size, sizeof(unsigned short));
    qsort(ushorts, size, sizeof(unsigned short), cmp_ushorts);
    return dup_ushorts;
}

static inline int cmp_ushort_ptrs(const void *a, const void *b) { return (*(unsigned short **)a - *(unsigned short **)b); }
static inline void sort_ushort_ptrs(unsigned short **ushort_ptrs, size_t size) { qsort(ushort_ptrs, size, sizeof(unsigned short *), cmp_ushort_ptrs); }
static inline unsigned short **sorted_ushort_ptrs(unsigned short **ushort_ptrs, size_t size)
{
    unsigned short **dup_ushort_ptrs = (unsigned short **)duparray(ushort_ptrs, size, sizeof(unsigned short *));
    qsort(ushort_ptrs, size, sizeof(unsigned short *), cmp_ushort_ptrs);
    return dup_ushort_ptrs;
}

static inline int cmp_shorts(const void *a, const void *b) { return (*(short *)a - *(short *)b); }
static inline void sort_shorts(short *shorts, size_t size) { qsort(shorts, size, sizeof(short), cmp_shorts); }
static inline short *sorted_shorts(short *shorts, size_t size)
{
    short *dup_shorts = (short *)duparray(shorts, size, sizeof(short));
    qsort(shorts, size, sizeof(short), cmp_shorts);
    return dup_shorts;
}

static inline int cmp_short_ptrs(const void *a, const void *b) { return (*(short **)a - *(short **)b); }
static inline void sort_short_ptrs(short **short_ptrs, size_t size) { qsort(short_ptrs, size, sizeof(short *), cmp_short_ptrs); }
static inline short **sorted_short_ptrs(short **short_ptrs, size_t size)
{
    short **dup_short_ptrs = (short **)duparray(short_ptrs, size, sizeof(short *));
    qsort(short_ptrs, size, sizeof(short *), cmp_short_ptrs);
    return dup_short_ptrs;
}

static inline int cmp_ulongs(const void *a, const void *b) { return (*(unsigned long *)a - *(unsigned long *)b); }
static inline void sort_ulongs(unsigned long *ulongs, size_t size) { qsort(ulongs, size, sizeof(unsigned long), cmp_ulongs); }
static inline unsigned long *sorted_ulongs(unsigned long *ulongs, size_t size)
{
    unsigned long *dup_ulongs = (unsigned long *)duparray(ulongs, size, sizeof(unsigned long));
    qsort(ulongs, size, sizeof(unsigned long), cmp_ulongs);
    return dup_ulongs;
}

static inline int cmp_ulong_ptrs(const void *a, const void *b) { return (*(unsigned long **)a - *(unsigned long **)b); }
static inline void sort_ulong_ptrs(unsigned long **ulong_ptrs, size_t size) { qsort(ulong_ptrs, size, sizeof(unsigned long *), cmp_ulong_ptrs); }
static inline unsigned long **sorted_ulong_ptrs(unsigned long **ulong_ptrs, size_t size)
{
    unsigned long **dup_ulong_ptrs = (unsigned long **)duparray(ulong_ptrs, size, sizeof(unsigned long *));
    qsort(ulong_ptrs, size, sizeof(unsigned long *), cmp_ulong_ptrs);
    return dup_ulong_ptrs;
}

static inline int cmp_longs(const void *a, const void *b) { return (*(long *)a - *(long *)b); }
static inline void sort_longs(long *longs, size_t size) { qsort(longs, size, sizeof(long), cmp_longs); }
static inline long *sorted_longs(long *longs, size_t size)
{
    long *dup_longs = (long *)duparray(longs, size, sizeof(long));
    qsort(longs, size, sizeof(long), cmp_longs);
    return dup_longs;
}

static inline int cmp_long_ptrs(const void *a, const void *b) { return (*(long **)a - *(long **)b); }
static inline void sort_long_ptrs(long **long_ptrs, size_t size) { qsort(long_ptrs, size, sizeof(long *), cmp_long_ptrs); }
static inline long **sorted_long_ptrs(long **long_ptrs, size_t size)
{
    long **dup_long_ptrs = (long **)duparray(long_ptrs, size, sizeof(long *));
    qsort(long_ptrs, size, sizeof(long *), cmp_long_ptrs);
    return dup_long_ptrs;
}

static inline int cmp_ulong_longs(const void *a, const void *b) { return (*(unsigned long long *)a - *(unsigned long long *)b); }
static inline void sort_ulong_longs(unsigned long long *ulong_longs, size_t size) { qsort(ulong_longs, size, sizeof(unsigned long long), cmp_ulong_longs); }
static inline unsigned long long *sorted_ulong_longs(unsigned long long *ulong_longs, size_t size)
{
    unsigned long long *dup_ulong_longs = (unsigned long long *)duparray(ulong_longs, size, sizeof(unsigned long long));
    qsort(ulong_longs, size, sizeof(unsigned long long), cmp_ulong_longs);
    return dup_ulong_longs;
}

static inline int cmp_ulong_long_ptrs(const void *a, const void *b) { return (*(unsigned long long **)a - *(unsigned long long **)b); }
static inline void sort_ulong_long_ptrs(unsigned long long **ulong_long_ptrs, size_t size) { qsort(ulong_long_ptrs, size, sizeof(unsigned long long *), cmp_ulong_long_ptrs); }
static inline unsigned long long **sorted_ulong_long_ptrs(unsigned long long **ulong_long_ptrs, size_t size)
{
    unsigned long long **dup_ulong_long_ptrs = (unsigned long long **)duparray(ulong_long_ptrs, size, sizeof(unsigned long long *));
    qsort(ulong_long_ptrs, size, sizeof(unsigned long long *), cmp_ulong_long_ptrs);
    return dup_ulong_long_ptrs;
}

static inline int cmp_long_longs(const void *a, const void *b) { return (*(long long *)a - *(long long *)b); }
static inline void sort_long_longs(long long *long_longs, size_t size) { qsort(long_longs, size, sizeof(long long), cmp_long_longs); }
static inline long long *sorted_long_longs(long long *long_longs, size_t size)
{
    long long *dup_long_longs = (long long *)duparray(long_longs, size, sizeof(long long));
    qsort(long_longs, size, sizeof(long long), cmp_long_longs);
    return dup_long_longs;
}

static inline int cmp_long_long_ptrs(const void *a, const void *b) { return (*(long long **)a - *(long long **)b); }
static inline void sort_long_long_ptrs(long long **long_long_ptrs, size_t size) { qsort(long_long_ptrs, size, sizeof(long long *), cmp_long_long_ptrs); }
static inline long long **sorted_long_long_ptrs(long long **long_long_ptrs, size_t size)
{
    long long **dup_long_long_ptrs = (long long **)duparray(long_long_ptrs, size, sizeof(long long *));
    qsort(long_long_ptrs, size, sizeof(long long *), cmp_long_long_ptrs);
    return dup_long_long_ptrs;
}

static inline int cmp_floats(const void *a, const void *b) { return (*(float *)a - *(float *)b); }
static inline void sort_floats(float *floats, size_t size) { qsort(floats, size, sizeof(float), cmp_floats); }
static inline float *sorted_floats(float *floats, size_t size)
{
    float *dup_floats = (float *)duparray(floats, size, sizeof(float));
    qsort(floats, size, sizeof(float), cmp_floats);
    return dup_floats;
}

static inline int cmp_float_ptrs(const void *a, const void *b) { return (*(float **)a - *(float **)b); }
static inline void sort_float_ptrs(float **float_ptrs, size_t size) { qsort(float_ptrs, size, sizeof(float *), cmp_float_ptrs); }
static inline float **sorted_float_ptrs(float **float_ptrs, size_t size)
{
    float **dup_float_ptrs = (float **)duparray(float_ptrs, size, sizeof(float *));
    qsort(float_ptrs, size, sizeof(float *), cmp_float_ptrs);
    return dup_float_ptrs;
}

static inline int cmp_doubles(const void *a, const void *b) { return (*(double *)a - *(double *)b); }
static inline void sort_doubles(double *doubles, size_t size) { qsort(doubles, size, sizeof(double), cmp_doubles); }
static inline double *sorted_doubles(double *doubles, size_t size)
{
    double *dup_doubles = (double *)duparray(doubles, size, sizeof(double));
    qsort(doubles, size, sizeof(double), cmp_doubles);
    return dup_doubles;
}

static inline int cmp_double_ptrs(const void *a, const void *b) { return (*(double **)a - *(double **)b); }
static inline void sort_double_ptrs(double **double_ptrs, size_t size) { qsort(double_ptrs, size, sizeof(double *), cmp_double_ptrs); }
static inline double **sorted_double_ptrs(double **double_ptrs, size_t size)
{
    double **dup_double_ptrs = (double **)duparray(double_ptrs, size, sizeof(double *));
    qsort(double_ptrs, size, sizeof(double *), cmp_double_ptrs);
    return dup_double_ptrs;
}

static inline int cmp_size_ts(const void *a, const void *b) { return (*(size_t *)a - *(size_t *)b); }
static inline void sort_size_ts(size_t *size_ts, size_t size) { qsort(size_ts, size, sizeof(size_t), cmp_size_ts); }
static inline size_t *sorted_size_ts(size_t *size_ts, size_t size)
{
    size_t *dup_size_ts = (size_t *)duparray(size_ts, size, sizeof(size_t));
    qsort(size_ts, size, sizeof(size_t), cmp_size_ts);
    return dup_size_ts;
}

static inline int cmp_size_t_ptrs(const void *a, const void *b) { return (*(size_t **)a - *(size_t **)b); }
static inline void sort_size_t_ptrs(size_t **size_t_ptrs, size_t size) { qsort(size_t_ptrs, size, sizeof(size_t *), cmp_size_t_ptrs); }
static inline size_t **sorted_size_t_ptrs(size_t **size_t_ptrs, size_t size)
{
    size_t **dup_size_t_ptrs = (size_t **)duparray(size_t_ptrs, size, sizeof(size_t *));
    qsort(size_t_ptrs, size, sizeof(size_t *), cmp_size_t_ptrs);
    return dup_size_t_ptrs;
}



/* Function to convert a string to an integer */
static inline int string_to_int(const char *str) { return atoi(str); }



/* Function to read the entire contents of a file into a string */
static inline char *read_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        standardlib_error_handler("Error: Unable to open file for reading");
    }

    /*  Determine the file size */
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    /*  Allocate memory for the file contents */
    char *content = (char *)malloc(file_size + 1);
    if (content == NULL)
    {
        standardlib_error_handler("Error: Memory allocation failed");
        ;
    }

    /*  Read the file contents into the string */
    size_t read_size;
    size_t total_read = 0;
    while ((read_size = fread(content + total_read, 1, file_size - total_read, file)) > 0)
    {
        total_read += read_size;
    }

    /*  Null-terminate the string */
    content[total_read] = '\0';

    /*  Close the file */
    fclose(file);

    return content;
}

/* Function to write a string to a file */
static inline void write_file(const char *filename, const char *content)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        standardlib_error_handler("Error: Unable to open file for writing");
        ;
    }

    /*  Write the string to the file */
    size_t write_size;
    size_t total_written = 0;
    size_t content_length = strlen(content);
    while ((write_size = fwrite(content + total_written, 1, content_length - total_written, file)) > 0)
    {
        total_written += write_size;
    }

    /*  Close the file */
    fclose(file);
}



/* Function to append a string to a file */
static inline void append_to_file(const char *filename, const char *content)
{
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        standardlib_error_handler("Error: Unable to open file for appending");
    }

    /*  Append the string to the file */
    size_t write_size = fwrite(content, 1, strlen(content), file);
    if (write_size != strlen(content))
    {
        standardlib_error_handler("Error: Appending to file failed.\n");
        ;
    }

    /*  Close the file */
    fclose(file);
}

#include <stdio.h>
#ifdef _WIN32
#include <io.h>
#include <sys/stat.h>
#else
#include <sys/stat.h>
#include <unistd.h>
#endif

static inline int file_exists(const char *filename)
{
#ifdef _WIN32
    return _access(filename, 0) == 0;
#else
    return access(filename, F_OK) == 0;
#endif
}

static inline int file_is_regular(const char *filename)
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

static inline int file_is_directory(const char *filename)
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

static inline int file_is_readable(const char *filename)
{
#ifdef _WIN32
    return _access(filename, 4) == 0; // 4 is for read permission on Windows
#else
    return access(filename, R_OK) == 0; // R_OK is for read permission on POSIX systems
#endif
}

static inline int file_is_writable(const char *filename)
{
#ifdef _WIN32
    return _access(filename, 2) == 0; // 2 is for write permission on Windows
#else
    return access(filename, W_OK) == 0; // W_OK is for write permission on POSIX systems
#endif
}

static inline int file_is_executable(const char *filename)
{
#ifdef _WIN32
    return _access(filename, 1) == 0; // 1 is for execute permission on Windows
#else
    return access(filename, X_OK) == 0; // X_OK is for execute permission on POSIX systems
#endif
}



/* Function to get the size of a file */
static inline long get_file_size(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        standardlib_error_handler("Error: Unable to open file for size calculation");
    }

    /*  Determine the file size */
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    /*  Close the file */
    fclose(file);

    return file_size;
}

/* Function to read a specific number of bytes from a file */
static inline char *read_bytes_from_file(const char *filename, size_t num_bytes)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        puts(filename);
        standardlib_error_handler("Error: Unable to open file for reading bytes");
    }

    /*  Allocate memory for the specified number of bytes */
    char *content = (char *)malloc(num_bytes + 1);
    if (content == NULL)
    {
        standardlib_error_handler("Error: Memory allocation failed.\n");
        ;
    }

    /*  Read the specified number of bytes from the file */
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

    /*  Null-terminate the string */
    content[total_read] = '\0';

    /*  Close the file */
    fclose(file);

    return content;
}



/* Function to remove a file */
static inline void remove_file(const char *filename)
{
    if (remove(filename) != 0)
    {
        standardlib_error_handler("Error: Unable to remove file");
    }
}



/* Function to copy the contents of one file to another */
static inline void copy_file(const char *source_filename, const char *destination_filename)
{
    FILE *source_file = fopen(source_filename, "r");
    if (source_file == NULL)
    {
        standardlib_error_handler("Error: Unable to open source file for reading.");
    }

    FILE *destination_file = fopen(destination_filename, "w");
    if (destination_file == NULL)
    {
        fclose(source_file);
        standardlib_error_handler("Error: Unable to open destination file for writing.\n");
        ;
    }

    char buffer[1024];
    size_t read_size;
    while ((read_size = fread(buffer, 1, sizeof(buffer), source_file)) > 0)
    {
        fwrite(buffer, 1, read_size, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    printf("File '%s' copied to '%s' successfully.\n", source_filename, destination_filename);
}



#ifdef _WIN32
#include <windows.h>

/* Function to list files in a directory using wildcard pattern on Windows */
static inline char **list_files_with_pattern(const char *directory, const char *pattern, size_t *len)
{
    char search_path[MAX_PATH];
    snprintf(search_path, MAX_PATH, "%s\\%s", directory, pattern);

    WIN32_FIND_DATA find_file_data;
    HANDLE find_handle = FindFirstFile(search_path, &find_file_data);

    if (find_handle == INVALID_HANDLE_VALUE)
    {
        standardlib_error_handler("Error: Unable to find files matching pattern in directory");
    }

    /*  Count the number of files matching the pattern */
    int file_count = 0;
    do
    {
        if (!(find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            file_count++;
        }
    } while (FindNextFile(find_handle, &find_file_data) != 0);

    /*  Allocate memory for the array of strings */
    char **files_array = (char **)malloc((file_count) * sizeof(char *));
    if (files_array == NULL)
    {
        standardlib_error_handler("Error: Memory allocation failed.\n");
        ;
    }

    /*  Populate the array with file names matching the pattern */
    int index = 0;
    FindClose(find_handle);
    find_handle = FindFirstFile(search_path, &find_file_data);
    do
    {
        if (!(find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            files_array[index] = strdup(find_file_data.cFileName);
            if (files_array[index] == NULL)
            {
                standardlib_error_handler("Error: Memory allocation for file name failed.\n");
                ;
            }
            index++;
        }
    } while (FindNextFile(find_handle, &find_file_data) != 0);

    /*  Close the find handle */
    FindClose(find_handle);

    *len = index;

    return files_array;
}

#else

/* Function to list files in a directory using wildcard pattern on POSIX systems */
#include <dirent.h>
#include <fnmatch.h>

static inline char **list_files_with_pattern(const char *directory, const char *pattern, size_t *len)
{
    DIR *dir = opendir(directory);
    if (dir == NULL)
    {
        standardlib_error_handler("Error: Unable to open directory");
    }

    /*  Count the number of files matching the pattern */
    int file_count = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (fnmatch(pattern, entry->d_name, FNM_PERIOD) == 0)
        {
            file_count++;
        }
    }
    rewinddir(dir);

    /*  Allocate memory for the array of strings */
    char **files_array = (char **)malloc((file_count) * sizeof(char *));
    if (files_array == NULL)
    {
        standardlib_error_handler("Error: Memory allocation failed.\n");
        ;
    }

    /*  Populate the array with file names matching the pattern */
    size_t index = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        if (fnmatch(pattern, entry->d_name, FNM_PERIOD) == 0)
        {
            files_array[index] = strdup(entry->d_name);
            if (files_array[index] == NULL)
            {
                standardlib_error_handler("Error: Memory allocation for file name failed.\n");
                ;
            }
            index++;
        }
    }

    /*  Close the directory */
    closedir(dir);
    *len = index;

    return files_array;
}

#endif



/* Function to find the first non-repeating character in a string */
static inline char first_non_repeating_char(const char *str)
{
    int char_count[256] = {0}; // Assuming ASCII characters

    /*  Count occurrences of each character */
    for (size_t i = 0; i < strlen(str); i++)
    {
        char_count[(unsigned char)str[i]]++;
    }

    /*  Find the first non-repeating character */
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (char_count[(unsigned char)str[i]] == 1)
        {
            return str[i];
        }
    }

    /*  If no non-repeating character is found, return a placeholder */
    return '\0';
}



/* Function to find the majority element (element appearing more than n/2 times) */
/* in an array */
static inline int majority_element(const int *arr, size_t size)
{
    int candidate = arr[0];
    int count = 1;

    /*  Find a potential majority candidate */
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

    /*  Verify if the candidate is a majority element */
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
        /*  If no majority element is found, return a placeholder */
        return -1;
    }
}



/* Function to calculate the mean of an array of integers */
static inline double calculate_mean(const int *arr, size_t size)
{
    double sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}

/* Function to calculate the median of an array of integers */
static inline double calculate_median(int *arr, size_t size)
{
    /*  Sort the array (using a simple bubble sort for demonstration purposes) */
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                /*  Swap elements if they are in the wrong order */
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    /*  Calculate the median based on sorted array */
    if (size % 2 == 0)
    {
        /*  If array size is even, return the average of the middle elements */
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
    else
    {
        /*  If array size is odd, return the middle element */
        return arr[size / 2];
    }
}

/* Function to calculate the mode of an array of integers */
static inline int calculate_mode(const int *arr, size_t size)
{
    /*  Count occurrences of each number */
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



/* Function to concatenate two strings */
static inline char *concatenate_strings(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char *result = (char *)malloc(len1 + len2 + 1);
    if (result == NULL)
    {
        standardlib_error_handler("Error: Memory allocation failed.\n");
        ;
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

/* Function to concatenate multiple strings */
static inline char *concatenate_multiple_strings(const char *strings[], size_t num_strings)
{
    size_t total_length = 0;

    /*  Calculate the total length of the concatenated string */
    for (size_t i = 0; i < num_strings; i++)
    {
        total_length += strlen(strings[i]);
    }

    char *result = (char *)malloc(total_length + 1);
    if (result == NULL)
    {
        standardlib_error_handler("Error: Memory allocation failed.\n");
        ;
    }

    /*  Concatenate the strings */
    result[0] = '\0'; // Ensure the string is initially empty
    for (size_t i = 0; i < num_strings; i++)
    {
        strcat(result, strings[i]);
    }

    return result;
}



/* Copy a string in printf format. free() after */
static inline char *dup_format(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    /*  Determine the length of the formatted string */
    int len = vsnprintf(NULL, 0, format, args);

    va_end(args);

    /*  Allocate memory for the formatted string */
    char *result = (char *)malloc(len + 1);
    if (result == NULL)
    {
        standardlib_error_handler("Error: Memory allocation failed.\n");
        ;
    }

    va_start(args, format);
    vsnprintf(result, len + 1, format, args);
    va_end(args);

    return result;
}



/* Function similar to Python's format() using curly braces ({4}, {1}, {}, {2}, */
/* etc.), note: pass arguments as strings */
static inline char *format_string(const char *format, ...)
{
    /*  Initialize variable argument list */
    va_list args;
    va_start(args, format);

    /*  Count the number of indices in the format string */
    int numIndices = 0;
    const char *ptr = format;
    while (*ptr)
    {
        if (*ptr == '{')
        {
            /*  Check if the closing brace is present */
            const char *endPtr = strchr(ptr, '}');
            if (endPtr)
            {
                numIndices++;
                ptr = endPtr + 1; // Move to the character after closing brace
            }
            else
            {
                /*  Error: Missing closing brace */
                va_end(args);
                return NULL;
            }
        }
        else
        {
            ptr++;
        }
    }

    /*  Create a dynamic array to store variable arguments */
    char **argArray = (char **)malloc(numIndices * sizeof(char *));
    if (!argArray)
    {
        /*  Error: Memory allocation failed */
        va_end(args);
        return NULL;
    }

    /*  Populate the dynamic array with variable arguments */
    for (int i = 0; i < numIndices; i++)
    {
        argArray[i] = va_arg(args, char *);
    }

    /*  Close the variable argument list */
    va_end(args);

    /*  Interpolate the format string */
    char *result = (char *)malloc(1); // Start with an empty string
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
                    printf("%d %d\n", last_index, numIndices);
                    index = last_index;
                    if (last_index < numIndices)
                        ++last_index;
                }
                else
                {
                    char indexStr[10];
                    /*  Extract the index between braces */
                    strncpy(indexStr, ptr + 1, endPtr - ptr - 1);
                    indexStr[endPtr - ptr - 1] = '\0';
                    index = atoi(indexStr);
                }

                /*  Check if the index is valid */
                if (index >= 0 && index < numIndices)
                {
                    /*  Concatenate the corresponding argument to the result */
                    result = (char *)realloc(result, strlen(result) + strlen(argArray[index]) + 1);
                    printf("Cat %s\n", argArray[index]);
                    strcat(result, argArray[index]);
                }
                else
                {
                    /*  Error: Invalid index */
                    free(result);
                    free(argArray);
                    return NULL;
                }

                ptr = endPtr + 1;
            }
            else
            {
                /*  Error: Missing closing brace */
                free(result);
                free(argArray);
                return NULL;
            }
        }
        else
        {
            /*  Concatenate non-indexed characters to the result */
            result = (char *)realloc(result, strlen(result) + 2);
            strncat(result, ptr, 1);
            ptr++;
        }
    }

    /*  Free the dynamic array */
    free(argArray);

    return result;
}



/* Function to apply a transformation to each element of an array */
static inline void map_int(int *array, size_t size, int (*transform)(int))
{
    for (size_t i = 0; i < size; i++)
    {
        array[i] = transform(array[i]);
    }
}



/* Function to perform a reduction on an array */
static inline int reduce_int(int *array, size_t size, int (*operation)(int, int))
{
    int result = array[0];
    for (size_t i = 1; i < size; i++)
    {
        result = operation(result, array[i]);
    }
    return result;
}



/* Function to filter elements based on a condition */
static inline size_t filter_int(int *source, size_t source_size, int *destination, int (*condition)(int))
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



/* Function to apply a transformation to each element of an array (void* */
/* version) */
static inline void map(void *array, size_t size, size_t elem_size, void (*transform)(void *))
{
    char *char_array = (char *)array;
    for (size_t i = 0; i < size; i++)
    {
        transform(char_array + i * elem_size);
    }
}



/* Function to perform a reduction on an array (void* version) */
static inline void reduce(void *array, size_t size, size_t elem_size, void *result, void (*operation)(void *, void *))
{
    char *char_array = (char *)array;
    char *char_result = (char *)result;

    /*  Initialize the result with the first element */
    for (size_t i = 0; i < elem_size; i++)
    {
        char_result[i] = char_array[i];
    }

    for (size_t i = 1; i < size; i++)
    {
        operation(char_result, char_array + i * elem_size);
    }
}



/* Function to filter elements based on a condition (void* version) */
static inline size_t filter(void *source, size_t source_size, size_t elem_size, void *destination, size_t dest_size, int (*condition)(void *))
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



/* Implementation of list_comprehension */
static inline void *list_comprehension(const void *input_array, size_t array_size, size_t elem_size, void (*transform_func)(void *value), int (*filter_func)(void *value), size_t *result_size)
{
    /*  Allocate memory for the result array */
    void *result = malloc(array_size * elem_size);
    if (result == NULL)
    {
        /*  Handle memory allocation error */
        return NULL;
    }

    size_t count = 0; // Number of elements in the result array

    /*  Iterate through the input array */
    for (size_t i = 0; i < array_size; ++i)
    {
        /*  Apply the filter function */
        if (filter_func((void *)((char *)input_array + i * elem_size)))
        {
            /*  Apply the transformation function */
            transform_func((void *)((char *)input_array + i * elem_size));

            /*  Copy the transformed value to the result array */
            memcpy((char *)result + count * elem_size, (char *)input_array + i * elem_size, elem_size);

            count++;
        }
    }

    /*  Update the result size */
    *result_size = count;

    return result;
}



/* Function to reject elements based on a condition */
static inline void *reject_array(const void *source, size_t source_size, size_t elem_size, int (*condition)(const void *), size_t *result_size)
{
    /*  Allocate memory for the result array */
    void *result = malloc(source_size * elem_size);
    if (result == NULL)
    {
        standardlib_error_handler("Error: Memory allocation failed in reject_array");
    }

    size_t result_index = 0;

    /*  Apply the rejection condition to each element */
    for (size_t i = 0; i < source_size; i++)
    {
        const void *current_source = (char *)source + i * elem_size;

        /*  Check condition */
        if (!condition(current_source))
        {
            void *current_result = (char *)result + result_index * elem_size;
            memcpy(current_result, current_source, elem_size);
            result_index++;
        }
    }

    /*  Set the result size */
    *result_size = result_index;

    return result;
}

/* Function to select elements based on a condition */
static inline void *select_array(const void *source, size_t source_size, size_t elem_size, int (*condition)(const void *), size_t *result_size)
{
    /*  Allocate memory for the result array */
    void *result = malloc(source_size * elem_size);
    if (result == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    size_t result_index = 0;

    /*  Apply the selection condition to each element */
    for (size_t i = 0; i < source_size; i++)
    {
        const void *current_source = (char *)source + i * elem_size;

        /*  Check condition */
        if (condition(current_source))
        {
            void *current_result = (char *)result + result_index * elem_size;
            memcpy(current_result, current_source, elem_size);
            result_index++;
        }
    }

    /*  Set the result size */
    *result_size = result_index;

    return result;
}











/* Function to check if a string is empty */
static inline int is_empty_string(const char *str) { return (str == NULL || *str == '\0'); }

/* Function to convert a string to lowercase */
static inline char *string_to_lowercase(char *str)
{
    char *new_str = strdup(str);
    char *orig_str = new_str;
    while (*new_str)
    {
        *new_str = tolower(*new_str);
        new_str++;
    }

    return orig_str;
}

/* Function to convert a string to uppercase */
static inline char *string_to_uppercase(char *str)
{
    char *new_str = strdup(str);
    char *orig_str = new_str;
    while (*new_str)
    {
        *new_str = toupper(*new_str);
        new_str++;
    }

    return orig_str;
}



/* Function to calculate the average of elements in an integer array */
static inline double calculate_average(const int *array, size_t size)
{
    if (size == 0)
    {
        fprintf(stderr, "Error: Empty array.\n");
        exit(EXIT_FAILURE);
    }

    int sum = calculate_sum(array, size);
    return (double)sum / size;
}



/* Function to check if all characters in a string are uppercase */
static inline int is_string_upper(const char *str)
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

/* Function to check if all characters in a string are lowercase */
static inline int is_string_lower(const char *str)
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

/* Function to check if all characters in a string are alphanumeric */
static inline int is_string_alphanumeric(const char *str)
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

/* Function to check if all characters in a string are digits */
static inline int is_string_digit(const char *str)
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

/* Function to check if all characters in a string are spaces */
static inline int is_string_space(const char *str)
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



/* Function to check if all elements in an integer array are even */
static inline int are_all_elements_even(const int *array, size_t size)
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

/* Function to check if all elements in an integer array are odd */
static inline int are_all_elements_odd(const int *array, size_t size)
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

/* Function to check if all elements in an integer array are positive */
static inline int are_all_elements_positive(const int *array, size_t size)
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

/* Function to check if all elements in an integer array are negative */
static inline int are_all_elements_negative(const int *array, size_t size)
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

/* Function to check if all elements in an integer array are zeros */
static inline int are_all_elements_zero(const int *array, size_t size)
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



/* Function to check if all characters in a string are alphabetic */
static inline int is_string_alpha(const char *str)
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

/* Function to check if all characters in a string are printable */
static inline int is_string_printable(const char *str)
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



/* Function to check if a string array contains only digits */
static inline int is_array_digit(const char *arr[], size_t size)
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

/* Function to check if a string array contains at least one uppercase, one */
/* lowercase, and one digit */
static inline int has_mixed_characters(const char *arr[], size_t size)
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

/* Function to check if a string array contains only uppercase characters */
static inline int is_array_upper(const char *arr[], size_t size)
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

/* Function to check if a string array contains only lowercase characters */
static inline int is_array_lower(const char *arr[], size_t size)
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





/* Function to remove duplicate strings from an array (Ruby-style) */
static inline void array_uniq(char *arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == NULL)
            continue;

        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[j] != NULL && strcmp(arr[i], arr[j]) == 0)
            {
                /*  Found a duplicate, free memory and set to NULL */
                free(arr[j]);
                arr[j] = NULL;
            }
        }
    }
}



/* Function to remove consecutive duplicate strings from an array (Bash-style) */
static inline void array_uniq_adjacent(char *arr[], size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] != NULL && strcmp(arr[i], arr[i - 1]) == 0)
        {
            /*  Found a consecutive duplicate, free memory and set to NULL */
            free(arr[i]);
            arr[i] = NULL;
        }
    }
}



/* Function to transpose a 2D array */
static inline void transpose(int **matrix, size_t rows, size_t cols)
{
    /*  Create a temporary matrix to store the transposed result */
    int **result = (int **)malloc(cols * sizeof(int *));
    for (size_t i = 0; i < cols; i++)
    {
        result[i] = (int *)malloc(rows * sizeof(int));
    }

    /*  Perform the transpose */
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }

    /*  Print the original matrix */
    printf("Original Matrix:\n");
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    /*  Print the transposed matrix */
    printf("\nTransposed Matrix:\n");
    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    /*  Free the memory for the temporary matrix */
    for (size_t i = 0; i < cols; i++)
    {
        free(result[i]);
    }
    free(result);
}



/* Function to concatenate three strings */
static inline char *concatenate_three_strings(const char *str1, const char *str2, const char *str3)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t len3 = strlen(str3);

    char *result = (char *)malloc(len1 + len2 + len3 + 1);
    if (result == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);

    return result;
}

/* Function to concatenate four strings */
static inline char *concatenate_four_strings(const char *str1, const char *str2, const char *str3, const char *str4)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t len3 = strlen(str3);
    size_t len4 = strlen(str4);

    char *result = (char *)malloc(len1 + len2 + len3 + len4 + 1);
    if (result == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    strcat(result, str4);

    return result;
}

/* Function to concatenate five strings */
static inline char *concatenate_five_strings(const char *str1, const char *str2, const char *str3, const char *str4, const char *str5)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t len3 = strlen(str3);
    size_t len4 = strlen(str4);
    size_t len5 = strlen(str5);

    char *result = (char *)malloc(len1 + len2 + len3 + len4 + len5 + 1);
    if (result == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    strcat(result, str4);
    strcat(result, str5);

    return result;
}



/* Function to apply a map operation on files */
static inline void map_files(const char *directory, char *(*map_function)(const char *filename))
{
    DIR *dir = opendir(directory);
    if (dir == NULL)
    {
        standardlib_error_handler("Unable to open directory");
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        { // Regular file
            char *file_data;
            char *new_str = map_function(file_data = read_file(entry->d_name));
            free(file_data);
            write_file(entry->d_name, file_data);
            free(new_str);
        }
    }

    closedir(dir);
}

/* Function to apply a filter operation on files */
static inline void filter_files(const char *directory, int (*filter_function)(const char *filename))
{
    DIR *dir = opendir(directory);
    if (dir == NULL)
    {
        standardlib_error_handler("Unable to open directory");
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        {
            if (filter_function(entry->d_name))
            {
            }
            else
            {
                remove(entry->d_name);
            }
        }
    }

    closedir(dir);
}

/* Function to apply a reduce operation on files */
static inline char *reduce_files(const char *directory, char *(*reduce_function)(char *value1, ...))
{

    /*  FIXME */
    return 0;
    DIR *dir = opendir(directory);
    if (dir == NULL)
    {
        standardlib_error_handler("Unable to open directory");
    }

    char *last_value = NULL;
    char *value = NULL;

    struct dirent *entry;
    if ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        { // Regular file
            last_value = read_file(entry->d_name);
        }
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        { // Regular file
            value = read_file(entry->d_name);

            char *new_value = reduce_function(last_value, value, entry->d_name);
            if (last_value)
            {
                free(last_value);
            }

            free(value);
            last_value = new_value;

            remove(entry->d_name);
        }
    }

    closedir(dir);
    write_file("reduce_out", (value));

    return last_value;
}



/* Dict */
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

static inline struct Dict *dict_new_instance()
{
    struct Dict *dict = (struct Dict *)malloc(sizeof(struct Dict));
    if (!dict)
    {
        standardlib_error_handler("Memory allocation failed for hash\n");
    }

    dict->capacity = STANDARDLIB_HASH_INITIAL_CAPACITY;
    dict->size = 0;
    dict->table = (struct KeyValue **)calloc(STANDARDLIB_HASH_INITIAL_CAPACITY, sizeof(struct KeyValue *));
    if (!dict->table)
    {
        free(dict);
        standardlib_error_handler("Memory allocation failed for keys\n");
    }

    return dict;
}

static inline void dict_destructor(struct Dict *dict)
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            struct KeyValue *nextPair = currentPair->next;
            free(currentPair->key);
            free(currentPair);
            currentPair = nextPair;
        }
    }
    free(dict->table);
    free(dict);
}

static inline unsigned int dict_hash(const char *key, size_t capacity)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash = (hash << 5) + *key++;
    }
    return hash % capacity;
}

static inline void dict_resize(struct Dict *dict)
{
    size_t newCapacity = dict->capacity + dict->capacity / 2 + 1;
    struct KeyValue **newTable = (struct KeyValue **)calloc(newCapacity, sizeof(struct KeyValue *));
    if (!newTable)
    {
        standardlib_error_handler("Memory allocation failed\n");
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

    free(dict->table);
    dict->table = newTable;
    dict->capacity = newCapacity;
}

static inline void dict_del(struct Dict *dict, const char *key)
{
    size_t index = dict_hash(key, dict->capacity);

    struct KeyValue *current = dict->table[index];
    struct KeyValue *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            /*  Key found, remove the entry */
            if (prev == NULL)
            {
                /*  If it's the first node in the linked list */
                dict->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            /*  Free memory */
            free(current->key);
            free(current);

            /*  Update size */
            dict->size--;

            return;
        }

        /*  Move to the next node in the linked list */
        prev = current;
        current = current->next;
    }
}

static inline void dict_add(struct Dict *dict, const char *key, void *value)
{
    if ((double)dict->size / dict->capacity > STANDARDLIB_HASH_LOAD_FACTOR_THRESHOLD)
    {
        dict_resize(dict);
    }

    unsigned int index = dict_hash(key, dict->capacity);

    struct KeyValue *newPair = (struct KeyValue *)malloc(sizeof(struct KeyValue));
    if (!newPair)
    {
        standardlib_error_handler("Memory allocation failed\n");
    }

    newPair->key = strdup(key);
    newPair->value = value;
    newPair->next = dict->table[index];
    dict->table[index] = newPair;

    dict->size++;
}

static inline void *dict_get(struct Dict *dict, const char *key)
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

static inline void *dict_get_check(struct Dict *dict, const char *key, int *key_is_in_dict)
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

static inline struct FrozenDict *frozen_dict_new_instance(size_t num_args, ...)
{
    struct FrozenDict *dict = (struct FrozenDict *)malloc(sizeof(struct FrozenDict));
    if (!dict)
    {
        standardlib_error_handler("Memory allocation failed for hash\n");
    }

    dict->capacity = STANDARDLIB_HASH_INITIAL_CAPACITY;
    dict->size = 0;
    dict->table = (struct KeyValue **)calloc(STANDARDLIB_HASH_INITIAL_CAPACITY, sizeof(struct KeyValue *));
    if (!dict->table)
    {
        free(dict);
        standardlib_error_handler("Memory allocation failed for keys\n");
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

static inline void frozen_dict_destructor(struct FrozenDict *dict)
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            struct KeyValue *nextPair = currentPair->next;
            free(currentPair->key);
            free(currentPair);
            currentPair = nextPair;
        }
    }
    free(dict->table);
    free(dict);
}

static inline void *frozen_dict_get(struct FrozenDict *dict, const char *key)
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

static inline void *frozen_dict_get_check(struct FrozenDict *dict, const char *key, int *key_is_in_dict)
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

static inline void dict_iter(struct Dict *dict, void (*callback)(char *key, void *value))
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *current = dict->table[i];

        while (current != NULL)
        {
            /*  Call the callback function with the key and value */
            callback(current->key, current->value);

            /*  Move to the next node in the linked list */
            current = current->next;
        }
    }
}

static inline size_t dict_size(struct Dict *dict) { return dict->size; }

static inline size_t frozen_dict_size(struct FrozenDict *dict) { return dict->size; }
static inline size_t dict_to_a(struct Dict *dict, char ***keys, void ***values)
{ /* return size of keys and values (they are always the same) */
    *keys = (char **)malloc(dict->size * sizeof(char *));
    *values = (void **)malloc(dict->size * sizeof(void *));

    if (!(*keys) || !(*values))
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
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

    return dict->size;
}

static inline size_t frozen_dict_to_a(struct FrozenDict *dict, char ***keys, void ***values)
{ /* return size of keys and values (they are always the same) */
    *keys = (char **)malloc(dict->size * sizeof(char *));
    *values = (void **)malloc(dict->size * sizeof(void *));

    if (!(*keys) || !(*values))
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
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

    return dict->size;
}

static inline void dict_del_keys(char **keys) { free(keys); }

static inline void dict_del_values(void **values) { free(values); }

/* Convert a frozen dictionary to a string representation */
static inline char *dict_to_s(struct Dict *dict, int pointer_or_string) /* 0 = pointer, 1 = string */
{
    /*  Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /*  Calculate the length of the string representation for each key-value pair */
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

    char *result = (char *)malloc(total_length + 1); // Add 1 for the null-terminator, at least 3 chars
    if (!result)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /*  Append the key and value to the string representation */
            if (pointer_or_string == 0)
            {
                index += snprintf(result + index, total_length - index, "%s: %p", currentPair->key, currentPair->value);
            }
            else if (pointer_or_string == 1)
            {
                index += snprintf(result + index, total_length - index, "%s: %s", currentPair->key, (char *)currentPair->value);
            }
            currentPair = currentPair->next;

            /*  Add a separator (comma) if there are more elements */
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

/* Convert a frozen dictionary to a string representation */
static inline char *frozen_dict_to_s(struct FrozenDict *dict, int pointer_or_string) /* 0 = pointer, 1 = string */
{
    /*  Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /*  Calculate the length of the string representation for each key-value pair */
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

    char *result = (char *)malloc(total_length + 1); // Add 1 for the null-terminator, at least 3 chars
    if (!result)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct KeyValue *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /*  Append the key and value to the string representation */
            if (pointer_or_string == 0)
            {
                index += snprintf(result + index, total_length - index, "%s: %p", currentPair->key, currentPair->value);
            }
            else if (pointer_or_string == 1)
            {
                index += snprintf(result + index, total_length - index, "%s: %s", currentPair->key, (char *)currentPair->value);
            }
            currentPair = currentPair->next;

            /*  Add a separator (comma) if there are more elements */
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

static inline void frozen_dict_del_keys(char **keys) { free(keys); }

static inline void frozen_dict_del_values(void **values) { free(values); }

/* Set */



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

static inline struct Set *set_new_instance()
{
    struct Set *dict = (struct Set *)malloc(sizeof(struct Set));
    if (!dict)
    {
        standardlib_error_handler("Memory allocation failed for hash\n");
    }

    dict->capacity = STANDARDLIB_HASH_INITIAL_CAPACITY;
    dict->size = 0;
    dict->table = (struct Key **)calloc(STANDARDLIB_HASH_INITIAL_CAPACITY, sizeof(struct Key *));
    if (!dict->table)
    {
        free(dict);
        standardlib_error_handler("Memory allocation failed for keys\n");
    }

    return dict;
}

static inline void set_destructor(struct Set *dict)
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            struct Key *nextPair = currentPair->next;
            free(currentPair->key);
            free(currentPair);
            currentPair = nextPair;
        }
    }
    free(dict->table);
    free(dict);
}

static inline unsigned int set_hash(const char *key, size_t capacity)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash = (hash << 5) + *key++;
    }
    return hash % capacity;
}

static inline void set_resize(struct Set *dict)
{
    size_t newCapacity = dict->capacity + dict->capacity / 2 + 1;
    struct Key **newTable = (struct Key **)calloc(newCapacity, sizeof(struct Key *));
    if (!newTable)
    {
        standardlib_error_handler("Memory allocation failed\n");
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

    free(dict->table);
    dict->table = newTable;
    dict->capacity = newCapacity;
}

static inline void set_del(struct Set *dict, const char *key)
{
    size_t index = set_hash(key, dict->capacity);

    struct Key *current = dict->table[index];
    struct Key *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            /*  Key found, remove the entry */
            if (prev == NULL)
            {
                /*  If it's the first node in the linked list */
                dict->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            /*  Free memory */
            free(current->key);
            free(current);

            /*  Update size */
            dict->size--;

            return;
        }

        /*  Move to the next node in the linked list */
        prev = current;
        current = current->next;
    }
}

static inline void set_add(struct Set *dict, const char *key)
{
    if ((double)dict->size / dict->capacity > STANDARDLIB_HASH_LOAD_FACTOR_THRESHOLD)
    {
        set_resize(dict);
    }

    unsigned int index = set_hash(key, dict->capacity);

    struct Key *newPair = (struct Key *)malloc(sizeof(struct Key));
    if (!newPair)
    {
        standardlib_error_handler("Memory allocation failed\n");
    }

    newPair->key = strdup(key);
    newPair->next = dict->table[index];
    dict->table[index] = newPair;

    dict->size++;
}

/* Set.in? */
static inline int set_in(struct Set *dict, const char *key)
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

static inline struct FrozenSet *frozen_set_new_instance(size_t num_args, ...)
{
    struct FrozenSet *dict = (struct FrozenSet *)malloc(sizeof(struct FrozenSet));
    if (!dict)
    {
        standardlib_error_handler("Memory allocation failed for hash\n");
    }

    dict->capacity = STANDARDLIB_HASH_INITIAL_CAPACITY;
    dict->size = 0;
    dict->table = (struct Key **)calloc(STANDARDLIB_HASH_INITIAL_CAPACITY, sizeof(struct Key *));
    if (!dict->table)
    {
        free(dict);
        standardlib_error_handler("Memory allocation failed for keys\n");
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

static inline void frozen_set_destructor(struct FrozenSet *dict)
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            struct Key *nextPair = currentPair->next;
            free(currentPair->key);
            free(currentPair);
            currentPair = nextPair;
        }
    }
    free(dict->table);
    free(dict);
}

static inline int frozen_set_in(struct FrozenSet *dict, const char *key)
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

static inline void set_iter(struct Set *dict, void (*callback)(char *key))
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *current = dict->table[i];

        while (current != NULL)
        {
            /*  Call the callback function with the key and value */
            callback(current->key);

            /*  Move to the next node in the linked list */
            current = current->next;
        }
    }
}

static inline size_t set_size(struct Set *dict) { return dict->size; }

static inline size_t frozen_set_size(struct FrozenSet *dict) { return dict->size; }
static inline size_t set_to_a(struct Set *dict, char ***keys)
{ /* return size of keys and values (they are always the same) */
    *keys = (char **)malloc(dict->size * sizeof(char *));

    if (!(*keys))
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t index = 0;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            (*keys)[index] = (currentPair->key);
            ++index;
            currentPair = currentPair->next;
        }
    }

    return dict->size;
}

static inline size_t frozen_set_to_a(struct FrozenSet *dict, char ***keys, void ***values)
{ /* return size of keys and values (they are always the same) */
    *keys = (char **)malloc(dict->size * sizeof(char *));
    *values = (void **)malloc(dict->size * sizeof(void *));

    if (!(*keys) || !(*values))
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t index = 0;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            (*keys)[index] = (currentPair->key);
            ++index;
            currentPair = currentPair->next;
        }
    }

    return dict->size;
}

static inline void set_del_keys(char **keys) { free(keys); }

/* Convert a frozen dictionary to a string representation */
static inline char *set_to_s(struct Set *dict) /* 0 = pointer, 1 = string */
{
    /*  Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /*  Calculate the length of the string representation for each key-value pair */
            total_length += strlen(currentPair->key);
            total_length += 2; // 2 for ", "
            currentPair = currentPair->next;
        }
    }

    char *result = (char *)malloc(total_length + 1); // Add 1 for the null-terminator, at least 3 chars
    if (!result)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /*  Append the key and value to the string representation */
            index += snprintf(result + index, total_length - index, "%s", currentPair->key);
            currentPair = currentPair->next;

            /*  Add a separator (comma) if there are more elements */
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

/* Convert a frozen dictionary to a string representation */
static inline char *frozen_set_to_s(struct FrozenSet *dict) /* 0 = pointer, 1 = string */
{
    /*  Allocate memory for the string representation */
    size_t total_length = 2;
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /*  Calculate the length of the string representation for each key-value pair */
            total_length += strlen(currentPair->key);
            total_length += 2; // 2 for ", "
            currentPair = currentPair->next;
        }
    }

    char *result = (char *)malloc(total_length + 1); // Add 1 for the null-terminator, at least 3 chars
    if (!result)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    result[0] = '{';
    size_t index = 1;

    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *currentPair = dict->table[i];
        while (currentPair != NULL)
        {
            /*  Append the key and value to the string representation */
            index += snprintf(result + index, total_length - index, "%s", currentPair->key);
            currentPair = currentPair->next;

            /*  Add a separator (comma) if there are more elements */
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

static inline void frozen_set_del_keys(char **keys) { free(keys); }

static inline void frozen_set_iter(struct Set *dict, void (*callback)(char *key))
{
    for (size_t i = 0; i < dict->capacity; ++i)
    {
        struct Key *current = dict->table[i];

        while (current != NULL)
        {
            /*  Call the callback function with the key and value */
            callback(current->key);

            /*  Move to the next node in the linked list */
            current = current->next;
        }
    }
}






