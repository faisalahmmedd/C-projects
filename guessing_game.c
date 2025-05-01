#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the world of guessing number: \n\n");

    int guessNumber,randomNumber;

    // Seed the random number generator with current time
    srand(time(0));

    randomNumber = rand()%500 +1;

    int attemptNo=0;


    do{

      printf("Please enter you guess between (1 to 500): ");
      scanf("%d",&guessNumber);

      attemptNo++;

      if(guessNumber>randomNumber)
      {
          printf("Enter a smaller number.\n\n");
      }
      else if(guessNumber<randomNumber)
      {
          printf("Enter a larger number.\n\n");
      }
      else
      {
          printf("Congratulation! You have guessed the correct number in %d attempts.\n\n",attemptNo);
      }

    }while(guessNumber!=randomNumber);


    printf("Thanks a lot for playing the game\n");
    printf("Developed By: Faisal Ahmmed\n");



    return 0;
}
