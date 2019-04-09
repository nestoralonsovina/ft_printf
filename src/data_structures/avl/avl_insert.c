#include "avl.h"

static int 	avl_height(t_avl_node *n)
{
	if (n == NULL)
		return (0);
	return (n->height);
}

static int 		avl_get_balance(t_avl_node *n)
{
	if (n == NULL)
		return (0);
	return (avl_height(n->left) - avl_height(n->right));
}

static t_avl_node	*avl_right_rotate(t_avl_node *root)
{
	t_avl_node *left_child;
	t_avl_node *temp;

	left_child = root->left;
	temp = left_child->right;

	left_child->right = root;
	root->left = temp;

	return (left_child);
}

static t_avl_node	*avl_left_rotate(t_avl_node *root)
{
	t_avl_node	*right_child;
	t_avl_node	*temp;

	right_child = root->right;
	temp = right_child->left;

	right_child->left = root;
	root->right = temp;

	root->height = ft_max(avl_height(root->left), avl_height(root->right)) + 1;
	right_child->height = ft_max(avl_height(right_child->left), avl_height(right_child->right)) + 1;
	return right_child;
}

static t_avl_node		*avl_insert_node(t_avl_node *node, unsigned long key, int index)
{
	int	balance;

	if (node == NULL)
		return (new_avl_node(key, index));

	if (key < node->key) {
		node->left = avl_insert_node(node->left, key, index);
		if (node->left == NULL)
			return (NULL);
	}
	else if (key > node->key) {
		node->right = avl_insert_node(node->right, key, index);
		if (node->right == NULL)
			return (NULL);
	}
	else
		return (NULL);


	node->height = 1 + ft_max(avl_height(node->left), avl_height(node->right));
	balance = avl_get_balance(node);

	if (balance > 1 && key < node->left->key)
		return (avl_right_rotate(node));

	if (balance < -1 && key > node->right->key)
		return (avl_left_rotate(node));

	if (balance > 1 && key > node->left->key)
	{
		node->left = avl_left_rotate(node->left);
		return (avl_right_rotate(node));
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = avl_right_rotate(node->right);
		return (avl_left_rotate(node));
	}

	return (node);
}

int				avl_insert(t_avl *self, unsigned long key, int index)
{
	t_avl_node *tmp;

	tmp = avl_insert_node(self->head, key, index);
	if (tmp == NULL)
	{
		self->free(self->head);
		return (0);
	}
	self->head = tmp;
	return (1);
}
