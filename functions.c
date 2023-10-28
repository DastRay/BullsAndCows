﻿#include "functions.h"

#include<stdio.h>
#include <time.h>

#define SIZE 4 // определение длины числа для игры

int Percent(int size_)
{
   int perc = 10;
   while (size_ - 2 > 0)
   {
      perc *= 10;
      size_--;
   }
   return perc;
}

void BullsAndCows()
{
   int num_hidden[SIZE]; // загаданное число 
   int attemp = 0;       // число, которое будет предлагать игрок как возможный ответ
   int num_attemp[SIZE]; // число, которое будет предлагать игрок как возможный ответ, но уже в массиве
   int bulls = 0;        // количество <быков>
   int cows = 0;         // количество <коров>
   int count_attemts = 0;// количество предпринятых попыток

   srand(time(NULL)); //инициализируется генератор псевдослучайных случайных чисел
   int randnum = Percent(SIZE) + rand() % (9 * Percent(SIZE)); // генерация числа длиной SIZE
   //printf("%d\n", randnum); //отладочная команда, вывод сгенерированного числа 
   for (int i = SIZE - 1; i >= 0; i--)
   {
      num_hidden[i] = randnum % 10;
      randnum /= 10;
   }

   printf("Добро пожаловать! Это игра \"Быки и коровы\" \nОзнакомьтесь с правилами игры: Быки и коровы — логическая игра,\nв\
ходе которой за несколько попыток один игрок должен определить,\nкакое число загадал \
другой игрок. После каждой попытки задумавший игрок выставляет «оценку», \nуказывая количество угаданного \
без совпадения с их позициями (количество «коров») и \nполных совпадений (количество «быков»). \
В нашем случае в роли игрока, который загадывает число выступает комьютер, \nпопробуйте отгадать его \
число за наименьшее число попыток. Удачи!\nВ нашей игре число имеет длину: %d", SIZE);
   printf("\n__________________________________________________________________________________________________________________\n");

   while (bulls < 4)
   {
      bulls = 0;
      cows = 0;
      count_attemts++;

      printf("Попытка номер %d\n", count_attemts);
      printf("Введите число: ");

      scanf_s("%d", &attemp); // считывание числа, которое предлагает игрок как верный ответ
      if (attemp < Percent(SIZE) || attemp > Percent(SIZE) * 10 - 1)
      {
         printf("Пожалуйста, введите %d значное число\n", SIZE);
         printf("--------------------------\n");
         count_attemts--;
         continue;
      }
      printf("--------------------------\n");

      for (int i = SIZE - 1; i >= 0; i--)
      {
         num_attemp[i] = attemp % 10;
         attemp /= 10;
      }

      for (int i = 0; i < SIZE; i++) // проверка чисел игрока и компьютера
      {
         if (num_hidden[i] == num_attemp[i]) // если число и позиция совпадают, то bulls увеличивается на единицу
         {
            bulls++;
         }
         else
         {     /*
              если числа на одинаковых позициях не равны то выполняется else: проверяются одинаковые числа, но уже на разных позициях
              если такие числа есть, то cows увеличивается на единицу при каждом совпадении, иначе не изменяется.
              если не использовать else, а просто запустить цикл в цикле то возможен неправильный подсчёт, т.к. в cows будут
              записываться и найденные bulls
              */
            for (int n = 0; n < SIZE; n++)
            {
               if (num_hidden[i] == num_attemp[n]) // если число и позиция не совпадают, то cows увеличивается на единицу
                  cows++;
            }
         }
      }
      printf("Быки: %d\n", bulls);  //общее число <быков>
      printf("Коровы: %d\n", cows); //общее число <коров>
   }

   printf("Поздравляю! Вы угадали число\n");
   printf("Загаданное число: ");
   int a = 0;
   while (a < SIZE)
   {
      printf("%d", num_hidden[a]);
      a++;
   }
   printf("\nЧисло попыток: %d", count_attemts);
}
