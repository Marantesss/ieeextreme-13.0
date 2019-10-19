#include <iostream>
#include <list>
#include <math.h>
#include <unordered_map>

using namespace std;

unordered_map <string, bool> validStringMap; 
bool validString (string inputString) {
    if (validStringMap.find(inputString) != validStringMap.end()) {
        return validStringMap[inputString];
    }
    
    if (inputString.size() == 1) {
        validStringMap[inputString] = true;
        return true;
    }
    
    for (uint64_t i = 1; i < inputString.size(); i++) {
        
        string left_part = inputString.substr(0, i);
        string right_part = inputString.substr(i, inputString.size()-1);
        
        if (left_part > right_part)
        {
            validStringMap[inputString] = false;
            return false;
        }
        
        if (validString(left_part) && validString(right_part)) {
            validStringMap[inputString] = true;
            return true;
        }
        
    }
    validStringMap[inputString] = false;
    return false;
}
int main() {
    int n;
    cin >> n;
    list <string> inputString;
    for (int i = 0; i < n; i++) {
        
        string in;
        cin >> in;
        inputString.push_back(in);
    }
    
    for (list <string>::iterator it = inputString.begin(); it != inputString.end(); ++it) {
        cout << validString(*it);
    }
    cout << endl;
    
    return 0;
}