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

void  hero_init_alt(t_hero *hero, t_hero *add)
{
    hero->name = add->name;
    hero->power = add->power;
    hero->next = add->next;
}

static int point_already_chained(t_hero *hero, t_hero *add)
{
    if (!hero || !add)
        return (0);
    else if (hero == add)
        return (1);
    else if (!hero->next)
        return (0);
    else 
        return (point_already_chained(hero->next, add));
}

void  hero_add_alt(t_hero *hero, t_hero *add)
{
    if (!add || point_already_chained(hero, add))
        return ;
    if (!hero || !hero->name)
        hero_init_alt(hero, add);
    else if (!hero->next)
    {
        hero->next = add;
        while (add->next)
        {
            if (add->next && add->next && !point_already_chained(hero, add->next))
            {
                add->next = NULL;
                break ;
            }
            add = add->next;
        }
    }
    else
        hero_add_alt(hero->next, add);
}

int main(void)
{
    t_hero *h;
    t_hero *h2;

    h = ft_calloc(1, sizeof(t_hero));
    printf("-----------------LISTE 1-----------------\n");
    hero_add(h, "Chris", 200);
    hero_add(h, "Jill", 110);
    hero_add(h, "Barry", -6);
    hero_print_all(h);
    h2 = ft_calloc(1, sizeof(t_hero));
    printf("-----------------LISTE 2-----------------\n");
    hero_add(h2, "Luis", 50);
    hero_add(h2, "Leon", 130);
    hero_add(h2, "Ada", 999);
    hero_add(h2, "Ashley", 2);
    hero_print_all(h2);
    printf("-----------------AJOUTS-----------------\n");
    hero_add_alt(h, h2);
    hero_print_all(h);
    t_hero *h3 = ft_calloc(1, sizeof(t_hero));
    hero_add_alt(h3, h);
    hero_print_all(h3);
    printf("--------------AJOUTS-BOUCLE--------------\n");
    hero_add_alt(h, h2);
    hero_print_all(h);
    free_memory(h);
    free(h3);
}
