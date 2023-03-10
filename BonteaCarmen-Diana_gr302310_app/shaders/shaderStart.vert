#version 410 core

layout(location=0) in vec3 vPosition;
layout(location=1) in vec3 vNormal;
layout(location=2) in vec2 vTexCoords;

out vec3 fNormal;
out vec4 fPosEye;
out vec2 fTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform	mat3 normalMatrix;

out vec4 fragPosLightSpace;
out vec3 vPosition1;
out vec3 vNormal1;
out vec3 fragPos;

uniform mat4 lightSpaceTrMatrix;

void main() 
{   //compute eye space coordinates
    vPosition1=vPosition;
    vNormal1=vNormal;
	fPosEye = view * model * vec4(vPosition, 1.0f);
	fragPos = vec3(model * vec4(vPosition, 1.0f));
	fNormal = normalize(normalMatrix * vNormal);
	fTexCoords = vTexCoords;
	fragPosLightSpace = lightSpaceTrMatrix * model * vec4(vPosition, 1.0f);
	gl_Position = projection * view * model * vec4(vPosition, 1.0f);
}
