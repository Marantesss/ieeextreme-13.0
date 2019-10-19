#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> objectives;
vector<pair<int,int>> powers;
int result = -1;
int N, M, S;

bool backtrack(int i, int acc){
    
} 

int main() {
    cin >> N >> M >> S;

    for(int i = 0; i < N; i++){
        int L, R;
        vector<int> objective;
        cin >> L >> R;
        for(; L <= R; L++){
            objective.push_back(L);
        }
        objectives.push_back(objective);
    }



    for(int i = 0; i < M; i++){
        backtrack(i, 0);
    }
}