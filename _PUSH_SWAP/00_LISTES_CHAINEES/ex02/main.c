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

void  hero_add(t_hero *hero, char *name, int power)
{
    if (!hero->name)
        hero_init(hero, name, power);
    else if (!hero->next)
    {
        hero->next = ft_calloc(1, sizeof(t_hero));
        hero_init(hero->next, name, power);
    }
    else
        hero_add(hero->next, name, power);
    
}

void  hero_print_all(t_hero *hero)
{
    int i;

    i = 0;
    if (!hero)
    {
        printf("Empty chain !\n");
        return ;
    }
    while (hero)
    {
        printf("Index %d : ", i);
        hero_print(hero);
        hero = hero->next;
        i++;
    }
}

int main(void)
{
    t_hero *h;

    h = ft_calloc(1, sizeof(t_hero));
    printf("-----------------TEST A-----------------\n");
    hero_print_all(h);
    printf("-----------------TEST B-----------------\n");
    hero_add(h, "Bob", 42);
    hero_print_all(h);
    printf("-----------------TEST C-----------------\n");
    hero_add(h, "Jack", 12);
    hero_print_all(h);
    printf("-----------------TEST D-----------------\n");
    hero_add(h, "Hadi", -6);
    hero_print_all(h);
    free(h->next->next->name);
    free(h->next->next);
    free(h->next->name);
    free(h->next);
    free(h->name);
    free(h);
}
