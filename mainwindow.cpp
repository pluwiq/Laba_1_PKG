#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentColor.setRgb(0,0,0);
    colorDialog = new QColorDialog;
    cmyk.k = 0;
    ui->spinBoxK_2->setValue(0);
    SetColor();


//    ui->widget_3->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                             "color : #c3195d;"
//                             "border: 4px solid  #c3195d;");
//    ui->widget_4->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                               "color : #c3195d;"
//                               "border: 4px solid  #c3195d;");
//    ui->B_label_2->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                                 "color : #c3195d;"
//                                 "border: 4px solid  #c3195d;");
//    ui->C_label_2->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                                 "color : #c3195d;"
//                                 "border: 4px solid  #c3195d;");
//    ui->R_label_2->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                                 "color : #c3195d;"
//                                 "border: 4px solid  #c3195d;");
//    ui->G_label_2->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                                 "color : #c3195d;"
//                                 "border: 4px solid  #c3195d;");
//    ui->M_label_2->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                                 "color : #c3195d;"
//                                 "border: 4px solid  #c3195d;");
//    ui->Y_label_2->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                                 "color : #c3195d;"
//                                 "border: 4px solid  #c3195d;");
//    ui->K_label_2->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                                 "color : #c3195d;"
//                                 "border: 4px solid  #c3195d;");
//    ui->H_label_2->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                                 "color : #c3195d;"
//                                 "border: 4px solid  #c3195d;");
//    ui->L_label_2->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                                 "color : #c3195d;"
//                                 "border: 4px solid  #c3195d;");
//    ui->S_label_2->setStyleSheet("background-color : #ffcbcb;""border-radius : 15px;"
//                                 "color : #c3195d;"
//                                 "border: 4px solid  #c3195d;");



    //RGB SLIDERS -> CHANGE RGB SPINS
    connect(ui->horizontalSliderR_2, SIGNAL(sliderMoved(int)), this, SLOT(RGBBoxChanger()));
    connect(ui->horizontalSliderG_2, SIGNAL(sliderMoved(int)), this, SLOT(RGBBoxChanger()));
    connect(ui->horizontalSliderB_2, SIGNAL(sliderMoved(int)), this, SLOT(RGBBoxChanger()));

    //RGB SPINS -> CHANGE RGB SLIDERS
    connect(ui->spinBoxR_2, SIGNAL(editingFinished()), this, SLOT(RGBSliderChanger()));
    connect(ui->spinBoxG_2, SIGNAL(editingFinished()), this, SLOT(RGBSliderChanger()));
    connect(ui->spinBoxB_2, SIGNAL(editingFinished()), this, SLOT(RGBSliderChanger()));

    //CMYK SPINS FIXED WHEN ANY RGB IS CHANGED
    connect(ui->horizontalSliderR_2, SIGNAL(sliderMoved(int)), this, SLOT(CMYKparam()));
    connect(ui->horizontalSliderG_2, SIGNAL(sliderMoved(int)), this, SLOT(CMYKparam()));
    connect(ui->horizontalSliderB_2, SIGNAL(sliderMoved(int)), this, SLOT(CMYKparam()));

    connect(ui->horizontalSliderR_2, SIGNAL(sliderMoved(int)), this, SLOT(HLSparam()));
    connect(ui->horizontalSliderG_2, SIGNAL(sliderMoved(int)), this, SLOT(HLSparam()));
    connect(ui->horizontalSliderB_2, SIGNAL(sliderMoved(int)), this, SLOT(HLSparam()));

    connect(ui->spinBoxR_2, SIGNAL(editingFinished()), this, SLOT(CMYKparam()));
    connect(ui->spinBoxG_2, SIGNAL(editingFinished()), this, SLOT(CMYKparam()));
    connect(ui->spinBoxB_2, SIGNAL(editingFinished()), this, SLOT(CMYKparam()));

    connect(ui->spinBoxR_2, SIGNAL(editingFinished()), this, SLOT(HLSparam()));
    connect(ui->spinBoxG_2, SIGNAL(editingFinished()), this, SLOT(HLSparam()));
    connect(ui->spinBoxB_2, SIGNAL(editingFinished()), this, SLOT(HLSparam()));

    connect(ui->spinBoxH_2, SIGNAL(editingFinished()), this, SLOT(HLSBoxChanger()));
    connect(ui->spinBoxS_2, SIGNAL(editingFinished()), this, SLOT(HLSBoxChanger()));
    connect(ui->spinBoxL_2, SIGNAL(editingFinished()), this, SLOT(HLSBoxChanger()));

    connect(ui->spinBoxH_2, SIGNAL(editingFinished()), this, SLOT(RGBparam()));
    connect(ui->spinBoxS_2, SIGNAL(editingFinished()), this, SLOT(RGBparam()));
    connect(ui->spinBoxL_2, SIGNAL(editingFinished()), this, SLOT(RGBparam()));

    connect(ui->spinBoxC_2, SIGNAL(editingFinished()), this, SLOT(CMYKBoxChanger()));
    connect(ui->spinBoxM_2, SIGNAL(editingFinished()), this, SLOT(CMYKBoxChanger()));
    connect(ui->spinBoxY_2, SIGNAL(editingFinished()), this, SLOT(CMYKBoxChanger()));
    connect(ui->spinBoxK_2, SIGNAL(editingFinished()), this, SLOT(CMYKBoxChanger()));

    connect(ui->spinBoxC_2, SIGNAL(editingFinished()), this, SLOT(RGBparam()));
    connect(ui->spinBoxM_2, SIGNAL(editingFinished()), this, SLOT(RGBparam()));
    connect(ui->spinBoxY_2, SIGNAL(editingFinished()), this, SLOT(RGBparam()));
    connect(ui->spinBoxK_2, SIGNAL(editingFinished()), this, SLOT(RGBparam()));

    connect(ui->spinBoxC_2, SIGNAL(editingFinished()), this, SLOT(HLSparam()));
    connect(ui->spinBoxM_2, SIGNAL(editingFinished()), this, SLOT(HLSparam()));
    connect(ui->spinBoxY_2, SIGNAL(editingFinished()), this, SLOT(HLSparam()));
    connect(ui->spinBoxK_2, SIGNAL(editingFinished()), this, SLOT(HLSparam()));
    //CMYK SPINS CHANGED -> RGB FIXED: SPINS AND SLIDERS

}

void MainWindow:: SetColor()
{
    QString rv = QString::number(currentColor.red());
    QString gv = QString::number(currentColor.green());
    QString bv = QString::number(currentColor.blue());
    ui->color_2->setStyleSheet("QWidget{""background-color:rgb("+rv+","+gv+","+bv+"); border: 2px solid black;""}");
}
void MainWindow:: RGBBoxChanger()
{
    //CHANGE SPINS
    rgb.r = ui->horizontalSliderR_2->value();
    rgb.g = ui->horizontalSliderG_2->value();
    rgb.b = ui->horizontalSliderB_2->value();

    ui->spinBoxR_2->setValue(rgb.r);
    ui->spinBoxG_2->setValue(rgb.g);
    ui->spinBoxB_2->setValue(rgb.b);

    //FIX COLOR
    currentColor.setRgb(rgb.r, rgb.g, rgb.b);
    SetColor();
    //TRANSLATE
    RGBtoCMYK();
}
void MainWindow:: RGBSliderChanger()
{
    //CHANGE SLIDERS
    rgb.r = ui->spinBoxR_2->value();
    rgb.g = ui->spinBoxG_2->value();
    rgb.b = ui->spinBoxB_2->value();

    ui->horizontalSliderR_2->setValue(rgb.r);
    ui->horizontalSliderG_2->setValue(rgb.g);
    ui->horizontalSliderB_2->setValue(rgb.b);
    //FIX COLOR
    currentColor.setRgb(rgb.r, rgb.g, rgb.b);
    SetColor();
    //TRANSLATE
    RGBtoCMYK();
}
void MainWindow::RGBtoCMYK()
{
    cmyk.k = qMin(qMin(255 - currentColor.red(), 255 - currentColor.green()), 255 - currentColor.blue());
    cmyk.c = (int)((255 - currentColor.red() - cmyk.k)/(1. - (cmyk.k/255.)));
    cmyk.m = (int)((255 - currentColor.green() - cmyk.k)/(1. - (cmyk.k/255.)));
    cmyk.y = (int)((255 - currentColor.blue() - cmyk.k)/(1. - (cmyk.k/255.)));
}
void MainWindow:: CMYKtoRGB()
{
    rgb.r = (int)((255 - currentColor.cyan())*(1. - (currentColor.black() /255.)));
    rgb.g = (int)((255 - currentColor.magenta())*(1. - (currentColor.black()/255.)));
    rgb.b = (int)((255 - currentColor.yellow())*(1. - (currentColor.black()/255.)));
}
void MainWindow:: CMYKparam()
{
    //CHANGE SPINS ACCORDING TO THE CURRENT COLOR
    ui->spinBoxC_2->setValue(currentColor.cyan());
    ui->spinBoxM_2->setValue(currentColor.magenta());
    ui->spinBoxY_2->setValue(currentColor.yellow());
    ui->spinBoxK_2->setValue(currentColor.black());
}
void MainWindow:: HLSparam()
{
    ui->spinBoxH_2->setValue(currentColor.hue());
    ui->spinBoxS_2->setValue(currentColor.hslSaturation());
    ui->spinBoxL_2->setValue(currentColor.lightness());
}
void MainWindow:: RGBparam()
{
    ui->horizontalSliderR_2->setValue(currentColor.red());
    ui->horizontalSliderG_2->setValue(currentColor.green());
    ui->horizontalSliderB_2->setValue(currentColor.blue());
    ui->spinBoxR_2->setValue(currentColor.red());
    ui->spinBoxG_2->setValue(currentColor.green());
    ui->spinBoxB_2->setValue(currentColor.blue());
}

void MainWindow:: CMYKBoxChanger()
{
    cmyk.c = ui->spinBoxC_2->value();
    cmyk.m = ui->spinBoxM_2->value();
    cmyk.y = ui->spinBoxY_2->value();
    cmyk.k = ui->spinBoxK_2->value();

    //FIX COLOR
    currentColor.setCmyk(cmyk.c, cmyk.m, cmyk.y, cmyk.k);
    SetColor();

    //TRANSLATE
    CMYKtoRGB();
    hls.h = currentColor.hue();
    hls.s = currentColor.saturation();
    hls.l = currentColor.lightness();
}

void MainWindow:: HLSBoxChanger()
{
    hls.h = ui->spinBoxH_2->value();
    hls.s = ui->spinBoxS_2->value();
    hls.l = ui->spinBoxL_2->value();
    currentColor.setHsl(hls.h, hls.s, hls.l);
    SetColor();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    currentColor = colorDialog->getColor();
    SetColor();
    ui->horizontalSliderR_2->setValue(currentColor.red());
    ui->horizontalSliderG_2->setValue(currentColor.green());
    ui->horizontalSliderB_2->setValue(currentColor.blue());
    ui->spinBoxR_2->setValue(currentColor.red());
    ui->spinBoxG_2->setValue(currentColor.green());
    ui->spinBoxB_2->setValue(currentColor.blue());
    ui->spinBoxC_2->setValue(currentColor.cyan());
    ui->spinBoxM_2->setValue(currentColor.magenta());
    ui->spinBoxY_2->setValue(currentColor.yellow());
    ui->spinBoxK_2->setValue(currentColor.black());

    ui->spinBoxH_2->setValue(currentColor.hue());
    ui->spinBoxS_2->setValue(currentColor.hslSaturation());
    ui->spinBoxL_2->setValue(currentColor.lightness());

}




