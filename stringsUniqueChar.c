#include <stdio.h>
#include <stdbool.h>

bool isUniqueChars(char * str)
{
     int i, value;
     int  checker = 0;
     bool rc = true;

     for (i = 0; i < sizeof(str) ; i++) {
          value = str[i] - 'a';
          printf ("%d \n", value);
          if (( checker & (1 << value)) > 0) {
              printf ("%s Nounique: \n","False");
              rc = false;
              break;
          }
          checker |= (1 << value);
          printf ("%d checker: \n", checker);
     }
     if (true == rc){
        printf ("%s unique: \n", "True");
     }
     checker = 0; 
     return rc; 
 }

int main()
{

    bool unique, unique2;      

    unique = isUniqueChars("helloword");
    unique2 = isUniqueChars("abcdef");
}
