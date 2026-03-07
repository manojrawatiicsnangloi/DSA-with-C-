#include <iostream>
#include <vector>
#include <queue>

class Node{
    public:int data;
    Node * left;
    Node * right;
    Node(int value){
        this -> data = value;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

class Tree{
    private:Node* root;

   public: Tree(){
        root = nullptr;
    }

    void levelOrder(){
        if(root == nullptr) return;
        std::queue<Node *> a;
        a.push(root);
        while (!a.empty()){
            Node * node = a.front();
            a.pop();
            std::cout << node -> data;
            if (node ->left) a.push(node ->left);
            if (node -> right) a.push(node ->right);
        }
    }
    void inorder(Node* root){
        if (root == nullptr) return;
        inorder(root -> left);
        std::cout << root -> data << " ";
        inorder(root -> right);
    }

    void postOrder(Node* root){
        if (root == nullptr) return;
        postOrder(root -> left);
        postOrder(root -> right);
        std::cout << root -> data << " ";
    }


    void preOrder(Node* root){
        if (root == nullptr) return;
        std::cout << root -> data << " ";
        preOrder(root -> left);
        preOrder(root -> right);
    }


    public:void insert(int value){
        root = insertRec(root, value);
    }
    void _inoder(){
        
        std::cout <<"--------------In Order-------------------- \n";
        inorder(root);
        std::cout <<"\n";
    }
    void _postOrder(){
        std::cout <<"--------------In Order-------------------- \n";
        postOrder(root);
        std::cout <<"\n";
    }
    void _preOrder(){
        std::cout <<"--------------In Order-------------------- \n";
        preOrder(root);
        std::cout <<"\n";
    }
    void _levelOrder(){
        std::cout <<"--------------In Order-------------------- \n";
        levelOrder();
        std::cout <<"\n";
    }

    Node * insertRec(Node * root, int value){
        if (root == nullptr) return new Node(value);
        if (root -> data > value) {
            root -> left = insertRec(root -> left, value);
        }
        else if (root -> data < value){
            root -> right = insertRec(root -> right, value);
        }
        return root;
    }
    void buildTree(std::vector<int>& arr){
        for (int i : arr){
            root = insertRec(root, i);
        }
    }
};

int main(){
    Tree t;
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    t.buildTree(arr);    
    t._inoder();
    t._preOrder();
    t._postOrder();
    return 0;
}