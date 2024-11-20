#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>
using namespace std;

// Question struct
struct Question {
    string questionText;
    vector<string> options;
    char correctOption;

    void displayQuestion() const {
        cout << questionText << endl;
        for (size_t i = 0; i < options.size(); i++) {
            cout << "   " << char('a' + i) << ") " << options[i] << endl;
        }
    }

    bool checkAnswer(char answer) const {
        return tolower(answer) == correctOption;
    }
};


// Quiz function
void runQuiz(const vector<Question>& quizQuestions, const string& quizName) {
    cout << "\nYou selected " << quizName << " quiz.\n";
    int score = 0;
    char answer;

    for (const auto& question : quizQuestions) {
        question.displayQuestion();
        cout << "Your answer: ";
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (question.checkAnswer(answer)) {
            cout << "\nCorrect!!!\n";
            score++;
        } else {
            cout << "\nWrong!!! The correct answer is " << char(question.correctOption) << ". " 
                 << question.options[question.correctOption - 'a'] << endl;
        }
        cout << "---------------------------------------------\n";
    }

    cout << "\nYour score in the " << quizName << " quiz is: " << score 
         << " out of " << quizQuestions.size() << "\n";
}

int main() {
    // Questions for C quiz
    vector<Question> cQuiz = {
        {"Which of the following is a Palindrome number?", 
         {"42042", "101010", "23232", "01234"}, 'c'},
        {"Which function is used to read a string?", 
         {"get()", "gets()", "input()", "read()"}, 'b'},
        {"Which of these is not a valid data type in C?", 
         {"int", "float", "string", "char"}, 'c'},
        {"What is the output of `printf(\"%d\", 5 + 10);`?", 
         {"15", "510", "5 + 10", "Error"}, 'a'},
        {"Which operator is used to access members of a structure?", 
         {". (dot)", "-> (arrow)", "* (asterisk)", "& (ampersand)"}, 'a'}
    };

    // Questions for C++ quiz
    vector<Question> cppQuiz = {
        {"What keyword is used to create a class?", 
         {"struct", "class", "object", "instance"}, 'b'},
        {"Which of the following is not a constructor?", 
         {"Default Constructor", "Parameterized Constructor", "Copy Constructor", "Destructor"}, 'd'},
        {"What is the purpose of the `virtual` keyword?", 
         {"To create a new object", "To allow polymorphism", "To overload functions", "To declare a constant"}, 'b'},
        {"Which of these is a valid inheritance?", 
         {"class A : public B", "class A inherits B", "class A extends B", "class A - B"}, 'a'}
    };

    // Questions for DSA quiz
    vector<Question> dsaQuiz = {
        {"What is the time complexity of binary search?", 
         {"O(n)", "O(log n)", "O(n log n)", "O(1)"}, 'b'},
        {"Which data structure uses LIFO?", 
         {"Queue", "Stack", "Array", "Linked List"}, 'b'},
        {"What is the worst-case time complexity of QuickSort?", 
         {"O(n)", "O(n log n)", "O(n^2)", "O(log n)"}, 'c'},
        {"What is a linked list?", 
         {"A collection of nodes", "A static data structure", "An array of lists", "None of the above"}, 'a'},
        {"Which of these is a type of tree structure?", 
         {"Binary Tree", "Circular Linked List", "Stack", "Queue"}, 'a'}
    };

    // Run quizzes
    string ch;
    cout << "Choose a quiz: C, C++, DSA\n";
    
    cin << ch;
    if (ch == "C") {
        runQuiz(cQuiz, "C");
    }
    else if (ch == "C++") {
        runQuiz(cppQuiz, "C++");
    }
    else if(ch == "DSA"){
        runQuiz(dsaQuiz, "DSA");
    }
    else{
        cout << "Invalid choice\n";
    }

    
    return 0;
}
