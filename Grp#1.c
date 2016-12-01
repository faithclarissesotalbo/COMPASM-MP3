#include <stdio.h>
#include <stdlib.h>

int main()
{
    char DNA;
    int n;
    printf("\t\t\tMain Menu\n");
    printf("\t\t1. Perform DNA Frequency\n"); 
    printf("\t\t2. Perform DNA Reverse Complement\n");
    printf("\t\t3. Perform Reverse Palindrome Test\n");
    printf("\t\t4. Perform DNA Pop Count\n");
    printf("\t\t5. Perform Genetic Fibonacci Sequence\n");
    printf("\t\t6. Exit\n");
    printf("\t\tEnter your choice: ");
    scanf("%d", &n);

switch(n){
case 1 :
     printf("Task to be performed: DNA Frequency Count\n");
     printf("Enter DNA string: ");
     scanf("%c", &DNA);
     printf("\nDNA Length: ");
     printf("\nFrequency of A: ");
     printf("\nFrequency of C: ");
     printf("\nFrequency of G: ");
     printf("\nFrequency of T: ");
     break;
     //call dna freq count
case 2 :
     printf("Task to be performed: DNA Reverse Complement\n");
     printf("Enter DNA string: ");
     printf("\nReverse Complement: ");
     break;
     //call dna reverse complement
case 3 : 
     printf("Task to be performed: DNA Reverse Palindrome Test\n");
     printf("Enter DNA string: ");
     printf("\nIs the DNA string a reverse Palindrome? ");
     break;
     //call reverse palindrome test
case 4 :
     printf("Task to be performed: DNA POP Count\n");
     printf("Enter DNA string: ");
     scanf("%s", &DNA);
     printf("\nPOPCOUNT: ");
     break;
     //call dna pop count
case 5 :
     printf("Task to be performed: Genetic Fibonacci Computation\n");
     printf("Enter month: ");
     printf("\nFibonacci sequence is ");
     break;
     //call genetic fibonacci sequence
default :
        break;
}

getch();
return 0;
}
