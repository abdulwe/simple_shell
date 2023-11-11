#include "builtins.h"

/**
 * __cd_error - print an error upon failure to change directory
 * @info: shell info
 * @dir: directory
 */
void __cd_error(info_t *info, char *dir)
{
	char *error = strjoin(NULL, " ", "can't cd to", dir);

	perrorl_default(*info->argv, info->lineno, error, *info->tokens, NULL);

	info->status = 2;

	free(error);
}
