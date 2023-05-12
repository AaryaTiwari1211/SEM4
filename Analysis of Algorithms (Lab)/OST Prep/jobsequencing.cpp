#include <bits/stdc++.h>
using namespace std;

struct Job
{
    string name;
    int deadline;
    int profit;
};

bool compare(Job A, Job B)
{
    return A.profit > B.profit;
}

vector<Job> sequencing(vector<Job> jobs, int slots)
{
    // Sort jobs in decreasing order of profits
    sort(jobs.begin(), jobs.end(), compare);

    // Initialize all_slots vector and filled array
    vector<Job> all_slots(slots);
    bool filled[slots];
    for (int i = 0; i < slots; i++)
    {
        filled[i] = false;
    }

    // Fill slots with jobs
    for (auto job : jobs)
    {
        for (int j = min(slots, job.deadline) - 1; j >= 0; j--)
        {
            if (filled[j] == false)
            {
                all_slots[j] = job;
                filled[j] = true;
                break;
            }
        }
    }

    // Return the vector of jobs in slots
    return all_slots;
}

int main()
{
    // Initialize the jobs vector
    vector<Job> all_jobs = {
        {"Aarya", 2, 100},
        {"Dhairya", 1, 19},
        {"Rohan", 2, 27},
        {"Dhruv", 1, 25},
        {"Aditya", 3, 15}};

    // Call sequencing function with jobs and number of slots
    vector<Job> all_slots = sequencing(all_jobs, 3);

    // Print the jobs in slots
    for (auto slot : all_slots)
    {
        cout << slot.name << " ";
    }
    
    cout << endl;
    return 0;
}
