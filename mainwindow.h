#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <appsettings.h>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void connectSignalsAndSlots();
    void setButtonState();
    void setStyleSheet();
    void setButtonText(QPushButton *b, bool is);
private slots:
    // Radio button group - Switch configuration modes
    void handleDefaultRadioClicked();
    void handleCustomRadioClicked();

    // Function control buttons
    void handleResetClicked();
    void handleDemoClicked();
    void handleGraphicTest1Clicked();
    void handleGraphicTest2Clicked();
    void handlePhysicsTestClicked();
    void handleWindowModeClicked();
    void handleVerticalSyncClicked();
    void handleTripleBufferingClicked();
    void handleWireFrameClicked();
    void handleFixedFPSClicked();

    // Numeric input/slider controls - Parameter value changes
    void handleFPSValueChanged(int fpsValue);
    void handleMaxAFAnisotropyValueChanged(int value);
    void handleMSAASampleCountValueChanged(int value);
    void handleShadowmapSizeValueChanged(int value);
    void handleSurfaceShadowsValueChanged(int value);
    void handleVolumetricIlluminationQualityValueChanged(int value);
    void handleAmbientOcclusionQualityValueChanged(int value);
    void handleDepthOfFieldQualityValueChanged(int value);
    void handleBloomQualityValueChanged(int value);
    void handleTextureQualityValueChanged(int value);
    void handleColorSaturationValueChanged(int value);

    // Dropdown selection boxes - Index changes
    void handleBenchMarkIndexChanged(int index);
    void handleGPUIndexChanged(int index);
    void handleResolutionIndexChanged(int index);
    void handleTextureFilteringModeIndexChanged(int index);
    void handleAntialiasingModeIndexChanged(int index);
    void handleVolumetricIlluminationSampleCountIndexChanged(int index);

private:
    Ui::MainWindow* ui         = nullptr;
};
#endif // MAINWINDOW_H
