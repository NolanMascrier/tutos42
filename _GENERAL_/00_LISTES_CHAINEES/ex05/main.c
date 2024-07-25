/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:43:07 by nmascrie          #+#    #+#             */
/*   Updated: 2024/03/09 22:43:12 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void   hero_cut(t_hero **hero, int n)
{
    int i;
    t_hero *bck;
    t_hero *ptr;

    i = 0;
    if (n < 0)
        return ;
    ptr = (*hero);
    if (n == 0)
    {
        bck = ptr->next;
        if (ptr->name)
                free(ptr->name);
        free(ptr);
        (*hero) = bck;
        return ;
    }
    while (ptr)
    {
        if ((i + 1) == n)
            bck = ptr;
        if (i == n)
        {
            bck->next = ptr->next;
            if (ptr->name)
                free(ptr->name);
            free(ptr);
            break ;
        }
        else 
        i++;
        if (!ptr->next)
            break ;
        ptr = ptr->next;
    }
}

int main(void)
{
    t_hero *h;

    h = ft_calloc(1, sizeof(t_hero));
    printf("-----------------LISTE 1-----------------\n");
    hero_add(h, "Chris", 200);
    hero_add(h, "Jill", 110);
    hero_add(h, "Leon", 120);
    hero_add(h, "Albert", 999);
    hero_add(h, "Ashley", 3);
    hero_add(h, "Sheva", 105);
    hero_add(h, "Barry", -6);
    hero_print_all(h);
    printf("-------------------CUT-------------------\n");
    hero_cut(&h, 3);
    hero_print_all(h);
    printf("-------------------CUT-------------------\n");
    hero_cut(&h, 5);
    hero_print_all(h);
    printf("-------------------CUT-------------------\n");
    hero_cut(&h, 0);
    hero_print_all(h);
    free_memory(h);
}
