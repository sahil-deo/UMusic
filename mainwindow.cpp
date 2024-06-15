#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMultimedia>
#include <QCoreApplication>


QString source;
QMediaPlayer *player;
QAudioOutput *audioOutput;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    player =  new QMediaPlayer;
    audioOutput = new QAudioOutput;

}

MainWindow::~MainWindow()
{
    delete ui;
}


bool isPaused;
bool isPlaying;
bool isLooping;


void MainWindow::on_playBtn_clicked()
{

    if(isPaused){
        player->play();
        return;
    }

    source = ui->addr->text();


    player->setAudioOutput(audioOutput);

    player->setSource(QUrl::fromLocalFile(source));


    audioOutput->setVolume(50);

    player->play();
    isPlaying = true;

}


void MainWindow::on_stopBtn_clicked()
{

    player->stop();
    isPlaying = false;
    isPaused = false;
}


void MainWindow::on_pauseBtn_clicked()
{
    if(player->isPlaying()){
        player->pause();
        isPaused = true;
    }
}



void MainWindow::on_loopBtn_clicked()
{
    if(isLooping){
        isLooping = false;
        player->setLoops(QMediaPlayer::Loops::Once);
        ui->loopBtn->setText("Loop Off");
    }else{
        isLooping = true;
        player->setLoops(QMediaPlayer::Loops::Infinite);
        ui->loopBtn->setText("Loop On");
    }
}

