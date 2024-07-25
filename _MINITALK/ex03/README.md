Ce dossier contient un ensemble de tutoriels et d'exercices basés autour du projet Push Swap. Au cours de ce projet, vous découvrirez divers concepts utilisés en programmation, notamment celui de la complexité, des piles et des files, ainsi que les tris. 

Ce fichier décrit les concepts de manière assez théorique, tandis que les exercices vous donneront du concret. 

Ce tutoriel assume que vous connaissez les listes chainées. Si vous avez réussi à arriver ici sans avoir touché aux listes chainées, laissez vous tenter par la boxe, car votre jeu d'esquive est sensationnel. Dans cette situation, vous trouverez tout de même quelques exercices et explications dans le sous-dossier associé. 

## Complexité Algorithmique
La complexité Algorithmique est une mesure arbitraire du nombre d'opérations effectuées dans votre programme. Plutôt de le mesurer temporairement, on va mesurer le nombre d'_opérations_, qui seront définis de manière différentes d'un projet à un autre. En général, on utilise les _affectations_ (=, +=, etc) comme unité de mesure; cependant, pour Push Swap, on utilisera les opérations telles que _ra_ ou _sb_. 

Lors de votre évaluation, il vous sera demandé de montrer combien de ces opérations vous effectués pour un tri de 3, 5, 50 et 100 valeurs. Votre note dépendera donc de ce nombre, de la _complexité_ de votre programme. 

Traditionnellement, la complexité d'un programme ou d'un algorithme est noté `O(n)`, où `n` est le nombre de valeurs a traiter. On dénote les cas généraux suivants :
* `O(1)` : Votre programme est executé en un nombre d'opération constant, peu importe le nombre de valeurs entrées. En général, une perfection inatteignable.
* `O(n)` ou `O(xn)` : La complexité de votre programme est dite linéaire, c'est a dire que le nombre d'opération augmente de manière proportionnelle a votre nombre de valeur. Un très bon résultat en général.
* `O(n²)` : La complexité de votre programme est exponentielle. Un cas à éviter, qui risque même de déborder votre machine tôt ou tard.
* `O(2^n)` : Un résultat apocalyptique à fuir comme la peste.

Il existe bien entendu plus de cas, avec des notations bien plus complexes (avec des `log(n)` et autres monstruosités mathématiques), surtout lorsque votre programme implémente plusieurs algorithme pour des cas différents - ce qui est le cas de Push Swap entre autres. Dans cette situations, il est plus perspicace de mesurer la complexité de chaque algorithme ou branche plutot que de l'entièreté de votre programme.

>[!caution]
>Les _opérations_ étant potentiellement différentes d'un projet à un autre, il est inefficace de comparer la complexité d'un programme a un autre en général ! La complexité d'un tri sera bien souvent bien plus basse que celle d'un pathfinding, cela ne veut pas dire pour autant que le tri est écris de manière plus optimisé ! 

Lors de votre correction, on vous demandera d'utiliser (en général ...) un visualizer pour votre algorithme, qui vous donnera le nombre d'opérations effectuées pour trier 3, 5, 50 et 100 valeurs. En fonction du type de tri que vous implémenterez, cette valeur ne sera pas forcément constante ... En général, pour calculer la complexité de votre tri, vous supposerez le _pire cas possible_ ...
## Pile et Files
Les Piles et les Files sont deux manières de stocker des valeurs, extrémement utiles en informatiques. Cependant, ces derniers sont égalemment utilisées dans la vie courante ! Comme par exemple, la pile d'assiette qui traine dans votre évier, ou la file d'attente pour aller aux toilettes dans une convention ... 

Une pile est définie par le principe du _LIFO_, _Last In, First Out_ (Dernier entré, premier sorti pour nos amis anglophobes) : En effet, lorsque vous voulez nettoyer votre tour d'assiette, vous commencez par celle toute en haut, pourtant la dernière que vous avez posé (en général), sans quoi vous risquez la catastrophe, et encore plus de fouillis à nettoyer ...

Une file (ou queue) est définie par le principe du _FIFO_, _First In, First Out_ (Premier entré, premier sorti) : la première personne à sortir de la file d'attente devant les toilettes est la personne qui aura attendu le plus longtemps (honteux accidents exclus), et couper a travers est impossible (si vous êtes quelqu'un de décent bien entendu).

Les Piles et les Files ont chacun des avantages et des inconvénients, que vous laisserais soin de découvrir pendant les exercices. 
## Tris
Nous voici dans le vif du sujet. Conflit éternel de la programmation, les tris sont une étape presque aussi classique que HELLO WORLD dans l'aventure de la programmation. Un tri consiste à changer l'ordre des valeurs dans un ensemble selon une _relation d'ordre_ entre deux valeurs.

Remettons au points quelques concepts mathématiques. Qu'est-ce qu'un ensemble ?
> En mathématiques, un ensemble désigne intuitivement un rassemblement d’objets distincts (les éléments de l'ensemble), « une multitude qui peut être comprise comme une totalité » pour paraphraser Georg Cantor qui est à l'origine de la théorie des ensembles.
_Extrait de [Wikipédia](https://fr.wikipedia.org/wiki/Ensemble)_

Un _Ensemble_ est donc un groupe d'objets disctints. Pour push swap, l'ensemble concerné est un sous-ensemble de ℕ, celui des **int**, a savoir tous les entiers entre -2147483648 et 2147483647. Cependant, pour mes explications, on considérera l'ensemble suivant : `[a b c d e f]`. 

> Une relation entre objets mathématiques d'un certain domaine est une propriété qu'ont, ou non, entre eux certains de ces objets ; ainsi la relation d'ordre strict, notée « < », définie sur N l'ensemble des entiers naturels : 1 < 2 signifie que 1 est en relation avec 2 par cette relation, et on sait que 1 n'est pas en relation avec 0 par celle-ci.
_Extrait de [Wikipédia](https://fr.wikipedia.org/wiki/Relation_(mathématiques))_

Une relation est une association entre deux valeurs (distinctes ou non) d'un ensemble, qui donnent une troisième valeur (potentiellement égale a l'une des deux autres), par exemple le `+`. On pourra par exemple définir la relation suivante : `a + b = c`. Une relation d'ordre est un cas particulier des relations; elle ne donne pas de troisième valeur, mais a la place _classe_ deux valeurs entre elles. Les deux relations d'ordre les plus connues sont bien entendu `>` et `<`. 

Beaucoup de blabla pour pas dire grand chose au final, vous auriez pu le déduire tout seul. Mais bon, faut bien ça des fois. Dans les exercices, vous découvrirez le tri le plus basique de tous, le tri a bulle, et verrez un début de pistes pour les deux tris utilisés en général pour Push Swap : Le tri par pignon, et le tri radix. 
