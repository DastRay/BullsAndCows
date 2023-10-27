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

/*
* void ReverseArray(int arr[], int size) // функиця разворачивающая массив
{
   int start = 0;
   int end = size - 1;

   while (start < end) {
      // Обмен значениями элементов массива
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;

      // Переход к следующим элементам
      start++;
      end--;
   }
}
*/
