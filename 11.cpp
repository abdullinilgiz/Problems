#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int result = 0;

    int i = 0, j = height.size() - 1;
    while(i < j){
        result = max(result, min(height[i], height[j]) * (j - i));
        if (height[i] > height[j]){
            --j;
        } else {
            ++i;
        }
    }

    return result;
}

int main() {

    vector<int> vec = {1,8,6,2, 100, 100,8,3,7};
    cout << maxArea(vec) << endl;

    return 0;
}