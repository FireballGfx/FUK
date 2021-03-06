#include "customview.h"

#include <QWheelEvent>

CustomView::CustomView(QWidget* parent) : QGraphicsView(parent){
    scale(1/2.0,1/2.0);
}

void CustomView::wheelEvent(QWheelEvent *event){
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleValue = 1.5;

    if(event->delta() > 0){
        scale(scaleValue,scaleValue);
    }else{
        scale(1/scaleValue,1/scaleValue);
    }
}
