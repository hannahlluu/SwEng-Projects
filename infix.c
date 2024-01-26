#include "infix.h"
#include <math.h>
#include <string.h>

char *operator2string(char operator);
int is_operator(char*token);
int double_stack_precedence(char operator);
double double_stack_peak( struct double_stack*stack);


// Evaluate expression stored as an array of string tokens
double evaluate_infix_expression(char **args, int nargs) {
    struct double_stack *stack = double_stack_new(nargs);
    int postfix_nargs = 0;
    char operator;  
    char **postfix = malloc(sizeof(char *) * nargs); // Output string
    for (int i = 0; i < nargs; i++) {
        if (args[i][0] >= '0' && args[i][0] <= '9') { // Check if the token is a number
        if (args[i][1] != '\0' && args[i][0] == '-') {
        -atof(args[i] + 1); // Skip the '-' sign
        }
 
            postfix[postfix_nargs] = strdup(args[i]); // Store the number as is
            postfix_nargs++;

        } 
        
        else if (args[i][0] == '(') { // If the token is a left bracket
            double_stack_push(stack, '(');

        } 
        // else if (is_operator(operator2string(args[i][0])) == 1) { // If the token is an operator
        //     while (double_stack_empty(stack) == 0 && is_operator(operator2string(double_stack_peak(stack))) ==1&& 
        //     double_stack_precedence(double_stack_peak(stack)) >= double_stack_precedence(args[i][0])) {
        //      operator = double_stack_pop(stack);
        //      if(operator == '-' && args[i][1] >= '0' && args[i][1] <= '9' ){
        //      postfix[postfix_nargs] = strdup(args[i]); // Store the negative number as is
        //       postfix_nargs++;
        //      }
        //         postfix[postfix_nargs] = operator2string(operator);
        //         postfix_nargs++;
        //     }
        //     double_stack_push(stack, args[i][0]);
        else if (is_operator(operator2string(args[i][0])) == 1) {
    while (double_stack_empty(stack) == 0 && is_operator(operator2string(double_stack_peak(stack))) == 1 &&
           double_stack_precedence(double_stack_peak(stack)) >= double_stack_precedence(args[i][0])) {
   if (args[i][0] == '-' && args[i][1] >= '0' && args[i][1] <= '9') {
        postfix[postfix_nargs] = '-';    
        postfix[postfix_nargs] = strdup(args[i]); // Store the negative number without '-'
    postfix_nargs++;
    double_stack_pop(stack);
    break;
    } else {
        operator = double_stack_pop(stack);
        postfix[postfix_nargs] = operator2string(operator);
        postfix_nargs++;
    }
    }
    double_stack_push(stack, args[i][0]);

        } else if (args[i][0] == ')') {
            while (!double_stack_empty(stack) && double_stack_peak(stack) != '(') {
                 operator = double_stack_pop(stack);
                postfix[postfix_nargs] = operator2string(operator);
                postfix_nargs++;
            }
            if (!double_stack_empty(stack) && double_stack_peak(stack) == '(') {
                double_stack_pop(stack); // Pop the '(' from the stack
            }
        }
    }

    while (!double_stack_empty(stack)) {
     operator = double_stack_pop(stack);
        postfix[postfix_nargs] = operator2string(operator);
        postfix_nargs++;
    }

    return evaluate_postfix_expression( postfix,postfix_nargs);
}

char *operator2string(char operator){
    char* result = malloc (sizeof(char)*2);
    result[0]= operator;
    result[1]= '\0';
    return result;
}
double double_stack_peak( struct double_stack*stack) {
    assert(!double_stack_empty(stack));
  return stack->items[stack->top - 1];

}

int double_stack_precedence(char operator) { // checking precedence of operator
    switch (operator) {
        case '^':
            return 3;
        case 'X':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; 
  
}
}