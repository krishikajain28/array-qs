#include <bits/stdc++.h>
using namespace std;

// q8:find leaders in an array
// leader = any element that is the most greatest among every element on its right
// meaning if array [23, 22, 12, 3, 0, 6]
// return leaders = [23,22,12,6]
// 23 has not greater element than it on its right
// same for 22, 12, 6
// 3 has 6 greater than it
// 0 has 6 greater than it

vector<int> findLeadersB(vector<int> &nums)
{
    // create an array for leaders
    // run a for loop for nums
    // let i be current idx
    // linear searchign if there is any elemtn greater than i on its right
    // if found break
    // if not, put i in leaders array
    int n = nums.size();

    vector<int> leaders;

    for (int i = 0; i < n; i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] < nums[j])
            {
                isLeader = false;
                break;
            }
        }

        if (isLeader)
        {
            leaders.push_back(nums[i]);
        }
    }

    return leaders;

    // tc ~ n^2
    // sc ~ n (maxi, just to return)
}

vector<int> findLeadersBe(vector<int> &nums)
{
    int n = nums.size();
    // we do not have a btter for this one
    // so we directly go to the optimal
}

vector<int> findLeadersO(vector<int> &nums)

{
    // optimal
    // basically we make a variable as the maxi
    // at start a = INT_MIN
    // that means let the minimum number be maxi for now
    // then we start iterating from n-1 --> 0
    // at every element we check if nums[a] > nums[i]
    // if yes, we update.
    // and we check form behind while iterating only tht if, nums[i] > maxi number that is a
    // if yes that means
    int n = nums.size();

    int maxi = INT_MIN;
    vector<int> leaders;

    for (int i = n - 1; i >= 0; i--)
    {
        if (maxi <= nums[i])
        {
            maxi = nums[i];
            leaders.push_back(nums[i]);
        }
    }

    return leaders;
}

int main()
{
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    vector<int> m = findLeadersO(nums);

    for (auto i : m)
    {
        cout << i << " ";
    }
}
