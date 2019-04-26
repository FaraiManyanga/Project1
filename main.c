#include <stdio.h>
char enc_rot(char text); //function for encoding of rotational text
//char dec_rot(char text); //function for decoding of rotational text
int rotation (int key); //function for rotating text

int main()
{
    int action; //variable for task choice 
    char text[1000];//input text to manipulate
    char textout[1000]; //text to output
    int key; //key for rotational encryption
    printf("what is your command \n");
    printf("To encrypt a rotational cypher, enter 1 \n");
    printf("To decrypt a rotational cypher, enter 2 \n");
    printf("To encrypt a substitution cypher, enter 3 \n");
    printf("To decrypt a substitution cypher, enter 4 \n");
    scanf("%d", &action);
    printf("Please enter text to modify")
    scanf("%d", &text)
    
    switch action { //case statement for task choice
        case 1{
            printf("Please enter key for encryption");
            scanf("%d", %key);
            enc_rot(text, key);
            break;
        }
        case 2{
            printf("Please enter key for decryption");
            scanf("-%d", &key); //minus sign makes key negative causing decryption
            enc_rot(text, key);
            break;
        }
        case 3{
            
            break;
        }
        case 4{
            
            break
        }
        default {
            printf("Incorrect action choice input. Please try again.");
            break;
        }
    }
}

char enc_rot(char text, int key) {
    int x = 0;
    int ascii[1000];
    while (text[x]!='\0') {
        ascii[x] = text [x];
        rotation(key, ascii);
        text[x] = ascii[x];
        printf("%d", text[x]);
        x = x + 1;
    }
}

/*char dec_rot(char text) {
    int z; 
    int key;
    printf("please enter decryption key");
    scanf("%d", &key);
    key = -key;
    
} */

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