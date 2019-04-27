#include <stdio.h>
#include <string.h>

void taskFive(void)  {
    
    char originalText[] =  "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU.";
    //char originalText[1000];
    //printf("Enter text to be decrypted\n\n");
    //scanf("%[^\n]%*c", originalText);
    
    int stringLength = strlen(originalText);
    int letterCount[26];
    char decryptedText[stringLength];
    int firstCommon = 0;
    int firstCommonAmount = 0;
    int secondCommon = 0;
    int secondCommonAmount = 0;
    int thirdCommon = 0;
    int thirdCommonAmount = 0;
    int i;
    int key;
    char checker;
    //static int attempt = 0;
    
    //attempt++;
    
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
    
    key = (firstCommon + 22) %26;
    
    for(i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            decryptedText[i] = (((originalText[i] - 39) + key) %26 ) + 65;
        }
        else
            decryptedText[i] = originalText[i];
    }
    
    printf("Decrypted text:\n%s\n\nIf this text does not make sense enter 'r' to retry\nIf correct enter any other to exit\n", decryptedText);
    scanf("%c", &checker);
    
    if (checker == 'r' || checker == 'R')  {
        key = (secondCommon + 22) %26;
        
        for(i = 0; i < stringLength + 1; i++)  {
            if (originalText[i] > 64 && originalText[i] < 91)  {
            decryptedText[i] = (((originalText[i] - 39) - key) %26 ) + 65;
            }
            else
                decryptedText[i] = originalText[i];
        }
        
        printf("Decrypted text:\n%s\n\nIf text does not make sense enter 'r' to retry again\nIf correct enter any other key to exit\n", decryptedText);
        scanf("%c", &checker);
        
        if (checker == 'r' || checker == 'R')  {
            key = (thirdCommon + 22) %26;
            
            for(i = 0; i < stringLength + 1; i++)  {
                if (originalText[i] > 64 && originalText[i] < 91)  {
                    decryptedText[i] = (((originalText[i] - 39) + key) %26 ) + 65;
                }    
                else
                        decryptedText[i] = originalText[i];
            }

            printf("Decrypted text:\n%s\n\nIf text does not make sense the text unfortunately cannot be decrypted\n", decryptedText);
            scanf("%c", &checker);            
        }    
    }
}

