int			len(char const *s, char c)
{
	int	j;

	j = 0;
	if (*s == 0)
		return (1);
	while (*s != 0)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != 0)
		{
			j++;
			while (*s != c && *s != 0)
				s++;
		}
		if (*s == 0)
			break ;
		s++;
	}
	return (j + 1);
}

int			len_p(char const *s, char c)
{

	int	i;
	i = 0;
	while (*s == c && *s != 0)
		s++;
	while (*s != c && *s != 0)
	{
		i++;
		s++;
	}
	return (i + 1);
}

char		*fill_p(char *p, char const *s, char c)
{
	int l;

	l = 0;
	while (s[l] != c && s[l] != 0)
	{
		p[l] = s[l];
		l++;
	}
	return (p);
}

char		**free_p(char **p, char *pp, int a)
{
	while (a > 0)
		free(&pp[--a]);
	free(p);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	static int	m;
	char		**p;
	int			q;
	int			r;

	if (s == 0)
		return (NULL);
	q = len(s, c);
	if (!(p = (char **)ft_calloc(sizeof(char*), q)))
		return (NULL);
	while (m < q - 1)
	{
		if (!(p[m] = (char *)ft_calloc(sizeof(char), len_p(s, c))))
			return (free_p(p, p[m], m));
		r = len_p(s, c);
		while (*s == c)
			s++;
		p[m] = fill_p(p[m], s, c);
		s = s + (r - 1);
		m++;
	}
	return (p);
}