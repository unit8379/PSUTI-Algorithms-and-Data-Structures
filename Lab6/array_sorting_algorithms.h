#pragma once

// Прототипы функций алгоритмов сортировки массива из 5-ой лаб. работы.
void bubbleSort(double*&, int);
void insertionSort(double*&, int);

// Сортировка "Пузырьком"
void bubbleSort(double*& array, int length)
{
    for (int i = 0; i < length - 1; ++i) // n - 1 Итераций
    {
        for (int j = 0; j < length - i - 1; ++j) // проход по неотсортированной части, сравнение всех соседних элементов
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Сортировка "Вставкой"
void insertionSort(double*& array, int length)
{
    for (int i = 1; i < length; ++i) // цикл для взятия элемента из неотсортированной части
    {
        int elem = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > elem) // цикл для нахождения места для вставки в отсортированной части
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = elem;
    }
}