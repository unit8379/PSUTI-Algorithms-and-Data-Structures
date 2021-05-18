// Л.Р. 7. Двоичные деревья поиска

#include <iostream>
#include "student_node.h"
#include "binary_search_tree.h"

// прототипы вспомогательных функций
void fillBinaryTree(node*&);
void fillDegenerateTree(node*&);
void fillPerfectlyBalancedTree(node*&);
void addNodesToPerfectlyBalancedTree(node*& tree);

int main()
{
    setlocale(LC_ALL, "");
    node* binaryTree = NULL; // корень бинарного дерева
    fillBinaryTree(binaryTree);

    // Обход дерева различными способами
    std::cout << "Двоичное дерево поиска было заполнено 12-ю уникальными узлами." << std::endl << std::endl;
    std::cout << "Обход дерева в восходящем порядке:" << std::endl;
    PostOrder(binaryTree);
    std::cout << std::endl << std::endl;
    std::cout << "Обход дерева в нисходящем порядке:" << std::endl;
    PreOrder(binaryTree);
    std::cout << std::endl << std::endl;
    std::cout << "Обход дерева в последовательном порядке:" << std::endl;
    InOrder(binaryTree);
    std::cout << std::endl << std::endl;

    // Удаление узлов и повторный просмотр
    DeleteNode(binaryTree, 8);
    std::cout << "Из дерева был удалён 8-ой узел." << std::endl;
    std::cout << "Просмотр дерева в нисходящем порядке после удаления:" << std::endl;
    PreOrder(binaryTree);
    std::cout << std::endl << std::endl;
    DeleteNode(binaryTree, 16);
    std::cout << "Из дерева был удалён 16-ый узел." << std::endl;
    std::cout << "Просмотр дерева в нисходящем порядке после удаления:" << std::endl;
    PreOrder(binaryTree);
    std::cout << std::endl << std::endl;

    // Поиск узла по значению ключа
    node* findedNode = NULL;
    std::cout << "Ниже представлен результат поиска узла по значению ключа 4:" << std::endl;
    SearchNode(binaryTree, 4, findedNode);
    outputStudentStruct(findedNode->studentData);
    findedNode = NULL;
    std::cout << std::endl << "Ниже представлен результат попытки нахождения несуществующего узла (ключ 20):" << std::endl;
    SearchNode(binaryTree, 20, findedNode);
    if (!findedNode)
        std::cout << "Такой узел не обнаружен" << std::endl << std::endl;
    else
        outputStudentStruct(findedNode->studentData);

    // Обход вырожденного дерева различными способами
    DeleteTree(binaryTree);
    binaryTree = NULL;
    fillDegenerateTree(binaryTree);
    std::cout << "Было создано вырожденное дерево с 4-мя уникальными узлами." << std::endl << std::endl;
    std::cout << "Обход вырожденного дерева в восходящем порядке:" << std::endl;
    PostOrder(binaryTree);
    std::cout << std::endl << std::endl;
    std::cout << "Обход вырожденного дерева в нисходящем порядке:" << std::endl;
    PreOrder(binaryTree);
    std::cout << std::endl << std::endl;
    std::cout << "Обход вырожденного дерева в последовательном порядке:" << std::endl;
    InOrder(binaryTree);
    std::cout << std::endl << std::endl;

    // Обход идеально сбалансированного дерева различными способами
    DeleteTree(binaryTree);
    binaryTree = NULL;
    fillPerfectlyBalancedTree(binaryTree);
    std::cout << "Было создано идеально сбалансированное дерево с 7-ю уникальными узлами." << std::endl << std::endl;
    std::cout << "Обход сбалансированного дерева в нисходящем порядке:" << std::endl;
    PreOrder(binaryTree);
    std::cout << std::endl << std::endl;
    std::cout << "Обход сбалансированного дерева в последовательном порядке:" << std::endl;
    InOrder(binaryTree);
    std::cout << std::endl << std::endl;
    
    // Добавление узлов в сбалансированное дерево и повторный просмотр
    addNodesToPerfectlyBalancedTree(binaryTree);
    std::cout << "В сбалансированное дерево было добавлено два узла (13 и 9)." << std::endl;
    std::cout << "Просмотр дерева в нисходящем порядке после добавления:" << std::endl;
    PreOrder(binaryTree);
    DeleteTree(binaryTree);
    std::cout << std::endl;
}

// функция для быстрого наполнения бинарного дерева
void fillBinaryTree(node*& tree)
{
    node buf; // буферный узел для вставки

    // 10
    StudentNode* newNode1 = new StudentNode;
    // поздняя инициализация через (firstName = {'G', 'l', 'e', 'b', '\0'}) в структурах не работает. Выручает функция strcpy
    strcpy_s(newNode1->firstName, "Gleb");
    newNode1->secondName = new char[15]{ 'E','z','h','o','v', '\0' };
    newNode1->id = 10;
    delete[] newNode1->averageMarks;
    newNode1->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode1->charToYear = 'V';
    buf.key = 10;
    buf.studentData = newNode1;
    AddNode(tree, tree, tree, buf);

    // 15
    StudentNode* newNode2 = new StudentNode;
    strcpy_s(newNode2->firstName, "Ivan");
    newNode2->secondName = new char[15]{ 'I','v','a','n','o', 'v', '\0' };
    newNode2->id = 15;
    delete[] newNode2->averageMarks;
    newNode2->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode2->charToYear = 'A';
    buf.key = 15;
    buf.studentData = newNode2;
    AddNode(tree, tree, tree, buf);

    // 5
    StudentNode* newNode3 = new StudentNode;
    strcpy_s(newNode3->firstName, "Nikolai");
    newNode3->secondName = new char[15]{ 'K','u','l','i','c', 'h', '\0' };
    newNode3->id = 5;
    delete[] newNode3->averageMarks;
    newNode3->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode3->charToYear = 'B';
    buf.key = 5;
    buf.studentData = newNode3;
    AddNode(tree, tree, tree, buf);

    // 14
    StudentNode* newNode4 = new StudentNode;
    strcpy_s(newNode4->firstName, "Roman");
    newNode4->secondName = new char[15]{ 'Z','a','g','i','t', 'o', 'v', '\0' };
    newNode4->id = 14;
    delete[] newNode4->averageMarks;
    newNode4->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode4->charToYear = 'B';
    buf.key = 14;
    buf.studentData = newNode4;
    AddNode(tree, tree, tree, buf);

    // 16
    StudentNode* newNode5 = new StudentNode;
    strcpy_s(newNode5->firstName, "Silvester");
    newNode5->secondName = new char[15]{ 'O','k','h','o','t', 'a', '\0' };
    newNode5->id = 16;
    delete[] newNode5->averageMarks;
    newNode5->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode5->charToYear = 'B';
    buf.key = 16;
    buf.studentData = newNode5;
    AddNode(tree, tree, tree, buf);

    // 8
    StudentNode* newNode6 = new StudentNode;
    strcpy_s(newNode6->firstName, "Modest");
    newNode6->secondName = new char[15]{ 'L','y','u','b','i', 'm', 'o', 'v', '\0' };
    newNode6->id = 8;
    delete[] newNode6->averageMarks;
    newNode6->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode6->charToYear = 'B';
    buf.key = 8;
    buf.studentData = newNode6;
    AddNode(tree, tree, tree, buf);

    // 9
    StudentNode* newNode7 = new StudentNode;
    strcpy_s(newNode7->firstName, "Aram");
    newNode7->secondName = new char[15]{ 'S','e','m','y','o', 'n', 'o', 'v', '\0' };
    newNode7->id = 9;
    delete[] newNode7->averageMarks;
    newNode7->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode7->charToYear = 'B';
    buf.key = 9;
    buf.studentData = newNode7;
    AddNode(tree, tree, tree, buf);

    // 7
    StudentNode* newNode8 = new StudentNode;
    strcpy_s(newNode8->firstName, "Emelyan");
    newNode8->secondName = new char[15]{ 'S','e','r','g','e', 'e', 'v', '\0' };
    newNode8->id = 7;
    delete[] newNode8->averageMarks;
    newNode8->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode8->charToYear = 'B';
    buf.key = 7;
    buf.studentData = newNode8;
    AddNode(tree, tree, tree, buf);

    // 6
    StudentNode* newNode9 = new StudentNode;
    strcpy_s(newNode9->firstName, "Konon");
    newNode9->secondName = new char[15]{ 'R','y','b','a','k', 'o', 'v', '\0' };
    newNode9->id = 6;
    delete[] newNode9->averageMarks;
    newNode9->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode9->charToYear = 'B';
    buf.key = 6;
    buf.studentData = newNode9;
    AddNode(tree, tree, tree, buf);

    // 3
    StudentNode* newNode10 = new StudentNode;
    strcpy_s(newNode10->firstName, "Aggey");
    newNode10->secondName = new char[15]{ 'P','r','o','k','o', 'f', 'i', 'e', 'v', '\0' };
    newNode10->id = 3;
    delete[] newNode10->averageMarks;
    newNode10->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode10->charToYear = 'B';
    buf.key = 3;
    buf.studentData = newNode10;
    AddNode(tree, tree, tree, buf);

    // 4
    StudentNode* newNode11 = new StudentNode;
    strcpy_s(newNode11->firstName, "Evsey");
    newNode11->secondName = new char[15]{ 'E','m','e','l','i', 'y', 'a', 'n', 'o', 'v', '\0' };
    newNode11->id = 4;
    delete[] newNode11->averageMarks;
    newNode11->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode11->charToYear = 'B';
    buf.key = 4;
    buf.studentData = newNode11;
    AddNode(tree, tree, tree, buf);

    // 2
    StudentNode* newNode12 = new StudentNode;
    strcpy_s(newNode12->firstName, "Oktyabrina");
    newNode12->secondName = new char[15]{ 'K','a','m','e','n', 's', 'k', 'a', 'y', 'a', '\0' };
    newNode12->id = 2;
    delete[] newNode12->averageMarks;
    newNode12->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode12->charToYear = 'B';
    buf.key = 2;
    buf.studentData = newNode12;
    AddNode(tree, tree, tree, buf);
}

// функция для быстрого заполнения вырожденного дерева
void fillDegenerateTree(node*& tree)
{
    node buf; // буферный узел для вставки

    // 10
    StudentNode* newNode1 = new StudentNode;
    strcpy_s(newNode1->firstName, "Gleb");
    newNode1->secondName = new char[15]{ 'E','z','h','o','v', '\0' };
    newNode1->id = 10;
    delete[] newNode1->averageMarks;
    newNode1->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode1->charToYear = 'V';
    buf.key = 10;
    buf.studentData = newNode1;
    AddNode(tree, tree, tree, buf);

    // 9
    StudentNode* newNode2 = new StudentNode;
    strcpy_s(newNode2->firstName, "Ivan");
    newNode2->secondName = new char[15]{ 'I','v','a','n','o', 'v', '\0' };
    newNode2->id = 9;
    delete[] newNode2->averageMarks;
    newNode2->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode2->charToYear = 'A';
    buf.key = 9;
    buf.studentData = newNode2;
    AddNode(tree, tree, tree, buf);

    // 8
    StudentNode* newNode3 = new StudentNode;
    strcpy_s(newNode3->firstName, "Nikolai");
    newNode3->secondName = new char[15]{ 'K','u','l','i','c', 'h', '\0' };
    newNode3->id = 8;
    delete[] newNode3->averageMarks;
    newNode3->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode3->charToYear = 'B';
    buf.key = 8;
    buf.studentData = newNode3;
    AddNode(tree, tree, tree, buf);

    // 7
    StudentNode* newNode4 = new StudentNode;
    strcpy_s(newNode4->firstName, "Roman");
    newNode4->secondName = new char[15]{ 'Z','a','g','i','t', 'o', 'v', '\0' };
    newNode4->id = 7;
    delete[] newNode4->averageMarks;
    newNode4->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode4->charToYear = 'B';
    buf.key = 7;
    buf.studentData = newNode4;
    AddNode(tree, tree, tree, buf);
}

// функция для быстрого заполнения идеально сбалансированного дерева
void fillPerfectlyBalancedTree(node*& tree)
{
    node buf; // буферный узел для вставки

    // 10
    StudentNode* newNode1 = new StudentNode;
    // поздняя инициализация через (firstName = {'G', 'l', 'e', 'b', '\0'}) в структурах не работает. Выручает функция strcpy
    strcpy_s(newNode1->firstName, "Gleb");
    newNode1->secondName = new char[15]{ 'E','z','h','o','v', '\0' };
    newNode1->id = 10;
    delete[] newNode1->averageMarks;
    newNode1->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode1->charToYear = 'V';
    buf.key = 10;
    buf.studentData = newNode1;
    AddNode(tree, tree, tree, buf);

    // 15
    StudentNode* newNode2 = new StudentNode;
    strcpy_s(newNode2->firstName, "Ivan");
    newNode2->secondName = new char[15]{ 'I','v','a','n','o', 'v', '\0' };
    newNode2->id = 15;
    delete[] newNode2->averageMarks;
    newNode2->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode2->charToYear = 'A';
    buf.key = 15;
    buf.studentData = newNode2;
    AddNode(tree, tree, tree, buf);

    // 5
    StudentNode* newNode3 = new StudentNode;
    strcpy_s(newNode3->firstName, "Nikolai");
    newNode3->secondName = new char[15]{ 'K','u','l','i','c', 'h', '\0' };
    newNode3->id = 5;
    delete[] newNode3->averageMarks;
    newNode3->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode3->charToYear = 'B';
    buf.key = 5;
    buf.studentData = newNode3;
    AddNode(tree, tree, tree, buf);

    // 14
    StudentNode* newNode4 = new StudentNode;
    strcpy_s(newNode4->firstName, "Roman");
    newNode4->secondName = new char[15]{ 'Z','a','g','i','t', 'o', 'v', '\0' };
    newNode4->id = 14;
    delete[] newNode4->averageMarks;
    newNode4->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode4->charToYear = 'B';
    buf.key = 14;
    buf.studentData = newNode4;
    AddNode(tree, tree, tree, buf);

    // 16
    StudentNode* newNode5 = new StudentNode;
    strcpy_s(newNode5->firstName, "Silvester");
    newNode5->secondName = new char[15]{ 'O','k','h','o','t', 'a', '\0' };
    newNode5->id = 16;
    delete[] newNode5->averageMarks;
    newNode5->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode5->charToYear = 'B';
    buf.key = 16;
    buf.studentData = newNode5;
    AddNode(tree, tree, tree, buf);

    // 8
    StudentNode* newNode6 = new StudentNode;
    strcpy_s(newNode6->firstName, "Modest");
    newNode6->secondName = new char[15]{ 'L','y','u','b','i', 'm', 'o', 'v', '\0' };
    newNode6->id = 8;
    delete[] newNode6->averageMarks;
    newNode6->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode6->charToYear = 'B';
    buf.key = 8;
    buf.studentData = newNode6;
    AddNode(tree, tree, tree, buf);

    // 3
    StudentNode* newNode10 = new StudentNode;
    strcpy_s(newNode10->firstName, "Aggey");
    newNode10->secondName = new char[15]{ 'P','r','o','k','o', 'f', 'i', 'e', 'v', '\0' };
    newNode10->id = 3;
    delete[] newNode10->averageMarks;
    newNode10->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode10->charToYear = 'B';
    buf.key = 3;
    buf.studentData = newNode10;
    AddNode(tree, tree, tree, buf);
}

// функция для добавления в сбалансированное дерево двух дополнительных узлов
void addNodesToPerfectlyBalancedTree(node*& tree)
{
    node buf; // буферный узел для вставки

    // 13
    StudentNode* newNode1 = new StudentNode;
    // поздняя инициализация через (firstName = {'G', 'l', 'e', 'b', '\0'}) в структурах не работает. Выручает функция strcpy
    strcpy_s(newNode1->firstName, "Lyubomila");
    newNode1->secondName = new char[15]{ 'Y','a','k','o','v', 'l', 'e', 'v', 'a', '\0' };
    newNode1->id = 13;
    delete[] newNode1->averageMarks;
    newNode1->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode1->charToYear = 'V';
    buf.key = 13;
    buf.studentData = newNode1;
    AddNode(tree, tree, tree, buf);

    // 9
    StudentNode* newNode7 = new StudentNode;
    strcpy_s(newNode7->firstName, "Aram");
    newNode7->secondName = new char[15]{ 'S','e','m','y','o', 'n', 'o', 'v', '\0' };
    newNode7->id = 9;
    delete[] newNode7->averageMarks;
    newNode7->averageMarks = new double[] {5, 5, 5, 5, 5, 5};
    newNode7->charToYear = 'B';
    buf.key = 9;
    buf.studentData = newNode7;
    AddNode(tree, tree, tree, buf);
}