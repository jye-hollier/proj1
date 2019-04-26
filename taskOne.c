// gets a string from standard input
//   
  
void taskOne(void)  {
    char originalText[] =  "THIS IS A STRING. A VERY LONG STRING (SORT OF) THAT DOESNT REALLY SAY MUCH (with some lower case to test)";
    
    //char originalText[1000];
    //scanf("%[^\n]%*c", originalText);
    
    int stringLength = strlen(originalText);
    char encryptedText[stringLength];
    int key = 4;
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