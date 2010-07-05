uniform float radius;

varying vec3 LightPosition;
varying vec3 Normal;

void main()
{
	vec4 inPos = gl_Vertex;
    //Normal = normalize(gl_NormalMatrix * gl_Normal);
	Normal = gl_Normal;
	
	float factor = 0.3;
	float freqx = 1.0 + sin(factor * 1.2) * 25.0;
    float freqy = 1.0 + sin(factor * 1.2) * 25.0;
    float freqz = 1.0 + sin(factor * 1.2) * 25.0;
    float amp = radius*0.06 + sin(factor) * radius*0.1;
    
    vec3 disp = vec3(0.0);
    float f = sin(Normal.x*freqx + factor) * sin(Normal.y*freqy + factor) * sin(Normal.z*freqz + factor);
    disp.x += Normal.x * amp * f;
    disp.y += Normal.y * amp * f;
    disp.z += Normal.z * amp * f;
    inPos.xyz += disp;
    Normal += disp;
    
	gl_Position = gl_ModelViewProjectionMatrix * inPos;
    
    Normal = normalize(gl_NormalMatrix * Normal);
	LightPosition = normalize(gl_LightSource[0].position.xyz);
	
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_FrontColor = gl_Color;
}