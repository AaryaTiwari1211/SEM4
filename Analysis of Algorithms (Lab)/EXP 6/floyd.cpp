#include <iostream>
using namespace std;
#define size 7

void printMatrix(int matrix[][size]);

void floydWarshall(int graph[][size])
{
    int matrix[size][size], i, j, k;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            matrix[i][j] = graph[i][j];
    for (k = 0; k < size; k++)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    printMatrix(matrix);
}

void printMatrix(int matrix[][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<< matrix[i][j]<<" ";
        }
        cout<<endl;
        printf("\n");
    }
}

int main()
{
    int graph[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Enter the weight of the edge between " << i+1 << " and " << j+1 << ": ";
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph);
}