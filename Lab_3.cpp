#include <iostream>

using namespace std;

enum NodeColor
{
    BLACK = 0,
    RED = 1
};

struct Node
{
    Node(int data)
    {
        this->data = data;
    }

    int data;

    NodeColor color; /* node color (BLACK, RED) */

    struct Node *left = NULL;   /* left child */
    struct Node *right = NULL;  /* right child */
    struct Node *parent = NULL; /* parent */
};

//--------------------------------------------------------------------------------------------------------------------------------

NodeColor getColor(Node *node)
{
    if (node == NULL)
        return BLACK;

    return node->color;
}

void setColor(Node *node, NodeColor color)
{
    if (node == NULL)
        return;

    node->color = color;
}

void insertNode(Node *root, Node *ptr)
{
    if (root->data > ptr->data)
    {
        if (root->left == NULL)
        {
            root->left = ptr;
            ptr->parent = root;
        }
        else
        {
            insertNode(root->left, ptr);
        }
    }
    else if (root->data < ptr->data)
    {
        if (root->right == NULL)
        {
            root->right = ptr;
            ptr->parent = root;
        }
        else
        {
            insertNode(root->right, ptr);
        }
    }
}

void rotateLeft(Node *ptr)
{
    Node *right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != NULL)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent != NULL && ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
}

void rotateRight(Node *ptr)
{
    Node *left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != NULL)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent != NULL && ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
}

void fixInsertNode(Node *ptr)
{
    Node *parent = NULL;
    Node *grandparent = NULL;
    while (getColor(ptr) == RED && getColor(ptr->parent) == RED)
    {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left)
        {
            Node *uncle = grandparent->right;
            if (getColor(uncle) == RED)
            {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else
            {
                if (ptr == parent->right)
                {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                ptr = parent;
            }
        }
        else
        {
            Node *uncle = grandparent->left;
            if (getColor(uncle) == RED)
            {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else
            {
                if (ptr == parent->left)
                {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                ptr = parent;
            }
        }
    }
}

int minValueNode(Node *node)
{
    Node *ptr = node;

    while (ptr->left != NULL)
        ptr = ptr->left;

    return ptr->data;
}

int maxValueNode(Node *node)
{
    Node *ptr = node;

    while (ptr->right != NULL)
        ptr = ptr->right;

    return ptr->data;
}

void insertValue(Node *root, int n)
{
    Node *node = new Node(n);
    insertNode(root, node);
    fixInsertNode(node);
}

void predecessor(Node *root, int n)
{
    if (root == NULL)
    {
        cout << "Нету предшественника у ключа: " << n << endl;
        return;
    }

    if (root->data == n)
    {
        cout << "Цвет предшественника: " << (getColor(root->parent) == BLACK ? "Черный" : "Красный") << endl;
        return;
    }

    if (root->data > n)
    {
        predecessor(root->left, n);
    }
    else if (root->data < n)
    {
        predecessor(root->right, n);
    }
}

void Init(short int &N, short int &M, short int &cycleCounter, int &mainNodeData)
{
    while (N <= 1 || N >= 256 || M <= 1 || M >= 256)
    {
        cout << "Сколько значений хотите ввести?" << endl;
        cin >> N;
        cout << "Сколько значений хотите проверить?" << endl;
        cin >> M;
    }

    cout << "Введите значение начального узла:";
    cin >> mainNodeData;
}

int main()
{
    short int N, M, cycleCounter;
    int mainNodeData;

    Init(N, M, cycleCounter, mainNodeData);

    Node *mainNode = new Node(mainNodeData);

    while (cycleCounter < (N - 1))
    {
        int newNodeData;

        cout << "Введите значение узла:";
        cin >> newNodeData;

        insertValue(mainNode, newNodeData);

        cout << "Мин:" << minValueNode(mainNode) << "Макс:" << maxValueNode(mainNode) << endl;

        cycleCounter++;
    }

    cycleCounter = 0;

    while (cycleCounter < M)
    {
        int findNodeData;

        cout << "Найти предшественника узла:";
        cin >> findNodeData;

        predecessor(mainNode, findNodeData);

        cycleCounter++;
    }
}