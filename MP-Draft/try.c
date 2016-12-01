#include <stdio.h>
#include <stdlib.h>

extern int CheckInput();
extern int DNALength();
extern int ACount();
extern int CCount();
extern int GCount();
extern int TCount();
extern int *Fibonacci();

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
     scanf("%d", &input);
     
     return input;
}

char *GetDNA()
{
     char *DNA = (char*)calloc(22, sizeof(char));
     printf("\nEnter DNA string: ");
     scanf("%s", DNA);
     
     switch(CheckInput(DNA))
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
                     printf("%s", DNA);
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
