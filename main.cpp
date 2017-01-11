#include <iostream>
#include <stack>
#include <sstream>

//Prototypes
double calculate(std::stack<double> postfixStack);
void popCalc(std::string str, std::stack<double>* postfixStack);

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

double calculate(std::stack<double> postfixStack) {

  //Input string
  std::string input;
  //Get the Input
  std::cout << "Please input the postfix expression : ";
  getline(std::cin, input);
  std::cout << std::endl;

  //Token array
  std::string tokens[10] = "end";
  int iterator = 0;

  //Character read and token string Variable
  //NOTE: We initialize token because we will be using +=
  std::string token = "";
  char c;

  //Add space to the end of input so that it counts the last token
  input += " ";

  //Tokenize the input
  for (int i = 0; i <= input.length(); i++) {

    //Get the character in input
    c = input[i];

    if(c == ' ') {
      tokens[iterator] = token;
      iterator++;

      //Reset token
      token = "";

    } else {
      token += c;

    }
  }

  //Variable for size type and string
  std::size_t sz;
  std::string str;

    for(int i = 0; i <= 10; i++) {

      if (tokens[i] == "+" || tokens[i] == "-"|| tokens[i] == "/"|| tokens[i] == "*") { //Check if its an operator
        //Call the calculating function with a pointer to
        //the postfixStack
        popCalc(tokens[i], &postfixStack);

      } else if (tokens[i] == "end") {

        std::cout << "In end part" << std::endl;

        return postfixStack.top();

      } else {
        //Convert the number to a double from a string
        //Store the token in string
        str = tokens[i];
        std::cout << "String " + str << std::endl;
        std::stringstream ss;
        ss << str;
        double converted;
        ss >> converted;
        std::cout << converted << std::endl;


        //Push the number into the stack
        postfixStack.push(converted);
      }

    }



  return postfixStack.top();
}

void popCalc(std::string str, std::stack<double>* postfixStack) {
  //Operands
  double operand1;
  double operand2;

  //NOTE: I'll have to test out this system while dividing as it might take the operands int the wrong order

  //Read and pop out the Operands
  operand1 = postfixStack->top();
  operand2 = postfixStack->top();
  std::cout << "Operands ";
  std::cout << operand1 << std::endl << operand2 << std::endl;
  postfixStack->pop();
  postfixStack->pop();

  //Store the result
  double result;

  //Determine what operation to do
  if (str.size() == 1) {
    //Convert str to character
    char op = str[0];

    switch (op) {
      case '+': {
        std::cout << "In case '+'" << std::endl;
        result = operand1 + operand2;
        break;
      }

      case '-': {
        result = operand1 - operand2;
        break;
      }

      case '*': {
        result = operand1 * operand2;
        break;
      }

      case '/': {
        result = operand1 / operand2;
        break;
      }
    }
  }


  //Push the result in the postfixStack
  postfixStack->push(result);

}
