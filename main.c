#include <stdio.h>

//function declaration
void enc_rot(int key); //function for encoding of rotational text
int rotation (int key, int ascii); //function for rotating text
int key_sub (char key[25]); //function for creating key during substitution text
char enc_sub (char text[1000]); //function for encoding for substitution
char dec_sub (char text[1000]); //function for decoding for substitution

//global variables
char text[1000];//input text to manipulate


int main()
{
    int action; //variable for task choice 
    int key; //key for rotational encryption
    
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
    char out; 
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

char enc_sub(char text[1000]) { //function to encode for substitution
    char keys[25]; //array to store keys 
    int b = 0; //counter
    int ascii2[25];
    int asciitext; //store of ascii values
    int location; //store of location of decrypted letter
    printf("Please enter key for Substitution");
    scanf ("%d", keys);
    key_sub(keys);
    while (text[b] !='\0') {
        asciitext = text[b]; //letter to ascii
        location = asciitext - 64; //ascii to location in array
        asciitext = ascii2[location]; //decryption
        text[b] = asciitext; //ascii to letter 
        printf("%d", text[b]);
        b = b + 1;
    }
}

char dec_sub(char text[1000]) { //function to decrypt substitution
    char keys [25]; 
    int ascii2[25];
    int asciitext;
    int a, b, new_ascii;//counters a and b, and variable for found ascii to return
    printf("Please enter key to decrypt substitution");
    scanf("%d", keys);
    key_sub(keys);
    while (text[a] !='\0') {
        asciitext = text[a]; 
        for (b=0; b < 25; b = b + 1) { //linear search
            if (asciitext == ascii2[b]) {
                new_ascii = b + 64; //decryption
            }
        }
        text[a] = new_ascii;
        printf("%d", text[a]);
        a = a + 1;
    }
}

int key_sub(char key[25]) { //function to decode key 
    int ascii2[25]; //store of key to allow decoding
    int z = 0; //counter
    for (z=0; z < 25; z = z + 1) { 
        ascii2[z] = key[z];
        ascii2[z] = ascii2[z] - 64;
    }
    return ascii2;
}
