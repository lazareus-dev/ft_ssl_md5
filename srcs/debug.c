#include "../includes/ft_ssl.h"
#include "../includes/ssl_md5.h"

void	debug_arg(t_arg *arg)
{
	dprintf(1, "***DEBUG ARG ***\n");
	dprintf(1, "\t*** arg_type [%d]\n", arg->type);
	dprintf(1, "\t*** filename [%s]\n", arg->filename);
	dprintf(1, "\t*** fd [%d]\n", arg->fd);
	dprintf(1, "\t*** arg.arg_content [%s]\n", arg->argument.content);
	dprintf(1, "\t*** arg.arg_len [%zu]\n", arg->argument.len);
}

void	debug_params(t_md5_transform *param)
{
	dprintf(1, "***DEBUG PARAM***\n");
	dprintf(1, "\tparam->a = [%u]\n", param->a);
	dprintf(1, "\tparam->b = [%u]\n", param->b);
	dprintf(1, "\tparam->c = [%u]\n", param->c);
	dprintf(1, "\tparam->d = [%u]\n", param->d);
	for (size_t i = 0; i < 16; i++)
		dprintf(1, "\tparam->m[%zu] = [%u]\n", i, param->m[i]);
}

void	debug_md5_ctx(t_md5_ctx *ctx)
{
	dprintf(1, "***DEBUG CTX***\n");
	for (size_t i = 0; i < ctx->datalen; i++)
		dprintf(1, "\tdata = [%c]\n", ctx->data[i]);
	dprintf(1, "\tdatalen = [%zu]\n", ctx->datalen);
	dprintf(1, "\tbitlen[0],[1] = [%u],[%d]\n", ctx->bitlen[0], ctx->bitlen[1]);
	for (size_t i = 0; i < 4; i++)
		dprintf(1, "\tstate[%zu] = [%u]\n", i, ctx->state[i]);
}