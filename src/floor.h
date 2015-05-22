#ifndef FLOOR_H
#define FLOOR_H

#define FLOOR_SHAPE 1

#include <iostream>
#include <glm/glm.hpp>
#include <string>
#include "shape.h"
#include "sgct.h"


class Floor : public Shape {

public:
    // Constructors
    Floor(glm::vec3, float, const std::string&, bool is = true);
    // Add constructor with custom material

    // Member functions
    void draw(glm::mat4&, glm::mat4&, glm::mat4&, glm::mat3&, unsigned int);
    void init(glm::vec3);

    void reset();

    void createVertices();
    void createFaceNormals();
    void createVertexNormals();
    void createUVs();
    void setup1();

    void integrateVelocity(const glm::vec3, float);
    void applyG(const glm::vec3, float);
    void applySpringForce(float, float);

    // Getters
    unsigned int getType() { return FLOOR_SHAPE; };
    glm::vec3 getPosition() { return this->position; };
    
    // Setters
    void setBodyStatic(int index) { _isStatic = true; };
    void setWindForce(glm::vec3 w_f) {};
    void setPosition(glm::vec3 p) { position = p; };

private:
    glm::vec3 position;
    glm::vec3 velocity;
    float size;
    bool _isStatic;

    // Data for OpenGL
    std::vector<glm::vec3> mVertices;
    std::vector<glm::vec3> mFaceNormals;
    std::vector<glm::vec3> mVertexNormals;
    std::vector<glm::vec2> mUvs;

    std::string textureName;
    GLuint vertexArray;
    GLuint vertexPositionBuffer;
    GLuint normalCoordBuffer;
    GLuint texCoordBuffer;

    // Shader data
    GLint MVPLoc;
    GLint MVLoc;
    GLint MVLightLoc;
    GLint NMLoc;
    GLint lightPosLoc;
    GLint lightAmbLoc;
    GLint lightDifLoc;
    GLint lightSpeLoc;

    // Material data
    glm::vec4 ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;

    size_t texHandle;
};

#endif // FLOOR_H