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

QStringList Cpuinfo::processorKeyList()
{
    QStringList procKeyList;

    foreach( QString key, mCpuinfoListOfMaps[mProcIndex].keys() )
        procKeyList.append(key);

    return procKeyList;
}

QStringList Cpuinfo::processorValueList()
{
    QStringList procValueList;

    foreach( QString key, mCpuinfoListOfMaps[mProcIndex].keys() )
        procValueList.append( mCpuinfoListOfMaps[mProcIndex].value(key).toString());

    return procValueList;
}

QVariantMap Cpuinfo::cpuinfoMap()
{
    return mCpuinfoListOfMaps[mProcIndex];
}

QVariantMap Cpuinfo::getCpuinfoMap(int processor)
{
    qDebug() << "Return map for processor " << processor;
    return mCpuinfoListOfMaps[processor];
}

void Cpuinfo::setProcIndex(int index)
{
    qDebug() << "mProcIndex =" << index;
    mProcIndex = index;
}

int Cpuinfo::numProcessors() {
    return mCpuinfoListOfMaps.count();
}

QString Cpuinfo::numCores()
{
    return mCpuinfoListOfMaps[0].value("cpu cores").toString();
}

QString Cpuinfo::cpuModelName()
{
    return mCpuinfoListOfMaps[0].value("model name").toString();
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

    QMap<QString, QVariant> map;

    while (!line.isNull()) {
        QStringList splitText = line.split(":",QString::SkipEmptyParts);

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

    qDebug() << "number of processors: " << mCpuinfoListOfMaps.count();
    qDebug() << "QStringList count: " << mCpuinfoList.count();
}
