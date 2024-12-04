#include "get_next_line.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

s_list* ft_lstnew()
{
    s_list* list;

    list = (s_list *)malloc(sizeof(s_list));
    if(!list)
        return (NULL);
    list->next = NULL;
    return (list);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str1;
	char	*str2;
	int		i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	str = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1)
			* sizeof(char));
	if (!str)
		return (NULL);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (*str2)
	{
		str[i++] = *str2;
		str2++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_s;
	size_t	i;

	len_s = (size_t)ft_strlen(s);
	i = 0;
	if (start >= len_s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = (char *)malloc(((len) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len && start < len_s)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

