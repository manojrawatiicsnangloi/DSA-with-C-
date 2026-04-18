    #include <iostream>
    using namespace std;


    class node{

        public:int data;
        node * left;
        node * right;
        int height;
        node(int value){
            this-> data = value;
            this -> left = this -> right = nullptr;
            this -> height = 1; 
        }
    };

    class avl_tree{
        private : node * root;

        int height(node *n){
            return (n == nullptr ?  0 : n -> height);
        }

        int getBalance(node * n){
            return n == nullptr ? 0 : n -> left - n -> right;
        }

        node * leftRotate(node * x){
            node * y = x -> right;
            node * t2 = y ->left;
            
            y -> left = x;
            x -> right = t2;
            x -> height = max(height(x -> left), height(x -> right));
            y -> height = max(height(y->left), height(x -> left));
        }

        node * rightRotate(node * x){
            node * y = x -> left;
            node * t2 = y -> right;

            y -> right = x;
            x -> left = t2;

            x -> height = max(height(x -> left), height(x-> right));
            y -> height = max(height(y -> left), height(y -> right));
        }
public: avl_tree(){
            root = nullptr;
        }

        void insert(){}

    };

    int main(){

        return 0;
    }