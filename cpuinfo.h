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
    Q_PROPERTY(int numProcessors READ numProcessors CONSTANT)
    Q_PROPERTY(QString cpuModelName READ cpuModelName CONSTANT)
    Q_PROPERTY(QString numCores READ numCores CONSTANT)
    Q_PROPERTY(QStringList cpuinfoList READ cpuinfoList CONSTANT)
    Q_PROPERTY(QStringList processorKeyList READ processorKeyList CONSTANT)
    Q_PROPERTY(QStringList processorValueList READ processorValueList CONSTANT)
    Q_PROPERTY(QVariantMap cpuinfoMap READ cpuinfoMap CONSTANT)


public:
    explicit Cpuinfo(QObject *parent = 0);

    Q_INVOKABLE void setProcIndex(int index);
    int numProcessors();
    QString cpuModelName();
    QString numCores();
    QStringList cpuinfoList();
    QStringList processorKeyList();
    QStringList processorValueList();
    QVariantMap cpuinfoMap();
    Q_INVOKABLE QVariantMap getCpuinfoMap(int processor);


signals:

public slots:

private:
    void readFile();

    int mProcIndex = 0;
    QStringList mCpuinfoList;
    QList <QMap<QString, QVariant>> mCpuinfoListOfMaps;
};

#endif // CPUINFO_H
