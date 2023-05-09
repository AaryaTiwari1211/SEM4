#include <bits/stdc++.h>
using namespace std;

void find_index(int n, int search)
{
    if (search <= n)
    {
        cout << "The last Candy goes in " << search << "th box";
    }
    else
    {
        int x = search - n;
        while (x > 0)
        {
            for (int j = n - 1; j > 0; j--)
            {
                x--;
                if (x == 0)
                {
                    cout << "the last candy went in " << j << "th box!!";
                    break;
                }
            }
            if (x == 0)
            {
                break;
            }
            for (int i = 2; i <= n; i++)
            {
                x--;
                if (x == 0)
                {
                    cout << "The last candy went in " << i << "th box";
                    break;
                }
            }
        }
    }
}

int main()
{
    int candies, box;
    cout << "Enter number of candies and boxes: ";
    cin >> candies >> box;
    find_index(box,candies);
    cout<<endl;
    for (int i = 1; i <= box; i++)
    {
        cout << " * ";
        candies--;
        if (candies == 0)
        {
            break;
        }
    }
    cout << endl;
    int i = 2;
    while (candies > 0)
    {
        if (i % 2 == 0)
        {
            for (int j = 1; j <= box - 1; j++)
            {
                cout << " * ";
                candies--;
                if (candies == 0)
                {
                    break;
                }
            }
            i++;
            cout << endl;
        }
        else
        {
            cout << "   ";
            for (int k = 2; k <= box; k++)
            {
                cout << " * ";
                candies--;
                if (candies == 0)
                {
                    break;
                }
            }
            i++;
            cout << endl;
        }
    }
}