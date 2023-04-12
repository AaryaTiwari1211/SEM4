#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the size: ";
    int size;
    cin >> size;
    int arr[size];
    int num[size];
    cout << "Enter the numbers: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        num[i] = arr[i] % 10;
    }
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += num[i];
    }
    cout<<"Sum is: "<<sum<<endl;
    cout <<endl<< "Divisible by 10: ";
    if (sum % 10 == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}