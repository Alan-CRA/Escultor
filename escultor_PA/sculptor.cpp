#include "sculptor.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h>

Sculptor::Sculptor(int nx, int ny, int nz) {
    this->nx=nx;
    this->ny=ny;
    this->nz=nz;

    v=new Voxel** [nx];
    v[0]=new Voxel* [nx*ny];
    v[0][0]=new Voxel [nx*ny*nz];

    for(int i=1;i<nx;i++){
        v[i]=v[i-1]+ny;
    }

    for(int i=1;i<ny*nx;i++){
        v[0][i]=v[0][i-1]+nz;
    }

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                v[i][j][k].show=false;
            }
        }
    }
}

Sculptor::~Sculptor(){
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z){
    if (x<0 || y<0 || z<0 || x>nx || y>ny || z>nz){
        std::cout << "Posicao Invalida" <<std::endl;
    }
    else{
        v[x][y][z].show=true;
        v[x][y][z].r=r;
        v[x][y][z].g=g;
        v[x][y][z].b=b;
        v[x][y][z].a=a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z){
    if (x<0|| y<0|| z<0|| x>nx || y>ny || z>nz){
        std::cout << "Posicao Invalida" <<std::endl;
    }
    else {
        v[x][y][z].show=false;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    if(x0<0 || y0<0 || z0<0 || x1>nx || y1>ny || z1>nz || x0>x1 || y0>y1 || z0>z1){
        std::cout << "Posicao Invalida" <<std::endl;
    }
    else{
        for(int i=x0;i<=x1;i++){
            for(int j=y0;j<=y1;j++){
                for(int k=z0;k<=z1;k++){
                    v[i][j][k].show=true;
                    v[i][j][k].r=r;
                    v[i][j][k].g=g;
                    v[i][j][k].b=b;
                    v[i][j][k].a=a;
                }
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    if(x0<0 || y0<0 || z0<0 || x1>nx || y1>ny || z1>nz || x0>x1 || y0>y1 || z0>z1){
        std::cout << "Posicao Invalida" <<std::endl;
    }
    else{
        for(int i=x0;i<=x1;i++){
            for(int j=y0;j<=y1;j++){
                for(int k=z0;k<=z1;k++){
                    v[i][j][k].show=false;
                }
            }
        }
    }
}


void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    if(radius <0 || xcenter-radius<0 || ycenter-radius<0 || zcenter-radius<0 || xcenter+radius>nx || ycenter+radius>ny || zcenter+radius>nz){
        std::cout << "Posicao Invalida" <<std::endl;
    }
    else{
        for(int i=xcenter-radius;i<xcenter+radius;i++){
            for(int j=ycenter-radius;j<ycenter+radius;j++){
                for(int k=zcenter-radius;k<zcenter+radius;k++){
                    if((pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2))<= pow(radius,2)){
                        v[i][j][k].show=true;
                        v[i][j][k].r=r;
                        v[i][j][k].g=g;
                        v[i][j][k].b=b;
                        v[i][j][k].a=a;

                    }

                }
            }
        }
    }

}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    if(radius <0 || xcenter-radius<0 || ycenter-radius<0 || zcenter-radius<0 || xcenter+radius>nx || ycenter+radius>ny || zcenter+radius>nz){
        std::cout << "Posicao Invalida" <<std::endl;
    }
    else{
        for(int i=xcenter-radius;i<xcenter+radius;i++){
            for(int j=ycenter-radius;j<ycenter+radius;j++){
                for(int k=zcenter-radius;k<zcenter+radius;k++){
                    if((pow(i-xcenter,2)+pow(j-ycenter,2)+pow(k-zcenter,2))<= pow(radius,2)){
                        v[i][j][k].show=false;
                    }
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    if(rx<0 || ry<0 || rz<0 || xcenter-rx<0 || ycenter-ry<0 || zcenter-rz<0 || xcenter+rx>nx || ycenter+ry>ny || zcenter+rz>nz){
        std::cout << "Posicao Invalida" <<std::endl;
    }
    else{
        for(int i=xcenter-rx;i<xcenter+rx;i++){
            for(int j=ycenter-ry;j<ycenter+ry;j++){
                for(int k=zcenter-rz;k<zcenter+rz;k++){
                    if((pow((i-xcenter)*ry*rz,2)+pow((j-ycenter)*rx*rz,2)+pow((k-zcenter)*rx*ry,2))<=pow(rx*ry*rz,2)){
                        v[i][j][k].show=true;
                        v[i][j][k].r=r;
                        v[i][j][k].g=g;
                        v[i][j][k].b=b;
                        v[i][j][k].a=a;
                    }
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    if(rx<0 || ry<0 || rz<0 || xcenter-rx<0 || ycenter-ry<0 || zcenter-rz<0 || xcenter+rx>nx || ycenter+ry>ny || zcenter+rz>nz){
        std::cout << "Posicao Invalida" <<std::endl;
    }
    else{
        for(int i=xcenter-rx;i<xcenter+rx;i++){
            for(int j=ycenter-ry;j<ycenter+ry;j++){
                for(int k=zcenter-rz;k<zcenter+rz;k++){
                    if((pow((i-xcenter)*ry*rz,2)+pow((j-ycenter)*rx*rz,2)+pow((k-zcenter)*rx*ry,2))<=pow(rx*ry*rz,2)){
                        v[i][j][k].show=false;
                    }
                }
            }
        }
    }

}

void Sculptor::writeOFF(const char* filename){
    std::ofstream fout;
    int i,j,k,i0,j0,k0,v1=0,nVoxels=0;
    fout.open(filename);
    if (!fout.is_open()) {
        exit(1);
    }
    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if(v[i][j][k].show){
                    nVoxels++;
                }
            }
        }
    }
    fout << "OFF\n";

    fout << 8*nVoxels << " " << 6*nVoxels << " 0\n";

    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if(v[i][j][k].show ){
                    for(i0=i;i0<=i+1;i0++){
                        for(j0=j;j0<=j+1;j0++){
                            for(k0=k;k0<=k+1;k0++){
                                fout << i0 << " " << j0 << " " << k0 << " \n";
                            }
                        }
                    }
                }
            }
        }
    }

    for(i=0;i<nx;i++){
        for(j=0;j<ny;j++){
            for(k=0;k<nz;k++){
                if(v[i][j][k].show ){
                    if (v[i][j][k].r<=1 && v[i][j][k].g<=1 && v[i][j][k].b<=1){
                        v[i][j][k].r=(int) (v[i][j][k].r*255);
                        v[i][j][k].g=(int) (v[i][j][k].g*255);
                        v[i][j][k].b=(int) (v[i][j][k].b*255);
                    }
                    fout << "4 "<< v1+0 << " " << v1+1 << " " << v1+3 << " " << v1+2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 "<< v1+4 << " " << v1+5 << " " << v1+7 << " " << v1+6 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 "<< v1+0 << " " << v1+2 << " " << v1+6 << " " << v1+4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 "<< v1+1 << " " << v1+5 << " " << v1+7 << " " << v1+3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 "<< v1+2 << " " << v1+3 << " " << v1+7 << " " << v1+6 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    fout << "4 "<< v1+0 << " " << v1+1 << " " << v1+5 << " " << v1+4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    v1=v1+8;
                }
            }
        }
    }

    fout.close();
    std::cout<<filename<<" Gerado"<<std::endl; // caso tenha sido printado um "posicao invalida", o arquivo apresentara erro
}
