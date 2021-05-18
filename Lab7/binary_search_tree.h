// ��������� ��� ������ � Binary Search Tree �������.
// � �������� �������� ������ ��������� StudentNode.
#pragma once

struct node
{
	StudentNode* studentData;
	int key; // ���� ���� � id ��������
	node* left, * right;
};

// ��������� ������� ������ � ������� ��������� ������
void AddNode(node*&, node*&, node*&, node&); // ������� ������ ���� � BST-������
void InOrder(node*); // ���������������� �����
void PreOrder(node*); // ���������� �����
void PostOrder(node*); // ���������� �����
void SearchNode(node*, int, node*&); // ����� ���� �� �����
void DeleteHelper(node*&, node*&); // �������-�������� ��� �������� ����
void DeleteNode(node*&, int); // �������� ���� �� ����������� �����
void DeleteTree(node*&); // �������� ������, ������������ ������ �� ���� ���������� �������� ������

/// <summary>
/// ���������� ����-�������� � ������
/// </summary>
/// <param name="tree">�������� ����</param>
/// <param name="current">���� � �������� ����� ������� �������</param>
/// <param name="prev">���������� �� current ����</param>
/// <param name="buf">����-�����, �������� ������ �������� ����� ����������� � ����� ����</param>
void AddNode(node*& tree, node*& current, node*& prev, node& buf)
{
	// ���� �������� ���� �� ����������, �� ������ ���
	if (current == NULL)
	{
		current = new node;
		current->left = NULL;
		current->right = NULL;
		current->key = buf.key;
		current->studentData = buf.studentData;

		// ���� ������� ���� ������� �� �����, �� ��������� ��� � ���������� �� previous �����
		if (tree != current)
		{
			if (buf.key < prev->key)
				prev->left = current;
			else
				prev->right = current;
		}
		return;
	}

	// ���������� ���������� �� ������, ���� �� ����� �� ������� current ����
	if (buf.key < current->key)
		AddNode(tree, current->left, current, buf);
	else
		AddNode(tree, current->right, current, buf);
}

/// <summary>
/// ����������� ������� ������ ������ ��������������� (� ������� �����������).
/// </summary>
/// <param name="r">��������� �� ������ �����, ������� ��������� ����������</param>
void InOrder(node* r)
{
	if (r == NULL) return;
	InOrder(r->left);
	std::cout << r->key << " "; // ����� ����
	InOrder(r->right);
}

// ���������� ����� ������ (�����). ���������� ����� �� ����� � ����� �����, ����� � ������.
void PreOrder(node* r)
{
	if (r == NULL) return;
	std::cout << r->key << " "; // ����� ����
	PreOrder(r->left);
	PreOrder(r->right);
}

// ���������� ����� ������ (�����). ��������� ����� ������� ����� �����, ����� ������.
void PostOrder(node* r)
{
	if (!r) return;
	PostOrder(r->left);
	PostOrder(r->right);
	std::cout << r->key << " "; // ����� ����
}

/// <summary>
/// ������������� ������� ������ ���� �� �����.
/// </summary>
/// <param name="r">������ ����� ��� ������</param>
/// <param name="keyToFind">���� ��� ������</param>
/// <param name="findedNode">��������� �� ��������� ����. ���� �� ������ ����� ����� NULL.</param>
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
/// ��������������� ������� ��� DeleteNode()
/// </summary>
/// <param name="r">��� ������ ��� ��������� �� ����� ��������� �� ���������� ����</param>
/// <param name="nodeToDelete">���� ��� ��������</param>
void DeleteHelper(node*& r, node*& nodeToDelete)
{
	// ������� ������� ������ ���� ������ ���������
	if (r->right == NULL)
	{
		// ������� ������ ���� ���������� �� ����� ���������� ����
		nodeToDelete->key = r->key;
		nodeToDelete->studentData = r->studentData;
		nodeToDelete = r; // ��������� ����� ���������� ������� ������ ����, �. �. ��������� ����������� � �������
		r = r->left; // �� ����� �������� ������� ���� ����� ��� ����� �����
	}
	else
		// ����������� ����� �������� ������� ����
		DeleteHelper(r->right, nodeToDelete);
}

/// <summary>
/// ������� �������� ���� � ������� �� �����.
/// </summary>
/// <param name="root">������, �� �������� ������ �����</param>
/// <param name="key">������� ����</param>
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
				// ���� ��������, ����� root ���������� ����� �������� ����
				nodeToDelete = root;
				// ���� ������ ����� �����������, �� ����� ����� ����� �� ����� ���������� ����
				// ���� � ����� ����� �� ����, �� ������ ��������� ���� ����� ������ NULL
				if (nodeToDelete->right == NULL)
					root = nodeToDelete->left;
				// ���� ���� ������ �����, �� �� ���� �����, �� ������ ���������� ���� ������� ������ �����
				else
					if (nodeToDelete->left == NULL)
						root = nodeToDelete->right;
					else
						// ���� � ���������� ���� ���� ��� �����, �� �������� �������-��������
						DeleteHelper(nodeToDelete->left, nodeToDelete);
				delete nodeToDelete;
			}
		}
	}
}

// �������� ����� ������, ������� �� ��� �����. ������������ ���������� �����
void DeleteTree(node*& r)
{
	if (!r) return;
	DeleteTree(r->left);
	DeleteTree(r->right);
	deleteInnerDynamic(*(r->studentData)); // ������ ������������� ���������
	delete r->studentData; // ������������ ������ �� ���������
	delete r; // ������������ ������ �� ������� ����
}