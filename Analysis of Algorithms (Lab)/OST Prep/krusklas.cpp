#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct Edge{ /** This structure represents the characteristics of any edge in the tree;        */
    int v1;
    int v2;
    int w;
};

bool compare(Edge A,Edge B) //This function is used in the sorting based of weights of the Edge;
{
    return A.w < B.w;
}

int findParent(int vertex , vector<int> &parent)
{
    if(parent[vertex]==vertex)
    {
        return vertex;
    }
    else
    {
        return findParent(parent[vertex], parent);
    }
}

void unionVertices(int v1,int v2,vector<int> &parent)
{
    int parentV1 = findParent(v1,parent);
    int parentV2 = findParent(v2,parent);

    if(parentV1==parentV2)
    {
        return;
    }
    else
    {
        parent[parentV1] = parentV2;
    }
}

vector<Edge> findMST(vector<Edge> &edges , int vertices)
{
    sort(edges.begin(),edges.end(),compare);
    vector<int> parent(vertices);
    for(int i=0;i<vertices;i++)
    {
        parent[i]=i;
    }
    vector<Edge> MST;
    for(auto edge : edges)
    {
        if(findParent(edge.v1,parent)!=findParent(edge.v2,parent))
        {
            unionVertices(edge.v1,edge.v2,parent);
            MST.push_back(edge);
        }
    }
    return MST;
}

int main()
{
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 7, 8},
        {1, 2, 8},
        {1, 7, 11},
        {2, 3, 7},
        {2, 8, 2},
        {2, 5, 4},
        {3, 4, 9},
        {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1},
        {6, 8, 6},
        {7, 8, 7},
    };

    int numVertices = 9;

    vector<Edge> MST = findMST(edges , numVertices);
    
    for(auto edge : MST)
    {
        cout<<edge.v1<<" -- "<<edge.v2<<" -- "<<" : "<<edge.w << endl;
    }
}
