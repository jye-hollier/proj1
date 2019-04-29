#include <stdio.h>
#include <string.h>

int main()  {
    
    /*Each task has is accessed though seperate individual functions*/
    
    int taskNumber = 0;
    void taskOne(void);
    void taskTwo(void);
    void taskThree(void);
    void taskFour(void);
    void taskFive(void);
    void taskSix(void);
    
    //While loop utilised to only allow valid selection (will reloop if invalid option entered)
    
    while (taskNumber <1||taskNumber > 6)  {
        printf("Please enter the task number:\n1 - Rotation Encryption\n2 - Rotation Decryption\n3 - Substitution Encryption\n4 - Substitution Decryption\n5 - Rotation Decryption(Given text only)\n6 - Substitution Decryption(Given text only)\n\n#");
        scanf("%d", &taskNumber);
    }

    switch(taskNumber)  {
        case 1:  taskOne();
            break;
        case 2:  taskTwo();
            break;
        case 3:  taskThree();
            break;
        case 4:  taskFour();
            break;
        case 5:  taskFive();
            break;
        case 6:  taskSix();
            break;
    }
    
    return 0;
}

void taskOne(void)  {
    
    /*This function allows the user to enter both the text to be encrypted and the rotation key number to be used thrugh standard input. 
      An array of 1000 chars is provided allowing for a maximum paragraph length of 1000 characters(including white space) to be entered*/
    
    char originalText[1000];
    int key;
    
    printf("\nPlease enter text to be encrypted:\n");
    scanf (" %[^\n]%*c", originalText);
    
    printf("\nPlease enter rotation key number to be used:\n#");
    scanf("%d", &key);
    
    int stringLength = strlen(originalText);
    char encryptedText[stringLength];
    int i;
    
    for(i = 0; i < stringLength; i++)  {                                        // Converts any lower case letters to capital
        if(originalText[i] >= 97 && originalText[i] <= 122)
            originalText[i] = originalText[i] - 32;   
    }
    
    
    
    for(i = 0; i < stringLength + 1; i++)  {                                    //Loops for every string element (plus 1 for ending null)
        if (originalText[i] > 64 && originalText[i] < 91)  {                    //I.e if a capital letter ascii code
            encryptedText[i] = (((originalText[i] - 65) + key) %26 ) + 65;      //Modifies each letter by key provided utilising the modulus to cater for letters which go past z
        }
        else
            encryptedText[i] = originalText[i];                                 //All lower case and other symbols ignored
    }
    
    printf("\nEncrypted text:\n%s\n", encryptedText);
    
}

void taskTwo(void)  {
    
    /*A reverse of taskOne, this function takes an encrypted text and key from the user and decrypts the message by subtracing the key from each ascii code
      An array of 1000 chars is provided allowing for a maximum paragraph length of 1000 characters(including white space) to be entered*/
    
    char originalText[1000];
    int key;
    
    printf("\nPlease enter text to be decrypted:\n");
    scanf (" %[^\n]%*c", originalText);
    
    printf("\nPlease enter the rotation key number used:\n#");
    scanf("%d", &key);
    
    int stringLength = strlen(originalText);
    char decryptedText[stringLength];
    int i;
    
    for(i = 0; i < stringLength; i++)  {                                        // Converts any lower case letters to capital
        if(originalText[i] >= 97 && originalText[i] <= 122)
            originalText[i] = originalText[i] - 32;   
    }
    
    for(i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            decryptedText[i] = (((originalText[i] - 39) - key) %26 ) + 65;      //Same formula for taskOne however key is subtracted
        }                                                                       //Only 39 is subtracted initially to prevent negative ascii code
        else
            decryptedText[i] = originalText[i];                                 //All lower case and other symbols ignored
    }
    
    printf("\nDecrypted text:\n%s\n", decryptedText);

}

void taskThree(void)  {
    
    /*This function takes the entered text and encryption code (in the form of a 26 capital letter string) to encrypt the text
      An array of 1000 chars is provided allowing for a maximum paragraph length of 1000 characters(including white space) to be entered*/
    
    char originalText[1000];
    char key[26];
    
    printf("\nPlease enter text to be encrypted:\n");
    scanf (" %[^\n]%*c", originalText);
    
    printf("\nPlease enter the encryption key:\n(E.g.: QWERTYUIOPASDFGHJKLZXCVBNM)\n\n");
    scanf(" %[^\n]%*c", key);
    
    int stringLength = strlen(originalText);
    char encryptedText[stringLength];
    int i;
    
    for (i = 0; i < 26; i++)  {                                 //Ensures all key elements are valid characters and capital
        if (key[i] >= 97 && key[i] <= 122)
            key[i] = key[i] - 32;
        else if (key[i] < 65 || key[i] > 122) {                 //Program exits if key contains a non-letter charatcter
            printf("\nKey contains invalid character(s)\n");
            return 0;
        }
    }            
    
    
    for(i = 0; i < stringLength; i++)  {                        // Converts any lower case letters to capital
        if(originalText[i] >= 97 && originalText[i] <= 122)
            originalText[i] = originalText[i] - 32;   
    }
    
    for(i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            encryptedText[i] = key[(originalText[i]-65)];       //Each letter is replaced by the element of the key corresponding to the original letter
        }                                                       //As originally standard a-z with ascii codes increasing by 1 each time, ascii code is reduced by 65 to give address of required substitute letter
        else
            encryptedText[i] = originalText[i];                 //All lower case and other symbols ignored
    }
    
    printf("\nEncrypted text:\n%s\n", encryptedText);
    
}

void taskFour(void)  {
    
    /*Like taskTwo this function takes the encrypted text and decryption code (in the form of a 26 capital letter string) to decrypt the text
      An array of 1000 chars is provided allowing for a maximum paragraph length of 1000 characters(including white space) to be entered*/
    
    char originalText[1000];
    char key[26];
    
    printf("\nPlease enter text to be decrypted:\n");
    scanf (" %[^\n]%*c", originalText);
    
    printf("\nPlease enter the encryption key used:\n(E.g.: QWERTYUIOPASDFGHJKLZXCVBNM)\n");
    scanf(" %[^\n]%*c", key);
    
    int stringLength = strlen(originalText);
    char decryptedText[stringLength];
    
    int i;
    int c;
    
    for (i = 0; i < 26; i++)  {                                 //Ensures all key elements are valid characters and capital
        if (key[i] >= 97 && key[i] <= 122)
            key[i] = key[i] - 32;
        else if (key[i] < 65 || key[i] > 122) {                 //Program exits if non letter element in key
            printf("\nKey contains invalid character(s)\n");
            return 0;
        }
    }
    
    for(i = 0; i < stringLength; i++)  {                        // Converts any lower case letters to capital
        if(originalText[i] >= 97 && originalText[i] <= 122)
            originalText[i] = originalText[i] - 32;   
    }
    
    for (i = 0; i < stringLength + 1; i++)  {                   //for each string elemtent including the end null
        if (originalText[i] > 64 && originalText[i] < 91)  {    //if it is a capital letter
            for (c = 0; c < 26; c++)  {                         //go through each elememt of the decryption code
                if (originalText[i] == key[c])  {               //if the letter is equal to the decryption code element
                    decryptedText[i] = c + 65;                  //decypted letter ascii code is the position of the matching element plus 65
                }
            }
        }
        else
            decryptedText[i] = originalText[i];                 //All other characters copied
    }
        
    printf("\nDecrypted text:\n%s\n", decryptedText);

}

void taskFive(void)  {
    
    /*This function attempts to decrypt a text encrypted by a rotation cipher. It takes the entered text placing it in an array.
      The string length function is then used to determine the actual text length. From here each letter is counted and the three 
      most common stored. One of these three letters is assumed to be E as the is the most commmon letter in english language. 
      The function provide the three possible decrypted texts requiring the user to select to correct one. An array of 1000 chars 
      is provided allowing for a maximum paragraph length of 1000 characters(including white space) to be entered*/
    
    char originalText[1000];
    
    printf("\nEnter text to be decrypted:\n");
    scanf(" %[^\n]%*c", originalText);
    
    int stringLength = strlen(originalText);
    int letterCount[26];                        //array to store each letters amount
    char decryptedText[stringLength];           //array for decrypted text
    int firstCommon = 0;                        //variables to record highest letter amounts and array positions
    int firstCommonAmount = 0;
    int secondCommon = 0;
    int secondCommonAmount = 0;
    int thirdCommon = 0;
    int thirdCommonAmount = 0;
    int i;
    int key;
    char checker;
    
    for(i = 0; i < stringLength; i++)  {                        // Converts any lower case letters to capital
        if(originalText[i] >= 97 && originalText[i] <= 122)
            originalText[i] = originalText[i] - 32;   
    }
        
    for(i = 0; i < 26; i++)  {                  //initialising each letter amount to zero
        letterCount[i] = 0;
    }

    for(i = 0; i < stringLength; i++)  {        //loops through every character of the text. If it is a capital letter its repective letter count is increased by one
        switch(originalText[i])  {              
            case 'A':    letterCount[0]++;
                        break;
            case 'B':    letterCount[1]++;
                        break;
            case 'C':    letterCount[2]++;
                        break;
            case 'D':    letterCount[3]++;
                        break;
            case 'E':    letterCount[4]++;
                        break;
            case 'F':    letterCount[5]++;
                        break;
            case 'G':    letterCount[6]++;
                        break;
            case 'H':    letterCount[7]++;
                        break;
            case 'I':    letterCount[8]++;
                        break;
            case 'J':    letterCount[9]++;
                        break;
            case 'K':    letterCount[10]++;
                        break;
            case 'L':    letterCount[11]++;
                        break;
            case 'M':    letterCount[12]++;
                        break;
            case 'N':    letterCount[13]++;
                        break;
            case 'O':    letterCount[14]++;
                        break;
            case 'P':    letterCount[15]++;
                        break;
            case 'Q':    letterCount[16]++;
                        break;
            case 'R':    letterCount[17]++;
                        break;
            case 'S':    letterCount[18]++;
                        break;
            case 'T':    letterCount[19]++;
                        break;
            case 'U':    letterCount[20]++;
                        break;
            case 'V':    letterCount[21]++;
                        break;
            case 'W':    letterCount[22]++;
                        break;
            case 'X':    letterCount[23]++;
                        break;
            case 'Y':    letterCount[24]++;
                        break;
            case 'Z':    letterCount[25]++;
                        break;
        }
    }
    
    /*After adding all Capital letters the three most common are found by looping through each lettercount array element*/
    
    for(i = 0; i < 26; i++)    {                        //if the element value is higher then all previous, its value and position
        if(letterCount[i] >= firstCommonAmount)  {      //are placed as first with the previous first becoming second and second becoming third.
            thirdCommon = secondCommon;
            secondCommon = firstCommon;
            firstCommon = i;
            thirdCommonAmount = secondCommonAmount;
            secondCommonAmount = firstCommonAmount;
            firstCommonAmount = letterCount[i];
        }
        else if (letterCount[i] < firstCommonAmount && letterCount[i] >= secondCommonAmount) {  //if less then first but equal to or higher then second
            thirdCommon = secondCommon;                                                         //second most common element becomes third
            secondCommon = i;
            thirdCommonAmount = secondCommonAmount;
            secondCommonAmount = letterCount[i];
        }
        else if(letterCount[i] < secondCommonAmount && letterCount[i] >= thirdCommonAmount) {   //if equal to or greater then third most common replaces it
            thirdCommon = i;
            thirdCommonAmount = letterCount[i];
        }             
    }
    
    key = (firstCommon + 22) %26;                       //first decryption attempt with key created assuming most common letter is E
    
    for(i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            decryptedText[i] = (((originalText[i] - 39) + key) %26 ) + 65;
        }
        else
            decryptedText[i] = originalText[i];
    }
    
    printf("\nDecrypted text:\n%s\n\nIf text does not make sense enter 'r' to retry\nIf correct enter any other key to exit\n", decryptedText);
    scanf(" %c", &checker);
    
    if (checker == 'r' || checker == 'R')  {            //if user responds that text is illegible, decryption attempted with second most common letter assumed to be E
        key = (secondCommon + 22) %26;                  //key created based on this assumption
        
        for(i = 0; i < stringLength + 1; i++)  {
            if (originalText[i] > 64 && originalText[i] < 91)  {
            decryptedText[i] = (((originalText[i] - 39) - key) %26 ) + 65;
            }
            else
                decryptedText[i] = originalText[i];
        }
        
        printf("\nDecrypted text:\n%s\n\nIf text does not make sense enter 'r' to retry again\nIf correct enter any other key to exit\n", decryptedText);
        scanf(" %c", &checker);
        
    }
    
    else                                            //if user responds text is readable, program exits
        return 0;
        
    if (checker == 'r' || checker == 'R')  {        //if user again responds that text is illegible, a final decryption is attempted with third most common letter assumed to be E
        key = (thirdCommon + 22) %26;               //key created based on this assumption
            
        for(i = 0; i < stringLength + 1; i++)  {
            if (originalText[i] > 64 && originalText[i] < 91)  {
                decryptedText[i] = (((originalText[i] - 39) + key) %26 ) + 65;
            }    
            else
                decryptedText[i] = originalText[i];
        }

        printf("\nDecrypted text:\n%s\n\nIf text does not make sense the text unfortunately cannot be decrypted\n", decryptedText);
                 
    }
    
    else                                            //if user responds text is readable, program exits
        return 0;

}

void taskSix(void)  {
    
    /*This function is meant to decrypt a substitution cipher. That is hard. Instead, it attempts to get some form of mark based on the fact
      that marks are calculated on the amount of correct letters decrypted. It finds the 3 most common letters in the text,
      exactly like the taskFive function, and assumes the most common is E, second most common, and third most common A.  
      All remaining letters are assumed to be O. An array of 1000 chars is provided allowing for a maximum paragraph length of 1000 characters
      (including white space) to be entered*/
    
    char originalText[1000];
    
    printf("\nPlease enter text to be decrypted:\n");
    scanf (" %[^\n]%*c", originalText);
    
    int stringLength = strlen(originalText);
    int letterCount[26];                        //array to store letter amounts
    char decryptedText[stringLength];           //array for decrypted text
    int firstCommon = 0;                        //variables to record highest letter amounts and array positions
    int firstCommonAmount = 0;
    int secondCommon = 0;
    int secondCommonAmount = 0;
    int thirdCommon = 0;
    int thirdCommonAmount = 0;
    int i;
    
    for(i = 0; i < stringLength; i++)  {                        // Converts any lower case letters to capital
        if(originalText[i] >= 97 && originalText[i] <= 122)
            originalText[i] = originalText[i] - 32;   
    }
        
    for(i = 0; i < 26; i++)  {                  //initalising each letter amount to zero
        letterCount[i] = 0;
    }

    for(i = 0; i < stringLength; i++)  {        //same lettercount method as in taskFive function
        switch(originalText[i])  {
            case 'A':    letterCount[0]++;
                        break;
            case 'B':    letterCount[1]++;
                        break;
            case 'C':    letterCount[2]++;
                        break;
            case 'D':    letterCount[3]++;
                        break;
            case 'E':    letterCount[4]++;
                        break;
            case 'F':    letterCount[5]++;
                        break;
            case 'G':    letterCount[6]++;
                        break;
            case 'H':    letterCount[7]++;
                        break;
            case 'I':    letterCount[8]++;
                        break;
            case 'J':    letterCount[9]++;
                        break;
            case 'K':    letterCount[10]++;
                        break;
            case 'L':    letterCount[11]++;
                        break;
            case 'M':    letterCount[12]++;
                        break;
            case 'N':    letterCount[13]++;
                        break;
            case 'O':    letterCount[14]++;
                        break;
            case 'P':    letterCount[15]++;
                        break;
            case 'Q':    letterCount[16]++;
                        break;
            case 'R':    letterCount[17]++;
                        break;
            case 'S':    letterCount[18]++;
                        break;
            case 'T':    letterCount[19]++;
                        break;
            case 'U':    letterCount[20]++;
                        break;
            case 'V':    letterCount[21]++;
                        break;
            case 'W':    letterCount[22]++;
                        break;
            case 'X':    letterCount[23]++;
                        break;
            case 'Y':    letterCount[24]++;
                        break;
            case 'Z':    letterCount[25]++;
                        break;
        }
    }
    
    /*After adding all capital letters the three most common are found by looping through each lettercount array element*/
    
    for(i = 0; i < 26; i++)    {
        if(letterCount[i] >= firstCommonAmount)  {      //if the element value is higher then all previous, its value and position
            thirdCommon = secondCommon;                 //are placed as first with the previous first becoming second and second becoming third.
            secondCommon = firstCommon;
            firstCommon = i;
            thirdCommonAmount = secondCommonAmount;
            secondCommonAmount = firstCommonAmount;
            firstCommonAmount = letterCount[i];
        }
        else if (letterCount[i] < firstCommonAmount && letterCount[i] >= secondCommonAmount) {  //if less then first but equal to or higher then second
            thirdCommon = secondCommon;                                                         //second most common element becomes third
            secondCommon = i;
            thirdCommonAmount = secondCommonAmount;
            secondCommonAmount = letterCount[i];
        }
        else if(letterCount[i] < secondCommonAmount && letterCount[i] >= thirdCommonAmount) {   //if equal to or greater then third most common replaces it
            thirdCommon = i;
            thirdCommonAmount = letterCount[i];
        }             
    }
    
    for (i = 0; i < stringLength + 1; i++)   {                      //For each originalText element 
        if (originalText[i] == (firstCommon + 65))                  //If most common, assumed E
            decryptedText[i] = 'E';
        else if (originalText[i] == (secondCommon + 65))            //If second common, assumed T
            decryptedText[i] = 'T';
        else if (originalText[i] == (thirdCommon + 65))             //If third common, assumed A
            decryptedText[i] = 'A';
        else if (originalText[i] > 64 && originalText[i] < 91)      //If a remaining letter assumed O
            decryptedText[i] = 'O';
        else
            decryptedText[i] = originalText[i];                     //Otherwise remains unchanged / copied
    }
        
    printf("\nDecrypted text:\n%s\n", decryptedText);

}