#include "../minishell.h"

char *is_outfile(t_comp *head)
{
    char *last;
    int out;

    if (!head)
        return (NULL);
    while (head != NULL)
    {
        if (head->whatisthis == 4)
        {
            out = open(head->data, O_WRONLY | O_CREAT, 0666);
            last = head->data;
        }
        head = head->next;
    }
    return (last);
}

char *is_infile(t_comp *head)
{
    if (!head)
        return (NULL);
    while (head != NULL)
    {
        if (head->whatisthis == 3)
            return (head->data);
        head = head->next;
    }
    return (NULL);
}