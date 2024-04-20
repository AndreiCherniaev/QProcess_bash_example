#include "MainClass.h"

MainClass::MainClass(QObject *parent)
    : QObject(parent)
{
    //Thanks https://github.com/AndreiCherniaev/libav_MJPEG-transcode-VP9_C_Universe
    process = new QProcess(this);
    connect(process, &QProcess::errorOccurred, this, &MainClass::QProcessErrHandler);
    connect(process, &QProcess::stateChanged, this, &MainClass::QProcessStateChangeHandler);
    connect(process, &QProcess::finished, this, &MainClass::QProcessFinishHandler);
    process->setProcessChannelMode(QProcess::MergedChannels);
    //If you need read Linux env variables (for example $PWD) then use qgetenv("PWD");
    process->setProgram("bash");
    process->setArguments({"-c", "ffmpeg -y -f lavfi -i testsrc=size=1280x720:rate=1:duration=10 -vcodec mjpeg -pix_fmt yuvj422p -f mjpeg input.yuvj422p"});
    process->start();
}


void MainClass::QProcessErrHandler(QProcess::ProcessError error){
    qWarning().noquote().nospace() << "QProcess problem;" << error;
    QCoreApplication::quit();
}


void MainClass::QProcessStateChangeHandler(QProcess::ProcessState newState){
    qDebug() << "new QProcess state=" << newState;
    if(newState==QProcess::NotRunning){
        qDebug().noquote().nospace() << "QProcess should finish";
    }
}


void MainClass::QProcessFinishHandler(int exitCode, QProcess::ExitStatus exitStatus){
    QByteArray processMsg(process->readAll());
    if(exitCode== 0 && exitStatus== QProcess::NormalExit){
        if(processMsg.isEmpty()) qDebug().noquote().nospace() << "QProcess finish ok";
        else qDebug().noquote().nospace() << "QProcess finish ok;msg;" << processMsg;
    }else qWarning().noquote().nospace() << "QProcess finish with code;" << exitCode << ";exitStatus;" << exitStatus << ";msg;" << processMsg;
    QCoreApplication::quit();
}
