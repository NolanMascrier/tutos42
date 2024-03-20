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

static int liste_len(t_hero *h)
{
    int     i;

    i = 0;
    while (h)
    {
        i++;
        h = h->next;
    }
    return (i);
}

void   hero_attack(t_hero **hero, int n, int pow)
{
    t_hero *ptr;
    int i;
    int bck;

    ptr = (*hero);
    i = 0;
    while (1)
    {
        if (n == (i % liste_len(*hero)))
        {
            bck = pow - ptr->power;
            ptr->power -= pow;
            if (ptr->power <= 0)
            {
                printf("%s is DEAD !\n", ptr->name);
                ptr = ptr->next;
                hero_cut(hero, i);
                if (bck > 0)
                {
                    if (n < liste_len(*hero))
                        hero_attack(hero, n, bck);
                    if ((n - 1) >= 0)
                        hero_attack(hero, n - 1, bck);
                }
            }
            return ;
        }
        i++;
        if (!ptr->next)
            return ;
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
    hero_add(h, "Barry", 1);
    hero_print_all(h);
    printf("------------------ATTAQUE-----------------\n");
    hero_attack(&h, 3, 500);
    hero_print_all(h);
    printf("-------------------SOINS------------------\n");
    hero_modify_all(h, &double_truc);
    hero_print_all(h);
    printf("------------------ATTAQUE-----------------\n");
    hero_attack(&h, 1, 500);
    hero_print_all(h);
    printf("------------------ATTAQUE-----------------\n");
    hero_attack(&h, 3, 500);
    hero_print_all(h);
    printf("------------------ATTAQUE-----------------\n");
    hero_attack(&h, 0, 500);
    hero_print_all(h);
    printf("------------------ATTAQUE-----------------\n");
    hero_attack(&h, 0, 500);
    hero_print_all(h);
    free_memory(h);
}
