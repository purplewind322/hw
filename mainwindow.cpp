#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

double firstNum;
bool isGettingSecondNum = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->button__digit__0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button__digit__1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button__digit__2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button__digit__3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button__digit__4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button__digit__5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button__digit__6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button__digit__7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button__digit__8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->button__digit__9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->button_plusandminus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->button_plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->button_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->button_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->button_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->button_plus->setCheckable(true);
    ui->button_minus->setCheckable(true);
    ui->button_multiply->setCheckable(true);
    ui->button_divide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if((ui->button_plus->isChecked() || ui->button_minus->isChecked() ||
       ui->button_multiply->isChecked() || ui->button_divide->isChecked()) && !(isGettingSecondNum)){

       labelNumber = (button->text()).toDouble();
       isGettingSecondNum = true;
       newLabel = QString::number(labelNumber,'g',15);

    }
    else{

        if(ui->label->text().contains('.') && button->text() == "0"){
            newLabel = ui->label->text() + button->text();
        }
        else{
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);
        }
    }



    ui->label->setText(newLabel);
}

void MainWindow::on_button_point_released()
{
    if(!(ui->label->text().contains('.'))){
        ui->label->setText(ui->label->text() + ".");
    }

}
void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;
    if(button->text() == "+/-"){
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_button_clear_released()
{
     ui->button_plus->setChecked(false);
     ui->button_multiply->setChecked(false);
     ui->button_minus->setChecked(false);
     ui->button_divide->setChecked(false);



     isGettingSecondNum = false;


     ui->label->setText("0");

}

void MainWindow::on_button_equal_released()
{
    double labelNumber, secondNum;
    QString newLabel;
    secondNum = ui->label->text().toDouble();


    if (ui->button_plus->isChecked()){
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->button_plus->setChecked(false);


    }
    else if (ui->button_minus->isChecked()){
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->button_minus->setChecked(false);

    }
    else if (ui->button_multiply->isChecked()){
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->button_multiply->setChecked(false);

    }
    else if (ui->button_divide->isChecked()){
        if(secondNum != 0){
            labelNumber = firstNum / secondNum;
            newLabel = QString::number(labelNumber,'g',15);
            ui->label->setText(newLabel);
            ui->button_divide->setChecked(false);
        }else{
            ui->label->setText("Error");
            ui->button_divide->setChecked(false);
        }

    }
    isGettingSecondNum = false;
}
void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);


}
