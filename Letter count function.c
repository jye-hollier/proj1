    
    #include <stdio.h>

main()  {

    char originalText[] =  "It as announcing it me stimulated frequently continuing. Least their she you now above going stand forth. He pretty future afraid should genius spirit on. Set property addition building put likewise get. Of will at sell well at as. Too want but tall nay like old. Removing yourself be in answered he. Consider occasion get improved him she eat. Letter by lively oh denote an. Perceived end knowledge certainly day sweetness why cordially. Ask quick six seven offer see among. Handsome met debating sir dwelling age material. As style lived he worse dried. Offered related so visitor we private removed. Moderate do subjects to distance. Inhabit hearing perhaps on ye do no. It maids decay as there he. Smallest on suitable disposed do although blessing he juvenile in. Society or if excited forbade. Here name off yet she long sold easy whom. Differed oh cheerful procured pleasure securing suitable in. Hold rich on an he oh fine. Chapter ability shyness article welcome be do on service. Perhaps far exposed age effects. Now distrusts you her delivered applauded affection out sincerity. As tolerably recommend shameless unfeeling he objection consisted. She although cheerful perceive screened throwing met not eat distance. Viewing hastily or written dearest elderly up weather it as. So direction so sweetness or extremity at daughters. Provided put unpacked now but bringing. Affronting discretion as do is announcing. Now months esteem oppose nearer enable too six. She numerous unlocked you perceive speedily. Affixed offence spirits or ye of offices between. Real on shot it were four an as. Absolute bachelor rendered six nay you juvenile. Vanity entire an chatty to. ";
    char capitalText[strlen(originalText)];
    char letterCount[26];
    int firstCommon = 0;
    int secondCommon = 0;
    int thirdCommon = 0;
    int stringLength = strlen(originalText);
    int i;
    
    for(i = 0; i < stringLength; i++)  {
        if(originalText[i] >= 97 && originalText[i] <= 122) {
            capitalText[i] = originalText[i] - 32;
        }
        else  {
            capitalText[i] = originalText[i];
        }    
    }
    
    for(i = 0; i < 26; i++)  {
        letterCount[i] = 0;
    }

    for(i = 0; i < stringLength; i++)  {
        switch(capitalText[i])  {
            case 65:    letterCount[0]++;
                        break;
            case 66:    letterCount[1]++;
                        break;
            case 67:    letterCount[2]++;
                        break;
            case 68:    letterCount[3]++;
                        break;
            case 69:    letterCount[4]++;
                        break;
            case 70:    letterCount[5]++;
                        break;
            case 71:    letterCount[6]++;
                        break;
            case 72:    letterCount[7]++;
                        break;
            case 73:    letterCount[8]++;
                        break;
            case 74:    letterCount[9]++;
                        break;
            case 75:    letterCount[10]++;
                        break;
            case 76:    letterCount[11]++;
                        break;
            case 77:    letterCount[12]++;
                        break;
            case 78:    letterCount[13]++;
                        break;
            case 79:    letterCount[14]++;
                        break;
            case 80:    letterCount[15]++;
                        break;
            case 81:    letterCount[16]++;
                        break;
            case 82:    letterCount[17]++;
                        break;
            case 83:    letterCount[18]++;
                        break;
            case 84:    letterCount[19]++;
                        break;
            case 85:    letterCount[20]++;
                        break;
            case 86:    letterCount[21]++;
                        break;
            case 87:    letterCount[22]++;
                        break;
            case 88:    letterCount[23]++;
                        break;
            case 89:    letterCount[24]++;
                        break;
            case 90:    letterCount[25]++;
                        break;
        }
    }

    for(i = 0; i < 26; i++)  {
        printf ("%d\n", letterCount[i]);
    }
    
    for(i = 0; i < 26; i++)    {
        if(letterCount[i] >= firstCommon)  {
            thirdCommon = secondCommon;
            secondCommon = firstCommon;
            firstCommon = i;
        }
        else if (letterCount[i] < firstCommon && letterCount[i] >= secondCommon) {
            thirdCommon = secondCommon;
            secondCommon = i;
        }
        else if(letterCount[i] < secondCommon && letterCount[i] > thirdCommon) {
            thirdCommon = i;
        }             
    }
    
    printf("\n\n%c\n%c\n%c\n", firstCommon, secondCommon, thirdCommon);
    
}