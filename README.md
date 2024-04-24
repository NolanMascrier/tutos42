Un ensemble de tutos et d'exercices divers pour 42, écris par Nolan MASCRIER.

Vous trouverez ci-dessous des explications un peu plus théoriques sur la programmation.
# L'informatique, une histoire de boole
Qu'est-ce qu'un programme, au final ? Une série d'instructions, qui est ensuite _traduit_ par le compilateur en quelque chose de compréhensible par la machine. Ce quelque chose, vous vous en doutez, relève du binaire, une série de 0 et de 1. 
Mais pour comprendre _exactement_ ce que cette série de 0 et de 1 représente, il faut remonter le temps, bien avant internet, bien avant la 1er guerre mondiale, au milieu du XIXem siècle. Un mathématicien britanique, George Boole (ce nom vous est familier ?) crée, pour des raisons bien a lui, un objet mathématique particulier, l'algèbre de Boole. Une algèbre de Boole est un objet très simple : il est composé de deux (2 ? ça semble familier ...) valeurs distinctes (`a` et `b`, `0` et `1`, `VRAI` ou `FAUX` ...), et des deux opérations `+` et `*`.

> [!CAUTION]
> `+` et `*`sont ici des opérations LOGIQUES et non arithmétiques ! Ils correspondent a `ET` et `OU`.

Cette algèbre, notée en général ainsi `(0, 1, +, *)` définit ainsi un total de 8 résultats (tiens, 8, encore un nombre familier ...) :
* `0 + 0 = 0`
* `0 + 1 = 1`
* `1 + 0 = 1`
* `1 + 1 = 1`
* `0 * 0 = 0`
* `0 * 1 = 0`
* `1 * 0 = 0`
* `1 * 1 = 1`

Si vous remplacez `+` et `*` par `&` et `|`, vous obtenez les résultats de manipulation de bits et C ... Tout ça commence a être familier, non ?

Le concept de l'algèbre de Boole ne sera qu'exploité bien plus tard, avec les fameuses "punch cards" et les premiers ordinateurs. Mais comment ces affreuses mathématiques se traduisent dans l'informatique moderne ?

Et bien, qu'est-ce qu'un ordinateur au final ? Une suite de courants electriques passant dans la carte mère. Pour chaque "partie" de la carte mère, du courant peut passer, ou ne pas passer ... Soit un 1, ou un 0. Et oui, au final, tout, même le plus magnifique des jeux vidéos, peut être simplifié sur ce concept de base : à un certain endroit de la carte mère, du courant passe ou non. Multipliez ça par des millions, voir des milliards de fois : vous avez ainsi un ordinateur. 

Votre processeur regarde alors chacune de ces parties, et applique les opérations booléennes au dessus. Les processeurs modernes peuvent faire plusieurs milions de ces calcules par secondes. Cependant, il faut bien à un moment _stocker_ ces calculs quelques part, surtout pour les plus complexes. C'est ici qu'intervient la mémoire ...

# La mémoire

