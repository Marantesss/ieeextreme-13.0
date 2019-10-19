#include <iostream>

using namespace std;

struct node {
    int value;
    node *left;
    node *right;
    int level;
};
int insertValue(struct node* currentNode, long long newValue) {
    if (newValue <= currentNode->value) {
        if (currentNode->left != NULL) // child exists
            return insertValue(currentNode->left, newValue);
        else {
            node *newNode = new node;
            newNode->value = newValue;
            newNode->level = currentNode->level + 1;
            currentNode->left = newNode;
            return newNode->level;
        }
    }
    else {
        if (currentNode->right != NULL) // child exists
            return insertValue(currentNode->right, newValue);
        else {
            node *newNode = new node;
            newNode->value = newValue;
            newNode->level = currentNode->level + 1;
            currentNode->right = newNode;
            return newNode->level;
        }
    }
}

int main() {

    node nodeCaralho;
    long long numNodes;
    cin >> numNodes;

    long long newNodeValue;
    cin >> newNodeValue;
    nodeCaralho.value = newNodeValue;
    nodeCaralho.level = 1;
    nodeCaralho.left = NULL;
    nodeCaralho.right = NULL;

    cout << nodeCaralho.level << " ";

    for (long long i = 1; i < numNodes; i++) {
        cin >> newNodeValue;
        cout << insertValue(&nodeCaralho, newNodeValue) << " ";
    }

    cout << endl;

    return 0;
}
