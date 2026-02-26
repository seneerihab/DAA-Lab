#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

struct cmp
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

Node *newNode(char ch, int freq)
{
    Node *temp = new Node();
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

void printCodes(Node *root, string str)
{
    if (!root)
        return;

    if (root->ch != '$')
        cout << root->ch << ": " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void huffman(char data[], int freq[], int n)
{
    priority_queue<Node *, vector<Node *>, cmp> pq;

    for (int i = 0; i < n; i++)
        pq.push(newNode(data[i], freq[i]));

    while (pq.size() > 1)
    {
        Node *l = pq.top();
        pq.pop();
        Node *r = pq.top();
        pq.pop();

        Node *top = newNode('$', l->freq + r->freq);
        top->left = l;
        top->right = r;

        pq.push(top);
    }

    printCodes(pq.top(), "");
}

int main()
{
    char data[] = {'X', 'Y', 'Z', 'W'};
    int freq[] = {7, 3, 11, 5};
    int n = 4;

    huffman(data, freq, n);
    return 0;
}