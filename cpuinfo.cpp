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
//    QString procCpuInfo = "/Users/Asia/Workspace/cpuinfo/cpuinfo.txt"; // Mac
//    QString procCpuInfo = "/home/am/Workspace/cpuinfo/cpuinfo.txt";    // Linux

    QFile file(procCpuInfo);
    qDebug() << "readFile: " << file.fileName();

    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        qDebug() << "Can't open file. return!";
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine();

    QStringList splitText;
    QMap<QString, QString> map;

    while (!line.isNull()) {
        splitText = line.split(":",QString::SkipEmptyParts);

        if (splitText.length() > 0) {
            QString key = splitText.at(0).trimmed();
            QString value;
            if (splitText.length() == 2) {
                value =  splitText.at(1).trimmed();
            }
            else {
                value = "";
            }

            map.insert(key, value);
            mCpuinfoList.append(key + " : " + value);

            if (key == "power management") {
                // add complete map of processor cpuinfo to QList
                mCpuinfoListOfMaps.append(map);
                // start next processor with a clear map
                map.clear();
                // add newline and separator to StringList
                mCpuinfoList.append("\n-----\n");
            }
        }
        line = in.readLine();
    }
    file.close();

    qDebug() << "number of processors: " << mCpuinfoListOfMaps.length();
    qDebug() << "QStringList count: " << mCpuinfoList.count();
}
