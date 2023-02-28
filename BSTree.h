#ifndef BSTREE
#define BSTREE

#include <iostream>
using std::cout;

template<typename T>
class BSTree
{
public:
    struct BSNode
    {
        T val;
        BSNode *left, *right;
        BSNode(T x) : val(x), left(nullptr), right(nullptr) {}
    };
    
    BSNode* head = nullptr;

    BSNode * search(T x) {
        return _search(head, x);
    }

    void insert(T x)
    {
        head = _insert(head, x);
    }

    void remove(T x)
    {
        head = _remove(head, x);
    }

    void inorder()
    {
        _inorder(head);
    }

private:
    BSNode* _search(BSNode* root,T x)
    {
        if (root == nullptr || root->val == x) return root;
        else if (x > root->val) return _search(root->right, x);
        else return _search(root->left, x);
    }

    BSNode* _insert(BSNode* root, T x)
    {
        if (root == nullptr) 
        {
            root = new BSNode(x);
            return root;
        }
        else if (x == root->val) return root;
        else if (x < root->val) root->left = _insert(root->left, x);
        else root->right = _insert(root->right, x);
        return root;
    }

    BSNode* _remove(BSNode* root, T x)
    {
        if (root == nullptr) return nullptr;
        else if (x < root->val) root->left = _remove(root->left, x);
        else if (x > root->val) root->right = _remove(root->right, x);
        else
        {
            if (root->left == nullptr)
            {
                BSNode *t = root->right;
                delete(root);
                return t;
            }
            else if (root->right == nullptr)
            {
                BSNode *t = root->left;
                delete(root);
                return t;
            }
            else
            {
                BSNode *t = root->right;
                while (t->left != nullptr) t = t->left;
                root->val = t->val;
                root->right = _remove(root->right, t->val);
            }
        }
        return root;
    }
    
    void _inorder(BSNode *root)
    {
        if (root == nullptr) return;
        _inorder(root->left);
        cout << root->val << ' ';
        _inorder(root->right);
    }
};
#endif
