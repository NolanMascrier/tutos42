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

int     double_truc(int a)
{
    return (a * 2);
}

int     is_big(int a)
{
    return (a >= 400);
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
    printf("-------------------DOUBLE-----------------\n");
    hero_modify_all(h, &double_truc);
    hero_print_all(h);
    printf("-------------------CUTIF-----------------\n");
    hero_cut_if(&h, &is_big);
    hero_print_all(h);
    printf("-------------------DOUBLE-----------------\n");
    hero_modify_all(h, &double_truc);
    hero_print_all(h);
    printf("-------------------CUTIF-----------------\n");
    hero_cut_if(&h, &is_big);
    hero_print_all(h);
    free_memory(h);
}
