#ifndef ADMINISTRATORBLOC_NOTIFICATION_LIST_READ_ONLY_H
#define ADMINISTRATORBLOC_NOTIFICATION_LIST_READ_ONLY_H

#include <QDialog>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <random>
#include "../observer/observer.h"
#include "../service/service_locatari.h"
#include "../observer/observer.h"

class NotificationListReadOnlyGui : public QDialog, public Observer {
    Q_OBJECT
private:
    ServiceLocatari& srv;
protected:
    void paintEvent(QPaintEvent* event) override;
public:
    NotificationListReadOnlyGui(ServiceLocatari& _srv, QWidget* parent = nullptr) : QDialog{parent}, srv{_srv}
    {
        this->setWindowTitle("Forme Geometrice Lista Notificari");
        srv.add_observer(this);
    }

    void update() override;

    ~NotificationListReadOnlyGui() override
    {
        srv.remove_observer(this);
    }
};

#endif //ADMINISTRATORBLOC_NOTIFICATION_LIST_READ_ONLY_H
