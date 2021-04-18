// Л.Р. 3. Файлы
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include "student_struct.h"
#include <string>

void writeStudentStructToTextFile(FILE*&, Student&); // функция записи структуры в текстовый файл
void writeStudentStructToBinaryFile(FILE*&, Student&); // функция записи структуры в двоичный файл
void readStudentStructFromTextFile(FILE*&, Student&); // функция считывания структуры из текстового файла
void readStudentStructFromBinaryFile(FILE*&, Student&); // функция считывания структуры из двоичного файла

const int N = 3;
const char *binaryFilePath = "D:\\Development\\VisualStudio\\PSUTI-Algorithms-and-Data-Structures\\Lab3\\binaryFile.bin"; // в папке с проектом
const char *textFilePath = "D:\\Development\\VisualStudio\\PSUTI-Algorithms-and-Data-Structures\\Lab3\\textFile.txt";
FILE* binaryFile = fopen(binaryFilePath, "wb"); // двоичный файл открыт для записи

int main()
{
    // размер структуры 48 байт (находится через sizeof) не всегда соотв. объёмы элементов (разнородные типы выравниваются по памяти)
    setlocale(LC_ALL, ""); // локаль для кириллицы в консоли
    FILE *textFile = fopen(textFilePath, "wt"); // текстовый файл открыт для записи
    Student* studentsForOutput = new Student[N];
    Student* studentsForTextInput = new Student[N];
    Student* studentsForBinaryInput = new Student[N];

    cout << "Введите информацию о трёх студентах:" << endl;
    for (int i = 0; i < N; ++i)
    {
        fillStudentStruct(studentsForOutput[i]);
        cout << endl;
        writeStudentStructToTextFile(textFile, studentsForOutput[i]);
        writeStudentStructToBinaryFile(binaryFile, studentsForOutput[i]);
    }
    fclose(textFile); // закрыл текстовый файл на запись
    fclose(binaryFile); // закрыл двоичный файл на запись
    textFile = fopen(textFilePath, "rt"); // открытие нового потока внутри FILE (теперь уже на чтение)
    binaryFile = fopen(binaryFilePath, "rb");
    
    
    cout << "Структуры студентовы были скопированы в текстовый и двоичный файлы." << endl;
    cout << "Ниже произведён вывод структур, прочитанных из файлов." << endl << endl;

    cout << "Структуры, прочитанные из текстового файла:" << endl;
    for (int i = 0; i < N; ++i)
    {
        readStudentStructFromTextFile(textFile, studentsForTextInput[i]);
        outputStudentStruct(&studentsForTextInput[i]);
        cout << endl;
    }
    fclose(textFile);
    cout << endl;

    cout << "Структуры, прочитанные из двоичного файла:" << endl;
    for (int i = 0; i < N; ++i)
    {
        readStudentStructFromBinaryFile(binaryFile, studentsForBinaryInput[i]);
        outputStudentStruct(&studentsForBinaryInput[i]);
        cout << endl;
    }
    fclose(binaryFile);

    // очистка памяти от структур
    // почему-то здесь крашится. пока что хз почему, но работу основной программы не влияет
    for (int i = 0; i < N; ++i)
    {
        deleteInnerDynamic(studentsForOutput[i]);
        deleteInnerDynamic(studentsForTextInput[i]);
        deleteInnerDynamic(studentsForBinaryInput[i]);
    }
    delete [] studentsForOutput;
    delete [] studentsForTextInput;
    delete [] studentsForBinaryInput;

    return 0;
}

void writeStudentStructToTextFile(FILE*& textFile, Student& student)
{
    if (textFile != NULL)
    {
        fprintf(textFile, "%s %s %lf %c ", student.firstName, student.secondName, student.id, student.charToYear);
        for (double* i = student.averageMarks; i < student.averageMarks + student.numberOfSubjects; ++i)
        {
            fprintf(textFile, "%lf ", *i);  
        }
        fprintf(textFile, "\n");
    }
    else cout << "Не получилось открыть файл" << endl;
}

void readStudentStructFromTextFile(FILE*& textFile, Student& student)
{
    if (textFile != NULL)
    {
        fscanf(textFile, "%s %s %lf %c ", student.firstName, student.secondName, &student.id, &student.charToYear);
        for (int i = 0; i < student.numberOfSubjects; ++i)
        {
            fscanf(textFile, "%lf ", student.averageMarks + i);
        }
        fscanf(textFile, "\n");
    }
    else cout << "Не получилось открыть файл" << endl;
}

void writeStudentStructToBinaryFile(FILE*& binaryFile, Student& student)
{
    if (binaryFile != NULL)
    {
        fwrite(&student, sizeof(struct Student), 1, binaryFile);
    }
    else cout << "Не получилось открыть файл" << endl;
}

void readStudentStructFromBinaryFile(FILE*& binaryFile, Student& student)
{
    if (binaryFile != NULL)
    {
        fread(&student, sizeof(struct Student), 1, binaryFile);
    }
    else cout << "Не получилось открыть файл" << endl;
}