#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QMap>
#include <QSettings>
#include <QFileInfo>

class AppSettings : public QObject {
    Q_OBJECT
private:
    AppSettings() {};
public:

    AppSettings(const AppSettings&) = delete;
    AppSettings& operator=(const AppSettings&) = delete;

    static AppSettings* getInstance() {
        static AppSettings* instance = new AppSettings;
        return instance;
    }

    QStringList availableBenchmarks() const;
    QStringList gpuList() const { return m_gpuList; }

    // Core Function
    QStringList buildCommandLine(const QString &defPath) const;  // CLI args
    QString generateDefinitionXml() const;  // Generate/Edit.3dmdef XML
    bool validate() const;  // Check for the path and etc.

    void load(QSettings *s = nullptr);
    void save(QSettings *s = nullptr) const;

    // Data Enumeration
    enum Language{
        English,
        Chinese,
    };
    enum BenchMark{
        IceStorm,
        IceStormExtreme,
        CloudGate,
        TimeSpy,
        TimeSpyExtreme,
        SteelNomad,
        SteelNomadLight,
        FireStrike,
        FireStrikeExtreme,
        FireStrikeUltra,
        WildLife,
        WildLifeExtreme,
        NightRaid,
        CPUProfile,
    };
    enum Resolution{
        r640x480,
        r720x400,
        r720x480,
        r720x576,
        r800x600,
        r1024x600,
        r1024x768,
        r1152x864,
        r1176x664,
        r1200x960,
        r1280x720,
        r1280x768,
        r1280x800,
        r1280x960,
        r1280x1024,
        r1360x768,
        r1366x768,
        r1440x480,
        r1440x900,
        r1600x900,
        r1600x1024,
        r1600x1200,
        r1680x1050,
        r1768x992,
        r1920x1080,
        r1920x1200,
        r1920x1440,
        r2048x1152,
        r2048x1280,
        r2160x1440,
        r2560x1080,
        r2560x1440,
        r2560x1600,
        r3200x1800,
        r3440x1440,
        r3840x2160,
        r3840x2400,
        r4096x2304,
        r5120x2160,
        r5120x2880,
        r7680x4320,
        r8192x4608,
    };
    enum TextureFilter{
        Bilinear,
        Trilinear,
        Anisotropic,
    };
    enum Antialiasing{
        Disabled,
        MSAA,
        FXAA,
    };
signals:
    // Location
    void cmdPathChanged();
    void resultPathChanged();
private:
    // Data Member
    QString       m_cmdPath                           = "";
    QString       m_resultPath                        = "";
    QString       m_customXmlContent                  = "";
    Language      m_language                          = English;
    BenchMark     m_benchmark                         = IceStorm;
    Resolution    m_resolution                        = r1280x720;
    TextureFilter m_textureFilter                     = Trilinear;
    Antialiasing  m_antialiasing                      = MSAA;
    int           m_gpuId                             = 0;
    int           m_maxAFAnisotropy                   = 2;
    int           m_msaa                              = 1;
    int           m_shadowmapSize                     = 1024;
    int           m_surfaceShadows                    = 4;
    int           m_ambientOcclusionQuality           = 1;
    int           m_depthofFieldQuality               = 1;
    int           m_bloomQuality                      = 1;
    int           m_colorSaturation                   = 0;
    int           m_volumetricIlluminationQuality     = 1;
    int           m_texturequality                    = 1;
    int           m_fps                               = 0;
    int           m_msaasample                        = 1;
    float         m_volumetricIlluminationSampleCount = 1.0f;
    bool          m_useCustom                         = false;
    bool          m_includeDemo                       = true;
    bool          m_graphicsTest1                     = true;
    bool          m_graphicsTest2                     = true;
    bool          m_physicsTest                       = true;
    bool          m_windowed                          = false;
    bool          m_verticalsync                      = false;
    bool          m_triplebuffer                      = false;
    bool          m_wireframe                         = false;
    bool          m_fixedfps                          = false;
    bool          m_audio                             = true;
    bool          m_systemInfo                        = false;
    QStringList   m_gpuList                           = {};
    QStringList   m_workloads                         = {};  // Current benchmark workload list （dynamic）
public:
    // Save & Load Data
    // 1. m_cmdPath
    const QString& getCmdPath() const { return m_cmdPath; }
    void setCmdPath(const QString& cmdPath) { m_cmdPath = cmdPath; }

    // 2. m_resultPath
    const QString& getResultPath() const { return m_resultPath; }
    void setResultPath(const QString& resultPath) { m_resultPath = resultPath; }

    // 3. m_customXmlContent
    const QString& getCustomXmlContent() const { return m_customXmlContent; }
    void setCustomXmlContent(const QString& content) { m_customXmlContent = content; }

    // 4. m_benchmark
    BenchMark getBenchmark() const { return m_benchmark; }
    void setBenchmark(BenchMark benchmark) { m_benchmark = benchmark; }

    // 5. m_resolution
    Resolution getResolution() const { return m_resolution; }
    void setResolution(Resolution resolution) { m_resolution = resolution; }

    // 6. m_textureFilter
    TextureFilter getTextureFilter() const { return m_textureFilter; }
    void setTextureFilter(TextureFilter filter) { m_textureFilter = filter; }

    // 7. m_antialiasing
    Antialiasing getAntialiasing() const { return m_antialiasing; }
    void setAntialiasing(Antialiasing antialiasing) { m_antialiasing = antialiasing; }

    // 8. m_gpuId
    int getGpuId() const { return m_gpuId; }
    void setGpuId(int gpuId) { m_gpuId = gpuId; }

    // 9. m_maxAFAnisotropy
    int getMaxAFAnisotropy() const { return m_maxAFAnisotropy; }
    void setMaxAFAnisotropy(int value) { m_maxAFAnisotropy = value; }

    // 10. m_msaa
    int getMsaa() const { return m_msaa; }
    void setMsaa(int msaa) { m_msaa = msaa; }

    // 11. m_shadowmapSize
    int getShadowmapSize() const { return m_shadowmapSize; }
    void setShadowmapSize(int size) { m_shadowmapSize = size; }

    // 12. m_surfaceShadows
    int getSurfaceShadows() const { return m_surfaceShadows; }
    void setSurfaceShadows(int value) { m_surfaceShadows = value; }

    // 13. m_ambientOcclusionQuality
    int getAmbientOcclusionQuality() const { return m_ambientOcclusionQuality; }
    void setAmbientOcclusionQuality(int quality) { m_ambientOcclusionQuality = quality; }

    // 14. m_depthofFieldQuality
    int getDepthofFieldQuality() const { return m_depthofFieldQuality; }
    void setDepthofFieldQuality(int quality) { m_depthofFieldQuality = quality; }

    // 15. m_bloomQuality
    int getBloomQuality() const { return m_bloomQuality; }
    void setBloomQuality(int quality) { m_bloomQuality = quality; }

    // 16. m_colorSaturation
    int getColorSaturation() const { return m_colorSaturation; }
    void setColorSaturation(int saturation) { m_colorSaturation = saturation; }

    // 17. m_volumetricIlluminationQuality
    int getVolumetricIlluminationQuality() const { return m_volumetricIlluminationQuality; }
    void setVolumetricIlluminationQuality(int quality) { m_volumetricIlluminationQuality = quality; }

    // 18. m_volumetricIlluminationSampleCount
    float getVolumetricIlluminationSampleCount() const { return m_volumetricIlluminationSampleCount; }
    void setVolumetricIlluminationSampleCount(float count) { m_volumetricIlluminationSampleCount = count; }

    // 19. m_useCustom
    bool isUseCustom() const { return m_useCustom; }
    void setUseCustom(bool useCustom) { m_useCustom = useCustom; }

    // 20. m_includeDemo
    bool isIncludeDemo() const { return m_includeDemo; }
    void setIncludeDemo(bool includeDemo) { m_includeDemo = includeDemo; }

    // 21. m_graphicsTest1
    bool isGraphicsTest1() const { return m_graphicsTest1; }
    void setGraphicsTest1(bool enable) { m_graphicsTest1 = enable; }

    // 22. m_graphicsTest2
    bool isGraphicsTest2() const { return m_graphicsTest2; }
    void setGraphicsTest2(bool enable) { m_graphicsTest2 = enable; }

    // 23. m_physicsTest
    bool isPhysicsTest() const { return m_physicsTest; }
    void setPhysicsTest(bool enable) { m_physicsTest = enable; }

    // 24. m_windowed
    bool isWindowed() const { return m_windowed; }
    void setWindowed(bool windowed) { m_windowed = windowed; }

    // 25. m_audio
    bool isAudioEnabled() const { return m_audio; }  // Clearer declaration
    void setAudioEnabled(bool audio) { m_audio = audio; }

    // 26. m_systemInfo
    bool isSystemInfoEnabled() const { return m_systemInfo; }
    void setSystemInfoEnabled(bool systemInfo) { m_systemInfo = systemInfo; }

    // 27. m_gpuList
    const QStringList& getGpuList() const { return m_gpuList; }
    QStringList& getGpuList() { return m_gpuList; }
    void setGpuList(const QStringList& gpuList) { m_gpuList = gpuList; }

    // 28. m_workloads
    const QStringList& getWorkloads() const { return m_workloads; }
    QStringList& getWorkloads() { return m_workloads; }
    void setWorkloads(const QStringList& workloads) { m_workloads = workloads; }

    // 29. m_language
    Language getLanguage() const { return m_language; }
    void setLanguage(Language language) { m_language = language; }

    // 30. m_verticalsync
    bool isVerticalSync() const { return m_verticalsync; }
    void setVerticalSync(bool verticalsync) { m_verticalsync = verticalsync; }

    // 31. m_triplebuffer
    bool isTripleBuffer() const { return m_triplebuffer; }
    void setTripleBuffer(bool triplebuffer) { m_triplebuffer = triplebuffer; }

    // 32. m_wireframe
    bool isWireFrame() const { return m_wireframe; }
    void setWireFrame(bool wireframe) { m_wireframe = wireframe; }

    // 33. m_fixedfps
    bool isFixedFPS() const { return m_fixedfps; }
    void setFixedFPS(bool fixedfps) { m_fixedfps = fixedfps; }

    // 34. m_fps
    int getFPS() const { return m_fps; }
    void setFPS(int value) { m_fps = value; }

    // 35. m_msaasample
    int getMSAASampleCount() const { return m_msaasample; }
    void setMSAASampleCount(int count) { m_msaasample = count; }

    // 36. m_texturequality
    int getTextureQuality() const { return m_texturequality; }
    void setTextureQuality(int quality) { m_texturequality = quality; }
};
#define AS AppSettings::getInstance()
#endif // APPSETTINGS_H
