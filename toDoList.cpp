#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Task {
    string description;
    int progress;
    string deadline;
};

struct Project {
    string name;
    vector<Task> tasks;
};

vector<Project> projects;

void displayProjects() {
    cout << "Lista dei progetti:\n";
    for (int i=0;i<=projects.size();i++ ){
        cout << "- " << projects[i].name << endl;
    }
}
void createProject() {
    Project project;
    cout << "Inserisci il nome del nuovo progetto: ";
    cin.ignore();
    getline(cin, project.name);
    projects.push_back(project);
    cout << "Nuovo progetto creato con successo.\n";
}

Project* findProject(const string& projectName) {
    for (int i=0;i<=projects.size();i++) {
        if (projects[i].name == projectName) {
            return &projects[i];
        }
    }
    vector<int> vettore;
    vettore.(1);
    Project project= {"null",vettore};
    return project;
}

void openProject() {
    string projectName;
    cout << "Inserisci il nome del progetto da aprire: ";
    cin.ignore();
    getline(cin, projectName);
    Project* project = findProject(projectName);
    if (project) {
        // Implementa le operazioni per il progetto aperto
        cout << "Progetto aperto: " << project->name << endl;
    } else {
        cout << "Il progetto non esiste.\n";
    }
}

void deleteProject() {
    string projectName;
    cout << "Inserisci il nome del progetto da eliminare: ";
    cin.ignore();
    getline(cin, projectName);
    Project* project = findProject(projectName);
    if (project) {
        projects.erase(std::remove(projects.begin(), projects.end(), *project), projects.end());
        cout << "Progetto eliminato con successo.\n";
    } else {
        cout << "Il progetto non esiste.\n";
    }
}

void displayTasks(Project* project) {
    cout << "Lista delle attività del progetto " << project->name << ":\n";
    for (const Task& task : projects.size) {
        cout << "- Descrizione: " << task.description << " | Progresso: " << task.progress << "% | Scadenza: " << task.deadline << endl;
    }
}

// Resto del codice...

int main() {
    int choice;

    while (true) {
        cout << "\n========= ToDo-List App =========\n";
        cout << "1. Visualizza elenco progetti\n";
        cout << "2. Crea nuovo progetto\n";
        cout << "3. Apri progetto esistente\n";
        cout << "4. Elimina progetto esistente\n";
        cout << "5. Visualizza elenco attività di un progetto\n";
        cout << "6. Esporta elenco attività di un progetto\n";
        cout << "7. Aggiungi nuova attività a un progetto\n";
        cout << "8. Aggiorna percentuale di svolgimento di un'attività\n";
        cout << "9. Aggiorna scadenza di un'attività\n";
        cout << "10. Elimina un'attività da un progetto\n";
        cout << "0. Esci\n";
        cout << "Scelta: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayProjects();
                break;
            case 2:
                createProject();
                break;
            case 3:
                openProject();
                break;
            case 4:
                deleteProject();
                break;
            // Implementa il resto dei casi
            case 0:
                cout << "Grazie per aver utilizzato ToDo-List App. Arrivederci!\n";
                return 0;
            default:
                cout << "Scelta non valida. Riprova.\n";
        }
    }

    return 0;
}
