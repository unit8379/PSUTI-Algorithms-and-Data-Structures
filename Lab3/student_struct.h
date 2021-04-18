#pragma once

using std::cout;
using std::cin;
using std::endl;

struct Student
{
    char firstName[15];
    char* secondName = new char[15];
    double id;
    const int numberOfSubjects = 6;
    double* averageMarks = new double[numberOfSubjects];
    char charToYear;
};

void fillStudentStruct(Student&); // ���������� ����� ��������� ��������
void fillDecimalArray(double*&, int); // ���������� ������� ����������� �� ������ �� ��� ���������
void outputArray(double*, int); // ����� ��������� ������� � �������
void outputStudentStruct(Student*); // ����� ����������� ��������� ��������
void deleteInnerDynamic(Student&); // ������������ ������ �� ����� ������� ��������� Student

void fillStudentStruct(Student& student)
{
    cout << "������� ��� ��������:" << endl;
    cin >> student.firstName;
    cout << "������� ������� ��������:" << endl;
    cin >> student.secondName;
    cout << "������� id ��������:" << endl;
    cin >> student.id;
    cout << "������� ������ �������� �� ����� ���������:" << endl;
    fillDecimalArray(student.averageMarks, student.numberOfSubjects);
    cout << "������� ����� ������:" << endl;
    cin >> student.charToYear;
}

void outputStudentStruct(Student* student)
{
    cout << "����� ���������� � ��������" << endl;
    cout << (*student).firstName << endl;
    cout << (*student).secondName << endl;
    cout << (*student).id << endl;
    outputArray(student->averageMarks, student->numberOfSubjects);
    cout << (*student).charToYear << endl;
}

void fillDecimalArray(double*& array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cin >> array[i];
    }
}

void outputArray(double* array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void deleteInnerDynamic(Student& student)
{
    delete[] student.averageMarks;
    delete[] student.secondName;
}