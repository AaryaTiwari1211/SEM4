#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    cout << "Number of occurrences of each element in the array: " << endl;
    for (auto it = count.begin(); it != count.end(); it++)
    {
        cout << it->first << " : " << it->second <<endl;
        cout << "Multiplication -- "<< it->first * it->second <<endl;
    }

    return 0;
}