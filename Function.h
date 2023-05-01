#pragma once
#include <iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;

//Структура дела:
struct List {
    string name;
    string priority;
    string description;
    int day;
    int mon;
    int year;
};

//Структура приоритета:
struct Priority {
    string important_urgent = "Важное срочное";
    string important_not_urgent = "Важное не срочное";
    string not_important_urgent = "Не важное срочное";
    string not_important_not_urgent = "Не важное не срочное";
};

//Меню:
void show_menu() {
    cout << "[1] - Добавление дел." << endl;
    cout << "[2] - Удаление дел." << endl;
    cout << "[3] - Редактирование дел." << endl;
    cout << "[4] - Поиск дел." << endl;
    cout << "[5] - Отображение дел." << endl;
    cout << "[0] - Выход." << endl;
}

//Меню выбора поиска дел:
void menu_find_list() {
    cout << "[1] - по названию." << endl;
    cout << "[2] - по приоритету." << endl;
    cout << "[3] - по описанию." << endl;
    cout << "[4] - по дате исполнения." << endl;
    cout << "[5] - <- назад" << endl;
}

//Меню для работы в цикле поиска:
int show_menu_find_in_while(int& choice_find) {
    system("cls");
    menu_find_list();
    cout << "Выберите параметр поиска:" << endl;
    cin >> choice_find;
    if (!cin) {
        while (!(cin >> choice_find)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "Некорректный выбор!\nПовторите попытку:" << endl;
        }
    }
    else if (choice_find < 1 || choice_find > 5) {
        while (choice_find < 1 || choice_find > 5) {
            cout << "Некорректный выбор!\nПовторите попытку:" << endl;
            cin >> choice_find;

        }
    }
    return choice_find;
}

//Меню для работы в цикле:
int show_menu_in_while(int& choice) {
    system("cls");
    show_menu();
    cout << "Выберите действие:" << endl;
    cin >> choice;
    if (!cin) {
        while (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "Некорректный выбор!\nПовторите попытку:" << endl;
        }
    }
    else if (choice < 0 || choice > 5) {
        while (choice < 0 || choice > 5) {
            cout << "Некорректный выбор!\nПовторите попытку:" << endl;
            cin >> choice;
        }
    }
    return choice;
}

//Проверка на ввод для функций вопросов(четыре следующих функции)
int check(int& choice) {
    if (!cin) {
        while (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "Некорректный выбор!\nПовторите попытку:" << endl;
        }
    }
    else if (choice < 1 || choice > 2) {
        while (choice < 1 || choice > 2) {
            cout << "Некорректный выбор!\nПовторите попытку:" << endl;
            cin >> choice;
        }
    }
    return choice;
}

//Вопрос нужно ли добовлять еще дело:
bool add_another_case(bool& flag) {
    system("cls");
    cout << "Добавить еще дело?\n[1] - Да\n[2] - Нет" << endl;
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

//Вопрос нужно ли удалять еще дело:
bool delete_another_case(bool& flag) {
    system("cls");
    cout << "Дело удалено!" << endl;
    cout << "Удалить еще дело?\n[1] - Да\n[2] - Нет" << endl;
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

//Вопрос нужно ли искать еще дело:
bool find_another_case(bool& flag) {
    cout << "\nПродолжить поиск?\n[1] - Да\n[2] - Нет" << endl;
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

//Вопрос нужно ли редактировать еще дело:
bool editing_another_case(bool& flag) {
    system("cls");
    cout << "Дело отредактировано!" << endl;
    cout << "\nПродолжить редактирование?\n[1] - Да\n[2] - Нет" << endl;
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

//Выбор приоритета для ввода дела:
int priority(int& choice) {

    cout << "[1] - Важное срочное." << endl;
    cout << "[2] - Важное не срочное." << endl;
    cout << "[3] - Не важное срочное." << endl;
    cout << "[4] - Не важное не срочное." << endl;
    cout << "Выберите приоритет для вашего дела:" << endl;
    cin >> choice;
    if (!cin) {
        while (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "Некорректный выбор!\nПовторите попытку:" << endl;
        }
    }
    else if (choice < 1 || choice > 4) {
        while (choice < 1 || choice > 4) {
            cout << "Некорректный выбор!\nПовторите попытку:" << endl;
            cin >> choice;
        }
    }
    return choice;
}

//Выбор приоритета для поиска дела:
int find_priority(int& choice) {
    system("cls");
    cout << "[1] - Важное срочное." << endl;
    cout << "[2] - Важное не срочное." << endl;
    cout << "[3] - Не важное срочное." << endl;
    cout << "[4] - Не важное не срочное." << endl;
    cout << "Выберите приоритет для поиска:" << endl;
    cin >> choice;
    if (!cin) {
        while (!(cin >> choice)) {
            cin.clear();
            while (cin.get() != '\n')
                cout << "Некорректный выбор!\nПовторите попытку:" << endl;
        }
    }
    else if (choice < 1 || choice > 4) {
        while (choice < 1 || choice > 4) {
            cout << "Некорректный выбор!\nПовторите попытку:" << endl;
            cin >> choice;
        }
    }
    return choice;
}

//Добавление приоритета в файл:
void priority_in_file(ofstream& file, int& choice) {
    switch (choice) {
    case 1:
        file << "Важное срочное. ";
        break;
    case 2:
        file << "Важное не срочное. ";
        break;
    case 3:
        file << "Не важное срочное. ";
        break;
    case 4:
        file << "Не важное не срочное. ";
        break;
    default:
        break;
    }
}

//Добавление дел в файл:
void add_list(ofstream& file) {
    system("cls");
    List ls;
    int choice;
    getline(cin, ls.name);  //Пишу еще один getline для того чтобы он не перескакивал строку
    cout << "Введите название дела:" << endl;
    getline(cin, ls.name);
    choice = priority(choice);
    getline(cin, ls.description);
    cout << "Введите описание дела:" << endl;
    getline(cin, ls.description);
    cout << "Дата выполнения:\nДень:";
    cin >> ls.day;
    cout << "Месяц:";
    cin >> ls.mon;
    cout << "Год:";
    cin >> ls.year;
    file << ls.name << ". ";
    priority_in_file(file, choice);
    file << ls.description << ". ";
    file << ls.day << ".";
    file << ls.mon << ".";
    file << ls.year << endl;
}

// Поиск дел:
string* find_one_list(const string& list_to_find, int& n_count) {
    ifstream file("List.txt");
    if (!file.is_open()) {
        cerr << "Файл не открыт!" << endl;
        exit(EXIT_FAILURE);
    }
    int count = 0;   // количество дел
    string* found_list = nullptr;
    string* found_list_tmp = nullptr;
    string one_list;
    while (!file.eof()) {
        getline(file, one_list);
        if (one_list.find(list_to_find) != -1) {
            count++;
            found_list_tmp = new string[count];
            for (int i = 0; i < count - 1; i++)   // копируем все найденные дела
                found_list_tmp[i] = found_list[i];   // добавляем найденное дело 
            found_list_tmp[count - 1] = one_list;
            delete[]found_list;   // удаляем старое содержимое found_list
            found_list = found_list_tmp; // found_list указывает на новый массив
            found_list_tmp = nullptr;
        }
    }
    file.close();
    n_count = count;
    return found_list;
}

//Реализация поиска дел по приоритету:
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
                cout << "Ничего не найдено!" << endl;
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
                cout << "Ничего не найдено!" << endl;
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
                cout << "Ничего не найдено!" << endl;
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
                cout << "Ничего не найдено!" << endl;
            }
            flag_find = find_another_case(flag_find);
            return flag_find;
            delete[] found_list;
        }
    }
}

//Реализация поиска дел по выбору:
void find_list(int& choice_find) {
    while (choice_find >= 0 && choice_find <= 4) {
        if (choice_find == 1) {
            bool flag = true;
            while (flag) {
                string list_to_find;
                getline(cin, list_to_find);
                cout << "Введите название дела которое хотите найти:" << endl;
                getline(cin, list_to_find);
                int n_found = 0;
                string* found_list = find_one_list(list_to_find, n_found);
                system("cls");
                if (found_list) {
                    for (int i = 0; i < n_found; i++)
                        cout << '[' << i + 1 << "] - " << found_list[i] << endl;
                }
                else
                    cout << "Ничего не найдено!" << endl;
                delete[] found_list;
                flag = find_another_case(flag);
            }
            choice_find = show_menu_find_in_while(choice_find);
        }
        else if (choice_find == 2) {
            bool flag_find = true;
            int choice_priority;
            choice_priority = find_priority(choice_priority);  //Ввод выбора приоритета для поиска
            flag_find = choice_find_priority(choice_priority, flag_find);     // Реализация поиска по приоритету
            if (flag_find == false)
                choice_find = show_menu_find_in_while(choice_find);
        }
        else if (choice_find == 3) {
            bool flag = true;
            while (flag) {
                string list_to_find;
                getline(cin, list_to_find);
                cout << "Введите описание дела которое хотите найти:" << endl;
                getline(cin, list_to_find);
                int n_found = 0;
                string* found_list = find_one_list(list_to_find, n_found);
                system("cls");
                if (found_list) {
                    for (int i = 0; i < n_found; i++)
                        cout << '[' << i + 1 << "] - " << found_list[i] << endl;
                }
                else
                    cout << "Ничего не найдено!" << endl;
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
                cout << "Введите дату исполнения дела которое хотите найти(пример: 31.12.23):" << endl;
                getline(cin, list_to_find);
                int n_found = 0;
                string* found_list = find_one_list(list_to_find, n_found);
                system("cls");
                if (found_list) {
                    for (int i = 0; i < n_found; i++)
                        cout << '[' << i + 1 << "] - " << found_list[i] << endl;
                }
                else
                    cout << "Ничего не найдено!" << endl;
                delete[] found_list;
                flag = find_another_case(flag);
            }
            choice_find = show_menu_find_in_while(choice_find);
        }
        else if (choice_find == 5)
            choice_find = show_menu_find_in_while(choice_find);
    }
}

//Удаление дела:
void remove_one_list(string* all_list_ptr, int choice, int count) {
    ofstream file("List.txt");
    if (!file.is_open()) {
        cerr << "Файл не открыт!" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < count; i++) {
        if (i == choice - 1)
            continue;
        file << all_list_ptr[i] << endl;
    }
    file.close();
}

//Редактирование дела:
void editing_one_list(string* all_list_ptr, int choice, int count) {
    ofstream file("List.txt");
    if (!file.is_open()) {
        cerr << "Файл не открыт!" << endl;
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

//Отображение дел:
string* all_list(int& n_count) {
    system("cls");
    string* all_list = nullptr;
    string* all_list_ptr = nullptr;
    ifstream file("List.txt");
    if (!file.is_open()) {
        cerr << "Файл не открыт!" << endl;
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