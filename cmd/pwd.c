#include "../minishell.h"

int main(int argc, char **argv)
{
    char *path;
    (void)argv;
    if (argc > 2)
        printf("to many parameters\n");
    else if (argc == 1)
    {
        path = getcwd(path, 50);
        printf("%s\n", path);
    }
    return (0);
}