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

// ��������� ������� ������ �� ���������� �٨ �� 2-�� ���. ������
void fillStudentStruct(StudentNode&); // ���������� ����� ��������� ��������
void fillDecimalArray(double*&, int); // ���������� ������� ����������� �� ������ �� ��� ���������
void outputArray(double*, int); // ����� ��������� ������� � �������
void outputStudentStruct(StudentNode*); // ����� ����������� ��������� ��������
void deleteInnerDynamic(StudentNode&); // ������������ ������ �� ����� ������� ��������� Student

// ������� ������ � ����������� �������

// node - ����, ����� �������� ����������� ����� ����
void Insert1(StudentNode* node)
{
    StudentNode* newNode = new StudentNode;
    fillStudentStruct(*newNode);
    newNode->next = node->next;
    node->next = newNode;
}

void Delete1(StudentNode* node) // node - ����, �������������� ���������� ����
{
    StudentNode* nodeToDelete;
    if (node->next) // null ~ false
    {
        nodeToDelete = node->next;
        node->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}

// ����� ���� ������� � startNode �� ���������� �������. ������� ���������� ���� � ��������� ���������
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
        std::cout << "����� �������� ���� ������: " << tempNode << std::endl;
        outputStudentStruct(tempNode);
        tempNode = tempNode->next;
    }
}

// ������� ������ � ���������� �������

void Insert2(StudentNode* node) // ������� ������ ���� ����� ���� node
{
    StudentNode* newNode = new StudentNode;
    fillStudentStruct(*newNode);
    newNode->next = node->next;
    newNode->previous = node;
    node->next = newNode;
    if (newNode->next) newNode->next->previous = newNode;
}

void Delete2(StudentNode* nodeToDelete) // ��� ��������� ������������ ����
{
    nodeToDelete->previous->next = nodeToDelete->next;
    if (nodeToDelete->next)
    {
        nodeToDelete->next->previous = nodeToDelete->previous;
    }
    delete nodeToDelete;
}

// ������� ���������� ���� � ��������� ����������
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

// ������� ������ � ���������� ��������� �������

void InsertRing(StudentNode* node) // ������� ������ ���� ����� ���� node
{
    StudentNode* newNode = new StudentNode;
    fillStudentStruct(*newNode);
    newNode->next = node->next;
    newNode->previous = node;
    node->next = newNode;
    // �������� �� ������������� ���������� ����� ��� �� ����� �.�. ������ ���������
    newNode->next->previous = newNode;
}

void DeleteRing(StudentNode* nodeToDelete)
{
    nodeToDelete->previous->next = nodeToDelete->next;
    // �������� �� ������������� ���������� ����� �� ���������
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
    }     while (currentNode != startNode && !successFlag);
    return successFlag;
}

void ShowRing(StudentNode* node)
{
    StudentNode* tempNode = node;
    do
    {
        std::cout << "����� �������� ���� ������: " << tempNode << std::endl;
        outputStudentStruct(tempNode);
        tempNode = tempNode->next;
    }     while (tempNode != node);
}

// ���������� ���������� ������� �� ������ �� ����������

void fillStudentStruct(StudentNode& student)
{
    std::cout << "������� ��� ��������:" << std::endl;
    std::cin >> student.firstName;
    std::cout << "������� ������� ��������:" << std::endl;
    std::cin >> student.secondName;
    std::cout << "������� id ��������:" << std::endl;
    std::cin >> student.id;
    std::cout << "������� ������ �������� �� ����� ���������:" << std::endl;
    fillDecimalArray(student.averageMarks, student.numberOfSubjects);
    std::cout << "������� ����� ������:" << std::endl;
    std::cin >> student.charToYear;
}

void outputStudentStruct(StudentNode* student)
{
    std::cout << "����� ���������� � ��������" << std::endl;
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