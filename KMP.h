#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> ComputePrefixFunction(string P) {
    int m = P.length();
    vector<int> pi(m);
    pi[0] = 0;
    int k = 0;

    for (int q = 1; q < m; q++) {
        while (k > 0 && P[k] != P[q]) {
            k = pi[k - 1];
        }
        if (P[k] == P[q]) {
            k++;
        }
        pi[q] = k;
    }

    return pi;
}

void KMPMatcher(string T, string P) {
    int n = T.length();
    int m = P.length();
    vector<int> pi = ComputePrefixFunction(P);
    int q = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i]) {
            q = pi[q - 1];
        }
        if (P[q] == T[i]) {
            q++;
        }
        if (q == m) {
            cout << "The template appears from the position " << i - m + 1 << endl;
            q = pi[q - 1];
        }
    }
}