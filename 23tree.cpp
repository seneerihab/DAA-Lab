#include <iostream>
using namespace std;

class Node
{
public:
    int data[3];    // max 3 values (temporary)
    Node *child[4]; // max 4 children
    int n;          // number of keys

    Node()
    {
        n = 0;
        for (int i = 0; i < 4; i++)
            child[i] = NULL;
    }
};

class TwoThreeTree
{
public:
    Node *root = NULL;

    // Insert helper
    Node *insert(Node *node, int val, int &upVal, Node *&newChild)
    {
        if (node == NULL)
        {
            node = new Node();
            node->data[0] = val;
            node->n = 1;
            return node;
        }

        // Leaf node
        if (node->child[0] == NULL)
        {
            node->data[node->n++] = val;

            // Sort values
            for (int i = 0; i < node->n - 1; i++)
            {
                for (int j = i + 1; j < node->n; j++)
                {
                    if (node->data[i] > node->data[j])
                        swap(node->data[i], node->data[j]);
                }
            }

            // If no overflow
            if (node->n < 3)
                return node;

            // Split
            Node *newNode = new Node();
            upVal = node->data[1];

            newNode->data[0] = node->data[2];
            newNode->n = 1;

            node->n = 1;

            newChild = newNode;
            return NULL;
        }

        // Internal node
        int i;
        if (val < node->data[0])
            i = 0;
        else if (node->n == 1 || val < node->data[1])
            i = 1;
        else
            i = 2;

        int newUp;
        Node *newChildNode = NULL;

        Node *temp = insert(node->child[i], val, newUp, newChildNode);

        if (temp != NULL)
            node->child[i] = temp;
        else
        {
            // Insert promoted value
            for (int j = node->n; j > i; j--)
            {
                node->data[j] = node->data[j - 1];
                node->child[j + 1] = node->child[j];
            }

            node->data[i] = newUp;
            node->child[i + 1] = newChildNode;
            node->n++;

            // Split if needed
            if (node->n < 3)
                return node;

            Node *newNode = new Node();
            upVal = node->data[1];

            newNode->data[0] = node->data[2];
            newNode->n = 1;

            newNode->child[0] = node->child[2];
            newNode->child[1] = node->child[3];

            node->n = 1;

            newChild = newNode;
            return NULL;
        }

        return node;
    }

    void insert(int val)
    {
        int upVal;
        Node *newChild = NULL;

        Node *temp = insert(root, val, upVal, newChild);

        if (temp == NULL)
        {
            Node *newRoot = new Node();
            newRoot->data[0] = upVal;
            newRoot->n = 1;
            newRoot->child[0] = root;
            newRoot->child[1] = newChild;
            root = newRoot;
        }
        else
        {
            root = temp;
        }
    }

    void display(Node *node)
    {
        if (node != NULL)
        {
            for (int i = 0; i < node->n; i++)
                cout << node->data[i] << " ";
            cout << endl;

            for (int i = 0; i <= node->n; i++)
                display(node->child[i]);
        }
    }
};

int main()
{
    TwoThreeTree tree;

    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        tree.insert(x);
    }

    cout << "\n2-3 Tree:\n";
    tree.display(tree.root);

    return 0;
}