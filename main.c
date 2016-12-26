#include <stdio.h>

//Function prototypes
char *getExpression();
void parse(char *expression);

//Function : Call the different functions needed
//to analyze and calculate the expression
int main() {

  char *expression = getExpression();

  parse(expression);

  return 0;
}

//Function : Gets the expression
//from the user
char *getExpression() {
  //Request the expression to be calculated
  printf("Please enter the expression you wish to calculate\n");
  printf("\n");

  //Get the input
  char input[100];
  fgets(input, 100, stdin);

  //Return the buffer
  return input;
}

void parse(char *expression) {
    
  printf("DEBUG\n"); //DEBUG

  //Get the input
  char input[100]; //DEBUG
  fgets(input, 100, stdin); //DEBUG

  return;
}
