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

void fillStudentStruct(Student&); // заполнение полей структуры студента
void fillDecimalArray(double*&, int); // заполнение массива переданного по ссылке на его указатель
void outputArray(double*, int); // вывод элементов массива в консоль
void outputStudentStruct(Student*); // вывод заполненной структуры студента
void deleteInnerDynamic(Student&); // освобождение памяти от полей объекта структуры Student

void fillStudentStruct(Student& student)
{
    cout << "Введите имя студента:" << endl;
    cin >> student.firstName;
    cout << "Введите фамилию студента:" << endl;
    cin >> student.secondName;
    cout << "Введите id студента:" << endl;
    cin >> student.id;
    cout << "Введите оценки студента по шести предметам:" << endl;
    fillDecimalArray(student.averageMarks, student.numberOfSubjects);
    cout << "Введите букву класса:" << endl;
    cin >> student.charToYear;
}

void outputStudentStruct(Student* student)
{
    cout << "Вывод информации о студенте" << endl;
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