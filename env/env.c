#include "../minishell.h"

char *trim_from_to(char *s, int from, int to)
{
    char *str;
    int i;

    str = malloc(sizeof(char) * (to - from) + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (from < to)
    {
        str[i] = s[from];
        from++;
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *env_key(char *str)
{
    char *key;
    int i;

    i = -1;
    while (str[++i])
    {
        if (str[i] == '=')
            return (key = trim_from_to(str, 0, i));
    }
    return (NULL);
}

int init_env(char **env)
{
    t_env *env_node;
    t_env *new_node;
    int i;

    env = malloc(sizeof(t_env));
    if (!env)
        return (0);
    i = 1;
    env_node->key = env_key(env[0]);
    env_node->val = ft_strdup(getenv(env_node->key));
    env_node->next = NULL;
    while (env && env[i])
    {
        new_node = malloc(sizeof(t_env));
        if (!new_node)
            return (0);
        new_node->key = env_key(env[i]);
        new_node->val = ft_strdup(getenv(new_node->key));
        new_node->next = NULL;
        env_node->next = new_node;
        env_node = new_node;
        i++;
    }
    return (0);
}