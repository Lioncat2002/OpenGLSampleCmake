#include <iostream>
#include "glad.h"
#include "GLFW/glfw3.h"
#include "starlight.h"

GLFWwindow *window;

const int WINDOW_WIDTH=1024;
const int WINDOW_HEIGHT=768;

starlight::Loader *loader;
starlight::Renderer *renderer;
starlight::RawModel model;

float vertices[]={
        //left bottom triangle
        -0.5f,0.5f,0.0f,
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        //right top triangle
        0.5f,-0.5f,0.0f,
        0.5f,0.5f,0.0f,
        -0.5f,0.5f,0.0f
};

int init(){
    if(!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    window= glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"game", nullptr, nullptr);

    if(!window){
        std::cout<<"Failed to create window\n";
        glfwTerminate();

        return false;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        std::cout<<"Failed to initialize GLAD\n";
        return false;
    }

    //glClearColor(0.6f,0.8f,1.0f,1.0f);
    glViewport(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);

    glEnable(GL_DEPTH_TEST);
    return true;
}

int load(){
    loader=new starlight::Loader();
    renderer=new starlight::Renderer();
    int length=sizeof(vertices)/sizeof(vertices[0]);
    model=loader->loadToVao(vertices,length);
    return true;
}
int render(){
    renderer->prepare();
    renderer->render(model);
    return true;
}
int update(){
    while(!glfwWindowShouldClose(window)){
        render();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    return true;
}

int main(){
    if(!init())
        return -1;

    if(!load())
        return -1;

    update();
    glfwTerminate();
    delete loader;
    delete renderer;

    return 0;
}