#include <stdio.h>
char enc_rot(char text); //function for encoding of rotational text
char dec_rot(char text); //function for decoding of rotational text
int rotation (int key); //function for rotating text

int main()
{
    int action; //variable for task choice 
    char text[1000];//input text to manipulate
    char textout; //text to output
    int ascii[1000];//ascii values for text
    printf("what is your command \n");
    printf("To encrypt a rotational cypher, enter 1 \n");
    printf("To decrypt a rotational cypher, enter 2 \n");
    printf("To encrypt a substitution cypher, enter 3 \n");
    printf("To decrypt a substitution cypher, enter 4 \n");
    scanf("%d", &action);
    switch action { //case statement for task choice
        case 1{
            textout = enc_rot(text);
            printf("%d", textout)
            break;
        }
        case 2{
            dec_rot(text);
            break;
        }
        case 3{
            
            break;
        }
        case 4{
            
            break
        }
        default {
            printf("Incorrect action input. Please try again.");
            break;
        }
    }
    printf("input text to encrypt please \n");
    scanf("%s", &text);
}

char enc_rot(char text) {
    int x = 0;
    while (text[x]!='\0') {
        ascii[x] = text (x);
        x = x + 1;
    }
}

int rotation (int key, int ascii) {
    int y = 0;
    while (ascii[y]!='\0') {
        if (ascii[y] <= 122)&&(ascii >=97) {
            ascii[y] = ascii [y] + 32;
        } else if (ascii[y] <= 90)&&(ascii[y] >=65) { //rotation of uppercase letters
            ascii[y] = ascii[y] + key;
            if (ascii[y] < 65) { //correction for going negative of range
                ascii[y] = ascii[y] + 26;
            } else if (ascii[y] > 90) { //correction of going positive of range
                ascii[y] = ascii[y] - 26;
            }
        } 
    }
    y = y + 1;
}