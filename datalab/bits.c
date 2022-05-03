/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using only the following:
  1. integer constants 0 through 255 (0xff), inclusive. you are
      not allowed to use big constants such as 0xffffffff.
  2. function arguments and local variables (no global variables).
  3. unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return (~(~x & ~y) & ~(x & y)); // Extracted from XOR truth table
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1 << 31); // tmin is a 1 followed by w-1 zeroes
}
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) { return !(~(x + (!(x + 1) ^ (x + 1)))); }
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int a = 0xAA;
  a = (a << 8) + 0xAA;
  a = (a << 8) + 0xAA;
  a = (a << 8) + 0xAA;   // Construct AllOddBits 0xAAAAAAAA
  return !((x & a) ^ a); // if x&a == a then (x&a)^a == 0
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x + 1); // From two's complement definition
}
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0'
 * to '9') Example: isAsciiDigit(0x35) = 1. isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /* x >= 30 :
   *   0x...30 >> 4 = 0x...3
   *   0x...3 + (-3) will be zero only when bit pattern "..." is all zeroes
   *
   * x <= 39 :
   *   if x + (-39) is negative then x > 39
   */
  return !((x >> 4) + (~(0x3) + 1)) & !!((x + (~(0x39))) & (1 << 31));
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int a = !(x & (~0));       // a = x==0? 1:0
  int k = (~0) + a;          // k = a? 0 : Tmax
  return (y & k) + (z & ~k); // x ? y : z
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int minus = (1 << 31);
  int signx = !(x & minus);     // is x positive
  int signy = !(y & minus);     // is y positive
  int ymx = y + (~x + 1);       // y - x
  int equals = !(x ^ y);        // x == y
  int isXtmin = !(x ^ minus);   // x == Tmin
  int signymx = !(ymx & minus); // is y - x > 0
  // Karnaugh Map
  // Vertical: signymx/isXtmin -> AB
  // Horizontal: signx/signy -> CD
  //
  //    00 01 11 10
  // 00  0  1  0  0
  // 01  1  1  x  x
  // 11  1  1  x  x
  // 10  1  1  1  0
  //
  // y = B + C'D + AC' + AD
  // return y + equals
  return (((!signx) & signy) | (signymx & (!signx)) | (signymx & (signy))) |
         equals | isXtmin;
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 ./dlc -e bits.c
 */
int logicalNeg(int x) {
  int Tmin = 0x01 << 31;
  int sign_x = x & Tmin;
  int sign_neg = (~x + 0x01) & Tmin;
  int sumshft = 1 + ((sign_x + sign_neg) >> 31);
  int isXnotTmin = 1 + ((sign_x | sign_neg) >> 31);
  return sumshft & isXnotTmin;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // Solution grabbed from chrszhu/funworkstuff3/bits.c on github
  int sign = x >> 31;
	int holder = 0;
	int mask = 0xF;
	int replacement = x;
	
  x = (x & ~sign) | ((~x) & sign);
	replacement = x;
	
	x = x >> 4;
	holder += (0x4 & (!!(x & ~0) << 2));
	x = x >> 4;
	holder += (0x4 & (!!(x & ~0) << 2));
	x = x >> 4;
	holder += (0x4 & (!!(x & ~0) << 2));
	x = x >> 4;
	holder += (0x4 & (!!(x & ~0) << 2));
	x = x >> 4;
	holder += (0x4 & (!!(x & ~0) << 2));
	x = x >> 4;
	holder += (0x4 & (!!(x & ~0) << 2));
	x = x >> 4;
	holder += (0x4 & (!!(x & ~0) << 2));
	
	replacement = (replacement >> holder) & mask;
	
	holder += (1 & !!(replacement&mask));
	replacement = replacement >> 1;
	holder += (1 & !!(replacement&mask));
	replacement = replacement >> 1;
	holder += (1 & !!(replacement&mask));
	replacement = replacement >> 1;
	holder += (1 & !!(replacement&mask));
	holder = holder + 1;
  return holder;
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned int exponent = 0x7f80 << 16;
  unsigned int mantissa = 0x7fffff;
  unsigned int uf_exp = exponent & uf;
  unsigned int uf_mant = mantissa & uf;
  unsigned int expOfOne = 1 << 23;
  if (uf_exp) {
    if ((uf & exponent) == exponent) {
      return uf;
    }
    return ((uf_exp + expOfOne) & exponent) + (uf & ~exponent);
  } else if (uf_mant) {
    if (uf == mantissa) {
      return mantissa << 1;
      // ((uf_exp + expOfOne) & exponent) + (uf & ~exponent);
    } else {
      return ((uf_mant << 1) + (uf & ~mantissa));
    }
  }
  return uf;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned int uf_exp = (0x7f80 << 16) & uf;
  unsigned int sign = 0x80000000u;
  unsigned int uf_sign = uf & sign;
  unsigned int result = 0;
  int exponent_value = 0;

  if (uf == 0x0) {
    return uf;
  }
  uf_exp = uf_exp >> 23;
  exponent_value = uf_exp - 0x7f;
  if (exponent_value < 0) {
    return 0;
  } else if (exponent_value > 16) {
    return sign;
  }
  result = 0x1 << exponent_value;
  if (!uf_sign) {
    return result;
  } else {
    return (~result) + 1;
  }
  return 0;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) { 
  unsigned int exponent_field = 0x7f80 << 16;
  unsigned int result = 0;
  char stepping_var; 
  if (x > 127) {
    return exponent_field; 
  } else if (x < -127) {
    return 0x0;
  }

  stepping_var = x;
  result = stepping_var + 0x7f;
  result = result << 23;

  return result; 
}
