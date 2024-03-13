/*
You probably don't want this one :D

This is a solution that uses the following "exactly" subproblems:
dp[i][j] is the maximum number of goals scored using the first i Geese games and
first j Hawks games, where we force Geese game i to be a rivalry game with
Hawks game j.

This solution ends up being O(n^4), which is too slow!
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

int max(int v1, int v2) {
  if (v1 > v2)
    return v1;
  else
    return v2;
}

int solve(char outcome1[], char outcome2[], int goals1[],
          int goals2[], int n) {
  int i, j, q, r;
  int prior_goals, total_goals, best;
  static int dp[SIZE + 1][SIZE + 1];
  for (i = 0; i <= n; i++)
    dp[0][i] = 0;
  for (i = 0; i <= n; i++)
    dp[i][0] = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      if ((outcome1[i] == 'W' && outcome2[j] == 'L' &&
           goals1[i] > goals2[j]) ||
          (outcome1[i] == 'L' && outcome2[j] == 'W' &&
           goals1[i] < goals2[j])) {
        prior_goals = 0;
        // We have to find the prior rivalry game
        for (q = 0; q < i; q++)
          for (r = 0; r < j; r++)
            prior_goals = max(prior_goals, dp[q][r]);
        total_goals = goals1[i] + goals2[j] + prior_goals;
      }
      else
        total_goals = 0;
      dp[i][j] = total_goals;
    }

  best = 0;
  for (q = 0; q <= n; q++)
    for (r = 0; r <= n; r++)
      best = max(best, dp[q][r]);
  return best;
}

int main(void) {
  int i, n, result;
  char outcome1[SIZE + 1], outcome2[SIZE + 1];
  int goals1[SIZE + 1], goals2[SIZE + 1];
  scanf("%d ", &n);
  for (i = 1; i <= n; i++)
    scanf("%c", &outcome1[i]);
  for (i = 1; i <= n; i++)
    scanf("%d ", &goals1[i]);
  for (i = 1; i <= n; i++)
    scanf("%c", &outcome2[i]);
  for (i = 1; i <= n; i++)
    scanf("%d", &goals2[i]);
  result = solve(outcome1, outcome2, goals1, goals2, n);
  printf("%d\n", result);
  return 0;
}