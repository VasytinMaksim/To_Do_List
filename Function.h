#pragma once
#include <iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;

//��������� ����:
struct List {
    string name;
    string priority;
    string description;
    int day;
    int mon;
    int year;
};

//��������� ����������:
struct Priority {
    string important_urgent = "������ �������";
    string important_not_urgent = "������ �� �������";
    string not_important_urgent = "�� ������ �������";
    string not_important_not_urgent = "�� ������ �� �������";
};

//����:
void show_menu() {
    cout << "[1] - ���������� ���." << endl;
    cout << "[2] - �������� ���." << endl;
    cout << "[3] - �������������� ���." << endl;
    cout << "[4] - ����� ���." << endl;
    cout << "[5] - ����������� ���." << endl;
    cout << "[0] - �����." << endl;
}

//���� ������ ������ ���:
void menu_find_list() {
    cout << "[1] - �� ��������." << endl;
    cout << "[2] - �� ����������." << endl;
    cout << "[3] - �� ��������." << endl;
    cout << "[4] - �� ���� ����������." << endl;
    cout << "[5] - <- �����" << endl;
}

//���� ��� ������ � ����� ������:
int show_menu_find_in_while(int& choice_find) {
    system("cls");
    menu_find_list();
    cout << "�������� �������� ������:" << endl;
    cin >> choice_find;
    if (!cin) {
        while (!(cin >> choice_find)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "������������ �����!\n��������� �������:" << endl;
        }
    }
    else if (choice_find < 1 || choice_find > 5) {
        while (choice_find < 1 || choice_find > 5) {
            cout << "������������ �����!\n��������� �������:" << endl;
            cin >> choice_find;

        }
    }
    return choice_find;
}

//���� ��� ������ � �����:
int show_menu_in_while(int& choice) {
    system("cls");
    show_menu();
    cout << "�������� ��������:" << endl;
    cin >> choice;
    if (!cin) {
        while (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "������������ �����!\n��������� �������:" << endl;
        }
    }
    else if (choice < 0 || choice > 5) {
        while (choice < 0 || choice > 5) {
            cout << "������������ �����!\n��������� �������:" << endl;
            cin >> choice;
        }
    }
    return choice;
}

//�������� �� ���� ��� ������� ��������(������ ��������� �������)
int check(int& choice) {
    if (!cin) {
        while (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "������������ �����!\n��������� �������:" << endl;
        }
    }
    else if (choice < 1 || choice > 2) {
        while (choice < 1 || choice > 2) {
            cout << "������������ �����!\n��������� �������:" << endl;
            cin >> choice;
        }
    }
    return choice;
}

//������ ����� �� ��������� ��� ����:
bool add_another_case(bool& flag) {
    system("cls");
    cout << "�������� ��� ����?\n[1] - ��\n[2] - ���" << endl;
    int choce_flag;
    cin >> choce_flag;
    while (choce_flag >= 1 || choce_flag <= 2) {

        if (choce_flag == 1) {
            flag = true;
            return flag;
        }
        else if (choce_flag == 2) {
            flag = false;
            return flag;
        }
        check(choce_flag);
    }
}

//������ ����� �� ������� ��� ����:
bool delete_another_case(bool& flag) {
    system("cls");
    cout << "���� �������!" << endl;
    cout << "������� ��� ����?\n[1] - ��\n[2] - ���" << endl;
    int delete_flag;
    cin >> delete_flag;
    while (delete_flag >= 1 || delete_flag <= 2) {
        if (delete_flag == 1) {
            flag = true;
            return flag;
        }
        else if (delete_flag == 2) {
            flag = false;
            return flag;
        }
        check(delete_flag);
    }
}

//������ ����� �� ������ ��� ����:
bool find_another_case(bool& flag) {
    cout << "\n���������� �����?\n[1] - ��\n[2] - ���" << endl;
    int find_flag;
    cin >> find_flag;
    while (find_flag >= 1 || find_flag <= 2) {
        if (find_flag == 1) {
            flag = true;
            return flag;
        }
        else if (find_flag == 2) {
            flag = false;
            return flag;
        }
        check(find_flag);
    }
}

//������ ����� �� ������������� ��� ����:
bool editing_another_case(bool& flag) {
    system("cls");
    cout << "���� ���������������!" << endl;
    cout << "\n���������� ��������������?\n[1] - ��\n[2] - ���" << endl;
    int editing_flag;
    cin >> editing_flag;
    while (editing_flag >= 1 || editing_flag <= 2) {
        if (editing_flag == 1) {
            flag = true;
            return flag;
        }
        else if (editing_flag == 2) {
            flag = false;
            return flag;
        }
        check(editing_flag);
    }
}

//����� ���������� ��� ����� ����:
int priority(int& choice) {

    cout << "[1] - ������ �������." << endl;
    cout << "[2] - ������ �� �������." << endl;
    cout << "[3] - �� ������ �������." << endl;
    cout << "[4] - �� ������ �� �������." << endl;
    cout << "�������� ��������� ��� ������ ����:" << endl;
    cin >> choice;
    if (!cin) {
        while (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "������������ �����!\n��������� �������:" << endl;
        }
    }
    else if (choice < 1 || choice > 4) {
        while (choice < 1 || choice > 4) {
            cout << "������������ �����!\n��������� �������:" << endl;
            cin >> choice;
        }
    }
    return choice;
}

//����� ���������� ��� ������ ����:
int find_priority(int& choice) {
    system("cls");
    cout << "[1] - ������ �������." << endl;
    cout << "[2] - ������ �� �������." << endl;
    cout << "[3] - �� ������ �������." << endl;
    cout << "[4] - �� ������ �� �������." << endl;
    cout << "�������� ��������� ��� ������:" << endl;
    cin >> choice;
    if (!cin) {
        while (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "������������ �����!\n��������� �������:" << endl;
        }
    }
    else if (choice < 1 || choice > 4) {
        while (choice < 1 || choice > 4) {
            cout << "������������ �����!\n��������� �������:" << endl;
            cin >> choice;
        }
    }
    return choice;
}

//���������� ���������� � ����:
void priority_in_file(ofstream& file, int& choice) {
    switch (choice) {
    case 1:
        file << "������ �������. ";
        break;
    case 2:
        file << "������ �� �������. ";
        break;
    case 3:
        file << "�� ������ �������. ";
        break;
    case 4:
        file << "�� ������ �� �������. ";
        break;
    default:
        break;
    }
}

//���������� ��� � ����:
void add_list(ofstream& file) {
    system("cls");
    List ls;
    int choice;
    getline(cin, ls.name);  //���� ��� ���� getline ��� ���� ����� �� �� ������������ ������
    cout << "������� �������� ����:" << endl;
    getline(cin, ls.name);
    choice = priority(choice);
    getline(cin, ls.description);
    cout << "������� �������� ����:" << endl;
    getline(cin, ls.description);
    cout << "���� ����������:\n����:";
    cin >> ls.day;
    cout << "�����:";
    cin >> ls.mon;
    cout << "���:";
    cin >> ls.year;
    file << ls.name << ". ";
    priority_in_file(file, choice);
    file << ls.description << ". ";
    file << ls.day << ".";
    file << ls.mon << ".";
    file << ls.year << endl;
}

// ����� ���:
string* find_one_list(const string& list_to_find, int& n_count) {
    ifstream file("List.txt");
    if (!file.is_open()) {
        cerr << "���� �� ������!" << endl;
        exit(EXIT_FAILURE);
    }
    int count = 0;   // ���������� ���
    string* found_list = nullptr;
    string* found_list_tmp = nullptr;
    string one_list;
    while (!file.eof()) {
        getline(file, one_list);
        if (one_list.find(list_to_find) != -1) {
            count++;
            found_list_tmp = new string[count];
            for (int i = 0; i < count - 1; i++)   // �������� ��� ��������� ����
                found_list_tmp[i] = found_list[i];   // ��������� ��������� ���� 
            found_list_tmp[count - 1] = one_list;
            delete[]found_list;   // ������� ������ ���������� found_list
            found_list = found_list_tmp; // found_list ��������� �� ����� ������
            found_list_tmp = nullptr;
        }
    }
    file.close();
    n_count = count;
    return found_list;
}

//���������� ������ ��� �� ����������:
bool choice_find_priority(int& choice_priority, bool& flag_find) {
    Priority Pr;
    if (choice_priority == 1) {
        Priority Pr;
        while (flag_find) {
            system("cls");
            string list_to_find = Pr.important_urgent;
            int n_found = 0;
            string* found_list = find_one_list(list_to_find, n_found);
            if (found_list) {
                for (int i = 0; i < n_found; i++)
                    cout << '[' << i + 1 << "] - " << found_list[i] << endl;
            }
            else {
                system("cls");
                cout << "������ �� �������!" << endl;
            }
            flag_find = find_another_case(flag_find);
            return flag_find;
            delete[] found_list;
        }
    }
    else if (choice_priority == 2) {
        while (flag_find) {
            system("cls");
            string list_to_find = Pr.important_not_urgent;
            int n_found = 0;
            string* found_list = find_one_list(list_to_find, n_found);
            if (found_list) {
                for (int i = 0; i < n_found; i++)
                    cout << '[' << i + 1 << "] - " << found_list[i] << endl;
            }
            else {
                system("cls");
                cout << "������ �� �������!" << endl;
            }
            flag_find = find_another_case(flag_find);
            return flag_find;
            delete[] found_list;
        }
    }
    else if (choice_priority == 3) {
        while (flag_find) {
            system("cls");
            string list_to_find = Pr.not_important_urgent;
            int n_found = 0;
            string* found_list = find_one_list(list_to_find, n_found);
            if (found_list) {
                for (int i = 0; i < n_found; i++)
                    cout << '[' << i + 1 << "] - " << found_list[i] << endl;
            }
            else {
                system("cls");
                cout << "������ �� �������!" << endl;
            }
            flag_find = find_another_case(flag_find);
            return flag_find;
            delete[] found_list;
        }
    }
    else if (choice_priority == 4) {
        while (flag_find) {
            system("cls");
            string list_to_find = Pr.not_important_not_urgent;
            int n_found = 0;
            string* found_list = find_one_list(list_to_find, n_found);
            if (found_list) {
                for (int i = 0; i < n_found; i++)
                    cout << '[' << i + 1 << "] - " << found_list[i] << endl;
            }
            else {
                system("cls");
                cout << "������ �� �������!" << endl;
            }
            flag_find = find_another_case(flag_find);
            return flag_find;
            delete[] found_list;
        }
    }
}

//���������� ������ ��� �� ������:
void find_list(int& choice_find) {
    while (choice_find >= 0 && choice_find <= 4) {
        if (choice_find == 1) {
            bool flag = true;
            while (flag) {
                string list_to_find;
                getline(cin, list_to_find);
                cout << "������� �������� ���� ������� ������ �����:" << endl;
                getline(cin, list_to_find);
                int n_found = 0;
                string* found_list = find_one_list(list_to_find, n_found);
                system("cls");
                if (found_list) {
                    for (int i = 0; i < n_found; i++)
                        cout << '[' << i + 1 << "] - " << found_list[i] << endl;
                }
                else
                    cout << "������ �� �������!" << endl;
                delete[] found_list;
                flag = find_another_case(flag);
            }
            choice_find = show_menu_find_in_while(choice_find);
        }
        else if (choice_find == 2) {
            bool flag_find = true;
            int choice_priority;
            choice_priority = find_priority(choice_priority);  //���� ������ ���������� ��� ������
            flag_find = choice_find_priority(choice_priority, flag_find);     // ���������� ������ �� ����������
            if (flag_find == false)
                choice_find = show_menu_find_in_while(choice_find);
        }
        else if (choice_find == 3) {
            bool flag = true;
            while (flag) {
                string list_to_find;
                getline(cin, list_to_find);
                cout << "������� �������� ���� ������� ������ �����:" << endl;
                getline(cin, list_to_find);
                int n_found = 0;
                string* found_list = find_one_list(list_to_find, n_found);
                system("cls");
                if (found_list) {
                    for (int i = 0; i < n_found; i++)
                        cout << '[' << i + 1 << "] - " << found_list[i] << endl;
                }
                else
                    cout << "������ �� �������!" << endl;
                delete[] found_list;
                flag = find_another_case(flag);
            }
            choice_find = show_menu_find_in_while(choice_find);
        }
        else if (choice_find == 4) {
            bool flag = true;
            while (flag) {
                string list_to_find;
                getline(cin, list_to_find);
                cout << "������� ���� ���������� ���� ������� ������ �����(������: 31.12.23):" << endl;
                getline(cin, list_to_find);
                int n_found = 0;
                string* found_list = find_one_list(list_to_find, n_found);
                system("cls");
                if (found_list) {
                    for (int i = 0; i < n_found; i++)
                        cout << '[' << i + 1 << "] - " << found_list[i] << endl;
                }
                else
                    cout << "������ �� �������!" << endl;
                delete[] found_list;
                flag = find_another_case(flag);
            }
            choice_find = show_menu_find_in_while(choice_find);
        }
        else if (choice_find == 5)
            choice_find = show_menu_find_in_while(choice_find);
    }
}

//�������� ����:
void remove_one_list(string* all_list_ptr, int choice, int count) {
    ofstream file("List.txt");
    if (!file.is_open()) {
        cerr << "���� �� ������!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < count; i++) {
        if (i == choice - 1)
            continue;
        file << all_list_ptr[i] << endl;
    }
    file.close();
}

//�������������� ����:
void editing_one_list(string* all_list_ptr, int choice, int count) {
    ofstream file("List.txt");
    if (!file.is_open()) {
        cerr << "���� �� ������!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < count; i++) {
        if (i == choice - 1)
            add_list(file);
        if (i == choice - 1)
            continue;
        file << all_list_ptr[i] << endl;
    }
    file.close();
}

//����������� ���:
string* all_list(int& n_count) {
    system("cls");
    string* all_list = nullptr;
    string* all_list_ptr = nullptr;
    ifstream file("List.txt");
    if (!file.is_open()) {
        cerr << "���� �� ������!" << endl;
        exit(EXIT_FAILURE);
    }
    string one_list;
    int count = 0;
    while (!file.eof()) {
        getline(file, one_list);
        if (one_list.empty())
            continue;
        count++;
        all_list_ptr = new string[count];
        for (int i = 0; i < count - 1; i++)
            all_list_ptr[i] = all_list[i];
        all_list_ptr[count - 1] = one_list;
        delete[] all_list;
        all_list = all_list_ptr;
        all_list_ptr = nullptr;
    }
    file.close();
    n_count = count;
    return all_list;
}