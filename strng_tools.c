#include "shell.h"

char *_strdup(const char *str)
{
	int   len = 0;
	int	size;
	char	*new_str;
	while (str[len])
		len++;
	size = len + 1;
	if(!(new_str = malloc(sizeof(char) * size)))
		return (NULL);
	len = 0;
	while (str[len])
	{
		new_str[len] = str[len];
	len ++;
	}
	new_str[len] = '\0';
	return (new_str);
}


// For Strcmp
int _strcmp(char *s1, char *s2)
{
        int equal = 0;

        while (*s1)
        {
                if (*s1 != *s2)
                {
                        equal = ((int)*s1) - ((int)*s2);
                        break;
                }
                s1++;
                s2++;
        }
        return (equal);
}

//For strlen

int _strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0'){
        i++;
    }
    return (i);
}

//For strcat
char	*_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// For strcpy
char    *_strcpy(char *dest, char *src) 
{
    int	i;

	i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i]; 
        i++;
    }
    //(end of string)
    dest[i]='\0';
    return (dest);

}
