void taskThree(void)  {
    
    /*This function takes the entered text and encryption code (in the form of a 26 capital letter string) to encrypt the text
      An array of 1000 chars is provided allowing for a maximum paragraph length of 1000 characters(including white space) to be entered*/
    
    char originalText[1000];
    char key[26];
    
    printf("\nPlease enter text to be encrypted:\n");
    scanf (" %[^\n]%*c", originalText);
    
    printf("\nPlease enter the encryption key:\n(E.g.: QWERTYUIOPASDFGHJKLZXCVBNM)\n\n");
    scanf(" %[^\n]%*c", key);
    
    int stringLength = strlen(originalText);
    char encryptedText[stringLength];
    int i;
    
    for (i = 0; i < 26; i++)  {                                 //Ensures all key elements are valid characters and capital
        if (key[i] >= 97 && key[i] <= 122)
            key[i] = key[i] - 32;
        else if (key[i] < 65 || key[i] > 122) {                 //Program exits if key contains a non-letter charatcter
            printf("key contains invalid character(s)");
            return 0;
        }
    }            
    
    
    for(i = 0; i < stringLength; i++)  {                        // Converts any lower case letters to capital
        if(originalText[i] >= 97 && originalText[i] <= 122)
            originalText[i] = originalText[i] - 32;   
    }
    
    for(i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            encryptedText[i] = key[(originalText[i]-65)];       //Each letter is replaced by the element of the key corresponding to the original letter
        }                                                       //As originally standard a-z with ascii codes increasing by 1 each time, ascii code is reduced by 65 to give address of required substitute letter
        else
            encryptedText[i] = originalText[i];                 //All lower case and other symbols ignored
    }
    
    printf("\nEncrypted text:\n%s", encryptedText);
    
}