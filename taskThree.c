void taskThree(void)  {
    
    /*This function takes the entered text and encryption code (in the form of a 26 capital letter string) to encrypt the text*/
    
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
            encryptedText[i] = key[(originalText[i]-65)];       //Each letter is replaced by the element of the key corresponding to the original letter
        }                                                       //As originally standard a-z with ascii codes increasing by 1 each time, ascii code is reduced by 65 to give address of required substitute letter
        else
            encryptedText[i] = originalText[i];                 //All lower case and other symbols ignored
    }
    
    printf("\nEncrypted text:\n%s", encryptedText);
    
}