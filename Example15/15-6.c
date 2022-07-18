#include <stdio.h>
#include <string.h>

struct word {
  unsigned int font : 8;
  unsigned int size : 7;
  unsigned int alignment : 2;
  unsigned int bold : 1;
  unsigned int italic : 1;
  unsigned int underline : 1;
};

const char* align[3] = { "left", "center", "right" };
const char* open[2] = { "off", "on" };

void print(struct word*);
char get_choice();
void eatline();


int main(void) {
  struct word type = { 1, 12, 0, 0, 0 };
  char choice;
  int num;
  char ch;

  print(&type);
  while ((choice = get_choice()) != 'q') {
    switch (choice) {
    case 'a':
      puts("Select alignment:");
      puts("l)left  c)center  r)right");
      while ((ch = getchar()) == '\0' || strchr("lcr", ch) == NULL) {
        eatline();
        puts("Invalid value, please enter again.");
      }
      eatline();
      switch (ch) {
      case 'l':
        type.alignment = 0;
        break;
      case 'c':
        type.alignment = 1;
        break;
      case 'r':
        type.alignment = 2;
        break;
      }
      break;
    case 's':
      printf("Enter font size (0-127):");
      while (scanf("%u", &num) != 1 || (num < 0 || num > 127))
      {
        eatline();
        puts("Invalid value, please enter again.");
      }
      eatline();
      type.size = num;
      break;
    case 'f':
      puts("Enter font ID (0-256):");
      while (scanf("%u", &num) != 1 || (num < 0 || num > 256)) {
        eatline();
        puts("Invalid value, please enter again.");
      }
      eatline();
      type.font = num;
      break;
    case 'b':
      type.bold = !type.bold;
      break;
    case 'i':
      type.italic = !type.italic;
      break;
    case 'u':
      type.underline = !type.underline;
      break;
    }

    print(&type);
  }
  printf("Bye.\n");
  return 0;
}

char get_choice() {
  char ch;
  puts("f)change font   s)change size   a)change alignment");
  puts("b)toggle hold   i)toggle italic u)toggle underline");
  puts("q)quit");
  ch = getchar();
  while (strchr("fsabiuq", ch) == NULL) {
    eatline();
    puts("Invalid value, please enter again");
    ch = getchar();
  }
  eatline();
  return ch;
}

void eatline() {
  while (getchar() != '\n') continue;
}

void print(struct word* pst) {
  printf(" ID SIZE ALIGENMENT    B    I    U\n");
  printf("%3u", pst->font);
  printf("%5u", pst->size);
  printf("%10s", align[pst->alignment]);
  printf("%7s", open[pst->bold]);
  printf("%5s", open[pst->italic]);
  printf("%5s\n\n", open[pst->underline]);
}