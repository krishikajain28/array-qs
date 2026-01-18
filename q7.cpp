#include <bits/stdc++.h>
using namespace std;

// Brute Force Placeholder
int nextPermutationB(vector<int> &a) // Changed int& to vector<int>&
{
    int n = a.size();
    return n;
}

// Better Approach Placeholder
int nextPermutationBe(vector<int> &a) // Changed int& to vector<int>&
{
    // cpp stl
    int n = a.size();
    return n;
}

// Optimal Approach (Working logic)
int nextPermutationO(int k)
{
    // 1. Convert int to vector
    vector<int> a;
    string s = to_string(k); // Easier conversion
    for (char c : s)
    {
        a.push_back(c - '0');
    }

    int n = a.size();
    int ind = -1;

    // 2. Find the break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            ind = i;
            break;
        }
    }

    // 3. If break point exists, swap with next greater element
    if (ind != -1)
    {
        for (int i = n - 1; i > ind; i--)
        {
            if (a[i] > a[ind])
            {
                swap(a[i], a[ind]);
                break;
            }
        }
    }

    // 4. Reverse the right half
    reverse(a.begin() + ind + 1, a.end());
ff
    // 5. Convert vector back to int
    int ans = 0;
    for (int i : a)
    {
        ans = ans * 10 + i;
    }

    return ans;
}

int main()
{
    int a = 321;

    // Using the Optimal function that takes an int
    int m = nextPermutationO(a);

    cout << "The ans : " << m;

    return 0;
}
