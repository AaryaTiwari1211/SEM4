// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void printarr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void merge(int arr[], int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int array1[size1];
    int array2[size2];
    for (int i = 0; i < size1; i++)
    {
        array1[i] = arr[left + i];
    }
    for (int j = 0; j < size2; j++)
    {
        array2[j] = arr[mid + 1 + j];
    }
    int a, b, c;
    a = 0;
    b = 0;
    c = left;
    while (a < size1 && b < size2)
    {
        if (array1[a] <= array2[b])
        {
            arr[c] = array1[a];
            a++;
        }
        else
        {
            arr[c] = array2[b];
            b++;
        }
        c++;
    }
    while (a < size1)
    {
        arr[c] = array1[a];
        a++;
        c++;
    }
    while (b < size2)
    {
        arr[c] = array2[b];
        b++;
        c++;
    }
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // int mid = left + (right-left)/2;
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
int main()
{
    int n;
    cout << "Enter total size of the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Unsorted Array is: ";
    printarr(arr, n);
    cout << endl;
    cout << "Sorted Array is: ";
    mergeSort(arr, 0, n - 1);
    printarr(arr, n);
    return 0;
}