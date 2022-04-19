#include <stdio.h>
void put1(const char * string){
  while(*string != '\0')
    putchar(*string++);
}
int main(void){
  char str[20] = "Hello World";
  put1(str);
  putchar('\n');
  return 0;

}