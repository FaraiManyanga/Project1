#include <stdio.h>

//function declaration
void enc_rot(int key); //function for encoding of rotational text
void rotation (int key, int ascii); //function for rotating text
int key_sub (); //function for creating key during substitution text
void enc_sub (); //function for encoding for substitution
void dec_sub (); //function for decoding for substitution

//global variables
char text[1000];//input text to manipulate
char out;//output of code for rotation
char subkey[25]; //store of key for substitution 

int main()
{
    int action ; //variable for task choice 
    int key ; //key for rotational encryption
    
    //menu to show choices
    printf("1.  Welcome. Please enter text to modify \n");
    fgets(text, 1000, stdin);
    printf("2.  what is your command?\n");
    printf("    To encrypt a rotational cypher, enter 1 \n");
    printf("    To decrypt a rotational cypher, enter 2 \n");
    printf("    To encrypt a substitution cypher, enter 3 \n");
    printf("    To decrypt a substitution cypher, enter 4 \n");
    scanf("%d", &action);

    switch (action) { //case statement for task choice
        case 1: //base code for encryption of rotational
            printf("3.  Please enter key \n");
            scanf("%d", &key);
            enc_rot(key);
            break;

        case 2: //base code for decryption of rotational
            printf("3.  Please enter key for decryption \n"); 
            scanf("%d", &key);
            key = key - (2*key); //makes key negative to allow decryption using encryption code
            enc_rot(key);
            break;
        
        case 3: //base code for encryption of substitution
            printf("3.  Please enter key for Substitution \n");
            scanf("%s", subkey);
            enc_sub(text);
            break;
        
        case 4: //base code for decryption of substitution
            printf("3.  Please enter key for Substitution \n");
            scanf("%s", subkey);
            dec_sub();
            break;
        
        default:
            printf("Incorrect action choice input. Please try again.");
            break;
        
    }
}

void enc_rot(int key) { //main code to encrypt rotational
    int x = 0; //counter
    int ascii; //store for acii value of letter
    while (text[x]!='\0') { //base code to process text
        ascii = text[x]; //change from string to ascii value
        rotation(key, ascii); //here rotations occur
        x = x + 1;
    }
}

void rotation (int key, int ascii) { //function for rotation of key
    if ((ascii <= 122) && (ascii >=97)) { //correction from lower case to upper
        ascii = ascii - 32;
    } 
    
    if (ascii <= 90 && ascii >=65) { //rotation of letters
        ascii = ascii + key;
        if (ascii < 65) { //correction for going negative of range
            ascii = ascii + 26;
        } else if (ascii> 90) { //correction of going positive of range
            ascii = ascii - 26;
        }
    } 
    out = ascii; //change back to string from ascii
    printf("%c", out);
}

void enc_sub() { //function to encode for substitution
    int b = 0; //counter
    for (b=0;text[b]!='\0'; b=b+1) {
        if ((text[b] <= 122) && (text[b] >=97)) { //correction from lower case
            text[b] = text[b] - 32;
        }
        if (text[b] <= 90 && text[b] >=65) { //encryption
            text[b] = subkey[text[b]-65];
        }
        printf("%c", text[b]);
    }
}

void dec_sub() { //function to decrypt substitution
    int b; //counter 
    int c; //another counter

    for (b=0; text[b]!='\0'; b=b+1) { //loop to allow scan for each letter
        for (c=0; c<=25; c=c+1) { //loop to allow comparison of text to key as linear search
            if ((text[b] <= 122) && (text[b] >=97)) { //correction from lower case
                text[b] = text[b] - 32;
            }
            if (text[b]==subkey[c]) { //decryption
                printf("%c", c+65);
            }
            
        }
        //below code allows for symbols, numbers and spaces to be output
        if ((text[b] >= 32) && (text[b] <= 64)) {
                printf("%c", text[b]);
        }
        if ((text[b] >= 91) && (text[b] <= 96)) {
                printf("%c", text[b]);
            }
        if ((text[b] >= 123) && (text[b] <= 126)) {
                printf("%c", text[b]);
            }
    }
}
