#include <iostream>
#include <map>

using namespace std;
void printarr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
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
    map<int, int*> freq;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for(auto i = count.begin();i!=count.end();i++)
    {
        ;
    }
    cout << "Number of occurrences of each element in the array: " << endl;
    for (auto it = count.begin(); it != count.end(); it++)
    {
        cout << it->first << " : " << it->second <<endl;
    }

    return 0;
}