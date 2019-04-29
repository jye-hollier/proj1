#include <stdio.h>
#include <string.h>

int main()  {
    
    /*Each task has is accessed though seperate individual functions*/
    
    int taskNumber = 0;
    void taskOne(void);
    void taskTwo(void);
    void taskThree(void);
    void taskFour(void);
    void taskFive(void);
    void taskSix(void);
    
    //While loop utilised to only allow valid selection (will reloop if invalid option entered)
    
    while (taskNumber <1||taskNumber > 6)  {
        printf("Please enter the task number:\n1 - Rotation Encryption\n2 - Rotation Decryption\n3 - Substitution Encryption\n4 - Substitution Decryption\n5 - Rotation Decryption(Given text only)\n6 - Substitution Decryption(Given text only)\n\n#");
        scanf("%d", &taskNumber);
    }

    switch(taskNumber)  {
        case 1:  taskOne();
            break;
        case 2:  taskTwo();
            break;
        case 3:  taskThree();
            break;
        case 4:  taskFour();
            break;
        case 5:  taskFive();
            break;
        case 6:  taskSix();
            break;
    }
    
    return 0;
}