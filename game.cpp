#include "game.h"
#include "ui_game.h"

#include <QDebug>
#include <QMessageBox>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    setGameButtonsConnection();
    counter = 0;
    check = false;
}

Game::~Game()
{
    delete ui;
}

void Game::on_pushButton_menu_clicked()
{
    emit goToMenu();
}

void Game::on_gameButtons_clicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if(!clickedButton->text().isEmpty())
        return;
    else if(check)
        return;

    if(counter % 2 == 0)
        clickedButton->setText("X");
    else
        clickedButton->setText("O");

    if(counter >= 4)
        checkWinner();

     counter++;
}

void Game::setGameButtonsConnection()
{
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &Game::on_gameButtons_clicked);
    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, &Game::on_gameButtons_clicked);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, this, &Game::on_gameButtons_clicked);
    QObject::connect(ui->pushButton_4, &QPushButton::clicked, this, &Game::on_gameButtons_clicked);
    QObject::connect(ui->pushButton_5, &QPushButton::clicked, this, &Game::on_gameButtons_clicked);
    QObject::connect(ui->pushButton_6, &QPushButton::clicked, this, &Game::on_gameButtons_clicked);
    QObject::connect(ui->pushButton_7, &QPushButton::clicked, this, &Game::on_gameButtons_clicked);
    QObject::connect(ui->pushButton_8, &QPushButton::clicked, this, &Game::on_gameButtons_clicked);
    QObject::connect(ui->pushButton_9, &QPushButton::clicked, this, &Game::on_gameButtons_clicked);
}

void Game::checkWinner()
{
    QString winner = "";

    if (ui->pushButton->text()  == "X" && ui->pushButton_2->text() == "X" && ui->pushButton_3->text() == "X" )
    {
        winner = "X";
        check = true;
    }
    else if (ui->pushButton_4->text()  == "X" && ui->pushButton_5->text() == "X" && ui->pushButton_6->text() == "X" )
    {
        winner = "X";
        check = true;
    }
    else if (ui->pushButton_7->text()  == "X" && ui->pushButton_8->text() == "X" && ui->pushButton_9->text() == "X" )
    {
        winner = "X";
        check = true;
    }
    else if (ui->pushButton->text()  == "X" && ui->pushButton_4->text() == "X" && ui->pushButton_7->text() == "X" )
    {
        winner = "X";
        check = true;
    }
    else if (ui->pushButton_2->text()  == "X" && ui->pushButton_5->text() == "X" && ui->pushButton_8->text() == "X" )
    {
        winner = "X";
        check = true;
    }
    else if (ui->pushButton_3->text()  == "X" && ui->pushButton_6->text() == "X" && ui->pushButton_9->text() == "X" )
    {
        winner = "X";
        check = true;
    }
    else if (ui->pushButton->text()  == "X" && ui->pushButton_5->text() == "X" && ui->pushButton_9->text() == "X" )
    {
        winner = "X";
        check = true;
    }
    else if (ui->pushButton_3->text()  == "X" && ui->pushButton_5->text() == "X" && ui->pushButton_7->text() == "X" )
    {
        winner = "X";
        check = true;
    }
    else if (ui->pushButton->text()  == "O" && ui->pushButton_2->text() == "O" && ui->pushButton_3->text() == "O" )
    {
        winner = "O";
        check = true;
    }
    else if (ui->pushButton_4->text()  == "O" && ui->pushButton_5->text() == "O" && ui->pushButton_6->text() == "O" )
    {
        winner = "O";
        check = true;
    }
    else if (ui->pushButton_7->text()  == "O" && ui->pushButton_8->text() == "O" && ui->pushButton_9->text() == "O" )
    {
        winner = "O";
        check = true;
    }
    else if (ui->pushButton->text()  == "O" && ui->pushButton_4->text() == "O" && ui->pushButton_7->text() == "O" )
    {
        winner = "O";
        check = true;
    }
    else if (ui->pushButton_2->text()  == "O" && ui->pushButton_5->text() == "O" && ui->pushButton_8->text() == "O" )
    {
        winner = "O";
        check = true;
    }
    else if (ui->pushButton_3->text()  == "O" && ui->pushButton_6->text() == "O" && ui->pushButton_9->text() == "O" )
    {
        winner = "O";
        check = true;
    }
    else if (ui->pushButton->text()  == "O" && ui->pushButton_5->text() == "O" && ui->pushButton_9->text() == "O" )
    {
        winner = "O";
        check = true;
    }
    else if (ui->pushButton_3->text()  == "O" && ui->pushButton_5->text() == "O" && ui->pushButton_7->text() == "O" )
    {
        winner = "O";
        check = true;
    }

    if(check)
        QMessageBox::information(nullptr, "Game Info", "Game Over! Winner is: " + winner);
    else if(!check && counter == 8)
        QMessageBox::information(nullptr, "Game Info", "Game Ended In a Draw!");
}

void Game::on_pushButton_restrart_clicked()
{
    ui->pushButton->setText("");
    counter = 0;
    check = false;

    ui->pushButton_2->setText("");
    counter = 0;
    check = false;

    ui->pushButton_3->setText("");
    counter = 0;
    check = false;

    ui->pushButton_4->setText("");
    counter = 0;
    check = false;

    ui->pushButton_5->setText("");
    counter = 0;
    check = false;

    ui->pushButton_6->setText("");
    counter = 0;
    check = false;

    ui->pushButton_7->setText("");
    counter = 0;
    check = false;

    ui->pushButton_8->setText("");
    counter = 0;
    check = false;

    ui->pushButton_9->setText("");
    counter = 0;
    check = false;



}
