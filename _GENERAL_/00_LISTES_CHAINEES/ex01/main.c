/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 02:43:13 by nmascrie          #+#    #+#             */
/*   Updated: 2024/03/09 02:43:19 by nmascrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void  hero_init(t_hero *hero, char *name, int power)
{
    hero->name = ft_strdup(name);
    hero->power = power;
    hero->next = NULL;
}

void  hero_print(t_hero *hero)
{
    printf("Hero : %s (Power : %d, ref to next : %p)\n", hero->name, hero->power, hero->next);
}

int main(void)
{
    t_hero h1;
    t_hero *h2;

    hero_init(&h1, "Bob", 42);
    h2 = ft_calloc(1, sizeof(t_hero));
    hero_init(h2, "Jean", 28);
    hero_print(&h1);
    hero_print(h2);
    free(h1.name);
    free(h2->name);
    free(h2);
}