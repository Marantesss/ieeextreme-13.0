#include <vector>
#include <iostream>

using namespace std;

long long int output = INT32_MAX;
vector<pair<int, int>> objectives;
vector<vector<long long int> > powers;
long long int N, M, S;

bool intersect(long long int Left, long long int Right)
{
    bool result = false;
    for(long long int i = 0; i < objectives.size(); i++){
        int L = objectives[i].first;
        int R = objectives[i].second;

        if(Left <= L && R <= Right){
            objectives.erase(i + objectives.begin());
            i--;
        }
        else if(L < Left && Left <= R && R <= Right){
            objectives[i].second = Left;
        }
        else if(Right < R && Left <= L && L <= Right){
            objectives[i].first = Right;
        }
        else if(L < Left && Right < R) {
            objectives[i].second = Left;
            objectives.push_back(pair<int,int>(Right, objectives[i].second));
        }
        else{
            continue;
        }

        result = true;
    }

    return result;
}

int main()
{
    int max_range = 0;
    int atIndex;
    cin >> N >> M >> S;

    for (long long int i = 0; i < N; i++)
    {
        long long int L, R;
        cin >> L >> R;
        objectives.push_back(pair<int, int>(L, R));
    }

    for (long long int i = 0; i < M; i++)
    {
        long long int L, R, C;
        cin >> L >> R >> C;
        vector<long long int> power = {L, R, C};
        powers.push_back(power);

        if ((R - L) > max_range)
        {
            max_range = R - L;
            atIndex = i;
        }
    }
    
    while (objectives.size() != 0)
    {
        if(powers.size() == 0){
            output = -1;
            break;
        }

        if(intersect(powers[atIndex][0], powers[atIndex][1])){
            output += powers[atIndex][2];
        }
        powers.erase(atIndex + powers.begin());
        max_range = 0;
        for (long long int i = 0; i < powers.size(); i++)
        {
            long long int L = powers[i][0];
            long long int R = powers[i][1];
            long long int C = powers[i][2];
            if ((R - L) > max_range)
            {
                max_range = R - L;
                atIndex = i;
            }
        }
    }
    cout << output << endl;

    return 0;
}