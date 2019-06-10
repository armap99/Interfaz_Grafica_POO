#ifndef TABLAALDEANOS_H
#define TABLAALDEANOS_H

#include <QMainWindow>
#include "civilizacion.h"
namespace Ui {
class TablaAldeanos;
}

class TablaAldeanos : public QMainWindow
{
    Q_OBJECT

public:
    explicit TablaAldeanos(QWidget *parent = nullptr);
    ~TablaAldeanos();
    void setAldea(Civilizacion &civilizacion);
    void setBarcos(Civilizacion &civilizacion);

private:
    Ui::TablaAldeanos *ui;
};

#endif // TABLAALDEANOS_H
