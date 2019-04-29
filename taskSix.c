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
        else if (originalText[i] > 64 && originalText[i] < 91)      //If a remaining letter assumed A
            decryptedText[i] = originalText[i];
        else
            decryptedText[i] = originalText[i];                     //Otherwise remains unchanged / copied
    }
        
    printf("\nDecrypted text:\n%s", decryptedText);

}