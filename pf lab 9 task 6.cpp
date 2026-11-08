#include <stdio.h>

void printData(void *ptr, char type);

double add(int a, int b);
double subtract(int a, int b);
double multiply(int a, int b);
double divide(int a, int b);

double performOperation(int a, int b,
                        double (*operation)(int, int));

int main()
{
    int number1, number2, choice;
    int wholeNumber = 100;
    float decimalNumber = 25.567;
    char character = 'A';

    double (*operations[4])(int, int) = {
        add, subtract, multiply, divide
    };

    printf("========== GENERIC DATA PRINTER ==========\n");

    printData(&wholeNumber, 'i');
    printData(&decimalNumber, 'f');
    printData(&character, 'c');

    printf("\n========== SMART CALCULATOR ==========\n");

    printf("Enter first number: ");
    scanf("%d", &number1);

    printf("Enter second number: ");
    scanf("%d", &number2);

    printf("\n1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Choose an operation: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4)
    {
        printf("Invalid menu choice.\n");
        return 0;
    }

    performOperation(number1, number2, operations[choice - 1]);

    return 0;
}

void printData(void *ptr, char type)
{
    if (type == 'i')
    {
        printf("Integer: %d\n", *(int *)ptr);
    }
    else if (type == 'f')
    {
        printf("Float: %.2f\n", *(float *)ptr);
    }
    else if (type == 'c')
    {
        printf("Character: %c\n", *(char *)ptr);
    }
}

double add(int a, int b)
{
    return a + b;
}

double subtract(int a, int b)
{
    return a - b;
}

double multiply(int a, int b)
{
    return a * b;
}

double divide(int a, int b)
{
    return (double)a / b;
}

double performOperation(int a, int b,
                        double (*operation)(int, int))
{
    double result;

    if (operation == divide && b == 0)
    {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }

    result = operation(a, b);

    printf("Result: %.2f\n", result);

    return result;
}
