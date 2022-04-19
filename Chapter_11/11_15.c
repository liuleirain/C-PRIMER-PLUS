#include <stdio.h>
int put2(const char * string){
  int count = 0;
  while(*string){
    putchar(*string++);
    count++;
  }
  putchar('\n');

  return (count);
}
int main(void){
  char str[20] = "I'm fine!";
  put2(str);
  return 0;
}