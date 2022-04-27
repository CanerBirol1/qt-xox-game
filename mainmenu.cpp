#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->frame_2->setVisible(false);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_clicked()
{
    emit emitPlaySignal();
}

void MainMenu::on_Button_botgame_toggled(bool checked)
{
    if(checked)
        ui->frame_2->setVisible(true);
    else
        ui->frame_2->setVisible(false);
}
