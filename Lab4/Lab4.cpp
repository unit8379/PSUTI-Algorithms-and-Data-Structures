// �.�. 4. ������� ������
#include <iostream>
#include "student_node.h"

using std::cout;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // ������ ��� ��������� � �������
	StudentNode* headNode = new StudentNode; // ������� ���� ������ ��� �������� ������
	headNode->next = NULL;
	StudentNode* findedNode = NULL;

	cout << "������ � ����������� �������." << endl;
	Insert1(headNode);
	if (Search1(headNode, 1, findedNode))
	{
		Insert1(findedNode);
	}
	
	cout << endl << "�������� ������ ����� ������� �����:" << endl;
	Show(headNode);

	cout << endl << "�������� ������ ����� �������� ������� ����:" << endl;
	Delete1(findedNode);
	Show(headNode);

	Delete1(headNode); // �� ����� ����������� ������ ����� ������� � ���������� �������
	headNode->previous = NULL;

	cout << endl << "������ � ���������� �������" << endl;
	Insert2(headNode);
	if (Search2(headNode, 1, findedNode))
	{
		Insert2(findedNode);
	}
	
	cout << endl << "�������� ����������� ������ ����� ������� �����" << endl;
	Show(headNode);

	cout << endl << "�������� ����������� ������ ����� �������� ������� ����:" << endl;
	Delete2(findedNode);
	Show(headNode);

	Search2(headNode, 1, findedNode); // ������������ ����������� ���� ����� ������� � ��������� �������
	Delete2(findedNode);

	cout << endl << "������ � ��������� ���������� �������" << endl;
	fillStudentStruct(*headNode); // ������� ���� ������ �������� �������� ������
	headNode->next = headNode;
	headNode->previous = headNode;

	InsertRing(headNode);
	cout << endl << "�������� ����������� ���������� ������ ����� ������� ����:" << endl;
	ShowRing(headNode);

	cout << endl << "�������� ����������� ���������� ������ ����� �������� ������� ���� ����� ��������:" << endl;
	if (SearchRing(headNode, 1, findedNode))
	{
		DeleteRing(findedNode);
	}
	ShowRing(headNode);

	return 0;
}