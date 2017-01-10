#include <iostream>
#include <stack>

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
  std::string tokens[10];
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

      //Check if the character is a space
      if (tokens[i] == " ") {
        //Start back at the top of the loop
        continue;
      } else if (tokens[i] == "+" || tokens[i] == "-"|| tokens[i] == "/"|| tokens[i] == "*") { //Check if its an operator
        //Call the calculating function with a pointer to
        //the postfixStack
        popCalc(tokens[i], &postfixStack);
      } else {
        //Convert the number to a double from a string
        //Store the token in string
        str = token[i];

        double converted = Double.parseDouble(str);

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
