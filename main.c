#include <stdio.h>

int main()
{
    int action; //variable for task choice 
    //variable for text to manipulate
    
    printf("what is your command \n");
    printf("To encrypt a rotational cypher, enter 1 \n");
    printf("To decrypt a rotational cypher, enter 2 \n");
    printf("To encrypt a substitution cypher, enter 3 \n");
    printf("To decrypt a substitution cypher, enter 4 \n");
    scanf("%d", &action);
    switch action { //case statement for task choice
        case 1{
            
            break;
        }
        case 2{
            
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
    
    return 0;
}
