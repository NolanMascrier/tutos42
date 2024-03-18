# Exercice 5 - Coupez !
Reprenez le code de l'exercice précédant. Ajoutez une fonction qui supprime le n-ieme élément de la chaine. La chaine ne doit pas être brisée pour autant : vous devez recoller les deux morceaux. Utilisez les en-têtes suivantes :
```C
void   hero_cut(t_hero **hero, int n);
```
N'oubliez pas de tester. 
> [!TIP]
> Recoller la chaine revient a dire que le `next` du chainon précédant le chainon coupé doit pointer vers le chainon suivant du chainon coupé ... 

## Explications

Cet exercice est un peu plus complexe, car vous aurez en réalité a écrire 2 fonctions : 
* L'élément a couper est le premier
* L'élément a couper n'est pas le dernier

Le cas général étant le plus facile, commençons par ce dernier. En premier lieu, vérifiez si `n` n'est pas négatif; si c'est le cas vous n'aurez rien a faire de toute façon. On va ensuite prendre deux valeurs de sauvegarde.

Souvenez vous l'exercice précédant : ici, on travaille sur le pointeur du pointeur. Si on modifiait ce dernier en le déplaçant par exemple, on le déplacerait également dans toute la zone mémoire, perdant potentiellement les pointeurs sur les premiers éléments, conduisant alors a une fuite mémoire. 

Ici, le pointeur `ptr` nous servira d'index pour nous déplacer dans la liste, c'est lui qu'on déplacera. De plus, on gardera un autre index `i` qui sera la représentation de la position de chaque élément. Cependant, il y a ici une subtilité : puisqu'il faut modifier l'élément _précédent_ de la liste lors de la coupe, il faut bien qu'on garde ce dernier en mémoire, car nous n'avons (pour l'instant) aucun moyen de retourner en arrière. Bien entendu, vous pouvez toujours passer outre, comme refaire une boucle qui part du début ... Mais ça serait vous compliquer la vie pour rien. Donc, lorsque notre position vaut un de moins que celle qu'on cherche, on va rendre notre second pointeur `bck` égal a l'élément actuel. Vous l'avez deviné : c'est l'élement précédent.

Maintenant, nous arrivons au cas ou `i` vaut `n` : c'est a dire l'élément qu'on cherche a supprimer. En premier lieu, on va "joindre les deux bouts", c'est a dire _exclure_ l'élément courant de la liste, en remplacant le _suivant_ du _précédant_ (l'élement courant si vous avez suivi) par l'élément suivant de l'élément courant : tout simplement `bck->next = ptr->next;`.
Vous voyez ici l'utilité des backups. N'oubliez pas bien entendu de libérer la mémoire associée après !
```C
if (ptr->name)
                free(ptr->name);
            free(ptr);
```
Testez maintenant votre programme. Vous remarquez qu'il marche ... Sauf quand vous voulez couper l'élément 0. En effet, il faudra rajouter un cas particulier dans votre fonction. 

```C
    if (n == 0)
    {
        bck = ptr->next;
        if (ptr->name)
                free(ptr->name);
        free(ptr);
        (*hero) = bck;
        return ;
    }
```
Dans l'absolu, le code est le même, a deux différences près. On initialise le backup immédiatement, mais le plus important est cette ligne : `(*hero) = bck;`. Puisque cet élément est le premier, il est égalemment celui qui _définit_ votre liste, celui que vous utilisez dans votre main comme pointeur pour utiliser vos fonctions. Si vous le coupez simplement, le reste de votre liste est _perdue_ définitivement, conduisant non seulement a des fuites mémoires, mais en plus une segfault ! Donc, vous devez pointer le pointeur vers l'élément suivant de la liste, celui que vous avez garder en mémoire ... 
## Pour aller plus loin
Il n'y a pas grand chose a ajouter ici. Vous avez surement remarqué que de devoir avoir deux backups, c'est prise de tête. C'est pour ça que les listes doublement chainées existent ... Vous les verrez dans l'exercice 07.