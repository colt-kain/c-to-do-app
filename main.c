#include <stdio.h>
#include <stdlib.h>

void display_options()
{
  printf("0. Quit program\n");
  printf("1. Add a new task item\n");
  printf("2. Remove an existing task item\n");
  printf("3. Display the task list\n");

  printf("\n");
}

int main()
{
  int user_choice = -1;
  while (user_choice != 0)
  {
    display_options();

    printf("Choice: ");
    if (scanf("%d", &user_choice) != 1)
    {
      printf("\nWrong format inputted.\nPlease provide an integer.\n\n");

      // Clear the input buffer for next loop iteration
      while (getchar() != '\n');

      continue;
    }
    else
      printf("\n");

    switch (user_choice)
    {
      default:
        printf("Invalid choice inputted.\nPlease provide a number in the range [0-3].\n\n");
        break;

      case 0:
        printf("Exiting program.\n\n");
        break;
    }
  }

  return 0;
}
