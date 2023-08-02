#include "binary_trees.h"

/**
 * create_queue - creates a new queue
 *
 * Return: newly creqted queue
 */
queue_t *create_queue()
{
	queue_t *queue = malloc(sizeof(queue_t));

	if (queue != NULL)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	return (queue);
}

/**
 * enqueue - a function that adds a new node to the end of the queue
 *
 * @queue: queue to add node
 *
 * @node: node from the binary tree to be added to the queue
 *
 * Return: void
 */
void enqueue(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (new_node == NULL)
		return;

	new_node->node = node;
	new_node->next = NULL;

	if (queue->rear == NULL)
	{
		queue->front = new_node;
		queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

/**
 * dequeue - remove and return the head node from the queue
 *
 * @queue: queue to remove head node from
 *
 * Return: altered queue
 */
binary_tree_t *dequeue(queue_t *queue)
{
	if (queue->front == NULL)
		return (NULL);

	binary_tree_t *node = queue->front->node;
	queue_node_t *temp = queue->front;
	queue->front = queue->front->next;

	if (queue->front == NULL)
		queue->rear = NULL;

	free(temp);
	return (node);
}

/**
 * destroy_queue - frees any allocated memory in the queue
 *
 * @queue: queue with memory to be deleted
 *
 * Return: void
 */
void destroy_queue(queue_t *queue)
{
	if (queue == NULL)
		return;

	while (queue->front != NULL)
	{
		queue_node_t *temp = queue->front;
		queue->front = queue->front->next;
		free(temp);
	}

	free(queue);
}

/**
 * binary_tree_levelorder - a function that goes through a binary tree
 * using level-order traversal
 *
 * @tree: pointer to the root node
 *
 * @func: function that prints the tree value at each travsal
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;
	binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;

	queue = create_queue();

	if (queue == NULL)
		return;

	enqueue(queue, (binary_tree_t *)tree);

	while (queue->front != NULL)
	{
		current = dequeue(queue);

		func(current->n);

		if (current->left != NULL)
			enqueue(queue, current->left);

		if (current->right != NULL)
			enqueue(queue, current->right);
	}
	destroy_queue(queue);
}
