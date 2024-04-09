## Visualiser les piles et les files
Vous êtes désormais des experts de la liste chainée, alors on utilisera cette dernière pour nos piles et nos files. Bien entendu, vous pouvez l'implémenter avec n'importe quel autre type de liste ... Ou même des tableaux.

Cependant, l'implémentation de ces dernières (en C tout du moins) dépends plus des fonctions associées que de la structure en elle même. On utilisera donc une seule structure.

Pour réprésenter cette dernière, on imaginera une pile d'assiette. En général, vous évitez de prendre une assiette au milieu de la pile, elle risquerai de s'écrouler. Par contre, vous pouvez prendre la dernière, ou soulever la pile en excluant la première assiète. On visualisera égalemment une autre pile.

## Push et Swap et rotations
Comme dit plus haut, on ne peut pas atteindre les assiettes au milieu, alors comment pourrait-t'on faire si l'assiette du milieu est celle qui nous intéresse ? Dans les piles et les files, on utilise ce qui s'appelle une _rotation_ afin de déplacer la pile. Vous ne pouvez pas juste prendre l'assiette au milieu ; par contre, vous pouvez enlever l'assiette du haut, la poser a coté, soulever la pile, et la poser sur l'assiette a part. La 2nd assiette devient alors la 1er, et la 1er devient a la dernière. En répétant ainsi de suite cette opération, on atteint alors l'assiette qui nous intéresse. Cette opération est nommée **Rotation inversée** (ou Reverse Rotate).

L'inverse est aussi possible : vous pouvez soulever votre pile sauf une seule assiette, que vous poserez alors sur la pile. La dernière devient la première, la 1er devient la 2em, etc. Cette opération est nommée **Rotation** (Rotate). 

Vous pouvez égalemment visualiser un barrillet de revolver : La balle placée en tête (celle qui sera tirée en appuyant sur la gachette) est la 1ere; et la suivante dans le sens horaire la 2nd, etc. Si vous faites tourner le barrillet (rotation), la dernière balle devient la 1er, la 1er devient la 2em, etc ...

>[!CAUTION]
> Le "1er" élément change si vous utilisez une pile ou une file, ne l'oubliez pas !

Une autre opération est égalemment possible : Vous prenez la première assiette, vous prenez la seconde, et vous les reposez dans l'ordre inverse ... La 1er est devenue la 2nd, et la 2nd la 1er : Vous avez effectué un **échange** (Swap). 

Pour l'exercice de push_swap, il existe une autre opération : la poussée, qui nécessite nos deux piles. Une **poussée** (Push) va "envoyer" le 1er élément d'une pile a l'autre. Oui, ce n'est pas très complexe a comprendre.

Réutilisez la structure `t_hero` pour les exercices.

## Exercice 1 - La tête
Créez les fonctions suivantes :
```C
t_hero *head_pile(t_hero *t);
t_hero *head_file(t_hero *t);
```
Ces deux fonctions renvoient la tête de la liste chainée, en la traitant respectivement en pile et en file.

## Exercice 2 - Swap
Implémentez la fonction :
```C
void  swap(t_hero *t);
```
Qui effectue un swap sur la liste.

>[!CAUTION]
> C'est le chainon qui doit être échangé, pas la valeur ! Il en va de même pour les exercices suivants !

## Exercice 3 - Push
Implémentez la fonction :
```C
void  push(t_hero *t1, t_hero *t2);
```
Qui pousse la tête de t1 sur t2.

## Exercice 4 - Rotation et Rotation inverse
Implémentez les fonctions suivantes :
```C
void rotate(t_hero *t);*
void reverse_rotate(t_hero *t);
```
Qui effectuent respectivement une rotation et une rotation inversée. 

## Exercice 5 -

## Examen
