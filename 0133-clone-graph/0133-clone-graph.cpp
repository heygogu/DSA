/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    //create a node registry to avoid dupicate creation of a node
   

    void cloneNodes(Node* actual, Node* clone, vector<Node*>& nodeRegistry){

        //explore the neighbors using dfs
        for(auto neighbor:actual->neighbors){
            if(nodeRegistry[neighbor->val]==NULL){
                //create a new node
                Node* newNode= new Node(neighbor->val);
                //add it to the neighbor of the clone
                nodeRegistry[neighbor->val]=newNode;
                clone->neighbors.push_back(newNode);

                cloneNodes(neighbor,newNode,nodeRegistry);
            }
            else{
                //already created
                clone->neighbors.push_back(nodeRegistry[neighbor->val]);
                // cloneNodes(neighbor,nodeRegistry[neighbor->val],nodeRegistry);
            }
        }
        

    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        vector<Node*>nodeRegistry(105,NULL); // 105 because of the constraints
        Node* cloneRoot = new Node(node->val);
        nodeRegistry[node->val]=cloneRoot;

        cloneNodes(node,cloneRoot,nodeRegistry);

        return cloneRoot;
    }
};