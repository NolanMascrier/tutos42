# Exercice 4 - Sans queue ni tête
Reprenez le code de l'exercice précédant. Ajoutez une fonction qui renvoie un pointeur vers _la queue_ de la liste, c'est a dire son dernier élément. De plus, ajoutez une fonction qui ajoute un chainon _en tête_ de la liste. Utilisez les en-têtes suivantes :
```C
t_hero *hero_get_tail(t_hero *hero);
void   hero_push(t_hero *hero, char *name, int power);
```
N'oubliez pas de tester. 
> [!INFO]
> Vous pouvez utiliser la queue de votre chaine pour simplifier les ajouts. *

## Explications

Quelque chose cloche, n'est-ce pas ? En effet, je vous ai induit en erreur ... 

Le principe de la queue est triviale; il vous suffit de renvoyer le pointeur du dernier élément de la chaine. Cette fonction peut être faite de manière récursive ou itérative. Si l'élément courant possède un élément suivant, ce n'est pas le dernier ... Donc faite la même verification pour celui-ci, ainsi de suite. 

Maintenant, ça se complique pour le push. Vous avez sans aucun doute envie de faire simplement :
* On initialise un chainon
* On lui donne comme _next_ le pointeur vers notre chaine
* On recule la chaine

N'est-ce pas ? Et bien, ce n'est pas faux. Cependant, ça ne va pas marcher, essayez le code vous même ... Vous remarquerez que notre chaine n'a pas bougé ! Elle ne contient toujours que trois éléments ! 

On arrive dans l'un des concepts les plus abstraits et vils du C. Souvenez vous du début de votre aventure 42 ...

* Si une fonction prends juste un _int_ comme paramètre, elle créera une copie locale.
*  * Si vous modifiez cet int dans votre fonction, seule la copie est changée.
* Alors, on utilise un pointeur vers ce _int_.
*  * On peut alors modifier la zone pointée vers notre _int_. La mémoire elle même est modifiée, donc elle se repercute sur tout votre programme, et même sur _tout votre pc_ !
*  * Mais vous pouvez vous douter de quelque chose ... Si lorsque je passe l'int directement, une copie locale est crée, est-ce qui se passe la même chose pour mon pointeur ?
*  * La réponse est ... Oui ! Le pointeur est une copie locale. La zone mémoire est quelque chose de physique (des bits valant 0 ou 1 a l'intérieur de votre mémoire vive), et le pointeur est une représentation abstraite _pointant_ vers ladite zone mémoire. Cependant, puisque vous utilisez de manière physique ce pointeur, il est doit bien être stocké de manière physique quelque part, non ? 
*  * Et s'il est stocké de manière physique, c'est qu'on peut avoir un pointeur sur ce dernier ...

Souvenez vous la piscine. Elle vous a préparé pour ce moment. Vous vous souvenez peut être d'une fonction ressemblant a ça :
```C
void foo(int **********a);
```
Et oui ! Ici, on utilise le pointeur du pointeur du pointeur [...] du pointeur vers la zone mémoire de `a` ! Mais revenons a notre liste chainée. Ici, vous voulez _reculer_ le pointeur de la liste chainée (qui, rappelons-le, pointe vers le _le premier élément de la liste_). Si vous reculez le pointeur, rien ne se passera ... Vu que ce n'est autre qu'une copie locale de ce pointeur. Donc, vous allez devoir utiliser le pointeur du pointeur.

Changez donc vos en têtes par celle-ci : 
```C
t_hero *hero_get_tail(t_hero *hero); //Celui ci n'as pas besoin d'être revu, bien entendu
void   hero_push(t_hero **hero, char *name, int power);
```
Compilez ... Et c'est pas bon. Bien entendu. Puisque maintenant votre _hero_ est un pointeur de pointeur (ou super pointeur), vous ne pouvez plus directement l'utiliser. Vous allez devoir le déréférencer, en ajoutant une étoile devant (et, par soucis de visibilité, en général, des parenthèses autour).

Ainsi, `hero = this;` deviendra `(*hero) = this;` !

Et magie ... Tout fonctionne !

Cette arcane apocryphale, le déréférencement, vous sera extrémement utile pour minishell, si vous décidez d'utiliser des listes chainées pour le faire. 
Vous pouvez théoriquement déréférencer (c'est dur a écrire) un nombre infini de fois. Cependant, si vous dépasser les 5 *, posez vous des questions, car la structure que vous utilisez devra surement être réecrite. De manière _très_ urgente.

## Pour aller plus loin

Pour tout vous avouer, bien que le code que je vous ai fourni dans les exercice fonctionne, il n'est pas _bon_. Pourquoi ? Si vous l'avez remarqué, toutes les fonctions assument que la liste a _déjà été initialisée_. Mais, maintenant que vous maitrisez le déréférencement, vous pouvez sans aucun doute modifier les fonctions afin qu'elle initialise une zone mémoire s'il la liste n'en a pas déjà de base ... 