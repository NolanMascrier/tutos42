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

## Pour aller plus loin
