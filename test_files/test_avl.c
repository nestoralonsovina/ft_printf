#include <stdio.h>
#include "../includes/avl.h"
#include "../includes/libft.h"


void	print_avl(t_avl_node *root) {
	if (root != NULL)
	{
		print_avl(root->left);
		ft_printf("%lx " , root->key);
		print_avl(root->right);
	}		
}

int		main(int ac, char **av) {
	t_avl avl;

	avl = avl_init();

	char **arg = ft_strsplit(av[1], ' ');
	int i = 0;
	while (*arg) {
		if (avl.insert(&avl, ft_djb2(*arg), i) == 0) {
			ft_printf("duplicated node amigo\n");
		}
		i += 1;
		arg += 1;
	}

	char **query = ft_strsplit(av[2], ' ');
	while (*query) {
		ft_printf("index of %s: %d\n", *query, avl.get_index(avl.head, ft_djb2(*query)));
		query += 1;
	}
	print_avl(avl.head);
	
	return 0;
}
