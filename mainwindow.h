#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QObject>

#include "mainmenu.h"
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_play_clicked();
    void on_goToMenu_clicked();

private:
    Ui::MainWindow *ui;
    QVBoxLayout* layout;

    MainMenu* mainMenu;
    Game* gameFrame;
};
#endif // MAINWINDOW_H
