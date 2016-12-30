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
    if (var == " ") {
      //Start back at the top of the loop
      return;
    } else if (var == "+" || var == "-"|| var == "/"|| var == "*") { //Check if its an operator
      //Call the calculating function

    }

  }

  return 0;
}

void popCalc(char var, std::stack<double>) {

}
