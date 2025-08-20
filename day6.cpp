#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// similar to Leetcode 560
vector<pair<int,int>> subarrayzsum(const vector<int>& arr)
{
    vector<pair<int,int>> result;
    unordered_map<long long, vector<int>> prefixMap;
    long long prefixSum = 0;
    for (int i = 0; i < arr.size(); i++) 
    {
        prefixSum += arr[i];
        if (prefixSum == 0) 
        {
            result.push_back({0, i});
        }
        if (prefixMap.find(prefixSum) != prefixMap.end()) 
        {
            for (int startIndex : prefixMap[prefixSum]) 
            {
                result.push_back({startIndex + 1, i});
            }
        }
        prefixMap[prefixSum].push_back(i);
    }
    return result;
}

void testcase(const vector<int>& arr)
{
    vector<pair<int,int>> subarrays = subarrayzsum(arr);
    cout << "Input: [ ";
    for (int x : arr) cout << x << " ";
    cout << "]" << endl;
    cout << "Subarrays with Zero Sum: ";
    if (subarrays.empty())
    {
        cout << "[]" << endl;
    }
    else
    {
        for (auto &p : subarrays) 
        {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
}

int main() 
{
    testcase({1, 2, -3, 3, -1, 2});          
    testcase({4, -1, -3, 1, 2, -1});         
    testcase({1, 2, 3, 4});                  
    testcase({0, 0, 0});                     
    testcase({-3, 1, 2, -3, 4, 0});          
    vector<int> bigArr;
    for (int i = 0; i < 5; i++)
    {
        bigArr.insert(bigArr.end(), {1, -1, 2, -2, 3, -3});
    }
    testcase(bigArr);
    return 0;
}
