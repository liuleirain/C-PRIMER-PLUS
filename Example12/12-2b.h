#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
static bool isMetric = true;
static int km;
static double liters;
static int miles;
static double gallons;

void set_mode(int n)
{
  if (n == 1)
  {
    isMetric = false;
  }
  if (n > 1)
  {
    printf("Invalid mode specified. Mode 1(US) used.\n");
    isMetric = false;
  }
}

void get_info()
{
  if (isMetric)
  {
    printf("Enter distance traveled in kilometers: ");
    scanf("%d", &km);
    printf("Enter fuel consumed in liters: ");
    scanf("%lf", &liters);
  }
  else
  {
    printf("Enter distance traveled in miles: ");
    scanf("%d", &miles);
    printf("Enter fuel consumed in gallons: ");
    scanf("%lf", &gallons);
  }
}

void show_info()
{
  if (isMetric)
  {
    printf("Fuel consumption is %.2lf liters per 100 km.\n", liters / (km / 100));
  }
  else
  {
    printf("Fuel consumption is %.1lf miles per gallon.\n", miles / gallons);
  }
}