/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmascrie <nmascrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:43:19 by nmascrie          #+#    #+#             */
/*   Updated: 2024/03/09 22:43:24 by nmascrie         ###   ########.fr       */
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