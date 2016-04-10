#include "Cpuinfo.h"

#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

Cpuinfo::Cpuinfo(QObject *parent) : QObject(parent)
{
    readFile();
}

QStringList Cpuinfo::cpuinfoList()
{
    return mCpuinfoList;
}

void Cpuinfo::readFile()
{
    QString procCpuInfo = "/proc/cpuinfo";
//    QFile file(procCpuInfo);
    QFile file("/Users/Asia/Workspace/cpuinfo/cpuinfo.txt");
    qDebug() << "readFile: " << file.fileName();

    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        qDebug() << "Can't open file. return!";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        mCpuinfoList.append(line);
    }
}
