#ifndef DOOM_MAP_H
#define DOOM_MAP_H

#include <map>
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#include "rendertree.h"
#include "resource_manager.h"
#include "doom_data.h"
#include "shader.h"

class DoomMap
{
    public:
        DoomMap();
        void addDirectionalLight(DirLight light);
        void addPointLight(PointLight light, int light_pos);
        bool addSectorToRenderTree(mapsector_t *sector);
        void update();
        void render();
    private:
        void compileSector(mapsector_t *sector, mapsector_t *parent); // Fills the null data on sidedefs
        void init(); // Inicializar arbol de renderizado
        int pnpoly(int nvert, mapvertex_t* vertices, mapvertex_t vertex);
        bool isSubsector(mapsector_t* parent, mapsector_t* son);
        RenderTree* render_tree;
        Shader* line_shader;
        Shader* plane_shader;
};

#endif