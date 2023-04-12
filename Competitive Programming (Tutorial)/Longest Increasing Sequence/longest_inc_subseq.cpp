#include <iostream>
#include <algorithm>
using namespace std;

void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int findmax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int lis(int arr[], int size)
{
    int l[size];
    fill_n(l, size, 1);
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && l[i] <= l[j])
            {
                l[i] = l[j] + 1;
            }
        }
    }

    int max = l[0];

    for (int i = 0; i < size; i++)
    {
        if (l[i] > max)
        {
            max = l[i];
        }
    }
    return max;
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "The array is: ";
    printarr(arr, size);
    cout << "The longest increasing subsequence is: ";
    int lis1 = lis(arr, size);
    cout << lis1 << endl;
}