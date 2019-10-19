#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Edge {
    unsigned int destNodeId;
    double weight;

    // Constructors
    Edge(unsigned int destNodeId, const double & weight) {
        this->weight = weight;
        this->destNodeId = destNodeId;
    }

    Edge() {

    }
};

class Node {
public:
    unsigned int id;
    vector<Edge> edges;

    // ---- Equality operator
    bool operator==(const Node &d2) const;

    Node() {}

    Node(unsigned int id, unsigned int destID, unsigned int weight) {
        this->id = id;
        this->edges.push_back(Edge(destID, weight));
    }

    Node(const Node &  node, unsigned int lastNodeId , double totalWeight) {
        this->id = node.id;
        this->edges = node.edges;
    }

    Node(unsigned int id) {
        this->id = id;
    }
};

class Graph {
public:
    vector<Node> nodes;
    // ---- constructor
    Graph() {}

    // ---- Nodes
    unsigned int addNode(unsigned int id, unsigned int destID, unsigned int weight) {
        nodes.push_back(Node(id, destID, weight));
    }

    unsigned int addNode(unsigned int id) {
        nodes.push_back(Node(id));
    }

    Node& getNodeWithID(unsigned int id) const {
        for (unsigned int i = 0; i < nodes.size(); i++)
            if (nodes.at(i).id == id)
                return const_cast<Node &>(nodes.at(i));
    } // we need to return the reference so we can set the node type when parsing

    unsigned int getEdgeWeight(unsigned int sourceID, unsigned int destID) {
        for (unsigned int i = 0; i < this->getNodeWithID(sourceID).edges.size(); i++) {
            if (this->getNodeWithID(sourceID).edges.at(i).destNodeId == destID)
                return this->getNodeWithID(sourceID).edges.at(i).weight;
        }
    }
};



int dfs(Graph graph, unsigned int sourceID, unsigned int destID, stack<unsigned int>& visitedNodes, vector<bool>& visited) {
    visitedNodes.push(sourceID);
    visited.at(sourceID) = true;

    if (sourceID == destID)
        return 1;

    // get nodes
    Node sourceNode = graph.getNodeWithID(sourceID);
    vector<unsigned int> childNodes;
    for (unsigned int i = 0; i < sourceNode.edges.size(); i++) {
        if (!visited.at(sourceNode.edges.at(i).destNodeId))
            childNodes.push_back(sourceNode.edges.at(i).destNodeId);
    }

    for (unsigned int i = 0; i < childNodes.size(); i++) {
        if (dfs(graph, childNodes.at(i), destID, visitedNodes, visited)) {
            return 1;
        }
    }

    visited.at(sourceID) = false;
    visitedNodes.pop();

    return 0;
}

unsigned int searchPath(Graph graph, unsigned int sourceID, unsigned int destID) {
    stack<unsigned int> visitedNodes;

    Node sourceNode = graph.getNodeWithID(sourceID);

    vector<bool> visited;
    for(unsigned int i = 0; i <= graph.nodes.size(); i++) {
        visited.push_back(false);
    }

    dfs(graph, sourceID, destID, visitedNodes, visited);

    unsigned int largestEdge = 0;
    while(visitedNodes.size() > 1) {
        unsigned int top = visitedNodes.top();
        visitedNodes.pop();
        unsigned int possibleLargestEdge = graph.getEdgeWeight(top, visitedNodes.top());
        if (largestEdge < possibleLargestEdge)
            largestEdge = possibleLargestEdge;
    }

    return largestEdge;
}

int main() {

    Graph graph = Graph();

    unsigned int numNodes;
    cin >> numNodes;
    for (unsigned int i = 1; i <= numNodes; i++) {
        graph.addNode(i);
    }

    for (unsigned int i = 0; i < numNodes - 1; i++) {
        unsigned int A, B, W;
        cin >> A >> B >> W;
        graph.getNodeWithID(A).edges.push_back(Edge(B, W));
        graph.getNodeWithID(B).edges.push_back(Edge(A, W));
    }

    unsigned int sum = 0;
    for (unsigned int i = 1; i <= graph.nodes.size(); i++) {
        for(unsigned int j = i+1; j <= graph.nodes.size(); j++) {
            sum += searchPath(graph, i, j);
        }
    }
    cout << sum << endl;
}





