*This project has been created as part of the 42 curriculum by ahoumdi.*

# libft

## Description

**libft** is the first project of the 42 Common Core. Its objective is to create a personal C library by reimplementing a selection of standard C library functions, developing additional utility functions, and implementing a basic linked-list API.

The project aims to develop a deeper understanding of fundamental C concepts, particularly memory manipulation, string handling, dynamic memory allocation, pointers, and data structures.

The resulting static library, `libft.a`, serves as a reusable toolkit for subsequent 42 projects.

The project is written in C, follows the 42 Norm, and is compiled using `-Wall -Wextra -Werror`.

### Contents

#### Part 1: Libc re-implementations

The first part consists of reimplementing standard C library functions while preserving their documented behavior and return-value contracts.

**Character classification and conversion**

| Function | Parameters | Description | Return value |
|---|---|---|---|
| `ft_isalpha` | `int c` | Checks whether `c` is an alphabetic character (uppercase or lowercase letter). | `1` if alphabetic, `0` otherwise, as required by the 42 subject. |
| `ft_isdigit` | `int c` | Checks whether `c` is a decimal digit (0–9). | `1` if a digit, `0` otherwise. |
| `ft_isalnum` | `int c` | Checks whether `c` is alphanumeric, meaning alphabetic or numeric. | `1` if alphanumeric, `0` otherwise. |
| `ft_isascii` | `int c` | Checks whether `c` is a 7-bit ASCII value (0–127). | `1` if within the ASCII range, `0` otherwise. |
| `ft_isprint` | `int c` | Checks whether `c` is printable, including the space character. | `1` if printable, `0` otherwise. |
| `ft_toupper` | `int c` | Converts a lowercase alphabetic character to uppercase. Other characters remain unchanged. | The converted character, or the original value if no conversion is necessary. |
| `ft_tolower` | `int c` | Converts an uppercase alphabetic character to lowercase. Other characters remain unchanged. | The converted character, or the original value if no conversion is necessary. |

**Memory manipulation**

| Function | Parameters | Description | Return value |
|---|---|---|---|
| `ft_memset` | `void *s`, `int c`, `size_t n` | Fills the first `n` bytes of the memory area pointed to by `s` with the byte value `c`, converted to an unsigned char. | Returns the original pointer `s`. |
| `ft_bzero` | `void *s`, `size_t n` | Erases the data in the first `n` bytes of the memory area by writing zero bytes. | No return value (`void`). |
| `ft_memcpy` | `void *dest`, `const void *src`, `size_t n` | Copies `n` bytes from the memory area pointed to by `src` to the memory area pointed to by `dest`. The memory areas must not overlap. | Returns the original destination pointer `dest`. |
| `ft_memmove` | `void *dest`, `const void *src`, `size_t n` | Copies `n` bytes from `src` to `dest`. The source and destination memory areas may overlap. | Returns the original destination pointer `dest`. |
| `ft_memchr` | `const void *s`, `int c`, `size_t n` | Scans the first `n` bytes of the memory area for the first occurrence of the byte `c`, interpreted as an unsigned char. | Returns a pointer to the matching byte, or `NULL` if the byte is not found. |
| `ft_memcmp` | `const void *s1`, `const void *s2`, `size_t n` | Compares the first `n` bytes of both memory areas, interpreting each byte as an unsigned char. | Returns an integer less than, equal to, or greater than zero according to the comparison of the first differing pair of bytes. Returns `0` if the compared bytes are identical. |
| `ft_calloc` | `size_t nmemb`, `size_t size` | Allocates memory for an array of `nmemb` elements, each of `size` bytes, and initializes all allocated bytes to zero. | Returns a pointer to the allocated memory, or `NULL` if allocation fails. |

**String manipulation**

| Function | Parameters | Description | Return value |
|---|---|---|---|
| `ft_strlen` | `const char *s` | Calculates the length of the string, excluding the terminating null byte. | Returns the number of bytes preceding the terminating null byte. |
| `ft_strlcpy` | `char *dst`, `const char *src`, `size_t dstsize` | Copies the source string into the destination buffer, copying at most `dstsize - 1` characters and null-terminating the result if `dstsize` is nonzero. | Returns the length of the source string, regardless of whether truncation occurs. |
| `ft_strlcat` | `char *dst`, `const char *src`, `size_t dstsize` | Appends the source string to the destination string, writing at most `dstsize - strlen(dst) - 1` characters when the destination is properly terminated and has room. Null-terminates the result when possible. | Returns the initial length of `dst` plus the length of `src` when `dst` is properly terminated within `dstsize`. If no null byte is found within `dstsize`, returns `dstsize + strlen(src)`. |
| `ft_strchr` | `const char *s`, `int c` | Locates the first occurrence of `c` in the string. The terminating null byte is considered part of the string. | Returns a pointer to the first occurrence of `c`, or `NULL` if it is not found. |
| `ft_strrchr` | `const char *s`, `int c` | Locates the last occurrence of `c` in the string. The terminating null byte is considered part of the string. | Returns a pointer to the last occurrence of `c`, or `NULL` if it is not found. |
| `ft_strncmp` | `const char *s1`, `const char *s2`, `size_t n` | Compares the first `n` characters of both strings, interpreting the compared characters as unsigned chars. Comparison stops at a null byte or at the first differing character. | Returns an integer less than, equal to, or greater than zero according to the first differing characters. Returns `0` if the compared portions are equal. |
| `ft_strnstr` | `const char *big`, `const char *little`, `size_t len` | Locates the first occurrence of `little` in `big`, examining no more than `len` characters of `big`. | Returns a pointer to the beginning of the located substring, or `NULL` if it is not found within the specified length. If `little` is empty, returns `big`. |
| `ft_strdup` | `const char *s` | Allocates sufficient memory using `malloc()` and creates a duplicate of the string, including its terminating null byte. | Returns a pointer to the newly allocated duplicate, or `NULL` if allocation fails. |

**String-to-integer conversion**

| Function | Parameters | Description | Return value |
|---|---|---|---|
| `ft_atoi` | `const char *nptr` | Converts the initial portion of the string to an integer. Leading whitespace is skipped, an optional `+` or `-` sign is recognized, and conversion continues through consecutive decimal digits until a non-digit character is encountered. | Returns the converted integer value. If no valid conversion can be performed, returns `0`. |

**Important implementation requirements**

- The five character-classification functions must return exactly `1` or `0`, as specified by the 42 subject.
- `ft_memcpy` has undefined behavior when the source and destination memory areas overlap. `ft_memmove` must correctly handle overlapping regions.
- `ft_strlcpy` and `ft_strlcat` use the full destination buffer size, including space for the terminating null byte.
- `ft_calloc` must handle allocation-size multiplication overflow and must return a freeable pointer when either allocation dimension is zero, as required by the subject.

#### Part 2: Additional functions

The following descriptions follow the official 42 Libft subject.

| Function | Specification |
|---|---|
| `ft_substr` | Allocates memory using `malloc()` and returns a substring from the string `s`. The substring starts at index `start` and has a maximum length of `len`. |
| `ft_strjoin` | Allocates memory using `malloc()` and returns a new string resulting from concatenating `s1` and `s2`. |
| `ft_strtrim` | Allocates memory using `malloc()` and returns a copy of `s1` with characters from `set` removed from the beginning and the end. |
| `ft_split` | Allocates memory using `malloc()` and returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. Each string is allocated independently. The returned array must be NULL-terminated. |
| `ft_itoa` | Allocates memory using `malloc()` and returns a string representing the integer received as an argument. Negative numbers must be handled. |
| `ft_strmapi` | Applies the function `f` to each character of the string `s`, passing its index as the first argument and the character itself as the second. A new string is allocated to store the results. |
| `ft_striteri` | Applies the function `f` to each character of the string passed as an argument, passing its index as the first argument. Each character is passed by address so it can be modified if necessary. |
| `ft_putchar_fd` | Outputs the character `c` to the specified file descriptor. |
| `ft_putstr_fd` | Outputs the string `s` to the specified file descriptor. |
| `ft_putendl_fd` | Outputs the string `s` followed by a newline to the specified file descriptor. |
| `ft_putnbr_fd` | Outputs the integer `n` to the specified file descriptor. |

#### Part 3: Linked lists

This part introduces singly linked lists and functions for creating, traversing, modifying, and deleting dynamically allocated nodes.

The following structure is defined in `libft.h`, following the official subject:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

**Structure members**

- `content`: The data contained in the node. Using `void *` allows different types of data to be stored.
- `next`: The address of the next node, or `NULL` if the current node is the last one.

**Linked-list function specifications**

The following prototypes and descriptions are based on the official 42 Libft subject.

| Function | Prototype | Specification |
|---|---|---|
| `ft_lstnew` | `t_list *ft_lstnew(void *content);` | Allocates memory using `malloc()` and returns a new node. The `content` member is initialized with the given parameter, and `next` is initialized to `NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds the node `new` at the beginning of the list. |
| `ft_lstsize` | `int ft_lstsize(t_list *lst);` | Counts the number of nodes in the list. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst);` | Returns the last node of the list. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new);` | Adds the node `new` at the end of the list. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Takes a node as a parameter and frees its content using the function `del`. Frees the node itself but does not free the next node. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and frees the given node and all its successors, using the function `del` and `free()`. Finally, sets the pointer to the list to `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Iterates through the list `lst` and applies the function `f` to the content of each node. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Iterates through the list `lst`, applies the function `f` to each node's content, and creates a new list resulting from the successive applications of `f`. The function `del` is used to delete the content of a node if needed. |

**Important linked-list behavior**

- `ft_lstnew` creates one node and initializes its `next` pointer to `NULL`.
- `ft_lstadd_front` and `ft_lstadd_back` modify the list through a pointer to its head pointer (`t_list **lst`).
- `ft_lstdelone` frees only the specified node and its content. It must not free the following nodes.
- `ft_lstclear` frees the specified node and every node following it, then sets the list pointer to `NULL`.
- `ft_lstiter` modifies or processes the content of existing nodes without creating a new list.
- `ft_lstmap` creates a separate list containing the results of applying `f` to the original list's contents. If an allocation fails, the partially created list must be properly cleaned up using `del`.

### Design notes

Several implementation decisions were made to ensure correct behavior, handle edge cases, and manage dynamically allocated memory safely.

- **`ft_memmove`**: Copies bytes forward or backward depending on the relative positions of the source and destination, ensuring correct behavior when memory regions overlap.
- **`ft_calloc`**: Checks for multiplication overflow before allocation using `SIZE_MAX / nmemb`, preventing an invalid allocation size.
- **`ft_itoa` and `ft_putnbr_fd`**: Handle `INT_MIN` without directly negating it as an `int`, avoiding signed integer overflow.
- **`ft_split`**: Handles allocation failures by freeing every previously allocated string and the pointer array before returning `NULL`.
- **`ft_lstmap`**: Handles allocation failures by releasing newly allocated content and clearing the partially constructed list using the supplied `del` function.

## Instructions

### Compilation

From the root of the repository:

```sh
make          # Builds libft.a
make clean    # Removes object files
make fclean   # Removes object files and libft.a
make re       # Performs fclean followed by all
```

The Makefile:

- Compiles source files using `cc -Wall -Wextra -Werror`.
- Creates the static library using `ar rcs`.
- Rebuilds affected object files when source files or `libft.h` change.

### Usage

Include the library header in your source file:

```c
#include "libft.h"
```

Compile and link your program against the static library:

```sh
cc -Wall -Wextra -Werror main.c libft.a -o main
```

Run the resulting executable:

```sh
./main
```

## Resources

### References

- **42 Libft subject** (`libft.en.subject.pdf`): Official project specifications, function prototypes, requirements, and descriptions.
- **42 Norm**: Coding standards and formatting requirements.
- **Linux man-pages (section 3)**: Documentation for standard C library functions.
- **BSD manual pages**: Documentation for functions such as `bzero`, `strlcpy`, `strlcat`, and `strnstr`.
- **ISO/IEC 9899 (C Standard)**: Reference for C language behavior, memory operations, pointers, and undefined behavior.
- **GNU Make Manual**: https://www.gnu.org/software/make/manual/
- **ar(1) manual page**: Documentation for creating static libraries.
- **Valgrind Documentation**: Memory leak detection and memory error analysis.
- **AddressSanitizer Documentation**: Detection of memory corruption, invalid memory access, and other memory-related errors.

### AI Usage

AI tools were used as learning and educational assistants throughout this project, with an emphasis on understanding concepts rather than generating solutions.

AI assistance focused on:

- **Low-level conceptual explanations:** Understanding how C works internally, including pointers, memory layout, stack and heap, dynamic allocation, pointer ownership, memory lifetime, and the behavior of functions at the system level.
- **Code review:** Identifying logical errors, examining implementation choices, discussing design decisions, and investigating potential edge cases.
- **Testing:** Exploring edge cases, reasoning about expected behavior, and improving test coverage.
- **Debugging:** Understanding compiler errors, investigating unexpected behavior, and analyzing memory-related problems.
- **Build systems:** Understanding Makefiles, compilation, linking, static libraries, and dependency management.

AI was not used as a substitute for implementation. Its role was to support independent problem-solving, challenge assumptions, clarify difficult concepts, and strengthen the understanding of C programming fundamentals.

The objective was not simply to make the code work, but to understand exactly how and why it works.
