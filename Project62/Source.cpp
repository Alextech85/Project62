#include<iostream>
using namespace std;

struct Node
{
	int key;
	Node* parent{ nullptr };
	Node* left{ nullptr };
	Node* right{ nullptr };
};


class BinaryTree
{
	Node* root;

public:
	BinaryTree() :root{ nullptr } {}

	void Print()
	{
		Print(root);
	}

	void Print(Node* current)
	{
		if (current)
		{
			Print(current->left);
			cout << current->key << " ";
			Print(current->right);
		}

	}


	void Add(int value)
	{
		Node* newnode = new Node;
		newnode->key = value;
		Node* newparent{ nullptr };
		Node* current{ root };

		while (current)
		{
			newparent = current;
			if (newnode->key < current->key)
				current = current->left;
			else
				current = current->right;
		}

		newnode->parent = newparent;

		if (!newparent)
			root = newnode;
		else
		{

			if (newnode->key < newparent->key)
				newparent->left = newnode;
			else
				newparent->right = newnode;
		}

	}
	Node* Search(int value)
	{
		Node* current{ root };
		while (current && current->key != value)
		{
			if (value > current->key)
			{
				return current;
				current = current->right;
			}
			else
				current = current->left;
		}
		return current;
	}

	Node* Max()
	{
		return Min(root);
	}

	Node* Max(Node* current)
	{
		while (current->right)
			current = current->right;
		return current;
	}

	Node* Min()
	{
		return Min(root);
	}

	Node* Min(Node* current)
	{
		while (current->left)
			current = current->left;
		return current;
	}

	Node* Next(Node* current)
	{
		if (current->right)
			return Min(current->right);

		Node* tempnode(current->parent);
		while (tempnode && tempnode->right == current)
		{
			current = tempnode;
			tempnode = tempnode->parent;
		}

		return tempnode;
	}

	Node* Prev(Node* current)
	{
		if (current->left)
			return Max(current->left);

		Node* tempnode{current->parent};
		while (tempnode && tempnode->left == current)
		{
			current = tempnode;
			tempnode = tempnode->parent;
		}
		
		return tempnode;
	}
};


int main()
{
	BinaryTree bintree;
	bintree.Add(45);
	bintree.Add(10);
	bintree.Add(15);
	bintree.Add(2);
	bintree.Add(20);
	bintree.Add(50);
	bintree.Add(60);

	bintree.Print();

	Node* p;
	if (p = bintree.Search(10))

		cout << "found " << p->key << " ";
	else
		cout << "not found\n";

	bintree.Print(p);

	cout << "\n";

	cout << "min = " << binTree.Min()->key << " max= " << binTree.Max()->key << "\n";

	cout << binTree.Prev(binTree.Searche(45))->key;

	return 0;
}