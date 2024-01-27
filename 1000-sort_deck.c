#include "deck.h"

/**
 * _strcmp - compare two strings
 * @str1: string
 * @str2: string
 * Return: 1 if str1 and str2 are equal, 0 if they are not equal
 */
int _strcmp(const char *str1, const char *str2)
{
	size_t i = 0;

	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return 0;
		i++;
	}

	return (str1[i] == '\0' && str2[i] == '\0');
}

/**
 * get_card_position - return the position based on card value and kind
 * @node: represent the card
 * Return: return the card position
 */
int get_card_position(const deck_node_t *node)
{
	int value;

	if (node->card->value[0] >= '2' && node->card->value[0] <= '9')
		value = node->card->value[0] - '0';
	else if (_strcmp(node->card->value, "10"))
		value = 10;
	else if (_strcmp(node->card->value, "Ace"))
		value = 1;
	else if (_strcmp(node->card->value, "Jack"))
		value = 11;
	else if (_strcmp(node->card->value, "Queen"))
		value = 12;
	else if (_strcmp(node->card->value, "King"))
		value = 13;
	else
		return -1;  /* Invalid card value */

	value += node->card->kind * 13;
	return value;
}

/**
 * swap_card - swap a card for its previous one
 * @card: card
 * @deck: card deck
 * Return: return a pointer to a card which was entered
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;
	
	back->next = current->next;

	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
	current->prev->next = current;
	else
		*deck = current;

	return current;
}

/**
 * insertion_sort_deck - function that sorts a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: Doubly linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	deck_node_t *node;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	
	node = (*deck)->next;

	while (node)
	{
		int value_prev, value_current;

		/* preparing the previous value */
		if (node->prev)
		{
			value_prev = get_card_position(node->prev);
			value_current = get_card_position(node);
		}

		while (node->prev && value_prev > value_current)
		{
			node = swap_card(node, deck);
			/* update values after swapping */
			if (node->prev)
			{
				value_prev = get_card_position(node->prev);
				value_current = get_card_position(node);
			}
		}

		node = node->next;
	}
}

/**
 * sort_deck - sort a deck using the insertion sort algorithm
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
