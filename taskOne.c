void taskOne(void)  {
    
    /*This function allows the user to enter both the text to be encrypted and the rotation key number to be used thrugh standard input. 
      An array of 1000 chars is provided allowing for a maximum paragraph length of 1000 characters(including white space) to be entered*/
    
    char originalText[1000];
    int key;
    
    printf("\nPlease enter text to be encrypted:\n");
    scanf (" %[^\n]%*c", originalText);
    
    printf("\nPlease enter rotation key number to be used:\n#");
    scanf("%d", &key);
    
    int stringLength = strlen(originalText);
    char encryptedText[stringLength];
    int i;
    
    for(i = 0; i < stringLength; i++)  {                                        // Converts any lower case letters to capital
        if(originalText[i] >= 97 && originalText[i] <= 122)
            originalText[i] = originalText[i] - 32;   
    }
    
    
    
    for(i = 0; i < stringLength + 1; i++)  {                                    //Loops for every string element (plus 1 for ending null)
        if (originalText[i] > 64 && originalText[i] < 91)  {                    //I.e if a capital letter ascii code
            encryptedText[i] = (((originalText[i] - 65) + key) %26 ) + 65;      //Modifies each letter by key provided utilising the modulus to cater for letters which go past z
        }
        else
            encryptedText[i] = originalText[i];                                 //All lower case and other symbols ignored
    }
    
    printf("\nEncrypted text:\n%s", encryptedText);
    
}