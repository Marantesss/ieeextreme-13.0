#include <iostream>

using namespace std;

int main() {
    int k, j;
    cin >> k >> j;
    int num = 0;

    while(k != 0 && j != 0 && k + j >= 3) {
        num++; k--; j--;
        if (k > j)
            k--;
        else
            j--;
    }

    cout << num << endl;
}