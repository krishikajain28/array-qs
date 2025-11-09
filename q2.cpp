#include <bits/stdc++.h>
using namespace std;

// q2: sortArrayof0sand1sand2s
// simpleproblem
// there s an array of 0s 1s and 2s
//  vector<int> a = {1, 2, 1, 2, 0, 0, 2, 1, 2, 2, 1, 1, 0, 2, 1, 1, 2, 0, 1};
// u have to sort it
// seems easy for  brute and better but the optimla uses DUTCH NATIONAL FLAG ALGORITHM
// whihc is why we learn about it

vector<int> sortArrayof0sand1sand2sB(vector<int> &a)
{
    // use an sorting techniques
    // so approx it ll take O(n logn)
    // and so we move to optimal
    // sc: acc to the sorting algo
    sort(a.begin(), a.end());
    return a;
}

vector<int> sortArrayof0sand1sand2sBe(vector<int> &a)
{
    // we run a loop and peserve the cnt for 0,1,2
    // and then we override in the array
    int n = a.size();
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            cnt0++;
        else if (a[i] == 1)
            cnt1++;
        else
            cnt2++;
    }

    for (int i = 0; i < cnt0; i++)
        a[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++)
        a[i] = 1;
    for (int i = cnt0 + cnt1; i < a.size(); i++)
        a[i] = 2;

    // or u could just simply create a variable indx and increment it whilestoring values
    // int idx = 0;
    // while (cnt0--)
    //     a[idx++] = 0;
    // while (cnt1--)
    //     a[idx++] = 1;
    // while (cnt2--)
    //     a[idx++] = 2;
    // like this

    return a;

    // TC : o(2N)
    // SC : o(1)
}

vector<int> sortArrayof0sand1sand2sO(vector<int> &a)

{
    // dutch national flag approach
    // We use 3 pointers: low, mid, high
    //
    // TC: O(n) | SC: O(1)
    int n = a.size();
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if (a[mid] == 1)
            mid++;
        else
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
    return a;
    // tc: O(n)
    // sc: O(1)
}

int main()
{
    vector<int> a = {1, 2, 1, 2, 0, 0, 2, 1, 2, 2, 1, 1, 0, 2, 1, 1, 2, 0, 1};

    vector<int> v = sortArrayof0sand1sand2sO(a);

    for (auto i : v)
        cout << i << " ";
}
