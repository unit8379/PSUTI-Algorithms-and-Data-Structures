#pragma once

struct StudentNode
{
    StudentNode* next;
    StudentNode* previous;

    char firstName[15];
    char* secondName = new char[15];
    double id;
    const int numberOfSubjects = 6;
    double* averageMarks = new double[numberOfSubjects];
    char charToYear;
};

// ПРОТОТИПЫ ФУНКЦИЙ РАБОТЫ СО СТРУКТУРОЙ ЕЩЁ СО 2-ой Лаб. работы
void fillStudentStruct(StudentNode&); // заполнение полей структуры студента
void fillDecimalArray(double*&, int); // заполнение массива переданного по ссылке на его указатель
void outputArray(double*, int); // вывод элементов массива в консоль
void outputStudentStruct(StudentNode*); // вывод заполненной структуры студента
void deleteInnerDynamic(StudentNode&); // освобождение памяти от полей объекта структуры Student

// ФУНКЦИИ РАБОТЫ С ОДНОСВЯЗНЫМ СПИСКОМ

// node - узел, после которого вставляется новый узел
void Insert1(StudentNode* node)
{
    StudentNode* newNode = new StudentNode;
    fillStudentStruct(*newNode);
    newNode->next = node->next;
    node->next = newNode;
}

void Delete1(StudentNode* node) // node - узел, предшествующий удаляемому узлу
{
    StudentNode* nodeToDelete;
    if (node->next) // null ~ false
    {
        nodeToDelete = node->next;
        node->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}

// поиск узла начиная с startNode до указанного индекса. Возврат найденного узла в ссылочном параметре
int Search1(StudentNode* startNode, int index, StudentNode*& findedNode)
{
    StudentNode* current = startNode;
    findedNode = startNode;
    int successFlag = 0;
    int iterator = 0;

    while (current && !successFlag)
    {
        if (iterator == index)
        {
            successFlag = 1;
        }
        iterator++;
        findedNode = current;
        current = current->next;
    }

    return successFlag;
}

void Show(StudentNode* node)
{
    StudentNode* tempNode = node->next;
    while (tempNode) // null ~ false
    {
        std::cout << "Адрес текущего узла списка: " << tempNode << std::endl;
        outputStudentStruct(tempNode);
        tempNode = tempNode->next;
    }
}

// ФУНКЦИИ РАБОТЫ С ДВУСВЯЗНЫМ СПИСКОМ

void Insert2(StudentNode* node) // вставка нового узла после узла node
{
    StudentNode* newNode = new StudentNode;
    fillStudentStruct(*newNode);
    newNode->next = node->next;
    newNode->previous = node;
    node->next = newNode;
    if (newNode->next) newNode->next->previous = newNode;
}

void Delete2(StudentNode* nodeToDelete) // тут удаляется передаваемый узел
{
    nodeToDelete->previous->next = nodeToDelete->next;
    if (nodeToDelete->next)
    {
        nodeToDelete->next->previous = nodeToDelete->previous;
    }
    delete nodeToDelete;
}

// Возврат найденного узла в ссылочном параметере
int Search2(StudentNode* startNode, int index, StudentNode*& findedNode)
{
    StudentNode* currentNode = startNode;
    int successFlag = 0;
    int iterator = 0;

    while (currentNode && !successFlag)
    {
        if (iterator == index)
        {
            findedNode = currentNode;
            successFlag = 1;
            break;
        }
        iterator++;
        currentNode = currentNode->next;
    }
    return successFlag;
}

// ФУНКЦИИ РАБОТЫ С ДВУСВЯЗНЫМ КОЛЬЦЕВЫМ СПИСКОМ

void InsertRing(StudentNode* node) // вставка нового узла после узла node
{
    StudentNode* newNode = new StudentNode;
    fillStudentStruct(*newNode);
    newNode->next = node->next;
    newNode->previous = node;
    node->next = newNode;
    // проверка на существование следующего звена уже не нужна т.к. список кольцевой
    newNode->next->previous = newNode;
}

void DeleteRing(StudentNode* nodeToDelete)
{
    nodeToDelete->previous->next = nodeToDelete->next;
    // проверка на существование следующего звена не требуется
    nodeToDelete->next->previous = nodeToDelete->previous;
    delete nodeToDelete;
}

int SearchRing(StudentNode* startNode, int index, StudentNode*& findedNode)
{
    StudentNode* currentNode = startNode;
    int successFlag = 0;
    int iterator = 0;

    do
    {
        if (iterator == index)
        {
            findedNode = currentNode;
            successFlag = 1;
        }
        currentNode = currentNode->next;
        iterator++;
    }
    while (currentNode != startNode && !successFlag);
    return successFlag;
}

void ShowRing(StudentNode* node)
{
    StudentNode* tempNode = node;
    do
    {
        std::cout << "Адрес текущего узла списка: " << tempNode << std::endl;
        outputStudentStruct(tempNode);
        tempNode = tempNode->next;
    }
    while (tempNode != node);
}

// РЕАЛИЗАЦИЯ ПРОТОТИПОВ ФУНКЦИЙ ПО РАБОТЕ СО СТРУКТУРОЙ

void fillStudentStruct(StudentNode& student)
{
    std::cout << "Введите имя студента:" << std::endl;
    std::cin >> student.firstName;
    std::cout << "Введите фамилию студента:" << std::endl;
    std::cin >> student.secondName;
    std::cout << "Введите id студента:" << std::endl;
    std::cin >> student.id;
    std::cout << "Введите оценки студента по шести предметам:" << std::endl;
    fillDecimalArray(student.averageMarks, student.numberOfSubjects);
    std::cout << "Введите букву класса:" << std::endl;
    std::cin >> student.charToYear;
}

void outputStudentStruct(StudentNode* student)
{
    std::cout << "Вывод информации о студенте" << std::endl;
    std::cout << (*student).firstName << std::endl;
    std::cout << (*student).secondName << std::endl;
    std::cout << (*student).id << std::endl;
    outputArray(student->averageMarks, student->numberOfSubjects);
    std::cout << (*student).charToYear << std::endl;
}

void fillDecimalArray(double*& array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cin >> array[i];
    }
}

void outputArray(double* array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void deleteInnerDynamic(StudentNode& student)
{
    delete[] student.averageMarks;
    delete[] student.secondName;
}