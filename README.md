# 2942
2942, le 1942 du turfu.

2942 est un jeu créé pour l'UE Moteur de Jeu.

On y incarne un vaisseau qui doit détruire des ennemis, tel que le classique 1942. Les touches fléchées permettent d'avancer et la barre d'espace permet de tirer.

**DONE :**
- [x] Déplacement du personnage.
- [x] Ennemis basiques.
- [x] Système de points.
- [x] Une classe abstraite pour les ennemis, afin d'en avoir plusieurs variétés.
- [x] Une UI plus propre que ce qu'il y a maintenant. (Principalement un écran de gameover).
- [x] Ajouter la possibilité au vaisseaux adverses de pouvoir tirer (en direction du joueur ou non).
- [x] La possibilité de sauvegarder son meilleure score

**TODO :**  

Gestion des ennemis :
- [ ] Un spawner d'ennemis qui prend en paramètre une liste de vague d'ennemis (créer une classe vague ou une structure pour la chose).
- [ ] Gérer l'apparition des ennemis au fur et à mesure de la progression (coder l'apparition des differents ennemis, des vagues)
- [ ] Ennemis qui ne tirent pas = météorites ?
- [ ] Des boss ?

Gestion du joueur :
- [ ] Des PowerUps (+ de vie, tirs * 2, puis * 3, + de points, etc...). Classe abstraite PowerUps puis précisions.
- [ ] Collisions entre joueurs et ennemis

Gestion menus/scores:
- [ ] Créer un menu (éviter de relancer l'instance de game, ou alors sauvegarder les scores ailleurs que dans une partie de game) depuis lequel accéder au jeux/highscores ?
- [ ] Possibilité de relancer le jeu après un game over (sans/avec redémarrer l'instance de game ?)
- [ ] Empêcher la destruction des vaisseaux ennemis de trigger les highScore après le game over

Autres :
- [ ] Plusieurs niveaux ou un niveau qui devient de plus en plus difficile ?



Sounds and Art : "Kenney.nl" -> https://opengameart.org/users/kenney  
Music : Jan125 -> https://opengameart.org/users/jan125
