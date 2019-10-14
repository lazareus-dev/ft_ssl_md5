#include "../includes/ft_ssl.h"

void	debug_arg(t_arg *arg)
{
	dprintf(1, "***DEBUG ARG ***\n");
	dprintf(1, "\t*** arg_type [%d]\n", arg->type);
	dprintf(1, "\t*** filename [%s]\n", arg->filename);
	dprintf(1, "\t*** fd [%d]\n", arg->fd);
	dprintf(1, "\t*** arg.arg_content [%s]\n", arg->argument.content);
	dprintf(1, "\t*** arg.arg_len [%zu]\n", arg->argument.len);
}