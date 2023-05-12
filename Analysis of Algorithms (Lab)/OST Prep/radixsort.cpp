#include <iostream>
using namespace std;

void countSort(int arr[], int size, int digit)
{
    int outputarr[size], freq[10] = {0};

    // Count the frequency of digits
    for (int i = 0; i < size; i++)
    {
        freq[(arr[i] / digit) % 10]++;
    }

    // Update the frequency array to get the actual positions
    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i - 1];
    }

    // Place each element in its correct position in the output array
    for (int i = size - 1; i >= 0; i--)
    {
        outputarr[freq[(arr[i] / digit) % 10] - 1] = arr[i];
        freq[(arr[i] / digit) % 10]--;
    }

    // Copy the sorted elements back to the input array
    for (int i = 0; i < size; i++)
    {
        arr[i] = outputarr[i];
    }
}

void radixSort(int arr[], int size)
{
    int max = arr[0];

    // Find the maximum element in the array
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Sort the array based on each digit
    for (int digit = 1; max / digit > 0; digit *= 10)
    {
        countSort(arr, size, digit);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
