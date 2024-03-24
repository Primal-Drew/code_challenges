#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Using asprintf()
char *solution1(int n) {
  static char *R1[]    = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
  static char *R10[]   = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
  static char *R100[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
  static char *R1000[] = {"", "M", "MM", "MMM" };
  
  char *buf;
  asprintf(&buf, "%s%s%s%s", R1000[n/1000], R100[n%1000/100], R10[n%100/10], R1[n%10]);
  return buf;
}



