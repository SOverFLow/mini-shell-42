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
            if (fd == -1)
                perror(files[i]);
            close(fd);
        }
        i++;
    }
    return (NULL);
}

char *infile_files(char **files, int len)
{
    int i;
    int fd;

    i = 0;
    while (i < len)
    {
        if (files[i + 1] == NULL)
        {
            fd = open(files[i], O_RDONLY);
            close(fd);
            if (fd == -1)
            {
                ft_putstr_fd("minishell: no such file or directory: ", 1);
                ft_putstr_fd(files[i], 1);
                printf("\n");
                return (NULL);
            }
            return (files[i]);
        }
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