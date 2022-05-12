
#include "../minishell.h"

static	int		num_of_args(t_comp *comp)
{
	int		num;

	num = 0;
	while (comp)
	{
		comp = comp->next;
		num++;
	}
	return (num);
}

void ft_exit(t_comp *comp)
{
    char *tmp;
    int i;

    if (num_of_args(comp) > 2)
    {
        ft_putstr_fd("exit\n", 1);
        printf("minishell: exit: Too many parametres\n");
    }
    else if (num_of_args(comp) == 2)
    {
        tmp = comp->next->data;
        i = 0;
        while (tmp[i])
        {
            if (!ft_isdigit(tmp[i]))
            {
                ft_putstr_fd("exit\n", 1);
                printf("minishell: exit: numeric argument required\n");
                exit(255);
            }
            i++;
        }
        ft_putstr_fd("exit\n", 1);
        exit(ft_atoi(tmp));
    }
    else
    {
        ft_putstr_fd("exit\n", 1);
        exit(0);
    }
}