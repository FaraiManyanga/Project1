#include <stdio.h>

//function declaration
void enc_rot(int key); //function for encoding of rotational text
int rotation (int key, int ascii); //function for rotating text
int key_sub (); //function for creating key during substitution text
void enc_sub (); //function for encoding for substitution
void dec_sub (); //function for decoding for substitution

//global variables
char text[1000];//input text to manipulate
char keys[25]; //array to store keys 
int keyout[25];
char out; 
char output[400];

int main()
{
    int action ; //variable for task choice 
    int key ; //key for rotational encryption
    
    printf("Welcome. Please enter text to modify \n");
    fgets(text, 500, stdin);
    printf("what is your command \n");
    printf("To encrypt a rotational cypher, enter 1 \n");
    printf("To decrypt a rotational cypher, enter 2 \n");
    printf("To encrypt a substitution cypher, enter 3 \n");
    printf("To decrypt a substitution cypher, enter 4 \n");
    scanf("%d", &action);
        
    switch (action) { //case statement for task choice
        case 1: //base code for encryption of rotational
            printf("Please enter key for encryption \n");
            scanf("%d", &key);
            enc_rot(key);
            break;

        case 2: //base code for decryption of rotational
            printf("Please enter key for decryption"); 
            scanf("-%d", &key);
            key = key - (2*key); //makes key negative to allow decryption
            enc_rot(key);
            break;
        
        case 3: //base code for encryption of substitution
            enc_sub(text);
            break;
        
        case 4: //base code for decryption of substitution
            dec_sub(text);
            break;
        
        default:
            printf("Incorrect action choice input. Please try again.");
            break;
        
    }
}

void enc_rot(int key) { //main code to encrypt rotational
    int x = 0; //counter
    int ascii; //store for acii value of letter
    while (text[x]!='\0') {
        ascii = text[x];
        //printf("%d", ascii);
        rotation(key, ascii);
        x = x + 1;
    }
}

int rotation (int key, int ascii) { //function for rotation of key
    if ((ascii <= 122) && (ascii >=97)) { //correction from lower case
        ascii = ascii - 32;
    } 
    if (ascii <= 90 && ascii >=65) { //rotation of uppercase letters
        ascii = ascii + key;
        if (ascii < 65) { //correction for going negative of range
            ascii = ascii + 26;
        } else if (ascii> 90) { //correction of going positive of range
            ascii = ascii - 26;
        }
    } 
    out = ascii;
    printf("%c", out);
    return ascii;

}

void enc_sub() { //function to encode for substitution
    int b = 0; //counter    
    ////printf("Please enter key for Substitution \n");
    ////scanf("%c", keys);
    char subkey[25] = {"QWERTYUIOPASDFGHJKLZXCVBNM"};
    
    for (b=0;b!='\0'; b=b+1) {
        if ((text[b] <= 122) && (text[b] >=97)) { //correction from lower case
            text[b] = text[b] - 32;
        }
        if (text[b] <= 90 && text[b] >=65) { //encryption
            output[b]=subkey[text[b]-65];
        }
    }
    printf("%s \n", output);
}

void dec_sub() { //function to decrypt substitution
    int b; //counter 
    int c;
    ////printf("Please enter key for Substitution \n");
    ////scanf("%c", keys);
    char subkey[25] = {"QWERTYUIOPASDFGHJKLZXCVBNM"}; //input of key
    
    for (b=0; text[b]!='\0'; b=b+1) { //changes each letter
        for (c=0; c<=25; c=c+1) //
            if (text[b]==subkey[c]) {
                if ((text[b] <= 122) && (text[b] >=97)) { //correction from lower case
                    text[b] = text[b] - 32;
                }
                if (text[b] <= 90 && text[b] >=65) { //encryption
                    output[b]= c + 65;
                    printf("%s", output[b]);
                } else {
                    printf("%s", text[b]);
                }
            }
        }    
}
