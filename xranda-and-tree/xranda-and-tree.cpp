#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

struct Edge {
    long long destNodeId;
    long long weight;

    // Constructors
    Edge(long long destNodeId, const long long & weight) {
        this->weight = weight;
        this->destNodeId = destNodeId;
    }

    Edge() {

    }
};

class Node {
public:
    long long id;
    vector<Edge> edges;

    Node() {}

    Node(long long id, long long destID, long long weight) {
        this->id = id;
        this->edges.push_back(Edge(destID, weight));
    }

    Node(const Node &  node, long long lastNodeId , long long totalWeight) {
        this->id = node.id;
        this->edges = node.edges;
    }

    Node(long long id) {
        this->id = id;
    }

    bool operator==(const Node& d2) const{
        return this->id == d2.id;
    }
};

struct NodeHash {
    bool operator()(const Node &d1, const Node &d2) const {
        return d1 == d2;
    }

    int operator()(const Node &d) const {
        return d.id;
    }
};

typedef unordered_set<Node, NodeHash, NodeHash> NodeHashTable;

class Graph {
public:
    NodeHashTable nodes;
    // ---- constructor
    Graph() {}

    // ---- Nodes
    void addNode(long long id) {
        nodes.insert(Node(id));
    }

    Node& getNodeWithID(long long id) const {
        return const_cast<Node &>(*(nodes.find(Node(id))));
    } // we need to return the reference so we can set the node type when parsing

    long long getEdgeWeight(long long sourceID, long long destID) {
        for (size_t i = 0; i < this->getNodeWithID(sourceID).edges.size(); i++) {
            if (this->getNodeWithID(sourceID).edges.at(i).destNodeId == destID)
                return this->getNodeWithID(sourceID).edges.at(i).weight;
        }
    }
};



int dfs(Graph graph, long long sourceID, long long destID, stack<long long>& visitedNodes, vector<bool>& visited) {
    visitedNodes.push(sourceID);
    visited.at(sourceID) = true;

    if (sourceID == destID)
        return 1;

    // get nodes
    Node sourceNode = graph.getNodeWithID(sourceID);
    vector<long long> childNodes;
    for (size_t i = 0; i < sourceNode.edges.size(); i++) {
        if (!visited.at(sourceNode.edges.at(i).destNodeId))
            childNodes.push_back(sourceNode.edges.at(i).destNodeId);
    }

    for (size_t i = 0; i < childNodes.size(); i++) {
        if (dfs(graph, childNodes.at(i), destID, visitedNodes, visited)) {
            return 1;
        }
    }

    visited.at(sourceID) = false;
    visitedNodes.pop();

    return 0;
}

long long searchPath(Graph graph, long long sourceID, long long destID) {
    stack<long long> visitedNodes;

    Node sourceNode = graph.getNodeWithID(sourceID);

    vector<bool> visited;
    for(size_t i = 0; i <= graph.nodes.size(); i++) {
        visited.push_back(false);
    }

    dfs(graph, sourceID, destID, visitedNodes, visited);

    long long largestEdge = 0;
    while(visitedNodes.size() > 1) {
        long long top = visitedNodes.top();
        visitedNodes.pop();
        long long possibleLargestEdge = graph.getEdgeWeight(top, visitedNodes.top());
        if (largestEdge < possibleLargestEdge)
            largestEdge = possibleLargestEdge;
    }

    return largestEdge;
}

int main() {

    Graph graph = Graph();

    long long numNodes;
    cin >> numNodes;
    for (long long i = 1; i <= numNodes; i++) {
        graph.addNode(i);
    }

    for (long long i = 0; i < numNodes - 1; i++) {
        long long A, B, W;
        cin >> A >> B >> W;
        graph.getNodeWithID(A).edges.push_back(Edge(B, W));
        graph.getNodeWithID(B).edges.push_back(Edge(A, W));
    }

    long long sum = 0;
    for (size_t i = 1; i <= graph.nodes.size(); i++) {
        for(size_t j = i+1; j <= graph.nodes.size(); j++) {
            sum += searchPath(graph, i, j);
        }
    }
    cout << sum << endl;
}
