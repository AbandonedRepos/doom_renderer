#ifndef RENDER_TREE_H
#define RENDER_TREE_H

#include <map>
#include <string>
#include <glad/glad.h>
#include <vector>
#include "rendernode.h"
#include "doom_data.h"
#include "shader.h"
#include "plane_renderer.h"

class RenderTree

{
    public:
        RenderTree(Shader *line_shader_, Shader *plane_shader_); 
        ~RenderTree();
        void setRootNode(RenderNode *root);
        void trasversalOrderPrintContent();
        bool isRootNodeNull();
        void render(); //It uses its children to do polygon substraction
        RenderNode *root_node;
        Shader* line_shader;
        Shader* plane_shader;
        PlaneRenderer* plane_renderer;
    private:
        void postOrderRendering(RenderNode* node, RenderNode* parent);
};

#endif