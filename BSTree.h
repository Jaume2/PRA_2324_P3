#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T>
class BSTree
{
private:
    int nelem;
    BSNode<T> *root;
    BSNode<T> *search(BSNode<T> *n, T e) const
    {
        if (n == nullptr)
        {
            throw runtime_error("Elemento no encontrado");
        }
        else if (n->elem < e)
        {
            search(n->right, e);
        }
        else if (n->elem > e)
        {
            search(n->left, e);
        }
        else
        {
            return n;
        }
    }
    BSNode<T> *insert(BSNode<T> *n, T e)
    {
        if (n == nullptr)
        {
            return new BSNode(e);
        }
        else if (n->elem = 0)
        {
            throw runtime_error("Elemento no encontrado");
        }
        else if (n->elem < e)
        {
            return insert(n->right, e);
        }
        else
        {
            return insert(n->left, e);
        }
    }
    void print_inorder(ostream &out, BSNode<T> *n) const
    {
        if (n == nullptr)
        {
            return;
        }
        print_inorder(out, n->left);
        out << n->elem << " ";
        print_inorder(out, n->right);
    }
    BSNode<T> *remove(BSNode<T> *n, T e)
    {
        if (n == nullptr)
        {
            throw runtime_error("Elemento no encontrado");
        }
        else if (n->elem < e)
        {
            return remove(n->right, e);
        }
        else if (n->elem > e)
        {
            return remove(n->left, e);
        }
        else
        {
            if (n->left != nullptr && n->right != nullptr)
            {
                n->elem = max(n->left);
                n->left = remove_max(n->left);
            }
            else
            {
                n = (n->left != nullptr) ? n->left : n->right;
            }
        }
        return n;
    }
    T max(BSNode<T> *n) const
    {
        if (n == nullptr)
        {
            throw runtime_error("Elemento no encontrado");
        }
        else if (n->right != nullptr)
        {
            return max(n->right);
        }
        else
        {
            return n->elem;
        }
    }
    BSNode<T> *remove_max(BSNode<T> *n)
    {
        if (n->right == nullptr)
        {
            return n->left;
        }
        else
        {
            n->right = remove_max(n->right);
            return n;
        }
    }
    void delete_cascade(BSNode<T> *n)
    {
        delete n;
    }

public:
    BSTree()
    {
        BSNode raiz = new BSNode(0, nullptr, nullptr);
        nelem = 1;
    }
    int size() const
    {
        return nelem;
    }
    T search(T e) const
    {
        if (root->elem == 0)
        {
            return search(root, e).elem;
        }
    }
    friend ostream &operator<<(ostream &out, const BSTree<T> &bst)
    {
        print_inorder(out, bst->root);
        return out;
    }
    void remove(T e)
    {
        root = remove(root, e);
    }
    ~BSTree()
    {
        delete_cascade(root);
    }
};
#endif