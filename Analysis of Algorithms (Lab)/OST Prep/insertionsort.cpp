#include<iostream>
using namespace std;

void insertionSort(int arr[] , int size)
{
    for(int i = 1;i<size;i++)
    {
        int j = i;
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main()
{
    int arr[5] = {1,4,3,2,5};
    insertionSort(arr,5);
    for(int i = 0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}
// #include <iostream>
// using namespace std;

// void insertionSort(int arr[], int n) {
//     for (int i = 1; i < n; i++) {
//         int j = i;
//         while (j > 0 && arr[j-1] > arr[j]) {
//             swap(arr[j], arr[j-1]);
//             j--;
//         }
//     }
// }

// int main() {
//     int arr[] = {5, 2, 9, 1, 5, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);
    
//     cout << "Original array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
    
//     insertionSort(arr, n);
    
//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
    
//     return 0;
// }
