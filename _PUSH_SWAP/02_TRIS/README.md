## Tris

Vous vous en doutez surement, mais un tri consiste a déplacer les éléments d'une liste de façon a ce qu'ils soient ordonnées selon une relation d'ordre. La plus connue de ces relations étant bien entendu "l'ordre croissant" disant que les plus petits entiers doivent être au début de la liste, tandis que les plus grands sont a la fin.

Ainsi, avec la liste suivante `18 7 25 63 9 10 148 41 1`, une fois triée par ordre croissant, vous obtiendrez la liste suivante `1 7 9 10 18 25 41 63 148`. Bon, ok, pas de grandes surprises ici, n'est-ce pas. 

Le plus basique des tris, le plus simple a mettre en place, et, en général, un rite de passage de l'algorithmique est la tri a bulle. 

## Tri a bulle

Le concept du tri a bulle est de comparer les élements deux a deux, inverser au besoin, et, si la liste a été modifiée, recommencer. 

Ainsi, si on reprends la liste `18 7 25 63 9 10 148 41 1`
* On compare 18 et 7.
  * 18 est plus grand que 7, donc on inverse.
* La liste est donc maintenant `7 18 25 63 9 10 148 41 1`
* On compare 18 et 25.
  * 18 est plus petit que 25, donc on le laisse ainsi.
* On compare 25 et 63
* etc
* On a eu un changement, donc on recommence le processus au début

Le tri a bulle est extrémement simple a comprendre et a écrire, mais il est peu efficace, surtout si la liste est très désordonnée. On utilisera donc le tri par pignon (**Quicksort**) ou le tri radial (**Radix sort**). 

## Quelques indices

Le principe du tri par pignon est de déclarer un pignon, et de déplacer toutes les valeurs supérieurs a ce dernier dans une autre. Puis, on recommence en affinant pour chaque liste, et on fini par obtenir une liste triée en la recomposant. Le tri par pignon est extrémement efficace, à la seule condition que ce pignon soit choisi de manière intelligente; ce qui est la grosse difficulté de ce tri. 

Quant au tri radial, il nécessite de décomposer la liste en "boites", puis de réassembler ces dernières. Il y aura une boite 0, et une boite 1, ainsi jusqu'a 9. Ensuite, pour chaque valeur, on regarde le nombre des unités : s'il vaut 0, il ira dans la case 0, s'il vaut 2 dans la case 2 ... etc. Une fois la liste recomposée, on recommence pour les dizaines puis les centaines ... 
Le tri radial produit un nombre constant d'opération, mais possède certain défauts. En premier lieu, il ne gère pas les négatifs. De deux, dans le sujet de push_swap, nous ne pouvons utiliser que 2 boites ... Boite 0, boite 1, ça vous rappelle quelque chose ?

## Exercice 1 - L'avant-bulle
Vous allez devoir implémenter un tri a bulle pour nos héros. Cependant, on ne va pas être barbant et trier via leur puissance ... 
Créez la fonction suivante :
```C
int  hash(t_hero *a, t_hero *b);
```
Qui va comparer deux chainons de la façon suivante : La somme des lettres du nom, avec `a` valant 1 et `z` valant 26, les majuscules comptant double, divisée par la puissance du personnage. Ces deux valeurs seront comparées par un `>`.

>[!CAUTION]
> Attention aux divisions par 0 !

>[!INFO]
> Vous avez remarqué le nom "hash". Le _hashing_ est une méthode en orienté objet qui permets de réduire un objet a un nombre, permettant alors une comparaison entre deux de ces objets. 

## Exercice 2 - Recherche le pignon
Créez la fonction suivante
```C
int median(t_hero *hero);
```
Qui retourne la valeur médiane des puissances de la liste.

## Exercice 3 - Indexage
Ajoutez un champ d'index dans la structure, un entier. Créez la fonction
```C
void  index(t_char *h);
```
La fonction va calculer l'index de chaque chainon en se basant sur la puissance. L'index commence a 1, et marquera la puissance la plus basse. L'index 2 marquera la 2nd puissance la plus basse ... Et l'index _n_ marquera donc la puissance la plus haute.

## Exercice 4 - Bubulle
Implémentez le tri a bulle, qui trie en utilisant le hashing.
```C
void bubble_sort(t_hero *h);
```
## Exercice 5 - Le tri des radis ?
Implémentez un tri radial basique. Utilisez 10 listes chainées pour substituer ces boites. 
```C
void radix_sort(t_hero *h0, t_hero *h1, ..., t_hero *h9);
void radix_sort2(t_hero *h[]); //si vous vous souciez de la norme, utilisez un tableau de listes pour vos boites
```
>[!TIP]
> Je vous ai demandé de faire un indexage pour une raison ...

## Exercice 6 - Pignon de poulet
Implémentez un tri par pignon basique. Triez en utilisant les puissances.
```C
void  quicksort(t_hero *h);
```
>[!TIP]
> La médiane est en général le meilleur pignon. En général ...

## Examen !

Pas besoin d'examen - allez rendre push_swap plutot. Vous n'avez plus qu'à faire attention à utiliser que 2 boites/sous-listes en même temps ... 
