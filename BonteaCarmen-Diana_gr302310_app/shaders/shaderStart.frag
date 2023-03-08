#version 410 core

in vec3 fNormal;
in vec3 fragPos;
in vec4 fPosEye;
in vec2 fTexCoords;
in vec4 fragPosLightSpace;
in vec3 vNormal1;
in vec3 vPosition1;


out vec4 fColor;

//lighting
uniform	vec3 lightDir;
uniform	vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 felinar_1;
uniform vec3 felinar_2;
uniform vec3 felinar_3;
uniform vec3 felinar_4;
uniform vec3 felinar_5;
uniform vec3 felinar_6;
uniform vec3 felinar_7;
uniform vec3 felinar_8;
uniform vec3 felinar_9;
uniform vec3 felinar_10;
uniform vec3 felinar_11;
uniform vec3 felinar_12;
uniform vec3 felinar_13;
uniform vec3 felinar_14;
uniform vec3 felinar_15;
uniform vec3 felinar_16;
uniform vec3 felinar_17;
uniform vec3 felinar_18;
uniform vec3 felinar_19;
uniform vec3 felinar_20;
uniform vec3 felinar_21;
uniform vec3 felinar_22;
uniform vec3 felinar_23;
uniform vec3 felinar_24;
uniform vec3 felinar_25;
uniform vec3 felinar_26;
uniform vec3 felinar_27;
uniform vec3 felinar_28;
uniform vec3 felinar_29;
uniform vec3 felinar_30;
uniform vec3 felinar_31;
uniform vec3 felinar_32;
uniform vec3 felinar_33;
uniform vec3 felinar_34;
uniform vec3 felinar_35;




//matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat3 normalMatrix;


//texture
uniform sampler2D diffuseTexture;
uniform sampler2D specularTexture;
uniform sampler2D shadowMap;

vec3 ambient;
float ambientStrength = 0.2f;
vec3 diffuse;
vec3 specular;
vec3 color;
vec3 lightDirN;
vec3 baseColor;
float specularStrength = 0.5f;
float shininess = 32.0f;
float inten ;
vec4 new_color;
uniform bool fog;
uniform bool pointLight;
uniform bool directLight;
uniform bool spotLight;
uniform bool dark;
uniform bool lampa;

//pointLight_2
float constant=1.0f;
float linear=0.075f;
float quadratic=0.045f;

float computeShadow() {
	vec3 normalizedCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
	if(normalizedCoords.z>1.0f)
	   return 0.0f;
	normalizedCoords = normalizedCoords * 0.5 + 0.5;
	float closestDepth = texture(shadowMap, normalizedCoords.xy).r;
	float currentDepth = normalizedCoords.z;
	//float shadow = currentDepth > closestDepth ? 1.0 : 0.0;

	float bias=0.05f;
	float shadow =currentDepth-bias>closestDepth ? 1.0f : 0.0f;

	
	return shadow;
}
vec3 compute_pointLight(){
    vec3 cameraPosEye = vec3(0.0f);//in eye coordinates, the viewer is situated at the origin
	
	//transform normal
	vec3 normalEye = normalize(fNormal);	
	
	//compute light direction
	if(lampa==true){
	lightDirN = normalize(lightPosition-fragPos);}
	else{
	lightDirN = normalize(lightDir);
	}
	
	//compute view direction 
	vec3 viewDirN = normalize(cameraPosEye - fPosEye.xyz);
	float dist = length(lightDir);	
	float a = 3.0;
	float b = 0.7;
	inten = 1.0f / (a * dist * dist + b * dist + 1.0f);
	
	//compute ambient light
	ambient = ambientStrength * lightColor;
	
	//compute diffuse light
	diffuse = max(dot(normalEye, lightDirN), 0.0f) * lightColor;
	
	//compute specular light
	vec3 reflection = reflect(-lightDirN, normalEye);
	float specCoeff = pow(max(dot(viewDirN, reflection), 0.0f), shininess);
	specular = specularStrength * specCoeff * lightColor;
	float shadow;
	shadow = computeShadow();
	
	//if(texture(diffuseTexture,fTexCoords).a<0.5)
	          //discard;
	
	
	ambient *= texture(diffuseTexture, fTexCoords).rgb;
	diffuse *= texture(diffuseTexture, fTexCoords).rgb;
	specular *= texture(specularTexture, fTexCoords).rgb;
	
	return min((ambient + (1.0f - shadow)*diffuse) + (1.0f - shadow)*specular, 1.0f);
}
vec3 compute_directLight(){
    //compute eye space coordinates
	vec4 vertPosEye = view * model * vec4(vPosition1, 1.0f);
	vec3 normalEye = normalize(normalMatrix * vNormal1);
	
	//normalize light direction
	//lightDir=fragmentPosition - lightPos
	vec3 lightDirN = normalize(lightDir);
	
	//compute view direction (in eye coordinates, the viewer is situated at the origin
	vec3 viewDir = normalize(- vertPosEye.xyz);
	if(dark==true){
	    baseColor = vec3(0.168f, 0.101f, 0.181f); 
	}
	else{baseColor = vec3(3.0f, 1.5f, 1.0f);//sunset
	}
	//compute ambient light
	ambient = ambientStrength * lightColor;
	
	//compute diffuse light
	diffuse = max(dot(normalEye, lightDirN), 0.0f) * lightColor;
	
	//compute specular light
	vec3 reflectDir = reflect(-lightDirN, normalEye);
	float specCoeff = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
	specular = specularStrength * specCoeff * lightDirN;
	
	//if(texture(diffuseTexture,fTexCoords).a<0.5)
	         //discard;
	float shadow;
	shadow = computeShadow();
	
	ambient *= texture(diffuseTexture, fTexCoords).rgb;
	diffuse *= texture(diffuseTexture, fTexCoords).rgb;
	specular *= texture(specularTexture, fTexCoords).rgb;
	
	return min((ambient + (1.0f - shadow)*diffuse)*baseColor + (1.0f - shadow)*specular, 1.0f);
	
	//return min((ambient + diffuse)*baseColor + specular, 1.0f);
}
vec3 compute_spotLight(){
    vec3 cameraPosEye = vec3(0.0f);//in eye coordinates, the viewer is situated at the origin
	
	// controls how big the area that is lit up is
	float outerCone = 0.90f;
	float innerCone = 0.95f;
	
	//transform normal
	vec3 normalEye = normalize(fNormal);	
	
	//compute light direction
	vec3 lightDirN = normalize(lightDir);
	
	//compute view direction 
	vec3 viewDirN = normalize(cameraPosEye - fPosEye.xyz);
	
		
	//compute ambient light
	ambient = ambientStrength * lightColor;
	
	//compute diffuse light
	diffuse = max(dot(normalEye, lightDirN), 0.0f) * lightColor;
	
	//compute specular light
	vec3 reflection = reflect(-lightDirN, normalEye);
	float specCoeff = pow(max(dot(viewDirN, reflection), 0.0f), shininess);
	specular = specularStrength * specCoeff * lightColor;
	
	// calculates the intensity of the crntPos based on its angle to the center of the light cone
	float angle = dot(vec3(0.0f, -1.0f, 0.0f), -lightDirN);
	inten = clamp((angle - outerCone) / (innerCone - outerCone), 0.0f, 1.0f);
	//if(texture(diffuseTexture,fTexCoords).a<0.5)
	        // discard;
			
	ambient *= texture(diffuseTexture, fTexCoords).rgb;
	diffuse *= texture(diffuseTexture, fTexCoords).rgb;
	specular *= texture(specularTexture, fTexCoords).rgb;
	float shadow;
	shadow = computeShadow();
	return min((ambient + (1.0f - shadow)*diffuse) + (1.0f - shadow)*specular*inten, 1.0f);
	//return min((ambient + diffuse) + specular*inten, 1.0f);
}
vec3 compute_pointLight_2(vec3 xLightPosition)
 { vec3 lightColor_2=vec3(1.0f, 1.0f, 1.0f);
	
	//compute light direction
    vec3 lightDirN_2 = normalize(xLightPosition-fragPos);
	
	vec3 cameraPosEye = vec3(0.0f);//in eye coordinates, the viewer is situated at the origin
	
	//transform normal
	vec3 normalEye = normalize(fNormal);	
	vec3 viewDirN = normalize(cameraPosEye - fragPos);
	float dist = length(xLightPosition-fragPos);	
	
	//compute ambient light
	ambient = ambientStrength * lightColor_2;
	
	//compute diffuse light
	diffuse =max(dot(normalEye, lightDirN_2), 0.0f) * lightColor_2;
	
	//compute specular light
	vec3 reflection = reflect(-lightDirN_2, normalEye);
	float specCoeff = pow(max(dot(viewDirN, reflection), 0.0f), shininess);
	specular = specularStrength * specCoeff * lightColor_2;
	
	float attenuation = 1.0 / (constant + linear * dist + quadratic * (dist * dist)); 
	
	//if(texture(diffuseTexture,fTexCoords).a<0.5)
	          //discard;
	ambient *= texture(diffuseTexture, fTexCoords).rgb;
	diffuse *= texture(diffuseTexture, fTexCoords).rgb;
	specular *= texture(specularTexture, fTexCoords).rgb;
    
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
    
}
vec3 computeLightComponents()
{		
	if(pointLight==true){
		return compute_pointLight();
	}
	else if(directLight==true){
		return compute_directLight();
	}
	else if(spotLight==true){
		return compute_spotLight();
	}
	else {
	  return compute_pointLight(); //by default pointLight
	}
	
}
float computeFog()
{
	float fogDensity = 0.005f;
	float fragmentDistance = length(fPosEye.xyz);
	float fogFactor = exp(-pow(fragmentDistance * fogDensity, 2));

	return clamp(fogFactor, 0.0f, 1.0f);
}

void main() 
{   
	color = computeLightComponents();
	if (pointLight == true){
	   color=computeLightComponents();
	   fColor = vec4(color, 1.0f);
    }
	if (directLight == true){
	  color=computeLightComponents();
	  fColor = vec4(color, 1.0f);
	}
	if (spotLight == true){
	  color=computeLightComponents();
	  fColor = vec4(color, 1.0f);}
	if(dark==true){
	   color=computeLightComponents();
	   fColor = vec4(color, 1.0f);
	}
	if(lampa==true){
	   
	   color=color+compute_pointLight_2(felinar_1)+compute_pointLight_2(felinar_2)+compute_pointLight_2(felinar_3)+compute_pointLight_2(felinar_4);
	   color=color+compute_pointLight_2(felinar_5)+compute_pointLight_2(felinar_6)+compute_pointLight_2(felinar_7)+compute_pointLight_2(felinar_8)+compute_pointLight_2(felinar_9)+compute_pointLight_2(felinar_10)+compute_pointLight_2(felinar_11);
	   color=color+compute_pointLight_2(felinar_12)+compute_pointLight_2(felinar_13)+compute_pointLight_2(felinar_14)+compute_pointLight_2(felinar_15)+compute_pointLight_2(felinar_16)+compute_pointLight_2(felinar_17)+compute_pointLight_2(felinar_18);
	   color=color+compute_pointLight_2(felinar_19)+compute_pointLight_2(felinar_20)+compute_pointLight_2(felinar_21)+compute_pointLight_2(felinar_22)+compute_pointLight_2(felinar_23);
	   color=color+compute_pointLight_2(felinar_24)+compute_pointLight_2(felinar_25)+compute_pointLight_2(felinar_26)+compute_pointLight_2(felinar_27)+compute_pointLight_2(felinar_28)+compute_pointLight_2(felinar_29);
	   color=color+compute_pointLight_2(felinar_30)+compute_pointLight_2(felinar_31)+compute_pointLight_2(felinar_32)+compute_pointLight_2(felinar_33)+compute_pointLight_2(felinar_34)+compute_pointLight_2(felinar_35);
	   
	   fColor = vec4(color, 1.0f);
	}
    if (fog == true){	
		float fogFactor = computeFog();
		vec4 fogColor = vec4(0.5f, 0.5f, 0.5f, 1.0f); 
		new_color = vec4 (color,1.0f);
		fColor = fogColor * (1 - fogFactor) + new_color * fogFactor;
	} 
	else {
	    
		fColor = vec4(color, 1.0f);
	}
   
  
   
    
    
}
