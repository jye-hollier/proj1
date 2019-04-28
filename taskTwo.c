void taskTwo(void)  {
    
    /*A reverse of taskOne, this function takes an encrypted text and key from the user and decrypts the message by subtracing the key from each ascii code*/
    
    char originalText[1000];
    int key;
    
    printf("\nPlease enter text to be encrypted:\n");
    scanf (" %[^\n]%*c", originalText);
    
    printf("\nPlease enter the rotation key number used:\n#");
    scanf("%d", &key);
    
    int stringLength = strlen(originalText);
    char decryptedText[stringLength];
    int i;
    
    for(i = 0; i < stringLength + 1; i++)  {
        if (originalText[i] > 64 && originalText[i] < 91)  {
            decryptedText[i] = (((originalText[i] - 39) - key) %26 ) + 65;      //Same formula for taskOne however key is subtracted
        }                                                                       //Only 39 is subtracted initially to prevent negative ascii code
        else
            decryptedText[i] = originalText[i];                                 //All lower case and other symbols ignored
    }
    
    printf("\nDecrypted text:\n%s", decryptedText);

}