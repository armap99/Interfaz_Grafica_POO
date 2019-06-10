#ifndef OPCIONESALDEANOS_H
#define OPCIONESALDEANOS_H

#include <QMainWindow>
#include <QMessageBox>
#include "tablaaldeanos.h"
#include "civilizacion.h"
#include "opcionesbarcos.h"

namespace Ui {
class OpcionesAldeanos;
}

class OpcionesAldeanos : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpcionesAldeanos(QWidget *parent = nullptr);
    ~OpcionesAldeanos();




    Civilizacion getCivilizacion() const;
    void setCivilizacion(const Civilizacion &value);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::OpcionesAldeanos *ui;
    TablaAldeanos TablaAldeanos;
    Civilizacion civilizacion;
    OpcionesBarcos MenuBarcos;
};

#endif // OPCIONESALDEANOS_H
