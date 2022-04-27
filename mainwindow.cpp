#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    layout = new QVBoxLayout();
    mainMenu = new MainMenu(this);
    layout->addWidget(mainMenu);
    ui->centralwidget->setLayout(layout);

    QObject::connect(mainMenu, &MainMenu::emitPlaySignal, this, &MainWindow::on_play_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainMenu;
    mainMenu = nullptr;
    delete gameFrame;
    gameFrame = nullptr;
}

void MainWindow::on_play_clicked()
{
    delete mainMenu;
    mainMenu = nullptr;

    gameFrame = new Game(this);
    layout->addWidget(gameFrame);
    ui->centralwidget->setLayout(layout);

    QObject::connect(gameFrame, &Game::goToMenu, this, &MainWindow::on_goToMenu_clicked);
}

void MainWindow::on_goToMenu_clicked()
{
    delete gameFrame;
    gameFrame = nullptr;

    mainMenu = new MainMenu(this);
    layout->addWidget(mainMenu);
    ui->centralwidget->setLayout(layout);

    QObject::connect(mainMenu, &MainMenu::emitPlaySignal, this, &MainWindow::on_play_clicked);
}

