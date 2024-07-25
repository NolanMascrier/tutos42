## Exercice 7 - Ultime puissance
Vous détenez maintenant le pouvoir de vie ou de mort sur votre héros. Ajoutez un second pointeur dans votre structure, qui pointera vers l'élément _précédant_ du chainon. Adaptez toutes les fonctions en conséquences. Créez une fonction qui _ciblera_ un hero a l'index _n_. N'ajoutez PAS cet index dans la structure, cela doit être entiérement géré dans la fonction ! Si l'index dépasse toutefois le nombre de chainons ... Revenez à 0, bien entendu. Une fois le hero ciblé, vous lancerez une attaque de puissance _pow_. Si la puissance de l'attaque dépasse celle du héros, ce dernier est éliminé, et son chainon retiré ! Mais ce n'est pas tout - Toute puissance qui est _superflue débordera_ ainsi de suite sur les deux héros situés à droite et à gauche de notre victime. Si le héro est en bout de chaine, l'attaque ne débordera toutefois pas.

Si le hero survis à l'attaque, il est toutefois affaibli, et sa puissance est diminuée de la puissance de l'attaque. Pensez aux implications lors d'une réaction en chaine ... 
Des messages adaptées doivent être affichés lorsque 
* L'attaque est lancée - Le nom du héros ciblé ainsi que la puissance de l'attaque doivent être visibles.
* Le héros subit des dégats - Faites un avant/après de sa puissance.
* Si le héros survis, affichez un message plein d'espoir.
* Sinon, le désespoir triomphe, et recommencez. 

La fonction doit être récursive.

Utilisez les en-têtes suivantes :
```C
void   hero_attack(t_hero **hero, int n, int pow);
```
N'oubliez pas de tester. 

## Explications

Le but de cet exercice est de voir les listes doublement chainees. On va ajouter un pointeur _previous_ a notre structure :
```C
typedef struct s_hero
{
  char  *name;
  int   power;
  struct s_hero  *next;
  struct s_hero  *previous;
}	t_hero;
```
Il va ensuite falloir modifier nos fonctions pour prendre en compte ce dernier. Ce n'est pas si complique que ca ... Les fonctions concernees sont bien entendu les ajouts, ainsi que la suppression. Vous pouvez egalemment modifier l'affichage, si vous le souhaitez ...

Passons maintenant a notre attaque.

## Pour aller plus loin
