#include "cpuinfo.h"

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
//    QString procCpuInfo = "/Users/Asia/Workspace/cpuinfo/cpuinfo.txt";
//    QString procCpuInfo = "/home/am/Workspace/cpuinfo/cpuinfo.txt";

    QFile file(procCpuInfo);
    qDebug() << "readFile: " << file.fileName();

    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        qDebug() << "Can't open file. return!";
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        mCpuinfoList.append(line);
        line = in.readLine();
    }
    file.close();
    qDebug() << "QStringList count: " << mCpuinfoList.count();
}
