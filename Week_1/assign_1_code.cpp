#include <iostream>
#include <vector>
using namespace std;

const int MODULO = 1000000007;

vector<long long> computeCatalan(int limit) {
    vector<long long> catalan(limit + 1, 0);
    catalan[0] = 1;
    for (int idx = 1; idx <= limit; ++idx) {
        for (int k = 0; k < idx; ++k) {
            catalan[idx] = (catalan[idx] + (catalan[k] * catalan[idx - k - 1]) % MODULO) % MODULO;
        }
    }
    return catalan;
}

int main() {
    int maxN = 100;
    vector<long long> result = computeCatalan(maxN); // Precompute all Catalan numbers up to maxN

    for (int m = 1; m <= maxN; ++m) {
        cout << result[m] << " ";
    }
    cout << "\n";
    return 0;
}


