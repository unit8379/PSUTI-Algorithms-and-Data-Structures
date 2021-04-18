// Л.Р. 5. Сортировка одномерных массивов
#include <iostream>

using std::cout;
using std::endl;

const int N = 10;

void bubbleSort(double*&);
void insertionSort(double*&);

int main()
{
    setlocale(LC_ALL, "");
    // {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    // {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
    double* arrayToSort = new double[10]{ 5, 4, 9, 3, 7, 8, 2, 2, 1, 9 };
    cout << "Изначальный массив:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << arrayToSort[i] << " ";
    }
    cout << endl << endl;

    cout << "Массив отсортированный пузырьком:" << endl;
    bubbleSort(arrayToSort);
    for (int i = 0; i < N; ++i)
    {
        cout << arrayToSort[i] << " ";
    }
    cout << endl << endl;

    delete[] arrayToSort;
    arrayToSort = new double[10]{ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    cout << "Изначальный массив:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << arrayToSort[i] << " ";
    }
    cout << endl << endl;

    cout << "Массив отсортированный вставкой:" << endl;
    insertionSort(arrayToSort);
    for (int i = 0; i < N; ++i)
    {
        cout << arrayToSort[i] << " ";
    }
    cout << endl;
    delete[] arrayToSort;

    return 0;
}

void bubbleSort(double*& array)
{
    for (int i = 0; i < N - 1; ++i) // n - 1 Итераций
    {
        for (int j = 0; j < N - i - 1; ++j) // проход по неотсортированной части, сравнение всех соседних элементов
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

void insertionSort(double*& array)
{
    for (int i = 1; i < N; ++i) // цикл для взятия элемента из неотсортированной части
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