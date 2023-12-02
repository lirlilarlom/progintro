#include <cstdio>

bool isLetter(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

bool checkInput (int *b)
{
    int a[26]{};
    char c;

    for (int i = 0; i < 26; i++)
    {
        scanf("%c\n", &c);
        if (c < 'a' || c > 'z') return 0;

        a[c - 'a']++;
        b[i] = c - 'a' - i;
    }

    for (int i = 0; i < 26; i++)
    {
        if (a[i] != 1) return 0;
    }


    return 1;
}

void encrypt(int arrInput[26])
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z') c += arrInput[c - 'a'];
        else if (c >= 'A' && c <= 'Z') c += arrInput[c - 'A'];

        putchar(c);
    }
}

int main()
{
    int arrInput[26]{};
    int c;

    if (!checkInput(arrInput))
    {
        printf("error\n");
        return 0;
    }

    encrypt(arrInput);

    return 0;
}
