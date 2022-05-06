#include "../minishell.h"

int is_var_valid(char *str)
{
    int i;

    i = 0;
    while (str[i] != NULL)
    {
        if (i == 0 && ft_isdigit(str[i]))
            return (0);
        if (!(ft_isalnum(str[i])) && str[i] != '_')
            return (0);
        i++;
    }
    return (1);
}

void free_env(t_env *env_node)
{
    if (env_node->next == NULL)
    {
        env_node->key = NULL;
        env_node->val = NULL;
        env_node->next = NULL;
        return ;
    }
}

void ft_unset(char **args, t_env *env_node)
{
    t_env *tmp_node;

    if (ft_strncmp(args[1], env_node->key, ft_strlen(env_node->key)) == 0)
    {
        free_env(env_node);
        return ;
    }
    while (env_node && env_node->next != NULL)
    {
         if (ft_strncmp(args[1], env_node->next->key, ft_strlen(env_node->next->key)) == 0)
         {
             tmp_node = env_node->next->next;
             free_env(env_node->next);
             env_node->next = tmp_node;
             return ;
         }
         env_node = env_node->next;
    }
}