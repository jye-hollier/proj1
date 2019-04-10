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
            case 65:    letterCount[0]++;
                        break;
            case 66:    letterCount[1]++;
                        break;
            case 67:    letterCount[2]++;
                        break;
            case 68:    letterCount[3]++;
                        break;
            case 69:    letterCount[4]++;
                        break;
            case 70:    letterCount[5]++;
                        break;
            case 71:    letterCount[6]++;
                        break;
            case 72:    letterCount[7]++;
                        break;
            case 73:    letterCount[8]++;
                        break;
            case 74:    letterCount[9]++;
                        break;
            case 75:    letterCount[10]++;
                        break;
            case 76:    letterCount[11]++;
                        break;
            case 77:    letterCount[12]++;
                        break;
            case 78:    letterCount[13]++;
                        break;
            case 79:    letterCount[14]++;
                        break;
            case 80:    letterCount[15]++;
                        break;
            case 81:    letterCount[16]++;
                        break;
            case 82:    letterCount[17]++;
                        break;
            case 83:    letterCount[18]++;
                        break;
            case 84:    letterCount[19]++;
                        break;
            case 85:    letterCount[20]++;
                        break;
            case 86:    letterCount[21]++;
                        break;
            case 87:    letterCount[22]++;
                        break;
            case 88:    letterCount[23]++;
                        break;
            case 89:    letterCount[24]++;
                        break;
            case 90:    letterCount[25]++;
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