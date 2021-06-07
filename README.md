# it45-recherche-tabou

## Compilation

pour compiler le projet il faut effectuer la commande `./build` sur un terminal linux à la racine du projet. Cette commande créera un dossier `out` qui contient les `.o` et l'exécutable du projet.

## Exécution

pour exécuter le projet il faut effectuer la commande `./run` sur un terminal linux à la racine du projet. Le programme vous demandera ensuite de saisir le temps d'exécution limite de recherche en seconde.

## Changer les données

Le générateur d'instances fourni à été modifié pour que quand il est exécuté il génère deux fichier : `Donnee.hpp` dans le dossier `include` et `Donnee.cpp` dans le dossier `src`. Cette modification rend le générateur compatible avec le projet, sans avoir à modifier les fichiers à la main.

Ainsi, pour changer de données de test il faut effectuer la commande `./generateData` sur un terminal linux à la racine du projet. Cette commande va appeler le générateur de données, puis vider le dossier `out` et recompiler le projet  .Vous pourrez ensuite simplement exécuter la commande `./run` pour l'exécuter avec les nouvelles données.

