#ifndef Grid_h
#define Grid_h

class Grid{
    public:
        //set number of rows and columns in grid x * y
        void setGridX(int xToSet);
        void setGridY(int yToSet);

        //get size of grid in x or y direction
        int getGridSizeX();
        int getGridSizeY();

        //get number of slots in grid
        int getSlots();

        // calculate x and y coordinates to move from position id
        void setMoveCoordinates(int position);

        //get calculated x or y coordinate
        int getXcoordinate();
        int getYcoordinate();

        // set column and row sizes in mm
        void setColumnWidth(int width);
        void setRowHeight(int height);

        //calculate distances in mm for coordinates
        int getDistanceToMoveX();
        int getDistanceToMoveY();

        void setStepsPerMillimeter(int steps);

    private:
        int gridSizeX;
        int gridSizeY;
        int xPosToMove;
        int yPosToMove;
        int columnWidth;
        int rowHeight;
        int stepsPerMillimeter;
        int slots;
};

#endif