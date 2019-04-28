void taskFour(void)  {
    
    char originalText[1000];
    char key[26];
    
    printf("\nPlease enter text to be decrypted:\n");
    scanf (" %[^\n]%*c", originalText);
    
    printf("\nPlease enter the encryption key used in capitals:\n(E.g.: QWERTYUIOPASDFGHJKLZXCVBNM)\n");
    scanf(" %[^\n]%*c", key);
    
    int stringLength = strlen(originalText);
    char decryptedText[stringLength];
    
    int i;
    int c;
    
    for (i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            for (c = 0; c < 26; c++)  {
                if (originalText[i] == key[c])  {
                    decryptedText[i] = c + 65;
                }
            }
        }
        else
            decryptedText[i] = originalText[i];
    }
        
    printf("\nDecrypted text:\n%s", decryptedText);
    
}