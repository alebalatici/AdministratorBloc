#ifndef ADMINISTRATORBLOC_NOTIFICATION_LIST_WINDOW_H
#define ADMINISTRATORBLOC_NOTIFICATION_LIST_WINDOW_H
#include <QDialog>
#include <QGroupBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QObject>
#include "../observer/observer.h"
#include "../service/service_locatari.h"
#include "gui_initializer.h"
#include "models/my_list.h"

class NotificationListWindow : public QDialog, public Observer {
    friend class GuiInitializer;
    Q_OBJECT
private:
    ServiceLocatari& srv;

    QTableWidget *notification_list_table{};

    QLineEdit* edit_apartament_adaugare = new QLineEdit;
    QLineEdit* edit_apartament_adaugare_random = new QLineEdit;
    QLineEdit* edit_export_filename = new QLineEdit;

    QPushButton* button_add_locatar = new QPushButton("Adauga locatar");
    QPushButton* button_empty_list = new QPushButton("Goleste lista de notificari");
    QPushButton* button_add_locatari_random = new QPushButton("Adauga locatari random");
    QPushButton* button_export = new QPushButton("Export lista de notificari");

    MyListModel* model_notificari = nullptr;
    QListView* lista_notificari = nullptr;

    void initialize_components();
    void connect_signals_slots();
    void reload_table_data(const vector<Locatar>& notificari);
    void reload_list_data(const vector<Locatar>& notificari);

public:
    NotificationListWindow(ServiceLocatari& _srv, QWidget* parent = nullptr) :   QDialog{parent}, srv{_srv}
    {
        lista_notificari = new QListView(this);
        model_notificari = new MyListModel(srv.list_get_all_notificari());
        lista_notificari->setModel(model_notificari);

        initialize_components();
        connect_signals_slots();
        srv.add_observer(this);
        reload_list_data(srv.list_get_all_notificari());
    }

    ~NotificationListWindow() override
    {
        srv.remove_observer(this);
    }

    void add_locatar_gui();
    void empty_list_gui();
    void add_random_notificari_gui();
    void export_to_html_gui();
    void update() override;
};

#endif //ADMINISTRATORBLOC_NOTIFICATION_LIST_WINDOW_H
