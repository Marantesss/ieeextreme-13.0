#include <string>
#include <iostream>
#include <vector>

using namespace std;

// coinValues[] = {1, 2, 5}
// exite um stock ilimitado de moedas de cada valor
vector <string> calcChange(long int m, long int numCoins, long int A) {
	long int minCoin[m + 1];
	long int lastCoin[m + 1];
	for (long int i = 0; i < m + 1; i++) {
		minCoin[i] = 100;
		lastCoin[i] = 0;
	}
	minCoin[0] = 0;

	for (long int i = 0; i < numCoins; i++) {
		long int possibleLastCoin = A + i;
		for (long int k = 1; k <= m; k++) {
			long int remainingChange = k - possibleLastCoin;
			if (remainingChange >= 0) {
				long int possibleMinCoin = minCoin[remainingChange] + 1;
				if (possibleMinCoin <= minCoin[k]) {
					minCoin[k] = possibleMinCoin;
					lastCoin[k] = possibleLastCoin;
				}
			}
		}
	}

	// getting the result
	long int remainingChange = m;
    vector <string> answer;
	while (remainingChange != 0) {
		answer.push_back(to_string(lastCoin[remainingChange]));
		remainingChange -= lastCoin[remainingChange];
	}

	return answer;
}

int main() {
    long int N, A, B;
    cin >> N >> A >> B;
    if (A * 2 <= N)
        cout << "YES" << endl;
    else {
        cout << "NO" << endl;
        return 0;
    }

    if (A * 2 == N) {
        cout << A << " " << A << endl;
        return 0;
    }

    vector<string> answer = calcChange(N, B - A + 1, A);

    for (long int i = answer.size() - 1; i >= 0; i--) {
        cout << answer.at(i);
        if (i != 0)
            cout << " ";
    }

    cout << endl;

    return 0;
}
