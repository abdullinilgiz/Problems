#include<iostream>
#include<vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = static_cast<int>(nums1.size());
    int n2 = static_cast<int>(nums2.size());
    int one = 2;
    int index = n1 + n2;
    if (index % 2 == 1) one = 1;
    if (n1 > 0 || n2 > 0) --index;
    index /= 2;
    int i = 0, j = 0;
    while (i < n1 && j < n2 && i + j < index){
        if (nums1[i] < nums2[j]){
            ++i;
        } else {
            ++j;
        }
    }
    while (i < n1 && i + j < index) ++i;
    while (j < n2 && i + j < index) ++j;
    double sum = 0;
    if (i == n1){
        for(int k = 0; k < one; ++k){
            sum += nums2[j];
            ++j;
        }
    }else if (j == n2){
        for(int k = 0; k < one; ++k){
            sum += nums1[i];
            ++i;
        }
    } else {
        for(int k = 0; k < one; ++k){
            if (i < n1 && j < n2) {
                if (nums1[i] < nums2[j]) {
                    sum += nums1[i];
                    ++i;
                } else {
                    sum += nums2[j];
                    ++j;
                }
            } else if (i == n1){
                sum += nums2[j];
            } else {
                sum += nums1[i];
            }
        }
    }
    if (one != 1){
        sum /= 2;
    }
    return sum;
}

int main() {

    vector<int> n2 = {3, 4};
    vector<int> n1 = {1, 2};
    cout << findMedianSortedArrays(n1, n2) << endl;

    return 0;
}