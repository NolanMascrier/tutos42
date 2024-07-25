# Exercice 2 - Enchainer la chaine
Reprenez le code du premier exercice. Ajoutez une fonction qui ajoute un nouveau chainon _a la fin_ de la chaine. De plus, créez une fonction qui affiche _l'entiereté_ de la chaine. Utilisez les en-têtes suivantes :
```C
void  hero_add(t_hero *hero, char *name, int power);
void  hero_print_all(t_hero *hero);
```
> [!CAUTION]
> `hero_add()` DOIT utiliser `hero_init()` !

Créez un programme de test initialisant une chaine, et ajoutant un chainon. L'entièreté de la chaine doit être affiché deux fois, avant et après l'ajout. 

> [!TIP]
> Pour se déplacer dans une chaine, vous devez rendre le chainon courant égal au chainon suivant ... Attention cependant a ne pas le rendre égal a NULL !

Pour cet exercice ainsi que les suivants, nous ajouterons deux fichiers : old.c, contenant les fonctions crées dans les exercices précedants, et new.c, qui contiendra des fonctions crées précédemment, mais mises à jour en fonction des besoins de l'exercice. Vous êtes bien entendu libres de vous organiser comme vous le souhaitez.

## Explications
Nous pouvons déduire trois cas pour notre ajout :
* La chaine est vide
* La chaine ne posséde qu'un élément
* La chaine possède plus d'un élément

Puisque nous utilisons notre ft_calloc pour initaliser la zone mémoire, le cas de la chaine vide n'existe pas, puisque nous savons déjà que l'ensemble des champs est égal a 0, ou NULL. Cela veut dire que notre premier chainon *existe*, il suffit donc de lui donner des valeurs.

```C
    if (!hero->name)
        hero_init(hero, name, power);
```

`hero_init()` va se charger d'initialiser les champs a leur valeur voulues, pas besoin de chercher plus loin ou plus complexe. Quant a la condition, il nous suffit de regarder si l'un des champs n'est pas initialisé : nous utilisons donc le `char *`, car il est entièrement possible que la puissance soit égale à 0. Ainsi, si le nom vaut NULL, le chainon n'est pas initialisé : on utilise alors notre initialisation. 

Le second cas est lorsqu'il n'y a qu'un seul chainon. D'un autre point de vue, n'avoir qu'un seul chainon signifie que le chainon suivant n'existe pas : donc, que le pointeur vers ce dernire vaut NULL.

```C
    else if (!hero->next)
    {
        hero->next = ft_calloc(1, sizeof(t_hero));
        hero_init(hero->next, name, power);
    }
```

Si le pointeur vers le suivant vaut NULL, il nous suffit d'allouer de la mémoire vers next, et d'initialiser les champs via notre fonction d'initialisation. Rien de transcendant, n'est-ce pas ?

Et il nous reste le cas général : il existe plus d'un chainon. Dans cette situation, on va essayer de se ramener vers le second cas : si l'on ne considère que le _dernier chainon_, alors la chaine n'a qu'un seul chainon, n'est-ce pas ? Il suffit alors de parcourir notre chaine jusqu'a son dernier élement. On le fait ici de manière récursive : s'il existe un chainon suivant, on appelle notre ajout dessus. 

```C
    else
        hero_add(hero->next, name, power);
```

Nous avons nos trois cas de gérés. Regardons du coté de l'affichage. Nous avons déjà une fonction nous permettant d'afficher un chainon : il suffit de l'appeller pour chaque chainon. 

On crée alors un boucle : tant que la chaine possède un pointeur vers un autre chainon, on affiche ce chainon, et on passe au suivant. Contrairement a l'ajout, on parcourt notre chaine de manière itérative ici. 

Ce morceau de code vous a peut être interpellé : 

```C
    hero = hero->next;
```

Ici, hero est un _pointeur_ vers la structure : modifier ce dernier ne modifie pas notre structure ! En le modifiant ainsi, on le déplace vers notre chainon suivant. Rappellez vous la piscine : ce pointeur est _une copie locale_ : il n'y a donc aucun danger a le faire bouger ! Modifier la valeur pointée se repercutera sur tout votre programme, mais modifier le pointeur ne le changera que pour la fonction courante.

## Pour approfondir

Pour faire un programme propre, il faut libérer la mémoire, mais on se retrouve confronté a un problème : 

```C
    free(h->next->next->name);
    free(h->next->next);
    free(h->next->name);
    free(h->next);
    free(h->name);
    free(h);
```

Non seulement cette abomination est effrayante, elle risque d'affoler la norminette. Et que faire si votre chaine possède des centaines de champs, avec des dizaines de chainons ? Allez-vous écrire 

```C
    free(h->next->next->next->next->next->next->next->next->next->next->name);
    free(h->next->next->next->next->next->next->next->next->next->next->truc);
    free(h->next->next->next->next->next->next->next->next->next->next->machin);
    free(h->next->next->next->next->next->next->next->next->next->next->bidule);
    ...
```

Bien sur que non - on va écrire une fonction qui va nettoyer notre chaine. le principe est le même que pour l'ajout : vous parcourez votre chaine de manière recursive ou itérative, nettoyez l'ensemble des champs, vous vous assurez qu'il n'y a pas de chainon suivant - dans le cas contraire, appellez la fonction à nouveau - puis vous libérez le chainon. Ce qui nous donnera quelque chose du genre :

```C
void    free_memory(t_hero *h)
{
    if (!h)
        return ;
    if (h->name)
        free(h->name);
    if (h->next)
        free_memory(h->next);
    free(h);
}
```

Je vous laisse la joie de l'écrire de manière itérative, si vous le souhaitez ...