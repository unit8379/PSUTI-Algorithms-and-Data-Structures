// Ћ.–. 4. —в€зные списки
#include <iostream>
#include "student_node.h"

using std::cout;
using std::endl;

int main()
{
	setlocale(LC_ALL, ""); // локаль дл€ кириллицы в консоли
	StudentNode* headNode = new StudentNode; // ведущий узел списка без полезных данных
	headNode->next = NULL;
	StudentNode* findedNode = NULL;

	cout << "–абота с односв€зным списком." << endl;
	Insert1(headNode);
	if (Search1(headNode, 1, findedNode))
	{
		Insert1(findedNode);
	}
	
	cout << endl << "ѕросмотр списка после вставки узлов:" << endl;
	Show(headNode);

	cout << endl << "ѕросмотр списка после удалени€ второго узла:" << endl;
	Delete1(findedNode);
	Show(headNode);

	Delete1(headNode); // ƒо конца освобождаем пам€ть перед работой с двусв€зным списком
	headNode->previous = NULL;

	cout << endl << "–абота с двусв€зным списком" << endl;
	Insert2(headNode);
	if (Search2(headNode, 1, findedNode))
	{
		Insert2(findedNode);
	}
	
	cout << endl << "ѕросмотр двусв€зного списка после вставки узлов" << endl;
	Show(headNode);

	cout << endl << "ѕросмотр двусв€зного списка после удалени€ первого узла:" << endl;
	Delete2(findedNode);
	Show(headNode);

	Search2(headNode, 1, findedNode); // освобождение оставшегос€ узла перед работой с кольцевым списком
	Delete2(findedNode);

	cout << endl << "–абота с кольцевым двусв€зным списком" << endl;
	fillStudentStruct(*headNode); // ведущий узел теперь содержит полезные данные
	headNode->next = headNode;
	headNode->previous = headNode;

	InsertRing(headNode);
	cout << endl << "ѕросмотр двусв€зного кольцевого списка после вставки узла:" << endl;
	ShowRing(headNode);

	cout << endl << "ѕросмотр двусв€зного кольцевого списка после удалени€ первого узла после ведущего:" << endl;
	if (SearchRing(headNode, 1, findedNode))
	{
		DeleteRing(findedNode);
	}
	ShowRing(headNode);

	return 0;
}