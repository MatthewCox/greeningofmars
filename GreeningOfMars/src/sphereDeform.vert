uniform float radius;

varying vec3 LightDirection;
varying vec3 ViewDirection;
varying vec3 Normal;

attribute vec3 Tangent;

void main()
{
	vec4 inPos = gl_Vertex;
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
    
	gl_Position = gl_ModelViewProjectionMatrix * inPos;
    
    Normal = gl_NormalMatrix * gl_Normal;
    vec4 Pos = gl_ModelViewMatrix * inPos;
    
    ViewDirection = vec3(gl_ModelViewMatrix * gl_Vertex);
    vec3 n = normalize(gl_NormalMatrix * gl_Normal);
	vec3 t = normalize(gl_NormalMatrix * Tangent);
	vec3 b = cross(n, t);
	
	vec3 LightPosition = gl_LightSource[0].position.xyz;
	
	vec3 v;
	v.x = dot(LightPosition, t);
	v.y = dot(LightPosition, b);
    v.z = dot(LightPosition, n);
    LightDirection = normalize(v);
    
    v.x = dot(ViewDirection, t);
	v.y = dot(ViewDirection, b);
    v.z = dot(ViewDirection, n);
    ViewDirection = normalize(v);
	
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_FrontColor = gl_Color;
}