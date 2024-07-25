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

t_hero *hero_get_tail(t_hero *hero)
{
    if (!hero->next)
        return (hero);
    else 
        return (hero_get_tail(hero->next));
}

void   hero_push(t_hero **hero, char *name, int power)
{
    t_hero *this;

    this = ft_calloc(1, sizeof(t_hero));
    hero_init(this, name, power);
    this->next = (*hero);
    (*hero) = this;
}

int main(void)
{
    t_hero *h;

    h = ft_calloc(1, sizeof(t_hero));
    printf("-----------------LISTE 1-----------------\n");
    hero_add(h, "Chris", 200);
    hero_add(h, "Jill", 110);
    hero_add(h, "Barry", -6);
    hero_print_all(h);
    printf("--------------QUEUE DE LISTE--------------\n");
    hero_print(hero_get_tail(h));
    printf("-------------------PUSH-------------------\n");
    hero_push(&h, "Albert", 999);
    hero_print_all(h);
    free_memory(h);
}
