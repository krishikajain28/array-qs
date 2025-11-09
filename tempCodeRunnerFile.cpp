#include <bits/stdc++.h>
using namespace std;

// q3: find the element w > n/2 frequency
// majority element

int findMajorityB(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                c++;
        }
        if (c > n / 2)
            return a[i];
    }
    return -1;
}

int findMajorityBe(vector<int> &a)
{
    // hashing and storing the counts of OBV
    int n = a.size();

    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++)
    {
        umap[a[i]]++;
    }

    for (auto i : umap)
    {
        if (i.second > n / 2)
        {
            return i.first;
        }
    }
    return -1;

    // How it works:
    // You create a hashmap (unordered_map) to count occurrences of each number.
    // You iterate through the map to check if any number occurs more than n/2 times.
    // If yes, you return that number; otherwise, return -1.
    // For your array {4, 5, 3, 5, 3, 5, 3, 5, 5, 5, 3}, the size n = 11.
    // Majority element must appear more than 11/2 = 5 times.
    // Number 5 appears 6 times → it is returned correctly.

    // tc: O(2n)for unordered, O(n^2) if hashing collisions appear
    // tc: O(n) + O(n logn) for ordered map

    // sc: O(n)
}

// Moore voting algorithm for the optimal

int findMajorityO(vector<int> &a)

{
    int n = a.size();
    int cnt = 0;
    int el;

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            el = a[i];
        }
        else if (a[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    if (cnt > 0)
        return el;
    else
        return -1;
}

int main()
{
    vector<int> a = {7, 0, 0, 1, 7, 7, 2, 7, 7};

    int m = findMajorityO(a);

    cout << "The ans : " << m;
}
