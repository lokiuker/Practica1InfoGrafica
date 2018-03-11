#include <imgui\imgui.h>
#include <imgui\imgui_impl_sdl_gl3.h>

bool show_test_window = false;

int EmiterRate = 1000;
int particleLife = 3000;
int CpaX = 4000;
int CpaY = 6000;
int CpaZ = 4000;
int Tab;
int test;
bool PlayProgram = false;//nuevo

void GUI() {
	bool show = true;
	ImGui::Begin("Simulation Parameters", &show, 0);
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	/*ImGui::Checkbox("Play simulaton", &PlayProgram);//Caja onclic
	if (ImGui::Button("Reset simulation", ImVec2(120, 20)))//boton para reiniciar todo por defecto
	{
		//reset all
	}
	//Emiter, creamos el arbol
	if (ImGui::TreeNode("Emiter"))
	{
		ImGui::TreePop();
		ImGui::SliderInt("Emiter Rate", &EmiterRate, 0.f, 1000.f);//caja de texto con barra para mover
		ImGui::SliderInt("particle Life", &particleLife, 0.f, 3000.f);
		//Fountain and Cascade MarcButtons
		if (ImGui::RadioButton("Fountain", &test, 0))//mini boton de seleccion circular
		{
			Tab = 1;
		}ImGui::SameLine();
		if (ImGui::RadioButton("Cascade", &test, 1))//mini boton de seleccion circular
		{
			Tab = 2;
		}
		//Mostrar valores de cada uno
		switch (Tab)
		{
		case 1:
		{
			ImGui::BeginChildFrame(1, ImVec2(120, 25));	//Lo hago con child frame para poder ponerle un tamaño a cada uno y ponerlos en la misma linea
			ImGui::InputInt("", &CpaX, 0.f, 100.f);//100.f es el max valor, cambiar por nombre/variable.
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::BeginChildFrame(2, ImVec2(120, 25));
			ImGui::InputInt("", &CpaY, 0.f, 100.f);//caja de texto para modificar a mano
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::BeginChildFrame(3, ImVec2(120, 25));
			ImGui::InputInt("", &CpaZ, 0.f, 100.f);
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::Text("Fountain Position");
			ImGui::BeginChildFrame(4, ImVec2(120, 25));
			ImGui::InputInt("", &CpaX, 0.f, 100.f);//100.f es el max valor, cambiar por nombre/variable.
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::BeginChildFrame(5, ImVec2(120, 25));
			ImGui::InputInt("", &CpaY, 0.f, 100.f);//caja de texto para modificar a mano
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::BeginChildFrame(6, ImVec2(120, 25));
			ImGui::InputInt("", &CpaZ, 0.f, 100.f);
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::Text("Fountain Velocity");
		}
		break;
		case 2:
		{
			ImGui::BeginChildFrame(1, ImVec2(120, 25));
			ImGui::InputInt("", &CpaX, 0.f, 100.f);//100.f es el max valor, cambiar por nombre/variable.
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::BeginChildFrame(2, ImVec2(120, 25));
			ImGui::InputInt("", &CpaY, 0.f, 100.f);//caja de texto para modificar a mano
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::BeginChildFrame(3, ImVec2(120, 25));
			ImGui::InputInt("", &CpaZ, 0.f, 100.f);
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::Text("Cascade Position");
			ImGui::BeginChildFrame(4, ImVec2(120, 25));
			ImGui::InputInt("", &CpaX, 0.f, 100.f);//100.f es el max valor, cambiar por nombre/variable.
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::BeginChildFrame(5, ImVec2(120, 25));
			ImGui::InputInt("", &CpaY, 0.f, 100.f);//caja de texto para modificar a mano
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::BeginChildFrame(6, ImVec2(120, 25));
			ImGui::InputInt("", &CpaZ, 0.f, 100.f);
			ImGui::EndChildFrame(); ImGui::SameLine();
			ImGui::Text("Cascade Velocity");
		}
		break;
		}
	}
	//Elasticity, creamos el arbol
	if (ImGui::TreeNode("Elasticity & Friction"))
	{
		ImGui::TreePop();//imprescindible para que no pete!!!!!
		ImGui::SliderInt("Elastic Coefficient", &EmiterRate, 0.f, 1000.f);//cambiar variables Emiterrate, particleLife
		ImGui::SliderInt("Friction Coefficient", &particleLife, 0.f, 3000.f);
	}
	if (ImGui::TreeNode("Colliders"))
	{
		ImGui::TreePop();
		ImGui::Checkbox("Use Sphere Collider", &PlayProgram); // cambiar variables
		ImGui::BeginChildFrame(7, ImVec2(120, 25));
		ImGui::InputInt("", &CpaX, 0.f, 100.f);//100.f es el max valor, cambiar por nombre/variable.
		ImGui::EndChildFrame(); ImGui::SameLine();
		ImGui::BeginChildFrame(8, ImVec2(120, 25));
		ImGui::InputInt("", &CpaY, 0.f, 100.f);//caja de texto para modificar a mano
		ImGui::EndChildFrame(); ImGui::SameLine();
		ImGui::BeginChildFrame(9, ImVec2(120, 25));
		ImGui::InputInt("", &CpaZ, 0.f, 100.f);
		ImGui::EndChildFrame(); ImGui::SameLine();
		ImGui::Text("Sphere Position");
		ImGui::SliderInt("Sphere Radius", &CpaZ, 0.f, 100.f);

		ImGui::Checkbox("Use Capsule Collider", &PlayProgram);
		ImGui::BeginChildFrame(10, ImVec2(120, 25));
		ImGui::InputInt("", &CpaX, 0.f, 100.f);//100.f es el max valor, cambiar por nombre/variable.
		ImGui::EndChildFrame(); ImGui::SameLine();
		ImGui::BeginChildFrame(11, ImVec2(120, 25));
		ImGui::InputInt("", &CpaY, 0.f, 100.f);//caja de texto para modificar a mano
		ImGui::EndChildFrame(); ImGui::SameLine();
		ImGui::BeginChildFrame(12, ImVec2(120, 25));
		ImGui::InputInt("", &CpaZ, 0.f, 100.f);
		ImGui::EndChildFrame(); ImGui::SameLine();
		ImGui::Text("Capsule Position");
		ImGui::SliderInt("Capsule Radius", &CpaZ, 0.f, 100.f);
	}
	if (ImGui::TreeNode("Forces"))
	{
		ImGui::TreePop();
		ImGui::Checkbox("Use gravity", &PlayProgram);
		ImGui::BeginChildFrame(13, ImVec2(120, 25));
		ImGui::InputInt("", &CpaX, 0.f, 100.f);//100.f es el max valor, cambiar por nombre/variable.
		ImGui::EndChildFrame(); ImGui::SameLine();
		ImGui::BeginChildFrame(14, ImVec2(120, 25));
		ImGui::InputInt("", &CpaY, 0.f, 100.f);//caja de texto para modificar a mano
		ImGui::EndChildFrame(); ImGui::SameLine();
		ImGui::BeginChildFrame(15, ImVec2(120, 25));
		ImGui::InputInt("", &CpaZ, 0.f, 100.f);
		ImGui::EndChildFrame(); ImGui::SameLine();
		ImGui::Text("Gravity Accel");
	}
	*/

	ImGui::End();

	if(show_test_window) {
		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}
}

void PhysicsInit() {
	// Do your initialization code here...
	// ...................................
}

void PhysicsUpdate(float dt) {
	// Do your update code here...
	// ...........................
}

void PhysicsCleanup() {
	// Do your cleanup code here...
	// ............................
}