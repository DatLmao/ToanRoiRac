#include <bits/stdc++.h>
using namespace std;

int n, r;
int a[100][100];
int check[100];

vector<pair<int, int>> T;

void Tree_BFS(int r) {
	queue<int> q;
	q.push(r);
	check[r] = 0;

	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int u = 1; u <= n; u++)
			if (a[v][u] == 1 && check[u]) {
				q.push(u);
				check[u] = 0;
				T.push_back({v, u});
			}
	}
}

int main() {
	freopen("BFS.inp", "r", stdin);
	freopen("BFS.out", "w", stdout);

	cin >> n >> r;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	for (int i = 1; i <= n; i++)
		check[i] = 1;

	Tree_BFS(r);
	cout << "T = {";
	for (int i = 0; i < T.size(); i++) {
    	cout << '(' << T[i].first << "," << T[i].second << ')';
    	if (i != T.size() - 1) cout << ',';
	}
	cout << "}";


	return 0;
}
