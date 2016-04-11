#ifndef CPUINFO_H
#define CPUINFO_H

#include <QList>
#include <QMap>
#include <QObject>
#include <QStringList>

class Cpuinfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList cpuinfoList READ cpuinfoList CONSTANT)

public:
    explicit Cpuinfo(QObject *parent = 0);
    QStringList cpuinfoList();

signals:

public slots:

private:
    void readFile();

    QStringList mCpuinfoList;
    QList <QMap<QString, QString>> mCpuinfoListOfMaps;
};

#endif // CPUINFO_H
