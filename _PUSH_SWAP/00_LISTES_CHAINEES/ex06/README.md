## Exercice 6 - Perfection
Reprenez le code de l'exercice précédant. Ajoutez une fonction faisant appel a la fonction de coupe si la condition passée en paramètre est respectée. Ajoutez en une autre qui _modifie_ les champs via la fonction passée en paramètre. Le choix de la fonction de modification ainsi que le champ à modifier/vérifier vous est laissé libre, mais je vous recommande un `to_Upper()` pour la modification du char*, et une fonction qui vérifie si l'int vaut 0 ou moins ... 

Utilisez les en-têtes suivantes :
```C
void   hero_cut_if(t_hero *hero, void (*f)(void *));
void   hero_modify_all(t_hero *hero, void (*f)(void *));
```

N'oubliez pas de tester. 
> [!TIP]
> Ce morceau de code bien moche `void (*f)(void *)` permets de passer une fonction en paramètre. Si vous créez la fonction `int is_zero_or_less(int a);`, vous l'enverrez ainsi a votre fonction `hero_cut_if(h2, &is_zero_or_less)` ...

## Explications
Le but de cet exercice est de voir les fonctions passées en arguments. En réalité, ces dernières peuvent être plus considérées comme une curiosité qu'autre chose, vu que vous n'utiliserez que peu ces dernières en C.

On utilisera ces deux fonctions super utiles a passée en argument : 
```C
int     double_truc(int a)
{
    return (a * 2);
}

int     is_big(int a)
{
    return (a >= 400);
}
```
Oui, le but ici sera de doubler la puissance de chaque personnage, et de les retirer de la liste s'ils dépassent 400. Vous êtes bien entendu libres d'utiliser vos propres fonctions à la place ...

Vous remarquez en premier lieu que j'ai changé les en-têtes.

Commençeons par le plus simple, la modification. Ce n'est pas sorcier - il suffit de parcourir la chaine, et d'appliquer votre modification a chaque chainon (ici, on va l'appliquer a power). Oui, c'est tout.

```C
void   hero_modify_all(t_hero *hero, int (*f)(int))
{
    while (hero)
    {
        hero->power = f(hero->power);
        hero = hero->next;
    }
}
```
Pas sorcier, non ? La difficulté était simplement de comprendre comment utiliser la fonction passée en argument. Vous remarquez que j'ai changé l'en-tête de la fonction, `void (*f)(void *)` est devenu `int (*f)(int)`. Decorticons la structure de cet argument :
* En premier lieu, un type. Puisque ma fonction _renvoie_ un int, le type de l'argument sera un int.
*  * `void *` peut paraitre assez particulier, mais il désigne "N'importe quelle valeur qui a de la mémoire allouée".
*  * Par exemple, si votre fonction modifiait le nom, vous auriez pu utiliser `char *` dans l'en-tête, ou garder `void *`.
*  * Si vous décidez de garder `void *`, il vous faudra _caster_ la valeur de retour de la fonction en `char *`
*  * Par exemple, avec le `char *` : `hero->name = f(hero->name);` et avec le `void *` : `hero->name = (char *)f(hero->name);`
*  * Si votre fonction modifie votre `char *`, vous aurez peut être a changer le pointeur vers la liste en pointeur de pointeur ...
* En deuxième, le nom de la fonction, pour qu'on puisse l'appeler plus loin, tout simplement. Ici notre fonction s'appelle donc `f()`.
* Et en dernier, entre parenthèses, les arguments de la fonction. 

Passsons au plus compliqué. Vous vous en douter, puisqu'il va falloir _retirer_ des chainons, on va devoir passer par le pointeur du pointeur. Et utiliser un backup. Et, tant qu'a faire, on va réutiliser la fonction de l'exercice précédent, donc vous aurez aussi besoin d'un index ...
```C
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
```
On initialise nos variables, et on parcours notre chaine. Si la condition passée en paramètre est respectée, c'est là qu'on va faire intervenir notre suppression. Après la découpe, on remets la chaine et l'index a 0, pour éviter tout cas farfelu de mémoire inutilisée (je détailleras ça plus bas si besoin). Pour éviter de sauter un chainon, on incrémente l'index _que_ si une suppression n'a pas été effectuée. Sans ça, votre index serait remis a 1 après une suppression, sautant possiblement l'élément 0, si le premier élément de la chaine a été supprimé ... 

Vous pouvez tester, et tout marche !
## Pour aller plus loin
Vous allez me dire : Pourquoi ? En effet, ce concept est pas spécialement utile. Vous pouvez tout autant juste créer une fonction normale qui fait la modification directement dans la fonction, surtout pour quelque chose d'aussi simpliste que de doubler une valeur, par exemple

```C
void   hero_modify_all(t_hero *hero)
{
    while (hero)
    {
        hero->power *= 2;
        hero = hero->next;
    }
}
```

Oui, je vous l'accorde. En C, ce n'est pas très utile. Par contre, dans d'autre langages, notemment le Java ou le C++, vous verrez un concept nommé _lambda expressions_. Ces expressions vous permettent de créer des "fonctions anonymes", des fonctions qui ne sont pas déclarées, mais utilisées _directement dans le code_. Par exemple, au lieu d'écrire
```C
hero_modify_all(h, &double_truc);
```
Vous écrirez quelque chose du genre
```C
hero_modify_all(h, ((a) -> (a*2)));
```
Notemment sur le traitement de listes chainées, vous aurez parfois a enchainer plusieurs modifications (par ailleurs, on appelle la modification de chaque élément un _mapping_) a la suite sur la même liste, et vous n'aurez peut être pas envie de refaire une fonction pour chaque modification différente. Si par contre vos fonctions de mapping prennent des fonctions en arguments, vous pourrez tout simplement envoyer des lambdas lors de vos appels, et ça vous simplifiera bien la vie !

Enfin, en théorie du moins.