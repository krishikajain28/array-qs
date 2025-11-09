#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    Given an array of integers 'nums' and an integer 'target',
    return the indices of the two numbers such that they add up to the target.

    Example:
    nums = [3, 4, 6, 2], target = 7
    Output: [0, 1]  because nums[0] + nums[1] = 3 + 4 = 7
*/

/*-----------------------------------------
    Approach 1: Brute Force
    -----------------------------------------
    - Check every possible pair (i, j)
    - If nums[i] + nums[j] == target → return their indices

    ⏱️ Time Complexity: O(n²)
    → Two nested loops for all pairs
    💾 Space Complexity: O(1)
    → No extra data structure used
*/

vector<int> twoSumB1(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (nums[i] + nums[j] == target)
                return {i, j}; // Return the first valid pairs' indexes
        }
    }
    return {}; // If no such pair exists
}

vector<int> twoSumB2(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (nums[i] + nums[j] == target)
                return {i, j}; // Return the first valid pair
    return {};                 // If no such pair exists
}

/*-----------------------------------------
    🔸 Approach 2: Better (Using Hash Map)
    -----------------------------------------
    - Use an unordered_map to store visited numbers and their indices
    - For each element nums[i]:
        → Calculate complement = target - nums[i]
        → If complement already exists in map, we found our answer
        → Otherwise, store nums[i] → i in map

    ⏱️ Time Complexity: O(n)
        → Each element processed once
    💾 Space Complexity: O(n)
        → Extra map to store elements
    💾 Space Complexity: O(n logn)
        → in case of ordered map


*/
vector<int> twoSumBe(vector<int> &nums, int target)
{
    unordered_map<int, int> seen; // value → index
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (seen.count(complement))
            return {seen[complement], i}; // Pair found
        seen[nums[i]] = i;                // Store current element
    }
    return {}; // No valid pair found
}

vector<int> twoSumO(vector<int> &nums, int target)
{
    // two pointer  approach

    // we first sort the array and place the pointers on the extreme ends of the array
    // as the array is sorted the elements are placed in ascending order
    // we try and find the sum for left + right pointer and check if its == k
    // if > k that means the number should be decreased, there f or we move the right one space behind
    // and vice versa for left

    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        if (nums[left] + nums[right] > target)
            right--;
        if (nums[left] + nums[right] < target)
            left++;
        if (nums[left] + nums[right] == target)
            return {left, right}; // 0 based array
    }
    return {};
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 8, 2, 5, 4, 6, 2, 4, 9, 5, 7, 8, 4, 2, 4, 7, 1, 9, 4, 1};
    int k = 7;

    vector<int> brute1 = twoSumB1(a, k);
    vector<int> brute2 = twoSumB2(a, k);

    vector<int> better = twoSumBe(a, k);

    vector<int> optimal = twoSumO(a, k);

    cout << "Brute 1: ";
    for (auto i : brute1)
        cout << i << " ";

    cout << "\nBrute 2: ";
    for (auto i : brute2)
        cout << i << " ";

    cout << "\nBetter : ";
    for (auto i : better)
        cout << i << " ";

    cout << "\nOptimal: ";
    for (auto i : optimal)
        cout << i << " ";
}
