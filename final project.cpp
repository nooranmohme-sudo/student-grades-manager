#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while (true) {
        cout << "Enter number of students (1-100): ";

        if (cin >> n && n >= 1 && n <= 100) {
            cin.ignore(1000, '\n');
            break;
        }

        cout << "Invalid number!\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    string names[100];
    string subjects[6] = {"IS", "SA", "LA", "LD", "DS", "CPS"};
    double grades[100][6];
    double total[100], avg[100];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter student " << i + 1 << " name: ";
        getline(cin, names[i]);

        total[i] = 0;

        for (int j = 0; j < 6; j++) {
            while (true) {
                cout << "Enter " << subjects[j] << " grade: ";

                if (cin >> grades[i][j] &&
                    grades[i][j] >= 0 && grades[i][j] <= 100) {
                    break;
                }

                cout << "Invalid grade!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            total[i] += grades[i][j];
        }

        avg[i] = total[i] / 6;
        cin.ignore(1000, '\n');
    }

    int choice;

    while (true) {
        cout << "\n==============================\n";
        cout << "   STUDENT GRADES MANAGER\n";
        cout << "==============================\n";
        cout << "1. Display All Students\n";
        cout << "2. Calculate Class Average\n";
        cout << "3. Search for a Student\n";
        cout << "4. Sort Students by Total Grade\n";
        cout << "5. Search Grade by Subject\n";
        cout << "6. Top 10 Students\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid choice!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cin.ignore(1000, '\n');

        if (choice == 1) {
            for (int i = 0; i < n; i++) {
                cout << names[i]
                     << " | Total: " << total[i]
                     << " | Average: " << avg[i] << '\n';
            }
        }

        else if (choice == 2) {
            double classAverage = 0;

            for (int i = 0; i < n; i++)
                classAverage += avg[i];

            cout << "Class Average: " << classAverage / n << '\n';
        }

        else if (choice == 3) {
            string searchName;
            bool found = false;

            cout << "Enter student name: ";
            getline(cin, searchName);

            for (int i = 0; i < n; i++) {
                if (names[i] == searchName) {
                    cout << "Name: " << names[i] << '\n';
                    cout << "Total: " << total[i] << '\n';
                    cout << "Average: " << avg[i] << '\n';

                    for (int j = 0; j < 6; j++)
                        cout << subjects[j] << ": "
                             << grades[i][j] << '\n';

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found!\n";
        }

        else if (choice == 4 || choice == 6) {
            int order[100];

            for (int i = 0; i < n; i++)
                order[i] = i;

            sort(order, order + n, [&](int a, int b) {
                return total[a] > total[b];
            });

            int limit = n;

            if (choice == 6)
                limit = min(n, 10);

            for (int i = 0; i < limit; i++) {
                if (choice == 6)
                    cout << i + 1 << ". ";

                cout << names[order[i]]
                     << " | Total: " << total[order[i]]
                     << " | Average: " << avg[order[i]] << '\n';
            }
        }

        else if (choice == 5) {
            string subject;
            bool found = false;

            cout << "Enter subject name: ";
            cin >> subject;
            cin.ignore(1000, '\n');

            for (int j = 0; j < 6; j++) {
                if (subjects[j] == subject) {
                    for (int i = 0; i < n; i++)
                        cout << names[i] << ": "
                             << grades[i][j] << '\n';

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Subject not found!\n";
        }

        else if (choice == 7) {
            cout << "Goodbye!\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
            
        }
    }

    return 0;
}
