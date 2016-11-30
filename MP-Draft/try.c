#include <stdio.h>

extern int CheckInput();

void PrintMenu()
{
     printf("\t\t\t\tMain Menu\n");
     printf("\t\t1. Perform DNA Frequency Count\n");
     printf("\t\t2. Perform DNA Reverse Complement\n");
     printf("\t\t3. Perform Reverse Palindrome Test\n");
     printf("\t\t4. Perform DNA Pop Count\n");
     printf("\t\t5. Perform Genetic Fibonacci Sequence\n");
     printf("\t\t6. Exit\n");
}   

int AskInput()
{
     int menuInput;
     PrintMenu();
     printf("\t\t   Enter your choice: ");
     scanf("%d", &menuInput);
     
     menuInput = CheckInput(menuInput);
     
     if(menuInput == -1)
          printf("\nError: Invalid choice");
     
     return menuInput;
}

int Perform(int input)
{
     switch(input)
     {
         case 1:
              printf("\nTask to be performed: DNA Frequency Count\n");
              break;
         case 2:
              printf("\nTask to be performed: DNA Reverse Complement\n");
              break;
         case 3:
              printf("\nTask to be performed: DNA Reverse Palindrome Test\n");
              break;
         case 4:
              printf("\nTask to be performed: DNA POP Count\n");
              break;
         case 5:
              printf("\nTask to be performed: Genetic Fibonacci Computation\n");
              break;
     }
     
     printf("Press any key to return to main menu ...\n");
     getchar();
     getchar();
     return AskInput();
}

int main()
{
    int menuInput = AskInput();
    
    while(menuInput != -1)
    {
        menuInput = Perform(menuInput);
    }
    
    return 0;
}
