#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>
#include <QDateTime>
#include <QElapsedTimer>
#include <QList>
#include <QRandomGenerator>

#define LIGHT_ON "image: url(:/resources/resources/light_on.png)"
#define LIGHT_OFF "image: url(:/resources/resources/light_off.png)"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_button_clicked();

    void timerUpdate();

    void lightsOut();

private:
    Ui::MainWindow *ui;
    QTimer  *timer1s;

};
#endif // MAINWINDOW_H
