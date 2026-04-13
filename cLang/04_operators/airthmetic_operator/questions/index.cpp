#include <iostream>
using namespace std;

int main() {

    // 1. Area of Circle
    float radius;
    cout << "Enter radius: ";
    cin >> radius;
    cout << "Area of Circle = " << 3.14 * radius * radius << endl << endl;

    // 2. Area of Rectangle
    float length, breadth;
    cout << "Enter length and breadth: ";
    cin >> length >> breadth;
    cout << "Area of Rectangle = " << length * breadth << endl << endl;

    // 3. Perimeter of Square
    float side;
    cout << "Enter side of square: ";
    cin >> side;
    cout << "Perimeter of Square = " << 4 * side << endl << endl;

    // 4. Total Cost
    int quantity;
    float price;
    cout << "Enter quantity and price per item: ";
    cin >> quantity >> price;
    cout << "Total Cost = " << quantity * price << endl << endl;

    // 5. Percentage
    float obtainedMarks, totalMarks;
    cout << "Enter obtained marks and total marks: ";
    cin >> obtainedMarks >> totalMarks;
    cout << "Percentage = " << (obtainedMarks / totalMarks) * 100 << "%" << endl << endl;

    // 6. Simple Interest
    float P, R, T;
    cout << "Enter principal, rate, and time: ";
    cin >> P >> R >> T;
    cout << "Simple Interest = " << (P * R * T) / 100 << endl << endl;

    // 7. Average Speed
    float distance, time;
    cout << "Enter distance and time: ";
    cin >> distance >> time;
    cout << "Average Speed = " << distance / time << endl << endl;

    // 8. Area of Triangle
    float base, height;
    cout << "Enter base and height: ";
    cin >> base >> height;
    cout << "Area of Triangle = " << 0.5 * base * height << endl << endl;

    // 9. Increased Value
    float number, percent;
    cout << "Enter number and percentage: ";
    cin >> number >> percent;
    cout << "Increased Value = " << number + (number * percent / 100) << endl << endl;

    // 10. Total Profit
    float costPrice, sellingPrice;
    int qty;
    cout << "Enter cost price, selling price, and quantity: ";
    cin >> costPrice >> sellingPrice >> qty;
    cout << "Total Profit = " << (sellingPrice - costPrice) * qty << endl;

    return 0;
}