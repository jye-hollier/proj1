void taskFour(void)  {
    char originalText[] =  "ZIOL OL Q LZKOFU. Q CTKN SGFU LZKOFU (LGKZ GY) ZIQZ RGTLFZ KTQSSN LQN DXEI (with some lower case to test) ";
    
    //printf
    //char originalText[1000];
    //scanf("%[^\n]%*c", originalText);
    
    int stringLength = strlen(originalText);
    char decryptedText[stringLength];
    
    char key[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    
    //printf("Enter 26 letter key string in capitals\nE.g.: QWERTYUIOPASDFGHJKLZXCVBNM\n\n");
    //scanf("%[^\n]%*c", key);
    
    int i;
    
    for(i = 0; i < stringLength + 1; i++)  {
        //if (originalText[i] > 64 && originalText[i] < 91)  {
            decryptedText[i] = key[(originalText[i]-65)];
        //}
        
        
        switch(originalText[i])  {
                case key[0]: decryptedText[i] = 'A'
                    break;
                case key[1]: decryptedText[i] = 'B'
                    break;
                case key[2]: decryptedText[i] = 'C'
                    break;
                case key[3]: decryptedText[i] = 'D'
                    break;
                case key[4]: decryptedText[i] = 'E'
                    break;
                case key[5]: decryptedText[i] = 'F'
                    break;
                case key[6]: decryptedText[i] = 'G'
                    break;
                case key[7]: decryptedText[i] = 'H'
                    break;
                case key[8]: decryptedText[i] = 'I'
                    break;
                case key[9]: decryptedText[i] = 'J'
                    break;
                case key[10]: decryptedText[i] = 'K'
                    break;
                case key[11]: decryptedText[i] = 'L'
                    break;
                case key[12]: decryptedText[i] = 'M'
                    break;
                case key[13]: decryptedText[i] = 'N'
                    break;
                case key[14]: decryptedText[i] = 'O'
                    break;
                case key[15]: decryptedText[i] = 'P'
                    break;
                case key[16]: decryptedText[i] = 'Q'
                    break;
                case key[17]: decryptedText[i] = 'R'
                    break;
                case key[18]: decryptedText[i] = 'S'
                    break;
                case key[19]: decryptedText[i] = 'T'
                    break;
                case key[20]: decryptedText[i] = 'U'
                    break;
                case key[21]: decryptedText[i] = 'V'
                    break;
                case key[22]: decryptedText[i] = 'W'
                    break;
                case key[23]: decryptedText[i] = 'X'
                    break;
                case key[24]: decryptedText[i] = 'Y'
                    break;
                case key[25]: decryptedText[i] = 'Z'
                    break;
                default: decryptedText[i] = originalText[i];
                    break;
         }       

    
//}
        
        
        
       // else
          //  decryptedText[i] = originalText[i];
   // }
    
    printf("Decrypted text:\n%s\n\n", decryptedText);
    
}