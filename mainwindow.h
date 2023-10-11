
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "rgb.h"
#include "cmyk.h"
#include "hls.h"
#include <QMainWindow>
#include <QColor>
#include <QSlider>
#include <QColorDialog>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QColorDialog* colorDialog;
    CMYK cmyk;
    RGB rgb;
    //hsv hsv;
    hls hls;
    bool isRGB;
    bool isCMYK;
    //bool isHSV;
    bool isHLS;
    QColor currentColor;
    void SetColor();
    void RGBtoCMYK();
    void CMYKtoRGB();
    void HLStoRGB();
    void RGBtoHLS();
   // void HSVtoRGB();
   // void RGBtoHSV();
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void CMYKparam();
    void RGBparam();
    //void HSVparam();
    void HLSparam();
    void RGBSliderChanger();
    void RGBBoxChanger();
    void CMYKBoxChanger();
  //  void HSVBoxChanger();
    void HLSBoxChanger();
private slots:
    void on_pushButton_clicked();
};


#endif // MAINWINDOW_H
