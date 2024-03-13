#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_N 10000

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int random_value(int left, int width) {
  return (rand() % width) + left;
}

void solve(int cap_nums[], int bottle_nums[], int left, int right) {
  int border, cap_index, cap_num, i, result, matching_bottle;
  if (right < left)
    return;

  border = left;
  cap_index = random_value(left, right - left + 1);
  cap_num = cap_nums[cap_index];

  i = left;
  while (i < right) {
    printf("0 %d %d\n", cap_num, bottle_nums[i]);
    scanf("%d", &result);
    if (result == 0) {
      swap(&bottle_nums[i], &bottle_nums[right]);
    } else if (result == 1) {
      swap(&bottle_nums[border], &bottle_nums[i]);
      border++;
      i++;
    } else {
      i++;
    }
  }

  matching_bottle = bottle_nums[right];
  printf("1 %d %d\n", cap_num, matching_bottle);

  border = left;

  i = left;
  while (i < right) {
    printf("0 %d %d\n", cap_nums[i], matching_bottle);
    scanf("%d", &result);
    if (result == 0) {
      swap(&cap_nums[i], &cap_nums[right]);
    } else if (result == -1) {
      swap(&cap_nums[border], &cap_nums[i]);
      border++;
      i++;
    } else {
      i++;
    }
  }

  solve(cap_nums, bottle_nums, left, border - 1);
  solve(cap_nums, bottle_nums, border, right - 1);
}

int main(void) {
  int n, i;
  int cap_nums[MAX_N], bottle_nums[MAX_N];
  srand((unsigned) time(NULL));
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    cap_nums[i] = i + 1;
    bottle_nums[i] = i + 1;
  }
  solve(cap_nums, bottle_nums, 0, n - 1);
  return 0;
}
