#include <iostream>
#include <stack>

using namespace std;

int main() {
    long long int N, A, B;
    cin >> N >> A >> B;
    if (A * 2 <= N)
        cout << "YES" << endl;
    else {
        cout << "NO" << endl;
        return 0;
    }

    long long int numCoins[N];
    long long int best[N];

    for(int i = 0; i < N; i++){
        numCoins[i] = __LONG_LONG_MAX__;
        best[i] = 0;
    }

    for (int i = A; i <= B; i++){
        for(int m = i; m <= N; m++){
            if((1 + numCoins[m - i]) <= numCoins[m]){
                numCoins[m] = 1 + numCoins[m - i];
                best[m] = i;
            }
        }
    }
    // int i = 0;
    // while(i <= N) {
    //     cout << best[i] << endl;
    //     i++;
    // }

    return 0;
}
