#ifndef GAME_H
#define GAME_H

#include <QWidget>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

signals:
    void goToMenu();

public slots:
    void on_gameButtons_clicked();

private slots:
    void on_pushButton_menu_clicked();
    void on_pushButton_restrart_clicked();

private:
    void setGameButtonsConnection();
    void checkWinner();

private:
    Ui::Game *ui;
    unsigned short counter;
    bool check;
};

#endif // GAME_H
