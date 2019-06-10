#ifndef OPCIONESBARCOS_H
#define OPCIONESBARCOS_H

#include <QMainWindow>
#include <QMessageBox>
#include "civilizacion.h"

namespace Ui {
class OpcionesBarcos;
}

class OpcionesBarcos : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpcionesBarcos(QWidget *parent = nullptr);
    ~OpcionesBarcos();

    Barco *getTitanic() const;
    void setTitanic(Barco *value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::OpcionesBarcos *ui;
    Barco *Titanic;
};

#endif // OPCIONESBARCOS_H
