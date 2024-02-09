Le projet "MY_NAVY" consiste à créer une version terminal du jeu de bataille navale en utilisant des signaux en langage C.
Les deux terminaux ne peuvent communiquer qu'en utilisant les signaux SIGUSER1 et SIGUSER2.
La carte de jeu est de taille 8x8 et à chaque tour, les positions des joueurs sont affichées, suivies des positions de l'ennemi.
Le jeu se termine lorsqu'un joueur a perdu tous ses navires, et le programme affiche alors si "I won" (j'ai gagné) ou "Enemy won" (l'ennemi a gagné).

Fonctionnement :

Le programme prend en entrée le PID (Process ID) du premier joueur (seulement pour le deuxième joueur) et un fichier représentant les positions des navires.
Ce fichier doit contenir des lignes formatées de la manière suivante: "LENGTH:FIRST_POSITION:LAST_POSITION", où LENGTH est la longueur du navire et FIRST_POSITION et LAST_POSITION sont ses positions initiales et finales de chaques bateaux.
Le fichier doit contenir exactement 4 bateaux de tailles (2, 3, 4 et 5).
