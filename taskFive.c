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