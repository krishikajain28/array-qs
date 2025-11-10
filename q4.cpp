#include <bits/stdc++.h>
using namespace std;

// q. Maximum subarray sum
// kadane 's algo

int maxSubarraySumB1(vector<int> &a)
{
    int n = a.size();
    int m = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int s = 0;
            for (int k = i; k <= j; k++)
            {
                s += a[k];
                m = max(m, s);
            }
        }
    }
    return m;

    // tc: O(n^3)
}

int maxSubarraySumBe(vector<int> &a)
{
    int n = a.size();
    int m = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += a[j];
            m = max(s, m);
        }
    }
    return m;
    // tc: O(n^2)
}

int maxSubarraySumO(vector<int> &a)
{
    // kadane's algo

    int n = a.size();

    int m = INT_MIN;
    int s = 0;

    for (int i = 0; i < n; i++)
    {
        s += a[i];
        if (s < 0)
        {
            s = 0;
        }
        m = max(s, m);
    }

    if (m > 0)
        return m;
    return {};

    // tc: O(n)
    // sc: O(1)
}

vector<int> maxSubarraySumWithArrayO(vector<int> &a)
{
    // kadane's algo
    // now this also returns the subarray

    int n = a.size();

    int m = INT_MIN;
    int s = 0;
    vector<int> sa = {};
    int ansStart = -1;
    int ansEnd = -1;
    int start = -1;

    for (int i = 0; i < n; i++)
    {
        if (s == 0)
        {
            start = i;
        }

        s += a[i];

        if (s < 0)
        {
            s = 0;
        }

        if (s > m)
        {
            m = s;
            ansStart = start;
            ansEnd = i;
        }
    }
    for (int k = ansStart; k <= ansEnd; k++)
    {
        sa.push_back(a[k]);
    }

    return sa;
    // tc: O(n)
    // sc: O(1)
}

int main()
{
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};

    int k = maxSubarraySumO(a);
    cout << "The max sum: " << k;

    vector<int> m = maxSubarraySumWithArrayO(a);

    cout << "\nThe array is: ";
    for (auto i : m)
    {
        cout << i << " ";
    }
}
