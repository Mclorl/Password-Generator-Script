#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

char letters[] = {"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ"};
char characters[] = {"!~`#$%^&*()-=_+[]{}\\|\'\";:/?.>,<"};
int numbers[] = {1,2,3,4,5,6,7,8,9,0};

// finding the length of an array
int lettersLength = (sizeof(letters)/sizeof(letters[0]));
int charactersLength = (sizeof(characters)/sizeof(characters[0]));
int numbersLength = (sizeof(numbers)/sizeof(numbers[0]));

void generatorRandom(int repeat, int lengthPass);
void usrInputFunction(int *usrInput1, int *usrinput2);

int main(void) { /* Password generator */
   int usrInputGenerated;
   int usrInputLengthPass;

   //Call function.
   usrInputFunction(&usrInputGenerated, &usrInputLengthPass);
   generatorRandom(usrInputGenerated, usrInputLengthPass);
   
   return 0;
}

void generatorRandom(int repeat, int lengthPass) {
   time_t time1;
   srand((unsigned)time(&time1));
   for (int i = 0; i<repeat; i++) {
      printf("No.%d combinantion\t\t", (i+1));
     
      for (int j = 0; j<lengthPass; j++) {
	 int num = rand() % 3;
	 switch(num) {
	    case 0:
	       printf("%c", letters[(rand() % lettersLength)]);
	       break;
	    case 1:
	       printf("%c", characters[(rand() % charactersLength)]);
	       break;
	    case 2:
	       printf("%d", numbers[(rand() % numbersLength)]);
	       break;
	 }
      }
      printf("\n");
   }
}

void usrInputFunction(int *usrInput1, int *usrInput2) {
   printf("What is the length of the password?\nInput:");
   scanf("%d", usrInput2);
   if (*usrInput2 <= 0) {
      printf("The value %d of the length of the password is invalid\n", *usrInput2);
      return;
   }

   if (*usrInput2 >= 30) {
      int ans;
      printf("The length of the password may be too long.\nAre you sure you want to continue? (0=y/1=n): ");
      scanf("%d", &ans);
      if (ans == 1) {
         printf("Abort.\n");
         return;
      } else if (ans > 1 || ans < 0) {
         printf("%d is an invalid input. Abort.\n", ans);
         return;
      }
   }
   
   printf("How many passwords need to be generated?\nInput:");
   scanf("%d", usrInput1);
   if (*usrInput1 <= 0) {
      printf("The value %d of how many passwords being generated is invalid\n", *usrInput1);
      return;
   }
}

