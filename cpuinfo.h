#ifndef CPUINFO_H
#define CPUINFO_H

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
};

#endif // CPUINFO_H
