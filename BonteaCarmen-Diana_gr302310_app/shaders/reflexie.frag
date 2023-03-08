#version 410 core

out vec4 fColor;
in vec2 vTexCoords1;
uniform sampler2D diffuseTexture;

uniform vec3 cameraPos;
uniform samplerCube skybox;

in vec3 normal;
in vec3 position;



void main() 
{ 
   vec3 viewDirectionN = normalize(position-cameraPos);
  vec3 normalN = normalize(normal);
   vec3 reflection = reflect(viewDirectionN, normalN);
   vec3 color = vec3(texture(skybox, reflection));
  fColor = vec4(color, 0.5f);
  //vec3 I=normalize(position-cameraPos);
 //vec3 R = reflect(I, normalize(normal));
  //fColor = vec4(texture(skybox, R).rgb, 1.0);
  
}
