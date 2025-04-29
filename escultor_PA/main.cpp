#include <iostream>
#include "sculptor.h"

int main()
{
    Sculptor arvore(3,6,3);
    arvore.setColor(0.45,0.17,0.17,1);
    arvore.putBox(1,1,0,5,1,1);
    arvore.setColor(0,1,0,1);
    arvore.putBox(0,2,3,5,0,2);
    arvore.cutVoxel(0,5,0);
    arvore.cutVoxel(2,5,2);
    arvore.cutVoxel(2,5,0);
    arvore.cutVoxel(0,5,2);
    arvore.writeOFF("arv.OFF");


    Sculptor boneco_de_neve(51,121,55);
    boneco_de_neve.setColor(1,1,1,1);
    boneco_de_neve.putSphere(25,25,25,25);
    boneco_de_neve.putSphere(25,60,25,20);
    boneco_de_neve.putSphere(25,90,25,15);
    boneco_de_neve.setColor(0,0,0,1);
    boneco_de_neve.putBox(24,26,24,26,50,50);
    boneco_de_neve.putBox(24,26,59,61,45,45);
    boneco_de_neve.putBox(18,20,92,94,38,38);
    boneco_de_neve.putBox(30,32,92,94,38,38);
    boneco_de_neve.putEllipsoid(25,100,25,17,1,17);
    boneco_de_neve.setColor(1,0,0,1);
    for(int i=101;i<120;i++){
        if(i==105){
            boneco_de_neve.setColor(0,0,0,1);
        }
        boneco_de_neve.putEllipsoid(25,i,25,13,1,13);
    }

    boneco_de_neve.setColor(1,0.4,0,1);
    boneco_de_neve.putEllipsoid(25,88,38,3,3,15);

    boneco_de_neve.cutSphere(25,25,25,23);
    boneco_de_neve.cutSphere(25,60,25,18);
    boneco_de_neve.cutSphere(25,90,25,13);
    for(int i=100;i<119;i++){
        boneco_de_neve.cutEllipsoid(25,i,25,11,1,11);
    }
    boneco_de_neve.cutEllipsoid(25,88,38,2,2,13);
    boneco_de_neve.writeOFF("boneco_neve.OFF");

    return 0;
}
