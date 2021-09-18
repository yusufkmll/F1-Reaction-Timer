#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

QElapsedTimer stopwatch;
QList<QFrame*> lightList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer1s = new QTimer(this);
    connect(timer1s, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    lightList << ui->light_1 << ui->light_2 << ui->light_3 << ui->light_4 << ui->light_5;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_pushButton_clicked()
//{

//    MessageBox basic
//    QMessageBox sda;
//    sda.setText("DENEMEEEE");
//    sda.setInformativeText("Do you want to save your changes?");
//    sda.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
//    sda.setDefaultButton(QMessageBox::Save);
//    int rep = sda.exec();

//    Hazır MessageBox ve DateTime
//    int rep = QMessageBox::warning(this, tr("EMIN MISIN?"),
//                                   tr("The document has been modified.\n"
//                                      "Do you want to save your changes?"),
//                                   QMessageBox::Save | QMessageBox::Discard
//                                   | QMessageBox::Cancel,
//                                   QMessageBox::Save);
//    QDateTime qday = QDateTime::currentDateTime();
//    if(rep == QMessageBox::Save)
//    {
//        QMessageBox boox;
//        boox.setText(qday.toString("dd.MM.yyyy"));
//        boox.exec();
//    }
//

//}

void MainWindow::on_button_clicked()
{
    timer1s->start(1000);
}

void MainWindow::on_pushButton_2_clicked()
{
    qint64 elapsed = stopwatch.nsecsElapsed();
    double elapsedD = (double)elapsed / 1000000000;
    QMessageBox sda;
    sda.setText("Fark: " + QString::number(elapsedD, 'f', 6) + " saniye");
    sda.exec();
}

int counter = 0;
void MainWindow::timerUpdate()
{
    lightList[counter]->setStyleSheet(LIGHT_ON);
    counter++;
    if(counter == 5)
    {
        counter = 0;
        stopwatch.start();
    }
    qDebug() << QString::number(counter);
}
