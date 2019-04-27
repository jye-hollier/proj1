#include <stdio.h>
#include <string.h>

void taskOne(void)  {
    
    char originalText[] =  "THIS IS A STRING. A VERY LONG STRING (SORT OF) THAT DOESNT REALLY SAY MUCH (with some lower case to test)";
    
    //char originalText[1000];
    int key;
    
    //printf("Please enter text to be encrypted:\n");
    //scanf("%[^\n]%*c", originalText);
    
    printf("Please enter the rotation key number to be used:\n#");
    scanf("%d", &key);
    
    int stringLength = strlen(originalText);
    char encryptedText[stringLength];
    int i;
    
    for(i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            encryptedText[i] = (((originalText[i] - 65) + key) %26 ) + 65;
        }
        else
            encryptedText[i] = originalText[i];
    }
    
    printf("Encrypted text:\n%s\n\n", encryptedText);
    
}
