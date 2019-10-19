#include <iostream>
#include <vector>

using namespace std;

int main() {
    long int N, A, B;
    cin >> N >> A >> B;
    if (A * 2 <= N)
        cout << "YES" << endl;
    else {
        cout << "NO" << endl;
        return 0;
    }

    long int numCoins[N + 1];
    long int best[N + 1];

    for(int i = 0; i <= N; i++){
        numCoins[i] = INT32_MAX;
        best[i] = 0;
    }
    numCoins[0] = 0;

    for (long int i = A; i <= B; i++) {
        for(long int m = i; m <= N; m++) {
            if((1 + numCoins[m - i]) <= numCoins[m] && (m - i) >= 0) {
                numCoins[m] = 1 + numCoins[m - i];
                best[m] = i;
            }
        }
    }

    vector<long int> outputArray;

    while(N > 1) {
        outputArray.push_back(best[N]);
        N = N - best[N];
    }

    while(!outputArray.empty()) {
        cout << outputArray.back() << " ";
        outputArray.pop_back();
    }

    return 0;
}
