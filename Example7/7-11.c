#include <stdio.h>
#include <ctype.h>

int main(void)
{
  const double PRICE_ARTICHOKES = 2.05;
  const double PRICE_BEETS = 1.15;
  const double PRICE_CARROTS = 1.09;
  const double DISCOUNT_RATE = 0.05;
  const double UNDER5 = 6.50;
  const double UNCER20 = 14.00;
  const double BASE20 = 14.00;
  const double EXTRALB = 0.50;

  double pounds;
  double pounds_artichokes;
  double pounds_beets;
  double pounds_carrots;
  double artichokes_price;
  double beets_price;
  double carrots_price;
  double vegetable_price;
  double order_fee;
  double discount;
  double freight;
  double total_price;

  char ch;

  while (1)
  {
    printf("Please select a vegetable input pounds:\n");
    printf("a) Artichokes pounds\t\tb) Beets pounds\n");
    printf("c) Carrots pounds\t\tq) quit\n");
    while ((ch = tolower(getchar())) != 'q')
    {
      if (isspace(ch))
      {
        continue;
      }
      while (getchar() != '\n')
        continue;
      printf("Please enter a pounds.\n");
      scanf("%lf", &pounds);
      switch (ch)
      {
      case 'a':
        pounds_artichokes += pounds;
        break;
      case 'b':
        pounds_beets += pounds;
        break;
      case 'c':
        pounds_carrots += pounds;
        break;
      default:
        printf("Please enter the right choice:\n");
        break;
      }
    }
    if (ch == 'q')
    {
      break;
    }
  }
  artichokes_price = pounds_artichokes * PRICE_ARTICHOKES;
  beets_price = pounds_beets * PRICE_BEETS;
  carrots_price = pounds_carrots * PRICE_CARROTS;
  order_fee = artichokes_price + beets_price + carrots_price;
  pounds = pounds_artichokes + pounds_beets + pounds_carrots;
  vegetable_price = artichokes_price + beets_price;
  if (order_fee >= 100)
  {
    discount = order_fee * 0.05;
  }
  if (pounds <= 5)
  {
    freight = 6.5;
  }
  else if (pounds <= 20)
  {
    freight = 14;
  }
  else
  {
    freight = 14 + (pounds - 20) * 0.5;
  }
  printf("artichokes = %.2lf, beets = %.2lf, carrots = %.2lf\n", PRICE_ARTICHOKES, PRICE_BEETS, PRICE_CARROTS);
  printf("Pounds total: %.2lf\n", pounds);
  printf("Order total: %.2lf\n", order_fee);
  printf("Vegetable total: %.2lf\n", vegetable_price);
  printf("Order pounds: %.2lf\n", pounds);
  printf("Freight: %.2lf\n", freight);

  return 0;
}
