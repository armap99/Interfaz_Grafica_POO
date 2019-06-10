#include "opcionesbarcos.h"
#include "ui_opcionesbarcos.h"

OpcionesBarcos::OpcionesBarcos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OpcionesBarcos)
{
    ui->setupUi(this);
}

OpcionesBarcos::~OpcionesBarcos()
{
    delete ui;
}

Barco *OpcionesBarcos::getTitanic() const
{
    return Titanic;
}

void OpcionesBarcos::setTitanic(Barco *value)
{
    Titanic = value;
}

void OpcionesBarcos::on_pushButton_clicked()
{
    QString nombre = QString::number(Titanic->getIdb());
    ui->plainTextEdit->insertPlainText(nombre);
}


void OpcionesBarcos::on_pushButton_2_clicked()
{
    Guerrero thor;
    thor.setId(Titanic->CantTrip());
    int salud = ui->spinBox->value();
    thor.setSalud(salud);
    int fuerza = ui->spinBox_2->value();
    thor.setFuerza(fuerza);
    int escudo = ui->spinBox_3->value();
    thor.setEscudo(escudo);
    int tipo = ui->spinBox_4->value();
    if(tipo == 1){
        thor.setTipo("Arquero");
    }
    else if (tipo == 2) {
        thor.setTipo("Lancero");
    }
    else if (tipo == 3) {
        thor.setTipo("Escudero");
    }
    else if (tipo == 4){
        thor.setTipo("Brujo");
    }
    Titanic->PushG(thor);
    ui->spinBox->clear();
    ui->spinBox_2->clear();
    ui->spinBox_3->clear();
    ui->spinBox_4->clear();
}

void OpcionesBarcos::on_pushButton_3_clicked()
{
    if(Titanic->CantTrip() == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        Titanic->PopG();
        ui->tableWidget->setColumnCount(5);//cuantas columnas
        QStringList headers;
        headers << "Id" << "Salud" << "Fuerza" << "Escudo" << "Tipo de Guerrero";
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        int i = 0;
        ui->tableWidget->setRowCount(Titanic->CantTrip());//columnas que se necesitan
        Barco copia = *Titanic;
        while (!copia.Tripulantes.empty()) {
            Guerrero j = copia.PopG();
            int id = j.getId();
            int salud = j.getSalud();
            int fuerza = j.getFuerza();
            int escudo = j.getEscudo();
            std::string tipo = j.getTipo();

            QString id_q = QString::number(id);
            QString salud_q = QString::number(salud);
            QString fuerza_q = QString::number(fuerza);
            QString escudo_q = QString::number(escudo);
            QString tipo_q = QString::fromStdString(tipo);

            QTableWidgetItem *idItem = new QTableWidgetItem(id_q);
            QTableWidgetItem *saludItem = new QTableWidgetItem(salud_q);
            QTableWidgetItem *fuerzaItem = new QTableWidgetItem(fuerza_q);
            QTableWidgetItem *escudoItem = new QTableWidgetItem(escudo_q);
            QTableWidgetItem *tipoItem = new QTableWidgetItem(tipo_q);

            ui->tableWidget->setItem(i,0,idItem);
            ui->tableWidget->setItem(i,1,saludItem);
            ui->tableWidget->setItem(i,2,fuerzaItem);
            ui->tableWidget->setItem(i,3,escudoItem);
            ui->tableWidget->setItem(i,4,tipoItem);
            i++;
        }
    }
}

void OpcionesBarcos::on_pushButton_4_clicked()
{
    if(Titanic->CantTrip() == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        ui->tableWidget_2->setColumnCount(5);//cuantas columnas
        QStringList headers;
        headers << "Id" << "Salud" << "Fuerza" << "Escudo" << "Tipo de Guerrero";
        ui->tableWidget_2->setHorizontalHeaderLabels(headers);
        int i = 0;
        ui->tableWidget_2->setRowCount(Titanic->CantTrip());//columnas que se necesitan
        Barco copia = *Titanic;
        while (!copia.Tripulantes.empty()) {
            Guerrero j = copia.PopG();
            int id = j.getId();
            int salud = j.getSalud();
            int fuerza = j.getFuerza();
            int escudo = j.getEscudo();
            std::string tipo = j.getTipo();

            QString id_q = QString::number(id);
            QString salud_q = QString::number(salud);
            QString fuerza_q = QString::number(fuerza);
            QString escudo_q = QString::number(escudo);
            QString tipo_q = QString::fromStdString(tipo);

            QTableWidgetItem *idItem = new QTableWidgetItem(id_q);
            QTableWidgetItem *saludItem = new QTableWidgetItem(salud_q);
            QTableWidgetItem *fuerzaItem = new QTableWidgetItem(fuerza_q);
            QTableWidgetItem *escudoItem = new QTableWidgetItem(escudo_q);
            QTableWidgetItem *tipoItem = new QTableWidgetItem(tipo_q);

            ui->tableWidget_2->setItem(i,0,idItem);
            ui->tableWidget_2->setItem(i,1,saludItem);
            ui->tableWidget_2->setItem(i,2,fuerzaItem);
            ui->tableWidget_2->setItem(i,3,escudoItem);
            ui->tableWidget_2->setItem(i,4,tipoItem);
            i++;
        }
    }
}

void OpcionesBarcos::on_pushButton_5_clicked()
{
    if(Titanic->CantTrip() == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        ui->tableWidget_2->setColumnCount(5);//cuantas columnas
        QStringList headers;
        headers << "Id" << "Salud" << "Fuerza" << "Escudo" << "Tipo de Guerrero";
        ui->tableWidget_2->setHorizontalHeaderLabels(headers);
        int i = 0;
        ui->tableWidget_2->setRowCount(1);//columnas que se necesitan
            Guerrero j = Titanic->TopG();
            int id = j.getId();
            int salud = j.getSalud();
            int fuerza = j.getFuerza();
            int escudo = j.getEscudo();
            std::string tipo = j.getTipo();

            QString id_q = QString::number(id);
            QString salud_q = QString::number(salud);
            QString fuerza_q = QString::number(fuerza);
            QString escudo_q = QString::number(escudo);
            QString tipo_q = QString::fromStdString(tipo);

            QTableWidgetItem *idItem = new QTableWidgetItem(id_q);
            QTableWidgetItem *saludItem = new QTableWidgetItem(salud_q);
            QTableWidgetItem *fuerzaItem = new QTableWidgetItem(fuerza_q);
            QTableWidgetItem *escudoItem = new QTableWidgetItem(escudo_q);
            QTableWidgetItem *tipoItem = new QTableWidgetItem(tipo_q);

            ui->tableWidget_2->setItem(i,0,idItem);
            ui->tableWidget_2->setItem(i,1,saludItem);
            ui->tableWidget_2->setItem(i,2,fuerzaItem);
            ui->tableWidget_2->setItem(i,3,escudoItem);
            ui->tableWidget_2->setItem(i,4,tipoItem);
    }
}
