#include "../minishell.h"

char *is_outfile(t_comp *head)
{
    if (!head)
        return (NULL);
    while (head != NULL)
    {
        if (head->whatisthis == 4)
            return (head->data);
        head = head->next;
    }
    return (NULL);
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