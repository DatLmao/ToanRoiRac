
#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("DT.inp", "r", stdin);
    freopen("DT.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    vector<int> DinhTreo, DinhCoLap;
    map<int,int> CanhSongSong;

    for(int i = 1; i <= n; i++){
        int check = 0;
        for(int j = 1; j <= n; j++){
            check += a[i][j];
            if(a[i][j] >= 2){
                CanhSongSong[i] = j;
            }
        }
        if(check == 1){ 
            DinhTreo.push_back(i);
        }
        if(check == 0){
            DinhCoLap.push_back(i);
        }
    }
    
    cout << "Đỉnh Cô Lập: ";
    for(int x:DinhCoLap) cout << x << " ";
    cout << endl;
    cout << "Đỉnh Treo: ";
    for(int x:DinhTreo) cout << x << " ";
    cout << endl;
    cout << "Cạnh Song Song: ";
    for(auto x:CanhSongSong){
        if(x.first < x.second) cout << x.first << '-' << x.second <<" ";
    }
    cout << endl;
}
