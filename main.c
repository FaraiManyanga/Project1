#include <stdio.h>

char enc_rot(char text[1000]); //function for encoding of rotational text
int rotation (int key); //function for rotating text
int key_sub (int key); //function for creating key during substitution text
char enc_sub (char text); //function for encoding for substitution
char dec_sub (char text); //function for decoding for substitution

int main()
{
    int action; //variable for task choice 
    char text[1000];//input text to manipulate
    int key; //key for rotational encryption
    printf("what is your command \n");
    printf("To encrypt a rotational cypher, enter 1 \n");
    printf("To decrypt a rotational cypher, enter 2 \n");
    printf("To encrypt a substitution cypher, enter 3 \n");
    printf("To decrypt a substitution cypher, enter 4 \n");
    scanf("%d", &action);
    printf("Please enter text to modify");
    scanf("%c", &text);
    
    switch action { //case statement for task choice
        case 1{ //base code for encryption of rotational
            printf("Please enter key for encryption");
            scanf("%d", %key);
            enc_rot(text, key);
            break;
        }
        case 2{ //base code for decryption of rotational
            printf("Please enter key for decryption"); 
            scanf("-%d", &key); //minus sign makes key negative causing decryption
            enc_rot(text, key);
            break;
        }
        case 3{ //base code for encryption of substitution
            enc_sub(text);
            break;
        }
        case 4{ //base code for decryption of substitution
            dec_sub(text);
            break
        }
        default {
            printf("Incorrect action choice input. Please try again.");
            break;
        }
    }
}

char enc_rot(char text, int key) { //main code to encrypt rotational
    int x = 0; //counter
    int ascii; //store for acii value of letter
    while (text[x]!='\0') {
        ascii = text [x];
        rotation(key, ascii);
        text[x] = ascii;
        printf("%c", text[x]);
        x = x + 1;
    }
}

int rotation (int key, int ascii) { //function for rotation of key
    if (ascii <= 122)&&(ascii >=97) { //correction from lower case
        ascii = ascii + 32;
    } else if (ascii <= 90)&&(ascii >=65) { //rotation of uppercase letters
        ascii = ascii + key;
        if (ascii < 65) { //correction for going negative of range
            ascii = ascii + 26;
        } else if (ascii> 90) { //correction of going positive of range
            ascii = ascii - 26;
        }
    } 
    return ascii;
}

char enc_sub(char text) { //function to encode for substitution
    char keys[25]; //array to store keys 
    int b = 0; //counter
    int asciitext; //store of ascii values
    int location; //store of location of decrypted letter
    printf("Please enter key for Substitution");
    scanf ("%d", keys);
    key_sub(keys);
    while text[a] !='\0' {
        asciitext = text[a]; //letter to ascii
        location = asciitext - 64; //ascii to location in array
        asciitext = ascii2[location]; //decryption
        text[a] = asciitext; //ascii to letter 
        printf("%d", text[a]);
    }
}

char dec_sub(char text) { //function to decrypt substitution
    char keys [25]; 
    int a, b, new_ascii; //counters a and b, and variable for found ascii to return
    printf("Please enter key to decrypt substitution");
    scanf("%d", keys);
    key_sub(keys);
    while text[a] !='\0' {
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

char key_sub(char key) { //function to decode key 
    int ascii2[25]; //store of key to allow decoding
    int z = 0; //counter
    for (z=0; z < 25; z = z + 1) { 
        ascii2[z] = key[z];
        ascii2[z] = ascii2[z] - 64;
    }
    return ascii2;
}