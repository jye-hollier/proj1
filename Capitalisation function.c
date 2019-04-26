    int i
    
    for(i = 0; i < (strlen(originalText); i++))  {
        if(originalText[i] >= 97 && originalText[i] <= 122) {
            capitalText[i] = originalText[i] - 32;
        }
        else  {
            capitalText[i] = originalText[i];
        }    
    }
    
     for(i = 0; i < stringLength; i++)  {
        if(originalText[i] >= 97 && originalText[i] <= 122) {
            capitalText[i] = originalText[i] - 32;
        }
        else  {
            capitalText[i] = originalText[i];
        }    
    }
    
  // Converts any lower case letters to capital
    for(i = 0; i < stringLength; i++)  {
        if(originalText[i] >= 97 && originalText[i] <= 122) {
            capitalText[i] = originalText[i] - 32;
        }
        else  {
            capitalText[i] = originalText[i];
        }    
    }
      