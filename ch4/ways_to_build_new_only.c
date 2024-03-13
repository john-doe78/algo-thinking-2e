/*
You probably don't want this one :D

This is a solution that uses only the new subproblems from Solution 2.

This solution ends up being O(m^2*n*k), which is too slow!
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_A 1000
#define MAX_B 200
#define MAX_K 200
#define MOD 1000000007

int solve(char a[], char b[], int i, int j, int k,
          int memo[MAX_A][MAX_B][MAX_K + 1]) {
  int total, p, q;
  if (memo[i][j][k] != -1)
    return memo[i][j][k];
  if (j == 0 && k == 1) {
    if (a[i] != b[j]) {
      if (i == 0)
        total = 0;
      else
        total = solve(a, b, i - 1, j, k, memo);
      memo[i][j][k] = total;
    } else {
      if (i == 0)
        total = 1;
      else
        total = 1 + solve(a, b, i - 1, j, k, memo);
      memo[i][j][k] = total;
    }
    return memo[i][j][k];
  }
  if (i == 0 || j == 0 || k == 0) {
    memo[i][j][k] = 0;
    return memo[i][j][k];
  }
  total = solve(a, b, i - 1, j, k, memo);
  p = i;
  q = j;
  while (p >= 1 && q >= 1 && a[p] == b[q]) {
    total = (total + solve(a, b, p - 1, q - 1, k - 1, memo)) % MOD;
    p--;
    q--;
  }
  if (q == 0 && k == 1 && a[p] == b[0])
    total++;
  memo[i][j][k] = total;
  return memo[i][j][k];
}

int main(void) {
  int a_length, b_length, num_substrings, i, j, k, result;
  char a[MAX_A + 1];
  char b[MAX_B + 1];
  static int memo[MAX_A][MAX_B][MAX_K + 1];
  scanf("%d%d%d", &a_length, &b_length, &num_substrings);
  scanf("%s", a);
  scanf("%s", b);
  for (i = 0; i < a_length; i++)
    for (j = 0; j < b_length; j++)
      for (k = 0; k <= num_substrings; k++)
        memo[i][j][k] = -1;
  result = solve(a, b, a_length - 1, b_length - 1, num_substrings, memo);
  printf("%d\n", result);
  return 0;
}
