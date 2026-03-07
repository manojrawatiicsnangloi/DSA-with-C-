    #include <iostream>
    using namespace std;

    // void changeValue(int* x){
    //     *x = 50;
    // }

    // int main(){

    //     int num = 10;

    //     changeValue(&num);

    //     cout << num << endl;

    // }


    void changeValue(int &x){
        x = 50;
    }

    int main(){
        int num = 10;
        changeValue(num);
        cout << num << endl;
    }