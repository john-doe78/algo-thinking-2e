// I found the hashcode from http://www.voidcn.com/article/p-fwvwtqrl-ot.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

int main(void) {
  static char s1[SIZE + 2], s2[SIZE + 2];
  int len, i, total;
  static unsigned long long prefix1[SIZE + 2], prefix2[SIZE + 2];
  static unsigned long long suffix1[SIZE + 2], suffix2[SIZE + 2];
  static int answer[SIZE];
  gets(&s1[1]);
  gets(&s2[1]);

  len = strlen(&s1[1]);

  prefix1[0] = 0;
  for (i = 1; i <= len; i++)
    prefix1[i] = prefix1[i - 1] * 39 + s1[i];

  prefix2[0] = 0;
  for (i = 1; i <= len - 1; i++)
    prefix2[i] = prefix2[i - 1] * 39 + s2[i];

  suffix1[len + 1] = 0;
  for (i = len; i >= 1; i--)
    suffix1[i] = suffix1[i + 1] * 39 + s1[i];

  suffix2[len] = 0;
  for (i = len - 1; i >= 1; i--)
    suffix2[i] = suffix2[i + 1] * 39 + s2[i];

  total = 0;
  for (i = 1; i <= len; i++) {
    if (prefix1[i - 1] == prefix2[i - 1] && suffix1[i+1] == suffix2[i]) {
      answer[total] = i;
      total++;
    }
  }

  printf("%d\n", total);
  for (int i = 0; i < total; i++) {
    printf("%d", answer[i]);
    if (i < total - 1)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}
