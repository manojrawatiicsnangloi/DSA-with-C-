#include <stdio.h>

int main() {

    // 1. Area of Circle
    float radius;
    printf("Enter radius: ");
    scanf("%f", &radius);
    printf("Area of Circle = %.2f\n\n", 3.14 * radius * radius);

    // 2. Area of Rectangle
    float length, breadth;
    printf("Enter length and breadth: ");
    scanf("%f %f", &length, &breadth);
    printf("Area of Rectangle = %.2f\n\n", length * breadth);

    // 3. Perimeter of Square
    float side;
    printf("Enter side of square: ");
    scanf("%f", &side);
    printf("Perimeter of Square = %.2f\n\n", 4 * side);

    // 4. Total Cost
    int quantity;
    float price;
    printf("Enter quantity and price per item: ");
    scanf("%d %f", &quantity, &price);
    printf("Total Cost = %.2f\n\n", quantity * price);

    // 5. Percentage
    float obtainedMarks, totalMarks;
    printf("Enter obtained marks and total marks: ");
    scanf("%f %f", &obtainedMarks, &totalMarks);
    printf("Percentage = %.2f%%\n\n", (obtainedMarks / totalMarks) * 100);

    // 6. Simple Interest
    float P, R, T;
    printf("Enter principal, rate, and time: ");
    scanf("%f %f %f", &P, &R, &T);
    printf("Simple Interest = %.2f\n\n", (P * R * T) / 100);

    // 7. Average Speed
    float distance, time;
    printf("Enter distance and time: ");
    scanf("%f %f", &distance, &time);
    printf("Average Speed = %.2f\n\n", distance / time);

    // 8. Area of Triangle
    float base, height;
    printf("Enter base and height: ");
    scanf("%f %f", &base, &height);
    printf("Area of Triangle = %.2f\n\n", 0.5 * base * height);

    // 9. Increased Value
    float number, percent;
    printf("Enter number and percentage: ");
    scanf("%f %f", &number, &percent);
    printf("Increased Value = %.2f\n\n", number + (number * percent / 100));

    // 10. Total Profit
    float costPrice, sellingPrice;
    int qty;
    printf("Enter cost price, selling price, and quantity: ");
    scanf("%f %f %d", &costPrice, &sellingPrice, &qty);
    printf("Total Profit = %.2f\n", (sellingPrice - costPrice) * qty);

    return 0;
}