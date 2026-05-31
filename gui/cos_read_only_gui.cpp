#include "cos_read_only_gui.h"

void NotificationListReadOnlyGui::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter p{this};
    //cercurile/liniile sa se vada netede, nu pixelate
    p.setRenderHint(QPainter::Antialiasing);

    //deseneaza o diagonala pe ecran
    p.setPen(QPen(Qt::gray, 1, Qt::DashLine));
    p.drawLine(0, 0, width(), height());

    size_t nr_elems = srv.list_get_all_notificari().size();

    //coordonate aleatorii in interiorul ferestrei
    std::random_device rd;
    std::mt19937 gen(rd());

    //marja de 40 pixeli ca sa nu desenze in afara marginilor ferestrei
    std::uniform_int_distribution<> distX(20, width() - 40);
    std::uniform_int_distribution<> distY(20, height() - 40);

    //atatea figuri cate elemente sunt in cos
    for (size_t i = 0; i < nr_elems; i++)
    {
        int x = distX(gen);
        int y = distY(gen);

        p.setBrush(QBrush(QColor{"#FF1493"}));
        p.setPen(QPen(Qt::white, 2, Qt::DashLine));
        p.drawEllipse(x, y, 25, 25); //cerc diametru = 25
    }
}

void NotificationListReadOnlyGui::update()
{
    this->repaint();
}