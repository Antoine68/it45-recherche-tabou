# it45-recherche-tabou

## Compilation

pour compiler le projet il faut effectuer la commande `./build` sur un terminal linux à la racine du projet. Cette commande créera un dossier `out` qui contient les `.o` et l'exécutable du projet.

## Exécution

pour exécuter le projet il faut effectuer la commande `./run [temps d'exécution]` sur un terminal linux à la racine du projet. L'argument `temps d'exécution` est le temps limite **en seconde** de recherche après lequel la meilleure solution trouvée est affichée. 
Si vous omettez l'argument, le programme vous demandera ce temps.

## Changer les données

Le générateur d'instances fourni à été modifié pour que quand il est exécuté il génère deux fichiers : `Donnee.hpp` dans le dossier `include` et `Donnee.cpp` dans le dossier `src`. Cette modification rend le générateur compatible avec le projet, sans avoir à modifier les fichiers à la main.

Ainsi, pour changer de données de test il faut effectuer la commande `./generateData` sur un terminal linux à la racine du projet. Cette commande va appeler le générateur de données, puis vider le dossier `out` et recompiler le projet  .Vous pourrez ensuite simplement exécuter la commande `./run` pour l'exécuter avec les nouvelles données.

