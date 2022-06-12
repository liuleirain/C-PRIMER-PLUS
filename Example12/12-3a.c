#include <stdio.h>
#include "12-3b.h"

int main(void)
{
  int mode;
  int range;
  double fuels;

  printf("Enter 0 for metric mode, 1 for US mode: ");
  scanf("%d", &mode);
  while (mode >= 0)
  {
    set_mode(&mode);
    get_info(&range, &fuels);
    show_info(&range, &fuels);
    printf("Enter 0 for metric mode, 1 for US mode");
    printf(" (-1 to quit): ");
    scanf("%d", &mode);
  }
  printf("Done.\n");
  return 0;
}