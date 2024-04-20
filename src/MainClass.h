#pragma once

#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QProcess>

class MainClass : public QObject
{
    Q_OBJECT
    QProcess *process;
public:
    MainClass(QObject *parent);
private slots:
    void QProcessErrHandler(QProcess::ProcessError error);
    void QProcessStateChangeHandler(QProcess::ProcessState newState);
    void QProcessFinishHandler(int exitCode, QProcess::ExitStatus exitStatus);
};
