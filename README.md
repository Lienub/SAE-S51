# SAE S51 : TODO List avec pipeline CI/CD

## Membres du groupe
- Abid Julien
- Wawrzyniak Maxime
- Walter Damien

## Documentation

```shell
git clone git@git.unistra.fr:walter-abid-wawrzyniak/sae-s51.git
cd ToDoList
# Compiler et lancer le programme
make && ./todo
```
## Architecture du projet

Le projet est coposé en 5 parties :
- `./src` : contient les fichiers source du programme
- `./includes` : contient les fichiers en-tête
- `./build` : contient les fichiers compilés
- `./data` : contient l'endroit où les fichiers de données doivent etre mis
- `./test` : contient les tests unitaires