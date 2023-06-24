# C - printf

* Group project: weight 5.0

### Requirements
* Language(s): `C`
* Operating system: `Ubuntu 20.04 LTS`
* Style Guide: <a href="https://github.com/alx-tools/Betty/tree/master">Betty Style</a>
* Allowed editors: `vi`, `vim`, or `emacs`
* Compilation should be achieved using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* You are allowed to use the following macros: `va_start`, `va_arg` and `va_end`
* No more than 5 functions per file.
* The use of global variables is not allowed.
* You are allowed to use <a href="https://github.com/alx-tools/_putchar.c/blob/master/_putchar.c">_putchar</a>
* All header files should be include guarded.
* The prototypes of all your functions and the prototype of the function `_putchar` should be included in your header file called `main.h`

### Authorized functions and macros
* `write` (`man 2 write`)
* `malloc` (`man 3 malloc`)
* `free` (`man 3 free`)
* `va_start` (`man 3 va_start`)
* `va_end` (`man 3 va_end`)
* `va_copy` (`man 3 va_copy`)
* `va_arg` (`man 3 va_arg`)

NOTE: THE `man` COMMAND CAN BE EXECUTES ON UNIX SYSTEMS TO GET INSIGHT ON THE FUNCTIONS AND MACROS.

### Compilation
`$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c`
All the codes will be compiled this way.

---
### SCRIPTS
0. Write a function that produces output according to a format.
    * Prototype: `int _printf(const char *format, ...);`
    * Returns: the number of characters printed (excluding the null byte used to end output to strings)
    * write output to stdout, the standard output stream
    * `format` is a character string. The format string is composed of zero or more directives.
    * You need to handle the following conversion specifiers:
        * `c`
        * `s`
        * `%`
    * You don’t have to reproduce the buffer handling of the C library `printf` function.
    * You don’t have to handle the flag characters
    * You don’t have to handle field width
    * You don’t have to handle precision
    * You don’t have to handle the length modifiers
<br>

1. The same printf function must handle the following conversion specifiers:
    * `i`
    * `d`
<br>

2. Handle the following custom conversion specifiers:
    * `b`: the unsigned int argument is converted to binary
<br>

3. Handle the following conversion specifiers:
    * `u`
    * `o`
    * `x`
    * `X`
<br>

4. Use a local buffer of 1024 chars in order to call `write` as little as possible.
<br>

5. Handle the following custom conversion specifier:
    * `S` : prints the string.
    * Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: `\x`, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
<br>

6. Handle the following conversion specifier: `p`.
    * You don’t have to handle the flag characters
    * You don’t have to handle field width
    * You don’t have to handle precision
    * You don’t have to handle the length modifiers
<br>

7. Handle the following flag characters for non-custom conversion specifiers:
    * `+`
    * space
    * `#`
<br>

8. Handle the following length modifiers for non-custom conversion specifiers:
    * `l`
    * `h`
    * Conversion specifiers to handle: `d`, `i`, `u`, `o`, `x`, `X`
<br>

9. Handle the field width for non-custom conversion specifiers.
<br>

10. Handle the precision for non-custom conversion specifiers.
<br>

11. Handle the `0` flag character for non-custom conversion specifiers.
<br>

12. Handle the `-` flag character for non-custom conversion specifiers.
<br>

13. Handle the following custom conversion specifier:
    * `r` : prints the reversed string
<br>

14. Handle the following custom conversion specifier:
    * `R`: prints the rot13'ed string
<br>

15. All the above options work well together.
<br>

---
### Authors
* Siphamandla Matshiane
* Peter Uzoma

### LICENSE
<a href="https://www.alxafrica.com/software-engineering/">ALX Software Engineering</a>
