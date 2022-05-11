#include "../minishell.h"

int outfile_len(t_comp *head)
{
    int len;

    len = 0;
    while (head)
    {
        if (head->whatisthis == 4)
            len++;
        head = head->next;
    }
    return (len);
}

char *opens_files(char **files, int len)
{
    int i;
    int fd;

    i = 0;
    while (i < len)
    {
        if (files[i + 1] == NULL)
            return (files[i]);
        else 
        {
            fd = open(files[i], O_WRONLY | O_CREAT,  0666);
            close(fd);
        }
        i++;
    }
    return (NULL);
}

char *is_outfile(t_comp *head)
{
    char **files;
    int i;
    int len;

    len = outfile_len(head);
    files = malloc(sizeof(char *) * (len + 1));
    i = 0;
    if (!head || !files)
        return (NULL);
    while (head != NULL)
    {
        if (head->whatisthis == 4)
        {
            files[i] = head->data;
            i++;
        }
        head = head->next;
    }
    return (opens_files(files, len));
}

char *infile_files(char **files, int len)
{
    int i;
    int fd;

    i = 0;
    while (i < len)
    {
        if (files[i + 1] == NULL)
            return (files[i]);
        else 
        {
            fd = open(files[i], O_RDONLY);
            if (fd == -1)
            {
                ft_putstr_fd("minishell: no such file or directory: ", 1);
                ft_putstr_fd(files[i], 1);
                printf("\n");
                break ;
            }
            if (fd != -1)
                close(fd);
        }
        i++;
    }
    return (NULL);
}

int infile_len(t_comp *head)
{
    int len;

    len = 0;
    while (head)
    {
        if (head->whatisthis == 3)
            len++;
        head = head->next;
    }
    return (len);
}

char *is_infile(t_comp *head)
{
    char **files;
    int i;
    int len;

    len = infile_len(head);
    files = malloc(sizeof(char *) * (len + 1));
    i = 0;
    if (!head || !files)
        return (NULL);
    while (head != NULL)
    {
        if (head->whatisthis == 3)
        {
            files[i] = head->data;
            i++;
        }
        head = head->next;
    }
    return (infile_files(files, len));
}