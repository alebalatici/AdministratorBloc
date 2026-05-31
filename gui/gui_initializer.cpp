//
// Created by Alexandra on 5/22/2026.
//

#include "gui_initializer.h"
#include "gui.h"
#include "models/my_table.h"
#include <cassert>
void GuiInitializer::initialize_form_adaugare(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QVBoxLayout* layout_box = new QVBoxLayout;
    gui->group_box_adaugare->setLayout(layout_box);
    QFormLayout* layout_form = new QFormLayout;

    gui->edit_apartament_adaugare = new QLineEdit;
    gui->edit_nume_adaugare = new QLineEdit;
    gui->edit_suprafata_adaugare = new QLineEdit;
    gui->edit_tip_adaugare = new QLineEdit;

    layout_form->addRow(gui->label_apartament_adaugare, gui->edit_apartament_adaugare);
    layout_form->addRow(gui->label_nume_adaugare, gui->edit_nume_adaugare);
    layout_form->addRow(gui->label_suprafata_adaugare, gui->edit_suprafata_adaugare);
    layout_form->addRow(gui->label_tip_adaugare, gui->edit_tip_adaugare);

    gui->button_add_locatar = new QPushButton("Adauga apartament");
    layout_form->addRow(gui->button_add_locatar);
    layout_box->addLayout(layout_form);
    layout->addWidget(gui->group_box_adaugare);
}

void GuiInitializer::initialize_form_modificare(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QVBoxLayout* layout_box = new QVBoxLayout;
    gui->group_box_modificare->setLayout(layout_box);
    QFormLayout* layout_form = new QFormLayout;

    gui->edit_apartament_modificare = new QLineEdit;
    gui->edit_nume_modificare = new QLineEdit;
    gui->edit_suprafata_modificare = new QLineEdit;
    gui->edit_tip_modificare = new QLineEdit;

    layout_form->addRow(gui->label_apartament_modificare, gui->edit_apartament_modificare);
    layout_form->addRow(gui->label_nume_modificare, gui->edit_nume_modificare);
    layout_form->addRow(gui->label_suprafata_modificare, gui->edit_suprafata_modificare);
    layout_form->addRow(gui->label_tip_modificare, gui->edit_tip_modificare);

    gui->button_modify_locatari = new QPushButton("Modificare locatari");
    layout_form->addRow(gui->button_modify_locatari);
    layout_box->addLayout(layout_form);
    layout->addWidget(gui->group_box_modificare);
}


void GuiInitializer::initialize_form_stergere(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QVBoxLayout* layout_box = new QVBoxLayout;
    gui->group_box_stergere->setLayout(layout_box);
    QFormLayout* layout_form = new QFormLayout;
    gui->edit_apartament_stergere = new QLineEdit;

    layout_form->addRow(gui->label_apartament_stergere, gui->edit_apartament_stergere);
    gui->button_delete_locatar = new QPushButton("Sterge locatar");

    layout_form->addRow(gui->button_delete_locatar);
    layout_box->addLayout(layout_form);
    layout->addWidget(gui->group_box_stergere);
}

void GuiInitializer::initialize_form_cautare(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QVBoxLayout* layout_box = new QVBoxLayout;
    gui->group_box_cautare->setLayout(layout_box);
    QFormLayout* layout_form = new QFormLayout;
    gui->edit_apartament_cautare = new QLineEdit;

    layout_form->addRow(gui->label_apartament_cautare, gui->edit_apartament_cautare);
    gui->button_find_locatar = new QPushButton("Cauta locatar");

    layout_form->addRow(gui->button_find_locatar);
    layout_box->addLayout(layout_form);
    layout->addWidget(gui->group_box_cautare);
}

void GuiInitializer::initialize_form_lista_notificari(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QVBoxLayout* layout_box = new QVBoxLayout;
    gui->group_box_lista_notificari->setLayout(layout_box);

    gui->button_notification_list_window = new QPushButton("Deschide lista de notificari");
    layout_box->addWidget(gui->button_notification_list_window);

    layout->addWidget(gui->group_box_lista_notificari);
}

void GuiInitializer::initialize_form_read_only_window(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QGroupBox* read_only = new QGroupBox("Figuri Geometrice");
    QVBoxLayout* layout_read_only = new QVBoxLayout;
    read_only->setLayout(layout_read_only);

    gui->button_cos_read_only_window = new QPushButton("Deschide Lista de Notificari Read-Only");
    layout_read_only->addWidget(gui->button_cos_read_only_window);

    layout->addWidget(read_only);
}

void GuiInitializer::initialize_form_sortare(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QVBoxLayout* layout_radio_box = new QVBoxLayout;
    gui->group_box_sortare->setLayout(layout_radio_box);
    layout_radio_box->addWidget(gui->radio_sortare_nume);
    layout_radio_box->addWidget(gui->radio_sortare_suprafata);
    layout_radio_box->addWidget(gui->radio_sortare_tip_suprafata);

    gui->button_sort_locatari = new QPushButton("Sorteaza locatari");
    layout_radio_box->addWidget(gui->button_sort_locatari);

    layout->addWidget(gui->group_box_sortare);
}

void GuiInitializer::initialize_form_filtrare(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QVBoxLayout* layout_box = new QVBoxLayout;
    gui->group_box_filtrare->setLayout(layout_box);

    QFormLayout* layout_form = new QFormLayout;
    gui->edit_filtrare_tip = new QLineEdit;
    layout_form->addRow(gui->label_filter_criteria_tip, gui->edit_filtrare_tip);

    gui->edit_filtrare_suprafata = new QLineEdit;
    layout_form->addRow(gui->label_filter_criteria_suprafata, gui->edit_filtrare_suprafata);

    layout_box->addLayout(layout_form);
    gui->button_filter_locatari_tip = new QPushButton("Filtreaza locatari dupa tip");
    gui->button_filter_locatari_suprafata = new QPushButton("Filtreaza locatari dupa suprafata");
    layout_box->addWidget(gui->button_filter_locatari_tip);
    layout_box->addWidget(gui->button_filter_locatari_suprafata);
    layout->addWidget(gui->group_box_filtrare);
}

void GuiInitializer::initialize_form_contor_tip(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QVBoxLayout* layout_box = new QVBoxLayout;
    gui->group_box_dictionar->setLayout(layout_box);

    gui->layout_butoane_dinamice = new QVBoxLayout;
    layout_box->addLayout(gui->layout_butoane_dinamice);

    layout->addWidget(gui->group_box_dictionar);
    gui->set_buttons_visibility();
}

void GuiInitializer::initialize_table(QVBoxLayout* layout, QTableWidget*& table)
{
    int nr_lines = 15;
    int nr_columns = 4;
    table = new QTableWidget{ nr_lines, nr_columns };

    QStringList table_header_list;
    table_header_list << "Apartament" << "Nume" << "Suprafata" << "Tip";
    table->setHorizontalHeaderLabels(table_header_list);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    layout->addWidget(table);
}

void GuiInitializer::initialize_form_undo(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QWidget* form = new QWidget;
    QFormLayout* layout_form = new QFormLayout;
    form->setLayout(layout_form);
    gui->button_undo = new QPushButton("Undo");
    layout_form->addRow(gui->button_undo);
    layout->addWidget(form);
}

void GuiInitializer::initialize_form_reload(QVBoxLayout* layout)
{
    assert(gui != nullptr);

    QWidget* form = new QWidget;
    QFormLayout* layout_form = new QFormLayout;
    form->setLayout(layout_form);
    gui->button_reload_data = new QPushButton("Reload data");
    layout_form->addRow(gui->button_reload_data);
    layout->addWidget(form);
}

void GuiInitializer::initialize_notification_list_form_adaugare(QVBoxLayout *layout, QLineEdit*& edit_apartament, QPushButton*& button_add_locatar)
{
    QVBoxLayout* layout_box = new QVBoxLayout;
    QGroupBox* group_box_adaugare = new QGroupBox("Adaugare");
    group_box_adaugare->setLayout(layout_box);
    QFormLayout* layout_form = new QFormLayout;
    layout_form->addRow(new QLabel("Numarul apartamentului:"), edit_apartament);
    layout_form->addRow(button_add_locatar);
    layout_box->addLayout(layout_form);
    layout->addWidget(group_box_adaugare);
}

void GuiInitializer::initialize_notification_list_form_empty(QVBoxLayout *layout, QPushButton*& button_empty_list)
{
    QVBoxLayout* layout_box = new QVBoxLayout;
    QGroupBox* group_box_golire = new QGroupBox("Golire Lista");
    group_box_golire->setLayout(layout_box);
    QFormLayout* layout_form = new QFormLayout;
    layout_form->addRow(button_empty_list);
    layout_box->addLayout(layout_form);
    layout->addWidget(group_box_golire);
}

void GuiInitializer::initialize_notification_list_form_adaugare_random(QVBoxLayout *layout, QLineEdit*& edit_number, QPushButton*& button_add_locatar_random)
{
    QVBoxLayout* layout_box = new QVBoxLayout;
    QGroupBox* group_box_adaugare_random = new QGroupBox("Adaugare Random");
    group_box_adaugare_random->setLayout(layout_box);
    QFormLayout* layout_form = new QFormLayout;
    layout_form->addRow(new QLabel("Numarul de locatari care sa fie generati:"), edit_number);
    layout_form->addRow(button_add_locatar_random);
    layout_box->addLayout(layout_form);
    layout->addWidget(group_box_adaugare_random);
}

void GuiInitializer::initialize_notification_list_form_export(QVBoxLayout *layout, QLineEdit*& edit_filename, QPushButton*& button_export)
{
    QVBoxLayout* layout_box = new QVBoxLayout;
    QGroupBox* group_box_export = new QGroupBox("Export");
    group_box_export->setLayout(layout_box);
    QFormLayout* layout_form = new QFormLayout;
    layout_form->addRow(new QLabel("Numele fisierului pentru export:"), edit_filename);
    layout_form->addRow(button_export);
    layout_box->addLayout(layout_form);
    layout->addWidget(group_box_export);
}

void GuiInitializer::initialize_notification_list_list(QVBoxLayout* layout, QListView*& list)
{
    QVBoxLayout* layout_box = new QVBoxLayout;
    QGroupBox* group_box_list = new QGroupBox("Lista de notificari");
    group_box_list->setLayout(layout_box);
    list->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout_box->addWidget(list);
    layout->addWidget(group_box_list);
}

void GuiInitializer::initialize_my_table(QVBoxLayout* layout, QTableView* table)
{
    table = new QTableView();
    layout->addWidget(table);
}