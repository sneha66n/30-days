#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size(), n = arr2.size();
    int gap = ceil((m + n) / 2.0);

    while (gap > 0) {
        int i = 0, j = gap;

        while (j < m + n) {
            int a = (i < m) ? arr1[i] : arr2[i - m];
            int b = (j < m) ? arr1[j] : arr2[j - m];

            if (a > b) {
                if (i < m && j < m) swap(arr1[i], arr1[j]);
                else if (i < m && j >= m) swap(arr1[i], arr2[j - m]);
                else swap(arr2[i - m], arr2[j - m]);
            }
            i++; j++;
        }

        if (gap == 1) break;
        gap = ceil(gap / 2.0);
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};

    mergeSortedArrays(arr1, arr2);

    cout << "arr1: ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
