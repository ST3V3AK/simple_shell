#include "main.h"

char *_getenv(const char *name)
{
	size_t len_name = strlen(name);
	int i;
	char *str;

	i = 0;
	while (environ[i] != NULL)
	{
		if ( (strncmp(environ[i], name, len_name)) == 0 )
		{
			str = (environ[i]);
			break;
		}
		else
			str = NULL;
		i++;
	}
	return (str);
}
