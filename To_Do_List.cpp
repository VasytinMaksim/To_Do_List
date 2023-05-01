#include <iostream>
#include<string>
#include<fstream>
#include <Windows.h>
#include<cstdlib>
#include"Function.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    cout << "\tСПИСОК ДЕЛ" << endl;
    show_menu();
    int choice;
    cout << "Выберите действие:" << endl;
    cin >> choice;
    while (choice >= 1 || choice <= 5) {
        if (choice == 1) {    //Добавление дел
            ofstream file("List.txt", ofstream::app);
            if (!file.is_open()) {
                cerr << "Файл не открыт!" << endl;
                exit(EXIT_FAILURE);
            }
            bool flag = true;
            while (flag) {
                add_list(file);    //Добавление дел в файл:
                flag = add_another_case(flag);
            }
            choice = show_menu_in_while(choice);
        }
        else if (choice == 2) {    //Удаление дел
            bool flag = true;
            while (flag) {
                int n_count = 0;
                string* all_list_ptr = all_list(n_count);
                for (int i = 0; i < n_count; i++)
                    cout << "[" << i + 1 << "] - " << all_list_ptr[i] << endl;
                cout << "Выберте номер дела для удаления:" << endl;
                int n_choice = 0;
                cin >> n_choice;
                if (!cin) {
                    while (!(cin >> n_choice)) {
                        cin.clear();
                        while (cin.get() != '\n')
                            cout << "Некорректный выбор!\nПовторите попытку:" << endl;
                    }
                }
                else if (n_choice < 1 || n_choice > n_count) {
                    while (n_choice < 1 || n_choice > n_count) {
                        cout << "Некорректный выбор!\nПовторите попытку:" << endl;
                        cin >> n_choice;
                    }
                }
                remove_one_list(all_list_ptr, n_choice, n_count);
                flag = delete_another_case(flag);
            }
            choice = show_menu_in_while(choice);
        }
        else if (choice == 3) {  //Редактирование дел
            system("cls");
            bool flag = true;
            while (flag) {
                int n_count = 0;
                string* all_list_ptr = all_list(n_count);
                for (int i = 0; i < n_count; i++)
                    cout << "[" << i + 1 << "] - " << all_list_ptr[i] << endl;
                cout << "Выберте номер дела для редактирования:" << endl;
                int n_choice = 0;
                cin >> n_choice;
                editing_one_list(all_list_ptr, n_choice, n_count);
                flag = editing_another_case(flag);
            }
            choice = show_menu_in_while(choice);
        }
        else if (choice == 4) {//Поиск дел
            int choice_find;
            choice_find = show_menu_find_in_while(choice_find);
            find_list(choice_find);
            choice = show_menu_in_while(choice);
        }
        else if (choice == 5) {    //Отображение дел
            int n_count = 0;
            string* all_list_ptr = all_list(n_count);
            cout << "Ваши дела:" << endl;
            for (int i = 0; i < n_count; i++)
                cout << "[" << i + 1 << "] - " << all_list_ptr[i] << endl;
            cout << "\nДля выхода в главное меню нажмите любую клавишу." << endl;
            system("pause>0");
            choice = show_menu_in_while(choice);
        }
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
    }
    exit(NULL);
    system("pause");
    return 0;
}