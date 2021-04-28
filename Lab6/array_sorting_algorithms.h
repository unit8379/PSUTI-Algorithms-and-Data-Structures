#pragma once

// ��������� ������� ���������� ���������� ������� �� 5-�� ���. ������.
void bubbleSort(double*&, int);
void insertionSort(double*&, int);

// ���������� "���������"
void bubbleSort(double*& array, int length)
{
    for (int i = 0; i < length - 1; ++i) // n - 1 ��������
    {
        for (int j = 0; j < length - i - 1; ++j) // ������ �� ����������������� �����, ��������� ���� �������� ���������
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

// ���������� "��������"
void insertionSort(double*& array, int length)
{
    for (int i = 1; i < length; ++i) // ���� ��� ������ �������� �� ����������������� �����
    {
        int elem = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > elem) // ���� ��� ���������� ����� ��� ������� � ��������������� �����
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = elem;
    }
}