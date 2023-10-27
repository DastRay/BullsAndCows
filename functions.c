#include "functions.h"
#include<stdio.h>

int Percent(int size_) //вспомогательная функция для заполнения массива по числу которое предлагает игрок
{
   ;
   int perc = 10;
   while (size_ - 1 > 0)
   {
      perc *= 10;
      size_--;
   }
   return perc;
}

