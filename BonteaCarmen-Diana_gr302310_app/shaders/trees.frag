#version 410 core

out vec4 fColor;
in vec2 vTexCoords1;
uniform sampler2D diffuseTexture;
void main() 
 { vec4 color=texture(diffuseTexture,vTexCoords1);   
       if(color.a<0.5)
	        discard;
    fColor = color;
}
