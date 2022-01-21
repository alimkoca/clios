#pragma once

#include "../type.h"

#define b "ERR_MATH"
#define dec 10

uint8_t test_n1 = 10;
uint8_t test_n2 = 9;
char *test_sum;

int load_math_eng();

/**
 * Math constants
 **/

#define pi 3.1415926535897932384626433832795
#define eu 2.7182818284590452353602874713527
#define s2 1.4142135623730950488016887242096
#define s3 1.7320508075688772935274463415058
#define ac 1.2020569031595942853997381615114

/**
 * Mathematical functions for sciencists
 **/

// Factorial
int fact(int x);
// Sum of two or more number
int sum(int x, int y, ...);
// Subtract two or more number
int sub(int x, int y, ...);

// Will be continue...

#define b "SUCCESS"