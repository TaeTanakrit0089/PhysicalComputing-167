# Lab07 Function

## Lecture Slide

- [lecture_slide.md](lecture_slide.md)
- [PC-Chapter 7 - Lecture Note.pdf](files/PC-Chapter%207%20-%20Lecture%20Note.pdf)

## Standard Functions in C: Math, String and Character Manipulation

### 1. Mathematics - `math.h`

This header file provides various mathematical functions and macros.

#### Common Functions:

| Function    | Description                                 | Example                                           |
|-------------|---------------------------------------------|---------------------------------------------------|
| `sin(x)`    | Returns the sine of `x` (in radians).       | `double result = sin(PI/2); // result = 1.0`      |
| `cos(x)`    | Returns the cosine of `x` (in radians).     | `double result = cos(PI); // result = -1.0`       |
| `tan(x)`    | Returns the tangent of `x` (in radians).    | `double result = tan(PI/4); // result = 1.0`      |
| `sqrt(x)`   | Returns the square root of `x`.             | `double result = sqrt(9); // result = 3.0`        |
| `pow(x, y)` | Returns `x` raised to the power of `y`.     | `double result = pow(2, 3); // result = 8.0`      |
| `exp(x)`    | Returns the exponential value of `x` (e^x). | `double result = exp(1); // result = 2.71828...`  |
| `log(x)`    | Returns the natural logarithm of `x`.       | `double result = log(10); // result = 2.30258...` |
| `log10(x)`  | Returns the base-10 logarithm of `x`.       | `double result = log10(100); // result = 2.0`     |
| `ceil(x)`   | Rounds `x` up to the nearest integer.       | `double result = ceil(4.2); // result = 5.0`      |
| `floor(x)`  | Rounds `x` down to the nearest integer.     | `double result = floor(4.7); // result = 4.0`     |
| `fabs(x)`   | Returns the absolute value of `x`.          | `double result = fabs(-3.5); // result = 3.5`     |

#### Example:

```c
#include <stdio.h>
#include <math.h>

int main() {
  double num = 2.7;

  printf("Sine of %.2f: %.2f\n", num, sin(num));
  printf("Square root of %.2f: %.2f\n", num, sqrt(num));
  printf("Ceiling of %.2f: %.2f\n", num, ceil(num));

  return 0;
}
```

### 2. String - `string.h`

This header file provides functions for manipulating C-style strings (null-terminated character arrays).

#### Common Functions:

| Function                   | Description                                                                        | Example                                                                                     |
|----------------------------|------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------|
| `strlen(str)`              | Returns the length of the string `str`.                                            | `int len = strlen("hello"); // len = 5`                                                     |
| `strcpy(dest, src)`        | Copies the string `src` into the string `dest`.                                    | `char dest[10]; strcpy(dest, "world"); // dest becomes "world"`                             |
| `strcat(dest, src)`        | Appends the string `src` to the end of the string `dest`.                          | `char dest[20] = "hello"; strcat(dest, " world"); // dest becomes "hello world"`            |
| `strcmp(str1, str2)`       | Compares two strings lexicographically.                                            | `int result = strcmp("apple", "banana"); // result < 0 (apple comes before banana)`         |
| `strncmp(str1, str2, n)`   | Compares the first `n` characters of two strings.                                  | `int result = strncmp("hello", "hell", 4); // result = 0 (first 4 characters are the same)` |
| `strstr(haystack, needle)` | Finds the first occurrence of the substring `needle` within the string `haystack`. | `char *ptr = strstr("This is a test", "is"); // ptr points to "is a test"`                  |

#### Example:

```c
#include <stdio.h>
#include <string.h>

int main() {
  char str1[20] = "hello";
  char str2[] = " world";

  printf("Length of str1: %lu\n", strlen(str1));

  strcat(str1, str2);
  printf("Concatenated string: %s\n", str1);

  return 0;
}
```

### 3. Character - `ctype.h`

This header file offers functions for character classification and conversion.

#### Common Functions:

| Function     | Description                                 | Example                                     |
|--------------|---------------------------------------------|---------------------------------------------|
| `isalpha(c)` | Checks if `c` is an alphabetic character.   | `if (isalpha('a')) { ... } // true`         |
| `isdigit(c)` | Checks if `c` is a decimal digit.           | `if (isdigit('5')) { ... } // true`         |
| `isalnum(c)` | Checks if `c` is an alphanumeric character. | `if (isalnum('_')) { ... } // false`        |
| `islower(c)` | Checks if `c` is a lowercase letter.        | `if (islower('A')) { ... } // false`        |
| `isupper(c)` | Checks if `c` is an uppercase letter.       | `if (isupper('Z')) { ... } // true`         |
| `tolower(c)` | Converts `c` to lowercase.                  | `char lower = tolower('A'); // lower = 'a'` |
| `toupper(c)` | Converts `c` to uppercase.                  | `char upper = toupper('b'); // upper = 'B'` |

#### Example:

```c
#include <stdio.h>
#include <ctype.h>

int main() {
  char ch = 'A';

  if (isupper(ch)) {
    printf("%c is uppercase.\n", ch);
  }

  printf("Lowercase: %c\n", tolower(ch));

  return 0;
}
```

These are just a few of the many functions available in `math.h`, `string.h`, and `ctype.h`. For a complete list and
more detailed descriptions, refer to the C library documentation. 
