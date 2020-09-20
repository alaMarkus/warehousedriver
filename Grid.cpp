#include "./Grid.h"

void Grid::setGridX(int xToSet){
    gridSizeX = xToSet;
}

void Grid::setGridY(int yToSet){
    gridSizeY = yToSet;
}

void Grid::setColumnWidth(int width){
    columnWidth = width;
}
void Grid::setRowHeight(int heigth){
    rowHeight = heigth;
}

int Grid::getGridSizeX(){
    return gridSizeX;
}

int Grid::getGridSizeY(){
    return gridSizeY;
}

void Grid::setStepsPerMillimeter(int steps){
    stepsPerMillimeter = steps;
}

void Grid::setMoveCoordinates(int position){
    if(position%gridSizeX==0){
        yPosToMove = position/gridSizeX;
    }else{
        yPosToMove = position/gridSizeX+1;
    }
    xPosToMove = position%gridSizeX;
    if(xPosToMove==0){
        xPosToMove=gridSizeX;
    }
}

int Grid::getXcoordinate(){
    return xPosToMove;
}

int Grid::getYcoordinate(){
    return yPosToMove;
}

int Grid::getDistanceToMoveX(){
    return (xPosToMove*columnWidth-columnWidth)*stepsPerMillimeter;
}

int Grid::getDistanceToMoveY(){
    return (yPosToMove*rowHeight-rowHeight)*stepsPerMillimeter;
}