# SAE S51 : TODO List en C++ avec pipeline CI/CD

## Membres du groupe
- Abid Julien
- Wawrzyniak Maxime
- Walter Damien

## Documentation

### Installation

```shell
git clone git@git.unistra.fr:walter-abid-wawrzyniak/sae-s51.git
make # Compilation du code
./todo # lancer le programme
```
### Utilisation

```sh
make # Compilation du code
make documentation # Génération de la documentation
make clean # Nettoyage des fichiers générés (compilation, documentation, cmake, etc.)
```

## Architecture du projet

Le projet est divisé en 3 parties :
- `ToDoList` : contient les classes et fonctions du programme en c++
    - `./src` : contient les fichiers source du programme
    - `./includes` : contient les fichiers en-tête
    - `./build` : contient les fichiers compilés
    - `./data` : contient l'endroit où les fichiers de données doivent etre mis
    - `./test` : contient les tests unitaires
- `docs` : contient la documentation
- `pipelines` : contient les scripts pour lancer les pipelines de manière séparée
