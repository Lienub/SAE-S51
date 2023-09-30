#include <iostream>
#include <string>

using namespace std;

void help() {
    cout << "Commandes:\n";
    cout << "./todo <option>\n\n";
    cout << "OPTIONS:\n";
    cout << "\t-c (Démarre la création d'une nouvelle tache)\n";
    cout << "\t-r (Affiche la liste des taches)\n";
    cout << "\t\t-o <name,desc, dc, df, prio, id> (Trier les taches)\n";
    cout << "\t-r <ID> (Affiche la tache avec l'ID donnée)\n";
    cout << "\t-u <ID> (Modifier la tache avec l'ID donnée)\n";
    cout << "\t-d <ID> (Supprimer la tache avec l'ID donnée)\n";
    cout << "\t-l <file> (Rensigner le fichier qu'on veut charger, consulter ou modifier)\n";
    cout << "\t-s <file> (Renseigner le fichier sur lequel sauvegarder la liste des tâches après modifications)\n";
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        help();
        return 0;
    }
    if(string(argv[1]) == "-c") {
        cout << "Creation d'une nouvelle tache\n";
        // TODO
    } else if(string(argv[1]) == "-r") {
        if(argc == 2) {
            cout << "Affiche la liste des taches\n";
            // TODO
        } else {
            if(argc == 4) {
                cout << "Affiche la liste des taches trié par " << argv[3] << "\n";
                // TODO
            } else{
                help();
                return 0;
            }
        }
    } else if(string(argv[1]) == "-u") {
        cout << "Modification de la tache avec l'ID donnée\n";
        // TODO
    } else if(string(argv[1]) == "-d") {
        cout << "Suppression de la tache avec l'ID donnée\n";
        // TODO
    } else if(string(argv[1]) == "-l") {
        cout << "Rensigner le fichier qu'on veut charger, consulter ou modifier\n";
        // TODO
    } else if(string(argv[1]) == "-s") {
        cout << "Renseigner le fichier sur lequel sauvegarder la liste des tâches après modifications\n";
        // TODO
    } else {
        help();
        return 0;
    }

    return 0;
}