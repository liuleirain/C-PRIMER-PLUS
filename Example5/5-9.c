#include <stdio.h>

float Temperatures(float x);

int main(void)
{
  float fahrenheit;
  printf("Enter a fahrenheit:");
  while (scanf("%f", &fahrenheit) == 1 && fahrenheit != 'q')
  {
    Temperatures(fahrenheit);
    printf("Enter a fahrenheit again:");
  };
  printf("Done.\n");

  return 0;
}

float Temperatures(float x)
{
  const float c_val = 32.0;
  const float v_val = 273.16;
  float open;
  float celsius;
  celsius = 5.0 / 9.0 * (x - c_val);
  open = celsius + 273.16;
  printf("celsius = %.2f, open = %.2f.\n", celsius, open);
  return 0;
}