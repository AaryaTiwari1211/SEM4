#include<iostream>
using namespace std;

void countSort(int arr[], int size, int r) {
    int freq[r+1] = {0}; // Initialize frequency array with all zeros
    int outputarr[size];
    for(int i = 0; i < size; i++) {
        freq[arr[i]]++; // Count occurrences of each element in arr
    }
    for(int i = 1; i <= r; i++) {
        freq[i] = freq[i] + freq[i-1]; // Update frequency array to get the actual positions of each element
    }
    for(int i = size-1; i >= 0; i--) { 
        outputarr[freq[arr[i]]-1] = arr[i];
        freq[arr[i]]--;
    }
    for(int i = 0; i < size; i++) {
        arr[i] = outputarr[i]; 
    }
}

int main() {
    int arr[5] = {1, 4, 3, 2, 5};
    countSort(arr, 5, 5); // Call countSort function to sort the array
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " "; // Print the sorted array
    }
    cout << endl;
    return 0;
}


