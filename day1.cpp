#include<iostream>
#include<vector>

using namespace std;

void dutchFlagSort(vector<int> &nums){
    int n = nums.size();

    if(n == 0){
        return;
    }

    int left = 0;
    int current = 0;
    int right = n - 1;

    while(current <= right){
        if(nums[current] == 0){
            swap(nums[left], nums[current]);
            left++;
            current++;
        }
        else if(nums[current] == 1){
            current++;
        }
        else{
            swap(nums[current], nums[right]);
            right--;
        }
    }
}

void displayVector(vector<int> &arr){
    cout << "[ ";
    for(auto val : arr){
        cout << val << " ";
    }
    cout << "]";
    cout << endl;
}

int main(){
    vector<vector<int>> testCases = {
        vector<int>({0, 1, 2, 1, 0, 2, 1, 0}),
        vector<int>({2, 2, 2, 2}),
        vector<int>({0, 0, 0, 0}),
        vector<int>({1, 1, 1, 1}),
        vector<int>({2, 0, 1}),
        vector<int>()
    };

    int caseNum = 1;

    for(auto test : testCases){
        cout << "Test Case : " << caseNum << endl;
        displayVector(test);
        dutchFlagSort(test);
        displayVector(test);
        cout << "\n\n" << endl;

        caseNum++;
    }
    return 0;
}
