#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

QElapsedTimer stopwatch;
QElapsedTimer stopwatchLightsOut;
QList<QFrame*> lightList;
int counter = 0;
bool lightsFullyOff = false;

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
    QMessageBox sda;
    if(lightsFullyOff)
    {
        qint64 elapsed = stopwatch.nsecsElapsed();
        double elapsedD = (double)elapsed / 1000000000;
        sda.setText("Reaction Time: " + QString::number(elapsedD, 'f', 6) + " seconds");
        sda.exec();
        lightsFullyOff = false;
    }
    else
    {
        timer1s->stop();
        counter = 0;
        sda.setText("Jumpstart!");
        sda.exec();
    }
}

void MainWindow::timerUpdate()
{
    if(counter < 5)
    {
        lightList[counter]->setStyleSheet(LIGHT_ON);
    }
    counter++;
    if(counter == 6)
    {
        counter = 0;
        quint32 v = QRandomGenerator::global()->bounded(2000); //Random miliseconds for lights out
        QTimer::singleShot(v, this, SLOT(lightsOut()));
        timer1s->stop();
    }
    qDebug() << QString::number(counter);
}

void MainWindow::lightsOut()
{
    lightsFullyOff = true;
    for (int i = 0; i < lightList.count(); i++)
    {
        lightList[i]->setStyleSheet(LIGHT_OFF);
    }
    stopwatch.start();
}
