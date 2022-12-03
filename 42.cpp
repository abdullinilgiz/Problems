#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    const int h = height.size();
    if (h < 3){
        return 0;
    }
    vector<int> max_left(h);
    vector<int> max_right(h);
    max_left[0] = height[0];
    max_right[h - 1] = height[h - 1];
    for ( int i = 1; i < h; ++i){
        max_left[i] = max(max_left[i-1], height[i]);
    }
    for( int i = h - 2;  i > 0; --i){
        max_right[i] = max(max_right[i + 1], height[i]);
    }
    int result = 0;
    for (int i = 1; i < h - 1; ++i){
        result += min(max_right[i], max_left[i]) - height[i];
    }
    return result;
}

int main() {

    vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(vec) << 6 << endl;
    vector<int> vec1 = {4,2,0,3,2,5};
    cout << trap(vec1) << 9 << endl;

    return 0;
}