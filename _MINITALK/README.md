Ce dossier contient un ensemble de tutoriels et d'exercices basés autour du projet Minitalk. Au cours de ce projet, vous découvrirez divers concepts utilisés en programmation, notamment celui des signaux et des serveurs/clients

## Client, serveur, et PID
Jusqu'a maintenant, tous vos programmes étaient monolithiques : il n'y avait qu'une seule instance de ce programme à la fois. Seulement, ce n'est pas toujours adapté au programme voulu : par exemple, si vous voulez partager des informations entre plusieurs programmes, etc.

Lors du cursus 42, vous utiliserez 3 manières différentes de créer plusieurs instances pour votre programme :
* Les threads, permettant d'executer une tache simple en parallèle
* Les forks, permettant de créer un clone de l'instance de votre programme
* Le client/serveur, permettant de découper votre programme en plusieurs sous-programmes qui communiquent entre eux. 

Bien entendu, Minitalk utilise le couple client serveur. Définissons d'abord ce que sont ces choses :
* Un serveur est le programme central, généralement non accessible a l'utilisateur. Il traite la plupart des données, et peut les partager aux clients, ou parfois même a d'autres serveurs.
* Un client est le programme utilisateur, celui avec lequel il va communiquer. Un client est connecté a un seul serveur en général, avec lequel il échange des données. 
* Dans certains cas, un client peut se connecter a un autre client. On appelle cette situation le P2P, Peer-to-Peer, ou paire a paire. Dans ce cas, le client est aussi considéré comme serveur : ces deux ne sont pas exclusifs. 

L'avantage de la structure serveur/client, c'est la possibilité d'extérioriser le serveur. Ainsi, non seulement ce dernier peut être installé sur une seconde machine, il n'a pas besoin d'être lancé ou modifié par l'utilisateur, garantissant une simplicité d'utilisation, mais aussi une certaine sécurité. En effet, les données sur le serveur n'étant accessible que de manière determinée par le client, il est (théoriquement, mais ça c'est une autre histoire) impossible de "tricher" sur les valeurs du serveur, par exemple en donnant des millions de pièce d'or a votre personnage.

Mais pour Minitalk, on va garder ça simple, le client et le serveur seront sur la même machine, et au lieu de communiquer via des ports et des sockets, on utilisera les signaux.

Mais avant, définissons ce qu'est le PID. Le _Program Identifier_ est, sans aucune surprise, un identifiant numérique unique associé a l'instance de votre programme. Vous pouvez facilement regarder les PID des programmes lancés sur votre machine, en utilisant _htop_ par exemple. Même si vous ne vous en êtes pas rendu compte, tous vos programmes jusqu'a maintenant avaient un PID. 

Définissons maintenant un signal. Un signal est une communication interne a votre machine, qui est défini par une unique valeur. Certain programmes vont "écouter" les signaux, et lorsque l'un d'entre eux est reçu, il effectuera certaines actions. Prenons un exemple que vous connaissez sans doute tous : Lorsque vous tentez d'accéder a une zone mémoire interdite (par exemple _tab[-1]_), votre _programme_ va envoyer le signal **SIGSEGV** (vous le reconnaissez ?) a votre terminal, qui affichera alors le fameux message du Core Dumped. Il n'existe qu'un petit nombre de signaux sous UNix :
* `SIGINT`, Signal d'interruption, envoyé lorsque vous utilisez CTRL+C dans le terminal.
* `SIGSEGV`, envoyé pour les erreurs de segmentation.
* `SIGKILL`, envoyé pour "tuer" le processus.
* `SIGUSR1` et `SIGUSR2` qui ne font rien par défaut.

Il en existe d'autre (une 20aine en tout), mais ceux-si sont ceux qui nous intéressent, surtout `SIGUSR1` et `SIGUSR2`, puisqu'on va s'en servir pour Minitalk. 

## Exercice 1 - Mise en bouche
Ecrivez un programme qui affiche un message au choix contenant le pid du programme. Oui, c'est tout.

## Exercice 2 - Surprise, un malloc
Ecrivez une fonction `add_char()` qui prends une chaine de charactère et un charactère, et qui retourne une concaténation de la chaine et du charactère.
Utilisez l'en-tête suivante :
```C
char   *add_char(char *origine, char add);
```
Vous me remercierez plus tard. 

## Exercice 3 - KILL
Ecrivez un programme qui affiche son PID, puis ne fait rien, une boucle infinie. Cependant, lorsque dans un autre terminal, on entre la commande `kill -USR1 [PID du programme]`, affiche une message et se ferme. 

## Exercice 4 - Communication
Ecrivez deux programmes, un nommé client, un nommé serveur.
* Le serveur se lance, affiche son PID, et boucle a l'infini.
* Le client se lance avec un argument, étant le PID du serveur. Puis, il boucle en lecture (utilisez readline).
* Si vous entrez "ping" dans le client, le serveur doit affiche "pong" suivi d'un retour a la ligne.
* Si vous entrez "pong" dans le client, le serveur doit affiche "ping" suivi d'un retour a la ligne.
* Ne faites rien dans les autres cas.

## Examen - Miaou
Ecrivez un programme qui fait office de client+serveur (P2P). 
* Le programme peut être lancé avec un ou deux arguments. Le premier argument étant un pseudonyme, le second étant un PID.
* Si le second argument n'est pas référencé, le programme affiche son PID, et sera considéré comme le serveur.
* Si le second argument est référencé, le programme se "connectera" au serveur du PID. 
  * Si le PID ne réfère a aucun serveur, envoyez un message d'erreur !
* Le programme bouclera a l'infini en lecture (utilisez readline), sauf si l'utilisateur utilise CTRL+C.
* Lorsqu'un message est écrit dans le programme, il doit être affiché dans tous les clients connectés (s'inculant lui même !), avec le format suivant : `[PSEUDO] : Message`.
* Si le programme serveur se ferme, tous les clients connectés se fermeront aussi.