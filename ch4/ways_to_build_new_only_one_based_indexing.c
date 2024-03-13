/*
You probably don't want this one :D

This is a solution that uses only the new subproblems from Solution 2.
I've used one-based indexing in this one to simplify the solution a bit.

This solution ends up being O(m^2*n*k), which is too slow!
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_A 1000
#define MAX_B 200
#define MAX_K 200
#define MOD 1000000007

int solve(char a[], char b[], int i, int j, int k,
          int memo[MAX_A + 1][MAX_B + 1][MAX_K + 1]) {
  int total, p, q;
  if (memo[i][j][k] != -1)
    return memo[i][j][k];
  if (j == 0 && k == 0) {
    memo[i][j][k] = 1;
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
  memo[i][j][k] = total;
  return memo[i][j][k];
}

int main(void) {
  int a_length, b_length, num_substrings, i, j, k, result;
  char a[MAX_A + 2];
  char b[MAX_B + 2];
  static int memo[MAX_A + 1][MAX_B + 1][MAX_K + 1];
  scanf("%d%d%d", &a_length, &b_length, &num_substrings);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (i = 0; i <= a_length; i++)
    for (j = 0; j <= b_length; j++)
      for (k = 0; k <= num_substrings; k++)
        memo[i][j][k] = -1;
  result = solve(a, b, a_length, b_length, num_substrings, memo);
  printf("%d\n", result);
  return 0;
}
