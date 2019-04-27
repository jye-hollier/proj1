#include <stdio.h>
#include <string.h>

void taskTwo(void)  {
    char originalText[] =  "YMNX NX F XYWNSL. F AJWD QTSL XYWNSL (XTWY TK) YMFY ITJXSY WJFQQD XFD RZHM (with some lower case to test)";
    
    //printf("Enter text to be encrypted\n\n")
    //char originalText[1000];
    //scanf("%[^\n]%*c", originalText);
    
    int key;// = 4;
    
    printf("Please enter the rotation key number used:\n#");
    scanf("%d", key);
    
    int stringLength = strlen(originalText);
    char decryptedText[stringLength];
    int i;
    
    for(i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            decryptedText[i] = (((originalText[i] - 39) - key) %26 ) + 65;
        }
        else
            decryptedText[i] = originalText[i];
    }
    
    printf("\n\nDecrypted text:\n%s\n\n", decryptedText);
}
