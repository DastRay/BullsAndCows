#include <stdio.h>
#include <time.h>
#include <locale.h>

#include "functions.h"

#define SIZE 4 // определение длины числа для игры


int main() 
{  
   setlocale(LC_ALL, "Rus");

   BullsAndCows();
}
