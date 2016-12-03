#include <stdio.h>
#include <stdlib.h>

extern int CheckNull();
extern int CheckLength();
extern int CheckValid();
extern int CheckTerminate();
//extern int CheckInput();
extern int DNALength();
extern int ACount();
extern int CCount();
extern int GCount();
extern int TCount();
//extern int *Fibonacci();

int CheckInput(char *input)
{
    int i = 0;
    int isNull = -1;
    int isValid = -1;
    int isTerminate = -1;
    int isLength = -1;
    //int check = -1;
    
    isNull = CheckNull(*input);
    if(isNull == 1)
    {
        printf("\nError: Null input");
        return -1;
    }
    else
    {
        isLength = CheckLength(*(input + 20));
        if(isLength == 1)
        {
            printf("\nError: Beyond maximum length");
            //printf("last input20: %08x", *(input + 20));
            return -1;
        }
        else
        {
            for(i = 0; i < 20; i++)
            {
                isValid = CheckValid(*(input + i));
                
                if(isValid > 0)
                {
                    break;
                }
            }
            
            if(isValid == 1)
            {
                printf("\nError: Invalid input");
                return -1;
            }
            else
            {
                isTerminate = CheckTerminate(*(input + i));
                
                if(isTerminate == 1)
                {
                    printf("\nError: Invalid or no terminator");
                    printf("\nchecked index %d", i);
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
        }
    }        
}

char *GetDNA()
{
     int validity = -1;
     char *DNA = (char*)calloc(22, sizeof(char));
     //printf("DNA end: %2x", *(DNA+21));
     printf("\nEnter DNA string: ");
     //getchar();
     fgets(DNA, 23, stdin);
     //scanf("%s", DNA);
     
     validity = CheckInput(DNA);
     
     if(validity == 1)
     {
         printf("Returned: %d", validity);
         return DNA;
     }
     else
         return NULL;
     
     /*
     switch(validity)
     {
          case -1:
               return DNA;
               break;
          case 1:
               printf("\nError: Null input");
               return NULL;
               break;
          case 2:
               printf("\nError: Beyond maximum length");
               return NULL;
               break;
          case 3:
               printf("\nError: Invalid input");
               return NULL;
               break;
          case 4:
               printf("\nError: Invalid or no terminator");
               return NULL;
               break;
          default:
               printf("\nHALA KAAAAAA");
               return NULL;
               break;
     }
     */
}

int AskInput()
{
     int input;
     printf("\n\t\t\t\tMain Menu\n");
     printf("\t\t1. Perform DNA Frequency Count\n");
     printf("\t\t2. Perform DNA Reverse Complement\n");
     printf("\t\t3. Perform Reverse Palindrome Test\n");
     printf("\t\t4. Perform DNA Pop Count\n");
     printf("\t\t5. Perform Genetic Fibonacci Sequence\n");
     printf("\t\t6. Exit\n");
     printf("\t\t   Enter your choice: ");
     //fgets(input, 1, stdin);
     scanf("%d", &input);
     getchar();
     return input;
}

int Perform(int input)
{
     int month;
     char *DNA;
     int *FS;
     switch(input)
     {
         case 1:
              printf("\nTask to be performed: DNA Frequency Count");
              DNA = GetDNA();
              
              if(DNA != NULL)
              {
                     /*
                     printf("\nDNA Length: %d", DNALength(DNA));
                     printf("\nFrequency of A: %d", ACount(DNA));
                     printf("\nFrequency of C: %d", CCount(DNA));
                     printf("\nFrequency of G: %d", GCount(DNA));
                     printf("\nFrequency of T: %d", TCount(DNA));
                     */
                     printf("DNA: //%s//, hex: %08x", DNA, *DNA);
              }
              break;
         case 2:
              printf("\nTask to be performed: DNA Reverse Complement");
              printf("\nEnter DNA string: ");
              scanf("%s", DNA);
              break;
         case 3:
              printf("\nTask to be performed: DNA Reverse Palindrome Test");
              printf("\nEnter DNA string: ");
              scanf("%s", DNA);
              break;
         case 4:
              printf("\nTask to be performed: DNA POP Count");
              printf("\nEnter DNA string: ");
              scanf("%s", DNA);
              break;
         case 5:
              printf("\nTask to be performed: Genetic Fibonacci Computation");
              printf("\nEnter month: ");
              scanf("%d", &month);
              FS = malloc(month * sizeof(int));
              //FS = Fibonacci(month);
              break;
         case 6:
              return -1;
              break;
         default:
              printf("\nError: Invalid menu choice");
              return -1;
              break;
     }
     
     free(DNA);
     printf("\nPress any key to return to main menu ...");
     getchar();
     return AskInput();
}

int main()
{
    int choice = AskInput();
    
    do{
        choice = Perform(choice);
    }while(choice != -1);
    
    return 0;
}
