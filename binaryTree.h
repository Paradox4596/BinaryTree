#pragma once
#ifndef binarytree_h
#define binarytree_h

#include <iostream>
#include <queue>
#include <stack>

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
            return new Node(value, pLeft, pRight);
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

    public:
        void Visit(Node* node) { std::cout << node->mData << " "; }

        void BreadthFirstSearch()
        {
            std::queue<Node*> q;

            q.push(mpRoot);

            while (!q.empty())
            {
                auto node = q.front();
                Visit(node);
                q.pop();

                if (node->mpLeft)
                {
                    q.push(node->mpLeft);
                }
                if (node->mpRight != nullptr)
                {
                    q.push(node->mpRight);
                }
            }
        }

        void DepthFirstSearch()
        {
            std::stack<Node*> s;

            s.push(mpRoot);

            while (!s.empty())
            {
                auto node = s.top();
                Visit(node);
                s.pop();

                if (node->mpRight) s.push(node->mpRight);
                if (node->mpLeft) s.push(node->mpLeft);
            }
        }

        void DFSRecursive(Node* node)
        {
            // base case
            if (!node)
            {
                return;
            }

            Visit(node);

            // recursive case
            DFSRecursive(node->mpLeft);
            DFSRecursive(node->mpRight);
        }

        void PreOrder(Node* node)
        {
            if (!node)
            {
                return;
            }

            Visit(node);
            DFSRecursive(node->mpLeft);
            DFSRecursive(node->mpRight);
        }

        void InOrder(Node* node)
        {
            if (!node)
            {
                return;
            }

            DFSRecursive(node->mpLeft);
            Visit(node);
            DFSRecursive(node->mpRight);
        }

        int Sum(Node* node)
        {
            // base case
            if (node == nullptr)
            {
                return 0;
            }
            return Sum(node->mpLeft) + node->mData + Sum(node->mpRight);
        }

        bool Search(Node* node, int value)
        {
            // base case
            if (!node) return false;

            return node->mData == value ||
                Search(node->mpLeft, value) ||
                Search(node->mpRight, value);
        }
    };
}

#endif
