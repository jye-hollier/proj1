#include <stdio.h>
#include <string.h>

void taskThree(void)  {
    char originalText[] =  "THIS IS A STRING. A VERY LONG STRING (SORT OF) THAT DOESNT REALLY SAY MUCH (with some lower case to test)";
    
    //printf
    //char originalText[1000];
    //scanf("%[^\n]%*c", originalText);
    
    int stringLength = strlen(originalText);
    char encryptedText[stringLength];
    
    char key[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    
    //printf("Enter 26 letter key string in capitals\nE.g.: QWERTYUIOPASDFGHJKLZXCVBNM\n\n");
    //scanf("%[^\n]%*c", key);
    
    int i;
    
    for(i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            encryptedText[i] = key[(originalText[i]-65)];
        }
        else
            encryptedText[i] = originalText[i];
    }
    
    printf("Encrypted text:\n%s\n\n", encryptedText);
    
}
