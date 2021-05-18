// Заголовок для работы с Binary Search Tree деревом.
// В качестве полезных данных выступает StudentNode.
#pragma once

struct node
{
	StudentNode* studentData;
	int key; // ключ узла — id студента
	node* left, * right;
};

// ПРОТОТИПЫ ФУНКЦИЙ РАБОТЫ С ДЕРЕВОМ ДВОИЧНОГО ПОИСКА
void AddNode(node*&, node*&, node*&, node&); // вставка нового узла в BST-дерево
void InOrder(node*); // последовательный обход
void PreOrder(node*); // нисходящий обход
void PostOrder(node*); // восходящий обход
void SearchNode(node*, int, node*&); // поиск узла по ключу
void DeleteHelper(node*&, node*&); // функция-помощник для удаления узла
void DeleteNode(node*&, int); // удаление узла по переданному ключу
void DeleteTree(node*&); // удаление дерева, освобождение памяти от всех внутренних полезных данных

/// <summary>
/// Добавление узла-студента в дерево
/// </summary>
/// <param name="tree">Корневой узел</param>
/// <param name="current">Узел с которого будет вестись вставка</param>
/// <param name="prev">Предыдущий от current узел</param>
/// <param name="buf">Узел-буфер, полезные данные которого будут скопированы в новый узел</param>
void AddNode(node*& tree, node*& current, node*& prev, node& buf)
{
	// если текущего узла не существует, то создаём его
	if (current == NULL)
	{
		current = new node;
		current->left = NULL;
		current->right = NULL;
		current->key = buf.key;
		current->studentData = buf.studentData;

		// если текущий узел отличен от корня, то вставляем его в подходящее от previous место
		if (tree != current)
		{
			if (buf.key < prev->key)
				prev->left = current;
			else
				prev->right = current;
		}
		return;
	}

	// рекурсивно спускаемся по дереву, пока не дойдём до пустого current узла
	if (buf.key < current->key)
		AddNode(tree, current->left, current, buf);
	else
		AddNode(tree, current->right, current, buf);
}

/// <summary>
/// Рекурсивная функция обхода дерева последовательно (в порядке возрастания).
/// </summary>
/// <param name="r">Указатель на корень ветви, которую требуется отобразить</param>
void InOrder(node* r)
{
	if (r == NULL) return;
	InOrder(r->left);
	std::cout << r->key << " "; // вывод узла
	InOrder(r->right);
}

// Нисходящий обход дерева (ветви). Происходит спуск от корня к левой ветви, затем к правой.
void PreOrder(node* r)
{
	if (r == NULL) return;
	std::cout << r->key << " "; // вывод узла
	PreOrder(r->left);
	PreOrder(r->right);
}

// Восходящий обход дерева (ветви). Послойный вывод сначала левой ветви, потом правой.
void PostOrder(node* r)
{
	if (!r) return;
	PostOrder(r->left);
	PostOrder(r->right);
	std::cout << r->key << " "; // вывод узла
}

/// <summary>
/// Нерекурсивная функция поиска узла по ключу.
/// </summary>
/// <param name="r">Корень ветви для поиска</param>
/// <param name="keyToFind">Ключ для поиска</param>
/// <param name="findedNode">Указатель на найденный узел. Если не найден будет равен NULL.</param>
void SearchNode(node* r, int keyToFind, node*& findedNode)
{
	while (r != NULL && findedNode == NULL)
	{
		if (r->key == keyToFind)
		{
			findedNode = r;
			return;
		}
		else
		{
			if (keyToFind < r->key)
				r = r->left;
			else
				r = r->right;
		}
	}
}

/// <summary>
/// Вспомогательная функция для DeleteNode()
/// </summary>
/// <param name="r">При вызове тут указатель на левое поддерево от удаляемого узла</param>
/// <param name="nodeToDelete">Узел для удаления</param>
void DeleteHelper(node*& r, node*& nodeToDelete)
{
	// найдено крайний правый узел левого поддерева
	if (r->right == NULL)
	{
		// крайний правый узел копируется на место удаляемого узла
		nodeToDelete->key = r->key;
		nodeToDelete->studentData = r->studentData;
		nodeToDelete = r; // удаляемым узлом становится крайний правый узел, т. к. произошло копирование с заменой
		r = r->left; // на место крайнего правого узла встаёт его левая ветвь
	}
	else
		// рекурсивный поиск крайнего правого узла
		DeleteHelper(r->right, nodeToDelete);
}

/// <summary>
/// Функция удаления узла с поиском по ключу.
/// </summary>
/// <param name="root">Корень, от которого ведётся поиск</param>
/// <param name="key">Искомый ключ</param>
void DeleteNode(node*& root, int key)
{
	node* nodeToDelete;
	if (root == NULL)
		return;
	else
	{
		if (key < root->key)
			DeleteNode(root->left, key);
		else
		{
			if (key > root->key)
				DeleteNode(root->right, key);
			else
			{
				// сюда попадаем, когда root становится равен искомому узлу
				nodeToDelete = root;
				// если правая ветвь отсутствует, то левая ветвь встаёт на место удаляемого узла
				// если и левой ветви не было, то вместо удалённого узла будет просто NULL
				if (nodeToDelete->right == NULL)
					root = nodeToDelete->left;
				// если была правая ветвь, но не было левой, то вместо удаляемого узла встанет правая ветвь
				else
					if (nodeToDelete->left == NULL)
						root = nodeToDelete->right;
					else
						// если у удаляемого узла было две ветви, то вызываем функцию-помощник
						DeleteHelper(nodeToDelete->left, nodeToDelete);
				delete nodeToDelete;
			}
		}
	}
}

// удаление всего дерева, начиная от его корня. используется восходящий обход
void DeleteTree(node*& r)
{
	if (!r) return;
	DeleteTree(r->left);
	DeleteTree(r->right);
	deleteInnerDynamic(*(r->studentData)); // чистка внутренностей структуры
	delete r->studentData; // освобождение памяти от структуры
	delete r; // освобождение памяти от объекта узла
}