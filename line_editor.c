#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;
void displayDocument()
{
    int i;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    for (i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }
}
void insertLine()
{
    int lineNumber;
    int i;

    printf("Enter line number to insert: ");
    scanf("%d", &lineNumber);

    getchar();

    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    if (lineCount >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    for (i = lineCount; i >= lineNumber; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    printf("Enter text: ");
    fgets(lines[lineNumber - 1], MAX_LENGTH, stdin);

    lines[lineNumber - 1][strcspn(lines[lineNumber - 1], "\n")] = '\0';

    lineCount++;

    printf("Line inserted successfully.\n");
}
void deleteLine()
{
    int lineNumber;
    int i;

    printf("Enter line number to delete: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (i = lineNumber - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}
void saveFile()
{
    FILE *file;
    int i;

    file = fopen("document.txt", "w");

    if (file == NULL)
    {
        printf("Unable to save file.\n");
        return;
    }

    for (i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("Document saved successfully.\n");
}
void loadFile()
{
    FILE *file;

    lineCount = 0;

    file = fopen("document.txt", "r");

    if (file == NULL)
    {
        printf("No saved file found.\n");
        return;
    }

    while (lineCount < MAX_LINES &&
           fgets(lines[lineCount], MAX_LENGTH, file) != NULL)
    {
        lines[lineCount][strcspn(lines[lineCount], "\n")] = '\0';
        lineCount++;
    }

    fclose(file);

    printf("Document loaded successfully.\n");
}
void showHelp()
{
    printf("\n========== HELP ==========\n");
    printf("insert  - Insert a new line\n");
    printf("delete  - Delete a line\n");
    printf("display - Display the document\n");
    printf("save    - Save the document\n");
    printf("load    - Load the saved document\n");
    printf("search  - Search text in the document\n");
    printf("help    - Show available commands\n");
    printf("exit    - Exit the editor\n");
    printf("==========================\n");
}
void searchLine()
{
    char keyword[MAX_LENGTH];
    int i;
    int found = 0;

    printf("Enter text to search: ");
    fgets(keyword, MAX_LENGTH, stdin);

    keyword[strcspn(keyword, "\n")] = '\0';

    for (i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], keyword) != NULL)
        {
            printf("Found in line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Text not found.\n");
    }
}

int main()
{
    char command[50];
    printf("=================================\n");
    printf("       SIMPLE LINE EDITOR\n");
    printf("=================================\n");
    printf("Type 'help' to see available commands.\n");
    
    while (1)
    {
        printf("\n> ");
        scanf("%s", command);
        getchar();

        if (strcmp(command, "insert") == 0)
        {
            insertLine();
        }
        else if (strcmp(command, "display") == 0)
        {
            displayDocument();
        }
        else if (strcmp(command, "delete") == 0)
        {
            deleteLine();
        }
        else if (strcmp(command, "save") == 0)
        {
            saveFile();
        }
        else if (strcmp(command, "load") == 0)
        {
            loadFile();
        }
        else if (strcmp(command, "help") == 0)
        {
            showHelp();
        }
            else if (strcmp(command, "search") == 0)
        {
            searchLine();
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Unknown command.\n");
        }
    }

    printf("Type 'help' to see available commands.\n");


    return 0;
}