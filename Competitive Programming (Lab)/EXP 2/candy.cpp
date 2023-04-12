// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void zig_zag(int n, int data)
{
    bool flag = true;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"* ";
        data--;
        if(data==0)
        {
            break;
        }
    }
    cout<<endl;
    while(data>0)
    {
        if(flag==true)
        {
            for(int i=1;i<=n-1;i++)
            {
                cout<<"* ";
                data--;
                if(data==0)
                {
                    break;
                }
            }
            flag = false;
            cout<<"\n";
        }
        else
        {
            cout<<"  ";
            for(int i=1;i<=n-1;i++)
            {
                if(data==0)
                {
                    break;
                }
                cout<<"* ";
                data--;
            }
            flag = true;
            cout<<"\n";
        }
    }
}
void find_index(int n,int search)
{
    if(search<=n)
    {
        cout<<"The last Candy goes in "<<"box "<<search;
    }
    else
    {
        int x = search - n;
        while(x>0)
        {
            for(int j=n-1;j>0;j--)
            {
                x--;
                if(x==0)
                {
                    cout<<"the last candy went in "<<"box "<<j;
                    break;
                }
            }
            if(x==0)
            {
                break;
            }
            for(int i = 2;i<=n;i++)
            {
                x--;
                if(x==0)
                {
                    cout<<"The last candy went in "<<"box "<<i;
                    break;
                }
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter the max size for zig-zag: ";
    cin >> n;
    int find;
    cout<<"Enter the number of candies: ";
    cin>>find;
    zig_zag(n, find);
    find_index(n,find);
    return 0;
}