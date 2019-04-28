void taskFour(void)  {
    
    /*Like taskTwo this function takes the encrypted text and decryption code (in the form of a 26 capital letter string) to decrypt the text*/
    
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
    
    for (i = 0; i < stringLength + 1; i++)  {                   //for each string elemtent including the end null
        if (originalText[i] > 64 && originalText[i] < 91)  {    //if it is a capital letter
            for (c = 0; c < 26; c++)  {                         //go through each elememt of the decryption code
                if (originalText[i] == key[c])  {               //if the letter is equal to the decryption code element
                    decryptedText[i] = c + 65;                  //decypted letter ascii code is the position of the matching element plus 65
                }
            }
        }
        else
            decryptedText[i] = originalText[i];                 //All other characters copied
    }
        
    printf("\nDecrypted text:\n%s", decryptedText);

}