// Л.Р. 1. Массивы автоматические, статические, динамические
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int N = 4;

int main()
{
    setlocale(LC_ALL, "");

    double array_double[N] = { 3.14, 45.86, 1.321, 653.27 }; // одномерный массив double
    double* pd; // указатель на double
    static int array_int[N] = { 3, 2, 1, 7 }; // статический одномерный массив int
    int(*p)[2]; // указатель на массив int
    char cube_char[2][2][1] = { { {'A'}, {'B'} }, { {'C'}, {'D'} } }; // трёхмерный массив символов
    char(*pch)[2][1]; // указатель на двумерный массив символов
    
    int size = sizeof(array_double) / sizeof(array_double[0]);
    // вывод содержимого массива типа double
    cout << "Проверка double массива" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << array_double[i] << " ";
    }
    cout << endl;

    // заполнение массива №1 из потока ввода cin
    cout << "Введите элементы double массива:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cin >> array_double[i];
    }
    cout << endl;

    // повторная проверка содержимого массива
    cout << "Вывод элементов double массива" << endl;
    for (double* ptr = array_double; ptr <= &array_double[N - 1]; ++ptr)
    {
        cout << *ptr << " ";
    }
    cout << endl;
    
    // указатель типа double* получает адрес массива типа double
    pd = array_double;
    cout << "Адрес массива: " << array_double << "\tАдрес указателя: " << &pd << endl;
    cout << "Адрес, хранящийся внутри указателя: " << pd << endl << endl;

    // проверка содержимого массива через указатель pd
    cout << "Проверка массива double через указатель" << endl;
    for (; pd <= &array_double[N - 1]; ++pd)
    {
        cout << *pd << " ";
    }
    cout << endl << endl;

    // проверка содержимого статического массива, его заполнение, повторная проверка
    cout << "Проверка статического массива int" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << array_int[i] << " ";
    }
    cout << endl;

    cout << "Введите элементы int массива:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cin >> array_int[i];
    }
    cout << endl;

    cout << "Вывод элементов int массива" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << array_int[i] << " ";
    }
    cout << endl << endl;

    // создание через указатель pd динамического массива double, проверка этого массива
    cout << "Проверка динамического массива double" << endl;
    pd = new double[N] { 5.67, 32.1, 12.567, 4.5 };
    for (double* ptr = pd; ptr <= pd + N - 1; ++ptr)
    {
        cout << *ptr << " ";
    }
    cout << endl;

    cout << "Введите элементы double массива:" << endl;
    for (double* ptr = pd; ptr <= pd + N - 1; ++ptr)
    {
        cin >> *ptr;
    }
    cout << endl;

    cout << "Вывод введённых элементов" << endl;
    for (double* ptr = pd; ptr <= pd + N - 1; ++ptr)
    {
        cout << *ptr << " ";
    }
    cout << endl << endl;
    delete[] pd; // удаление динамического массива double из памяти
    
    // Создание двумерного динамического массива через указатель на одномерный массив int
    cout << "Заполенение и проверка динамического двумерного массива" << endl;
    p = new int[2][2]();

    cout << "Введите int элементы матрицы (4)" << endl;
    int n = 16 / sizeof(p[0]); // кол-во строк (16 / 8 = 2)
    int m = sizeof(p[0]) / sizeof(p[0][0]); // кол-во столбцов (8 / 4 = 2)

    // указатель на последний элемент: адрес самого начала + N - 1;
    int* end = p[0] + n * m - 1;
    for (int* ptr = p[0]; ptr <= end; ++ptr)
    {
        cin >> *ptr;
    }

    cout << "Вывод матрицы" << endl;
    for (int* ptr = p[0], i = 1; ptr <= end; ++ptr, ++i)
    {
        cout << *ptr << "\t";
        // переход на новую строку, если это был последний столбец
        if (i % 2 == 0) cout << endl;
    }

    delete[] p; // удаление динамического двумерного массива int

    // Вывод элемента трёхмерного массива разными способами
    cout << endl << "Вывод одного из элементов трёхмерного массива с помощью индекса: ";
    cout << cube_char[1][0][0] << endl;
    cout << endl << "Вывод одного из элементов трёхмерного массива с помощью разыменовывания адреса: ";
    // достаю указатель на вектор из указателя на двумерный массив, из указателя на вектор достаю указатель типа char*
    // смещаю адрес на 2 объекта типа char (+2 байта), в итоге получаю третий элемент трёхмерного массива ('C')
    cout << *(*(*(cube_char)) + 2) << endl;
    // Присвоение указателю на двумерный массив символов трёхмерного массива символов cube_char
    pch = cube_char;
    cout << endl << "Вывод одного из элементов трёхмерного массива через разыменовывание указателя на двумерный массив char: ";
    cout << *(*(*(pch)) + 2) << endl;

    return 0;
}
