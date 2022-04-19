#include <stdio.h>
#include <string.h>
int main(void)
{
  float downloadSpeed;

  float fileSize;
  float times;
  printf("Please enter the download speed:");
  scanf("%f", &downloadSpeed);
  printf("Please enter the file size:");
  scanf("%f", &fileSize);
  printf("At %.2f megabits per second, a file of %.2f megabytel\n downloads in %.2f seconds.\n", downloadSpeed, fileSize, fileSize / (downloadSpeed / 8));
  return 0;
}