/******************************************************************************

   Tyler Hull
   p622s636
   
      Program 7
      
   Description of problem:
      This program will allow the user to convert a non negative integer into
      a binary and octal number. It will utilize a stack to do the actual
      conversion
*/

#include <forward_list>
#include <iostream>
using namespace std;


int main(void)
{
   forward_list<int> intlist;
   forward_list<int>::iterator intlist_itr;
   int data[] = {17,9,33,83,21};
   
   intlist.push_front(17);
   for (int i = 0; i <= 4; i++)
   {
      intlist_itr = intlist.begin();
      
      while (intlist_itr != NULL && *intlist_itr <= data[i])
         intlist_itr++;
   
      if (intlist_itr == NULL)
      {
         intlist.push_back(data[i])
      }
      else
      {
         intlist.insert(intlist_itr, data[i])
      }
   }
   
   intlist_itr = intlist.begin();
   while (instlist_itr != NULL)
   {
      cout << *intlist_itr << endl;
      intlist_itr++;
   }
}