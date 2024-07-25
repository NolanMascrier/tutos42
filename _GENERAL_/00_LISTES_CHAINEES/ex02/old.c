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