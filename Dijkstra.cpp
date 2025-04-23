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
    if ((x == inf && y != inf) || (x > y))
        return true;
    else 
        return false; 
}

void Dijsktra(int s) {
    vector<long long> d(sodinh + 1);
    vector<int> truoc(sodinh + 1);
    vector<int> V;

    for (int i = 1; i <= sodinh; i++){
        V.push_back(i);
        d[i] = Mtts[s][i];
        truoc[i] = s;
    }
    d[s] = 0;

    V.erase(find(V.begin(), V.end(), s));

    while (!V.empty()) {
        int u = V[0];
        int min = d[V[0]];

        for (int k : V) {
            if (d[k] < min) {
                min = d[k];
                u = k;
            }
        }
        V.erase(find(V.begin(), V.end(), u));

        for (int v : V) {
            int tong = add(d[u], Mtts[u][v]);
            if (compare(d[v], tong)) {
                d[v] = tong;
                truoc[v] = u;
            }
        }
    }

    for (int i = 1; i <= sodinh; i++) {
        if (i != s) {
            if (d[i] != inf)
                cout << "d[" << i << "] = " << d[i] << ", ";
            else {
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
    freopen("Dijkstra.inp", "r", stdin);
    freopen("Dijkstra.out", "w", stdout);
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

    Dijsktra(s);

    return 0;
}
