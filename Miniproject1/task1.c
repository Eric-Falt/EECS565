#include <stdio.h>
#include <string.h>
#include <ctype.h>

// removes spaces and sets all characters to uppercases in the given string
void formatString(char inputString[])
{
    // itterates through the string
    for (int i = 0; inputString[i] != '\0'; ++i)
    {
        // if there is a space, shift the string to remove it
        if (inputString[i] == ' ')
        {
            for (int j = i; inputString[j] != '\0'; ++j)
            {
                inputString[j] = inputString[j + 1];
            }

            // fixes the index since we removed a space
            --i;
        }

        // converts each character to lowercase in the string
        if (islower(inputString[i]))
        {
            inputString[i] = toupper(inputString[i]);
        }
    }
}

int main()
{
    // gets the key from the user and formats it
    char key[100];
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    formatString(key);

    // gets the message from the user and formats it
    char message[100];
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    formatString(message);

    int encrypt;
    printf("Enter '0' to encrypt the message, or '1' to decrypt the message");
    scanf("%d", &encrypt);

    // Enter one to encrypt the message or 1 to decrypt it and prints the new message using the key
    if (encrypt == 0)
    {
        for (int i = 0; message[i] != '\0'; ++i)
        {
            printf("%c", ((message[i] - 'A') - (key[i % strlen(key)] - 'A')) % 26 + 'A');
        }
    }
    else
    {
        for (int i = 0; message[i] != '\0'; ++i)
        {
            printf("%c", (message[i] - 'A' - (key[i % strlen(key)] - 'A') + 26) % 26 + 'A');
        }
    }
}
