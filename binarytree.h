#pragma once
#include <iostream>

namespace mytree
{
	struct Node
	{
		int mData;
		Node* mpLeft;
		Node* mpRight;

		Node(int data = 0, Node* pLeft = nullptr, Node* pRight = nullptr)
		{
			mData = data;
			mpLeft = pLeft;
			mpRight = pRight;
		}
	};

	class BinaryTree
	{
	private:
		Node* mpRoot;

	public:
		BinaryTree()
		{
			mpRoot = CreateNode(0);
		}

		Node* CreateNode(int value, Node* pLeft = nullptr, Node* pRight = nullptr)
		{
			new Node(value, pLeft, pRight);
		}

		Node* GetRoot() { return mpRoot; }

		Node* InsertLeft(Node* parent, int value)
		{
			parent->mpLeft = CreateNode(value);
			return parent->mpLeft;
		}

		Node* InsertRight(Node* parent, int value)
		{
			parent->mpRight = CreateNode(value);
			return parent->mpRight;
		}
	};
}