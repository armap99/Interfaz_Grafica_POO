#include "tablaaldeanos.h"
#include "ui_tablaaldeanos.h"

TablaAldeanos::TablaAldeanos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TablaAldeanos)
{
    ui->setupUi(this);



}

TablaAldeanos::~TablaAldeanos()
{
    delete ui;
}

void TablaAldeanos::setAldea(Civilizacion &civilizacion)
{
    ui->tableWidget->setColumnCount(4);//cuantas columnas
    QStringList headers;
    headers << "Nombre" << "Edad" << "Genero" << "Salud";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    int i = 0;
    ui->tableWidget->setRowCount(civilizacion.size());//columnas que se necesitan
    for (auto it = civilizacion.habitantes.begin(); it != civilizacion.habitantes.end(); ++it) {
        Aldeanos &j = *it;
        std::string nombre = j.getNombre();
        int edad = j.getEdad();
        std::string genero = j.getGenero();
        int salud = j.getSalud();

        QString nombre_q = QString::fromStdString(nombre);
        QString edad_q = QString::number(edad);
        QString genero_q = QString::fromStdString(genero);
        QString salud_q = QString::number(salud);

        QTableWidgetItem *nombreItem = new QTableWidgetItem(nombre_q);
        QTableWidgetItem *edadItem = new QTableWidgetItem(edad_q);
        QTableWidgetItem *generoItem = new QTableWidgetItem(genero_q);
        QTableWidgetItem *saludItem = new QTableWidgetItem(salud_q);

        ui->tableWidget->setItem(i,0,nombreItem);
        ui->tableWidget->setItem(i,1,edadItem);
        ui->tableWidget->setItem(i,2,generoItem);
        ui->tableWidget->setItem(i,3,saludItem);
        i++;
    }
}

void TablaAldeanos::setBarcos(Civilizacion &civilizacion)
{
    ui->tableWidget->setColumnCount(5);//cuantas columnas
    QStringList headers;
    headers << "Id" << "Combustible" << "Velocidad" << "Armadura" << "Gerreros Abordo";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    int i = 0;
    ui->tableWidget->setRowCount(civilizacion.BarcosEnPuerto());//columnas que se necesitan
    for (auto it = civilizacion.puerto.begin(); it != civilizacion.puerto.end(); ++it) {
        Barco &j = **it;
        int id = j.getIdb();
        int combustible = j.getCombustible();
        int velocidad = j.getVelocidad();
        int armadura = j.getArmadura();
        int cant = j.CantTrip();

        QString id_q = QString::number(id);
        QString combustible_q = QString::number(combustible);
        QString velocidad_q = QString::number(velocidad);
        QString armadura_q = QString::number(armadura);
        QString cant_q = QString::number(cant);

        QTableWidgetItem *idItem = new QTableWidgetItem(id_q);
        QTableWidgetItem *combustibleItem = new QTableWidgetItem(combustible_q);
        QTableWidgetItem *velocidadItem = new QTableWidgetItem(velocidad_q);
        QTableWidgetItem *armaduraItem = new QTableWidgetItem(armadura_q);
        QTableWidgetItem *cantItem = new QTableWidgetItem(cant_q);

        ui->tableWidget->setItem(i,0,idItem);
        ui->tableWidget->setItem(i,1,combustibleItem);
        ui->tableWidget->setItem(i,2,velocidadItem);
        ui->tableWidget->setItem(i,3,armaduraItem);
        ui->tableWidget->setItem(i,4,cantItem);
        i++;
    }
}
