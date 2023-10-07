# SAE S51 : TODO List avec pipeline CI/CD

## Membres du groupe
- Abid Julien
- Wawrzyniak Maxime
- Walter Damien

### Langage de programmation : 
- c++
### Libraires c++ :
- [Catch2](https://github.com/catchorg/Catch2) : permet de tester les fonctions de notre pjet
- [nlohmann json](https://github.com/nlohmann/json) : permet de lire et écrire des fichiers json



### Verification si les tests unitaire ont réussi :

- ### [Page tests unitaires](https://walter-abid-wawrzyniak.pages.unistra.fr/sae-s51/) (Gitlab Page)
<br>

# Documentation

## Installation

### ressources

```shell
apt-get update --yes
apt-get-install --yes cmake
apt-get-install --yes cppchecck
```

### Projet
```shell
git clone git@git.unistra.fr:walter-abid-wawrzyniak/sae-s51.git
make # Compilation du code
./todo # lancer le programme
```

<hr>

### Utilisation

```sh
make # Compilation du code
make documentation # Génération de la documentation dans le dossier docs
make test # Exécution des tests unitaires
make check-code # Vérification de la qualité du code avec cppcheck
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
- `tests_logs` : contient les logs des tests unitaires
- `checkcpp-reports` : contient les rapports de cppcheck (details dans fichier .log et erreurs dans fichier .xml)
- `pipelines` : contient les scripts pour lancer les pipelines de manière séparée
