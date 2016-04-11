#ifndef CPUINFO_H
#define CPUINFO_H

#include <QList>
#include <QMap>
#include <QObject>
#include <QStringList>
#include <QVariant>

class Cpuinfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList cpuinfoList READ cpuinfoList CONSTANT)
    Q_PROPERTY(int numProcessors READ numProcessors CONSTANT)

public:
    explicit Cpuinfo(QObject *parent = 0);
    QStringList cpuinfoList();
    QVariantMap cpuinfoMap();
    Q_INVOKABLE QVariantMap getCpuinfoMap(int processor);
    int numProcessors() { return mCpuinfoListOfMaps.count(); }

signals:

public slots:

private:
    void readFile();

    QStringList mCpuinfoList;
    QList <QMap<QString, QVariant>> mCpuinfoListOfMaps;
};

#endif // CPUINFO_H
