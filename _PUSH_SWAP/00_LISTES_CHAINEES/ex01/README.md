# Exercice 1 - Initialisation de la chaine

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

## Explications

Lorsque vous utilisez directement une strucutre (ici, `h1`), vous devez appeler les champs via un `.`, ce qui est fait dans cette ligne :

`free(h1.name);`

Sinon, une flèche (`->`) est utilisée lorsque vous utilisez le _pointeur_ vers la structure. Remémorez vous vos premier codes durant la piscine : pourquoi utiliser un pointeur vers un int lorsque vous voulez modifier ce dernier dans une structure ? Car

`int plus(int a);` 

Créera une copie locale de `a`, et c'est cette dernière qui sera modifiée : votre `a` dans le main n'est jamais touché. Par contre, si votre fonction prends un pointeur a la place

`int plus(int *a);`

Il ne créra pas de copie locale, mais se réferera à la zone mémoire occupée par votre int; ainsi les modifications apportée a `a` dans la fonction se répercuteront sur le `a` de votre main. La logique est la même pour les structures; si vous voulez que la fonction modifie cette dernière, il faudra donc lui envoyer le pointeur, d'où

`void  hero_init(t_hero *hero, char *name, int power);`

Et puisque `hero` ici est un pointeur, on utilisera la flèche `->` pour modifier les champs. 

Il existe cependant une certaine subtilité : Si vous déclarez votre structure via un pointeur, il faudra que vous allouiez la mémoire manuellement, tandis que déclarer la structure directement allouera automatiquement la mémoire nécessaire.

Vous remarquez égalemment que nous allouons de la mémoire dans les deux cas, via `ft_strdup()`. Cette mémoire devra bien entendu être libérée a son tour, et _devra impérativement_ être libéré  **avant** que la structure elle même soit libérée.

En effet, dans cette situation, si vous libérez la mémoire de la structure avant, vous n'aurez plus de pointeur dessus; il sera alors impossible d'accéder a la zone mémoire allouée au nom, créant ainsi une fuite mémoire !

## Pour approfondir

Ici, la fonction d'initialisation modifie une structure déjà existante, expliquant la nécessité du pointeur. Cependant, on peut imaginer une situation alternative, à savoir que la fonction crée la structure directement, qu'il renvoie alors :

```C
t_hero hero_init(char *name, int power)
{
  t_hero h;
  
  h.name = name;
  h.power = power;
  return (h);
}
```
On peut égalemment imaginer la même version, mais avec de la mémoire allouée ...

```C
t_hero *hero_init(char *name, int power)
{
  t_hero *h;
  
  h = ft_calloc(1, sizeof(t_hero));
  h->name = name;
  h->power = power;
  return (h);
}
```

Il n'y a pas vraiment de raisons de préférer une façon d'écrire a une autre, cela relève de vos habitudes. Sachez cependant qu'en général, pour des valeurs "dures", des valeurs que vous vous servirez longtemps dans l'execution du programme, on préfére allouer de la mémoire, et utiliser une initialisation directe dans le cas d'une valeur qui ne sera utile que pour une seule fonction.
