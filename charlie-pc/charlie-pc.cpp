#include <vector>
#include <map>
#include <iostream>

using namespace std;
vector<int> results;

class Node {
public:
    int value;
    vector<Node> children;

    Node() {
        this->value = 0;
    }
    Node(int value){
        this->value = value;
    }
    void setValue(int value){
        this->value = value;
    }
    void addChild(Node child){
        this->children.push_back(child);
    }
    void setChild(vector<Node> child){
        this->children = child;
    }
};

void dfs(Node node, int acc){
    if(node.children.size() == 0)
        results.push_back(acc + node.value);

    for(int i = 0; i < node.children.size(); i++){
        dfs(node.children[i], acc+node.value);
    }
}

int main() {
    vector<vector<int>> components;
    vector<Node> next;
    vector<Node> previous;
    multimap<int, int> index;
    int T, B, numComp;

    cin >> T >> B >> numComp;

    for(int i = 0; i < numComp; i++){
        int compSize;
        cin >> compSize;
        vector<int> comps(compSize, 0);
        components.push_back(comps);
    }

    for(int i = 0; i < numComp; i++){
        index.insert(pair<int,int>(components[i].size(), i));
        for(int j = 0; j < components[i].size(); j++){
            int value;
            cin >> value;
            components[i][j] = value;
        }
    }

    
    for (multimap<int,int>::iterator it = index.end(); it != index.begin();) {
        it--;

        for(int i = 0; i < components[it->second].size(); i++){
            Node current(components[it->second][i]);
            current.setChild(previous);
            next.push_back(current);
        }

        previous = next;
        next.clear();
    }

    int max = 0;
    for(int i = 0; i < previous.size(); i++){
        dfs(previous[i], 0);
    }
    for(int i = 0; i < results.size(); i++){
        if(results[i] <= B && results[i] > max)
            max = results[i];
    }
    
    cout << max << endl;

    return 0;
}