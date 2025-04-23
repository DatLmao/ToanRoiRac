#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e9;
long long Mtts[1000][1000];
int sodinh;

int add(long long x, long long y) {
    if (x == inf || y == inf)
        return inf;
    else 
        return x + y;
}

bool compare(long long x, long long y) {
    if ((x == inf && y != inf)||(x > y))
        return true;
    else 
        return false; 
}

void Ford_Bellman(int s) {
    vector<long long> d(sodinh + 1);
    vector<int> truoc(sodinh + 1);
    vector<int> V, T;

    for (int i = 1; i <= sodinh; i++) {
        V.push_back(i);
        if (i != s)
            T.push_back(i);
    }

    for (int v : V) {
        d[v] = Mtts[s][v];
        truoc[v] = s;
    }
    d[s] = 0;

    for (int k = 1; k < sodinh - 1; k++) 
        for (int v : T) 
            for (int u : V) {
                int tong = add(d[u], Mtts[u][v]);
                if (compare(d[v], tong)) {
                    d[v] = tong;
                    truoc[v] = u;
                }
            }
    for (int i = 1; i <= sodinh; i++) {
        if (i != s) {
            if (d[i] != inf)
                cout << "d[" << i << "] = " << d[i] << ", ";
            else{
                cout << "d[" << i << "] = inf, Không có đường đi " << s << " đến " << i;
                continue;
            }

            vector<int> H;
            int x = i;
            while (x != s) {
                H.push_back(x);
                x = truoc[x];
                if (x == s)
                    H.push_back(x);
            }
            reverse(H.begin(), H.end());

            for (int c : H) {
                if (c != H.back())
                    cout << c << ", ";
                else 
                    cout << c;
            }
            cout << endl;
        }
    }
}

int main() {
    freopen("Bai4.inp", "r", stdin);
    freopen("Bai4.out", "w", stdout);

    string y;
    int s;
    cin >> sodinh >> s;

    for (int i = 1; i <= sodinh; i++) {
        for (int j = 1; j <= sodinh; j++) {
            cin >> y;
            if (y != "inf")
                Mtts[i][j] = stoi(y);
            else 
                Mtts[i][j] = inf;
        }
    }

    Ford_Bellman(s);

    return 0;
}
