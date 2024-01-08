#define GLM_ENABLE_EXPERIMENTAL
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <learnopengl/shader.h>
#include <learnopengl/model.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>


#include <irrklang/irrKlang.h>
using namespace irrklang;

ISoundEngine* SoundEngine = createIrrKlangDevice();

class Cube {
public:
    Cube(float size) : m_size(size) {
        float vertices[] = {
            -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f, -0.5f,  0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,

            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,

            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,

            -0.5f, -0.5f, -0.5f,
            0.5f, -0.5f, -0.5f,
            0.5f, -0.5f,  0.5f,
            0.5f, -0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f,  0.5f, -0.5f,
            0.5f,  0.5f, -0.5f,
            0.5f,  0.5f,  0.5f,
            0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f,
        };

        float normals[] = {
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,
            0.0f, 0.0f, -1.0f,

            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,
            0.0f, 0.0f, 1.0f,

            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,
            -1.0f, 0.0f, 0.0f,

            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.0f,

            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 0.0f,


            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
        };

        float textureCoords[] = {
            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,

            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,

            1.0f, 0.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,

            1.0f, 0.0f,
            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,

            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f,

            0.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 0.0f,
            0.0f, 1.0f
        };


        glGenBuffers(3, VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(textureCoords), textureCoords, GL_STATIC_DRAW);

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
    }
    Cube() : Cube(1.f) {
    }

    void Render() {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);
    }


    float m_size;
    unsigned int VAO;
    unsigned int VBO[3];
    //unsigned int EBO;
};



class Cylinder {
public:
    Cylinder(float radius, float height, float sectorCount) :
        m_radius(radius), m_height(height), m_sectorCount(sectorCount) {

        m_nVertice = (sectorCount + 1) * 2 + (sectorCount + 1 + 1) * 2;
        m_nIndices = sectorCount * 2 * 3 + sectorCount * 2 * 3 * 2;
        float* vertices = new float[m_nVertice * 3];
        float* normals = new float[m_nVertice * 3];
        float* texCoords = new float[m_nVertice * 2];
        int* indices = new int[m_nIndices];

        // lateral side
        float PI = 3.1415926;
        float sectorStep = 2 * PI / sectorCount;
        float sectorAngle = 0;
        int cnt = 0;
        float zArray[2] = { m_height, 0 };
        for (int i = 0; i < 2; ++i) {
            float z = zArray[i];
            for (int j = 0; j <= sectorCount; ++j) {
                sectorAngle = j * sectorStep;
                float x = m_radius * cos(sectorAngle);             // r * cos(v)
                float y = m_radius * sin(sectorAngle);             // r * sin(v)

                vertices[cnt * 3 + 0] = x;
                vertices[cnt * 3 + 1] = y;
                vertices[cnt * 3 + 2] = z;

                // normalized vertex normal (nx, ny, nz)
                normals[cnt * 3 + 0] = x / m_radius;
                normals[cnt * 3 + 1] = y / m_radius;
                normals[cnt * 3 + 2] = 0.f;

                // vertex tex coord (s, t) range between [0, 1]
                texCoords[cnt * 2 + 0] = (float)j / sectorCount;
                texCoords[cnt * 2 + 1] = z / m_height;


                cnt += 1;
            }
        }

        // top side
        {
            vertices[cnt * 3 + 0] = 0;
            vertices[cnt * 3 + 1] = 0;
            vertices[cnt * 3 + 2] = height;
            normals[cnt * 3 + 0] = 0.f;
            normals[cnt * 3 + 1] = 0.f;
            normals[cnt * 3 + 2] = 1.f;
            texCoords[cnt * 2 + 0] = 0.5f;
            texCoords[cnt * 2 + 1] = 0.5f;
            cnt += 1;
        }
        for (int j = 0; j <= sectorCount; ++j) {
            sectorAngle = j * sectorStep;
            float x = m_radius * cos(sectorAngle);             // r * cos(v)
            float y = m_radius * sin(sectorAngle);             // r * sin(v)

            vertices[cnt * 3 + 0] = x;
            vertices[cnt * 3 + 1] = y;
            vertices[cnt * 3 + 2] = height;

            // normalized vertex normal (nx, ny, nz)
            normals[cnt * 3 + 0] = 0.f;
            normals[cnt * 3 + 1] = 0.f;
            normals[cnt * 3 + 2] = 1.f;

            // vertex tex coord (s, t) range between [0, 1]
            texCoords[cnt * 2 + 0] = -(x / m_radius) * 0.5f + 0.5f;
            texCoords[cnt * 2 + 1] = -(y / m_radius) * 0.5f + 0.5f;
            cnt += 1;
        }


        // floor
        {
            vertices[cnt * 3 + 0] = 0;
            vertices[cnt * 3 + 1] = 0;
            vertices[cnt * 3 + 2] = 0;
            normals[cnt * 3 + 0] = 0.f;
            normals[cnt * 3 + 1] = 0.f;
            normals[cnt * 3 + 2] = -1.f;
            texCoords[cnt * 2 + 0] = 0.5f;
            texCoords[cnt * 2 + 1] = 0.5f;
            cnt += 1;
        }
        for (int j = 0; j <= sectorCount; ++j) {
            sectorAngle = j * sectorStep;
            float x = m_radius * cos(sectorAngle);             // r * cos(v)
            float y = m_radius * sin(sectorAngle);             // r * sin(v)

            vertices[cnt * 3 + 0] = x;
            vertices[cnt * 3 + 1] = y;
            vertices[cnt * 3 + 2] = 0;

            // normalized vertex normal (nx, ny, nz)
            normals[cnt * 3 + 0] = 0.f;
            normals[cnt * 3 + 1] = 0.f;
            normals[cnt * 3 + 2] = -1.f;

            // vertex tex coord (s, t) range between [0, 1]
            texCoords[cnt * 2 + 0] = -(x / m_radius) * 0.5f + 0.5f;
            texCoords[cnt * 2 + 1] = -(y / m_radius) * 0.5f + 0.5f;
            cnt += 1;
        }


        // k1 + 1  k2 + 1
        // k1      k2 
        int iCnt = 0;
        for (int j = 0; j < sectorCount; ++j) {
            int k1 = j;
            int k2 = (sectorCount + 1) + j;
            //k1 = > k2 = > k1 + 1
            indices[iCnt++] = k1;
            indices[iCnt++] = k2;
            indices[iCnt++] = k1 + 1;

            // k1+1 => k2 => k2+1
            indices[iCnt++] = k1 + 1;
            indices[iCnt++] = k2;
            indices[iCnt++] = k2 + 1;
        }


        for (int i = 0; i <= sectorCount; ++i) {
            indices[iCnt++] = (sectorCount + 1) * 2 + 0;
            indices[iCnt++] = (sectorCount + 1) * 2 + i;
            indices[iCnt++] = (sectorCount + 1) * 2 + i + 1;
        }

        for (int i = 0; i <= sectorCount; ++i) {
            indices[iCnt++] = (sectorCount + 1) * 2 + (sectorCount + 1 + 1) + 0;
            indices[iCnt++] = (sectorCount + 1) * 2 + (sectorCount + 1 + 1) + i;
            indices[iCnt++] = (sectorCount + 1) * 2 + (sectorCount + 1 + 1) + i + 1;
        }



        glGenBuffers(3, VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * m_nVertice, vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * m_nVertice, normals, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2 * m_nVertice, texCoords, GL_STATIC_DRAW);


        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_nIndices, indices, GL_STATIC_DRAW);

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
    }
    Cylinder() : Cylinder(1.f, 1, 32) {
    }


    void Render() {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, m_nIndices, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }


    int m_nVertice;
    int m_nIndices;
    float m_radius;
    float m_height;
    int m_sectorCount;
    unsigned int VAO;
    unsigned int VBO[3];
    unsigned int EBO;
};




class Sphere {
public:
    Sphere(float radius, float sectorCount, float stackCount) : m_radius(radius), m_sectorCount(sectorCount), m_stackCount(stackCount) {
        std::vector<float> vertices;
        std::vector<float> normals;
        std::vector<float> texCoords;
        std::vector<unsigned int> indices;

        float PI = 3.1415926;
        float sectorStep = 2.f * PI / sectorCount;
        float stackStep = PI / stackCount;
        float sectorAngle = 0;
        float stackAngle = 0;
        for (int i = 0; i <= stackCount; ++i) {
            stackAngle = PI / 2 - i * stackStep;
            float xy = m_radius * cos(stackAngle);             // r * cos(u)
            float z = m_radius * sin(stackAngle);              // r * sin(u)
            for (int j = 0; j <= sectorCount; ++j) {
                sectorAngle = j * sectorStep;

                float x = xy * cos(sectorAngle);             // r * cos(u) * cos(v)
                float y = xy * sin(sectorAngle);             // r * cos(u) * sin(v)

                // vertex position (x, y, z)
                vertices.push_back(x);
                vertices.push_back(y);
                vertices.push_back(z);

                // normalized vertex normal (nx, ny, nz)
                normals.push_back(x / m_radius);
                normals.push_back(y / m_radius);
                normals.push_back(z / m_radius);

                // vertex tex coord (s, t) range between [0, 1]
                float s = (float)j / sectorCount;
                float t = (float)i / stackCount;
                texCoords.push_back(s);
                texCoords.push_back(t);
            }
        }

        int k1, k2;
        for (int i = 0; i < stackCount; ++i) {
            k1 = i * (sectorCount + 1);     // beginning of current stack
            k2 = k1 + sectorCount + 1;      // beginning of next stack

            for (int j = 0; j < sectorCount; ++j, ++k1, ++k2) {
                // k1 => k2 => k1+1

                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);


                // k1+1 => k2 => k2+1
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);

            }
        }

        m_nVertice = vertices.size();
        m_nIndices = indices.size();

        glGenBuffers(3, VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * normals.size(), normals.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * texCoords.size(), texCoords.data(), GL_STATIC_DRAW);


        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
    }


    Sphere() : Sphere(1.f, 32, 32) {
    }

    void Render() {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, m_nIndices, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }


    int m_nVertice;
    int m_nIndices;
    float m_radius;
    int m_sectorCount;
    int m_stackCount;
    unsigned int VAO;
    unsigned int VBO[3];
    unsigned int EBO;
};


unsigned int planeVAO;
unsigned int planeVBO;
void RenderPlane() {
    if (planeVAO == 0) {
        float planeVertices[] = {
            // positions            // normals         // texcoords
             10.f,  -0.11f,  10.f,  0.0f, 1.0f, 0.0f,  10.f,  0.0f,
            -10.f,  -0.11f,  10.f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
            -10.f,  -0.11f, -10.f,  0.0f, 1.0f, 0.0f,   0.0f, 10.f,

             10.f,  -0.11f,  10.f,  0.0f, 1.0f, 0.0f,  10.f,  0.0f,
            -10.f,  -0.11f, -10.f,  0.0f, 1.0f, 0.0f,   0.0f, 10.f,
             10.f,  -0.11f, -10.f,  0.0f, 1.0f, 0.0f,  10.f, 10.f
        };
        glGenVertexArrays(1, &planeVAO);
        glGenBuffers(1, &planeVBO);
        glBindVertexArray(planeVAO);
        glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glBindVertexArray(0);
    }

    glBindVertexArray(planeVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
unsigned int loadTexture(const char* path);


// settings
const unsigned int SCR_WIDTH = 1200;
const unsigned int SCR_HEIGHT = 800;


Cube* pCubeUnit;
Cylinder* pCylinderUnit;
Sphere* pSphereUnit;

float angle1 = 0;
float angle2 = 0;

// camera
float Zoom = 40.f;
glm::vec3 camPos(0, 3, 8);

glm::vec3 lightPos(0.0f);
// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;
unsigned int texVec[6];

bool openUp = false;
bool openDown = false;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Opengl", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetScrollCallback(window, scroll_callback);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    glEnable(GL_DEPTH_TEST);


    Shader* pShader;
    Shader baseShader("shaders/baseShader.vs", "shaders/baseShader.fs");
    Shader shader("shaders/shader.vs", "shaders/shader.fs");
    pShader = &baseShader;

    stbi_set_flip_vertically_on_load(true);
    texVec[0] = loadTexture("wood.png");
    texVec[1] = loadTexture("watermelon.jpg");
    texVec[2] = loadTexture("kola.jpg");
    texVec[3] = loadTexture("iceCreame.jpg");
    texVec[4] = loadTexture("xc.jpg");

    
    stbi_set_flip_vertically_on_load(false);
    Model houseModel("model/food/food.obj");
    pCubeUnit = new Cube();
    pCylinderUnit = new Cylinder(0.2, 0.4, 32);
    pSphereUnit = new Sphere(0.5, 32, 32);
  

    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);


        // render
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        shader.use();


        glm::mat4 projection(1.0f);
        glm::mat4 view = glm::lookAt(glm::vec3(0, 3, 8), glm::vec3(0, 2, 0), glm::vec3(0, 1, 0));
        projection = glm::perspective(glm::radians(Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);


        lightPos = glm::vec3(1, 3, 3);

        shader.setMat4("projection", projection);
        shader.setMat4("view", view);
        // set light uniforms
        shader.setVec3("viewPos", camPos);

        shader.setVec3("pointLight.position", lightPos);
        shader.setVec3("pointLight.ambient", 0.3f, 0.3f, 0.3f);
        shader.setVec3("pointLight.diffuse", 1.0f, 1.0f, 1.0f);
        shader.setVec3("pointLight.specular", 1.0f, 1.0f, 1.0f);
        shader.setFloat("pointLight.constant", 1.0f);
        shader.setFloat("pointLight.linear", 0.05);
        shader.setFloat("pointLight.quadratic", 0.008);


        // floor
        glm::mat4 model = glm::mat4(1.0f);
        shader.setMat4("model", model);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texVec[0]);
        RenderPlane();

        if (openUp) {
            angle1 += deltaTime * 80;
            if (angle1 > 180) {
                angle1 = 180;
            }
        }
        else {
            angle1 -= deltaTime * 80;
            if (angle1 < 0) {
                angle1 = 0;
            }
        }

        if (openDown) {
            angle2 += deltaTime * 80;
            if (angle2 > 180) {
                angle2 = 180;
            }
        }
        else {
            angle2 -= deltaTime * 80;
            if (angle2 < 0) {
                angle2 = 0;
            }
        }

        {
            pShader->use();
            pShader->setMat4("projection", projection);
            pShader->setMat4("view", view);
            // set light uniforms
            pShader->setVec3("viewPos", camPos);
            pShader->setBool("isDark", true);

            pShader->setVec3("pointLight.position", lightPos);
            pShader->setVec3("pointLight.ambient", 0.3f, 0.3f, 0.3f);
            pShader->setVec3("pointLight.diffuse", 1.0f, 1.0f, 1.0f);
            pShader->setVec3("pointLight.specular", 1.0f, 1.0f, 1.0f);
            pShader->setFloat("pointLight.constant", 1.0f);
            pShader->setFloat("pointLight.linear", 0.05);
            pShader->setFloat("pointLight.quadratic", 0.008);


            pShader->setVec3("Color", glm::vec3(238 / 255.f, 229 / 255.f, 222 / 255.f));

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0, 0.0, 0));
            model = glm::scale(model, glm::vec3(1.6, 0.1, 1.8));
            pShader->setMat4("model", model);
            pCubeUnit->Render();


            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0, 1.6, 0));
            model = glm::scale(model, glm::vec3(1.6, 0.12, 1.8));
            pShader->setMat4("model", model);
            pCubeUnit->Render();

            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0, 3.6, 0));
            model = glm::scale(model, glm::vec3(1.6, 0.1, 1.8));
            pShader->setMat4("model", model);
            pCubeUnit->Render();


            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(-0.8, 1.8, 0));
            model = glm::scale(model, glm::vec3(0.1, 3.7, 1.8));
            pShader->setMat4("model", model);
            pCubeUnit->Render();

            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.8, 1.8, 0));
            model = glm::scale(model, glm::vec3(0.1, 3.7, 1.8));
            pShader->setMat4("model", model);
            pCubeUnit->Render();


            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0, 1.8, -0.9));
            model = glm::scale(model, glm::vec3(1.6, 3.7, 0.1));
            pShader->setMat4("model", model);
            pCubeUnit->Render();


            //divider
            pShader->setVec3("Color", glm::vec3(250 / 255.f, 250 / 255.f, 250 / 255.f));

            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0, 2.8, 0));
            model = glm::scale(model, glm::vec3(1.5, 0.03, 1.8));
            pShader->setMat4("model", model);
            pCubeUnit->Render();

            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0, 2.2, 0));
            model = glm::scale(model, glm::vec3(1.5, 0.03, 1.8));
            pShader->setMat4("model", model);
            pCubeUnit->Render();



            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0, 0.8, 0));
            model = glm::scale(model, glm::vec3(1.5, 0.03, 1.8));
            pShader->setMat4("model", model);
            pCubeUnit->Render();


            // watermelon
            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.3, 3.1, 0));
            model = glm::rotate(model, glm::radians(90.f), glm::vec3(1, 0, 0));
            model = glm::scale(model, glm::vec3(0.6, 0.6, 0.6));
            shader.use();
            shader.setMat4("model", model);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texVec[1]);
            pSphereUnit->Render();
            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(-0.3, 3.1, 0));
            model = glm::rotate(model, glm::radians(90.f), glm::vec3(1, 0, 0));
            model = glm::scale(model, glm::vec3(0.6, 0.6, 0.6));
            shader.use();
            shader.setMat4("model", model);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texVec[1]);
            pSphereUnit->Render();



            // cola
            for (int i = -4; i <= 4; ++i) {
                model = glm::mat4(1.0f);
                model = glm::translate(model, glm::vec3(i * 0.165, 1.66, 0.5));
                model = glm::scale(model, glm::vec3(0.4, 0.8, 0.4));
                model = glm::rotate(model, glm::radians(i * 30.f), glm::vec3(0, 1, 0));
                model = glm::rotate(model, glm::radians(-90.f), glm::vec3(1, 0, 0));
                shader.setMat4("model", model);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, texVec[2]);
                pCylinderUnit->Render();
            }


            // ice cream box
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texVec[3]);
            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(-0.4, 1.18, -0.2));
            model = glm::scale(model, glm::vec3(0.7, 0.7, 1.6));
            shader.setMat4("model", model);
            pCubeUnit->Render();

            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.4, 0.4, -0.2));
            model = glm::scale(model, glm::vec3(0.7, 0.7, 1.6));
            shader.setMat4("model", model);
            pCubeUnit->Render();


            pShader->use();
            // Under the fridge door
            glm::mat4 modelRotate2 = glm::mat4(1.f);
            modelRotate2 = glm::translate(modelRotate2, glm::vec3(0.8, 0, 0.9));
            modelRotate2 = glm::rotate(modelRotate2, glm::radians(angle2), glm::vec3(0, 1, 0));
            modelRotate2 = glm::translate(modelRotate2, glm::vec3(-0.8, 0, 0));

            pShader->setVec3("Color", glm::vec3(255 / 255.f, 228 / 255.f, 196 / 255.f));
            model = glm::mat4(1.0f);
            model = model * modelRotate2;
            model = glm::translate(model, glm::vec3(0, 0.79, 0.0));
            model = glm::scale(model, glm::vec3(1.6, 1.58, 0.1));
            pShader->setMat4("model", model);
            pCubeUnit->Render();


            //// grips
            pShader->setVec3("Color", glm::vec3(139 / 255.f, 137 / 255.f, 137 / 255.f));
            model = glm::mat4(1.0f);
            model = model * modelRotate2;
            model = glm::translate(model, glm::vec3(-0.7, 0.5, 0.1));
            model = glm::scale(model, glm::vec3(0.2, 2, 0.2));
            model = glm::rotate(model, glm::radians(-90.f), glm::vec3(1, 0, 0));
            pShader->setMat4("model", model);
            pCylinderUnit->Render();



            // on fridge door
            glm::mat4 modelRotate1 = glm::mat4(1.f);
            modelRotate1 = glm::translate(modelRotate1, glm::vec3(0.8, 2.63, 0.9));
            modelRotate1 = glm::rotate(modelRotate1, glm::radians(angle1), glm::vec3(0, 1, 0));
            modelRotate1 = glm::translate(modelRotate1, glm::vec3(-0.8, 0, 0));

            pShader->setVec3("Color", glm::vec3(255 / 255.f, 228 / 255.f, 196 / 255.f));
            model = glm::mat4(1.0f);
            model = model * modelRotate1;
            model = glm::scale(model, glm::vec3(1.6, 2.03, 0.1));
            pShader->setMat4("model", model);
            pCubeUnit->Render();


            // grips
            pShader->setVec3("Color", glm::vec3(139 / 255.f, 137 / 255.f, 137 / 255.f));
            model = glm::mat4(1.0f);
            model = model * modelRotate1;
            model = glm::translate(model, glm::vec3(-0.7, -0.8, 0.1));
            model = glm::scale(model, glm::vec3(0.2, 2, 0.2));
            model = glm::rotate(model, glm::radians(-90.f), glm::vec3(1, 0, 0));
            pShader->setMat4("model", model);
            pCylinderUnit->Render();

            shader.use();
            model = glm::mat4(1.0f);
            model = model * modelRotate1;
            model = glm::translate(model, glm::vec3(0, 0.4, 0.1));
            model = glm::scale(model, glm::vec3(0.8, 0.8, 0.05));
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texVec[4]);
            shader.setMat4("model", model);
            pCubeUnit->Render();



        }



        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}















static float viewSpeed = 2;
void processInput(GLFWwindow* window)
{
    static std::vector<int> last_key(128, GLFW_RELEASE);
    int curr_key = 0;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    

    curr_key = glfwGetKey(window, GLFW_KEY_Q);
    if (GLFW_RELEASE == last_key[GLFW_KEY_Q] && GLFW_PRESS == curr_key) {
        
        SoundEngine->play2D("open.wav", false);
        openUp = true;
    }
    last_key[GLFW_KEY_Q] = curr_key;

    curr_key = glfwGetKey(window, GLFW_KEY_W);
    if (GLFW_RELEASE == last_key[GLFW_KEY_W] && GLFW_PRESS == curr_key) {
        SoundEngine->play2D("open.wav", false);
        openUp = false;
    }

    last_key[GLFW_KEY_W] = curr_key;

    curr_key = glfwGetKey(window, GLFW_KEY_A);
    if (GLFW_RELEASE == last_key[GLFW_KEY_A] && GLFW_PRESS == curr_key) {

        SoundEngine->play2D("open.wav", false);
        openDown = true;
    }
    last_key[GLFW_KEY_A] = curr_key;

    curr_key = glfwGetKey(window, GLFW_KEY_S);
    if (GLFW_RELEASE == last_key[GLFW_KEY_S] && GLFW_PRESS == curr_key) {
        SoundEngine->play2D("open.wav", false);
        openDown = false;
    }

    last_key[GLFW_KEY_S] = curr_key;


}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}



// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (Zoom >= 1.0f && Zoom <= 60.f)
        Zoom -= yoffset;
    if (Zoom <= 1.0f)
        Zoom = 1.0f;
    if (Zoom >= 60.f)
        Zoom = 60.f;
}



// utility function for loading a 2D texture from file
// ---------------------------------------------------
unsigned int loadTexture(char const* path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT); // for this tutorial: use GL_CLAMP_TO_EDGE to prevent semi-transparent borders. Due to interpolation it takes texels from next repeat 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}
