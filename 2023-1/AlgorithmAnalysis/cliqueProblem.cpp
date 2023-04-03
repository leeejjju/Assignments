#include <iostream>
#include <vector>
#include <set>
#include <chrono>
/*
by chatGPT

"base on C++, write a code to solve clique problem about n, with some code for know run time "

In this version of the code, the start variable is set to the current time using high_resolution_clock::now() before calling bron_kerbosch, and the stop variable is set to the current time after the function returns. The duration variable is calculated by subtracting start from stop and converting the result to milliseconds using duration_cast<milliseconds>.
Finally, the running time is output along with the maximal cliques. Note that the running time may vary depending on the size of the input graph and the hardware used to run the program.
I hope this helps! Let me know if you have any questions.

*/

using namespace std;
using namespace std::chrono;

const int MAXN = 100;

int n;
vector<int> adj[MAXN];
set<int> R, P, X;
vector<set<int>> cliques;

void bron_kerbosch() {
    if (P.empty() && X.empty()) {
        cliques.push_back(R);
        return;
    }

    for (int v : P) {
        set<int> neighbors;
        for (int u : adj[v]) {
            if (P.count(u) || X.count(u)) {
                neighbors.insert(u);
            }
        }

        R.insert(v);
        P.erase(v);
        bron_kerbosch();
        R.erase(v);
        X.insert(v);

        for (int u : neighbors) {
            if (!X.count(u)) {
                P.insert(u);
            }
        }
    }
}

int main() {
    // read input
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }

    // initialize P
    for (int i = 0; i < n; i++) {
        P.insert(i);
    }

    // measure running time of Bron-Kerbosch algorithm
    auto start = high_resolution_clock::now();
    bron_kerbosch();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    // output maximal cliques and running time
    for (set<int> clique : cliques) {
        for (int v : clique) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << "Running time: " << duration.count() << " ms" << endl;

    return 0;
}
