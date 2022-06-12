#include <stdio.h>
#include "12-3b.h"
#include <stdbool.h>

static bool isMetric = true;

void set_mode(int *n)
{
  if (*n == 1)
  {
    isMetric = false;
  }
  if (*n > 1)
  {
    printf("Invalid mode specified. Mode 1(US) used.\n");
    isMetric = false;
  }
}

void get_info(int *n, double *m)
{
  if (isMetric)
  {
    printf("Enter distance traveled in kilometers: ");
    scanf("%d", n);
    printf("ENter fuel consumed in liters: ");
    scanf("%lf", m);
  }
  else
  {
    printf("Enter distance traveled in miles: ");
    scanf("%d", n);
    printf("Enter fule consumed in gallons: ");
    scanf("%lf", m);
  }
}

void show_info(int *n, double *m)
{
  if (isMetric)
  {
    printf("Fule consumption is %.2lf liters per 100 km.\n", (*m / (double)*n) * 100);
  }
  else
  {
    printf("Fuel consumption is %.1f miles per gallon.\n", (double)*n / *m);
  }
}