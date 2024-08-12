# Lecture 07 - Function

## Chapter 7: Function

[PC-Chapter 7 - Lecture Note.pdf](files/PC-Chapter%207%20-%20Lecture%20Note.pdf)

## Outline

* Introduction to function
* **User defined function**
    * Function declaration
    * Function design
    * Parameter passing
* **Standard function**

## What is function?

* It is a block of code that has a name, and it has a property that it is reusable
* It can be executed from as many different points in a C Program as required
* We pass information to the function called arguments specified when the function is called.
* The function either returns some value to the point it was called from or returns nothing.

## Functions in C

* **User defined function** - Write your own function
* **Standard function** - In standard library

## Function in C

```
main()
|
+-- func1 ()
|    |
|    +-- funcA ()
|    +-- funcB()
|
+-- func2 ()
|    |
|    +-- funcC () 
|    +-- funcD() 
|    +-- funcE () 
|
+-- func3 ()
```

## User defined function

**Header**

```c
return_type function_name (parameter_list)
```

**Body**

```c
{ 
    // Local Declarations
    // Statements
    // Return
}
```

## Void Type

* To signify that a function returns no value

```c
int FirstEx()
{
    int x;
    return x;
}

void SecondEx()
{
    ...
}
```

## Function Declaration

```c
#include<file.h>

type func_name(type);
type variable

int main()
{
    type variable;
    statement.1;
    statement.n;
    var = func_name (value);
    return 0;
}

type func_name(type variable)
{
    statement.1;
    statement.n;
    return (var);
}
```

## Can we write functions before main program?

Yes

## Function Declaration

```c
#include<file.h>
type variable

type func_name(type variable)
{
    statement.1;
    statement.n;
    return (var);
}

int main()
{
    type variable;
    statement.1;
    statement.n;
    var = func_name (value);
    return 0;
}
```

## Function Design

* Without input, without output:
    ```
    [Function]
    ```
* With input, without output:
    ```
    Input --> [Function]
    ```
* Without input, with output:
    ```
    [Function] --> Output
    ```
* With input, with output:
    ```
    Input --> [Function] --> Output
    ```

## Function: Without Input/Output

```c
#include <stdio.h>

void hello();

int main()
{
    printf("Function main 1\n");
    hello();
    printf("Function main 2\n");
    return 0;
}

void hello()
{
    printf("Hello World!!\n");
}
```

## Function: With Input, Without Output

```c
#include <stdio.h>

void showValue (int x);

int main()
{
    int i=20;  // i = 20
    showValue(i); // x = 20
    return 0;
}

void showValue (int x)
{
    printf("%d\n",x); // prints 20
}
```

## Function: Without Input, With Output

```c
#include <stdio.h>

int getInput();

int main()
{
    int input;
    input = getInput(); // input = 50
    printf("input = %d", input); 
    return 0;
}

int getInput ()
{
    int num;
    printf("Input number: ");
    scanf("%d", &num); // num = 50
    return num; 
}
```

## Function: With Input, With Output

```c
#include <stdio.h>

float cubeVol (float x);

int main()
{
    float side = 10.5;  // side = 10.5
    float volume;
    volume = cubeVol(side); // x = 10.5, Volume = 1157.625
    printf("Volume of cube = %f", volume); 
    return 0;
}

float cubeVol (float x)
{
    return x*x*x;
}
```

## Parameter Passing

```c
#include <stdio.h>

void printValue (int x, float y);

int main()
{
    int a=10;
    printValue(a, 20.5);
    return 0;
}

void printValue(int x, float y) // #argument = #parameter
{                                 // Type of argument ≈ Type of parameter
    printf("%d %f\n", x, y);
}
```

## Parameter Passing

* **Pass by value**
* **Pass by reference** - Array, Pointer - Will be in Pointer Topic

## Pass by Value

```c
#include <stdio.h>
void add (int x, int y);

int main()
{
    int a = 10; // a = 10
    int b= 15;  // b = 15
    printf("a = %d\n", a);
    add(a,b); // x = 10, y = 15, x = 25
    printf("a = %d\n", a); // a = 10
    return 0;
}

void add(int x, int y)
{
    x = x + y;
    printf("x = %d\n", x); // x = 25
}
```

## Passing Array Argument to Functions

```c
#include <stdio.h>
#define MAX_NUM 10

int findMax (int list [MAX_NUM]);
int findMin (int list [MAX_NUM]);

int main()
{
    int list [MAX_NUM];
    int i;
    printf("Enter 10 numbers: ");
    for (i = 0; i < MAX_NUM; i++)
        scanf("%d", &list [i]);
    
    printf("Maximum number = %d\n", findMax (list)); // Maximum number = 32
    printf("Minimum number = %d\n", findMin (list)); // Minimum number = 2
    return 0;
}

// Input: 10 11 5 6 4 2 24 16 32 14

int findMax (int list [MAX_NUM])
{
    int max;
    int i;
    max = list[0];
    for (i = 0; i < MAX_NUM; i++)
        if (list[i] > max)
            max = list[i];
    return max;
}

int findMin (int list [MAX_NUM])
{
    int min;
    int i;
    min = list[0];
    for (i = 0; i < MAX_NUM; i++)
        if (list[i] < min)
            min = list[i];
    return min;
}
```

## Scope of Visibility

* The scope of variables can be global or local.
* A global variable's scope includes all the statements in a program.
* The scope of a local variable includes only statements inside the function in which it is declared.
* The same identifier can be reused inside different functions to name different variables.
* A name is local if it is declared in the current scope, and it is global if declared in an outer scope.

## Example 1

```c
#include <stdio.h>

int a; // Global Scope

void functionA();

int main()
{
    a = 20;
    printf("main (start) -> a = %d\n", a); // main (start) -> a = 20
    functionA(); 
    printf("main (after) -> a = %d\n", a); // main (after) -> a = 20
    return 0;
}

void functionA()
{
    int a = 10; // Local Scope
    a = a + 5;
    printf("in functionA -> a = %d\n", a); // in functionA -> a = 15
}
```

## Example 2 (1/2)

```c
#include <stdio.h>

int x; // Global Scope

void functionA();
void functionB (int x);

int main()
{
    x = 10;
    printf("main (start) -> x = %d\n", x); // main (start) -> x = 10
    functionA(); 
    printf("main (after funcA) -> x = %d\n", x); // main (after funcA) -> x = 20
    functionB(x);
    printf("main (after funcB) -> x = %d\n", x); // main (after funcB) -> x = 20
    return 0;
}
```

## Example 2 (2/2)

```c
void functionA()
{
    x = x + 10; // Global Scope
    printf("in functionA -> x = %d\n", x); // in functionA -> x = 20
}

void functionB (int x)
{
    x = x + 10; // Local Scope
    printf("in functionB -> x = %d\n", x); // in functionB -> x = 30
}
```

## Standard Functions

```c
#include <header_file.h>
```

* Standardized collection of header files and library routines used to implement common operations

## Standard Functions

* **Mathematics** • **math.h**
* **String** • **string.h**
* **Character** • **ctype.h**

## math.h (1/2)

| Functions                        | Descriptions                         |
|----------------------------------|--------------------------------------|
| `double sin(double x)`           | Sine of x, where x is in radian      |
| `double cos(double x)`           | Cosine of x, where x is in radian    |
| `double tan(double x)`           | Tan of x, where x is in radian       |
| `double exp(double x)`           | e<sup>x</sup> where x≈2.718282       |
| `double log(double x)`           | Natural logarithm of x, where x>0    |
| `double log10(double x)`         | Logarithm of x to base 10, where x>0 |
| `double pow(double x, double y)` | x<sup>y</sup>, where x>0             |
| `double sqrt(double x)`          | √x                                   |

## math.h (2/2)

| Functions                                                                                      | Descriptions                 |
|------------------------------------------------------------------------------------------------|------------------------------|
| `double ceil(double x)` <br> `float ceilf(float x)` <br> `long double ceill(long double x)`    | Round up to integral value   |
| `double floor(double x)` <br> `float floorf(float x)` <br> `long double floorl(long double x)` | Round down to integral value |
| `int abs(int x)` <br> `long labs(long x)` <br> `double fabs(double x)`                         | Round up to integral value   |

## Example

```c
#include <stdio.h>
#include <math.h>
#define PI 3.141592654

int main()
{
    double degree;
    double radian;
    degree = 60.0;
    radian = degree * PI/180;
    printf("degree = %f\n", degree);   // degree = 60.000000
    printf("radian = %f\n", radian);   // radian = 1.047198
    printf("cos = %f\n", cos (radian));  // cos = 0.500000
    printf("sin = %f\n", sin (radian));  // sin = 0.866025
    printf("tan = %f\n", tan (radian));  // tan = 1.732051
    return 0;
}
```

## string.h

| Functions              | Descriptions                         |
|------------------------|--------------------------------------|
| `strcpy(str1, str2)`   | Copy string                          |
| `strcat(dest1, dest2)` | Concatenate strings                  |
| `strcmp(str1, str2)`   | Compare strings                      |
| `strcmpi(str1, str2)`  | Compare strings (not case sensitive) |
| `strlen(str);`         | Determine string length              |

## ctype.h

| Functions      | Descriptions                         |
|----------------|--------------------------------------|
| `tolower(ch);` | Convert character case to lower case |
| `toupper(ch);` | Convert character case to upper case |

## Chapter 7: Function

**Completed**

**06016409 - Physical Computing**
Kitsuchart Pasupa, PhD
School of Information Technology
King Mongkut's Institute of Technology Ladkrabang
