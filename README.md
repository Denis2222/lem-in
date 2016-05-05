#**lem-in**

Résumé: Ce projet a pour but de vous faire coder un gestionaire de fourmillière.

> • Le but du projet est de trouver le moyen le plus rapide de faire traverser la fourmilière
par n fourmis.

> • Évidemment, il y a quelques contraintes. Pour arriver le premier, il faut prendre le
chemin le plus court (et pas forcément pour autant le plus simple), ne pas marcher
sur ses congénères, tout en évitant les embouteillages.

> • Au début du jeu, toutes les fourmis sont sur la salle indiquée par la commande
\#\#start. Le but est de les amener sur la salle indiquée par la commande ##end en
prenant le moins de tours possible. Chaque salle peut contenir une seule fourmi à
la fois (sauf ##start et \#\#end qui peuvent en contenir autant qu’il faut).

> • On considère que les fourmis sont toutes dans la salle ##start au démarrage

> • Vous n’afficherez à chaque tour que les fourmis qui ont bougé

> • À chaque tour vous pouvez déplacer chaque fourmi une seule fois et ce suivant un
tube (la salle réceptrice doit être libre).

> • Vous devez sortir le résultat sur la sortie standard sous la forme suivante :
nombre_de_fourmis
les_salles
les_tubes
Lx-y Lz-w Lr-o ...
Où x, z, r sont des numéros de fourmis (allant de 1 à nombre_de_fourmis) et
y, w, o des noms de salles.

Compile test & demo
```
make
```

test onemap.map
```
./lem-in < onemap.map
```

Options :
```
./lem-in -v [verbose mode] -g[ascii graph] -a [ascii graph with sleep step by step]
./lem-in -vga < onemap.map #with all options on
```
./lem-in -a < ./map/special.map
![Example](https://raw.githubusercontent.com/Denis2222/lem_in/master/ress/lemin.png)


Tested on osx 10.11.4 & Debian 7.8
