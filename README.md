#OpenGL Base
A simple project that provides some util functions and third party librararies that you can just clone and write some OpenGL code.
##License
OpenGL Base is under the MIT license. For full license text see LICENCE.txt
##Building
OpenGL Base uses premake as build system.
For Windows and Visual Studio just run the file GenProjectsVS2019.bat
For other Platforms run the following command to generate a project for your preferred build system:

    premake5 <project-type>

premake5 allows your to generate project files for a number of build systems: Visual Studio, GNU Make, Xcode, Code::Blocks, and more across Windows, Mac OS X, and Linux
Once the projects have generated without errors, you may use them to build the project.
##Third Party Libraries
* [Premake5](https://premake.github.io/) 
* [GLFW](http://www.glfw.org/)
* [Glad](https://glad.dav1d.de/)
* [GLM](http://glm.g-truc.net/)
* [ImGui](https://github.com/ocornut/imgui) 
* [stb_image](https://github.com/nothings/stb)