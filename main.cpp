#include <iostream>
#include <stack>

//Prototypes
double calculate(std::stack postfixStack);
bool isEmpty(std::string input);

int main() {

  //Postfix stack
  std::stack<double> postfixStack;

  //Varibable to store the result
  double result;

  //Calculate the expression
  result = calculate(postfixStack);

  //Display the result
  std::cout << "Result : " << result << std::endl;

  return 0;
}

double calculate(std::stack postfixStack) {

  //Input string
  std::string input;
  //Get the Input
  std::cout << "Please input the postfix expression : ";
  getline(input, std::cin);
  std::cout << std::endl;

  //While the input string is not empty
  while (!isEmpty(input)) {
    //Get the operand or operator
    
  }

  return 0;
}

bool isEmpty(std::string input) {

  //While the end of the string has not been reached
  for (int i = 0; i <= input.length(); i++) {
    //If at one moment, the character is not a space, return false
    if (input[i] != " ") return false

  }

  //By default, the function returns false
  return true;

}
