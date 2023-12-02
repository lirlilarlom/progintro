#include <cstdio>

bool isLetter(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

void reverse(int *b)
{
    int temp[26];

    for (int i = 0; i < 26; i++)
    {
        int index = *(b + i) + i;
        temp[index] = -*(b + i);
    }

    for (int i = 0; i < 26; i++)
    {
        b[i] = temp[i];
    }
}

bool checkInput(int *b)
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

void encrypt(int permutation[26])
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z') c += permutation[c - 'a'];
        else if (c >= 'A' && c <= 'Z') c += permutation[c - 'A'];

        putchar(c);
    }
}

void decrypt(int *b)
{
    reverse(b);
    encrypt(b);
}

int main()
{
    int permutation[26];
    int c;

    if (!checkInput(permutation))
    {
        printf("error\n");
        return 0;
    }

    char fn = getchar();
    while ((c = getchar()) != '\n' && c != EOF);

    switch (fn)
    {
        case 'e':
            encrypt(permutation);
            break;

        case 'd':
            decrypt(permutation);
            break;
    }

    return 0;
}
