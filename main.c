#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_options()
{
  printf("0. Quit program\n");
  printf("1. Add a new task item\n");
  printf("2. Remove an existing task item\n");
  printf("3. Display the task list\n");

  printf("\n");
}

void add_task(const char *new_task);
void remove_task(int task_number);
void display_tasks();

int main()
{
  int user_choice;

  do
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
        char new_task[50];
        
        printf("New task: ");
        if (fgets(new_task, 50, stdin) == NULL)
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

      case 2:
        int task_to_delete;

        printf("Task to remove (number): ");
        if (scanf("%d", &task_to_delete) != 1)
        {
          printf("\nWrong format inputted.\nPlease provide an integer.\n\n");

          while (getchar() != '\n');

          continue;
        }
        else
          printf("\n");

        remove_task(task_to_delete);

        break;

      case 3:
        display_tasks();
        break;
    }

  } while (user_choice != 0);

  return 0;
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

void remove_task(int task_number)
{
  FILE *original_list = fopen("to_do_list.txt", "r");
  FILE *temporary_list = fopen("temporary.txt", "w");

  char file_contents[1024];
  int current_line = 0;

  while (fgets(file_contents, 1024, original_list) != NULL)
  {
    current_line++;

    if (current_line != task_number)
      fputs(file_contents, temporary_list);
  }

  fclose(original_list);
  fclose(temporary_list);

  if (remove("to_do_list.txt") != 0 || rename("temporary.txt", "to_do_list.txt") != 0)
  {
    perror("Error updating file");
    exit(EXIT_FAILURE);
  }
}

void display_tasks()
{
  FILE *to_do_list = fopen("to_do_list.txt", "r");

  if (to_do_list == NULL)
  {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  char character;
  while ((character = fgetc(to_do_list)) != EOF)
    putchar(character);

  printf("\n");

  fclose(to_do_list);
}
