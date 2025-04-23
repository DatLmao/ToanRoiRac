#include <bits/stdc++.h>
using namespace std;

// Code nay in ra bang chan tri cua bieu thuc (P ∧ Q) → R

void BangChanTri(){
        cout << 'P' << " " << 'Q' << " " << 'R' << " " << "(P∧Q)→R" << endl;
        for(int i = 1; i >= 0; i--){
            for(int j = 1; j >= 0; j--){
                for(int k = 1; k >= 0; k--){
                    bool p = i, q = j, r = k, result = !(p&q) || r;
                    cout << p << " " << q << " " << r << " "  << " " << " " << " " << result << endl;
                }
            }
        }
}

int main() {
    freopen("Bai1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    BangChanTri();

}

