/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoumdi <ahoumdi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:34:47 by username          #+#    #+#             */
/*   Updated: 2026/10/28 18:19:28 by ahoumdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;
	t_list *next;

	if (lst == NULL)
		return;
	if (*lst == NULL)
		return;

	current = *lst;
	while (current != NULL)
	{
		next= current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static void del_content(void *content)
{
    free(content);
}

static char *make_content(const char *str)
{
    char *copy = malloc(strlen(str) + 1);
    if (copy != NULL)
        strcpy(copy, str);
    return copy;
}

int main(void)
{
    t_list *head;
    t_list *a;
    t_list *b;
    t_list *c;

    /* Test 1: Empty list */
    head = NULL;
    ft_lstclear(&head, del_content);
    printf("Test 1 - empty list: %s\n",
        head == NULL ? "PASS" : "FAIL");

    /* Test 2: NULL pointer-to-pointer */
    ft_lstclear(NULL, del_content);
    printf("Test 2 - NULL lst: survived call\n");

    /* Test 3: Multiple nodes */
    a = ft_lstnew(make_content("first"));
    b = ft_lstnew(make_content("second"));
    c = ft_lstnew(make_content("third"));

    if (a == NULL || b == NULL || c == NULL)
    {
        /* Simplify cleanup if an allocation failed. */
        if (a != NULL)
            ft_lstclear(&a, del_content);
        if (b != NULL)
            ft_lstclear(&b, del_content);
        if (c != NULL)
            ft_lstclear(&c, del_content);
        return (1);
    }

    a->next = b;
    b->next = c;
    head = a;

    ft_lstclear(&head, del_content);
    printf("Test 3 - multiple nodes: %s\n",
        head == NULL ? "PASS" : "FAIL");

    return (0);
}

