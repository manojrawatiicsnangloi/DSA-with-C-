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
            return n == nullptr ? 0 : height(n -> left) - height(n -> right);
        }

        void _inorder(node * n){
            if (n == nullptr) return;
            _inorder(n -> left);
            cout << n -> data << " ";
            _inorder(n -> right);
        }
        node * leftRotate(node * x){
            node * y = x -> right;
            node * t2 = y ->left;
            
            y -> left = x;
            x -> right = t2;
            x -> height = max(height(x -> left), height(x -> right));
            y -> height = max(height(y->left), height(x -> left));
            return y;
        }

        node * rightRotate(node * x){
            node * y = x -> left;
            node * t2 = y -> right;

            y -> right = x;
            x -> left = t2;

            x -> height = max(height(x -> left), height(x-> right));
            y -> height = max(height(y -> left), height(y -> right));
            return y;   
        }

        node * _insert(node * n, int value){
            if (n == nullptr) return new node(value);
            if (n -> data > value){
                n -> left = _insert(n -> left, value); 
            }
            else if (n -> data < value){
                n -> right = _insert(n -> right, value); 
            }
            else return n;

            n -> height = 1 + max(height(n-> left), height(n -> right));
            int balance = getBalance(n);
            if (balance > 1 && value < n -> left -> data){
                return rightRotate(n);
            }
            if (balance > 1 && value > n -> left -> data){
                n -> left = leftRotate(n->left);
                return rightRotate(n);
            }
            
            if (balance < 1 && value > n ->right -> data){
                return leftRotate(n);
            }
            if (balance < 1 && value < n -> right -> data){
                n -> right = rightRotate(n-> right);    
                return leftRotate(n);
            }
            return n;
        }


    public: avl_tree(){
            root = nullptr;
        }
        
        void insert(int value){
        root = _insert(root, value);
        }
        void inorder(){
            _inorder(root);
        }

    };

    int main(){
        int arr [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        avl_tree t;
        for (int i : arr){
            t.insert(i);
        }

        t.inorder();
        return 0;
    }