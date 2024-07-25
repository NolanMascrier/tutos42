## Qu'est-ce qu'une liste chainée ?
Une liste chainée est une structure particulière, possédant au moins parmis ses champs un pointeur vers un autre élément, étant lui même du type de la structure. Ainsi, une "chaine" se crée entre plusieurs fois la même structure, possédant des champs différents. Chaque élement sera nommé chainon. 

Voici un exemple un peu poussé de représentation de liste chainée, vu qu'il posséde un pointeur vers l'élement précédent.
![291021993-860874c3-9c3e-4134-aece-2e69c494a803](https://github.com/IrinaNekotari/tutos42/assets/63266772/7057b565-0c6d-4b36-9116-177a4110c4f2)
On peut ici voir que la liste chainée possède 5 chainons, chaquant possédant trois champs. 

L'avantage d'une liste chainée comparée a un tableau ou double tableau est évidente : non seulement on peut mettre plusieurs types de valeurs par "cases", c'est égalemment plus simple a écrire. Cependant, il est impossible d'_accéder_ directement à l'une des "cases", on est obligés de parcourir la liste entière jusqu'a l'élement voulu, ce qui peut ralentir l'éxecution du programme lors de l'utilisation de listes chainées extrémement longues. 

Observons la syntaxe d'une liste chainée. 

```C
typedef struct s_hero
{
  char  *name;
  int   power;
  struct s_hero  *next;
}	t_hero;
```

Vous reconnaissez la syntaxe d'une structure - c'est en effet la même. Le seul ajout étant `struct s_hero *next;`, un pointeur vers l'élément suivant. Nous utiliserons la structure `s_hero` pour tous les exercices, alors n'hésitez pas a l'ajouter dans votre **.h**.

Sauf précisions, n'utilisez que des fonctions que vous avez codé vous même, en dehors de `malloc` et de `printf`. Tout code produit ne doit comporter aucune fuite mémoire. Le respect de la norme est optionnelle, mais recommandé (nan, vraiment). 

## Exercice 1 - Initialisation de la chaine

Pour ce premier exercice, créez une fonction qui initialise le premier élément de la structure. Créez également une fonction qui affiche _tout_ le contenu du chainon. Utilisez les en-têtes suivantes :
```C
void  hero_init(t_hero *hero, char *name, int power);
void  hero_print(t_hero *hero);
```
De plus, ajoutez une fonction main qui initalise les _deux_ listes chainées suivantes :
```C
t_hero h1;
t_hero *h2;
```
Le programme doit ensuite afficher le contenu des deux chainons. Oui, ça inclue aussi le pointeur ... 

> [!TIP]
> Tout champ _doit_ être initialisé à une valeur, même si cette dernière est NULL ...
>
> Je vous demande deux chainons différent pour une raison. Observez la différence entre `.` et `->` ...

## Exercice 2 - Enchainer la chaine
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

## Exercice 3 - ça se complique
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

## Exercice 4 - Sans queue ni tête
Reprenez le code de l'exercice précédant. Ajoutez une fonction qui renvoie un pointeur vers _la queue_ de la liste, c'est a dire son dernier élément. De plus, ajoutez une fonction qui ajoute un chainon _en tête_ de la liste. Utilisez les en-têtes suivantes :
```C
t_hero *hero_get_tail(t_hero *hero);
void   hero_push(t_hero *hero, char *name, int power);
```
N'oubliez pas de tester. 
> [!INFO]
> Vous pouvez utiliser la queue de votre chaine pour simplifier les ajouts. *

## Exercice 5 - Coupez !
Reprenez le code de l'exercice précédant. Ajoutez une fonction qui supprime un élément de la chaine. La chaine ne doit pas être brisée pour autant : vous devez recoller les deux morceaux. Utilisez les en-têtes suivantes :
```C
void   hero_cut(t_hero **hero);
```
N'oubliez pas de tester. 
> [!TIP]
> Recoller la chaine revient a dire que le `next` du chainon précédant le chainon coupé doit pointer vers le chainon suivant du chainon coupé ... 
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
void   hero_attack(t_hero *hero, int n, int pow);
```
N'oubliez pas de tester. 

## Examen !

Cet exercice n'est pas nécessaire, mais il peut être un petit challenge stimulant pour vous.

Implémentez une calculatrice. La calculatrice doit
* Utiliser une liste chainée
* Être capable d'utiliser les opérations basiques (+, -, *, /, ^)
* Être capable d'utiliser les parenthèses
* Ne pas calculer en direct, c'est a dire que le calcul n'est effectué qu'au dernier moment, _en respectant les priorités de calcul_ !
* Être intéractive :
*  * Elle attends les entrées de l'utilisateurs. 
*  * Les entrées ne peuvent être que des nombres ENTIERS (le resultat des divisions est arrondi au plus proche), positifs et négatifs, des opérations, ou des parenthèses.
*  * Vous êtes libres d'implémenter une aide/rappel, qui sera appelé si l'entrée est `?`, `help` ou quelque chose du genre.
*  * L'entrée `=` termine le programme, calcule le résultat, et affiche ce dernier.
*  * Après chaque entrée, le calcul doit être affiché en entier.

Vous pouvez utiliser les fonctions _atoi_ et _readline_ (ainsi que toutes ses fonctions associées), ou tout équivalent que vous aurez vous même codé.

Vous ne trouverez pas de correction ou d'explications pour celui la. Bonne chance ~ 

BONUS !

* CTRL+D doit faire un _UNDO_ sur votre calcul, a savoir retire la dernière valeure entrée. Il est possible d'_UNDO_ l'entiereté du calcul ...
* CTRL+C doit faire un _REDO_, a savoir retire le dernier _UNDO_. Cependant, il n'est pas possible de _REDO_ si la dernière action effectuée n'était pas un _UNDO_ ...

Ce bonus vous initiera inconsciemment au concept de pile et de file, et en plus vous donnera quelques petits indices pour minishell. 