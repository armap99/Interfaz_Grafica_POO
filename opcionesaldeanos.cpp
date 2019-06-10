#include "opcionesaldeanos.h"
#include "ui_opcionesaldeanos.h"
#include <QPixmap>


OpcionesAldeanos::OpcionesAldeanos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OpcionesAldeanos)
{
    ui->setupUi(this);
    QImage imagen("pug.jpg");
    ui->label_11->setPixmap(QPixmap::fromImage(imagen));
}

Civilizacion OpcionesAldeanos::getCivilizacion() const
{
    return civilizacion;
}

void OpcionesAldeanos::setCivilizacion(const Civilizacion &value)
{
    civilizacion = value;
}

OpcionesAldeanos::~OpcionesAldeanos()
{
    delete ui;
}

void OpcionesAldeanos::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
    std::string nombre = civilizacion.getNombre();
    QString nombre_s = QString::fromStdString(nombre);
    ui->plainTextEdit->insertPlainText(nombre_s);
}

void OpcionesAldeanos::on_pushButton_2_clicked()//agregar al inicio
{
    QString nombre = ui->lineEdit->text();
    int edad = ui->spinBox->value();
    QString genero = ui->lineEdit_2->text();
    int salud = ui->spinBox_2->value();
    Aldeanos Armando;
    Armando.setNombre(nombre.toStdString());
    Armando.setEdad(edad);
    Armando.setGenero(genero.toStdString());
    Armando.setSalud(salud);
    civilizacion.AgregarInicio(Armando);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->spinBox->clear();
    ui->spinBox_2->clear();

}

void OpcionesAldeanos::on_pushButton_3_clicked()//agregar al final
{
    QString nombre = ui->lineEdit->text();
    int edad = ui->spinBox->value();
    QString genero = ui->lineEdit_2->text();
    int salud = ui->spinBox_2->value();
    Aldeanos Armando;
    Armando.setNombre(nombre.toStdString());
    Armando.setEdad(edad);
    Armando.setGenero(genero.toStdString());
    Armando.setSalud(salud);
    civilizacion.AgregarFinal(Armando);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->spinBox->clear();
    ui->spinBox_2->clear();
}

void OpcionesAldeanos::on_pushButton_4_clicked()//eliminar po nombre
{
    QString nombre = ui->lineEdit_3->text();
    civilizacion.EliminarNombre(nombre.toStdString());
    ui->lineEdit_3->clear();
}

void OpcionesAldeanos::on_pushButton_5_clicked()//eliminar por salud
{
    int edad = ui->spinBox_3->value();
    civilizacion.EliminarSalud(edad);
    ui->spinBox_3->clear();
}

void OpcionesAldeanos::on_pushButton_6_clicked()//eliminar por edad mayor a 60
{
    civilizacion.EliminarEdad();
}

void OpcionesAldeanos::on_pushButton_7_clicked()//ordenar por nombre
{
    civilizacion.OrdenarNombre();
}

void OpcionesAldeanos::on_pushButton_8_clicked()//ordenar por edad
{
    civilizacion.OrdenarEdad();
}

void OpcionesAldeanos::on_pushButton_9_clicked()//ordenar por salud
{
    civilizacion.OrdenarSalud();
}

void OpcionesAldeanos::on_pushButton_10_clicked()//mostrar
{
    if(civilizacion.size() == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        TablaAldeanos.show();
        TablaAldeanos.setAldea(civilizacion);
    }
}


void OpcionesAldeanos::on_pushButton_11_clicked()//agragar barco
{
    int combustible = ui->spinBox_4->value();
    Barco Titanic;
    if(civilizacion.puerto.empty()){
       Titanic.setIdb(0);
    }
    else{
        Titanic.setIdb(civilizacion.puerto.back()->getIdb()+1);
    }
    Titanic.setCombustible(combustible);
    civilizacion.AgregarBarco(Titanic);
    ui->spinBox_4->setValue(1);
}

void OpcionesAldeanos::on_pushButton_12_clicked()//mostra tabla en ventana aparte :v
{
    if(civilizacion.BarcosEnPuerto()==0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else {
        TablaAldeanos.show();
        TablaAldeanos.setBarcos(civilizacion);
    }
}

void OpcionesAldeanos::on_pushButton_13_clicked()//mostrar ventana en la misma pantalla mayor practicidad
{
    if(civilizacion.BarcosEnPuerto()==0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else {
        ui->tableWidget->setColumnCount(5);//cuantas columnas
        QStringList headers;
        headers << "Id" << "Combustible" << "Velocidad" << "Armadura" << "Guerreros Abordo";
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        int i = 0;
        ui->tableWidget->setRowCount(civilizacion.BarcosEnPuerto());//columnas que se necesitan
        for (auto it = civilizacion.puerto.begin(); it != civilizacion.puerto.end(); ++it) {
            Barco &j = **it;
            int id = j.getIdb();
            int combustible = j.getCombustible();
            int velocidad = j.getVelocidad();
            int armadura = j.getArmadura();
            size_t cant = j.CantTrip();

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
}

void OpcionesAldeanos::on_pushButton_14_clicked()//buscar barco
{
    if(civilizacion.BarcosEnPuerto()==0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        int idBus = ui->spinBox_7->value();
        MenuBarcos.setTitanic(civilizacion.BuscarBarco(idBus));
        ui->spinBox_7->clear();
        MenuBarcos.show();
    }
}

void OpcionesAldeanos::on_pushButton_15_clicked()//Eliminar barco id
{
    int id = ui->spinBox_8->value();
    civilizacion.EliminarBarcoId(id);
    ui->spinBox_8->clear();
    ui->spinBox_9->clear();
}

void OpcionesAldeanos::on_pushButton_16_clicked()//Eliminar Barco por combustible
{
    int x = ui->spinBox_9->value();
    civilizacion.EliminarBarcoCantida(x);
    ui->spinBox_8->clear();
    ui->spinBox_9->clear();
}

void OpcionesAldeanos::on_pushButton_17_clicked()
{
    if(civilizacion.BarcosEnPuerto()==0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else {
        ui->tableWidget_2->setColumnCount(5);//cuantas columnas
        QStringList headers;
        headers << "Id" << "Combustible" << "Velocidad" << "Armadura" << "Guerreros Abordo";
        ui->tableWidget_2->setHorizontalHeaderLabels(headers);
        int i = 0;
        ui->tableWidget_2->setRowCount(civilizacion.BarcosEnPuerto());//columnas que se necesitan
        for (auto it = civilizacion.puerto.begin(); it != civilizacion.puerto.end(); ++it) {
            Barco &j = **it;
            int id = j.getIdb();
            int combustible = j.getCombustible();
            int velocidad = j.getVelocidad();
            int armadura = j.getArmadura();
            size_t cant = j.CantTrip();

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

            ui->tableWidget_2->setItem(i,0,idItem);
            ui->tableWidget_2->setItem(i,1,combustibleItem);
            ui->tableWidget_2->setItem(i,2,velocidadItem);
            ui->tableWidget_2->setItem(i,3,armaduraItem);
            ui->tableWidget_2->setItem(i,4,cantItem);
            i++;
        }
    }
}

void OpcionesAldeanos::on_pushButton_18_clicked()//mandar
{
    int id = ui->spinBox_11->value();
    int valocida = ui->spinBox_10->value();
    if(valocida == 0){
        QMessageBox::information(this,"Datos in.","Ingrese velocidad");
    }
    else{
        Barco* ubicacion= civilizacion.BuscarBarco(id);
        civilizacion.EliminarBarcoIdSBorrar(id);
        ubicacion->setVelocidad(valocida);
        civilizacion.AgregarBatalla(ubicacion);
        ui->tableWidget_2->clear();
    }
    ui->spinBox_11->clear();
    ui->spinBox_10->clear();
}



void OpcionesAldeanos::on_pushButton_20_clicked()//barcos en pelea
{
    if(civilizacion.batalla.empty()){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        ui->tableWidget_2->clear();
        ui->tableWidget_2->setColumnCount(5);//cuantas columnas
        QStringList headers;
        headers << "Id" << "Combustible" << "Velocidad" << "Armadura" << "Guerreros Abordo";
        ui->tableWidget_2->setHorizontalHeaderLabels(headers);
        int i = 0;
        ui->tableWidget_2->setRowCount(civilizacion.batalla.size());//columnas que se necesitan
        std::priority_queue <Barco*,std::vector<Barco*>,Barco::comparador> copia(civilizacion.batalla);
        //crear copia para pop y cambiar ciclo
        while(!copia.empty()) {
            Barco *j = copia.top();
            copia.pop();
            int id = j->getIdb();
            int combustible = j->getCombustible();
            int velocidad = j->getVelocidad();
            int armadura = j->getArmadura();
            size_t cant = j->CantTrip();

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

            ui->tableWidget_2->setItem(i,0,idItem);
            ui->tableWidget_2->setItem(i,1,combustibleItem);
            ui->tableWidget_2->setItem(i,2,velocidadItem);
            ui->tableWidget_2->setItem(i,3,armaduraItem);
            ui->tableWidget_2->setItem(i,4,cantItem);
            i++;
        }
    }
}

void OpcionesAldeanos::on_pushButton_21_clicked()//mostrar batalla
{
    if(civilizacion.batalla.empty()){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        ui->tableWidget_3->clear();
        ui->tableWidget_3->setColumnCount(5);//cuantas columnas
        QStringList headers;
        headers << "Id" << "Combustible" << "Velocidad" << "Armadura" << "Guerreros Abordo";
        ui->tableWidget_3->setHorizontalHeaderLabels(headers);
        int i = 0;
        ui->tableWidget_3->setRowCount(civilizacion.batalla.size());//columnas que se necesitan
        std::priority_queue <Barco*,std::vector<Barco*>,Barco::comparador> copia(civilizacion.batalla);
        //crear copia para pop y cambiar ciclo
        while(!copia.empty()) {
            Barco *j = copia.top();
            copia.pop();
            int id = j->getIdb();
            int combustible = j->getCombustible();
            int velocidad = j->getVelocidad();
            int armadura = j->getArmadura();
            size_t cant = j->CantTrip();

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

            ui->tableWidget_3->setItem(i,0,idItem);
            ui->tableWidget_3->setItem(i,1,combustibleItem);
            ui->tableWidget_3->setItem(i,2,velocidadItem);
            ui->tableWidget_3->setItem(i,3,armaduraItem);
            ui->tableWidget_3->setItem(i,4,cantItem);
            i++;
        }
    }
}

void OpcionesAldeanos::on_pushButton_22_clicked()//recuperar
{
    ui->tableWidget_3->clear();
    int combustible = ui->spinBox_6->value();
    int armadura= ui->spinBox_12->value();
    if(armadura == 0 or combustible ==0){
        Barco * Muerto = civilizacion.batalla.top();
        civilizacion.batalla.pop();
        delete Muerto;
        std::priority_queue <Barco*,std::vector<Barco*>,Barco::comparador> copia(civilizacion.batalla);
        while (!civilizacion.batalla.empty()) {
            civilizacion.batalla.pop();
            if(copia.top()->getArmadura()-10 < 1 or copia.top()->getCombustible()-15 < 1){
                Barco * Aux = copia.top();
                copia.pop();
                delete Aux;
            }
        }
        while (!copia.empty()) {
                Barco* aux = copia.top();
                copia.pop();
                aux->setArmadura(aux->getArmadura()-10);
                aux->setCombustible(aux->getCombustible()-15);
                civilizacion.AgregarBatalla(aux);
        }
    }
    else{
        Barco * Muerto = civilizacion.batalla.top();
        Muerto->setCombustible(combustible);
        Muerto->setArmadura(armadura);
        Muerto->setVelocidad(0);
        civilizacion.AgregarBarco(*Muerto);
        civilizacion.batalla.pop();
        std::priority_queue <Barco*,std::vector<Barco*>,Barco::comparador> copia(civilizacion.batalla);
        while (!civilizacion.batalla.empty()) {
            civilizacion.batalla.pop();
            if(copia.top()->getArmadura()-10 < 1 or copia.top()->getCombustible()-15 < 1){
                Barco * Aux = copia.top();
                copia.pop();
                delete Aux;
            }
        }
        while (!copia.empty()) {
                Barco* aux = copia.top();
                copia.pop();
                aux->setArmadura(aux->getArmadura()-10);
                aux->setCombustible(aux->getCombustible()-15);
                civilizacion.AgregarBatalla(aux);
        }
        //mostrar barcos en batalla
    }
}
