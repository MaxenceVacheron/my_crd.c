
char **my_str_to_word_array(const char *str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }
    char **word;

    // int str_word_count = word_count(str);
    word = malloc((2) * sizeof(char *)); // why this is necessary I don't know

    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < 2; i++)
    {
        word[i] = malloc((len) * sizeof(char));
    }

    int c = 0;

    while (str[c] != '\0')
    {

        if (str[c] != ' ')
        {
            word[j][k++] = str[c];
        }
        else
        {
            word[j][k++] = '\0';
            j++;
            k = 0;
        }
        c++;
    }
    // int a = 0;
    // int b = 0;
    // while (word[a] != NULL)
    // {
    //     printf("%s\n", word[a]);
    //     while (word[a][b] != '\0')
    //     {
    //         printf("%c\n", word[a][b]);
    //         ++b;
    //     }
    //     b = 0;
    //     ++a;
    // }
    return (word);
}