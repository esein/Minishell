#include "minishell.h"

int	main()
{
	char	*pwd;
	//	execve("~/Mygit/ft_ls/ft_ls", NULL, NULL);
	pwd = NULL;
	pwd = getcwd(pwd, 0);
	ft_putendl(pwd);
	if (chdir("../") < 0)
		ft_putstr("bon");
	free(pwd);
	pwd = NULL;
	pwd = getcwd(pwd, 0);
	ft_putstr(pwd);
	return (0);
}

