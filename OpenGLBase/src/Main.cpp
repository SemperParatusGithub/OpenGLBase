#include "Util/Shader.h"
#include "Util/Texture.h"
#include "Util/ImGuiUtil.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>


int main()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW!" << std::endl;
		return -1;
	}

	GLFWwindow *window;
	window = glfwCreateWindow(1280, 720, "Hello Window", nullptr, nullptr);

	if (!window)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize Glad!" << std::endl;
		return -1;
	}

	/* ImGui Setup */
	ImGuiUtil::ImGuiInit(window);

	ImGui::GetStyle().WindowMinSize = ImVec2 { 400.0f, 500.0f };
	ImGuiIO &io = ImGui::GetIO();
	ImFont *openSansRegular = io.Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Regular.ttf", 32.0f);
	ImFont *openSansBold = io.Fonts->AddFontFromFileTTF("res/fonts/OpenSans/OpenSans-Bold.ttf", 32.0f);
	io.FontDefault = openSansRegular;

	/* Square Color */
	float col[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	glClearColor(0.7f, 0.7f, 0.7f, 0.7f);
	glViewport(0, 0, 1280, 720);

	/* Vertices and Indices */
	float vertices[] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f, 0.5f
	};
	uint32_t indices[] = {
		0, 1, 2, 2, 3, 0
	};

	/* VertexArray */
	unsigned int va;
	glCreateVertexArrays(1, &va);
	glBindVertexArray(va);

	/* VertexBuffer */
	unsigned int vb;
	glCreateBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	/* IndexBuffer */
	unsigned int ib;
	glCreateBuffers(1, &ib);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	/* Set Position attribute */
	glEnableVertexArrayAttrib(va, 0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

	/* Shader */
	OpenGLBase::Shader shader(OpenGLBase::Shader::LoadFromGLSLFiles("res/shaders/Example.vert.glsl", "res/shaders/Example.frag.glsl"));

	while (!glfwWindowShouldClose(window))
	{
		ImGuiUtil::ImGuiNewFrame();

		glfwPollEvents();
		glfwSwapBuffers(window);

		glClear(GL_COLOR_BUFFER_BIT);

		shader.Bind();
		shader.SetUniform4f("u_Color", col[0], col[1], col[2], col[3]);
		glBindVertexArray(va);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		ImGui::PushFont(openSansBold);
		ImGui::Begin("Settings");
		ImGui::PushFont(openSansRegular);
		ImGui::SetNextItemWidth(ImGui::GetWindowSize().x * 2.f / 3.25f);
		ImGui::ColorPicker4("Square color", col);
		ImGui::PopFont();
		ImGui::PopFont();
		ImGui::End();

		ImGuiUtil::ImGuiRender();
	}

	ImGuiUtil::ImGuiShutdown();
	return 0;
}