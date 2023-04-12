#include<cstdlib>
#include <iostream>
using namespace std;
void maxheap(int arr[], int size, int root)
{
    int max = root;
    int left = (2 * root) + 1;
    int right = (2 * root) + 2;

    if (size > left && arr[max] < arr[left])
    {
        max = left;
    }
    if (size > right && arr[max] < arr[right])
    {
        max = right;
    }
    if (max != root)
    {
        swap(arr[root], arr[max]);
        maxheap(arr, size, max);
    }
}
void heapsort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        maxheap(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxheap(arr, i, 0);
    }
}

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    cout<<"Unsorted Array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    heapsort(arr, size);
    cout<<"Sorted Array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}