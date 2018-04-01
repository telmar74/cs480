/******************************************************************************

   Tyler Hull
   p622s636
   
      Program 3
      
   Description of problem:
      This program tests the Fraction class created in fraction.cpp/.hpp.
      It will prompt for user input to create an initial fraction. Then provide
      menu options to add, subtract, multiply, divide, get the decimal
      equivalent, or reduce to lowest terms.
*/

#include "fraction.cpp"
#include <iostream>
using namespace std;

// Main menu to give user choices to perform on a fraction
// Proconditions: none
// Postconditions: returns an integer corresponding to one of the menu
// choices
int main_menu (void);

// User prompts to create a fraction by providing numerator and denominator.
// Proconditions: none
// Postconditions: Returns a fraction without 0 in the numerator or
// denomintator, and a non negative denominator.
Fraction user_fraction (void);

// User prompts to enter an operator to perform on a fraction
// Preconditions: none
// Postcondidtions: Returns a char holding the operator
char user_operator (void);

// Displays the result of math performed on two fractions
// Preconditions: none
// Postconditions: Will display both operands, operator and the result
void print_results (char oper, Fraction op1, Fraction op2, Fraction reslt);

int main (void)
{
   Fraction result, operand1, operand2;
   int menu_selection; // holds user menu selection
   
   // Program information
   cout << "This program performs basic operations on fractions.\n\n";
   
   // Get initial fraction
   cout << "Please enter an initial fraction to work on.\n";
   operand1 = user_fraction();
   
   // Main menu
   do
   {
      // Display initial fraction then print menu and get selection
      cout << "\nYour fraction is ";
      operand1.Print();
      cout << endl;
      menu_selection = main_menu();
      
      // Perform action based on selection
      switch (menu_selection)
      {
         case 1:
            cout << "\nEnter the second operand.\n";
            operand2 = user_fraction();
            result = operand1 + operand2;
            print_results('+', operand1, operand2, result);
            operand1 = result;
            break;
         case 2:
            cout << "\nEnter the second operand.\n";
            operand2 = user_fraction();
            result = operand1 - operand2;
            print_results('-', operand1, operand2, result);
            operand1 = result;
            break;
         case 3:
         cout << "\nEnter the second operand.\n";
            operand2 = user_fraction();
            result = operand1 * operand2;
            print_results('*', operand1, operand2, result);
            operand1 = result;
            break;
         case 4:
            cout << "\nEnter the second operand.\n";
            operand2 = user_fraction();
            result = operand1 / operand2;
            print_results('/', operand1, operand2, result);
            operand1 = result;
            break;
         case 5:
            // double dec_equ;
            // dec_equ = operand1.Double_value();
            cout << "\n The decimal equivalent of ";
            operand1.Print();
            cout << " is " << operand1.Double_value();
            cout << endl << endl;
            break;
         case 6:
            cout << "\n Your fraction ";
            operand1.Print();
            cout << " has been reduced to ";
            operand1 = operand1.Lowest_term();
            operand1.Print();
            cout << endl << endl;
            break;
      }
      
   }
   while (menu_selection != 7);
   
   return 0;
}

int main_menu (void)
{
   int selection; // user entered menu selection
   
   // Output menu and get selection
   do
   {
      cout << "What would you like to do with your fraction?\n"
           << " 1 - Add another fraction to it\n"
           << " 2 - Subtract another fraction from it\n"
           << " 3 - Multiply it with another fraction\n"
           << " 4 - Divide it by another fraction\n"
           << " 5 - Display the decimal equilvalent\n"
           << " 6 - Reduce the fraction to lowest terms\n"
           << " 7 - Quit\n"
           << "Enter your choice: ";
      cin >> selection;
   }
   while (selection < 1 || selection > 7);
   
   return selection;
}

Fraction user_fraction (void)
{
   int numer, denom;
   
   // Get numerator
   do
   {
      cout << "  Enter a non-zero integer for the numerator: ";
      cin >> numer;
   }
   while (numer == 0);
   
   // Get denominator
   do
   {
      cout << "  Enter a non-zero non-negative integer for the denominator: ";
      cin >> denom;
   }
   while (denom <= 0);
   
   // create and return fraction
   Fraction user_created(numer, denom);
   return user_created;   
}

char user_operator (void)
{
   char oper; // user entered operator
   
   // Get operator +,-,*,/ only
   do
   {
      cout << "\nAvailable operations:\n"
        << "+, -, *, /\n"
        << "Please enter the operation you would like to perform: ";
      cin >> oper;
      if (!(oper == '+' || oper == '-' || oper == '*' || oper == '/'))
      {
         cout << "Invalid choice, please select from the available"
              << " options.\n";
      }
   }
   while (!(oper == '+' || oper == '-' || oper == '*' || oper == '/'));
   
   return oper;
}

void print_results (char oper, Fraction op1, Fraction op2, Fraction reslt)
{
   cout << "\nThe results are:\n\n";
   op1.Print();
   cout << " " << oper << " ";
   op2.Print();
   cout << " = ";
   reslt.Print();
   cout << endl;
   
   return;
}