#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> result;
    //k = min(static_cast<int>(arr.size()), k);
    auto it_next = lower_bound(arr.begin(), arr.end(), x);
    auto it_prev = it_next;
    double dist1, dist2;
    while(k > 0 && it_prev != arr.begin() && it_next != arr.end()){
        dist1 = abs(*prev(it_prev) - x);
        dist2 = abs(*it_next - x);
        if(dist1 < dist2) {
            --it_prev;
        } else if (dist1 == dist2) {
            if (*prev(it_prev) < *it_next){
                --it_prev;
            } else {
                ++it_next;
            }
        } else {
            ++it_next;
        }
        --k;
    }
    if (k == 0){
        result = vector<int>(it_prev, it_next);
    }
    if (it_prev == arr.begin()){
        while(k > 0){
            ++it_next;
            --k;
        }
        result = vector<int>(it_prev, it_next);
    } else {
        while(k > 0){
            --it_prev;
            --k;
        }
        result = vector<int>(it_prev, it_next);
    }
    return result;
}

int main() {

    vector<int> vec = {1, 2, 3, 4, 5 ,6 ,7, 8};
    vector<int> result = findClosestElements(vec, 5, 7);
    for(auto item : result){
        cout << item << " ";
    }

    return 0;
}