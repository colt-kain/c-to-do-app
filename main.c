#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_options()
{
  printf("0. Save and quit program\n");
  printf("1. Add a new task item\n");
  printf("2. Remove an existing task item\n");
  printf("3. Display the task list\n");

  printf("\n");
}

void add_task(const char *new_task)
{
  FILE *to_do_list = fopen("to_do_list.txt", "a");

  if (to_do_list == NULL)
  {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  fprintf(to_do_list, "- %s\n", new_task);

  fclose(to_do_list);
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

    while (getchar() != '\n');

    switch (user_choice)
    {
      default:
        printf("Invalid choice inputted.\nPlease provide a number in the range [0-3].\n\n");
        break;

      case 0:
        printf("Exiting program.\n\n");
        break;

      case 1:
        const int TASK_MAX_LENGTH = 50;

        char new_task[TASK_MAX_LENGTH];
        
        printf("New task: ");
        if (fgets(new_task, TASK_MAX_LENGTH, stdin) == NULL)
        {
          perror("Error reading input");
          exit(EXIT_FAILURE);
        }
        else
          printf("\n");

        size_t new_task_length = strlen(new_task);
        if (new_task_length > 0 && new_task[new_task_length - 1] == '\n')
          new_task[new_task_length - 1] = '\0';
        else
          while (getchar() != '\n');

        add_task(new_task);

        break;
    }
  }

  return 0;
}
