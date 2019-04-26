/*This function takes the string and counts each letter. 
    After processing these amounts it will return the most letters assignment (i.e. a = 0, b = 1 etc.)
    When called first it will return the most commmon letter, then following attempts n will recieve the 
    nth most common letter (up to 3)*/


#include<stdio.h>
#include<string.h>

main()  {

    char originalText[] =  "THIS IS A STRING A VEERY LONFJNKSXZNCDJKNVCDJNCSJNCKA";
    int stringLength = strlen(originalText);
    char letterCount[26];
    int firstCommon = 0;
    int firstCommonAmount = 0;
    int secondCommon = 0;
    int secondCommonAmount = 0;
    int thirdCommon = 0;
    int thirdCommonAmount = 0;
    int i;
    static int attempt = 0;
    
    attempt++;
    
    for(i = 0; i < 26; i++)  {
        letterCount[i] = 0;
    }

    for(i = 0; i < stringLength; i++)  {
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
    
    for(i = 0; i < 26; i++)    {
        printf("\n%d  %d", i, letterCount[i]);
    }

    for(i = 0; i < 26; i++)    {
        if(letterCount[i] >= firstCommonAmount)  {
            thirdCommon = secondCommon;
            secondCommon = firstCommon;
            firstCommon = i;
            thirdCommonAmount = secondCommonAmount;
            secondCommonAmount = firstCommonAmount;
            firstCommonAmount = letterCount[i];
        }
        else if (letterCount[i] < firstCommonAmount && letterCount[i] >= secondCommonAmount) {
            thirdCommon = secondCommon;
            secondCommon = i;
            thirdCommonAmount = secondCommonAmount;
            secondCommonAmount = letterCount[i];
        }
        else if(letterCount[i] < secondCommonAmount && letterCount[i] >= thirdCommonAmount) {
            thirdCommon = i;
            thirdCommonAmount = letterCount[i];
        }             
    }
    
    switch (attempt)  {
        case 1: return firstCommon;
                break;
        case 2: return secondCommon;
                break;
        case 3: return thirdCommon;
                break;
    }
    
}