#!/bin/bash
#
# 2023, Gregory Cohen <gregorycohen2@gmail.com>
#
#
#    DONATION REQUEST: If this free software has helped you and you find
#    it valuable, please consider making a donation to support the ongoing
#    development and maintenance of this project. Your contribution helps
#    ensure the availability of this library to the community and encourages
#    further improvements.
#
#
#                          Donations can be made at:
#                 https://www.paypal.com/paypalme/cstandardlib
#
#	This code is in the Public domain. You are free to do anything with it.
#
#

FUNCS='
static inline size_t dict_size(struct Dict *dict);
static inline void print_uint_array(const unsigned int *array, size_t size);
static inline int *generate_range(int start, int end, int step, size_t *range_size);
static inline int equal_uint_ptr(const unsigned int **array, const unsigned int **array2, size_t size);
static inline char **sorted_strings(char **strings, size_t size);
static inline ssize_t find_first_of(const char *str, const char *char_set);
static inline void *frozen_dict_get(struct FrozenDict *dict, const char *key);
static inline int equal_size_t_ptr(const size_t **array, const size_t **array2, size_t size);
static inline char *format_string(const char *format, ...);
static inline char *trim_chars(const char *str, const char *chars_to_trim);
static inline char *shellescape(const char *str);
static inline void array_uniq(char *arr[], size_t size);
static inline size_t find_max_length_bitonic_subarray(const int *array, long size);
static inline size_t dict_to_a(struct Dict *dict, char ***keys, void ***values);
static inline unsigned long long *sorted_ulong_longs(unsigned long long *ulong_longs, size_t size);
static inline long get_file_size(const char *filename);
static inline void print_ulong_long_ptr_array(const unsigned long long **array, size_t size);
static inline int file_is_directory(const char *filename);
static inline void reverse_array(int *array, size_t size);
static inline int is_string_alpha(const char *str);
static inline void print_long_array(const long *array, size_t size);
static inline long **sorted_long_ptrs(long **long_ptrs, size_t size);
static inline int are_arrays_equal(const int *array1, size_t size1, const int *array2, size_t size2);
static inline char **split(const char *str, char delimiter, size_t *count);
static inline unsigned long long **sorted_ulong_long_ptrs(unsigned long long **ulong_long_ptrs, size_t size);
static inline int are_all_elements_positive(const int *array, size_t size);
static inline int equal_short_ptr(const short **array, const short **array2, size_t size);
static inline void *frozen_dict_get_check(struct FrozenDict *dict, const char *key, int *key_is_in_dict);
static inline int find_maximum_consecutive_sum(const int *array, size_t size);
static inline size_t frozen_dict_to_a(struct FrozenDict *dict, char ***keys, void ***values);
static inline void transpose(int **matrix, size_t rows, size_t cols);
static inline int find_majority_element(const int *array, size_t size);
static inline char *to_lowercase(const char *str);
static inline void print_int_array(const int *array, size_t size);
static inline int is_palindrome(const char *str);
static inline struct FrozenSet *frozen_set_new_instance(size_t num_args, ...);
static inline size_t common_prefix_length(const char *str1, const char *str2);
static inline void print_int_ptr_array(const int **array, size_t size);
static inline size_t count_occurrences(const char *str, const char *substring);
static inline int equal_int_ptr(const int **array, const int **array2, size_t size);
static inline int equal_long(const long *array, const long *array2, size_t size);
static inline char *read_file(const char *filename);
static inline void print_ushort_ptr_array(const unsigned short **array, size_t size);
static inline int equal_ulong(const unsigned long *array, const unsigned long *array2, size_t size);
static inline int *find_intersection(const int *array1, size_t size1, const int *array2, size_t size2, size_t *intersection_size);
static inline int file_exists(const char *filename);
static inline size_t frozen_dict_size(struct FrozenDict *dict);
static inline void *arraydup(const void *arr, size_t num_mem, size_t size);
static inline int find_min(const int *array, size_t size);
static inline void print_double_array(const double *array, size_t size);
static inline int is_alpha(const char *str);
static inline void dict_resize(struct Dict *dict);
static inline void print_ulong_array(const unsigned long *array, size_t size);
static inline char *longest_common_prefix(const char **strings, size_t count);
static inline int is_alphanumeric(const char *str);
static inline struct FrozenDict *frozen_dict_new_instance(size_t num_args, ...);
static inline float *sorted_floats(float *floats, size_t size);
static inline void array_uniq_adjacent(char *arr[], size_t size);
static inline void print_short_array(const short *array, size_t size);
static inline int calculate_mode(const int *arr, size_t size);
static inline int equal_char(const char *array, const char *array2, size_t size);
static inline void remove_file(const char *filename);
static inline void free_array(void **array, size_t len);
static inline int is_sorted_descending(const int *array, size_t size);
static inline unsigned int dict_hash(const char *key, size_t capacity);
static inline void print_uchar_ptr_array(const unsigned char **array, size_t size);
static inline short **sorted_short_ptrs(short **short_ptrs, size_t size);
static inline void set_add(struct Set *dict, const char *key);
static inline int are_all_elements_zero(const int *array, size_t size);
static inline void print_long_long_ptr_array(const long long **array, size_t size);
static inline double *sorted_doubles(double *doubles, size_t size);
static inline unsigned int **sorted_uint_ptrs(unsigned int **uint_ptrs, size_t size);
static inline void set_resize(struct Set *dict);
static inline size_t count_vowels(const char *str);
static inline void dict_destructor(struct Dict *dict);
static inline size_t common_suffix_length(const char *str1, const char *str2);
static inline int equal_double(const double *array, const double *array2, size_t size);
static inline int is_sorted_ascending(const int *array, size_t size);
static inline unsigned char **sorted_uchar_ptrs(unsigned char **uchar_ptrs, size_t size);
static inline void set_destructor(struct Set *dict);
static inline unsigned long **sorted_ulong_ptrs(unsigned long **ulong_ptrs, size_t size);
static inline void print_string_array(char **array, size_t size);
static inline void foundationallib_error_handler(const char *message);
static inline void append_to_file(const char *filename, const char *content);
static inline char *frozen_dict_to_s(struct FrozenDict *dict, int pointer_or_string);
static inline int equal_ulong_long_ptr(const unsigned long long **array, const unsigned long long **array2, size_t size);
static inline char *reverse_words(const char *str);
static inline int equal_float_ptr(const float **array, const float **array2, size_t size);
static inline void append(char ***array, size_t *count, const char *element);
static inline struct Set *set_new_instance();
static inline int equal_uchar_ptr(const unsigned char **array, const unsigned char **array2, size_t size);
static inline short *sorted_shorts(short *shorts, size_t size);
static inline char **list_files_with_pattern(const char *directory, const char *pattern, size_t *len);
static inline char *string_to_lowercase(char *str);
static inline void reverse_in_place(char *str);
static inline int is_array_digit(const char *arr[], size_t size);
static inline size_t frozen_set_to_a(struct FrozenSet *dict, char ***keys, void ***values);
static inline void print_char_array(const char *array, size_t size);
static inline void print_char_ptr_array(const char **array, size_t size);
static inline char *set_to_s(struct Set *dict);
static inline int equal_ulong_long(const unsigned long long *array, const unsigned long long *array2, size_t size);
static inline int are_all_elements_even(const int *array, size_t size);
static inline char **sorted_char_ptrs(char **char_ptrs, size_t size);
static inline void print_uchar_array(const unsigned char *array, size_t size);
static inline int frozen_set_in(struct FrozenSet *dict, const char *key);
static inline int file_is_executable(const char *filename);
static inline ssize_t find_last_of(const char *str, const char *char_set);
static inline char *read_bytes_from_file(const char *filename, size_t num_bytes);
static inline void print_double_ptr_array(const double **array, size_t size);
static inline int is_array_lower(const char *arr[], size_t size);
static inline ssize_t find_equilibrium_index(const int *array, size_t size);
static inline int equal_short(const short *array, const short *array2, size_t size);
static inline int are_all_elements_odd(const int *array, size_t size);
static inline size_t **sorted_size_t_ptrs(size_t **size_t_ptrs, size_t size);
static inline int *sorted_ints(int *ints, size_t size);
static inline void dict_add(struct Dict *dict, const char *key, void *value);
static inline char *dup_format(const char *format, ...);
static inline int is_string_alphanumeric(const char *str);
static inline int set_in(struct Set *dict, const char *key);
static inline void print_uint_ptr_array(const unsigned int **array, size_t size);
static inline void print_short_ptr_array(const short **array, size_t size);
static inline struct Dict *dict_new_instance();
static inline size_t set_to_a(struct Set *dict, char ***keys);
static inline int equal_long_long_ptr(const long long **array, const long long **array2, size_t size);
static inline unsigned int *sorted_uints(unsigned int *uints, size_t size);
static inline int equal_ulong_ptr(const unsigned long **array, const unsigned long **array2, size_t size);
static inline double calculate_average(const int *array, size_t size);
static inline int is_string_upper(const char *str);
static inline char *concatenate_multiple_strings(const char *strings[], size_t num_strings);
static inline double **sorted_double_ptrs(double **double_ptrs, size_t size);
static inline int ends_with(const char *str, const char *suffix);
static inline int is_string_printable(const char *str);
static inline char *concatenate_four_strings(const char *str1, const char *str2, const char *str3, const char *str4);
static inline size_t frozen_set_size(struct FrozenSet *dict);
static inline void print_long_ptr_array(const long **array, size_t size);
static inline int equal_double_ptr(const double **array, const double **array2, size_t size);
static inline char *string_to_uppercase(char *str);
static inline void rotate_array(int *array, size_t size, unsigned long positions);
static inline int majority_element(const int *arr, size_t size);
static inline void *dict_get(struct Dict *dict, const char *key);
static inline int *merge_sorted_arrays(const int *array1, size_t size1, const int *array2, size_t size2, size_t *merged_size);
static inline void dict_del(struct Dict *dict, const char *key);
static inline void frozen_set_destructor(struct FrozenSet *dict);
static inline int equal_long_long(const long long *array, const long long *array2, size_t size);
static inline char *frozen_set_to_s(struct FrozenSet *dict);
static inline char *to_uppercase(const char *str);
static inline char *trim_whitespace(const char *str);
static inline char *strip(const char *str);
static inline int equal_long_ptr(const long **array, const long **array2, size_t size);
static inline int equal_ushort_ptr(const unsigned short **array, const unsigned short **array2, size_t size);
static inline ssize_t index_of(const char *str, char target);
static inline void print_float_array(const float *array, size_t size);
static inline size_t remove_duplicates(int *array, size_t size);
static inline size_t *sorted_size_ts(size_t *size_ts, size_t size);
static inline unsigned char *sorted_uchars(unsigned char *uchars, size_t size);
static inline ssize_t binary_search(const int *sorted_array, size_t size, int target);
static inline char *join(const char **array, size_t count, const char *delimiter);
static inline int is_valid_integer(const char *str);
static inline int are_anagrams(const char *str1, const char *str2);
static inline void prepend(char ***array, size_t *count, const char *element);
static inline int is_string_digit(const char *str);
static inline double calculate_median(int *arr, size_t size);
static inline long long **sorted_long_long_ptrs(long long **long_long_ptrs, size_t size);
static inline int file_is_readable(const char *filename);
static inline char first_non_repeating_char(const char *str);
static inline int is_array_upper(const char *arr[], size_t size);
static inline void *replicate(const void *source, size_t source_size, size_t elem_size, size_t repetitions);
static inline long *sorted_longs(long *longs, size_t size);
static inline char *replace_all(const char *str, const char *old_substring, const char *new_substring);
static inline int file_is_regular(const char *filename);
static inline ssize_t find_index(const int *array, size_t size, int target);
static inline void print_size_t_ptr_array(const size_t **array, size_t size);
static inline unsigned short **sorted_ushort_ptrs(unsigned short **ushort_ptrs, size_t size);
static inline char *concatenate_strings(const char *str1, const char *str2);
static inline int calculate_sum(const int *array, size_t size);
static inline int equal_int(const int *array, const int *array2, size_t size);
static inline size_t set_size(struct Set *dict);
static inline void *dict_get_check(struct Dict *dict, const char *key, int *key_is_in_dict);
static inline int equal_char_ptr(const char **array, const char **array2, size_t size);
static inline char *dict_to_s(struct Dict *dict, int pointer_or_string);
static inline int equal_uint(const unsigned int *array, const unsigned int *array2, size_t size);
static inline char *reverse_string(const char *str);
static inline char *string_to_json(const char *input_string);
static inline ssize_t last_index_of(const char *str, char target);
static inline int equal_size_t(const size_t *array, const size_t *array2, size_t size);
static inline void print_size_t_array(const size_t *array, size_t size);
static inline void set_del(struct Set *dict, const char *key);
static inline int equal_float(const float *array, const float *array2, size_t size);
static inline int find_kth_smallest(int *array, size_t size, size_t k);
static inline double calculate_mean(const int *arr, size_t size);
static inline int is_string_lower(const char *str);
static inline int equal_ushort(const unsigned short *array, const unsigned short *array2, size_t size);
static inline void print_ulong_long_array(const unsigned long long *array, size_t size);
static inline void print_long_long_array(const long long *array, size_t size);
static inline char *to_title_case(const char *str);
static inline unsigned short *sorted_ushorts(unsigned short *ushorts, size_t size);
static inline void print_ushort_array(const unsigned short *array, size_t size);
static inline void print_float_ptr_array(const float **array, size_t size);
static inline int *find_longest_increasing_subsequence(const int *array, size_t size, size_t *subsequence_size);
static inline char first_non_repeating(const char *str);
static inline int are_all_elements_negative(const int *array, size_t size);
static inline char *concatenate_five_strings(const char *str1, const char *str2, const char *str3, const char *str4, const char *str5);
static inline int **sorted_int_ptrs(int **int_ptrs, size_t size);
static inline void print_ulong_ptr_array(const unsigned long **array, size_t size);
static inline float **sorted_float_ptrs(float **float_ptrs, size_t size);
static inline int is_string_space(const char *str);
static inline int file_is_writable(const char *filename);
static inline char *concatenate_three_strings(const char *str1, const char *str2, const char *str3);
static inline int has_mixed_characters(const char *arr[], size_t size);
static inline unsigned int set_hash(const char *key, size_t capacity);
static inline int *find_union(const int *array1, size_t size1, const int *array2, size_t size2, size_t *union_size);
static inline void copy_file(const char *source_filename, const char *destination_filename);
static inline char *longest_common_suffix(const char **strings, size_t count);
static inline char *int_to_str(int number);
static inline unsigned long *sorted_ulongs(unsigned long *ulongs, size_t size);
static inline void write_file(const char *filename, const char *content);
static inline int equal_uchar(const unsigned char *array, const unsigned char *array2, size_t size);
static inline int is_numeric(const char *str);
static inline long long *sorted_long_longs(long long *long_longs, size_t size);
static inline void frozen_dict_destructor(struct FrozenDict *dict);
static inline int *find_leaders(const int *array, size_t size, size_t *leaders_size);
static inline size_t array_length(const char **array, size_t count);
static inline char *sorted_chars(char *chars, size_t size);
static inline int find_max(const int *array, size_t size);
static inline char *concatenate(const char *str1, const char *str2);
'

# Check if the number of arguments is not equal to 3
if [ "$#" -ne 3 ]; then
	echo "Generate custom \`standardlib' library (github.com/gregoryc/standardlib) with a given prefix to make it customized and to avoid any possibility whatsoever of namespace collisons."
	echo "Usage $0 <origin_header_file> <prefix (e.g., \"l\", \"g\", [your company name], etc.> <customer_header_output_file>"
	exit 1
fi

function green_text() {
	# ANSI escape code for green text
	GREEN='\033[0;32m'
	NC='\033[0m' # No Color

	# Print text in green
	echo -e "${GREEN}$1${NC}"
}

function main() {
	funcs="$4"
	prefix="$2"
	outfile="$3"
	inputfile="$1"

	data=$(
		grep -o '^(static inline|struct) .* \**\([^()]\+\)(' "$inputfile" |
			sed "s/^(static inline|struct) .* \**\([^()]\+\)(/sed 's\/\\1\/${prefix}\1\/'/"
	)
	# Iterate over the lines in data and combine them with |
	while IFS= read -r line; do
		combined_data+="|$line"
	done <<<"$data"

	# Remove the leading pipe character
	combined_data="cat $inputfile | ${combined_data#|}"

	# Print the combined data
	eval "$combined_data" >$outfile
	green_text "Custom standardlib.h file generated to $(realpath $outfile)"
}

main "$1" "$2" "$3" "$FUNCS"
