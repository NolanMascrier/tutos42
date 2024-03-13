# Exercice 3 - ça se complique
Reprenez le code de l'exercice précédant. Ajoutez des alternatives a `hero_add()` et `hero_init()`, qui prendront un pointeur vers un chainon a la place. Utilisez les en-têtes suivantes :
```C
void  hero_init_alt(t_hero *hero, t_hero *add);
void  hero_add_alt(t_hero *hero, t_hero *add);
```
`add` étant bien entendu le chainon venant se greffer a notre liste. N'oubliez pas de créer un programme de test.

> [!IMPORTANT]
> Assurez vous que la liste ne boucle pas, c'est-a-dire que le pointeur next d'un chainon ne peut pas renvoyer vers un chainon se situant _avant_ le chainon courant.
>
> Avoir une liste bouclante n'est pas un interdit, vous pourrez peut être en avoir besoin un jour ou un autre. Mais pas aujourd'hui ...

## Explications

Cet exercice est un peu plus compliqué, et il vous demande un peu d'imagination pour faire face au plus gros problème : comment éviter la boucle ? 

Pour l'éviter, on va faire en sorte que l'ajout vérifie si le pointeur vers le suivant ne pointe pas déjà vers un des chainons de la chaine. 

En premier lieu, créeons la dite vérification. 
```C
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
```
On s'assure en premier lieu que les chainons existent. Ensuite, puisque les valeurs passées en argument sont des pointeurs, il n'y a qu'a les comparer ! Si les pointeurs sont égaux, celà signifie que le pointeur existe déjà dans la chaine, donc il y a un risque de boucle ... 
Sinon, on regarde si un suivant existe. Si c'est n'est pas le cas, on est en bout de chaine, et aucune boucle possible n'a étée trouvée - donc, tout va bien.
Et dans le dernier cas, on rappelle la vérification de manière récursive. 

Il n'y a plus qu'a utiliser cette fonction pour faire l'ajout. Comme pour l'ajout normal, on va séparer l'ajout en trois cas. Le troisième cas, le cas général, étant simplement un moyen de ramener la situation au cas 2, n'a pas besoin de plus de détails, le raisonnement étant le même. 
Dans le second cas, on va simplement remplacer le pointeur vers le chainon suivant (qui vaut NULL ...). Vous pouvez ainsi visualiser le raccord entre les deux chaines. Cependant, il faut aussi vérifier qu'il n'y a pas de boucle dans la partie qu'on a rajouté ... 
```C
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
```
C'est ici que ça devient plus complexe. Comme notre fonction vérifie l'entièreté de la chaine initiale par rapport a un seul chainon de la chaine a ajouter, c'est sur cette dernière qu'on va devoir itérer ! En effet, puisque l'ajout ne _copie_ pas la seconde chaine mais la "raccroche" juste, modifier une modifiera égalemment l'autre. Lors de notre itération, on va appeller notre fonction de vérification sur chaque chainon. Si jamais une boucle est trouvée, on va _briser_ cette dernière, simplement en changeant le pointeur du chainon suivant par un NULL. 

Le premier cas est un peu particulier. En effet, il est strictement impossible de rendre le pointeur du premier chainon égal au deuxième, vu que celui ci a déjà été initialisée via un malloc. Dans cette situation, on copiera les _pointeurs_ de chaque valeurs, et non pas les valeurs en elle-même (sauf pour power, qui est un int).

## Pour aller plus loin ...
Vous avez remarqué sans aucun doute que lors de la copie dans le premier cas, on copie les pointeurs. En effet, ce qu'on cherche a obtenir ici sont _deux_ chaines qui occupent la même zone de mémoire. Donc, lors de nos copies, on va copier uniquement les pointeurs; celà s'appelle une _copie superficielle_. Seul le premier chainon est différent, et a donc de la mémoire allouée : d'où l'unique `free()` a la fin du main ...

L'inverse de la copie superficielle est appellée _copie pronfonde_. Dans cette situation, on devra recrée la chaine (donc, chaque chainon sera initialisée via malloc), et chaque valeur copiée via une duplication. Ainsi, on obtient deux chaines différentes, dont les pointeurs seront différents, mais dont l'ensemble des champs (autres que les pointeurs) seront identiques a la première.

Dans l'absolu, on préfère presque tout le temps une copie profonde. Cependant, la copie superficielle peut avoir ses avantages, comme dans notre cas actuel ... 