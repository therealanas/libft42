*This project has been created as part of the 42 curriculum by ahoumdi.*

# libft

## Description

**libft** is the first project of the 42 common core. The goal is to build, from scratch, a small static C library (`libft.a`) that re-implements a selection of standard C library functions, adds a set of useful utility functions, and provides a minimal linked-list API. The library is reused in later 42 projects, so it has to be correct, norm-compliant and free of memory leaks.

The project is written in C, follows the 42 Norm, and is compiled with `-Wall -Wextra -Werror`. Only `malloc`, `free` and `write` are used from the standard library.

### Contents

**Part 1: libc re-implementations**

| Category | Functions |
| --- | --- |
| Character tests / conversion | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Conversion | `ft_atoi` |

**Part 2: additional functions**

`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

**Linked lists**

The library defines the following structure in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

### Design notes

- **`ft_memmove`** copies forward or backward depending on whether the destination lies after the source, so overlapping buffers are handled correctly.
- **`ft_calloc`** checks for multiplication overflow (`size > SIZE_MAX / nmemb`) before calling `malloc`.
- **`ft_itoa` and `ft_putnbr_fd`** handle `INT_MIN` without ever negating it as an `int`.
- **`ft_split`** frees every string already allocated, and the pointer array, if an allocation fails part-way.
- **`ft_lstmap`** releases the new content and the partially built list with the supplied `del` function if any allocation fails.

## Instructions

### Compilation

From the root of the repository:

```sh
make          # builds libft.a
make clean    # removes the object files
make fclean   # removes the object files and libft.a
make re       # fclean followed by all
```

The Makefile compiles with `cc -Wall -Wextra -Werror`, archives the objects with `ar rcs`, and only rebuilds what has changed (including when `libft.h` is modified).

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Then compile and link against the library:

```sh
cc -Wall -Wextra -Werror main.c libft.a -o main
```
## Resources

### References

- `man 3` pages for each re-implemented function (`strlcpy`, `strlcat`, `memmove`, `memchr`, `calloc`, `atoi`, ...)
- The C standard (ISO/IEC 9899), for undefined behavior and the exact contracts of `memcpy` vs. `memmove`
- GNU Make manual: https://www.gnu.org/software/make/manual/
- `ar(1)` manual page, for building static libraries
- The 42 Norm and the project subject (`libft.en.subject.pdf`)
- Valgrind and AddressSanitizer documentation, for leak and memory-error checking

## AI Usage

AI tools were used as learning and educational assistants throughout this project, with an emphasis on understanding concepts rather than generating solutions.

AI assistance focused on:

- **Low-level conceptual explanations:** Understanding how C works internally, including pointers, memory layout, stack and heap, dynamic allocation, pointer ownership, memory lifetime, and the behavior of functions at the system level.
- **Code review:** Identifying logical errors, examining implementation choices, and discussing potential edge cases.
- **Testing:** Exploring edge cases, reasoning about expected behavior, and improving test coverage.

AI was not used as a substitute for implementation. Its role was to support independent problem-solving, challenge assumptions, clarify difficult concepts, and strengthen the understanding of C programming fundamentals.

**The objective was not simply to make the code work, but to understand exactly how and why it works.**
