#include <iostream>
#include <stack>

//Prototypes
double calculate(std::stack postfixStack);
void popCalc(std::string str, std::stack<double>* postfixStack)

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

  //String to store the operator or operand
  std::string str = "";

  //While the input string is not empty
  while (!input.empty()) {
    //Get the operand or operator while there are no spaces
    for (int i = 0; str != " "; i++) {
      //Put a character into str
      str = str + input[i];

      //Remove the caracter from input
      input.erase(0,1);
    }

    //Check if the character is a space
    if (str == " ") {
      //Start back at the top of the loop
      return;
    } else if (str == "+" || str == "-"|| str == "/"|| str == "*") { //Check if its an operator
      //Call the calculating function with a pointer to
      //the postfixStack
      popCalc(str, &postfixStack);
    } else {
      //Convert the number to a double from a string
      double converted;
      converted = std::stod(str);

      //Push the number into the stack
      postfixStack.push(converted);
    }

    //TODO: Return the result

  }

  return 0;
}

void popCalc(std::string str, std::stack<double>* postfixStack) {
  //Operands
  double operand1;
  double operand2;

  //NOTE: I'll have to test out this system while dividing as it might take the operands int the wrong order

  //Pop out the Operands
  operand1 = postfixStack.pop();
  operand2 = postfixStack.pop();

  //Store the result
  double result;

  //Determine what operation to do
  switch (var) {
    case "+": {
      result = operand1 + operand2;
      break;
    }

    case "-": {
      result = operand1 - operand2;
      break;
    }

    case "*": {
      result = operand1 * operand2;
      break;
    }

    case "/": {
      result = operand1 / operand2;
      break;
    }
  }

  //Push the result in the postfixStack
  postfixStack.push(result);

}
