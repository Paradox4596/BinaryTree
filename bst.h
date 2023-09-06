#pragma once

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

    class BinarySearchTree

    {
    private:
        Node* mpRoot;

    public:
        BinarySearchTree()
        {
            mpRoot = CreateNode(0);
        }

        Node* CreateNode(int value, Node* pLeft = nullptr, Node* pRight = nullptr)
        {
            return new Node(value, pLeft, pRight);
        }

        Node* GetRoot() { return mpRoot; }

        Node* Insert(node* parent, int data)
        {
            // rules
        }
    };
}