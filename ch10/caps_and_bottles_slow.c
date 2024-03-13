#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, cap_num, bottle_num, result;
  scanf("%d", &n);
  for (cap_num = 1; cap_num <= n; cap_num++)
    for (bottle_num = 1; bottle_num <= n; bottle_num++) {
      printf("0 %d %d\n", cap_num, bottle_num);
      scanf("%d", &result);
      if (result == 0) {
        printf("1 %d %d\n", cap_num, bottle_num);
        break;
      }
  }
  return 0;
}
