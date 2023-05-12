#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Item {
    string name;
    float profit;
    float weight;
    float ratio = profit/weight;
};

bool compare(Item A , Item B)
{
    return A.ratio > B.ratio;
}

void print(vector<Item> x)
{
    for(auto item: x)
    {
        cout<<item.name<<" was added to the knapsack with weight "<<item.weight<<" and profit "<<item.profit<<endl;
    }
}

vector<Item> knapsack(vector<Item> ratios , int max_weight)
{
    sort(ratios.begin() , ratios.end() , compare);
    vector<Item> Knapsack;
    for(auto item : ratios)
    {
        if(item.weight>max_weight)
        {
            continue;
        }
        else
        {
            Knapsack.push_back(item);
            max_weight = max_weight - item.weight;
        }
    }
    return Knapsack;
}

int main()
{
    vector<Item> All_Items = {
        {"Onion" , 1 , 4},
        {"Tomato" , 2 , 5},
        {"Apple" , 3 , 1},
    };
    vector<Item> final = knapsack(All_Items,9);
    print(final);
}

