void taskTwo(void)  {
    
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
            decryptedText[i] = (((originalText[i] - 39) - key) %26 ) + 65;
        }
        else
            decryptedText[i] = originalText[i];
    }
    
    printf("\nDecrypted text:\n%s", decryptedText);
}