void taskThree(void)  {
    
    char originalText[1000];
    char key[26];
    
    printf("\nPlease enter text to be encrypted:\n");
    scanf (" %[^\n]%*c", originalText);
    
    printf("\nPlease enter the encryption key in capitals:\n(E.g.: QWERTYUIOPASDFGHJKLZXCVBNM)\n\n");
    scanf(" %[^\n]%*c", key);
    
    int stringLength = strlen(originalText);
    char encryptedText[stringLength];
    int i;
    
    for(i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            encryptedText[i] = key[(originalText[i]-65)];
        }
        else
            encryptedText[i] = originalText[i];
    }
    
    printf("\nEncrypted text:\n%s", encryptedText);
    
}