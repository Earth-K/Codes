#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

struct Node{
    int n,x,y;
    struct Node* left;
    struct Node* right;
}nodes[10000];
int nodes_n;

Node* createNode(int n,int x, int y){
    nodes[nodes_n] = {n,x,y,NULL,NULL};
    return &nodes[nodes_n++];
}

struct comp{
    bool operator()(Node& n1, Node& n2){
        if(n1.y == n2.y)
            return n1.x > n2.x;
        else
            return n1.y < n2.y;
    }
};

void insertNode(Node* root, Node* newNode){
    if(root->left == NULL && root->x > newNode->x){
        root->left = newNode;
    }
    else if(root->right == NULL && root->x < newNode->x){
        root->right = newNode;
    }
    else if(root->x > newNode->x){
        insertNode(root->left, newNode);
    }
    else if(root->x < newNode->x){
        insertNode(root->right, newNode);
    }
}

void preOrder(Node* node, vector<int>& res){
    if(node == NULL) return;
    res.push_back(node->n);
    preOrder(node->left,res);
    preOrder(node->right,res);
}
void postOrder(Node* node, vector<int>& res){
    if(node == NULL) return;
    postOrder(node->left,res);
    postOrder(node->right,res);
    res.push_back(node->n);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    priority_queue<Node, deque<Node>, comp> pq;
    for(int i=0; i<nodeinfo.size(); i++){
        pq.push({i+1, nodeinfo[i][0], nodeinfo[i][1], NULL, NULL});
    }
    
    Node node = pq.top(); pq.pop();
    Node* root = createNode(node.n, node.x, node.y);
    
    while(!pq.empty()){
        Node node = pq.top();
        Node* newNode = createNode(node.n, node.x, node.y);
        insertNode(root, newNode);
        pq.pop();
    }
    vector<int> preRes;
    preOrder(root,preRes);
    vector<int> postRes;
    postOrder(root,postRes);
    answer.push_back(preRes);
    answer.push_back(postRes);
    return answer;
}