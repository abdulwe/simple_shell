#include "hsh.h"

/**
 * remove_reply - remove comments (#) from a command
 * @cmd: pointer to the cmd to process
 */
void remove_reply(cmdlist_t *cmd)
{
	char **tokens, **new, *tmp;

	for (tokens = cmd->tokens; *tokens; ++tokens)
	{
		if (**tokens == '#')
		{
			tmp = *tokens;
			*tokens = NULL;
			new = arrdup(cmd->tokens);
			*tokens = tmp;
			free_tokens(&(cmd->tokens));
			cmd->tokens = new;
			free_cmdlist(&(cmd->next));
			return;
		}
	}
}
