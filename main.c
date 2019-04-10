#include <stdio.h>



int main()  {
    char originalText[] = "abcdefghijklmnopqrstuvwxyz  aBcD gf\0hjh";
    int stringLength = strlen(originalText)
    char capitalText[stringLength];
    int i;
    
    
// Converts any lower case letters to capital
    for(i = 0; i < strlen(originalText); i++)  {
        if(originalText[i] >= 97 && originalText[i] <= 122) {
            capitalText[i] = originalText[i] - 32;
        }
        else  {
            capitalText[i] = originalText[i];
        }    
    }
    
   
// Function to determine rotation
    for(i = 0; i <= /*string legth*/; i++)  {
    //use a switch to add up different letters then determine most common
    //then do rotation function
    //then do spell check function
    //if this doesnt make sense use second most common term, then 3rd
}


// Function to change character in rotation cipher

for(i = 0; i <= stringLength; i++)  {
    if(/*ASCII code*/ >= 41 && /*ASCII code*/ <= 90 && ...)    {   //if code is a capital letter AND code plus rotation amount is still in range
        /*ASCII code*/ = /*ASCII code*/ + rotationNumber
    }
    else if (//its a capital and it plus rotation goes out of range) {  //BUT if this takes it outside of the range it must then be reduced by 26?
        code = code + change - 26
    }
then print new text
        
        
    }
}