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

t_hero *hero_get_tail(t_hero *hero)
{
    if (!hero->next)
        return (hero);
    else 
        return (hero_get_tail(hero->next));
}

void   hero_cut_if(t_hero **hero, int (*f)(int))
{
    int i;
    t_hero *h;

    i = 0;
    h = (*hero);
    while (h)
    {
        if (f(h->power))
        {
            hero_cut(hero, i);
            i = 0;
            h = (*hero);
        }
        else 
            i++;
        if (!h || !h->next)
            return ;
        h = h->next;
    }
}

void   hero_modify_all(t_hero *hero, int (*f)(int))
{
    while (hero)
    {
        hero->power = f(hero->power);
        hero = hero->next;
    }
}