#include "gui.h"

void GraphicalInterface::set_buttons_visibility()
{
    if (srv.get_undo_count() == 0)
        button_undo->setVisible(false);
    else
        button_undo->setVisible(true);

    QLayoutItem* child;
    while ((child = layout_butoane_dinamice->takeAt(0)) != nullptr)
    {
        if (child->widget())
            delete child->widget();
        delete child;
    }

    auto dictionar = srv.get_all_dictionar();
    for (auto const& [tip, count]: dictionar)
    {
        if (count > 0)
        {
            QString text_button = QString::fromStdString("Contor " + tip);
            QPushButton* button = new QPushButton(text_button);

            QObject::connect(button, &QPushButton::clicked, this, [this, tip, count]()
            {
                QString mesaj = "Sunt in total " + QString::number(count) + " locuinte de tip " + QString::fromStdString(tip);
                QMessageBox::information(this, "Info", mesaj);
            });
            layout_butoane_dinamice->addWidget(button);
        }
    }
}

void GraphicalInterface::initialize_gui_components()
{
    QHBoxLayout* layout_main = new QHBoxLayout;
    setLayout(layout_main);

    QGroupBox* tab_modificare = new QGroupBox("Date Locatari");
    QHBoxLayout* layout_modificare = new QHBoxLayout;
    tab_modificare->setLayout(layout_modificare);

    QWidget* left_modificare = new QWidget;
    QVBoxLayout* left_layout_modificare = new QVBoxLayout;
    left_modificare->setLayout(left_layout_modificare);

    GuiInitializer initializer(this);

    initializer.initialize_form_adaugare(left_layout_modificare);
    initializer.initialize_form_stergere(left_layout_modificare);
    initializer.initialize_form_modificare(left_layout_modificare);
    initializer.initialize_form_cautare(left_layout_modificare);

    QWidget* right_modificare = new QWidget;
    QVBoxLayout* right_layout_modificare = new QVBoxLayout;
    right_modificare->setLayout(right_layout_modificare);

    initializer.initialize_table(right_layout_modificare, table_modificare);
    initializer.initialize_form_undo(right_layout_modificare);
    initializer.initialize_form_reload(right_layout_modificare);
    initializer.initialize_form_contor_tip(right_layout_modificare);

    layout_modificare->addWidget(left_modificare);
    layout_modificare->addWidget(right_modificare);

    QGroupBox* tab_filtrare = new QGroupBox("Filtrare si Statistici");
    QHBoxLayout* layout_filtrare = new QHBoxLayout;
    tab_filtrare->setLayout(layout_filtrare);

    QWidget* left_filtrare = new QWidget;
    QVBoxLayout* left_layout_filtrare = new QVBoxLayout;
    left_filtrare->setLayout(left_layout_filtrare);

    initializer.initialize_form_sortare(left_layout_filtrare);
    initializer.initialize_form_filtrare(left_layout_filtrare);

    QWidget* right_filtrare = new QWidget;
    QVBoxLayout* right_layout_filtrare = new QVBoxLayout;
    right_filtrare->setLayout(right_layout_filtrare);

    initializer.initialize_table(right_layout_filtrare, table_filtrare);

    layout_filtrare->addWidget(left_filtrare);
    layout_filtrare->addWidget(right_filtrare);

    QGroupBox* tab_lista_notificari = new QGroupBox("Lista de notificari");
    QHBoxLayout* layout_lista_notificari = new QHBoxLayout;
    tab_lista_notificari->setLayout(layout_lista_notificari);

    QWidget* left_lista_notificari = new QWidget;
    QVBoxLayout* left_layout_lista_notificari = new QVBoxLayout;
    left_lista_notificari->setLayout(left_layout_lista_notificari);

    initializer.initialize_notification_list_form_adaugare(left_layout_lista_notificari, edit_notification_list_adaugare, button_notification_list_add_locatar);
    initializer.initialize_notification_list_form_empty(left_layout_lista_notificari, button_notification_list_empty_list);
    initializer.initialize_notification_list_form_adaugare_random(left_layout_lista_notificari, edit_notification_list_adaugare_random, button_notification_list_add_locatari_random);
    initializer.initialize_notification_list_form_export(left_layout_lista_notificari, edit_notification_list_export_filename, button_notification_list_export);

    QWidget* right_lista_notificari = new QWidget;
    QVBoxLayout* right_layout_lista_notificari = new QVBoxLayout;
    right_lista_notificari->setLayout(right_layout_lista_notificari);

    initializer.initialize_notification_list_list(right_layout_lista_notificari, lista_notificari);
    initializer.initialize_form_lista_notificari(right_layout_lista_notificari);
    initializer.initialize_form_read_only_window(right_layout_lista_notificari);

    layout_lista_notificari->addWidget(left_lista_notificari);
    layout_lista_notificari->addWidget(right_lista_notificari);

    tab_widget->addTab(tab_modificare, "Modificare Date Locatari");
    tab_widget->addTab(tab_filtrare, "Sortare si Filtrare");
    tab_widget->addTab(tab_lista_notificari, "Lista de notificari");

    layout_main->addWidget(tab_widget);
    set_style();
}

void GraphicalInterface::connect_signals_slots()
{
    QObject::connect(button_add_locatar, &QPushButton::clicked, this, &GraphicalInterface::add_locatari_gui);
    QObject::connect(button_delete_locatar, &QPushButton::clicked, this, &GraphicalInterface::delete_locatari_gui);
    QObject::connect(button_sort_locatari, &QPushButton::clicked, this, &GraphicalInterface::sort_locatari_gui);
    QObject::connect(button_filter_locatari_tip, &QPushButton::clicked, this, &GraphicalInterface::filter_locatari_tip_gui);
    QObject::connect(button_filter_locatari_suprafata, &QPushButton::clicked, this, &GraphicalInterface::filter_locatari_suprafata_gui);
    QObject::connect(button_modify_locatari, &QPushButton::clicked, this, &GraphicalInterface::modify_locatari_gui);
    QObject::connect(button_undo, &QPushButton::clicked, this, &GraphicalInterface::undo_gui);
    QObject::connect(button_find_locatar, &QPushButton::clicked, this, &GraphicalInterface::find_locatari_gui);
    QObject::connect(button_notification_list_window, &QPushButton::clicked, this, [this]()
    {
        open_window<NotificationListWindow>("Lista de Notificari");
    });
    QObject::connect(button_cos_read_only_window, &QPushButton::clicked, this, [this]()
    {
        open_window<NotificationListReadOnlyGui>("Lista de Notificari Read Only");
    });
    QObject::connect(button_reload_data, &QPushButton::clicked, [&]()
    {
       this->reload_data_table(srv.get_all_locatari(), table_modificare);
    });
    QObject::connect(button_notification_list_add_locatar, &QPushButton::clicked, this, [this]()
    {
        try
        {
            int apartament = edit_notification_list_adaugare->text().toInt();
            edit_notification_list_adaugare->clear();

            this->srv.list_add_notificare(apartament);
            this->reload_data_list(this->srv.list_get_all_notificari());
            QMessageBox::information(this, "Info", QString::fromStdString("Locatar adaugat cu succes in lista de notificari."));
        }

        catch (ServiceException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
        }
    });
    QObject::connect(button_notification_list_empty_list, &QPushButton::clicked, this, [this]()
    {
        try
        {
            this->srv.list_empty_full();
            this->reload_data_list(this->srv.list_get_all_notificari());
        }

        catch (ServiceException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
        }
    });
    QObject::connect(button_notification_list_add_locatari_random, &QPushButton::clicked, this, [this]()
    {
        try
        {
            int number = edit_notification_list_adaugare_random->text().toInt();
            edit_notification_list_adaugare_random->clear();

            this->srv.list_add_random_notificari(number);
            this->reload_data_list(this->srv.list_get_all_notificari());
            QMessageBox::information(this, "Info", QString::fromStdString("Locatari adaugati cu succes."));
        }

        catch (ServiceException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
        }
    });
    QObject::connect(button_notification_list_export, &QPushButton::clicked, this, [this]()
    {
        try
        {
            string filename = edit_notification_list_export_filename->text().toStdString();
            edit_notification_list_export_filename->clear();

            srv.list_export_to_html(filename);

            QMessageBox::information(this, "Info", QString::fromStdString("Lista de notificari a fost exportata cu succes."));
        }

        catch (ServiceException& e)
        {
            QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
        }
    });
}

void GraphicalInterface::reload_data_table(const vector<Locatar>& locatari, QTableWidget* table)
{
    table->clearContents();
    table->setRowCount(int(locatari.size()));

    int line_number = 0;
    for (auto& locatar : locatari)
    {
        table->setItem(line_number, 0, new QTableWidgetItem(QString::number(locatar.get_apartment())));
        table->setItem(line_number, 1, new QTableWidgetItem(QString::fromStdString(locatar.get_nume())));
        table->setItem(line_number, 2, new QTableWidgetItem(QString::number(locatar.get_suprafata())));
        table->setItem(line_number, 3, new QTableWidgetItem(QString::fromStdString(locatar.get_tip())));
        line_number++;
    }
    srv.initialize_dictionar();
    set_buttons_visibility();
}

void GraphicalInterface::reload_data_list(const vector<Locatar>& locatari)
{
    model_notificari->setLocatari(locatari);
}

void GraphicalInterface::add_locatari_gui()
{
    try
    {
        int apartament = edit_apartament_adaugare->text().toInt();
        string nume = edit_nume_adaugare->text().toStdString();
        double suprafata = edit_suprafata_adaugare->text().toDouble();
        string tip = edit_tip_adaugare->text().toStdString();

        edit_apartament_adaugare->clear();
        edit_nume_adaugare->clear();
        edit_suprafata_adaugare->clear();
        edit_tip_adaugare->clear();

        this->srv.add_locatar(apartament, nume, suprafata, tip);
        this->reload_data_table(this->srv.get_all_locatari(), table_modificare);
        this->reload_data_table(this->srv.get_all_locatari(), table_filtrare);

        int row = table_modificare->rowCount() - 1;
        table_modificare->selectRow(row);
        table_modificare->scrollToItem(table_modificare->item(row, 0));

        QMessageBox::information(this, "Info", QString::fromStdString("Locatar adaugat cu succes."));
    }

    catch(ServiceException& e)
    {
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
    }
}

void GraphicalInterface::undo_gui()
{
    try
    {
        string undo_type = srv.print_last_undo_operation();
        srv.undo();
        this->reload_data_table(this->srv.get_all_locatari(), table_modificare);
        this->reload_data_table(this->srv.get_all_locatari(), table_filtrare);
        QMessageBox::information(this, "Info", QString::fromStdString(undo_type) + " efectuat cu succes.");
    }

    catch(ServiceException& e)
    {
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
    }
}

void GraphicalInterface::modify_locatari_gui()
{
    try
    {
        int apartament = edit_apartament_modificare->text().toInt();
        string nume = edit_nume_modificare->text().toStdString();
        double suprafata = edit_suprafata_modificare->text().toDouble();
        string tip = edit_tip_modificare->text().toStdString();

        edit_apartament_modificare->clear();
        edit_nume_modificare->clear();
        edit_suprafata_modificare->clear();
        edit_tip_modificare->clear();

        this->srv.modify_locatar(apartament, nume, suprafata, tip);
        this->reload_data_table(this->srv.get_all_locatari(), table_modificare);
        this->reload_data_table(this->srv.get_all_locatari(), table_filtrare);

        Locatar& l = srv.find_locatar(apartament);
        int row = get_row_table(l.get_apartment(), table_modificare);
        if (row != -1)
        {
            table_modificare->selectRow(row);
            table_modificare->scrollToItem(table_modificare->item(row, 0));
        }

        QMessageBox::information(this, "Info", QString::fromStdString("Locatar modificat cu succes."));
    }

    catch(ServiceException& e)
    {
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
    }
}

void GraphicalInterface::delete_locatari_gui()
{
    try
    {
        int apartament = edit_apartament_stergere->text().toInt();
        edit_apartament_stergere->clear();
        this->srv.delete_locatar(apartament);
        this->reload_data_table(this->srv.get_all_locatari(), table_modificare);
        this->reload_data_table(this->srv.get_all_locatari(), table_filtrare);

        QMessageBox::information(this, "Info", QString::fromStdString("Locatar sters cu succes."));
    }
    catch(ServiceException& e)
    {
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
    }
}

int GraphicalInterface::get_row_table(int id, QTableWidget* table)
{
    for (int i = 0; i < table->rowCount(); i++)
    {
        int current_id = table->item(i, 0)->text().toInt();
        if (current_id == id)
            return i;
    }
    return -1;
}

void GraphicalInterface::find_locatari_gui()
{
    try
    {
        int apartament = edit_apartament_cautare->text().toInt();
        edit_apartament_cautare->clear();
        Locatar l = srv.find_locatar(apartament);

        std::ostringstream oss;
        oss << l;
        QString mesaj = "Locatarul cu numarul apartamentului " + QString::number(apartament) + " este:\n" + QString::fromStdString(oss.str());
        int row = get_row_table(l.get_apartment(), table_modificare);
        if (row != -1)
        {
            table_modificare->selectRow(row);
            table_modificare->scrollToItem(table_modificare->item(row, 0));
        }

        QMessageBox::information(this, "Info", mesaj);
    }
    catch(ServiceException& e)
    {
        QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
    }
}

void GraphicalInterface::sort_locatari_gui()
{
    if (this->radio_sortare_nume->isChecked())
        this->reload_data_table(ServiceLocatari::sort_after_name(srv.get_all_locatari()), table_filtrare);
    else if (this->radio_sortare_suprafata->isChecked())
        this->reload_data_table(ServiceLocatari::sort_after_surface(srv.get_all_locatari()), table_filtrare);
    else if (this->radio_sortare_tip_suprafata->isChecked())
        this->reload_data_table(ServiceLocatari::sort_after_type_and_surface(srv.get_all_locatari()), table_filtrare);
}

void GraphicalInterface::filter_locatari_tip_gui()
{
    string filterC = this->edit_filtrare_tip->text().toStdString();
    this->reload_data_table(ServiceLocatari::filter_after_type(srv.get_all_locatari(), filterC), table_filtrare);
}

void GraphicalInterface::filter_locatari_suprafata_gui()
{
    int filterC = this->edit_filtrare_suprafata->text().toInt();
    this->reload_data_table(ServiceLocatari::filter_after_surface(srv.get_all_locatari(), filterC), table_filtrare);
}

void GraphicalInterface::update()
{
    this->reload_data_table(srv.get_all_locatari(), table_modificare);
    this->reload_data_table(srv.get_all_locatari(), table_filtrare);
    this->model_notificari->setLocatari(srv.list_get_all_notificari());
}

void GraphicalInterface::set_style()
{
    this->setStyleSheet(R"(
        QWidget {
            background-color: #121212;
            font-family: 'Segoe UI', Arial, sans-serif;
            font-size: 10pt;
            color: #E0E0E0;
        }


        QTabWidget::pane {
            border: 2px solid #FF1493;
            background-color: #1E1E1E;
            border-radius: 8px;
            top: -2px;
            padding: 12px;
        }
        QTabBar::tab {
            background-color: #252525;
            border: 2px solid #333333;
            border-bottom-color: none;
            border-top-left-radius: 6px;
            border-top-right-radius: 6px;
            padding: 10px 20px;
            color: #A0A0A0;
            font-weight: bold;
            margin-right: 4px;
        }
        QTabBar::tab:hover {
            background-color: #FF69B4;
            color: #000000;
            border-color: #FF69B4;
        }

        QTabBar::tab:selected {
            background-color: #FF1493;
            color: #000000;
            border-color: #FF1493;
        }


        QGroupBox {
            background-color: #1A1A1A;
            border: 2px solid #FF69B4;
            border-radius: 8px;
            margin-top: 16px;
            font-weight: bold;
            color: #FFFFFF;
            padding: 12px;
        }
        QGroupBox::title {
            subcontrol-origin: margin;
            subcontrol-position: top-center;
            padding: 2px 14px;
            background-color: #FF1493;
            color: #000000;
            border-radius: 4px;
            font-weight: bold;
        }


        QLineEdit {
            padding: 6px;
            border: 1px solid #555555;
            border-radius: 6px;
            background-color: #2D2D2D;
            color: #FFFFFF;
        }
        QLineEdit:focus {
            border: 2px solid #FF1493;
            background-color: #333333;
        }


        QPushButton {
            background-color: #FF1493;
            color: #000000;
            border: none;
            border-radius: 6px;
            padding: 8px 16px;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #FF69B4;
        }
        QPushButton:pressed {
            background-color: #C71585;
        }


        QTableWidget {
            background-color: #121212;
            color: white;
            gridline-color: #2a1b24;
            border: 1px solid #FF1493;
            font-size: 13px;
        }
        QHeaderView::section {
            background-color: #1a1a1a;
            color: #FF1493;
            padding: 5px;
            border: 1px solid #2a1b24;
            font-weight: bold;
        }
        QTableWidget::item:selected {
            background-color: #FF1493;
            color: white;
        }
        QTableWidget::item:hover {
            background-color: #2a1b24;
            color: #FF1493;
        }


        QRadioButton {
            spacing: 8px;
            color: #E0E0E0;
            padding: 4px 0;
        }
        QRadioButton::indicator {
            width: 14px;
            height: 14px;
            border-radius: 7px;
            border: 2px solid #FF69B4;
            background: #2D2D2D;
        }
        QRadioButton::indicator:checked {
            background-color: #FF1493;
            border: 2px solid #1A1A1A;
        }


        QListView {
            background-color: #121212;
            color: white;
            border: 1px solid #FF1493;
            padding: 5px;
        }
        QListView::item:selected {
            background-color: #FF1493;
            color: white;
            border: none;
        }
        QListView::item:hover {
            background-color: #2a1b24;
            color: #FF1493;
        }
    )");
}