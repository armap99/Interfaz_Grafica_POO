#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    aux = 0;
    connect(ui->actionAbrir,SIGNAL(triggered()),this,SLOT(Abrir()));
    connect(ui->actionGuardar,SIGNAL(triggered()),this,SLOT(Guardar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//usuario
{
    qDebug() << "Registrando jugador";
    QString usuario = ui->lineEdit->text();
    ui->lineEdit->clear();
    qDebug() << usuario;
    videogame.setUsuario(usuario.toStdString());
}

void MainWindow::on_pushButton_2_clicked()//boton agregar
{
    //unsigned int i(0);
    qDebug() << "Agreagando aldea...";
    QString nombre = ui->lineEdit_2->text();
    int ubicacionx = ui->spinBox->value();
    int ubicaciony = ui->spinBox_2->value();
    if(ubicacionx < 0 or ubicaciony < 0){
        QMessageBox::information(this,"Error","Ubicacion invalida");
    }
    Civilizacion a;
    a.setNombre(nombre.toStdString());
    a.setUbicacionX(ubicacionx);
    a.setUbicacionY(ubicaciony);
//    while(i <= videogame.size()){
//        if(a == videogame[i]){
//            QMessageBox::information(this,"Error","Ubicacion invalida");

//        }
//        i++;
//    }
    videogame.Agregar(a);
    ui->lineEdit_2->clear();
    ui->spinBox->clear();
    ui->spinBox_2->clear();

}

void MainWindow::on_pushButton_3_clicked()//inicializa
{
    qDebug() << "Agreagando aldeas...";
    QString nombre = ui->lineEdit_2->text();
    int ubicacionx = ui->spinBox->value();
    int ubicaciony = ui->spinBox_2->value();
    int n = ui->spinBox_3->value();
    if(ubicacionx < 0 or ubicaciony < 0){
        QMessageBox::information(this,"Error","Ubicacion invalida");
    }
    Civilizacion a;
    a.setNombre(nombre.toStdString());
    a.setUbicacionX(ubicacionx);
    a.setUbicacionY(ubicaciony);
    //validacion de uvicacion iguales aqui qu procede,
    videogame.Inicializa(n,a);
    ui->lineEdit_2->clear();
    ui->spinBox->clear();
    ui->spinBox_2->clear();
    ui->spinBox_3->clear();
}

void MainWindow::on_pushButton_4_clicked()//incertar
{
    qDebug() << "Agreagando aldeas...";
    QString nombre = ui->lineEdit_2->text();
    int ubicacionx = ui->spinBox->value();
    int ubicaciony = ui->spinBox_2->value();
    int n = ui->spinBox_3->value();
    if(ubicacionx < 0 or ubicaciony < 0){
        QMessageBox::information(this,"Error","Ubicacion invalida");
    }
    Civilizacion a;
    a.setNombre(nombre.toStdString());
    a.setUbicacionX(ubicacionx);
    a.setUbicacionY(ubicaciony);
    //validacion de uvicacion iguales aqui qu procede,
    if(n >= videogame.size()){
        QMessageBox::information(this,"Error","Posicion invalida de lista");
    }
    else{
        videogame.Insertar(a,n);
        ui->lineEdit_2->clear();
        ui->spinBox->clear();
        ui->spinBox_2->clear();
        ui->spinBox_3->clear();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    qDebug() << "Mostrar";
    ui->textEdit->clear();
    if(videogame.size() == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        std::string nombre = videogame.primera().getNombre();
        size_t x = videogame.primera().getUbicacionX();
        size_t y = videogame.primera().getUbicacionY();
        QString nombre_s = QString::fromStdString(nombre);
        QString x_s = QString::number(x);
        QString y_s = QString::number(y);
        ui->textEdit->insertPlainText("Civilizacion: " + nombre_s + "\n");
        ui->textEdit->insertPlainText("Ubicacion x: " + x_s + "\n");
        ui->textEdit->insertPlainText("Ubicacion y: " + y_s + "\n");
        ui->textEdit->insertPlainText("\n");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    qDebug() << "Mostrar";
    ui->textEdit->clear();
    if(videogame.size() == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        std::string nombre = videogame.ultima().getNombre();
        size_t x = videogame.ultima().getUbicacionX();
        size_t y = videogame.ultima().getUbicacionY();
        QString nombre_s = QString::fromStdString(nombre);
        QString x_s = QString::number(x);
        QString y_s = QString::number(y);
        ui->textEdit->insertPlainText("Civilizacion: " + nombre_s + "\n");
        ui->textEdit->insertPlainText("Ubicacion x: " + x_s + "\n");
        ui->textEdit->insertPlainText("Ubicacion y: " + y_s + "\n");
        ui->textEdit->insertPlainText("\n");
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    qDebug() << "Mostrar";
    ui->textEdit_2->clear();
    if(videogame.size() == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        videogame.Ordenar();
        for(size_t i = 0; i < videogame.size(); i++){
            std::string nombre = videogame[i].getNombre();
            size_t x = videogame[i].getUbicacionX();
            size_t y = videogame[i].getUbicacionY();
            QString nombre_s = QString::fromStdString(nombre);
            QString x_s = QString::number(x);
            QString y_s = QString::number(y);
            ui->textEdit_2->insertPlainText("Civilizacion: " + nombre_s + "\n");
            ui->textEdit_2->insertPlainText("Ubicacion x: " + x_s + "\n");
            ui->textEdit_2->insertPlainText("Ubicacion y: " + y_s + "\n");
            ui->textEdit_2->insertPlainText("\n");
        }
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    qDebug() << "Eliminar";
    if(videogame.size() == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    QString  nombre =ui->lineEdit_3->text();
    videogame.EliminarN(nombre.toStdString());
    ui->lineEdit_3->clear();
}


void MainWindow::on_pushButton_9_clicked()
{
    qDebug() << "Resumen";
    ui->textEdit_3->clear();
    ui->textEdit_2->clear();
    if(videogame.size() == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        std::string usuario = videogame.getUsuario();
        QString usuario_s = QString::fromStdString(usuario);
        ui->textEdit_3->insertPlainText("Usuario: " + usuario_s + "\n" + "\n");
        for(size_t i = 0; i < videogame.size(); i++){
            std::string nombre = videogame[i].getNombre();
            size_t x = videogame[i].getUbicacionX();
            size_t y = videogame[i].getUbicacionY();
            QString nombre_s = QString::fromStdString(nombre);
            QString x_s = QString::number(x);
            QString y_s = QString::number(y);
            ui->textEdit_3->insertPlainText("Civilizacion: " + nombre_s + "\n");
            ui->textEdit_3->insertPlainText("Ubicacion x: " + x_s + "\n");
            ui->textEdit_3->insertPlainText("Ubicacion y: " + y_s + "\n");
            ui->textEdit_3->insertPlainText("\n");
        }
    }
}

void MainWindow::on_pushButton_10_clicked()//mostrar
{
    int cont=1;
    qDebug() << "Modificacion";
    ui->spinBox_4->clear();
    ui->textEdit_4->clear();
    if(videogame.size() == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        for(size_t i = 0; i < videogame.size(); i++){
            std::string nombre = videogame[i].getNombre();
            size_t x = videogame[i].getUbicacionX();
            size_t y = videogame[i].getUbicacionY();
            QString nombre_s = QString::fromStdString(nombre);
            QString x_s = QString::number(x);
            QString y_s = QString::number(y);
            QString cont_s = QString::number(cont);
            ui->textEdit_4->insertPlainText(cont_s+") "+"Civilizacion: " + nombre_s + "\n");
            ui->textEdit_4->insertPlainText("Ubicacion x: " + x_s + "\n");
            ui->textEdit_4->insertPlainText("Ubicacion y: " + y_s + "\n");
            ui->textEdit_4->insertPlainText("\n");
            cont++;
        }
    }
}

void MainWindow::on_pushButton_11_clicked()//modificar
{
    int nAldea = ui->spinBox_4->value();
    int cont;
    for(size_t i = 0; i < videogame.size(); i++){
        cont++;
    }
    if(cont == 0){
        QMessageBox::information(this,"Error","Vacia");
    }
    else{
        if(nAldea > cont){
            QMessageBox::information(this,"Error","Aldea invalida");
        }
        else{
            Civilizacion &c = videogame[(nAldea-1)];
            MenuAldea.setCivilizacion(c);
            MenuAldea.show();
            aux = nAldea;
        }
    }
    ui->spinBox_4->clear();
}

void MainWindow::on_pushButton_12_clicked()
{
    videogame.EliminarN(MenuAldea.getCivilizacion().getNombre());
    videogame.Insertar(MenuAldea.getCivilizacion(),aux-1);
    aux = 0;
    MenuAldea.close();
}

void MainWindow::Abrir()
{
    qDebug() << "Abrir prro";

    QString ubicacion = QFileDialog::getOpenFileName(this,"Abrir Archivo","C:/","TXT (*.txt)");

    qDebug() << ubicacion;
    videogame.recuperar(ubicacion.toStdString());
}

void MainWindow::Guardar()
{
    QString ubicacion = QFileDialog::getSaveFileName(this,"Guardar Archivo","C:/","Archivo txt (*.txt)");
    qDebug() << ubicacion;
    videogame.respaldar(ubicacion.toStdString(),videogame.Aldeas);
}
