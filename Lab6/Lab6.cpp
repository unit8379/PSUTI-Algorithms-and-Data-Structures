// Л.Р. 6. Поиск данных в массивах и связных списках
#include <iostream>
#include "student_node.h"
#include "array_sorting_algorithms.h"

using std::cout;
using std::endl;

const int N = 10;

// прототипы для вспомогательных функций
void InsertNode(StudentNode*& node, StudentNode*& nodeToInsert);
void fillSomeNodesOfLinkedList(StudentNode*& node);
// прототипы для функций поиска
int LinearSearchList(StudentNode* startNode, int studentId, StudentNode*& findedNode);
int LinearSearchArray(double*& array, int length, int value);
int BinarySearchArray(double*& array, int length, int value);

int main()
{
    setlocale(LC_ALL, "");

    StudentNode* headNode = new StudentNode; // ведущий узел списка без полезных данных
    headNode->next = NULL;
    headNode->previous = NULL;
    StudentNode* findedNode = NULL;

    // Заполнение двусвязного списка и применение к нему линейного поиска
    fillSomeNodesOfLinkedList(headNode);
    cout << "Изначальный связный список:" << endl << endl;
    Show(headNode);
    cout << endl << "Поиск в списке студента с id = 2." << endl;
    LinearSearchList(headNode, 2, findedNode);
    cout << "В результате линейного поиска был найден следующий узел:" << endl;
    outputStudentStruct(findedNode);
    cout << endl << endl;


    // {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    // {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
    double* array = new double[10]{ 5, 4, 9, 3, 7, 8, 2, 2, 1, 9 };
    cout << "Теперь приступаем к проверке алгоритмов поиска на массиве." << endl;
    cout << "Изначальный массив:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl << endl;

    cout << "Результат работы линейного поиска (искался элемент 7):" << endl;
    cout << LinearSearchArray(array, N, 7);
    cout << endl << endl;

    insertionSort(array, N);
    cout << "Массив был отсортирован вставкой:" << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl << endl;

    cout << "Результат работы двоичного поиска (искался элемент 7):" << endl;
    cout << BinarySearchArray(array, N, 7);
    cout << endl << endl;

    delete[] array;
    return 0;
}

// Линейный поиск в одномерном массиве. Возвращается индекс первого найденного элемента.
// Если нужный элемент не найден, то возвращается -1.
int LinearSearchArray(double*& array, int length, int value)
{
    int index = -1;
    for (int i = 0; i < length; ++i)
    {
        if (array[i] == value)
        {
            return i;
        }
    }
    return index;
}

// Двоичный поиск в отсортированном одномерном массиве. Возвращается индекс подходящего элемента.
// Если нужный элемент не найден, то возвращается -1.
int BinarySearchArray(double*& array, int length, int value)
{
    int left = 0;
    int right = length - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // вычисление середины массива

        if (value == array[mid])
        {
            return mid;
        }
        else if (value < array[mid])
        {
            right = mid - 1; // переход к левому подмассиву
        }
        else
        {
            left = mid + 1; // переход к правому подмассиву
        }
    }
    return -1;
}

// Функция линейного поиска в двусвязном списке. Поиск осуществляется по id студента.
// Возврат студента в ссылочном параметре.
// Если нужный узел не найден, то возвращается 0.
int LinearSearchList(StudentNode* startNode, int studentId, StudentNode*& findedNode)
{
    StudentNode* currentNode = startNode->next;
    int successFlag = 0;

    while (currentNode && !successFlag)
    {
        if (currentNode->id == studentId)
        {
            findedNode = currentNode;
            successFlag = 1;
            break;
        }
        currentNode = currentNode->next;
    }
    return successFlag;
}

// функция для быстрого наполнения списка, чтобы не писать каждый раз в консоли
void fillSomeNodesOfLinkedList(StudentNode*& node)
{
    StudentNode* newNode1 = new StudentNode;
    // поздняя инициализация через (firstName = {'G', 'l', 'e', 'b', '\0'}) в структурах не работает. Выручает функция strcpy
    strcpy_s(newNode1->firstName, "Gleb");
    newNode1->secondName = new char[15]{'E','z','h','o','v', '\0'};
    newNode1->id = 1;
    delete[] newNode1->averageMarks;
    newNode1->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode1->charToYear = 'V';
    InsertNode(node, newNode1);

    StudentNode* newNode2 = new StudentNode;
    strcpy_s(newNode2->firstName, "Ivan");
    newNode2->secondName = new char[15]{ 'I','v','a','n','o', 'v', '\0' };
    newNode2->id = 2;
    delete[] newNode2->averageMarks;
    newNode2->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode2->charToYear = 'A';
    InsertNode(newNode1, newNode2);

    StudentNode* newNode3 = new StudentNode;
    strcpy_s(newNode3->firstName, "Nikolai");
    newNode3->secondName = new char[15]{ 'K','u','l','i','c', 'h', '\0' };
    newNode3->id = 3;
    delete[] newNode3->averageMarks;
    newNode3->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode3->charToYear = 'B';
    InsertNode(newNode2, newNode3);
}

// функция вставки взята из заголовка и немного переделана
void InsertNode(StudentNode*& node, StudentNode*& nodeToInsert)
{
    nodeToInsert->next = node->next;
    nodeToInsert->previous = node;
    node->next = nodeToInsert;
    if (nodeToInsert->next) nodeToInsert->next->previous = nodeToInsert;
}