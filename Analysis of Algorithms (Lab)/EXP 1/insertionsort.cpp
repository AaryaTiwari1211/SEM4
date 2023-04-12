#include <iostream>
#include <cstdlib>
using namespace std;
void insertionSort(int arr[], int size)
{
    int key;
    int temp;
    int shiftcount = 0;
    int sum = 0;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            shiftcount = shiftcount + 1;
        }
        cout << "\nThe number of shifts in cycle " << i << " is: " << shiftcount;
        temp = shiftcount;
        sum = sum + temp;
        cout << "\n";
        shiftcount = 0;
        arr[j + 1] = key;
    }
    cout << "\n";
    cout << "Total shifts are -- " << sum;
}
void insertionSortReverse(int arr[], int size)
{
    int key;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "\n";
}
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
        arr[i] = rand() % 69;
    }
    insertionSortReverse(arr,size);
    cout << "\nUnsorted array in Worst Case is:";
    printarr(arr, size);
    insertionSort(arr, size);
    cout << "\n";
    cout << "\nSorted array is:";

    printarr(arr, size);
    return 0;
}