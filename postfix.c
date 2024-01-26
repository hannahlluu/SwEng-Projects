#include "postfix.h"
#include "stack.h"
#include <math.h>
#include <string.h>

int is_operator(char*token);
// evaluate expression stored as an array of string tokens
double evaluate_postfix_expression(char ** args, int nargs) {
  double num1 = 0.0;
  double num2 = 0.0;
  double result = 0.0;
  struct double_stack * stack = double_stack_new(nargs);
  for(int i =0; i<nargs; i++){
    char token = args[i][0];
    //printf("i = %c", args[i][0]);
    //printf("%c \n" , args[i][1]);

    if(!is_operator(args[i])) {
      double number = atof(args[i]);
    double_stack_push(stack,number);
    }
    else switch(token) {
   
      case '+':
        num2 = double_stack_pop(stack);
        num1 = double_stack_pop(stack); 
        result = num1+num2;
        double_stack_push(stack,result);
       break;
      
	case '-':
    if (args[i][1] != '\0' && args[i][0] == '-') {
        num1 = -atof(args[i] + 1); // Skip the '-' sign
        double_stack_push(stack, num1);
    } else {
        num2 = double_stack_pop(stack);
        num1 = double_stack_pop(stack);
        result = num1 - num2;
        double_stack_push(stack, result);
    }
    break;


      // case 'x': {
      //   double num2 = double_stack_pop(stack);
      //   double num1 =double_stack_pop(stack);
      //   printf("Multiplying %f and %f \n",num2, num1);
      //   double result = num1*num2;
      //   printf("Pushing %f to the stack\n",result);
      //   double_stack_push(stack,result);
      //     printf("result so far: %f \n", result);
      //   break;
      // }
            case 'X': 
        num2 = double_stack_pop(stack);
        num1 =double_stack_pop(stack);
        result = num1*num2;
        double_stack_push(stack,result);
        break;
      

      case '/':
        num2 = double_stack_pop(stack);
        num1 = double_stack_pop(stack);
        result = num1/num2;
        double_stack_push(stack,result);
        break;
      
      
      case '^': 
        num2 = double_stack_pop(stack);
        num1 = double_stack_pop(stack);
        result = pow(num1,num2);
        double_stack_push(stack,result);
        break;
    

  }

}
 return double_stack_pop(stack);

}


