#include <stdio.h>
#include <string.h>

void taskFour(void)  {
    char originalText[] =  "ZIOL OL Q LZKOFU. Q CTKN SGFU LZKOFU (LGKZ GY) ZIQZ RGTLFZ KTQSSN LQN DXEI (with some lower case to test";
    
    //printf
    //char originalText[1000];
    //scanf("%[^\n]%*c", originalText);
    
    int stringLength = strlen(originalText);
    char decryptedText[stringLength];
    int i;
    int c;
    
    char key[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    
    for(c=0;c<stringLength;c++)  {
        printf("%d\n", originalText[c]);
    }
        
    for (i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {        //if a capital letter
            for (c = 0; c < 26; c++)  {
                if (originalText[i] == key[c])  {
                    decryptedText[i] = c + 65;
                }
            }
        }
        else
            decryptedText[i] = originalText[i];
    }
        
    for(c=0;c<stringLength;c++)  {
        printf("%d\n", decryptedText[c]);
    }  
    
    printf("Decrypted text:\n%s", decryptedText);
    
}