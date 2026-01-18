#include <bits/stdc++.h>
using namespace std;

// customize this template according to ur needs
// q

int findLongestConsecutiveB(vector<int> &nums)
{
    int n = nums.size();
    int maxL = 1;

    for (int i = 0; i < n; i++)
    {
        int curr = nums[i] + 1;
        int currL = 1;

        while (find(nums.begin(), nums.end(), curr) != nums.end())
        {
            currL++;
            curr++;
            maxL = max(maxL, currL);
        }
    }
    return maxL;
}

int findLongestConsecutiveBe(vector<int> &nums)
{
    int n = nums.size();

    sort
}

int findLongestConsecutiveO(vector<int> &nums)

{
    // a set is toooooo low --> {O(n logn)}
    // an unordered set for this solution will be good -->{O(1)}

    int n = nums.size();

    if (nums.size() == 0)
        return 0;

    unordered_set<int> s;

    for (auto i : nums)
    {
        s.insert(i);
    }

    int l = 1;

    for (auto i : s)
    {
        if (s.find(i - 1) == s.end())
        {
            int curr = i + 1;
            int currL = 1;
            while (s.find(curr++) != s.end())
            {
                currL++;
                l = max(currL, l);
            }
        }
    }

    return l;

    // tc: to insert  we visit onceevery element and to
}

int main()
{
    vector<int> a = {101, 1, 1, 1, 102, 1, 2, 7, 6, 4, 2, 3, 104};
    // 1, 2, 3, 4, 6, 7, 101, 102, 104

    int ans = findLongestConsecutiveB(a);

    cout << "Length is: " << ans;
}
