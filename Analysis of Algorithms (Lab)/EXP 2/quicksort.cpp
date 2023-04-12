// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int count1 = 0;
int count2 = 0;
int count3 = 0;
void swapnumber(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swapnumber(&arr[i], &arr[j]);
            count1++;
        }
    }
    swapnumber(&arr[i + 1], &arr[right]);
    return i + 1;
}
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int x = partition(arr, left, right);
        quickSort(arr, left, x - 1);
        quickSort(arr, x + 1, right);
        count2++;
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
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    print(arr, n);
    cout << endl;
    cout << "Swap runs " << count1 << " times" << endl;
    cout << "QuickSort runs " << count2 << " times" << endl;
    return 0;
}