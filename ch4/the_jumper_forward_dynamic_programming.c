#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int min(int v1, int v2) {
  if (v1 < v2)
    return v1;
  else
    return v2;
}

int solve(int cost[], int n) {
  int i, j;
  int first, second;
  static int dp[SIZE + 1][SIZE + 1];
  for (j = 1; j <= n; j++)
    dp[n][j] = 0;
  for (j = n; j >= 1; j--)
    for (i = 1; i < n; i++) {
      if (i + j + 1<= n)
        first = dp[i + j + 1][j + 1];
      else
        first = -1;
      if (i - j >= 1)
        second = dp[i - j][j];
      else
        second = -1;
      if (first == -1 && second == -1)
        dp[i][j] = -1;
      else if (second == -1)
        dp[i][j] = cost[i + j + 1] + first;
      else if (first == -1)
        dp[i][j] = cost[i - j] + second;
      else
        dp[i][j] = min(cost[i + j + 1] + first, cost[i - j] + second);
  }
  return dp[2][1];
}

int main(void) {
  int i, n, result;
  int cost[SIZE + 1];
  scanf("%d ", &n);
  for (i = 1; i <= n; i++)
    scanf("%d", &cost[i]);
  result = cost[2] + solve(cost, n);
  printf("%d\n", result);
  return 0;
}
