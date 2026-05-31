#ifndef ADMINISTRATORBLOC_GUI_H
#define ADMINISTRATORBLOC_GUI_H

#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QGroupBox>
#include <QTabWidget>
#include <QRadioButton>
#include <QTableView>
#include "../service/service_locatari.h"
#include "notification_list_window.h"
#include "cos_read_only_gui.h"
#include "gui_initializer.h"
#include "../observer/observer.h"
#include "models/my_list.h"
#include "models/my_table.h"
using std::vector;
using std::string;
class GraphicalInterface : public QWidget, public Observer {
    Q_OBJECT
    friend class GuiInitializer;
private:
    ServiceLocatari& srv;

    QVBoxLayout* layout_butoane_dinamice;

    MyTableModel* my_table_locatari;

    QLabel* label_apartament_adaugare = new QLabel{"Numarul apartamentului:"};
    QLabel* label_nume_adaugare = new QLabel{"Numele locatarului:"};
    QLabel* label_suprafata_adaugare = new QLabel{"Suprafata apartamentului:"};
    QLabel* label_tip_adaugare = new QLabel{"Tipul apartamentului:"};

    QLabel* label_apartament_stergere = new QLabel{"Numarul apartamentului:"};

    QLabel* label_apartament_modificare = new QLabel{"Numarul apartamentului:"};
    QLabel* label_nume_modificare = new QLabel{"Numele locatarului:"};
    QLabel* label_suprafata_modificare = new QLabel{"Suprafata apartamentului:"};
    QLabel* label_tip_modificare = new QLabel{"Tipul apartamentului:"};

    QLabel* label_filter_criteria_tip = new QLabel(tr("Tipul dupa care se filtreaza:"));
    QLabel* label_filter_criteria_suprafata = new QLabel(tr("Suprafata minima dupa care se filtreaza:"));

    QLabel* label_apartament_cautare = new QLabel{"Numarul apartamentului:"};

    QLabel* label_undo = new QLabel(tr("Undo"));


    QLineEdit* edit_apartament_adaugare;
    QLineEdit* edit_nume_adaugare;
    QLineEdit* edit_suprafata_adaugare;
    QLineEdit* edit_tip_adaugare;

    QLineEdit* edit_apartament_stergere;

    QLineEdit* edit_apartament_modificare;
    QLineEdit* edit_nume_modificare;
    QLineEdit* edit_suprafata_modificare;
    QLineEdit* edit_tip_modificare;

    QLineEdit* edit_filtrare_tip;
    QLineEdit* edit_filtrare_suprafata;

    QLineEdit* edit_apartament_cautare;

    QLineEdit* edit_notification_list_adaugare = new QLineEdit;
    QLineEdit* edit_notification_list_adaugare_random = new QLineEdit;
    QLineEdit* edit_notification_list_export_filename = new QLineEdit;

    QPushButton* button_add_locatar;
    QPushButton* button_delete_locatar;
    QPushButton* button_sort_locatari;
    QPushButton* button_filter_locatari_tip;
    QPushButton* button_filter_locatari_suprafata;
    QPushButton* button_reload_data;
    QPushButton* button_modify_locatari;
    QPushButton* button_undo;
    QPushButton* button_find_locatar;
    QPushButton* button_notification_list_window;
    QPushButton* button_cos_read_only_window;

    QPushButton* button_notification_list_add_locatar = new QPushButton("Adauga locatar");
    QPushButton* button_notification_list_empty_list = new QPushButton("Goleste lista de notificari");
    QPushButton* button_notification_list_add_locatari_random = new QPushButton("Adauga locatari random");
    QPushButton* button_notification_list_export = new QPushButton("Export lista de notificari");

    QGroupBox* group_box_sortare = new QGroupBox(tr("Sortare"));
    QGroupBox* group_box_filtrare = new QGroupBox(tr("Filtrare"));
    QGroupBox* group_box_adaugare = new QGroupBox(tr("Adaugare"));
    QGroupBox* group_box_stergere = new QGroupBox(tr("Stergere"));
    QGroupBox* group_box_modificare = new QGroupBox(tr("Modificare"));
    QGroupBox* group_box_cautare = new QGroupBox(tr("Cautare"));
    QGroupBox* group_box_lista_notificari = new QGroupBox(tr("Lista de Notificari"));
    QGroupBox* group_box_dictionar = new QGroupBox(tr("Contor Tip Locatari"));

    QRadioButton* radio_sortare_nume = new QRadioButton(QString::fromStdString(std::string("Sortare dupa nume")));
    QRadioButton* radio_sortare_suprafata = new QRadioButton(QString::fromStdString(std::string("Sortare dupa suprafata")));
    QRadioButton* radio_sortare_tip_suprafata = new QRadioButton(QString::fromStdString(std::string("Sortare dupa tip si suprafata")));

    QTableWidget* table_modificare;
    QTableWidget* table_filtrare;

 //   QListWidget* lista_locuinte = new QListWidget;

    QListView* lista_notificari = nullptr;
    MyListModel* model_notificari = nullptr;

    QTabWidget* tab_widget = new QTabWidget;

    void initialize_gui_components();
    void connect_signals_slots();
    void reload_data_table(const vector<Locatar>& locatari, QTableWidget* table);
    void reload_my_table(const vector<Locatar>& locatari, MyTableModel* table);
    void reload_data_list(const vector<Locatar>& locatari);
    static int get_row_table(int id, QTableWidget* table);
    template<typename WindowType>
    void open_window(const string& title)
    {
        auto* dialog = new WindowType(srv);
        dialog->setStyleSheet(this->styleSheet());
        dialog->setWindowTitle(QString::fromStdString(title));
        dialog->resize(500, 450);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
    }
    void set_style();

    void set_buttons_visibility();
public:
    GraphicalInterface(ServiceLocatari& _srv) : srv { _srv }
    {
        this->setWindowTitle("Administrator Bloc");
        srv.initialize_dictionar();

        lista_notificari = new QListView(this);
        model_notificari = new MyListModel(srv.list_get_all_notificari());
        lista_notificari->setModel(model_notificari);

        initialize_gui_components();
        connect_signals_slots();
        srv.add_observer(this);

        reload_data_table(srv.get_all_locatari(), table_modificare);
        reload_data_table(srv.get_all_locatari(), table_filtrare);
    }

    ~GraphicalInterface() override
    {
        srv.remove_observer(this);
    }

    void add_locatari_gui();
    void delete_locatari_gui();
    void sort_locatari_gui();
    void filter_locatari_tip_gui();
    void filter_locatari_suprafata_gui();
    void modify_locatari_gui();
    void find_locatari_gui();
    void undo_gui();
    void update() override;
};

#endif //ADMINISTRATORBLOC_GUI_H