#include "mainwindow.hh"
#include "ui_mainwindow.h"

static const int TIMER_INTERVAL_ms = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), timer(new QTimer(this)), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Method 1 for backgroud color
    ui->lcdNumberSec->setStyleSheet("background: #000000");

    // Method 2 for background color
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255, 255, 150));
    ui->lcdNumberMin->setPalette(palette);
    ui->lcdNumberMin->setAutoFillBackground(true);

    connect(ui->startButton,
            &QPushButton::clicked,
            this,
            &MainWindow::on_start_button_clicked);
    connect(ui->stopButton,
            &QPushButton::clicked,
            this,
            &MainWindow::on_stop_button_clicked);
    connect(ui->resetButton,
            &QPushButton::clicked,
            this,
            &MainWindow::on_reset_button_clicked);
    connect(ui->closeButton,
            &QPushButton::clicked,
            this,
            &MainWindow::on_close_button_clicked);

    connect(timer, &QTimer::timeout, this, &MainWindow::on_timer_timeout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_timer_timeout()
{
    int current_mins = ui->lcdNumberMin->intValue();
    int current_secs = ui->lcdNumberSec->intValue();

    if (current_secs == 59)
    {
        update_display(current_mins + 1, 0);
    }
    else
    {
        update_display(current_mins, current_secs + 1);
    }
}

void MainWindow::on_start_button_clicked()
{
    timer->start(TIMER_INTERVAL_ms);
}

void MainWindow::on_stop_button_clicked()
{
    timer->stop();
}

void MainWindow::on_reset_button_clicked()
{
    update_display(0, 0);
}

void MainWindow::on_close_button_clicked()
{
    close();
}

void MainWindow::update_display(int mins, int secs)
{
    ui->lcdNumberMin->display(mins);
    ui->lcdNumberSec->display(secs);
}
