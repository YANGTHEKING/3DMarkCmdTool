#include "appsettings.h"
#include <QDir>
#include <QXmlStreamWriter>
#include <QBuffer>

QStringList AppSettings::availableBenchmarks() const
{
    return {"timespy.3dmdef",
            "firestrike.3dmdef",
            "speedway.3dmdef",};
}

QStringList AppSettings::buildCommandLine(const QString &defPath) const
{
    QStringList args;
    args << "--definition=" + QFileInfo(defPath).fileName();
    args << "--out=" + m_resultPath;
    if (m_gpuId > 0) args << "--gpu-select=" + QString::number(m_gpuId);
    if (m_systemInfo) { args << "--systeminfo=on" << "--systeminfomonitor=on"; }
    if (!m_audio) args << "--audio=off";
    if (m_windowed) args << "--scalingmode=stretched";
    args << "--export=" + m_resultPath + ".xml";
    return args;
}

QString AppSettings::generateDefinitionXml() const
{
    QString result;
    return result;
}

bool AppSettings::validate() const
{
    return QFileInfo::exists(m_cmdPath) && QDir(QFileInfo(m_resultPath).absolutePath()).exists();
}

void AppSettings::load(QSettings *s)
{

}
void AppSettings::save(QSettings *s) const
{

}
