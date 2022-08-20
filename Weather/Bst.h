#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>

using namespace std;

/**
	 * @class Bst file
	 * @brief  Manages all Bst object
	 *
	 * Bst class contain methods to set and search for the
	 * m_root and node of the BST.
	 *
	 * @author Tan Sheng Ying
	 * @version 01
	 * @date 15/07/2022, Started
	 *
	 * @bug My program currently has no bugs...
	 */

/// Defines a node
template<class T>
struct node
{
    /// Data of the node
    T data;
    /// Left pointer of the node
    node<T> *left;
    /// Right pointer of the node
    node<T> *right;
};

template <class T>
class BST
{
public:

    /**
    * @brief Default Constructor
    *
    * Set m_root to null pointer
    *
    * @param none
    */
    BST();

    /**
    * @brief Default Destructor
    *
    * Delete all the node in the Bst tree
    *
    * @param none
    */
    ~BST();

    /**
    * @brief Function that is used by the destructor
    * to delete all the node of the Bst tree
    *
    * Recursive function that recurse down the tree,
    * until it reach a leaf of the tree, and delete the node of the Bst
    * in a post traversal order.
    *
    * @param A reference to a pointer node
    * @return void
    * @pre Can only be call in the default destructor function
    */
    void ClearNode(node<T> *&p);

    /**
    * @brief Print out the T object
    *
    * @param &item - a reference to an T object
    * @return void
    */
    void Print(T &item);
//    void Insert(const T &item);       //Iterative Approach

    /**
    * @brief To insert a T object into the Bst
    *
    * Create a current and trailCurrent pointer, set to null pointer
    * Create a newnode pointer and set it to T object
    * Insert the newnode to a position of the Bst, if there is
    * no node in the Bst, the newnode will become the m_root.
    *
    * If there is a node in the Bst, it will call the Insert().
    *
    * @param &item
    * @return void
    */
    void ProcessInsert(const T &item);

    /**
    * @brief To insert a T object into the Bst
    *
    * If the m_root is not a nullpointer, it will traverse down to
    * find the next node that is nullpointer.
    *
    * @param *currentNode  - a pointer which point to the current node
    * @param *newNode      - a pointer which point to the T data
    * @param *trailingNode - a pointer which point one node behind of currentNode.
    * @return void
    * @pre Can only be call in the ProcessInsert function
    */
    void Insert(node<T> *c, node<T> *n, node<T> *t);
//    bool Search(const T &item);       //Iterative Approach

    /**
    * @brief To search a T object in the Bst
    *
    * Create a bool isFound
    *
    * This function search the BST for item, and returned whether
    * the item is inside or not inside the BST.
    *
    * @param &item - a reference to an T object
    * @return bool
    */
    bool ProcessSearch(T &item);

    /**
    * @brief To search a T object into the Bst
    *
    * A recursive function that uses InOrderTraversal to search
    * all the node of the Bst, if the T &item is found, isFound = true.
    *
    * @param &item      - A reference to the T item object
    * @param *p         - A pointer that point to the current node
    * @param &isFound   - A bool reference.
    * @return void
    * @pre This function only works when ProcessSearch() is called.
    */
    void Search(T &item, node<T> *p, bool &isFound);

    /**
    * @brief To Traverse the Bst
    *
    * To take a funcPtr and call the different traversal methods
    * of a Bst. The 3 different way to traverse down a tree include,
    * InOrder, PreOrder and PostOrder Traversal.
    *
    * @param *funcPtr - A function pointer to the function that is in the parameter.
    * @return void
    */
    void ProcessNode(void (*funcPtr)(T &item)) const;

    void ProcessReplace(T &item);

    void Replace(T &item, node<T> *p);

private:
    /**
    * @brief To Traverse the Bst using InOrderTraversal
    *
    * @param *p - A pointer that point to the current node
    * @param *funcPtr - A function pointer to the function that is in the parameter.
    * @return void
    * @pre This function only works when ProcessNode() is called.
    */
    void InOrderTraversal(node<T> *p, void (*funcPtr)(T &item)) const;

    /**
    * @brief To Traverse the Bst using PreOrderTraversal
    *
    * @param *p - A pointer that point to the current node
    * @param *funcPtr - A function pointer to the function that is in the parameter.
    * @return void
    * @pre This function only works when ProcessNode() is called.
    */
    void PreOrderTraversal(node<T> *p, void (*funcPtr)(T &item)) const;

    /**
    * @brief To Traverse the Bst using PostOrderTraversal
    *
    * @param *p - A pointer that point to the current node
    * @param *funcPtr - A function pointer to the function that is in the parameter.
    * @return void
    * @pre This function only works when ProcessNode() is called.
    */
    void PostOrderTraversal(node<T> *p, void (*funcPtr)(T &item)) const;

    /**Private variable, A node pointer */
    node<T> *m_root;
};

template<class T>
BST<T>::BST()
{
    m_root = nullptr;
}

template<class T>
BST<T>::~BST()
{
    ClearNode(m_root);
}

template<class T>
void BST<T>::ClearNode(node<T> *&p) //Reference to a pointer
{
    if (p != nullptr)
    {
        ClearNode(p->left);
        ClearNode(p->right);
        delete p;
        p = nullptr;
    }
}

//template<class T>
//void BST<T>::Insert(const T &item)
//{
//    node<T> *current = nullptr;
//    node<T> *trailCurrent = nullptr;
//    node<T> *newNode = nullptr;
//
//    newNode = new node<T>;
//    newNode->data = item;
//    newNode->left = nullptr;
//    newNode->right = nullptr;
//
//    if (m_root == nullptr)
//    {
//        m_root = newNode;
//    }
//    else
//    {
//        current = m_root;
//        while (current != nullptr)
//        {
//            trailCurrent = current;
//            if (item == current->data)
//            {
//                cout << "Duplicates are not allowed" << endl;
//                return;
//            }
//            else
//            {
//                if (item < current->data)
//                {
//                    current = current -> left;
//                }
//                else
//                {
//                    current = current -> right;
//                }
//            }
//        }
//        if (item < trailCurrent->data)
//        {
//            trailCurrent->left = newNode;
//        }
//        else
//        {
//            trailCurrent->right = newNode;
//        }
//
//    }
//}

template<class T>
void BST<T>::ProcessInsert(const T &item)
{
    node<T> *current = nullptr;
    node<T> *trailCurrent = nullptr;
    node<T> *newNode = nullptr;

    newNode = new node<T>;
    newNode->data = item;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (m_root == nullptr)
    {
        m_root = newNode;
    }
    else
    {
        current = m_root;
        Insert(current,newNode,trailCurrent);
    }
}

template<class T>
void BST<T>::Insert(node<T> *c, node<T> *n, node<T> *t)
{
    if (c == nullptr)
    {
        if (n->data < t->data)
        {
            t->left = n;
        }
        else
        {
            t->right = n;
        }
        return;
    }
    if (n->data < c->data)
    {
        t = c;
        c = c->left;
        Insert(c, n, t);
    }
    else
    {
        t = c;
        c = c->right;
        Insert(c,n, t);
    }
}

template <class T>
void BST<T>::ProcessNode(void (*funcPtr)(T &item)) const
{
    cout << "InOrderTraversal" << endl;
    InOrderTraversal(m_root, *funcPtr);
    cout << endl;

    cout << "PreOrderTraversal" << endl;
    PreOrderTraversal(m_root, *funcPtr);
    cout << endl;

    cout << "PostOrderTraversal" << endl;
    PostOrderTraversal(m_root, *funcPtr);;
    cout << endl;
}

template <class T>
void BST<T>::InOrderTraversal(node<T> *p, void (*funcPtr)(T &item)) const
{
    if (p != nullptr)
    {
        InOrderTraversal(p->left, *funcPtr);
        (*funcPtr)(p->data);
        InOrderTraversal(p->right, *funcPtr);
    }
}

template <class T>
void BST<T>::PreOrderTraversal(node<T> *p, void (*funcPtr)(T &item)) const
{
    if (p != nullptr)
    {
        (*funcPtr)(p->data);
        PreOrderTraversal(p->left, *funcPtr);
        PreOrderTraversal(p->right, *funcPtr);
    }
}

template <class T>
void BST<T>::PostOrderTraversal(node<T> *p, void (*funcPtr)(T &item)) const
{
    if (p != nullptr)
    {
        PostOrderTraversal(p->left, *funcPtr);
        PostOrderTraversal(p->right, *funcPtr);
        (*funcPtr)(p->data);
    }
}

// Iterative Search
//template <class T>
//bool BST<T>::Search(const T &item)
//{
//    node<T> *current = nullptr;
//    bool isFound = false;
//
//    current = m_root;
//    while (current != nullptr && isFound != true)
//    {
//        if(current->data == item)
//        {
//            isFound = true;
//        }
//        else if (current ->data > item)
//        {
//            current = current->left;
//        }
//        else if (current ->data < item)
//        {
//            current = current->right;
//        }
//    }
//    return isFound;
//}

//Recursive Search
template <class T>
bool BST<T>::ProcessSearch(T &item)
{
    bool isFound = false;
    Search(item, m_root, isFound);

    return isFound;
}

template<class T>
void BST<T>::Search( T &item, node<T> *p, bool &isFound)
{
    if (p != nullptr)
    {
        Search(item, p->left, isFound);
        if (p->data == item)
        {
            isFound = true;
            item = p->data;
        }
        Search(item, p->right, isFound);
    }
}

template<class T>
void BST<T>::ProcessReplace(T &item)
{
    Replace(item, m_root);
}

template <class T>
void BST<T>::Replace(T &item, node<T> *p)
{
    if(p != nullptr)
    {
        Replace(item, p->left);
        if(p->data == item)
        {
            p->data = item;
        }
        Replace(item, p->right);
    }
}


template <class T>
void Print(T &item)         // why dont need the BST<T>::
{
    cout << item << ", ";
}

#endif // BST_H_INCLUDED
