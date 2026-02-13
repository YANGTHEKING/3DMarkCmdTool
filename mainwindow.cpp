#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appsettings.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectSignalsAndSlots();
    setStyleSheet();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectSignalsAndSlots()
{
    // ====================== Radio Button Group ======================
    connect(ui->rbDefault, &QRadioButton::clicked,
            this, &MainWindow::handleDefaultRadioClicked);
    connect(ui->rbCustom, &QRadioButton::clicked,
            this, &MainWindow::handleCustomRadioClicked);

    // ====================== Function Control Buttons ======================
    connect(ui->bReset, &QPushButton::clicked,
            this, &MainWindow::handleResetClicked);
    connect(ui->bDemo, &QPushButton::clicked,
            this, &MainWindow::handleDemoClicked);
    connect(ui->bGraphicTest_1, &QPushButton::clicked,
            this, &MainWindow::handleGraphicTest1Clicked);
    connect(ui->bGraphicTest_2, &QPushButton::clicked,
            this, &MainWindow::handleGraphicTest2Clicked);
    connect(ui->bPhysicsTest, &QPushButton::clicked,
            this, &MainWindow::handlePhysicsTestClicked);
    connect(ui->bWindowMode, &QPushButton::clicked,
            this, &MainWindow::handleWindowModeClicked);
    connect(ui->bVerticalSync, &QPushButton::clicked,
            this, &MainWindow::handleVerticalSyncClicked);
    connect(ui->bTripleBuffering, &QPushButton::clicked,
            this, &MainWindow::handleTripleBufferingClicked);
    connect(ui->bWireFrame, &QPushButton::clicked,
            this, &MainWindow::handleWireFrameClicked);
    connect(ui->bFixedFPS, &QPushButton::clicked,
            this, &MainWindow::handleFixedFPSClicked);

    // ====================== Numeric Input/Slider Controls ======================
    connect(ui->sbFPS, &QSpinBox::valueChanged,
            this, &MainWindow::handleFPSValueChanged);
    connect(ui->sMaxAFAnistropy, &QSlider::valueChanged,
            this, &MainWindow::handleMaxAFAnisotropyValueChanged);
    connect(ui->sMSAASampleCount, &QSlider::valueChanged,
            this, &MainWindow::handleMSAASampleCountValueChanged);
    connect(ui->sShadowmapSize, &QSlider::valueChanged,
            this, &MainWindow::handleShadowmapSizeValueChanged);
    connect(ui->sSurfaceShadows, &QSlider::valueChanged,
            this, &MainWindow::handleSurfaceShadowsValueChanged);
    connect(ui->sVolumetricIlluminationQuality, &QSlider::valueChanged,
            this, &MainWindow::handleVolumetricIlluminationQualityValueChanged);
    connect(ui->sAmbientOcclusionQuality, &QSlider::valueChanged,
            this, &MainWindow::handleAmbientOcclusionQualityValueChanged);
    connect(ui->sDepthofFieldQuality, &QSlider::valueChanged,
            this, &MainWindow::handleDepthOfFieldQualityValueChanged);
    connect(ui->sBloomQuality, &QSlider::valueChanged,
            this, &MainWindow::handleBloomQualityValueChanged);
    connect(ui->sTextureQuality, &QSlider::valueChanged,
            this, &MainWindow::handleTextureQualityValueChanged);
    connect(ui->sColorSaturation, &QSlider::valueChanged,
            this, &MainWindow::handleColorSaturationValueChanged);

    // ====================== Dropdown Selection Boxes ======================
    connect(ui->cbBenchMark, &QComboBox::currentIndexChanged,
            this, &MainWindow::handleBenchMarkIndexChanged);
    connect(ui->cbGPU, &QComboBox::currentIndexChanged,
            this, &MainWindow::handleGPUIndexChanged);
    connect(ui->cbResolution, &QComboBox::currentIndexChanged,
            this, &MainWindow::handleResolutionIndexChanged);
    connect(ui->cbTextureFilteringMode, &QComboBox::currentIndexChanged,
            this, &MainWindow::handleTextureFilteringModeIndexChanged);
    connect(ui->cbAntialiasingMode, &QComboBox::currentIndexChanged,
            this, &MainWindow::handleAntialiasingModeIndexChanged);
    connect(ui->cbVolumetricIlluminationSampleCount, &QComboBox::currentIndexChanged,
            this, &MainWindow::handleVolumetricIlluminationSampleCountIndexChanged);
}

// Test Mode
void MainWindow::handleDefaultRadioClicked()
{
    if(!AS->isUseCustom())
        return;
    ui->rbCustom->setChecked(false);
    handleResetClicked();
    AS->setUseCustom(false);
}


void MainWindow::handleCustomRadioClicked()
{
    if(AS->isUseCustom())
        return;
    ui->rbDefault->setChecked(false);
    handleResetClicked();
    AS->setUseCustom(true);
}

void MainWindow::setButtonState()
{
    switch (AS->getBenchmark())
    {
    case AppSettings::IceStorm:

        break;
    default:
        break;
    }
}

void MainWindow::setStyleSheet()
{
    this->setWindowTitle("3DMarkCmdTool");
}

void MainWindow::setButtonText(QPushButton *b, bool isTrue)
{
    switch (AS->getLanguage())
    {
    case AppSettings::Chinese:
        if(isTrue)
        {
            b->setText("是");
        }
        else
        {
            b->setText("否");
        }
        break;
    case AppSettings::English:
    default:
        if(isTrue)
        {
            b->setText("Yes");
        }
        else
        {
            b->setText("No");
        }
        break;
    }
}

void MainWindow::handleResetClicked()
{
    //BenchMark
}

void MainWindow::handleDemoClicked()
{
    AS->setIncludeDemo(!AS->isIncludeDemo());
    setButtonText(ui->bDemo, AS->isIncludeDemo());
}

void MainWindow::handleGraphicTest1Clicked()
{
    AS->setGraphicsTest1(!AS->isGraphicsTest1());
    setButtonText(ui->bGraphicTest_1, AS->isGraphicsTest1());
}

void MainWindow::handleGraphicTest2Clicked()
{
    AS->setGraphicsTest2(!AS->isGraphicsTest2());
    setButtonText(ui->bGraphicTest_2, AS->isGraphicsTest2());
}

void MainWindow::handlePhysicsTestClicked()
{
    AS->setPhysicsTest(!AS->isPhysicsTest());
    setButtonText(ui->bPhysicsTest, AS->isPhysicsTest());
}

void MainWindow::handleWindowModeClicked()
{
    AS->setWindowed(!AS->isWindowed());
    setButtonText(ui->bWindowMode, AS->isWindowed());
}

void MainWindow::handleVerticalSyncClicked()
{
    AS->setVerticalSync(!AS->isVerticalSync());
    setButtonText(ui->bVerticalSync, AS->isVerticalSync());
}

void MainWindow::handleTripleBufferingClicked()
{
    AS->setTripleBuffer(!AS->isTripleBuffer());
    setButtonText(ui->bTripleBuffering, AS->isTripleBuffer());
}

void MainWindow::handleWireFrameClicked()
{
    AS->setWireFrame(!AS->isWireFrame());
    setButtonText(ui->bWireFrame, AS->isWireFrame());
}

void MainWindow::handleFixedFPSClicked()
{
    AS->setFixedFPS(!AS->isFixedFPS());
    setButtonText(ui->bFixedFPS, AS->isFixedFPS());
}

void MainWindow::handleFPSValueChanged(int value)
{
    AS->setFPS(value);
}

void MainWindow::handleMaxAFAnisotropyValueChanged(int value)
{
    AS->setMaxAFAnisotropy(value);
}

void MainWindow::handleMSAASampleCountValueChanged(int value)
{
    AS->setMSAASampleCount(value);
}

void MainWindow::handleShadowmapSizeValueChanged(int value)
{
    AS->setShadowmapSize(value);
}

void MainWindow::handleSurfaceShadowsValueChanged(int value)
{
    AS->setSurfaceShadows(value);
}

void MainWindow::handleVolumetricIlluminationQualityValueChanged(int value)
{
    AS->setVolumetricIlluminationQuality(value);
}

void MainWindow::handleAmbientOcclusionQualityValueChanged(int value)
{
    AS->setAmbientOcclusionQuality(value);
}

void MainWindow::handleDepthOfFieldQualityValueChanged(int value)
{
    AS->setDepthofFieldQuality(value);
}

void MainWindow::handleBloomQualityValueChanged(int value)
{
    AS->setBloomQuality(value);
}

void MainWindow::handleTextureQualityValueChanged(int value)
{
    AS->setTextureQuality(value);
}

void MainWindow::handleColorSaturationValueChanged(int value)
{
    AS->setColorSaturation(value);
}

void MainWindow::handleBenchMarkIndexChanged(int index)
{
    AS->setBenchmark(static_cast<AppSettings::BenchMark>(index));
}

void MainWindow::handleGPUIndexChanged(int index)
{
    AS->setGpuId(index);
}

void MainWindow::handleResolutionIndexChanged(int index)
{
    AS->setResolution(static_cast<AppSettings::Resolution>(index));
}

void MainWindow::handleTextureFilteringModeIndexChanged(int index)
{
    AS->setTextureFilter(static_cast<AppSettings::TextureFilter>(index));
}

void MainWindow::handleAntialiasingModeIndexChanged(int index)
{
    AS->setAntialiasing(static_cast<AppSettings::Antialiasing>(index));
}

void MainWindow::handleVolumetricIlluminationSampleCountIndexChanged(int index)
{
    QString value = ui->cbVolumetricIlluminationSampleCount->itemText(index);
    AS->setVolumetricIlluminationSampleCount(value.toFloat());
}


