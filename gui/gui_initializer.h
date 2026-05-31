//
// Created by Alexandra on 5/22/2026.
//

#ifndef ADMINISTRATORBLOC_GUI_INITIALIZER_H
#define ADMINISTRATORBLOC_GUI_INITIALIZER_H
#include <vector>
#include <QWidget>
#include <QtWidgets>
using std::vector;
class GraphicalInterface;
class NotificationListWindow;
class MyTableModel;
class GuiInitializer {
private:
    GraphicalInterface* gui = nullptr;
    NotificationListWindow* ntw = nullptr;
public:
    GuiInitializer(GraphicalInterface* _gui) : gui { _gui }, ntw { nullptr } {}
    GuiInitializer(NotificationListWindow* _ntw) : gui { nullptr }, ntw { _ntw } {}

    void initialize_form_adaugare(QVBoxLayout* layout);
    void initialize_form_stergere(QVBoxLayout* layout);
    void initialize_form_sortare(QVBoxLayout* layout);
    void initialize_form_filtrare(QVBoxLayout* layout);
    void initialize_form_modificare(QVBoxLayout* layout);
    void initialize_form_undo(QVBoxLayout* layout);
    void initialize_form_reload(QVBoxLayout* layout);
    void initialize_form_cautare(QVBoxLayout* layout);
    void initialize_form_contor_tip(QVBoxLayout* layout);
    void initialize_form_lista_notificari(QVBoxLayout* layout);
    static void initialize_table(QVBoxLayout* layout, QTableWidget*& table);
    void initialize_form_read_only_window(QVBoxLayout* layout);
    static void initialize_notification_list_form_export(QVBoxLayout *layout, QLineEdit*& edit_filename, QPushButton*& button_export);
    static void initialize_notification_list_form_adaugare(QVBoxLayout *layout, QLineEdit*& edit_apartament, QPushButton*& button_add_locatar);
    static void initialize_notification_list_list(QVBoxLayout *layout, QListView*& list);
    static void initialize_notification_list_form_empty(QVBoxLayout *layout, QPushButton*& button_empty_list);
    static void initialize_notification_list_form_adaugare_random(QVBoxLayout *layout, QLineEdit*& edit_number, QPushButton*& button_add_locatar_random);
    static void initialize_my_table(QVBoxLayout* layout, QTableView* table);
};

#endif //ADMINISTRATORBLOC_GUI_INITIALIZER_H
