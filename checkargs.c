
#include"push_swap.h"

int	check_dub(t_list *list)
{
	int		count;
	t_list	*temp;

	count = 0;
	while (list->next != NULL)
	{
		temp = list->next;
		while (temp != NULL)
		{
			if (list->value == temp->value)
			{
				count++;
				return (0);
			}
			temp = temp->next;
		}
		list = list->next;
	}
	return(1);
}
	
int	isnum(char	*str)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while(str[i])
	{
		if (!
				ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
