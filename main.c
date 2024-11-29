
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100








// Function to check if the character is a valid digit or operator
int isValidCharacter(char c) {
    return isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to handle the precedence of operators
int precedence(char operator) {
    if (operator == '*' || operator == '/') {
        return 2;
    }
    if (operator == '+' || operator == '-') {
        return 1;
    }
    return 0;
}

// Function to perform the calculation based on the operator
int applyOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Error: Division by zero.\n");
                exit(1); // Terminate the program if division by zero occurs
            }
            return operand1 / operand2;
        default: return 0;
    }
}

// Function to evaluate the expression
int evaluateExpression(const char* expression) {
    int values[MAX_LEN], valuesIndex = -1;
    char operators[MAX_LEN], operatorsIndex = -1;

    int i = 0;
    while (expression[i] != '\0') {
        // Skip whitespaces
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        // If the character is a number, parse the full number and push to values stack
        if (isdigit(expression[i])) {
            int value = 0;
            while (isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            values[++valuesIndex] = value;
        }
        // If the character is an operator
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (operatorsIndex >= 0 && precedence(operators[operatorsIndex]) >= precedence(expression[i])) {
                int val2 = values[valuesIndex--];
                int val1 = values[valuesIndex--];
                char op = operators[operatorsIndex--];
                values[++valuesIndex] = applyOperation(val1, val2, op);
            }
            operators[++operatorsIndex] = expression[i];
            i++;
        }
        // If the character is invalid
        else {
            printf("Error: Invalid expression.\n");
            exit(1); // Terminate the program if invalid character is found
        }
    }

    // Process the remaining operators in the stack
    while (operatorsIndex >= 0) {
        int val2 = values[valuesIndex--];
        int val1 = values[valuesIndex--];
        char op = operators[operatorsIndex--];
        values[++valuesIndex] = applyOperation(val1, val2, op);
    }

    return values[valuesIndex];
}

int main() {
    char expression[MAX_LEN];

    // Get the input expression
    printf("Enter a mathematical expression: ");
    fgets(expression, MAX_LEN, stdin);

    // Remove trailing newline from fgets input
    expression[strcspn(expression, "\n")] = '\0';
    int len = strlen(expression);
// Check for any invalid characters
    for (int i = 0; expression[i] != '\0'; i++) {
        if (!isValidCharacter(expression[i]) && !isspace(expression[i])||( (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') &&
            (expression[i + 1] == '+' || expression[i + 1] == '-' || expression[i + 1] == '*' || expression[i + 1] == '/'))) {
            printf("Error: Invalid expression.\n");
            return 1; // Exit if invalid character is found
        }
    }
    if ((expression[0] == '+' || expression[0] == '-' || expression[0] == '*' || expression[0] == '/')||(expression[len - 1] == '+' || expression[len - 1] == '-' || expression[len - 1] == '*' || expression[len - 1] == '/'))
    {
    printf("Error: Invalid expression.\n");
            return 1;
    }

    // Evaluate the expression and print the result
    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}
