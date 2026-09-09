#include <stdio.h>
#include <string.h>

void bruteForce(char message[130], int keyLength, int firstWordLength);
int main()
{
    // gets the message from the user and removes the newline
    char message[130];
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    int keyLength;
    printf("Enter the key length: ");
    scanf("%d", &keyLength);

    int firstWordLength;
    printf("Enter the first word length: ");
    scanf("%d", &firstWordLength);

    bruteForce(message, keyLength, firstWordLength);

    for (int i = 0; message[i] != '\0'; ++i)
    {
        printf("%c", message[i]);
    }
}

void bruteForce(char message[130], int keyLength, int firstWordLength)
{
    char *key = malloc(keyLength);
    int 

    int letterIndex = 0;
    for (int i = 0; i < keyLength; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            key[] = keyLength - i + 'A';
        }
        
    }

    free(key);
}