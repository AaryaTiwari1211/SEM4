#include <iostream>
using namespace std;

#define MAX_TREE_HT 50

struct node
{
    int frequency;
    char data;
    struct node *l, *r;
};

struct tree
{
    int size;
    int capacity;
    struct node **array;
};

struct node *newNode(char data, int frequency)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->l = temp->r = NULL;
    temp->data = data;
    temp->frequency = frequency;

    return temp;
}
struct tree *createtree(int capacity)
{
    struct tree *treeeap = (struct tree *)malloc(sizeof(struct tree));
    treeeap->size = 0;
    treeeap->capacity = capacity;
    treeeap->array = (struct node **)malloc(treeeap->capacity * sizeof(struct node *));
    return treeeap;
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i];

    cout << "\n";
}

void swap(struct node **a, struct node **b)
{
    struct node *t = *a;
    *a = *b;
    *b = t;
}

void treeeapify(struct tree *treeeap, int idx)
{
    int smallest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    if (l < treeeap->size && treeeap->array[l]->frequency < treeeap->array[smallest]->frequency)
        smallest = l;

    if (r < treeeap->size && treeeap->array[r]->frequency < treeeap->array[smallest]->frequency)
        smallest = r;

    if (smallest != idx)
    {
        swap(&treeeap->array[smallest], &treeeap->array[idx]);
        treeeapify(treeeap, smallest);
    }
}
int checkSizeOne(struct tree *treeeap)
{
    return (treeeap->size == 1);
}

struct node *extractMin(struct tree *treeeap)
{
    struct node *temp = treeeap->array[0];
    treeeap->array[0] = treeeap->array[treeeap->size - 1];

    --treeeap->size;
    treeeapify(treeeap, 0);

    return temp;
}

void inserttreeeap(struct tree *treeeap, struct node *treeeapNode)
{
    ++treeeap->size;
    int i = treeeap->size - 1;

    while (i && treeeapNode->frequency < treeeap->array[(i - 1) / 2]->frequency)
    {
        treeeap->array[i] = treeeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    treeeap->array[i] = treeeapNode;
}

void buildtreeeap(struct tree *treeeap)
{
    int n = treeeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        treeeapify(treeeap, i);
}

int isLeaf(struct node *root)
{
    return !(root->l) && !(root->r);
}

struct tree *createAndBuildtreeeap(char data[], int frequency[], int size)
{
    struct tree *treeeap = createtree(size);

    for (int i = 0; i < size; ++i)
        treeeap->array[i] = newNode(data[i], frequency[i]);

    treeeap->size = size;
    buildtreeeap(treeeap);

    return treeeap;
}

struct node *buildHfTree(char data[], int frequency[], int size)
{
    struct node *l, *r, *top;
    struct tree *treeeap = createAndBuildtreeeap(data, frequency, size);

    while (!checkSizeOne(treeeap))
    {
        l = extractMin(treeeap);
        r = extractMin(treeeap);

        top = newNode('$', l->frequency + r->frequency);

        top->l = l;
        top->r = r;

        inserttreeeap(treeeap, top);
    }
    return extractMin(treeeap);
}

void printHCodes(struct node *root, int arr[], int top)
{
    if (root->l)
    {
        arr[top] = 0;
        printHCodes(root->l, arr, top + 1);
    }

    if (root->r)
    {
        arr[top] = 1;
        printHCodes(root->r, arr, top + 1);
    }
    if (isLeaf(root))
    {
        cout << root->data << "  | ";
        printArray(arr, top);
    }
}

void HuffmanCodes(char data[], int frequency[], int size)
{
    struct node *root = buildHfTree(data, frequency, size);
    int arr[MAX_TREE_HT], top = 0;
    printHCodes(root, arr, top);
}

int main()
{
    char arr[] = {'A', 'B', 'C', 'D'};
    int frequency[] = {5, 1, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Char | Huffman code ";
    cout << "\n----------------------\n";
    HuffmanCodes(arr, frequency, size);
}