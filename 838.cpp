#include <iostream>
#include <vector>

using namespace std;

string pushDominoes(string dominoes) {
    int n = dominoes.size();
    vector<int> forces(n, 0);
    int i = 0;
    while(i < n && dominoes[i] != 'R'){
        ++i;
    }
    int force = n;
    for(++i; i < n; ++i){
        if (dominoes[i] == 'R'){
            force = n;
        } else if (dominoes[i] == 'L') {
            force = 0;
        } else {
            if (force > 0) {
                --force;
            }
        }
        forces[i] += force;
    }
    i = n - 1;
    while(i > -1 && dominoes[i] != 'L'){
        --i;
    }
    force = n;
    for(--i; i > -1; --i){
        if (dominoes[i] == 'L'){
            force = n;
        } else if (dominoes[i] == 'R') {
            force = 0;
        } else {
            if (force > 0) {
                --force;
            }
        }
        forces[i] -= force;
    }
    for(int j = 0; j < n; ++j){
        if (forces[j] < 0){
            dominoes[j] = 'L';
        } else if (forces[j] > 0){
            dominoes[j] = 'R';
        }
    }
    return dominoes;
}

int main () {

    string s = "RR.L";
    cout << pushDominoes(s)  << "  " << "RR.L" << endl;
    s = ".L.R...LR..L..";
    cout << pushDominoes(s)  << "  " << "LL.RR.LLRRLL.." << endl;
    s = "L.L...L.L.LL.L..L...";
    cout << pushDominoes(s)  << "  " << "LLLLLLLLLLLLLLLLL..." << endl;


    return 0;
}
