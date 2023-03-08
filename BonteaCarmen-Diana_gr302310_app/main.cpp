//
//  main.cpp
//  OpenGL Advances Lighting
//
//  Created by CGIS on 28/11/16.
//  Copyright � 2016 CGIS. All rights reserved.
//

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "SkyBox.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"

#include "Shader.hpp"
#include "Model3D.hpp"
#include "Camera.hpp"     
#include <stdlib.h>     
#include <time.h> 
#include <iostream>
#include<stdio.h>
#include<windows.h>
//#include<MMsystem.h>
int glWindowWidth = 800;
int glWindowHeight = 600;
int retina_width, retina_height;
GLFWwindow* glWindow = NULL;

const unsigned int SHADOW_WIDTH = 2048;
const unsigned int SHADOW_HEIGHT = 2048;

glm::mat4 model;
GLuint modelLoc;
glm::mat4 view;
GLuint viewLoc;
glm::mat4 projection;
GLuint projectionLoc;
glm::mat3 normalMatrix;
GLuint normalMatrixLoc;
glm::mat4 lightRotation;

glm::vec3 lightDir;
GLuint lightDirLoc;
glm::vec3 lightColor;
GLuint lightColorLoc;
bool tasta_1 = false;
bool tasta_2 = false;
bool tasta_3 = false;
//::vec3 lightDir2;
//GLuint lightDirLoc2;
//glm::vec3 lightColor2;
//GLuint lightColorLoc2;
int ploaie_x[102];
int ploaie_y[102];
int ploaie_z[102];
gps::Camera myCamera(
				//glm::vec3(0.0f, 1.2f, 30.0f),
				//glm::vec3(0.0f, 0.0f, 0.0f),
	            glm::vec3(22.565922, 41.104991, 198.445908),
	            glm::vec3(22.426773, 39.658424, 167.552216),
				glm::vec3(0.0f, 1.0f, 0.0f));


float cameraSpeed = 1.0f;
bool zana_move = false;
float move_zana = 0.0f;
float rotate_zana = 0.0f;
float zana_x = 0.0f;
float zana_y = 0.0f;
bool pressedKeys[1024];
float angleY = 0.0f;
GLfloat lightAngle;
GLfloat lightAngle2;
bool play_music = false;
bool stop_music = false;
bool stanga = true;
bool dreapta = false;
gps::Model3D nanosuit;
gps::Model3D zana;
gps::Model3D aripi;
gps::Model3D drop_0;
gps::Model3D drop_1;
gps::Model3D drop_2;
gps::Model3D drop_3;
gps::Model3D drop_4;
gps::Model3D drop_5;
gps::Model3D drop_6;
gps::Model3D drop_7;
gps::Model3D drop_8;
gps::Model3D drop_9;
gps::Model3D drop_10;
gps::Model3D drop_11;
gps::Model3D drop_12;
gps::Model3D drop_13;
gps::Model3D drop_14;
gps::Model3D drop_15;
gps::Model3D drop_16;
gps::Model3D drop_17;
gps::Model3D drop_18;
gps::Model3D drop_19;
gps::Model3D drop_20;
gps::Model3D drop_21;
gps::Model3D drop_22;
gps::Model3D drop_23;
gps::Model3D drop_24;
gps::Model3D drop_25;
gps::Model3D drop_26;
gps::Model3D drop_27;
gps::Model3D drop_28;
gps::Model3D drop_29;
gps::Model3D drop_30;
gps::Model3D drop_31;
gps::Model3D drop_32;
gps::Model3D drop_33;
gps::Model3D drop_34;
gps::Model3D drop_35;
gps::Model3D drop_36;
gps::Model3D drop_37;
gps::Model3D drop_38;
gps::Model3D drop_39;
gps::Model3D drop_40;
gps::Model3D drop_41;
gps::Model3D drop_42;
gps::Model3D drop_43;
gps::Model3D drop_44;
gps::Model3D drop_45;
gps::Model3D drop_46;
gps::Model3D drop_47;
gps::Model3D drop_48;
gps::Model3D drop_49;
gps::Model3D drop_50;
gps::Model3D drop_51;
gps::Model3D drop_52;
gps::Model3D drop_53;
gps::Model3D drop_54;
gps::Model3D drop_55;
gps::Model3D drop_56;
gps::Model3D drop_57;
gps::Model3D drop_58;
gps::Model3D drop_59;
gps::Model3D drop_60;
gps::Model3D drop_61;
gps::Model3D drop_62;
gps::Model3D drop_63;
gps::Model3D drop_64;
gps::Model3D drop_65;
gps::Model3D drop_66;
gps::Model3D drop_67;
gps::Model3D drop_68;
gps::Model3D drop_69;
gps::Model3D drop_70;
gps::Model3D drop_71;
gps::Model3D drop_72;
gps::Model3D drop_73;
gps::Model3D drop_74;
gps::Model3D drop_75;
gps::Model3D drop_76;
gps::Model3D drop_77;
gps::Model3D drop_78;
gps::Model3D drop_79;
gps::Model3D drop_80;
gps::Model3D drop_81;
gps::Model3D drop_82;
gps::Model3D drop_83;
gps::Model3D drop_84;
gps::Model3D drop_85;
gps::Model3D drop_86;
gps::Model3D drop_87;
gps::Model3D drop_88;
gps::Model3D drop_89;
gps::Model3D drop_90;
gps::Model3D drop_91;
gps::Model3D drop_92;
gps::Model3D drop_94;
gps::Model3D drop_95;
gps::Model3D drop_96;
gps::Model3D drop_97;
gps::Model3D drop_98;
gps::Model3D drop_99;
gps::Model3D drop_93;
gps::Model3D drop_100;

gps::Model3D casa2_1;
gps::Model3D casa2_2;
gps::Model3D casa2_3;
gps::Model3D ground;
gps::Model3D lightCube;
gps::Model3D screenQuad;
gps::Model3D barca;
gps::Model3D tree;
gps::Model3D tree_1;
gps::Model3D tree_crown_1;
gps::Model3D tree_2;
gps::Model3D tree_crown_2;
gps::Model3D tree_3;
gps::Model3D tree_crown_3;
gps::Model3D tree_4;
gps::Model3D tree_crown_4;
gps::Model3D tree_5;
gps::Model3D tree_crown_5;
gps::Model3D tree_6;
gps::Model3D tree_crown_6;
gps::Model3D tree_7;
gps::Model3D tree_crown_7;
gps::Model3D tree_8;
gps::Model3D tree_crown_8;
gps::Model3D tree_9;
gps::Model3D tree_crown_9;
gps::Model3D tree_10;
gps::Model3D tree_crown_10;
gps::Model3D tree_11;
gps::Model3D tree_crown_11;
gps::Model3D tree_12;
gps::Model3D tree_crown_12;
gps::Model3D tree_13;
gps::Model3D tree_crown_13;
gps::Model3D tree_14;
gps::Model3D tree_crown_14;
gps::Model3D tree_15;
gps::Model3D tree_crown_15;
gps::Model3D tree_16;
gps::Model3D tree_crown_16;
gps::Model3D tree_17;
gps::Model3D tree_crown_17;
gps::Model3D tree_18;
gps::Model3D tree_crown_18;
gps::Model3D tree_19;
gps::Model3D tree_crown_19;
gps::Model3D tree_20;
gps::Model3D tree_crown_20;
gps::Model3D tree_21;
gps::Model3D tree_crown_21;
gps::Model3D tree_22;
gps::Model3D tree_crown_22;
gps::Model3D tree_23;
gps::Model3D tree_crown_23;
gps::Model3D tree_24;
gps::Model3D tree_crown_24;
gps::Model3D tree1_1;
gps::Model3D tree1_2;
gps::Model3D tree2_1;
gps::Model3D tree2_2;
gps::Model3D tree3_1;
gps::Model3D tree3_2;
gps::Model3D tree4_1;
gps::Model3D tree4_2;
gps::Model3D tree5_1;
gps::Model3D tree5_2;
gps::Model3D tree6_1;
gps::Model3D tree6_2;
gps::Model3D tree7_1;
gps::Model3D tree7_2;
gps::Model3D tree8_1;
gps::Model3D tree8_2;
gps::Model3D tree9_1;
gps::Model3D tree9_2;
gps::Model3D tree10_1;
gps::Model3D tree10_2;
gps::Model3D tree11_1;
gps::Model3D tree11_2;
gps::Model3D tree12_1;
gps::Model3D tree12_2;
gps::Model3D tree13_1;
gps::Model3D tree13_2;
gps::Model3D tree14_1;
gps::Model3D tree14_2;
gps::Model3D tree15_1;
gps::Model3D tree15_2;
gps::Model3D tree16_1;
gps::Model3D tree16_2;
gps::Model3D tree17_1;
gps::Model3D tree17_2;
gps::Model3D grass;
gps::Model3D vie;
gps::Model3D water;
gps::Model3D tufis_4;
gps::Model3D tufis_5;
gps::Model3D tufis_6;
gps::Model3D tufis_7;
gps::Model3D tufis_8;
gps::Model3D tufis_9;
gps::Model3D tufis_10;
gps::Model3D tufis_11;
gps::Model3D tufis_12;
gps::Model3D tufis_13;
gps::Model3D tufis_14;
gps::Model3D tufis_15;
gps::Model3D tufis_16;
gps::Model3D tufis_17;
gps::Model3D tufis_18;
gps::Model3D tufis_19;
gps::Model3D tufis_20;
gps::Model3D frunze_1;
gps::Model3D frunze_2;
gps::Model3D frunze_3;
gps::Model3D frunze_4;
gps::Model3D frunze_5;
gps::Model3D frunze_6;
gps::Model3D frunze_7;
gps::Model3D frunze_8;
gps::Model3D frunze_9;
gps::Model3D frunze_10;
gps::Model3D frunze_11;
gps::Model3D frunze_12;
gps::Model3D cityvine_1;
gps::Model3D cityvine_2;
gps::Model3D cityvine_3;
gps::Model3D cityvine_4;
gps::Model3D cityvine_5;
gps::Model3D cityvine_6;
gps::Model3D cityvine_7;
gps::Model3D cityvine_8;
gps::Model3D cityvine_9;
gps::Model3D cityvine_10;
gps::Model3D cityvine_11;
gps::Model3D cityvine_12;
gps::Model3D cityvine_13;
gps::Model3D cityvine_14;
gps::Model3D cityvine_15;
gps::Model3D cityvine_16;
gps::Model3D cityvine_17;
gps::Model3D cityvine_18;
gps::Model3D cityvine_19;
gps::Model3D cityvine_20;
gps::Model3D waterivy_1;
gps::Model3D waterivy_2;
gps::Model3D waterivy_3;
gps::Model3D waterivy_4;
gps::Model3D waterivy_5;
gps::Model3D waterivy_6;
gps::Model3D waterivy_7;
gps::Model3D waterivy_8;
gps::Model3D ivy_1;
gps::Model3D ivy_2;
gps::Model3D ivy_3;
gps::Model3D ivy_4;
gps::Model3D ivy_5;
gps::Model3D ivy_6;
gps::Model3D ivy_7;
gps::Model3D ivy_8;
gps::Model3D ivy_9;
gps::Model3D ivy_10;
gps::Model3D ivy_11;
gps::Model3D ivy_12;
gps::Model3D ivy_13;
gps::Model3D ivy_14;
gps::Model3D ivy_15;
gps::Model3D ivy_16;
gps::Model3D ivy_17;
gps::Model3D ivy_18;
gps::Model3D ivy_19;
gps::Model3D ivy_20;
gps::Model3D ivy_21;
gps::Model3D ivy_22;
gps::Model3D ivy_23;
gps::Model3D ivy_24;
gps::Model3D ivy_25;
gps::Model3D ivy_26;
gps::Model3D ivy_27;
gps::Model3D ivy_28;
gps::Model3D ivy_29;
gps::Model3D ivy_30;
gps::Model3D ivy_31;
gps::Model3D ivy_32;
gps::Model3D ivy_33;
gps::Model3D ivy_34;
gps::Model3D ivy_35;
gps::Model3D ivy_36;
gps::Model3D flori_1;
gps::Model3D flori_2;
gps::Model3D flori_3;
gps::Model3D flori_4;
gps::Model3D flori_5;
gps::Model3D flori_6;
gps::Model3D flori_7;
gps::Model3D flori_8;
gps::Model3D flori_9;
gps::Model3D flori_10;
gps::Model3D steag_1;
gps::Model3D steag_2;
gps::Model3D steag_3;
gps::Model3D awning_1;
gps::Model3D awning_2;
gps::Model3D awning_3;
gps::Model3D awning_4;
gps::Model3D copac_f;
gps::Model3D planta_1;
gps::Model3D planta_2;
gps::Model3D planta_3;
gps::Model3D planta_4;
gps::Model3D planta_5;
gps::Model3D planta_6;
gps::Model3D planta_7;
gps::Model3D planta_8;
gps::Model3D planta_9;
gps::Model3D planta_10;
gps::Model3D planta_11;
gps::Model3D planta_12;
gps::Model3D planta_13;
gps::Model3D planta_14;
gps::Model3D planta_15;
gps::Model3D planta_16;
gps::Model3D planta_17;
gps::Model3D planta_18;
gps::Model3D casa_1;
gps::Model3D casa_2;
gps::Model3D casa_3;
gps::Model3D casa_4;
gps::Model3D casa_5;
gps::Model3D casa_6;
gps::Model3D casa_7;
gps::Model3D casa_8;
gps::Model3D casa_9;
gps::Model3D casa_10;
gps::Model3D casa_11;
gps::Model3D nuferi_1;
gps::Model3D nuferi_2;
gps::Model3D nuferi_3;
gps::Model3D nuferi_4;
gps::Model3D nuferi_5;
gps::Model3D nuferi_6;
gps::Model3D nuferi_7;
gps::Model3D nuferi_8;
gps::Model3D nuferi_9;
gps::Model3D nuferi_10;
gps::Model3D nuferi_11;
gps::Model3D topiar_1;
gps::Model3D topiar_2;
gps::Model3D topiar_3;
gps::Model3D topiar_4;
gps::Model3D topiar_5;
gps::Model3D topiar_6;
gps::Model3D topiar_7;
gps::Model3D topiar_8;









gps::Shader myCustomShader;
gps::Shader lightShader;
gps::Shader screenQuadShader;
glm::vec3 camPosition = glm::vec3(0.0f, 5.0f, 15.0f);
glm::vec3 camTarget = glm::vec3(0.0f, 2.0f, -10.0f);
gps::Shader depthShader;
gps::Shader copac;

gps::Shader reflexie;

GLuint shadowMapFBO;
GLuint framebuffer;
GLuint depthMapTexture;
float angle = 0.0f;
bool showDepthMap;
//fog
bool fog = false;
bool pointLight = false;
bool directLight = false;
bool spotLight = false;
bool lampa = false;
bool presentation = false;
//bool lumina1 = false;
//bool lumina2 = false;
bool dark = false;
bool dark_sky = false;
bool day = true;
//reflexie
glm::vec3 cameraPos;
//skybox
gps::SkyBox mySkyBox;
gps::SkyBox mySkyBox_2;
gps::Shader skyboxShader;
std::vector<const GLchar*> faces;
std::vector<const GLchar*> faces_2;

//miscare barca
bool move_boat = false;
float move_x = 0.0f;
float move_y = 0.0f;
//rain 
float move = 0.0f;
bool rain = false;
//mousecallback
bool first_mouse = true;
float last_x = 400;
float last_y = 300;
float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch = 0.0f;

//animatie de prezentare
glm::vec3 camera_position[] = {
	glm::vec3(-138.008896, -40.752344, 110.983429),
	glm::vec3(-130.468262, -52.811747, 146.183289),
	glm::vec3(-127.003914, -56.020321, 165.590561),
	glm::vec3(-122.599579, -57.381072, 193.594528),
	glm::vec3(-121.518036, -48.228979, 197.429428),
	glm::vec3(-151.674652, -46.158545, 221.092285),
	glm::vec3(-121.000443, -46.464844, 216.649933),
	glm::vec3(-86.937981, -45.912479, 195.838516),
	glm::vec3(-68.969269, -43.338306, 183.530334),
	glm::vec3(-26.782223, -41.152813, 188.504013),
	glm::vec3(37.667023, -39.5847, 194.429550),
	glm::vec3(86.511703, -40.976376, 204.431793),
	glm::vec3(134.508011, -43.380423, 204.301758),
	glm::vec3(132.926559, -43.937117, 196.242813),
	glm::vec3(130.677521, -49.421535, 149.748764),
	glm::vec3(145.416702, -54.438076, 110.967728),
	glm::vec3(154.032150, -54.692774, 84.341499),
	glm::vec3(168.190796, -55.979231, 47.016079),
	glm::vec3(172.206497, -57.624388, 10.278174),
	glm::vec3(163.334808, -57.70205, 8.774104),
	glm::vec3(107.080338, -54.693728, 7.260035),
	glm::vec3(35.101509, -51.598648, 3.852772),
	glm::vec3(24.033800, -52.651722, 5.275789),
	glm::vec3(2.530173, -51.839081, 6.917378),
	//glm::vec3(-33.844379, 11.882967, 9.348255),
	//glm::vec3(-29.491823, 11.338260, 4.020007),
	//glm::vec3(-21.512220, 13.462326, 4.221935),
	glm::vec3(-2.751911, -57.597715, -15.938965),
	glm::vec3(13.720613, -57.45923, -37.073780),
	glm::vec3(7.138162, -56.33101, -95.587318),
	glm::vec3(-2.588069,-55.421575, -136.531631),
	glm::vec3(14.097002, -58.337621, -150.331207),
	glm::vec3(41.885303, -58.109871, -150.672897),
	glm::vec3(70.330185, -50.48885, -149.994019),
	glm::vec3(66.991180, -53.305199, -189.735825),
	glm::vec3(54.939121, -43.513226, -215.848282),
	glm::vec3(43.939110, -43.199961, -220.605759),
	glm::vec3(62.809269, -35.616192, -239.795212),
	glm::vec3(63.814423, -35.975513, -244.454849),
	glm::vec3(80.784836, -28.883644, -233.693680),
	glm::vec3(81.551025, -21.887501, -231.857559),
	glm::vec3(92.913353, -22.814888, -201.973541),
	glm::vec3(100.384399,-22.814888, -195.660065)
};
glm::vec3 camera_target[] = {
   glm::vec3(-137.772217, -41.128569, 111.879219),
   glm::vec3(-130.322067, -53.123253, 147.122223),
   glm::vec3(-126.890388, -56.117904, 166.579285),
   glm::vec3(-122.422638, -57.421204, 194.577927),
   glm::vec3(-121.247650, -48.140955, 198.388153),
   glm::vec3(-150.796738, -46.2283, 221.565979),
   glm::vec3(-120.013344, -46.47357, 216.490051),
   glm::vec3(-86.129654, -45.891537, 195.250153),
   glm::vec3(-68.006630, -43.227705, 183.283173),
   glm::vec3(-25.825462, -41.178118, 188.793793),
   glm::vec3(38.642967, -39.603025, 194.646805),
   glm::vec3(87.468575, -41.006914, 204.720688),
   glm::vec3(135.501343, -43.294136, 204.378189),
   glm::vec3(133.653732, -44.07629, 195.570618),
   glm::vec3(131.153854, -49.548601, 148.878723),
   glm::vec3(145.671371, -54.550412, 110.007248),
   glm::vec3(154.359375, -54.763401, 83.399193),
   glm::vec3(168.596436, -56.052469, 46.104988),
   glm::vec3(172.342209, -57.612171, 9.287500),
   glm::vec3(162.345810, -57.707286, 8.626297),
   glm::vec3(106.095169, -54.643135, 7.096059),
   glm::vec3(34.129112, -51.558516, 3.622908),
   glm::vec3(23.122173, -53.002747, 5.061969),
  // glm::vec3(-32.844509, 11.870749, 9.337784),
   //glm::vec3(-28.546488, 11.424546, 3.705534),
   //glm::vec3(-20.513720, 13.512918, 4.242848),
   glm::vec3(1.611113,  -52.038448, 6.577408),
   glm::vec3(-2.180288, -57.640463, -16.758368),
   glm::vec3(13.533570, -57.640463, -38.054287),
   glm::vec3(6.953359,  -56.321411, -96.570045),
   glm::vec3(-2.416269, -55.459963, -137.516022),
   glm::vec3(14.930654, -58.461223, -150.869492),
   glm::vec3(42.700935, -58.108126, -151.251465),
   glm::vec3(70.367210, -50.752724, -150.957870),
   glm::vec3(66.820457, -53.36886, -190.719086),
   glm::vec3(54.415695, -43.55946, -216.699097),
   glm::vec3(44.662914, -43.485649, -221.233841),
   glm::vec3(63.516430, -35.732864, -240.492569),
   glm::vec3(64.790176, -36.155174, -244.329849),
   glm::vec3(81.187950, -28.929878, -232.779694),
   glm::vec3(81.934120, -21.989426, -230.939499),
   glm::vec3(93.235466, -22.846298, -201.027359),
   glm::vec3(99.411606, -22.855019, -195.431900)
};

glm::vec3 camera_Position;
glm::vec3 camera_Target;
int i = 0;
float t = 1;

//ploaie
void generate_position() {
	int randomNumber;

	/* initialize random seed: */
	srand(time(NULL));
	
	/* generate random number between 1 and 10: */
	//randomNumber = rand() % 10 + 1;

	int len = sizeof(ploaie_x) / sizeof(ploaie_x[0]);
	int min = -200;
	int max = 200;
	for (int i = 0; i < len; i++)
	{
		ploaie_x[i]= rand() % (max - min + 1) + min;
	}
	
     min = 50;
	 max = 200;
	for (int i = 0; i < len; i++)
	{
		ploaie_y[i] = rand() % (max - min + 1) + min;
	}
	min = -200;
	max = 200;
	for (int i = 0; i < len; i++)
	{
		ploaie_z[i] = rand() % (max - min + 1) + min;
	}
}

GLenum glCheckError_(const char *file, int line) {
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR)
	{
		std::string error;
		switch (errorCode)
		{
		case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
		case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
		case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
		case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
		case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
		case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
		case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
		}
		std::cout << error << " | " << file << " (" << line << ")" << std::endl;
	}
	return errorCode;
}
#define glCheckError() glCheckError_(__FILE__, __LINE__)



void windowResizeCallback(GLFWwindow* window, int width, int height) {
	fprintf(stdout, "window resized to width: %d , and height: %d\n", width, height);
	//TODO	
	// 
	//for RETINA display
	glfwGetFramebufferSize(glWindow, &retina_width, &retina_height);
    myCustomShader.useShaderProgram();

	//set projection matrix
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);

	//send matrix data to shader
	GLint projLoc = glGetUniformLocation(myCustomShader.shaderProgram, "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	lightShader.useShaderProgram();
    glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));



	//set Viewport transform
	glViewport(0, 0, retina_width, retina_height);
}

void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_M && action == GLFW_PRESS)
		showDepthMap = !showDepthMap;

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			pressedKeys[key] = true;
		else if (action == GLFW_RELEASE)
			pressedKeys[key] = false;
	}
}

void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
	if (first_mouse)
	{
		last_x = xpos;
		last_y = ypos;
		first_mouse = false;
	}
	// the offset movement between the last and current frame
	float new_x = xpos - last_x;
	float new_y = last_y - ypos; // reversed since y-coordinates range from bottom to top
	last_x = xpos;
	last_y = ypos;

	float sensitivity = 0.05;
	
	new_x =new_x* sensitivity;
	new_y =new_y* sensitivity;
	//add the offset values to the globally declared pitch and yaw values:
	yaw =yaw+ new_x;
	pitch = pitch+ new_y;
/*
	In the third step we'd like to add some constraints to the camera so users won't be able to make weird camera movements(also causes a LookAt flip once direction vector is parallel to the world up direction).
	The pitch needs to be constrained in such a way that users won't be able to look higher than 89 degrees (at 90 degrees we get the LookAt flip) and also not below -89 degrees. 
	This ensures the user will be able to look up to the sky or below to his feet but not further. The constraints work by replacing the Euler value with its constraint value whenever it breaches the constraint:
	*/
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	myCamera.rotate(pitch, yaw);
}

void processMovement()
{
	if (pressedKeys[GLFW_KEY_Y]) {
		zana_move = true;
		
		
	}
	if (pressedKeys[GLFW_KEY_U]) {
		zana_move = false;
		zana_x = 0;
		zana_y = 0;
		rotate_zana= 0;
	}


	if (pressedKeys[GLFW_KEY_Q]) {
		//angleY -= 4.0f;	
		yaw = yaw - 4.0f;
		if (yaw < 0.0f)
			yaw += 360.0f;
		myCamera.rotate(pitch, yaw);
		std::cout << "Camera position" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraPosition()) << std::endl;
		std::cout << "Camera target" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraTarget()) << std::endl;
	}

	if (pressedKeys[GLFW_KEY_E]) {
		//angleY += 4.0f;		
		yaw = yaw + 4.0f;
		if (yaw > 360.0f)
			yaw -= 360.0f;
		myCamera.rotate(pitch, yaw);
		std::cout << "Camera position" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraPosition()) << std::endl;
		std::cout << "Camera target" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraTarget()) << std::endl;
	}
	//rotim lumina
	if (pressedKeys[GLFW_KEY_J]) {
		lightAngle += 1.0f;	
		if (lightAngle > 360.0f)
			lightAngle -= 360.0f;
		glm::vec3 lightDirTr = glm::vec3(glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(lightDir, 1.0f));
		myCustomShader.useShaderProgram();
		glUniform3fv(lightDirLoc, 1, glm::value_ptr(lightDirTr));
	}
	//rotim lumina
	if (pressedKeys[GLFW_KEY_L]) {
		lightAngle -= 1.0f;
		if (lightAngle < 0.0f)
			lightAngle += 360.0f;
		glm::vec3 lightDirTr = glm::vec3(glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(lightDir, 1.0f));
		myCustomShader.useShaderProgram();
		glUniform3fv(lightDirLoc, 1, glm::value_ptr(lightDirTr));
	}

	if (pressedKeys[GLFW_KEY_UP]) {
		myCamera.move(gps::MOVE_FORWARD, cameraSpeed);	
		std::cout << "Camera position" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraPosition()) << std::endl;
		std::cout << "Camera target" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraTarget()) << std::endl;
	}

	if (pressedKeys[GLFW_KEY_DOWN]) {
		myCamera.move(gps::MOVE_BACKWARD, cameraSpeed);	
		std::cout << "Camera position" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraPosition()) << std::endl;
		std::cout << "Camera target" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraTarget()) << std::endl;
	}

	if (pressedKeys[GLFW_KEY_LEFT]) {
		myCamera.move(gps::MOVE_LEFT, cameraSpeed);	
		std::cout << "Camera position" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraPosition()) << std::endl;
		std::cout << "Camera target" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraTarget()) << std::endl;
	}

	if (pressedKeys[GLFW_KEY_RIGHT]) {
		myCamera.move(gps::MOVE_RIGHT, cameraSpeed);
		std::cout << "Camera position" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraPosition()) << std::endl;
		std::cout << "Camera target" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraTarget()) << std::endl;
	}
	if (pressedKeys[GLFW_KEY_R]) {
		myCamera.move(gps::MOVE_UP, cameraSpeed);
		std::cout << "Camera position" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraPosition()) << std::endl;
		std::cout << "Camera target" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraTarget()) << std::endl;
	}
	if (pressedKeys[GLFW_KEY_T]) {
		myCamera.move(gps::MOVE_DOWN, cameraSpeed); 
		std::cout << "Camera position" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraPosition()) << std::endl;
		std::cout << "Camera target" << std::endl;
		std::cout << glm::to_string(myCamera.getCameraTarget()) << std::endl;

	}
	//solid
	if (pressedKeys[GLFW_KEY_S]) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
	}
	//wireframe
	if (pressedKeys[GLFW_KEY_W]) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 
	}
	//polygonal
	if (pressedKeys[GLFW_KEY_P]) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); 
	}
	//smooth
	if (pressedKeys[GLFW_KEY_N]) { 
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_POLYGON_SMOOTH);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
	}
	if (pressedKeys[GLFW_KEY_F]) {
		fog = true;
		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "fog"), fog);

	/*	copac.useShaderProgram();
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);*/
	}
	if (pressedKeys[GLFW_KEY_G]) {
		fog = false;
		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

		/*copac.useShaderProgram();
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);*/
	}
	
	if (pressedKeys[GLFW_KEY_1]) {
		tasta_1 = true;
		tasta_2 = false;
		tasta_3 = false;
		pointLight = true;
		directLight = false;
		spotLight = false;
		lampa = false;

		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "pointLight"), pointLight);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "directLight"), directLight);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight"), spotLight);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);

		/*copac.useShaderProgram();
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "pointLight"), pointLight);
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "directLight"), directLight);
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "spotLight"), spotLight);*/
		//glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);
	}
	if (pressedKeys[GLFW_KEY_2]) {
		tasta_1 = false;
		tasta_2 = true;
		tasta_3 = false;
		pointLight = false;
		directLight = true;
		spotLight = false;
		lampa = false;

		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "pontLight"), pointLight);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "directLight"), directLight);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight"), spotLight);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);

	  /*copac.useShaderProgram();
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "pointLight"), pointLight);
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "directLight"), directLight);
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "spotLight"), spotLight);*/
		//glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);
	
	}
	if (pressedKeys[GLFW_KEY_3]) {
		tasta_1 = false;
		tasta_2 = false;
		tasta_3 = true;
		pointLight = true;
		directLight = false;
		spotLight = true;
		lampa = false;
		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "pontLight"), pointLight);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "directLight"), directLight);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight"), spotLight);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);

		/*copac.useShaderProgram();
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "pointLight"), pointLight);
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "directLight"), directLight);
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "spotLight"), spotLight);*/
		//glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);
	
	}
	if (pressedKeys[GLFW_KEY_4]) {
		lampa = true;
		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);
	}
	if (pressedKeys[GLFW_KEY_5]) {
		lampa = false;
		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);
	}
	if (pressedKeys[GLFW_KEY_6]) {
		i = 0;
		t = 1.0f;
		presentation = true;
	}
	if (pressedKeys[GLFW_KEY_7]) {
		presentation = false;
		myCamera.setCameraPos(glm::vec3(6.359237, -5.829151, 142.784439));
		myCamera.setCameraTarget(glm::vec3(6.359237, -7.829151, 111.784439));

	}
	if (pressedKeys[GLFW_KEY_8]) {
		move_boat = true;
	}
	if (pressedKeys[GLFW_KEY_9]) {
		move_boat = false;
	}
	if (pressedKeys[GLFW_KEY_Z]) {
		play_music = true;
		if (play_music)
		{
			PlaySound(TEXT("song.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		}

	}
	if (pressedKeys[GLFW_KEY_X]) {
		play_music = false;
		if (!play_music)
		{
			PlaySound(NULL, 0, 0);
		}

	}
	if (pressedKeys[GLFW_KEY_D]) {
		dark = true;
		directLight = true;
		day = false;
		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "dark"), dark);

		copac.useShaderProgram();
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "dark"), dark);

		copac.useShaderProgram();
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "directLight"), directLight);
		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "directLight"), directLight);

		//skyboxShader.useShaderProgram();
		faces.push_back("cubemap/MilkWorldRT.tga");
		faces.push_back("cubemap/MilkWorldLF.tga");
		faces.push_back("cubemap/MilkWorldUP.tga");
		faces.push_back("cubemap/MilkWorldDN.tga");
		faces.push_back("cubemap/MilkWorldBK.tga");
		faces.push_back("cubemap/MilkWorldFT.tga");
		mySkyBox.Load(faces);
		skyboxShader.useShaderProgram();
		view = myCamera.getViewMatrix();
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));

		projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		mySkyBox.Draw(skyboxShader, view, projection);
		
	}
	if (pressedKeys[GLFW_KEY_C]) {
		dark = false;
		directLight = true;
		day = true;
		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "dark"), dark);
		/*myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "dark"), dark);*/


		/*copac.useShaderProgram();
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "directLight"), directLight);*/
		myCustomShader.useShaderProgram();
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "directLight"), directLight);
		////skyboxShader.useShaderProgram();
		//faces.push_back("cubemap/MilkWorldRT.tga");
		//faces.push_back("cubemap/MilkWorldLF.tga");
		//faces.push_back("cubemap/MilkWorldUP.tga");
		//faces.push_back("cubemap/MilkWorldDN.tga");
		//faces.push_back("cubemap/MilkWorldBK.tga");
		//faces.push_back("cubemap/MilkWorldFT.tga");
		//mySkyBox.Load(faces);
		//skyboxShader.useShaderProgram();

		/*view = myCamera.getViewMatrix();
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));

		projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		mySkyBox.Draw(skyboxShader, view, projection);*/

	}
	if (pressedKeys[GLFW_KEY_A]) {
		rain = true;
		if (play_music)
		{
			play_music = false;
			stop_music = true;
		}
		PlaySound(TEXT("rain.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}

	if (pressedKeys[GLFW_KEY_B]) {
		rain = false;
		PlaySound(NULL, 0, 0);
		if (stop_music)
		{
			play_music = true;
			PlaySound(TEXT("song.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		}
	}


}

bool initOpenGLWindow()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	glWindow = glfwCreateWindow(glWindowWidth, glWindowHeight, "OpenGL Shader Example", NULL, NULL);
	if (!glWindow) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return false;
	}

	glfwSetWindowSizeCallback(glWindow, windowResizeCallback);
	glfwSetKeyCallback(glWindow, keyboardCallback);
	glfwSetCursorPosCallback(glWindow, mouseCallback);
   // glfwSetInputMode(glWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwMakeContextCurrent(glWindow);

	glfwSwapInterval(1);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	//for RETINA display
	glfwGetFramebufferSize(glWindow, &retina_width, &retina_height);

	return true;
}

void initOpenGLState()
{
	//glClearColor(0.3, 0.3, 0.3, 1.0);
	glClearColor(0.5, 0.5, 0.5, 1.0);

	glViewport(0, 0, retina_width, retina_height);

	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
	glEnable(GL_CULL_FACE); // cull face
	glCullFace(GL_BACK); // cull back face
	glFrontFace(GL_CCW); // GL_CCW for counter clock-wise

	//glEnable(GL_FRAMEBUFFER_SRGB);


}

void initObjects() {
	drop_0.LoadModel("obiecte_1\\drop_1.obj", "obiecte_1\\");
	zana.LoadModel("obiecte_1\\zana.obj", "obiecte_1\\");
	aripi.LoadModel("obiecte_1\\aripi.obj", "obiecte_1\\");
	drop_1.LoadModel("obiecte_1\\drop_1.obj", "obiecte_1\\");
	drop_2.LoadModel("obiecte_1\\drop_2.obj", "obiecte_1\\");
	drop_3.LoadModel("obiecte_1\\drop_3.obj", "obiecte_1\\");
	drop_4.LoadModel("obiecte_1\\drop_4.obj", "obiecte_1\\");
	drop_5.LoadModel("obiecte_1\\drop_5.obj", "obiecte_1\\");
	drop_6.LoadModel("obiecte_1\\drop_6.obj", "obiecte_1\\");
	drop_7.LoadModel("obiecte_1\\drop_7.obj", "obiecte_1\\");
	drop_8.LoadModel("obiecte_1\\drop_8.obj", "obiecte_1\\");
	drop_9.LoadModel("obiecte_1\\drop_9.obj", "obiecte_1\\");
	drop_10.LoadModel("obiecte_1\\drop_10.obj", "obiecte_1\\");
	drop_11.LoadModel("obiecte_1\\drop_11.obj", "obiecte_1\\");
	drop_12.LoadModel("obiecte_1\\drop_12.obj", "obiecte_1\\");
	drop_13.LoadModel("obiecte_1\\drop_13.obj", "obiecte_1\\");
	drop_14.LoadModel("obiecte_1\\drop_14.obj", "obiecte_1\\");
	drop_15.LoadModel("obiecte_1\\drop_15.obj", "obiecte_1\\");
	drop_16.LoadModel("obiecte_1\\drop_16.obj", "obiecte_1\\");
	drop_17.LoadModel("obiecte_1\\drop_17.obj", "obiecte_1\\");
	drop_18.LoadModel("obiecte_1\\drop_18.obj", "obiecte_1\\");
	drop_19.LoadModel("obiecte_1\\drop_19.obj", "obiecte_1\\");
	drop_20.LoadModel("obiecte_1\\drop_20.obj", "obiecte_1\\");
	drop_21.LoadModel("obiecte_1\\drop_21.obj", "obiecte_1\\");
	drop_22.LoadModel("obiecte_1\\drop_22.obj", "obiecte_1\\");
	drop_23.LoadModel("obiecte_1\\drop_23.obj", "obiecte_1\\");
	drop_24.LoadModel("obiecte_1\\drop_24.obj", "obiecte_1\\");
	drop_25.LoadModel("obiecte_1\\drop_25.obj", "obiecte_1\\");
	drop_26.LoadModel("obiecte_1\\drop_26.obj", "obiecte_1\\");
	drop_27.LoadModel("obiecte_1\\drop_27.obj", "obiecte_1\\");
	drop_28.LoadModel("obiecte_1\\drop_28.obj", "obiecte_1\\");
	drop_29.LoadModel("obiecte_1\\drop_29.obj", "obiecte_1\\");
	drop_30.LoadModel("obiecte_1\\drop_30.obj", "obiecte_1\\");
	drop_31.LoadModel("obiecte_1\\drop_31.obj", "obiecte_1\\");
	drop_32.LoadModel("obiecte_1\\drop_32.obj", "obiecte_1\\");
	drop_33.LoadModel("obiecte_1\\drop_33.obj", "obiecte_1\\");
	drop_34.LoadModel("obiecte_1\\drop_34.obj", "obiecte_1\\");
	drop_35.LoadModel("obiecte_1\\drop_35.obj", "obiecte_1\\");
	drop_36.LoadModel("obiecte_1\\drop_36.obj", "obiecte_1\\");
	drop_37.LoadModel("obiecte_1\\drop_37.obj", "obiecte_1\\");
	drop_38.LoadModel("obiecte_1\\drop_38.obj", "obiecte_1\\");
	drop_39.LoadModel("obiecte_1\\drop_39.obj", "obiecte_1\\");
	drop_40.LoadModel("obiecte_1\\drop_40.obj", "obiecte_1\\");
	drop_41.LoadModel("obiecte_1\\drop_41.obj", "obiecte_1\\");
	drop_42.LoadModel("obiecte_1\\drop_42.obj", "obiecte_1\\");
	drop_43.LoadModel("obiecte_1\\drop_43.obj", "obiecte_1\\");
	drop_44.LoadModel("obiecte_1\\drop_44.obj", "obiecte_1\\");
	drop_45.LoadModel("obiecte_1\\drop_45.obj", "obiecte_1\\");
	drop_46.LoadModel("obiecte_1\\drop_46.obj", "obiecte_1\\");
	drop_47.LoadModel("obiecte_1\\drop_47.obj", "obiecte_1\\");
	drop_48.LoadModel("obiecte_1\\drop_48.obj", "obiecte_1\\");
	drop_49.LoadModel("obiecte_1\\drop_49.obj", "obiecte_1\\");
	drop_50.LoadModel("obiecte_1\\drop_50.obj", "obiecte_1\\");
	drop_51.LoadModel("obiecte_1\\drop_51.obj", "obiecte_1\\");
	drop_52.LoadModel("obiecte_1\\drop_52.obj", "obiecte_1\\");
	drop_53.LoadModel("obiecte_1\\drop_53.obj", "obiecte_1\\");
	drop_53.LoadModel("obiecte_1\\drop_54.obj", "obiecte_1\\");
	drop_54.LoadModel("obiecte_1\\drop_55.obj", "obiecte_1\\");
	drop_55.LoadModel("obiecte_1\\drop_56.obj", "obiecte_1\\");
	drop_56.LoadModel("obiecte_1\\drop_57.obj", "obiecte_1\\");
	drop_57.LoadModel("obiecte_1\\drop_58.obj", "obiecte_1\\");
	drop_58.LoadModel("obiecte_1\\drop_59.obj", "obiecte_1\\");
	drop_59.LoadModel("obiecte_1\\drop_60.obj", "obiecte_1\\");
	drop_60.LoadModel("obiecte_1\\drop_61.obj", "obiecte_1\\");
	drop_61.LoadModel("obiecte_1\\drop_62.obj", "obiecte_1\\");
	drop_62.LoadModel("obiecte_1\\drop_63.obj", "obiecte_1\\");
	drop_63.LoadModel("obiecte_1\\drop_64.obj", "obiecte_1\\");
	drop_64.LoadModel("obiecte_1\\drop_65.obj", "obiecte_1\\");
	drop_65.LoadModel("obiecte_1\\drop_66.obj", "obiecte_1\\");
	drop_66.LoadModel("obiecte_1\\drop_67.obj", "obiecte_1\\");
	drop_67.LoadModel("obiecte_1\\drop_68.obj", "obiecte_1\\");
	drop_68.LoadModel("obiecte_1\\drop_69.obj", "obiecte_1\\");
	drop_69.LoadModel("obiecte_1\\drop_70.obj", "obiecte_1\\");
	drop_70.LoadModel("obiecte_1\\drop_71.obj", "obiecte_1\\");
	drop_71.LoadModel("obiecte_1\\drop_72.obj", "obiecte_1\\");
	drop_72.LoadModel("obiecte_1\\drop_73.obj", "obiecte_1\\");
	drop_73.LoadModel("obiecte_1\\drop_74.obj", "obiecte_1\\");
	drop_74.LoadModel("obiecte_1\\drop_75.obj", "obiecte_1\\");
	drop_75.LoadModel("obiecte_1\\drop_76.obj", "obiecte_1\\");
	drop_76.LoadModel("obiecte_1\\drop_77.obj", "obiecte_1\\");
	drop_77.LoadModel("obiecte_1\\drop_78.obj", "obiecte_1\\");
	drop_78.LoadModel("obiecte_1\\drop_79.obj", "obiecte_1\\");
	drop_79.LoadModel("obiecte_1\\drop_80.obj", "obiecte_1\\");
	drop_80.LoadModel("obiecte_1\\drop_81.obj", "obiecte_1\\");
	drop_81.LoadModel("obiecte_1\\drop_82.obj", "obiecte_1\\");
	drop_82.LoadModel("obiecte_1\\drop_83.obj", "obiecte_1\\");
	drop_83.LoadModel("obiecte_1\\drop_84.obj", "obiecte_1\\");
	drop_84.LoadModel("obiecte_1\\drop_85.obj", "obiecte_1\\");
	drop_85.LoadModel("obiecte_1\\drop_86.obj", "obiecte_1\\");
	drop_86.LoadModel("obiecte_1\\drop_87.obj", "obiecte_1\\");
	drop_87.LoadModel("obiecte_1\\drop_88.obj", "obiecte_1\\");
	drop_88.LoadModel("obiecte_1\\drop_89.obj", "obiecte_1\\");
	drop_89.LoadModel("obiecte_1\\drop_90.obj", "obiecte_1\\");
	drop_90.LoadModel("obiecte_1\\drop_91.obj", "obiecte_1\\");
	drop_91.LoadModel("obiecte_1\\drop_92.obj", "obiecte_1\\");
	drop_92.LoadModel("obiecte_1\\drop_93.obj", "obiecte_1\\");
	drop_93.LoadModel("obiecte_1\\drop_94.obj", "obiecte_1\\");
	drop_94.LoadModel("obiecte_1\\drop_95.obj", "obiecte_1\\");
	drop_95.LoadModel("obiecte_1\\drop_96.obj", "obiecte_1\\");
	drop_96.LoadModel("obiecte_1\\drop_97.obj", "obiecte_1\\");
	drop_97.LoadModel("obiecte_1\\drop_98.obj", "obiecte_1\\");
	drop_98.LoadModel("obiecte_1\\drop_99.obj", "obiecte_1\\");
	drop_99.LoadModel("obiecte_1\\drop_100.obj", "obiecte_1\\");
	drop_100.LoadModel("obiecte_1\\drop_101.obj", "obiecte_1\\");
	

	nanosuit.LoadModel("obiecte_1\\suramar.obj", "obiecte_1\\");
	mySkyBox.Load(faces);
	barca.LoadModel("obiecte_1\\barca.obj", "obiecte_1\\");
	casa2_1.LoadModel("obiecte_1\\casa2_1.obj", "obiecte_1\\");
	casa2_2.LoadModel("obiecte_1\\casa2_2.obj", "obiecte_1\\");
	casa2_3.LoadModel("obiecte_1\\casa2_3.obj", "obiecte_1\\");
	tree_1.LoadModel("obiecte_1\\copac_1.obj", "obiecte_1\\");
	tree_crown_1.LoadModel("obiecte_1\\coroana_1.obj", "obiecte_1\\");
	tree_2.LoadModel("obiecte_1\\copac_2.obj", "obiecte_1\\");
	tree_crown_2.LoadModel("obiecte_1\\coroana_2.obj", "obiecte_1\\");
	tree_3.LoadModel("obiecte_1\\copac_3.obj", "obiecte_1\\");
	tree_crown_3.LoadModel("obiecte_1\\coroana_3.obj", "obiecte_1\\");
	tree_4.LoadModel("obiecte_1\\copac_4.obj", "obiecte_1\\");
	tree_crown_4.LoadModel("obiecte_1\\coroana_4.obj", "obiecte_1\\");
	tree_5.LoadModel("obiecte_1\\copac_5.obj", "obiecte_1\\");
	tree_crown_5.LoadModel("obiecte_1\\coroana_5.obj", "obiecte_1\\");
	tree_6.LoadModel("obiecte_1\\copac_6.obj", "obiecte_1\\");
	tree_crown_6.LoadModel("obiecte_1\\coroana_6.obj", "obiecte_1\\");
	tree_7.LoadModel("obiecte_1\\copac_7.obj", "obiecte_1\\");
	tree_crown_7.LoadModel("obiecte_1\\coroana_7.obj", "obiecte_1\\");
	tree_8.LoadModel("obiecte_1\\copac_8.obj", "obiecte_1\\");
	tree_crown_8.LoadModel("obiecte_1\\coroana_8.obj", "obiecte_1\\"); 
	tree_9.LoadModel("obiecte_1\\copac_9.obj", "obiecte_1\\");
	tree_crown_9.LoadModel("obiecte_1\\coroana_9.obj", "obiecte_1\\");
	tree_10.LoadModel("obiecte_1\\copac_10.obj", "obiecte_1\\");
	tree_crown_10.LoadModel("obiecte_1\\coroana_10.obj", "obiecte_1\\");
	tree_11.LoadModel("obiecte_1\\copac_11.obj", "obiecte_1\\");
	tree_crown_11.LoadModel("obiecte_1\\coroana_11.obj", "obiecte_1\\");
	tree_12.LoadModel("obiecte_1\\copac_12.obj", "obiecte_1\\");
	tree_crown_12.LoadModel("obiecte_1\\coroana_12.obj", "obiecte_1\\");
	tree_13.LoadModel("obiecte_1\\copac_13.obj", "obiecte_1\\");
	tree_crown_13.LoadModel("obiecte_1\\coroana_13.obj", "obiecte_1\\");
	tree_14.LoadModel("obiecte_1\\copac_14.obj", "obiecte_1\\");
	tree_crown_14.LoadModel("obiecte_1\\coroana_14.obj", "obiecte_1\\");
	tree_15.LoadModel("obiecte_1\\copac_15.obj", "obiecte_1\\");
	tree_crown_15.LoadModel("obiecte_1\\coroana_15.obj", "obiecte_1\\");
	tree_16.LoadModel("obiecte_1\\copac_16.obj", "obiecte_1\\");
	tree_crown_16.LoadModel("obiecte_1\\coroana_16.obj", "obiecte_1\\");
	tree_17.LoadModel("obiecte_1\\copac_17.obj", "obiecte_1\\");
	tree_crown_17.LoadModel("obiecte_1\\coroana_17.obj", "obiecte_1\\");
	tree_18.LoadModel("obiecte_1\\copac_18.obj", "obiecte_1\\");
	tree_crown_18.LoadModel("obiecte_1\\coroana_18.obj", "obiecte_1\\");
	tree_19.LoadModel("obiecte_1\\copac_19.obj", "obiecte_1\\");
	tree_crown_19.LoadModel("obiecte_1\\coroana_19.obj", "obiecte_1\\");
	tree_20.LoadModel("obiecte_1\\copac_20.obj", "obiecte_1\\");
	tree_crown_20.LoadModel("obiecte_1\\coroana_20.obj", "obiecte_1\\");
	tree_21.LoadModel("obiecte_1\\copac_21.obj", "obiecte_1\\");
	tree_crown_21.LoadModel("obiecte_1\\coroana_21.obj", "obiecte_1\\");
	tree_22.LoadModel("obiecte_1\\copac_22.obj", "obiecte_1\\");
	tree_crown_22.LoadModel("obiecte_1\\coroana_22.obj", "obiecte_1\\");
	tree_23.LoadModel("obiecte_1\\copac_23.obj", "obiecte_1\\");
	tree_crown_23.LoadModel("obiecte_1\\coroana_23.obj", "obiecte_1\\");
	tree_24.LoadModel("obiecte_1\\copac_24.obj", "obiecte_1\\");
	tree_crown_24.LoadModel("obiecte_1\\coroana_24.obj", "obiecte_1\\");
    tree1_1.LoadModel("obiecte_1\\copac1_1.obj", "obiecte_1\\");
	tree1_2.LoadModel("obiecte_1\\copac1_2.obj", "obiecte_1\\");
	tree2_1.LoadModel("obiecte_1\\copac2_1.obj", "obiecte_1\\");
	tree2_2.LoadModel("obiecte_1\\copac2_2.obj", "obiecte_1\\");
	tree3_1.LoadModel("obiecte_1\\copac3_1.obj", "obiecte_1\\");
	tree3_2.LoadModel("obiecte_1\\copac3_2.obj", "obiecte_1\\");
    tree4_1.LoadModel("obiecte_1\\copac4_1.obj", "obiecte_1\\");
	tree4_2.LoadModel("obiecte_1\\copac4_2.obj", "obiecte_1\\");
	tree5_1.LoadModel("obiecte_1\\copac5_1.obj", "obiecte_1\\");
	tree5_2.LoadModel("obiecte_1\\copac5_2.obj", "obiecte_1\\");
	tree6_1.LoadModel("obiecte_1\\copac6_1.obj", "obiecte_1\\");
	tree6_2.LoadModel("obiecte_1\\copac6_2.obj", "obiecte_1\\");
	tree7_1.LoadModel("obiecte_1\\copac7_1.obj", "obiecte_1\\");
	tree7_2.LoadModel("obiecte_1\\copac7_2.obj", "obiecte_1\\");
	tree8_1.LoadModel("obiecte_1\\copac8_1.obj", "obiecte_1\\");
	tree8_2.LoadModel("obiecte_1\\copac8_2.obj", "obiecte_1\\");
	tree9_1.LoadModel("obiecte_1\\copac9_1.obj", "obiecte_1\\");
	tree9_2.LoadModel("obiecte_1\\copac9_2.obj", "obiecte_1\\");
	tree10_1.LoadModel("obiecte_1\\copac10_1.obj", "obiecte_1\\");
	tree10_2.LoadModel("obiecte_1\\copac10_2.obj", "obiecte_1\\");
	tree11_1.LoadModel("obiecte_1\\copac11_1.obj", "obiecte_1\\");
	tree11_2.LoadModel("obiecte_1\\copac11_2.obj", "obiecte_1\\");
	tree12_1.LoadModel("obiecte_1\\copac12_1.obj", "obiecte_1\\");
	tree12_2.LoadModel("obiecte_1\\copac12_2.obj", "obiecte_1\\");
	tree13_1.LoadModel("obiecte_1\\copac13_1.obj", "obiecte_1\\");
	tree13_2.LoadModel("obiecte_1\\copac13_2.obj", "obiecte_1\\");
	tree14_1.LoadModel("obiecte_1\\copac14_1.obj", "obiecte_1\\");
	tree14_2.LoadModel("obiecte_1\\copac14_2.obj", "obiecte_1\\");
	tree15_1.LoadModel("obiecte_1\\copac15_1.obj", "obiecte_1\\");
	tree15_2.LoadModel("obiecte_1\\copac15_2.obj", "obiecte_1\\");
	tree16_1.LoadModel("obiecte_1\\copac16_1.obj", "obiecte_1\\");
	tree16_2.LoadModel("obiecte_1\\copac16_2.obj", "obiecte_1\\");
	tree17_1.LoadModel("obiecte_1\\copac17_1.obj", "obiecte_1\\");
	tree17_2.LoadModel("obiecte_1\\copac17_2.obj", "obiecte_1\\");
	tufis_4.LoadModel("obiecte_1\\tufis_4.obj", "obiecte_1\\");
	tufis_5.LoadModel("obiecte_1\\tufis_5.obj", "obiecte_1\\");
	tufis_6.LoadModel("obiecte_1\\tufis_6.obj", "obiecte_1\\");
	tufis_7.LoadModel("obiecte_1\\tufis_7.obj", "obiecte_1\\");
	tufis_8.LoadModel("obiecte_1\\tufis_8.obj", "obiecte_1\\");
	tufis_9.LoadModel("obiecte_1\\tufis_9.obj", "obiecte_1\\");
	tufis_10.LoadModel("obiecte_1\\tufis_10.obj", "obiecte_1\\");
	tufis_11.LoadModel("obiecte_1\\tufis_11.obj", "obiecte_1\\");
	tufis_12.LoadModel("obiecte_1\\tufis_12.obj", "obiecte_1\\");
	tufis_13.LoadModel("obiecte_1\\tufis_13.obj", "obiecte_1\\");
	tufis_14.LoadModel("obiecte_1\\tufis_14.obj", "obiecte_1\\");
	tufis_15.LoadModel("obiecte_1\\tufis_15.obj", "obiecte_1\\");
	tufis_16.LoadModel("obiecte_1\\tufis_16.obj", "obiecte_1\\");
	tufis_17.LoadModel("obiecte_1\\tufis_17.obj", "obiecte_1\\");
	tufis_18.LoadModel("obiecte_1\\tufis_17.obj", "obiecte_1\\");
	tufis_19.LoadModel("obiecte_1\\tufis_17.obj", "obiecte_1\\");
	tufis_20.LoadModel("obiecte_1\\tufis_17.obj", "obiecte_1\\");
    frunze_1.LoadModel("obiecte_1\\frunze_1.obj", "obiecte_1\\");
	frunze_2.LoadModel("obiecte_1\\frunze_2.obj", "obiecte_1\\");
	frunze_3.LoadModel("obiecte_1\\frunze_3.obj", "obiecte_1\\");
	frunze_4.LoadModel("obiecte_1\\frunze_4.obj", "obiecte_1\\");
	frunze_5.LoadModel("obiecte_1\\frunze_5.obj", "obiecte_1\\");
	frunze_6.LoadModel("obiecte_1\\frunze_6.obj", "obiecte_1\\");
	frunze_7.LoadModel("obiecte_1\\frunze_7.obj", "obiecte_1\\");
	frunze_8.LoadModel("obiecte_1\\frunze_8.obj", "obiecte_1\\");
	frunze_9.LoadModel("obiecte_1\\frunze_9.obj", "obiecte_1\\");
	frunze_10.LoadModel("obiecte_1\\frunze_10.obj", "obiecte_1\\");
	frunze_11.LoadModel("obiecte_1\\frunze_11.obj", "obiecte_1\\");
	frunze_12.LoadModel("obiecte_1\\frunze_12.obj", "obiecte_1\\");
	cityvine_1.LoadModel("obiecte_1\\cityvine_1.obj", "obiecte_1\\");
	cityvine_2.LoadModel("obiecte_1\\cityvine_2.obj", "obiecte_1\\");
	cityvine_3.LoadModel("obiecte_1\\cityvine_3.obj", "obiecte_1\\");
	cityvine_4.LoadModel("obiecte_1\\cityvine_4.obj", "obiecte_1\\");
	cityvine_5.LoadModel("obiecte_1\\cityvine_5.obj", "obiecte_1\\");
	cityvine_6.LoadModel("obiecte_1\\cityvine_6.obj", "obiecte_1\\");
	cityvine_7.LoadModel("obiecte_1\\cityvine_7.obj", "obiecte_1\\");
	cityvine_8.LoadModel("obiecte_1\\cityvine_8.obj", "obiecte_1\\");
	cityvine_9.LoadModel("obiecte_1\\cityvine_9.obj", "obiecte_1\\");
	cityvine_10.LoadModel("obiecte_1\\cityvine_10.obj", "obiecte_1\\");
	cityvine_11.LoadModel("obiecte_1\\cityvine_11.obj", "obiecte_1\\");
	cityvine_12.LoadModel("obiecte_1\\cityvine_12.obj", "obiecte_1\\");
	cityvine_13.LoadModel("obiecte_1\\cityvine_13.obj", "obiecte_1\\");
	cityvine_14.LoadModel("obiecte_1\\cityvine_14.obj", "obiecte_1\\");
    cityvine_15.LoadModel("obiecte_1\\cityvine_15.obj", "obiecte_1\\");
	cityvine_16.LoadModel("obiecte_1\\cityvine_16.obj", "obiecte_1\\");
	cityvine_17.LoadModel("obiecte_1\\cityvine_17.obj", "obiecte_1\\");
	cityvine_18.LoadModel("obiecte_1\\cityvine_18.obj", "obiecte_1\\");
	cityvine_19.LoadModel("obiecte_1\\cityvine_19.obj", "obiecte_1\\");
	cityvine_20.LoadModel("obiecte_1\\cityvine_20.obj", "obiecte_1\\");
	ivy_1.LoadModel("obiecte_1\\ivy_1.obj", "obiecte_1\\");
	ivy_2.LoadModel("obiecte_1\\ivy_2.obj", "obiecte_1\\");
	ivy_3.LoadModel("obiecte_1\\ivy_3.obj", "obiecte_1\\");
	ivy_4.LoadModel("obiecte_1\\ivy_4.obj", "obiecte_1\\");
	ivy_5.LoadModel("obiecte_1\\ivy_5.obj", "obiecte_1\\");
	ivy_6.LoadModel("obiecte_1\\ivy_6.obj", "obiecte_1\\");
	ivy_7.LoadModel("obiecte_1\\ivy_7.obj", "obiecte_1\\");
	ivy_8.LoadModel("obiecte_1\\ivy_8.obj", "obiecte_1\\");
	ivy_9.LoadModel("obiecte_1\\ivy_9.obj", "obiecte_1\\");
	ivy_10.LoadModel("obiecte_1\\ivy_10.obj", "obiecte_1\\");
	ivy_11.LoadModel("obiecte_1\\ivy_11.obj", "obiecte_1\\");
	ivy_12.LoadModel("obiecte_1\\ivy_12.obj", "obiecte_1\\");
	ivy_13.LoadModel("obiecte_1\\ivy_13.obj", "obiecte_1\\");
	ivy_14.LoadModel("obiecte_1\\ivy_14.obj", "obiecte_1\\");
	ivy_15.LoadModel("obiecte_1\\ivy_15.obj", "obiecte_1\\");
	ivy_16.LoadModel("obiecte_1\\ivy_16.obj", "obiecte_1\\");
	ivy_17.LoadModel("obiecte_1\\ivy_17.obj", "obiecte_1\\");
	ivy_18.LoadModel("obiecte_1\\ivy_18.obj", "obiecte_1\\");
	ivy_19.LoadModel("obiecte_1\\ivy_19.obj", "obiecte_1\\");
	ivy_20.LoadModel("obiecte_1\\ivy_20.obj", "obiecte_1\\");
	ivy_21.LoadModel("obiecte_1\\ivy_21.obj", "obiecte_1\\");
	ivy_22.LoadModel("obiecte_1\\ivy_22.obj", "obiecte_1\\");
	ivy_23.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_24.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_25.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_26.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_27.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_28.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_29.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_30.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_31.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_32.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_33.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_34.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_35.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	ivy_36.LoadModel("obiecte_1\\ivy_23.obj", "obiecte_1\\");
	waterivy_1.LoadModel("obiecte_1\\waterivy_1.obj", "obiecte_1\\");
	waterivy_2.LoadModel("obiecte_1\\waterivy_2.obj", "obiecte_1\\");
	waterivy_3.LoadModel("obiecte_1\\waterivy_3.obj", "obiecte_1\\");
	waterivy_4.LoadModel("obiecte_1\\waterivy_4.obj", "obiecte_1\\");
	waterivy_5.LoadModel("obiecte_1\\waterivy_5.obj", "obiecte_1\\");
	waterivy_6.LoadModel("obiecte_1\\waterivy_6.obj", "obiecte_1\\");
	waterivy_7.LoadModel("obiecte_1\\waterivy_7.obj", "obiecte_1\\");
	waterivy_8.LoadModel("obiecte_1\\waterivy_8.obj", "obiecte_1\\");
	steag_1.LoadModel("obiecte_1\\steag_1.obj", "obiecte_1\\");
	steag_2.LoadModel("obiecte_1\\steag_2.obj", "obiecte_1\\");
	steag_3.LoadModel("obiecte_1\\steag_3.obj", "obiecte_1\\");
	awning_1.LoadModel("obiecte_1\\awning_1.obj", "obiecte_1\\");
	awning_2.LoadModel("obiecte_1\\awning_2.obj", "obiecte_1\\");
	awning_3.LoadModel("obiecte_1\\awning_3.obj", "obiecte_1\\");
	awning_4.LoadModel("obiecte_1\\awning_4.obj", "obiecte_1\\");
	flori_1.LoadModel("obiecte_1\\flori_1.obj", "obiecte_1\\");
	flori_2.LoadModel("obiecte_1\\flori_2.obj", "obiecte_1\\");
	flori_3.LoadModel("obiecte_1\\flori_3.obj", "obiecte_1\\");
	flori_4.LoadModel("obiecte_1\\flori_4.obj", "obiecte_1\\");
	flori_5.LoadModel("obiecte_1\\flori_5.obj", "obiecte_1\\");
	flori_6.LoadModel("obiecte_1\\flori_6.obj", "obiecte_1\\");
	flori_7.LoadModel("obiecte_1\\flori_7.obj", "obiecte_1\\");
	flori_8.LoadModel("obiecte_1\\flori_8.obj", "obiecte_1\\");
	flori_9.LoadModel("obiecte_1\\flori_9.obj", "obiecte_1\\");
	flori_10.LoadModel("obiecte_1\\flori_10.obj", "obiecte_1\\");
    copac_f.LoadModel("obiecte_1\\copac_f.obj", "obiecte_1\\");
	planta_1.LoadModel("obiecte_1\\planta_1.obj", "obiecte_1\\");
	planta_2.LoadModel("obiecte_1\\planta_2.obj", "obiecte_1\\");
	planta_3.LoadModel("obiecte_1\\planta_3.obj", "obiecte_1\\");
	planta_4.LoadModel("obiecte_1\\planta_4.obj", "obiecte_1\\");
	planta_5.LoadModel("obiecte_1\\planta_5.obj", "obiecte_1\\");
	planta_6.LoadModel("obiecte_1\\planta_6.obj", "obiecte_1\\");
	planta_7.LoadModel("obiecte_1\\planta_7.obj", "obiecte_1\\");
	planta_8.LoadModel("obiecte_1\\planta_8.obj", "obiecte_1\\");
	planta_9.LoadModel("obiecte_1\\planta_9.obj", "obiecte_1\\");
	planta_10.LoadModel("obiecte_1\\planta_10.obj", "obiecte_1\\");
	planta_11.LoadModel("obiecte_1\\planta_11.obj", "obiecte_1\\");
	planta_12.LoadModel("obiecte_1\\planta_12.obj", "obiecte_1\\");
	planta_13.LoadModel("obiecte_1\\planta_13.obj", "obiecte_1\\");
	planta_14.LoadModel("obiecte_1\\planta_14.obj", "obiecte_1\\");
	planta_15.LoadModel("obiecte_1\\planta_15.obj", "obiecte_1\\");
	planta_16.LoadModel("obiecte_1\\planta_16.obj", "obiecte_1\\");
	planta_17.LoadModel("obiecte_1\\planta_17.obj", "obiecte_1\\");
	planta_18.LoadModel("obiecte_1\\planta_18.obj", "obiecte_1\\");
	casa_1.LoadModel("obiecte_1\\casa_1.obj", "obiecte_1\\");
	casa_2.LoadModel("obiecte_1\\casa_2.obj", "obiecte_1\\");
	casa_3.LoadModel("obiecte_1\\casa_3.obj", "obiecte_1\\");
	casa_4.LoadModel("obiecte_1\\casa_4.obj", "obiecte_1\\");
	casa_5.LoadModel("obiecte_1\\casa_5.obj", "obiecte_1\\");
	casa_6.LoadModel("obiecte_1\\casa_6.obj", "obiecte_1\\");
	casa_7.LoadModel("obiecte_1\\casa_7.obj", "obiecte_1\\");
	casa_8.LoadModel("obiecte_1\\casa_8.obj", "obiecte_1\\");
	casa_9.LoadModel("obiecte_1\\casa_9.obj", "obiecte_1\\");
	casa_10.LoadModel("obiecte_1\\casa_10.obj", "obiecte_1\\");
	casa_11.LoadModel("obiecte_1\\casa_11.obj", "obiecte_1\\");
	nuferi_1.LoadModel("obiecte_1\\nuferi_1.obj", "obiecte_1\\");
	nuferi_2.LoadModel("obiecte_1\\nuferi_2.obj", "obiecte_1\\");
	nuferi_3.LoadModel("obiecte_1\\nuferi_3.obj", "obiecte_1\\");
	nuferi_4.LoadModel("obiecte_1\\nuferi_4.obj", "obiecte_1\\");
	nuferi_5.LoadModel("obiecte_1\\nuferi_5.obj", "obiecte_1\\");
	nuferi_6.LoadModel("obiecte_1\\nuferi_6.obj", "obiecte_1\\");
	nuferi_7.LoadModel("obiecte_1\\nuferi_7.obj", "obiecte_1\\");
	nuferi_8.LoadModel("obiecte_1\\nuferi_8.obj", "obiecte_1\\");
	nuferi_9.LoadModel("obiecte_1\\nuferi_9.obj", "obiecte_1\\");
	nuferi_10.LoadModel("obiecte_1\\nuferi_10.obj", "obiecte_1\\");
	nuferi_11.LoadModel("obiecte_1\\nuferi_11.obj", "obiecte_1\\");
	topiar_1.LoadModel("obiecte_1\\topiar_1.obj", "obiecte_1\\");
	topiar_2.LoadModel("obiecte_1\\topiar_2.obj", "obiecte_1\\");
	topiar_3.LoadModel("obiecte_1\\topiar_3.obj", "obiecte_1\\");
	topiar_4.LoadModel("obiecte_1\\topiar_4.obj", "obiecte_1\\");
	topiar_5.LoadModel("obiecte_1\\topiar_5.obj", "obiecte_1\\");
	topiar_6.LoadModel("obiecte_1\\topiar_6.obj", "obiecte_1\\");
	topiar_7.LoadModel("obiecte_1\\topiar_7.obj", "obiecte_1\\");
	topiar_8.LoadModel("obiecte_1\\topiar_8.obj", "obiecte_1\\");
	grass.LoadModel("obiecte_1\\iarba.obj", "obiecte_1\\");
	vie.LoadModel("obiecte_1\\vita.obj", "obiecte_1\\");


	water.LoadModel("obiecte_1\\apa.obj", "obiecte_1\\");
	ground.LoadModel("objects/ground/ground.obj");
	lightCube.LoadModel("objects/cube/cube.obj");
	//screenQuad.LoadModel("objects/quad/quad.obj");
}

void initShaders() {
	myCustomShader.loadShader("shaders/shaderStart.vert", "shaders/shaderStart.frag");
	myCustomShader.useShaderProgram();
	lightShader.loadShader("shaders/lightCube.vert", "shaders/lightCube.frag");
	lightShader.useShaderProgram();
	screenQuadShader.loadShader("shaders/screenQuad.vert", "shaders/screenQuad.frag");
	screenQuadShader.useShaderProgram();
	skyboxShader.loadShader("shaders/skyboxShader.vert", "shaders/skyboxShader.frag");
	skyboxShader.useShaderProgram();
	depthShader.loadShader("shaders/depth.vert", "shaders/depth.frag");
	depthShader.useShaderProgram();
	copac.loadShader("shaders/trees.vert", "shaders/trees.frag");
	copac.useShaderProgram();
	reflexie.loadShader("shaders/reflexie.vert", "shaders/reflexie.frag");
	reflexie.useShaderProgram();
	
}

void initUniforms() {
	myCustomShader.useShaderProgram();
	
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	modelLoc = glGetUniformLocation(myCustomShader.shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	
	view = myCamera.getViewMatrix();
	viewLoc = glGetUniformLocation(myCustomShader.shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));


	
	normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
	normalMatrixLoc = glGetUniformLocation(myCustomShader.shaderProgram, "normalMatrix");
	glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	projectionLoc = glGetUniformLocation(myCustomShader.shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));


	//set the light direction (direction towards the light)
	//lightDir = glm::vec3(0.0f, 1.0f, 1.0f);
	lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightDir = glm::vec3(-16.392496, 690.310120, 400.604858);
	lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	lightDirLoc = glGetUniformLocation(myCustomShader.shaderProgram, "lightDir");	
	glUniform3fv(lightDirLoc, 1, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "fog"), fog);

	//set light color
	//lightColor = glm::vec3(1.0f, 0.0f, 1.0f); //purple light
	lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	lightColorLoc = glGetUniformLocation(myCustomShader.shaderProgram, "lightColor");
	glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));

	//lumina felinar
	glm::vec3 lightPosition = glm::vec3(-11.984890, -55.877903, 67.224266);
	GLuint pointLightPosition1Loc = glGetUniformLocation(myCustomShader.shaderProgram, "lightPosition");
	glUniform3fv(pointLightPosition1Loc, 1, glm::value_ptr(lightPosition));

	glm::vec3 felinar_1 = glm::vec3(-6.000000, -41.999977, 139.000000);
	GLuint point_felinar_1_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_1");
	glUniform3fv(point_felinar_1_position, 1, glm::value_ptr(felinar_1));

	glm::vec3 felinar_2 = glm::vec3(-25.606651, -42.908752, 127.253700);
	GLuint point_felinar_2_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_2");
	glUniform3fv(point_felinar_2_position, 1, glm::value_ptr(felinar_2));

	glm::vec3 felinar_3 = glm::vec3(46.000000, -52.399967, 79.000000);
	GLuint point_felinar_3_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_3");
	glUniform3fv(point_felinar_3_position, 1, glm::value_ptr(felinar_3));

	glm::vec3 felinar_4 = glm::vec3(58.140846, -52.092056, 82.126076);
	GLuint point_felinar_4_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_4");
	glUniform3fv(point_felinar_4_position, 1, glm::value_ptr(felinar_4));

	glm::vec3 felinar_5 = glm::vec3(59.187740, -55.003815, 47.116459);
	GLuint point_felinar_5_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_5");
	glUniform3fv(point_felinar_5_position, 1, glm::value_ptr(felinar_5));

	glm::vec3 felinar_6 = glm::vec3(62.869335, -54.275284, 12.692766);
	GLuint point_felinar_6_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_6");
	glUniform3fv(point_felinar_6_position, 1, glm::value_ptr(felinar_6));

	glm::vec3 felinar_7= glm::vec3(63.779190, -54.471855, -2.361077);
	GLuint point_felinar_7_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_7");
	glUniform3fv(point_felinar_7_position, 1, glm::value_ptr(felinar_7));

	glm::vec3 felinar_8 = glm::vec3(157.391525, -54.606792, 42.873486);
	GLuint point_felinar_8_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_8");
	glUniform3fv(point_felinar_8_position, 1, glm::value_ptr(felinar_8));

	glm::vec3 felinar_9 = glm::vec3(134.144928, -56.181778, 12.465664);
	GLuint point_felinar_9_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_9");
	glUniform3fv(point_felinar_9_position, 1, glm::value_ptr(felinar_9));

	glm::vec3 felinar_10 = glm::vec3(101.673843, -53.992264, 12.469846);
	GLuint point_felinar_10_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_10");
	glUniform3fv(point_felinar_10_position, 1, glm::value_ptr(felinar_10));

	glm::vec3 felinar_11 = glm::vec3(104.404274, -55.238239, -0.336106);
	GLuint point_felinar_11_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_11");
	glUniform3fv(point_felinar_11_position, 1, glm::value_ptr(felinar_11));

	glm::vec3 felinar_12 = glm::vec3(133.458221, -55.746891, 2.597692);
	GLuint point_felinar_12_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_12");
	glUniform3fv(point_felinar_12_position, 1, glm::value_ptr(felinar_12));

	glm::vec3 felinar_13 = glm::vec3(163.613586, -55.399929, -25.441666);
	GLuint point_felinar_13_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_13");
	glUniform3fv(point_felinar_13_position, 1, glm::value_ptr(felinar_13));

	glm::vec3 felinar_14 = glm::vec3(163.472961, -55.403709, 78.141441);
	GLuint point_felinar_14_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_14");
	glUniform3fv(point_felinar_14_position, 1, glm::value_ptr(felinar_14));

	glm::vec3 felinar_15 = glm::vec3(159.746841, -54.748566, -53.906120);
	GLuint point_felinar_15_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_15");
	glUniform3fv(point_felinar_15_position, 1, glm::value_ptr(felinar_15));

	glm::vec3 felinar_16 = glm::vec3(175.378098, -55.352558, -57.202652);
	GLuint point_felinar_16_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_16");
	glUniform3fv(point_felinar_16_position, 1, glm::value_ptr(felinar_16));

	glm::vec3 felinar_17 = glm::vec3(173.141388, -59.797867, -17.165998);
	GLuint point_felinar_17_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_17");
	glUniform3fv(point_felinar_17_position, 1, glm::value_ptr(felinar_17));
	
	glm::vec3 felinar_18 = glm::vec3(170.218216, -60.096371, 37.592442);
	GLuint point_felinar_18_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_18");
	glUniform3fv(point_felinar_18_position, 1, glm::value_ptr(felinar_18));

	glm::vec3 felinar_19 = glm::vec3(146.410431, -60.402683, 11.389699);
	GLuint point_felinar_19_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_19");
	glUniform3fv(point_felinar_19_position, 1, glm::value_ptr(felinar_19));

	glm::vec3 felinar_20 = glm::vec3(148.019470, -60.402683, 9.595494);
	GLuint point_felinar_20_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_20");
	glUniform3fv(point_felinar_20_position, 1, glm::value_ptr(felinar_20));

	glm::vec3 felinar_21 = glm::vec3(146.685135, -55.287155, 74.069756);
	GLuint point_felinar_21_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_21");
	glUniform3fv(point_felinar_21_position, 1, glm::value_ptr(felinar_21));

	glm::vec3 felinar_22 = glm::vec3(141.010956, -51.584274, 103.873116);
	GLuint point_felinar_22_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_22");
	glUniform3fv(point_felinar_22_position, 1, glm::value_ptr(felinar_22));

	glm::vec3 felinar_23 = glm::vec3(154.041260, -51.953350, 107.067520);
	GLuint point_felinar_23_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_23");
	glUniform3fv(point_felinar_23_position, 1, glm::value_ptr(felinar_23));

	glm::vec3 felinar_24 = glm::vec3(172.960876, -60.402683, -8.166500);
	GLuint point_felinar_24_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_24");
	glUniform3fv(point_felinar_24_position, 1, glm::value_ptr(felinar_24));

	glm::vec3 felinar_25 = glm::vec3(174.362930, -60.402683, -15.298611);
	GLuint point_felinar_25_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_25");
	glUniform3fv(point_felinar_25_position, 1, glm::value_ptr(felinar_24));

	glm::vec3 felinar_26 = glm::vec3(107.040810, -60.402683, 108.510849);
	GLuint point_felinar_26_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_26");
	glUniform3fv(point_felinar_26_position, 1, glm::value_ptr(felinar_26));

	glm::vec3 felinar_27 = glm::vec3(86.128616, -60.402683, 91.976486);
	GLuint point_felinar_27_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_27");
	glUniform3fv(point_felinar_27_position, 1, glm::value_ptr(felinar_27));

	glm::vec3 felinar_28 = glm::vec3(102.548790, -40.790939, 229.801331);
	GLuint point_felinar_28_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_28");
	glUniform3fv(point_felinar_28_position, 1, glm::value_ptr(felinar_28));

	glm::vec3 felinar_29 = glm::vec3(122.202110, -40.931255, 213.958206);
	GLuint point_felinar_29_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_29");
	glUniform3fv(point_felinar_29_position, 1, glm::value_ptr(felinar_29));

	glm::vec3 felinar_30 = glm::vec3(38.748806, -60.144756, 142.256210);
	GLuint point_felinar_30_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_30");
	glUniform3fv(point_felinar_30_position, 1, glm::value_ptr(felinar_30));

	glm::vec3 felinar_31 = glm::vec3(21.372162, -60.531654, 152.092789);
	GLuint point_felinar_31_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_31");
	glUniform3fv(point_felinar_31_position, 1, glm::value_ptr(felinar_31));

	glm::vec3 felinar_32 = glm::vec3(29.131329, -61.073116, 155.421829);
	GLuint point_felinar_32_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_32");
	glUniform3fv(point_felinar_32_position, 1, glm::value_ptr(felinar_32));

	glm::vec3 felinar_33 = glm::vec3(68.897316, -60.785625, 154.847916);
	GLuint point_felinar_33_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_33");
	glUniform3fv(point_felinar_33_position, 1, glm::value_ptr(felinar_33));

	glm::vec3 felinar_34 = glm::vec3(65.557938, -61.109623, 175.765213);
	GLuint point_felinar_34_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_34");
	glUniform3fv(point_felinar_34_position, 1, glm::value_ptr(felinar_34));

	glm::vec3 felinar_35 = glm::vec3(71.718903, -61.093922, 179.759354);
	GLuint point_felinar_35_position = glGetUniformLocation(myCustomShader.shaderProgram, "felinar_35");
	glUniform3fv(point_felinar_35_position, 1, glm::value_ptr(felinar_35));


	lightShader.useShaderProgram();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//copaci si iarba
	 copac.useShaderProgram();
	 model = glm::mat4(1.0f);
	 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	 glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	 view = myCamera.getViewMatrix_2();
	 glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));

	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view* lightRotation))* lightDir));
    glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));


	//apa
	reflexie.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(reflexie.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	cameraPos = myCamera.getCameraPosition();
	glUniformMatrix4fv(glGetUniformLocation(reflexie.shaderProgram, "cameraPos"), 1, GL_FALSE, glm::value_ptr(cameraPos));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(reflexie.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));

	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(reflexie.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	glUniformMatrix3fv(glGetUniformLocation(myCustomShader.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	


	//myCustomShader.useShaderProgram();

}

void initFBO() {
	//TODO - Create the FBO, the depth texture and attach the depth texture to the FBO
	//generate FBO ID
	glGenFramebuffers(1, &shadowMapFBO);

	//create depth texture for FBO
	glGenTextures(1, &depthMapTexture);
	glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
		SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

	//attach texture to FBO
	glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMapTexture,0);

	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

glm::mat4 computeLightSpaceTrMatrix() {
	//TODO - Return the light-space transformation matrix
	glm::mat4 lightView = glm::lookAt(glm::inverseTranspose(glm::mat3(lightRotation)) * lightDir, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	const GLfloat near_plane = 0.1f, far_plane = 1000.0f;
	glm::mat4 lightProjection = glm::ortho(-500.0f, 500.0f, -500.0f,500.0f, near_plane, far_plane);//laturile piramidei
	//far_plane 
	glm::mat4 lightSpaceTrMatrix = lightProjection * lightView;
	return lightSpaceTrMatrix;
}

void drawObjects(gps::Shader shader, bool depthPass) {
		
	shader.useShaderProgram();
	
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	nanosuit.Draw(shader);

	//miscare zana
	if (zana_move == true)
	{
		if (stanga)
		{
			rotate_zana + 34;
			//stanga = false;
			zana_x = zana_x + 0.06;
			zana_y = zana_y + 0.05;
			model = glm::mat4(1.0f);
		
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(zana_x, -70, zana_y));
			//model = glm::translate(model, glm::vec3(66.455, -32.089, -48.561));
			model = glm::translate(model, glm::vec3(-66.455, 32.089, 48.561));
			model = glm::rotate(model, glm::radians(rotate_zana), glm::vec3(0.0f, 0.0f, 1.0f));
			model = glm::translate(model, glm::vec3(66.455, -32.089, -48.561));
			/*model = glm::translate(model, glm::vec3(66.455, -32.089, -48.561));
			model = glm::translate(model, glm::vec3(-66.455 + zana_x, 32.089 + 70, 48.561 + zana_y));
			model = glm::rotate(model, glm::radians(rotate_zana), glm::vec3(0.0f, 0.0f, 1.0f));
			model = glm::translate(model, glm::vec3(66.455 - zana_x, -32.089 + 70, -48.561 - zana_y));
			model = glm::translate(model, glm::vec3(zana_x, -70, zana_y));*/
			
			glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
			aripi.Draw(shader);

			

			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, -70, 0.0f));
			model = glm::translate(model, glm::vec3(zana_x, 0.0, zana_y));
			glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
			zana.Draw(myCustomShader);
			
		}
	    else{
			rotate_zana - 68;
			stanga = true;
			zana_x = zana_x + 0.06;
			zana_y = zana_y + 0.05;
			model = glm::mat4(1.0f);

			model = glm::translate(model, glm::vec3(zana_x, -70, zana_y));
			//model = glm::translate(model, glm::vec3(66.455, -32.089, -48.561));
			model = glm::translate(model, glm::vec3(-66.455, 32.089, 48.561));
			model = glm::rotate(model, glm::radians(rotate_zana), glm::vec3(0.0f, 0.0f, 1.0f));
			//model = glm::translate(model, glm::vec3(66.455, -32.089, -48.561));
			model = glm::translate(model, glm::vec3(66.455, -32.089, -48.561));
			/*model = glm::translate(model, glm::vec3(-66.455+zana_x, 32.089+70, 48.561+zana_y));
			model = glm::rotate(model, glm::radians(rotate_zana), glm::vec3(0.0f, 0.0f, 1.0f));
			model = glm::translate(model, glm::vec3(66.455-zana_x, -32.089+70, -48.561-zana_y));
            model = glm::translate(model, glm::vec3(zana_x, -70, zana_y));*/

			glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
			aripi.Draw(shader);

			//glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
			//aripi.Draw(shader);

			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, -70, 0.0f));
			model = glm::translate(model, glm::vec3(zana_x, 0.0f, zana_y));
			glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
			zana.Draw(myCustomShader);

		}
		
		
	}
	else
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -70, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		zana.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -70, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		aripi.Draw(myCustomShader);

	}
	//miscare barca
	if (move_boat == true)
	{

	
		model = glm::mat4(1.0f);
	    model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	  
		move_x = move_x - 0.06;
		move_y = move_y + 0.005;
		model = glm::translate(model, glm::vec3(move_x, 0.0f, move_y));
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		//std::cout << "x"<<move_x << "/n";
		//std::cout << "y" << move_y << "/n";
		if (!depthPass) {
			normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
			glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
		}
		barca.Draw(shader);
		if (move_x <= -129.118)
		{
			move_x = 0;
			move_y = 0;
		}

	}
	else{
		model = glm::mat4(1.0f);
		model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		barca.Draw(shader);
		move_x = 0;
		move_y = 0;

	}
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa2_1.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa2_2.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa2_3.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa_1.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa_2.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa_3.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa_4.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}
	casa_5.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa_6.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa_7.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa_8.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa_9.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa_10.Draw(shader);

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));

	// do not send the normal matrix if we are rendering in the depth map
	if (!depthPass) {
		normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
		glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	}

	casa_11.Draw(shader);

	copac.useShaderProgram();

	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view* lightRotation))* lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(myCustomShader.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	nuferi_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	////lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));

	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(myCustomShader.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	nuferi_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	nuferi_3.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	nuferi_4.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	nuferi_5.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	nuferi_6.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	/*lightDir = glm::vec3(37.877537, 86.888863, 135.304535);*/
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	nuferi_7.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	nuferi_8.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	nuferi_9.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	nuferi_10.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	nuferi_11.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_1.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_3.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_4.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_5.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	////bind the shadow map
	//glActiveTexture(GL_TEXTURE3);
	//glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_6.Draw(copac);

	copac.useShaderProgram(); 
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_7.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_8.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_9.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_10.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_11.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_12.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_13.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_14.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_15.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_16.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_17.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	planta_18.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	topiar_1.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	topiar_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	topiar_3.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	topiar_4.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	topiar_5.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	topiar_6.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	/*lightDir = glm::vec3(37.877537, 86.888863, 135.304535);*/
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	topiar_7.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	topiar_8.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	cityvine_1.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	cityvine_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	cityvine_3.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	cityvine_4.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	cityvine_5.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	cityvine_6.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	cityvine_7.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	cityvine_8.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	cityvine_9.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	cityvine_10.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	cityvine_11.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	cityvine_12.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	cityvine_13.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	cityvine_14.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	cityvine_15.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	cityvine_16.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	cityvine_17.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	cityvine_18.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	cityvine_19.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	cityvine_20.Draw(copac);




	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_1.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_2.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_3.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_4.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_5.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_6.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_7.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_8.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_9.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_10.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_11.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	frunze_12.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	grass.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_4.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_5.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_6.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_7.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_8.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_9.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_10.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_11.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_12.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_13.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_14.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_15.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_16.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_17.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_18.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_19.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tufis_20.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	vie.Draw(copac);



	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_1.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_2.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_3.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_3.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_4.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_4.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_5.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_5.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_6.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_6.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_7.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_7.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_8.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_8.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_9.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_9.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_10.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_10.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_11.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_11.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_12.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_12.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_13.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_13.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_14.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_14.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_15.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_15.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_16.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_16.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_17.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_17.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_18.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_18.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_19.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_19.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_20.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_20.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_21.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_21.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_22.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_22.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_23.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_23.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_24.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree_crown_24.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree1_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree1_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree2_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree2_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree3_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree3_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree4_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree4_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree5_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree5_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree6_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree6_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree7_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree7_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree8_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree8_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree9_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree9_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree10_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree10_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree11_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree11_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree12_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree12_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree13_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree13_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree14_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree14_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree15_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree15_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree16_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree16_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree17_1.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	tree17_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	waterivy_1.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	waterivy_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	waterivy_3.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	waterivy_4.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	waterivy_5.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	waterivy_6.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	waterivy_7.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	waterivy_8.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_1.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_3.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_4.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_5.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_6.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_7.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_8.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_9.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_10.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_11.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_12.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_13.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_14.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_15.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_16.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_17.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_18.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_19.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_20.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_21.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_22.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_23.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_24.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_25.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_26.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_27.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_28.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_29.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_30.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_31.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_32.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_33.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_34.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_35.Draw(copac);
	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	ivy_36.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	steag_1.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	steag_2.Draw(copac);


	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	steag_3.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	awning_1.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	awning_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	awning_3.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	awning_4.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	copac_f.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	flori_1.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	flori_2.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	flori_3.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	flori_4.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	flori_5.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	flori_6.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	flori_7.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	flori_8.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	flori_9.Draw(copac);

	copac.useShaderProgram();
	model = glm::mat4(1.0f);
	model = glm::translate(glm::mat4(1.0f), glm::vec3(0, -70, 0));
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	//lightDir = glm::vec3(37.877537, 86.888863, 135.304535);
	//lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightDir"), 1, GL_FALSE, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));
	//glUniform1i(glGetUniformLocation(copac.shaderProgram, "fog"), fog);

	//lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //with light
	//glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightColor"), 1, GL_FALSE, glm::value_ptr(lightColor));
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(glGetUniformLocation(copac.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}
	flori_10.Draw(copac);


	
	//

	//
	//reflexie.useShaderProgram();
	//model= glm::mat4(1.0f);
	////model = glm::rotate(glm::mat4(1.0f), glm::radians(angleY), glm::vec3(0.0f, 1.0f, 0.0f));
	//glUniformMatrix4fv(glGetUniformLocation(reflexie.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	//glm::vec3 cameraPos = myCamera.getCameraPosition();
	//glUniformMatrix4fv(glGetUniformLocation(reflexie.shaderProgram, "cameraPos"), 1, GL_FALSE, glm::value_ptr(cameraPos));
	////mySkyBox.Load(faces);
	//water.Draw(shader);

	//model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f));
	//model = glm::scale(model, glm::vec3(0.5f));
	//glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	////mySkyBox.Load(faces);

	//// do not send the normal matrix if we are rendering in the depth map
	//if (!depthPass) {
	//	normalMatrix = glm::mat3(glm::inverseTranspose(view * model));
	//	glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));
	//}

	//ground.Draw(shader);	
}

void renderScene() {

	// depth maps creation pass
	//TODO - Send the light-space transformation matrix to the depth map creation shader and
	//		 render the scene in the depth map

	

	// render depth map on screen - toggled with the M key
	depthShader.useShaderProgram();
	glUniformMatrix4fv(glGetUniformLocation(depthShader.shaderProgram, "lightSpaceTrMatrix"),
		1,
		GL_FALSE,
		glm::value_ptr(computeLightSpaceTrMatrix()));
	glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
	glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
	glClear(GL_DEPTH_BUFFER_BIT);
	drawObjects(depthShader, true);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);


	if (showDepthMap) {
		glViewport(0, 0, retina_width, retina_height);

		glClear(GL_COLOR_BUFFER_BIT);

		screenQuadShader.useShaderProgram();

		//bind the depth map
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, depthMapTexture);
		glUniform1i(glGetUniformLocation(screenQuadShader.shaderProgram, "depthMap"), 0);

		glDisable(GL_DEPTH_TEST);
		screenQuad.Draw(screenQuadShader);
		glEnable(GL_DEPTH_TEST);
	}
	else {

		// final scene rendering pass (with shadows)

		glViewport(0, 0, retina_width, retina_height);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		myCustomShader.useShaderProgram();

		view = myCamera.getViewMatrix();
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
				
		lightRotation = glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f));
		glUniform3fv(lightDirLoc, 1, glm::value_ptr(glm::inverseTranspose(glm::mat3(view * lightRotation)) * lightDir));

		//bind the shadow map
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, depthMapTexture);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "shadowMap"), 3);

		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "lightSpaceTrMatrix"),1,GL_FALSE,glm::value_ptr(computeLightSpaceTrMatrix()));


		/*glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, depthMapTexture);
		glUniform1i(glGetUniformLocation(copac.shaderProgram, "shadowMap"), 3);

		glUniformMatrix4fv(glGetUniformLocation(copac.shaderProgram, "lightSpaceTrMatrix"), 1, GL_FALSE, glm::value_ptr(computeLightSpaceTrMatrix()));*/
        
		drawObjects(myCustomShader, false);

		

	
		
		//draw a white cube around the light

		lightShader.useShaderProgram();
        glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));

		model = lightRotation;
		model = glm::translate(model, 1.0f * lightDir);
		model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));
		glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
	    lightCube.Draw(lightShader);

		mySkyBox.Draw(skyboxShader, view, projection);

		reflexie.useShaderProgram();
		view = myCamera.getViewMatrix();
		glUniformMatrix4fv(glGetUniformLocation(reflexie.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
		cameraPos = myCamera.getCameraPosition();
		glUniformMatrix4fv(glGetUniformLocation(reflexie.shaderProgram, "cameraPos"), 1, GL_FALSE, glm::value_ptr(cameraPos));

		projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
		glUniformMatrix4fv(glGetUniformLocation(reflexie.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(reflexie.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		water.Draw(reflexie);

		myCustomShader.useShaderProgram();
		
		if (fog == true)
		{
			myCustomShader.useShaderProgram();
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "fog"), fog);
		}
		else {
			myCustomShader.useShaderProgram();
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "fog"), fog);
		}
		if (tasta_1)
		{
			pointLight = true;
			directLight = false;
			spotLight = false;
			lampa = false;

			myCustomShader.useShaderProgram();
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "pointLight"), pointLight);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "directLight"), directLight);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight"), spotLight);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);

		}
		if (tasta_2)
		{
			pointLight = false;
			directLight = true;
			spotLight = false;
			lampa = false;

			myCustomShader.useShaderProgram();
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "pontLight"), pointLight);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "directLight"), directLight);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight"), spotLight);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);
			/*if (lampa = true)
			{
				myCustomShader.useShaderProgram();
				glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);
			}
			else {
				
				myCustomShader.useShaderProgram();
				glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);
			}*/
		}
		if (tasta_3) {
			pointLight = true;
			directLight = false;
			spotLight = true;
			lampa = false;
			myCustomShader.useShaderProgram();
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "pontLight"), pointLight);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "directLight"), directLight);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight"), spotLight);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "lampa"), lampa);
		}

		if (presentation == true)
		{
			if (i < 39)
			{
				if (t >=0)
				{
					t = t - 0.01;
					camera_Position = camera_position[i] * t + camera_position[i + 1] * (1 - t);
					camera_Target = camera_target[i] * t + camera_target[i + 1] * (1-t);
					myCamera.setCameraPos(camera_Position);
					myCamera.setCameraTarget(camera_Target);
				}
				else {
					t = 1;
					i++;
				}
			}
		}

		//rain
		if (rain == true)
		{
			
			if (move >= -300)
			{
				generate_position();

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[0], ploaie_y[0], ploaie_z[0]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_0.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[1], ploaie_y[1], ploaie_z[1]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_1.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[2], ploaie_y[2], ploaie_z[2]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_2.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[3], ploaie_y[3], ploaie_z[3]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_3.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[4], ploaie_y[4], ploaie_z[4]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_4.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[5], ploaie_y[5], ploaie_z[5]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_5.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[6], ploaie_y[6], ploaie_z[6]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_6.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[7], ploaie_y[7], ploaie_z[7]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_7.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[8], ploaie_y[8], ploaie_z[8]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_8.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[9], ploaie_y[9], ploaie_z[9]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_9.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[10], ploaie_y[10], ploaie_z[10]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_10.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[11], ploaie_y[11], ploaie_z[11]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_11.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[12], ploaie_y[12], ploaie_z[12]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_12.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[13], ploaie_y[13], ploaie_z[13]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_13.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[14], ploaie_y[14], ploaie_z[14]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_14.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[15], ploaie_y[15], ploaie_z[15]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_15.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[16], ploaie_y[16], ploaie_z[16]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_16.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[17], ploaie_y[17], ploaie_z[17]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_17.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[18], ploaie_y[18], ploaie_z[18]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_18.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[19], ploaie_y[19], ploaie_z[19]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_19.Draw(myCustomShader);
				

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[20], ploaie_y[20], ploaie_z[20]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_20.Draw(myCustomShader);
			
                
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[21], ploaie_y[21], ploaie_z[21]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_21.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[22], ploaie_y[22], ploaie_z[22]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_22.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[23], ploaie_y[23], ploaie_z[23]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_23.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[24], ploaie_y[24], ploaie_z[24]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_24.Draw(myCustomShader);
			
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[25], ploaie_y[25], ploaie_z[25]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_25.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[26], ploaie_y[26], ploaie_z[26]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_26.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[27], ploaie_y[27], ploaie_z[27]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_27.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[28], ploaie_y[28], ploaie_z[28]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_28.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[29], ploaie_y[29], ploaie_z[29]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_29.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[30], ploaie_y[30], ploaie_z[30]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_30.Draw(myCustomShader);
			
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[31], ploaie_y[31], ploaie_z[31]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_31.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[32], ploaie_y[32], ploaie_z[32]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_32.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[33], ploaie_y[33], ploaie_z[33]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_33.Draw(myCustomShader);
				
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[34], ploaie_y[34], ploaie_z[34]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_34.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[35], ploaie_y[35], ploaie_z[35]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_35.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[36], ploaie_y[36], ploaie_z[36]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_36.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[37], ploaie_y[37], ploaie_z[37]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_37.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[38], ploaie_y[38], ploaie_z[38]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_38.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[39], ploaie_y[39], ploaie_z[39]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_39.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[40], ploaie_y[40], ploaie_z[40]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_40.Draw(myCustomShader);

			
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[41], ploaie_y[41], ploaie_z[41]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_41.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[42], ploaie_y[42], ploaie_z[42]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_42.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[43], ploaie_y[43], ploaie_z[43]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_43.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[44], ploaie_y[44], ploaie_z[44]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_44.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[45], ploaie_y[45], ploaie_z[45]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_45.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[46], ploaie_y[46], ploaie_z[46]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_46.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[47], ploaie_y[47], ploaie_z[47]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_47.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[48], ploaie_y[48], ploaie_z[48]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_48.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[49], ploaie_y[49], ploaie_z[49]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_49.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[50], ploaie_y[50], ploaie_z[50]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_50.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[51], ploaie_y[51], ploaie_z[51]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_51.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[52], ploaie_y[52], ploaie_z[52]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_52.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[53], ploaie_y[53], ploaie_z[53]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_53.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[54], ploaie_y[54], ploaie_z[54]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_54.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[55], ploaie_y[55], ploaie_z[55]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_55.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[56], ploaie_y[56], ploaie_z[56]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_56.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[57], ploaie_y[57], ploaie_z[57]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_57.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[58], ploaie_y[58], ploaie_z[58]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_58.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[59], ploaie_y[59], ploaie_z[59]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_59.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[60], ploaie_y[60], ploaie_z[60]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_61.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[62], ploaie_y[62], ploaie_z[62]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_62.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[63], ploaie_y[63], ploaie_z[63]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_63.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[64], ploaie_y[64], ploaie_z[64]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_64.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[65], ploaie_y[65], ploaie_z[65]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_65.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[66], ploaie_y[66], ploaie_z[66]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_66.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[67], ploaie_y[67], ploaie_z[67]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_67.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[68], ploaie_y[68], ploaie_z[68]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_68.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[69], ploaie_y[69], ploaie_z[69]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_69.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[70], ploaie_y[70], ploaie_z[70]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_70.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[71], ploaie_y[71], ploaie_z[71]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_71.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[72], ploaie_y[72], ploaie_z[72]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_72.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[73], ploaie_y[73], ploaie_z[73]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_73.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[74], ploaie_y[74], ploaie_z[74]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_74.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[75], ploaie_y[75], ploaie_z[75]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_75.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[76], ploaie_y[76], ploaie_z[76]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_76.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[77], ploaie_y[77], ploaie_z[77]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_77.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[78], ploaie_y[78], ploaie_z[78]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_78.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[79], ploaie_y[79], ploaie_z[79]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_79.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[80], ploaie_y[80], ploaie_z[80]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_80.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[81], ploaie_y[81], ploaie_z[81]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_81.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[82], ploaie_y[82], ploaie_z[82]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_82.Draw(myCustomShader);


				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[83], ploaie_y[83], ploaie_z[83]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_83.Draw(myCustomShader);


				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[84], ploaie_y[84], ploaie_z[84]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_84.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[85], ploaie_y[85], ploaie_z[85]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_85.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[86], ploaie_y[86], ploaie_z[86]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_86.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[87], ploaie_y[87], ploaie_z[87]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_87.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[88], ploaie_y[88], ploaie_z[88]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_88.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[89], ploaie_y[89], ploaie_z[89]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_89.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[90], ploaie_y[90], ploaie_z[90]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_90.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[91], ploaie_y[91], ploaie_z[91]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_91.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[92], ploaie_y[92], ploaie_z[92]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_92.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[93], ploaie_y[93], ploaie_z[93]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_93.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[94], ploaie_y[94], ploaie_z[94]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_94.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[95], ploaie_y[95], ploaie_z[95]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_95.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[96], ploaie_y[96], ploaie_z[96]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_96.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[97], ploaie_y[97], ploaie_z[97]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_97.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[98], ploaie_y[98], ploaie_z[98]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_98.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[99], ploaie_y[99], ploaie_z[99]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_99.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[100], ploaie_y[100], ploaie_z[100]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_100.Draw(myCustomShader);

			


				move = move - 2.5;
			}
			else {

				move = 0;
				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[0], ploaie_y[0], ploaie_z[0]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_0.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[1], ploaie_y[1], ploaie_z[1]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_1.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[2], ploaie_y[2], ploaie_z[2]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_2.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[3], ploaie_y[3], ploaie_z[3]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_3.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[4], ploaie_y[4], ploaie_z[4]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_4.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[5], ploaie_y[5], ploaie_z[5]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_5.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[6], ploaie_y[6], ploaie_z[6]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_6.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[7], ploaie_y[7], ploaie_z[7]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_7.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[8], ploaie_y[8], ploaie_z[8]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_8.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[9], ploaie_y[9], ploaie_z[9]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_9.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[10], ploaie_y[10], ploaie_z[10]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_10.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[11], ploaie_y[11], ploaie_z[11]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_11.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[12], ploaie_y[12], ploaie_z[12]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_12.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[13], ploaie_y[13], ploaie_z[13]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_13.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[14], ploaie_y[14], ploaie_z[14]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_14.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[15], ploaie_y[15], ploaie_z[15]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_15.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[16], ploaie_y[16], ploaie_z[16]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_16.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[17], ploaie_y[17], ploaie_z[17]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_17.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[18], ploaie_y[18], ploaie_z[18]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_18.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[19], ploaie_y[19], ploaie_z[19]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_19.Draw(myCustomShader);
				drop_19.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[20], ploaie_y[20], ploaie_z[20]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_20.Draw(myCustomShader);


				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[21], ploaie_y[21], ploaie_z[21]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_21.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[22], ploaie_y[22], ploaie_z[22]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_22.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[23], ploaie_y[23], ploaie_z[23]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_23.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[24], ploaie_y[24], ploaie_z[24]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_24.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[25], ploaie_y[25], ploaie_z[25]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_25.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[26], ploaie_y[26], ploaie_z[26]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_26.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[27], ploaie_y[27], ploaie_z[27]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_27.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[28], ploaie_y[28], ploaie_z[28]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_28.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[29], ploaie_y[29], ploaie_z[29]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_29.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[30], ploaie_y[30], ploaie_z[30]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_30.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[31], ploaie_y[31], ploaie_z[31]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_31.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[32], ploaie_y[32], ploaie_z[32]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_32.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[33], ploaie_y[33], ploaie_z[33]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_33.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[34], ploaie_y[34], ploaie_z[34]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_34.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[35], ploaie_y[35], ploaie_z[35]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_35.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[36], ploaie_y[36], ploaie_z[36]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_36.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[37], ploaie_y[37], ploaie_z[37]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_37.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[38], ploaie_y[38], ploaie_z[38]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_38.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[39], ploaie_y[39], ploaie_z[39]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_39.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[40], ploaie_y[40], ploaie_z[40]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_40.Draw(myCustomShader);


				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[41], ploaie_y[41], ploaie_z[41]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_41.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[42], ploaie_y[42], ploaie_z[42]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_42.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[43], ploaie_y[43], ploaie_z[43]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_43.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[44], ploaie_y[44], ploaie_z[44]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_44.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[45], ploaie_y[45], ploaie_z[45]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_45.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[46], ploaie_y[46], ploaie_z[46]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_46.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[47], ploaie_y[47], ploaie_z[47]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_47.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[48], ploaie_y[48], ploaie_z[48]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_48.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[49], ploaie_y[49], ploaie_z[49]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_49.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[50], ploaie_y[50], ploaie_z[50]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_50.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[51], ploaie_y[51], ploaie_z[51]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_51.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[52], ploaie_y[52], ploaie_z[52]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_52.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[53], ploaie_y[53], ploaie_z[53]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_53.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[54], ploaie_y[54], ploaie_z[54]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_54.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[55], ploaie_y[55], ploaie_z[55]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_55.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[56], ploaie_y[56], ploaie_z[56]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_56.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[57], ploaie_y[57], ploaie_z[57]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_57.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[58], ploaie_y[58], ploaie_z[58]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_58.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[59], ploaie_y[59], ploaie_z[59]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_59.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[60], ploaie_y[60], ploaie_z[60]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_61.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[62], ploaie_y[62], ploaie_z[62]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_62.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[62], ploaie_y[62], ploaie_z[62]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_63.Draw(myCustomShader);


				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[1], ploaie_y[1], ploaie_z[1]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_64.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[2], ploaie_y[2], ploaie_z[2]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_65.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[3], ploaie_y[3], ploaie_z[3]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_66.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[4], ploaie_y[4], ploaie_z[4]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_67.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[5], ploaie_y[5], ploaie_z[5]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_68.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[6], ploaie_y[6], ploaie_z[6]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_69.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[7], ploaie_y[7], ploaie_z[7]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_70.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[8], ploaie_y[8], ploaie_z[8]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_71.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[9], ploaie_y[9], ploaie_z[9]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_72.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[10], ploaie_y[10], ploaie_z[10]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_73.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[11], ploaie_y[11], ploaie_z[11]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_74.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[12], ploaie_y[12], ploaie_z[12]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_75.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[13], ploaie_y[13], ploaie_z[13]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_76.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[14], ploaie_y[14], ploaie_z[14]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_77.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[15], ploaie_y[15], ploaie_z[15]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_78.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[16], ploaie_y[16], ploaie_z[16]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_79.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[17], ploaie_y[17], ploaie_z[17]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_80.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[18], ploaie_y[18], ploaie_z[18]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_81.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[19], ploaie_y[19], ploaie_z[19]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_82.Draw(myCustomShader);


				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[20], ploaie_y[20], ploaie_z[20]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_83.Draw(myCustomShader);


				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[21], ploaie_y[21], ploaie_z[21]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_84.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[22], ploaie_y[22], ploaie_z[22]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_85.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[23], ploaie_y[23], ploaie_z[23]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_86.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[24], ploaie_y[24], ploaie_z[24]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_87.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[25], ploaie_y[25], ploaie_z[25]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_88.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[26], ploaie_y[26], ploaie_z[26]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_89.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[27], ploaie_y[27], ploaie_z[27]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_90.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[28], ploaie_y[28], ploaie_z[28]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_91.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[29], ploaie_y[29], ploaie_z[29]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_92.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[30], ploaie_y[30], ploaie_z[30]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_93.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[31], ploaie_y[31], ploaie_z[31]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_94.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[32], ploaie_y[32], ploaie_z[32]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_95.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[33], ploaie_y[33], ploaie_z[33]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_96.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[34], ploaie_y[34], ploaie_z[34]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_97.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[35], ploaie_y[35], ploaie_z[35]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_98.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[36], ploaie_y[36], ploaie_z[36]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_99.Draw(myCustomShader);

				model = glm::mat4(1.0f);
				model = glm::translate(glm::mat4(1.0f), glm::vec3(ploaie_x[37], ploaie_y[37], ploaie_z[37]));
				model = glm::translate(model, glm::vec3(0.0f, move, 0.0f));
				glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
				drop_100.Draw(myCustomShader);
			}
			
		}
		

	}
	
}

void cleanup() {
	glDeleteTextures(1,& depthMapTexture);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDeleteFramebuffers(1, &shadowMapFBO);
	glfwDestroyWindow(glWindow);
	//close GL context and any other GLFW resources
	glfwTerminate();
}

int main(int argc, const char * argv[]) {
	   
	   //faces.push_back("cubemap/purple_right1.png");
	   //faces.push_back("cubemap/purple_left2.png");
	   //faces.push_back("cubemap/purple_top3.png");
	   //faces.push_back("cubemap/purple_bottom4.png");
	   //faces.push_back("cubemap/purple_front5.png");
	  // faces.push_back("cubemap/purple_back6.png");
	
	if (!initOpenGLWindow()) {
		glfwTerminate();
		return 1;
	}
	faces.push_back("cubemap/nebulart.tga");
	faces.push_back("cubemap/nebulalf.tga");
	faces.push_back("cubemap/nebulaup.tga");
	faces.push_back("cubemap/nebuladn.tga");
	faces.push_back("cubemap/nebulabk.tga");
	faces.push_back("cubemap/nebulaft.tga");

	
	skyboxShader.useShaderProgram();
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));

	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	mySkyBox.Load(faces);

	initOpenGLState();
	initObjects();
	initShaders();
	initUniforms();
	initFBO();

	glCheckError();

	while (!glfwWindowShouldClose(glWindow)) {

		processMovement();
	
		renderScene();	


		glfwPollEvents();
		glfwSwapBuffers(glWindow);
	}

	cleanup();

	return 0;
}
