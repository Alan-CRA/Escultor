#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
    float r,g,b; // Cores
    float a; // Trasnparencia
    bool show; // Incluido ou nao
};

class Sculptor {
private:
    Voxel ***v; // 3D matrix
    int nx,ny,nz; // Dimensions
    float r,g,b,a; // Current drawing color
public:
    Sculptor(int _nx, int _ny, int _nz); // Construtor Voxel
    ~Sculptor(); // Destrutor Voxel
    void setColor(float r, float g, float b, float a); // Mudar cor Voxel
    void putVoxel(int x, int y, int z); // Colocar Voxel na posição x,y,z
    void cutVoxel(int x, int y, int z); // Retirar Voxel na posição x,y,z
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); // Colocar Voxel nos intervalos [x0,x1], [y0,y1] e [z0,z1]
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); // Retirar Voxel nos intervalos [x0,x1], [y0,y1] e [z0,z1]
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); // Colocar Voxel para preencher esfera de centro x,y,z e raio r
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); // Retirar Voxel para preencher esfera de centro x,y,z e raio r
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Colocar Voxel para preencher elipse  de centro x,y,z e raios rx,ry,rz
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Retirar Voxel para preencher elipse  de centro x,y,z e raios rx,ry,rz
    void writeOFF(const char* filename); // Exportar arquivo OFF
};

#endif // SCULPTOR_H
