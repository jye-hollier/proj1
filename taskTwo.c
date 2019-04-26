void taskTwo(void)  {
    char originalText[] =  "XLMW MW E WXVMRK. E ZIVC PSRK WXVMRK (WSVX SJ) XLEX HSIWRX VIEPPC WEC QYGL";
    
    //printf("Enter text to be encrypted\n\n")
    //char originalText[1000];
    //scanf("%[^\n]%*c", originalText);
    
    int key = 4;
    
    //printf("Enter rotation key")
    //scanf("%d", key)
    
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
    
    printf("Decrypted text:\n%s\n\n", decryptedText);
}