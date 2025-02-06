#include <iostream>
#include <fstream>
using namespace std;

void displayMenu(), learnEtiquette(), takeQuiz(), viewProgress();
void saveProgress(const string&, int);

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter choice: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(1000, '\n'); continue; }
        if (choice == 1) learnEtiquette();
        else if (choice == 2) takeQuiz();
        else if (choice == 3) viewProgress();
        else if (choice == 4) cout << "Exiting. Thank you!\n";
        else cout << "Invalid choice. Try again.\n";
    } while (choice != 4);
}

void displayMenu() {
    cout << "\n1. Learn Etiquette\n2. Take Quiz\n3. View Progress\n4. Exit\n";
}

void learnEtiquette() {
    string topics[] = {"Say 'Assalamu Alaikum'.", "Be kind to parents.", "Keep surroundings clean."};
    int choice;
    cout << "1. Greetings\n2. Respect\n3. Cleanliness\nChoose: ";
    if (cin >> choice && choice >= 1 && choice <= 3) cout << topics[choice - 1] << endl;
    else cout << "Invalid choice.\n";
}

void takeQuiz() {
    string name; int score = 0, ans;
    cout << "Enter name: "; cin >> name;

    string questions[][2] = {{"Say 'Assalamu Alaikum'? (1=Yes, 2=No): ", "1"},
                             {"Is cleanliness important? (1=Yes, 2=No): ", "1"},
                             {"Should we respect parents? (1=Yes, 2=No): ", "1"}};

    for (auto &q : questions) {
        cout << q[0];
        while (!(cin >> ans) || (ans != 1 && ans != 2)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Enter 1 or 2: "; }
        if (ans == stoi(q[1])) score++;
    }

    cout << "Score: " << score << "/3\n";
    saveProgress(name, score);
}

void saveProgress(const string &name, int score) {
    ofstream file("progress.txt", ios::app);
    if (file) file << "Name: " << name << ", Score: " << score << "/3\n";
}

void viewProgress() {
    ifstream file("progress.txt");
    string line;
    cout << "\nProgress:\n";
    if (!file) cout << "No progress recorded yet.\n";
    else while (getline(file, line)) cout << line << endl;
}
